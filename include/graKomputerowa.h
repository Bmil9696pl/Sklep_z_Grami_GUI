//
// Created by bartek on 23.12.2021.
//

#ifndef SKLEP_Z_GRAMI_GRAKOMPUTEROWA_H
#define SKLEP_Z_GRAMI_GRAKOMPUTEROWA_H

#include "./gra.h"

class GraKomputerowa : public Gra {
public:
    string wymagania;
    GraKomputerowa();
    ~GraKomputerowa();
    GraKomputerowa(string n, double c, string o, string w);
    explicit GraKomputerowa(string n);
    GraKomputerowa& operator=(const GraKomputerowa &rhs);
    string opisGry();
    string podajNazwe();
    void zapisz();
};

#endif //SKLEP_Z_GRAMI_GRAKOMPUTEROWA_H
