#include "VirtualMemoryManagement.h"
using  namespace std;
int main() {
    VirtualMemoryManagement demo = VirtualMemoryManagement();
    int *element, *el;
    cout << "---Запись значений с индексами: 0, 55, 23, 23000---" << endl;
    cout << "Результат операции :" << demo.RecordElemenForIndex(0,21) << endl;
    cout << "Результат операции :" << demo.RecordElemenForIndex(55,55) << endl;
    cout << "Результат операции :" << demo.RecordElemenForIndex(23,78) << endl;
    cout << "Результат операции :" << demo.RecordElemenForIndex(23000,90) << endl;

    cout << "---Запись значений с индексами: 0, 55, 23, 23000---" << endl;
    cout << "---True - выполнено, False - не выполнено ---" << endl;
    cout << "Результат операции:" << demo.ReadElementForIndex(0,element) <<"\tЭлемент:" << demo.numberForExam<< endl;
    cout << "Результат операции:" << demo.ReadElementForIndex(55,element)<<"\tЭлемент:" <<  demo.numberForExam << endl;
    cout << "Результат операции:" << demo.ReadElementForIndex(23,element)<<"\tЭлемент:" << demo.numberForExam << endl;
    cout << "Результат операции:" << demo.ReadElementForIndex(23000,element) <<"\tЭлемент:" << demo.numberForExam<< endl;


    return 0;
}
