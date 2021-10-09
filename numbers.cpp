//
// Created by Marina Roshchupkina on 06.10.2021.
//

#include "numbers.h"

//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void In(numbers &r, ifstream &ifst) {
    ifst >> r.length;
    for (int i = 0; i < r.length; ++i) {
        ifst >> r.cyphered[i];
    }
    for (int i = 0; i < r.length; ++i) {
        char temp;
        ifst >> temp >> r.cypher[1][i];
        r.cypher[0][i]=(int)temp;
    }
    for (int i = 0; i < r.length; ++i) {
        for (int j = 0; j < r.length; ++j) {
            if(r.cyphered[i]==r.cypher[1][j])
                r.decyphered[i]=r.cypher[0][j];
        }
    }
}

// Случайный ввод параметров строки
void InRnd(numbers &r) {
    r.length = RandomSmall();
    for (int i = 0; i < r.length; ++i) {
        r.cyphered[i] = RandomSmall()*RandomSmall();
        r.decyphered[i] = (char)(Random());
        r.cypher[0][i] = r.cyphered[i];
        r.cypher[1][i] = r.decyphered[i];
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Out(numbers &r, ofstream &ofst) {
    ofst << "numbers cypher: cyphered text = ";
    for (int i = 0; i < r.length; ++i) {
        ofst  << r.cyphered[i];
    }
    ofst << ", decyphered text = " << r.decyphered
         << ". function result = " << Func(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Func(numbers &r) {
    int sum = 0;
    for (int i = 0; i < strlen(r.decyphered); ++i) {
        sum += (int) r.decyphered[i];
    }
    return (double) sum / strlen(r.decyphered);
}
