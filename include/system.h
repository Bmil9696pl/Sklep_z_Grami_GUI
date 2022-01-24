//
// Created by bartek on 27.12.2021.
//

#ifndef SKLEP_Z_GRAMI_SYSTEM_H
#define SKLEP_Z_GRAMI_SYSTEM_H

#include "Exception.h"
#include "ListaZakupow.h"
using namespace std;

// @brief ładuje linijki z pliku, tworzy z nich nowe obiekty oraz dodaje je do vektora który jest zwracany
// @param "plik" - ścierzka do pliku z którego odczytywane mają być dane
template <class type>
vector<type> zaladojPolki(string plik){
    vector<type> vect;
    string line;
    ifstream input(plik);
    while(!input.eof()){
        getline(input,line);
        type nowy(line);
        vect.push_back(nowy);
    }
    input.close();
    return vect;
};

#endif //SKLEP_Z_GRAMI_SYSTEM_H
