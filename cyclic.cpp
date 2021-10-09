//
// Created by Marina Roshchupkina on 06.10.2021.
//

//------------------------------------------------------------------------------
// cyclic.cpp - содержит функции обработки шифрования циклическим сдвигом
//------------------------------------------------------------------------------

#include "cyclic.h"

//------------------------------------------------------------------------------
// Ввод параметров строки и шифра из потока
void In(cyclic &r, ifstream &ifst) {
    ifst >> r.cyphered >> r.cypher;
    for (int i = 0; i < strlen(r.cyphered); ++i) {
        r.decyphered[i]=(char)(r.cypher+(int)r.cyphered[i]);
    }
}

// Случайный ввод параметров строки и шифра
void InRnd(cyclic &r) {
    r.cypher = RandomSmall();
    int lenght = RandomSmall();
    for (int i = 0; i < lenght; ++i) {
        char symb = (char)Random();
        r.cyphered[i]=symb;
        r.decyphered[i]=(char)(r.cypher+(int)symb);
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в поток
void Out(cyclic &r, ofstream &ofst) {
    ofst << "cyclic cypher: cyphered text = " << r.cyphered << ", decyphered text = " << r.decyphered
         << ". function result = " << Func(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление функции общей для всех строк.
double Func(cyclic &r) {
    int sum = 0;
    for (int i = 0; i < strlen(r.decyphered); ++i) {
        sum += (int) r.decyphered[i];
    }
    return (double) sum / strlen(r.decyphered);
}
