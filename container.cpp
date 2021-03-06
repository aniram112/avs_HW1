//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"


//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while(!ifst.eof())
    {
        if((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size){
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++){
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

//------------------------------------------------------------------------------
// Удаление элементов значение функции у которых меньше среднего арифметического
void DeleteLess(container &arr, ofstream &ofst) {
    double sum = 0;
    for (int i = 0; i < arr.len; i++) {
        sum += Func(*arr.cont[i]);
    }
    double mean = sum / (arr.len);
    ofst << "Mean: "<<mean<<" Sum: "<<sum<<" Len: "<<arr.len<<endl;
    for (int i = 0; i < arr.len; i++) {
        if (Func(*arr.cont[i]) < mean) {
            for(int j = i; j < arr.len; j++) {
                arr.cont[j] = arr.cont[j+1];
            }
            arr.cont[arr.len-1] = NULL;
            arr.len--;
            i--;
        }

    }

}
