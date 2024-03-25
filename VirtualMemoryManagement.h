//
// Created by hikiray on 24.03.24.
//
#ifndef VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
#define VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
#include <iostream>
#include <filesystem>
#include <fstream>
#include "Page.h"
using namespace std;

class VirtualMemoryManagement {
private:
    Page pages[3];
public:
    VirtualMemoryManagement(string filepath = "memory.bin", int size = 3)
    {
        if(!filesystem::exists(filepath)) {
            ofstream filememory = ofstream(filepath, ios_base::binary);
            string VM = "VM";
            filememory.write((char*)&VM,sizeof(int));
            for (int i = 0; i < 512; i++) {
                filememory.write((char*)&"0",sizeof(int));
            }
            filememory.close();
        }
    }
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
