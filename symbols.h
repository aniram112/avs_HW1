//
// Created by Marina Roshchupkina on 06.10.2021.
//

#ifndef __symbols__
#define __symbols__

//------------------------------------------------------------------------------
// symbols.h - содержит описание строки, зашифрованной посимвольной заменой
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

// строка
struct symbols {
    int length;
    char cyphered[100]; // зашифрованный текст
    char decyphered[100]; // открытая строка
    char cypher[2][100]; // шифр
};

// Ввод параметров строки и ее шифра из файла
void In(symbols &r, ifstream &ifst);

// Случайный ввод параметров строки и ее шифра
void InRnd(symbols &r);

// Вывод параметров строки в форматируемый поток
void Out(symbols &r, ofstream &ofst);

// Деление кодов символов незашифрованной строки на число символов в ней
double Func(symbols &r);

#endif //__symbols__
