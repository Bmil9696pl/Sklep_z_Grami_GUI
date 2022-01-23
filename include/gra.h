//
// Created by bartek on 23.12.2021.
//

#ifndef SKLEP_Z_GRAMI_GRA_H
#define SKLEP_Z_GRAMI_GRA_H

#include <iostream>
#include <string>
#include "fstream"
using namespace std;


    class Gra {
    public:

        string nazwa;
        double cena;
        string opis;

        virtual ~Gra() {};
        virtual void zapisz() = 0;
        virtual string podajNazwe() = 0;
        virtual string opisGry() = 0;
    };

#endif //SKLEP_Z_GRAMI_GRA_H
