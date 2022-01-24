#ifndef LISTAZAKUPOW_H
#define LISTAZAKUPOW_H

#include "vector"
#include "gra.h"
#include "graKarty.h"
#include "graKomputerowa.h"
#include <iostream>
#include <string>
using namespace std;

class ListaZakupow{
public:
    vector<Gra*> Koszyk;
    ListaZakupow();
    ~ListaZakupow();
    void dodajProdukt(GraKarciana *pKarciana);
    void dodajProdukt(GraKomputerowa *pKomputerowa);
    void zapisz();
};

#endif // LISTAZAKUPOW_H
