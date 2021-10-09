//
// Created by Marina Roshchupkina on 06.10.2021.
//

#ifndef __cypher__
#define __cypher__

#include "symbols.h"
#include "cyclic.h"
#include "numbers.h"

//------------------------------------------------------------------------------
// структура, обобщающая все строки шифрования
struct cypher {
    // значения ключей для каждой из строк
    enum key {SYMBOLS, CYCLIC, NUMBERS};
    key k; // ключ
    // используемые альтернативы
    union {
        symbols s;
        cyclic c;
        numbers n;
    };
};

// Ввод обобщенной строки
cypher *In(ifstream &ifdt);

// Случайный ввод обобщенной строки
cypher *InRnd();

// Вывод обобщенной строки
void Out(cypher &s, ofstream &ofst);

// Вычисление функции строки
double Func(cypher &s);

#endif