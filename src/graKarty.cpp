#include "../include/graKarty.h"

// @brief w tej funkcji wybierana jest ilość paczek która ma być dodana do koszyka
// @param "kart" - gra karciana ktorej ilość jest określana
GraKarciana GraKarciana::kupKarty(int ilosc) {
    GraKarciana ret;
    ret = *this;
    for(int i = 1; i < ilosc ; ++i){
        ret += *this;
    }
    return ret;
}

// @brief zwraca nazwę obiektu
string GraKarciana::podajNazwe() {
    return nazwa;
}

// @brief zapisuje obiekt do pliku "zakupy"
void GraKarciana::zapisz() {
    ofstream output;
    output.open("C:/Users/bartek-tominek/Documents/build-Sklep_z_Grami-Desktop_Qt_6_2_2_MSVC2019_64bit-Debug/zakupy", ios::app);
    output << nazwa << endl;
    output << cena << "zł" << endl;
    output << nKart << " w " << nPaczek << " paczkach" << endl;
    output << opis << endl;
    output << endl;
    output.close();
}

GraKarciana::GraKarciana() {}

GraKarciana::~GraKarciana() noexcept {}

// @brief konstruktor gry karcianej
// @param "nazwaKart" - nazwa gry karcianej
// @param "cenaKart" - cena gry karcianej
// @param "opisKart" - opis gry karcianej
// @param "liczbaKart" - liczba kart w paczce
// @param "liczbaPaczek" - liczba paczek
GraKarciana::GraKarciana(string nazwaKart, double cenaKart, string opisKart, int liczbaKart, int liczbaPaczek):
nKart(liczbaKart),
nPaczek(liczbaPaczek)
{
    nazwa = nazwaKart;
    cena = cenaKart;
    opis = opisKart;
}

// @brief przeciążony operator += który dodaje liczbę kart, paczek, i cenę (służy do kupowania wielu paczek tej samej gry karcianej na raz)
// @param "rhs" - gra karciana po prawej stronie operatora
GraKarciana GraKarciana::operator+=(const GraKarciana rhs) {
    this->nKart += rhs.nKart;
    this->nPaczek += rhs.nPaczek;
    this->cena += rhs.cena;
    return *this;
}

// @brief konstruktor, który przyjmuje string pobrany z pliku i przetwarza go tak aby dało się stworzyć obiekt
// @karam "dane" - string z danymi odczytanymi z pliku (przykładowo: Magic the Gathering;8;trading card game stworzony przez Wizards of the Coast;10;1)
GraKarciana::GraKarciana(string dane) {
    nazwa = "";
    string pomCena = "";
    opis = "";
    string pomLiczKart = "";
    string pomLiczPacz = "";
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
            else if (count == 1)
                pomCena = pomCena + x;
            else if (count == 2)
                opis = opis + x;
            else if (count == 3)
                pomLiczKart = pomLiczKart + x;
            else if (count == 4)
                pomLiczPacz = pomLiczPacz + x;
        }
    }
    cena = stod(pomCena);
    nKart = stoi(pomLiczKart);
    nPaczek = stoi(pomLiczPacz);
}

// @brief wypisuje informacje i opis gry
string GraKarciana::opisGry() {
    string ret;
    ret = nazwa + "\n";
    ret += to_string(cena) + "zl" + "\n";
    ret += to_string(nKart) + " w " + to_string(nPaczek) + " paczkach" + "\n";
    ret += opis;
    return ret;
}

// @brief operator kopiujący gry karciane
// @param "rhs" - obiekt po prawej stronie operatora
GraKarciana& GraKarciana::operator=(GraKarciana const &rhs){
    nazwa = rhs.nazwa;
    cena = rhs.cena;
    opis = rhs.opis;
    nPaczek = rhs.nPaczek;
    nKart = rhs.nKart;
    return * this;
}
