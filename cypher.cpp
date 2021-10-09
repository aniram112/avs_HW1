//
// Created by Marina Roshchupkina on 06.10.2021.
//

#include "cypher.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной строки и ее шифра из файла
cypher *In(ifstream &ifst) {
    cypher *sp;
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            sp = new cypher;
            sp->k = cypher::SYMBOLS;
            In(sp->s, ifst);
            return sp;
        case 2:
            sp = new cypher;
            sp->k = cypher::CYCLIC;
            In(sp->c, ifst);
            return sp;
        case 3:
            sp = new cypher;
            sp->k = cypher::NUMBERS;
            In(sp->n, ifst);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной строки и ее шифра
cypher *InRnd() {
    cypher *sp;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            sp = new cypher;
            sp->k = cypher::SYMBOLS;
            InRnd(sp->s);
            return sp;
        case 2:
            sp = new cypher;
            sp->k = cypher::CYCLIC;
            InRnd(sp->c);
            return sp;
        case 3:
            sp = new cypher;
            sp->k = cypher::NUMBERS;
            InRnd(sp->n);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей строки в поток
void Out(cypher &s, ofstream &ofst) {
    switch (s.k) {
        case cypher::SYMBOLS:
            Out(s.s, ofst);
            break;
        case cypher::CYCLIC:
            Out(s.c, ofst);
            break;
        case cypher::NUMBERS:
            Out(s.n, ofst);
            break;
        default:
            ofst << "Incorrect string!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление функции строки
double Func(cypher &s) {
    switch (s.k) {
        case cypher::SYMBOLS:
            return Func(s.s);
            break;
        case cypher::CYCLIC:
            return Func(s.c);
            break;
        case cypher::NUMBERS:
            return Func(s.n);
            break;
        default:
            return 0.0;
    }
}
