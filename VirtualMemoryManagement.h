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
    ofstream out;
    ifstream input;
    Page pages[3];
public:
    VirtualMemoryManagement(string filepath = "memory.bin", int size = 3)
    {
        if(!filesystem::exists(filepath)) {
            out = ofstream(filepath, ios_base::binary);
            string VM = "VM";
            out.write((char*)&VM,sizeof(int));
            for (int i = 0; i < 512; i++) {
                out.write((char*)&"0",sizeof(int));
            }
        }
        else{
            out.open(filepath, ios_base::binary);
            input.open(filepath, ios_base::binary);
        }

    }
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYMANAGEMENT_H
