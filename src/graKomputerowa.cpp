#include "../include/graKomputerowa.h"

// @brief zapisuje obiekt do pliku "zakupy"
void GraKomputerowa::zapisz() {
    ofstream output;
    output.open("C:/Users/bartek-tominek/Documents/build-Sklep_z_Grami-Desktop_Qt_6_2_2_MSVC2019_64bit-Debug/zakupy", ios::app);
    output << nazwa << endl;
    output << cena << "zł" << endl;
    output << opis << endl;
    output << wymagania << endl;
    output << endl;
    output.close();
}

// @brief zwraca nazwę obiektu
string GraKomputerowa::podajNazwe() {
    return nazwa;
}

GraKomputerowa::GraKomputerowa() {}

GraKomputerowa::~GraKomputerowa() noexcept {}

// @brief konstruktor gry komputerowej
// @param "nazwaGry" - nazwa gry komputerowej
// @param "cenaGry" - cena gry komputerowej
// @param "opisGry" - opis gry komputerowej
// @param "wymaganiaGry" - wymagania gry komputerowej
GraKomputerowa::GraKomputerowa(string nazwaGry, double cenaGry, string opisGry, string wymaganiaGry):
wymagania(wymaganiaGry)
{
    nazwa = nazwaGry;
    cena = cenaGry;
    opis = opisGry;
}

// @brief konstruktor, który przyjmuje string pobrany z pliku i przetwarza go tak aby dało się stworzyć obiekt
// @karam "dane" - string z danymi odczytanymi z pliku (przykładowo: uncharted;160,25;gra przygodowa, rpg;ps4 exlusive)
GraKomputerowa::GraKomputerowa(string dane) {
    string pomCena = "";
    nazwa = "";
    opis = "";
    wymagania = "";
    string srednikk = ";";
    char srednik = srednikk[0];
    int count = 0;
    for(char x : dane) {
        bool CZYSREDNIKBYLTERAZWYKRYTY = 0;
        if (x == srednik) {
            count++;
            CZYSREDNIKBYLTERAZWYKRYTY = 1;
        }
        if (CZYSREDNIKBYLTERAZWYKRYTY == 0){
            if (count == 0)
                nazwa = nazwa + x;
            if (count == 1)
                pomCena = pomCena + x;
            if (count == 2)
                opis = opis + x;
            if (count == 3)
                wymagania = wymagania + x;
        }
    }
    cena = stod(pomCena);
}

// @brief wypisuje informacje i opis gry
string GraKomputerowa::opisGry() {
    string ret;
    ret = nazwa + "\n";
    ret += to_string(cena) + "zl" + "\n";
    ret += opis + "\n";
    ret += wymagania;
    return ret;
}

// @brief operator kopiujący gry komputerowe
// @param "rhs" - obiekt po prawej stronie operatora
GraKomputerowa &GraKomputerowa::operator=(const GraKomputerowa &rhs) {
    nazwa = rhs.nazwa;
    wymagania = rhs.wymagania;
    cena = rhs.cena;
    opis = rhs.opis;
    return *this;
}
