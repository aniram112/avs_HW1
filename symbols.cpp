//
// Created by Marina Roshchupkina on 06.10.2021.
//

#include "symbols.h"

//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void In(symbols &r, ifstream &ifst) {
    ifst >> r.cyphered;
    r.length = strlen(r.cyphered);
    for (int i = 0; i < r.length; ++i) {
        ifst >> r.cypher[0][i]>> r.cypher[1][i];
    }
    // Расшифровка, заменой символов с шифра на символы ключа.
    for (int i = 0; i < r.length; ++i) {
        for (int j = 0; j < r.length; j ++) {
            if (r.cyphered[i] == r.cypher[0][j])
                r.decyphered[i]= r.cypher[1][j];
        }
    }
}

// Случайный ввод параметров зашифрованной строки
void InRnd(symbols &r) {
    r.length = RandomSmall();
    for (int i = 0; i < r.length; ++i) {
        char symb = (char)Random();
        r.cyphered[i]=symb;
        char symb_new = (char)Random();
        r.decyphered[i]+=symb_new;
        r.cypher[0][i]=symb;
        r.cypher[1][i]=symb_new;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Out(symbols &r, ofstream &ofst) {
    ofst << "symbols cypher: cyphered text = " << r.cyphered << ", decyphered text = " << r.decyphered
         << ". function_result = " << Func(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Func(symbols &r) {
    int sum = 0;
    for (int i = 0; i < r.length; ++i) {
        sum += (int) r.decyphered[i];
    }
    return (double) sum / r.length;
}


