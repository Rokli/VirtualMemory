//
// Created by hikiray on 24.03.24.
//

#ifndef VIRTUALMEMORY_PAGE_H
#define VIRTUALMEMORY_PAGE_H


#include <ctime>
#include <vector>
using namespace std;
struct Page {
public:
    int numberPage;
    bool pageMode;
    time_t  pageTime;
    vector<int> memoryValues;
    vector<unsigned char> memoryByte;
    Page(int numberPage, vector<unsigned char> bitArray, vector<int> valuesModelArray)
    {
        this->numberPage = numberPage;
        pageMode = false;
        pageTime = clock();
        memoryValues = valuesModelArray;
        memoryByte =  bitArray;
    }
};


#endif //VIRTUALMEMORY_PAGE_H
