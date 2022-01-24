#include "../include/ListaZakupow.h"

ListaZakupow::ListaZakupow() {}

ListaZakupow::~ListaZakupow() {}

// @brief dodaje produkt do koszyka
// @param "pKarciana" wskaźnik do gry karcianej która jest dodawana
void ListaZakupow::dodajProdukt(GraKarciana *pKarciana) {
    Koszyk.push_back(pKarciana);
}

// @brief dodaje produkt do koszyka
// @param "pKarciana" wskaźnik do gry komputerowej która jest dodawana
void ListaZakupow::dodajProdukt(GraKomputerowa *pKomputerowa) {
    Koszyk.push_back(pKomputerowa);
}

// @brief zapisuje koszyk do pliku "zakupy" - "kupuno" tego co się wstawiło do koszyka
void ListaZakupow::zapisz() {
    ofstream output;
    output.open("C:/Users/bartek-tominek/Documents/build-Sklep_z_Grami-Desktop_Qt_6_2_2_MSVC2019_64bit-Debug/zakupy");
    output << "Twoje zakupy:" << endl;
    output << endl;
    output.close();
    for(auto i = Koszyk.begin(); i != Koszyk.end(); i++)
        (*i)->zapisz();
}
