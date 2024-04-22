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
    string filepath;
    int size;

public:
     int numberForExam;
    VirtualMemoryManagement(string filepath = "memory.bin", int size = 3, int pageLength = 128)
    {
        this->size = size;
        this->filepath = filepath;
        this->pageLength = pageLength;
        if(!filesystem::exists(filepath)) {
            ofstream recordFile(filepath, ios::out | ios::binary);
            unsigned char V = 'V';
            unsigned char W = 'W';
            int tmp = '0';
            recordFile.write((char *) &V, sizeof(unsigned char));
            recordFile.write((char *) &W, sizeof(unsigned char));
            for (int i = 0; i < 512 * size; i++) {
                recordFile.write((char*)&tmp,sizeof(int));
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
        int numberPage = index / pageLength;
        vector<unsigned char> valuesArrayByte (pageLength * sizeof(int));
        Page oldPage = this->pages[0];
        int indexOldestPage = 0;
        for(Page tmp : this->pages){
            if(tmp.numberPage == numberPage)
                return tmp.numberPage;
        }
        for(int i = 1; index < pages.size();i++){
            if(pages[i].pageTime < oldPage.pageTime){
                indexOldestPage = i;
                oldPage = pages[i];
            }
        }
        if(oldPage.pageMode){
            SavePage(oldPage);
        }
        oldPage.pageTime = clock();
        oldPage.pageMode = true;
        vector<int> valuesArray = ByteToInt(valuesArrayByte);
        return indexOldestPage;
    }
    void SavePage(Page page){
        for(Page tmp: this->pages){
            if(tmp.numberPage == page.numberPage)
                this->pages[tmp.numberPage] = page;
        }
        ofstream recordFile(filepath, ios::out | ios::binary);
        char V = 'V';
        char W = 'W';
        char tmp = '0';
        recordFile.write((char *) &V, sizeof(char));
        recordFile.write((char *) &W, sizeof(char));
        for(Page tmp: this->pages){
            for(int i: tmp.memoryByte){
                recordFile.write((char *)&i, sizeof(char));
            }
        }
        recordFile.close();
    }
    bool ReadElementForIndex(int index, int* element){
        if(index < 0 || index > size * pageLength)
            return false;
        int indexElement= DeterminingPageIndex(index);
        element = &pages[indexElement].memoryValues[index];
        this->numberForExam = *element;
        return true;
    }
    vector<int> ByteToInt(vector<unsigned char> byte){
        vector<int> array(byte.size()/sizeof(int));
        int j = 0;
        for(int i = 0; i < byte.size();i += 4){
            unsigned char tmp[] = {byte[i],byte[i+1],byte[i+2], byte[i+3]};
            array[j] = *(int*)tmp;
            j++;
        }
        return array;
    }
    bool RecordElemenForIndex(int index,int element){
        if(index < 0 || index > size * pageLength)
            return false;
        int indexElement = DeterminingPageIndex(index);
        int address = index % pageLength;
        this->pages[indexElement].memoryValues[address] = element;
        this->pages[indexElement].memoryByte[address] = 1;
        this->pages[indexElement].pageMode = true;
        this->pages[indexElement].pageTime = clock();
        return true;
    }
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
