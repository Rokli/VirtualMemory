#include <iostream>
#include <fstream>
#include <chrono>
#include "VirtualMemoryManagement.h"
using  namespace std;
int main() {
    int x = 214214;
    int tmp;
//    ifstream ifout("txt.bin",ios_base::binary);
//    ofstream fout("txt.bin",ios_base::binary);
//    ifout.read((char*)&tmp,sizeof(int));
//    fout.close();
    VirtualMemoryManagement demo = VirtualMemoryManagement();
    return 0;
}
