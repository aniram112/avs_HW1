//
// Created by Marina Roshchupkina on 06.10.2021.
//

#ifndef __cyclic__
#define __cyclic__

//------------------------------------------------------------------------------
// cyclic.h - содержит описание строки, зашифрованной измененрем кода символа.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

struct cyclic {
    int cypher;
    char cyphered[100];
    char decyphered[100];
};


// Ввод параметров строки и шифра из файла
void In(cyclic &r, ifstream &ifst);

// Случайный ввод параметров строки и шифра
void InRnd(cyclic &r);

// Вывод параметров строки в форматируемый поток
void Out(cyclic &r, ofstream &ofst);

// Деление кодов символов незашифрованной строки на число символов в ней
double Func(cyclic &r);

#endif //__cyclic__
