#include "../include/system.h"

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

// @brief konstruktor dla klasy Exeception
// @param "msg" string z wiadomością błędu
Exception::Exception(string msg):wiadomosc(msg) {}

// @brief wypisanie wiadomosci
string Exception::what() {
    return wiadomosc;
}

// @brief zwraca obiekt wyszukany po nazwie z podanego vektora
// @param "polkaKariane" - vektor w którym zapisane są wszystkie gry karciane
// @param "nazwa" - nazwa przy pomocy której szukana jest gra karciana
/*GraKarciana znajdzNaPolce(vector <GraKarciana> polkaKarciane, string nazwa) {
    GraKarciana ret;
    for (auto i = polkaKarciane.begin(); i != polkaKarciane.end(); i++) {
        if (i->podajNazwe() == nazwa)
            return ret.kupKarty(*i);
    }
    throw Exception("nie znaleziono obiektu o tej nazwie");
}*/

// @brief zwraca obiekt wyszukany po nazwie z podanego vektora
// @param "polkaKariane" - vektor w którym zapisane są wszystkie gry komputerowe
// @param "nazwa" - nazwa przy pomocy której szukana jest gra komputerowa
GraKomputerowa znajdzNaPolce(vector<GraKomputerowa> polkaKomputerowe, string nazwa){
    GraKomputerowa ret;
    for(auto i = polkaKomputerowe.begin(); i!=polkaKomputerowe.end(); i++){
        if(i->podajNazwe() == nazwa) {
            ret = *i;
            return ret;
        }
    }
    throw Exception("nie znaleziono obiektu o tej nazwie");
}
