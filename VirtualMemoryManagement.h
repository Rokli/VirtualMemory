//
// Created by hikiray on 24.03.24.
//
#ifndef VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
#define VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
#include <iostream>
#include <filesystem>
#include <fstream>
#include "Page.cpp"
using namespace std;

class VirtualMemoryManagement {
private:
    vector<Page> pages;
    vector<Page> pagesBuffer;
    int pageLength;
public:
    VirtualMemoryManagement(string filepath = "memory.bin", int size = 3, int pageLength = 128)
    {
        this->pageLength = pageLength;
        if(!filesystem::exists(filepath)) {
            ofstream recordFile(filepath, ios::out | ios::binary);
            char V = 'V';
            char W = 'W';
            char tmp = '0';
            recordFile.write((char *) &V, sizeof(char));
            recordFile.write((char *) &W, sizeof(char));
            for (int i = 0; i < 512 * size; i++) {
                recordFile.write((char*)&tmp,sizeof(char));
            }
            recordFile.close();
        }
        // ifstream readFile(filepath, ios::out | ios::binary);
        for(int i = 0; i < size; i++){
            vector<int> memoryPage(128);
            vector<unsigned char> memoryByte(512);
            Page page{i,memoryByte,memoryPage};
            this->pages.push_back(page);
        }
        for(int i = 0; i < size; i++){
            DeterminingPageIndex(this->pages[i].numberPage);
        }

        // readFile.close();
    }
    int DeterminingPageIndex(int index){
        bool flag = false;
        for(Page tmp : this->pages){
            if(tmp.numberPage == index)
                flag = true;
        }
        Page page = this->pages[index];
        if(flag == false)
                Page page = this->pages[0];
        if(page.pageMode){
            SavePage(page);
        }
        page.pageTime = clock();
        page.pageMode = true;
        return page.numberPage;
    }
    void SavePage(Page page){
        for(Page tmp: this->pages){
            if(tmp.numberPage == page.numberPage)
                this->pages[tmp.numberPage] = page;
        }

    }
    bool ReadElementForIndex(int index, int element){
        int indexElement= DeterminingPageIndex(index);
        int addres = indexElement % pageLength;
        element = pages[indexElement].memoryValues[addres];
        return true;
    }
    bool RecordElemenForIndex(int index,int element){
        int indexElement =DeterminingPageIndex(index);
        int address = index % pageLength;
        this->pages[indexElement].memoryValues[address] = element;
        this->pages[indexElement].memoryByte[address] = 1;
        this->pages[indexElement].pageMode = true;
        this->pages[indexElement].pageTime = clock();
        return true;
    }
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
