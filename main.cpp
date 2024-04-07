#include "VirtualMemoryManagement.h"
using  namespace std;
int main() {
    int x = 214214;
    int tmp;
    //TODO:
    // Проверка git
//    ifstream ifout("txt.bin",ios_base::binary);
//    ofstream fout("txt.bin",ios_base::binary);
//    ifout.read((char*)&tmp,s  izeof(int));
//    fout.close();
    VirtualMemoryManagement demo = VirtualMemoryManagement();
    cout << "-----------------" << endl;
    cout << "Результат операции :" << demo.RecordElemenForIndex(0,21) << endl;
    cout << "-----------------" << endl;
    cout << "Результат операции:" << demo.DeterminingPageIndex(0) << endl;

    return 0;
}
