//
// Created by Marina Roshchupkina on 06.10.2021.
//

#ifndef __numbers__
#define __numbers__

//------------------------------------------------------------------------------
// number.h - содержит описание строки, зашифрованной заменой букв на числа
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

// строка, шифрующаяся числами.
struct numbers {
    int length;
    int cypher[2][100];
    int cyphered[100];
    char decyphered[100];
};


// Ввод параметров строки из файла
void In(numbers &r, ifstream &ifst);

// Случайный ввод параметров строки
void InRnd(numbers &r);

// Вывод параметров строки в форматируемый поток
void Out(numbers &r, ofstream &ofst);

// Деление кодов символов незашифрованной строки на число символов в ней
double Func(numbers &r);

#endif //__numbers__
