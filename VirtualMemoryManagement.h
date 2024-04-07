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
public:
    VirtualMemoryManagement(string filepath = "memory.bin", int size = 3)
    {
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

        // readFile.close();
    }
    void DeterminingPageIndex(){

    }
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
