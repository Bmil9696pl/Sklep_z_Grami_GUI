#include "../include/Exception.h"

// @brief konstruktor dla klasy Exeception
// @param "msg" - string z wiadomością błędu
Exception::Exception(string msg):wiadomosc(msg) {}

// @brief zwrócenie wiadomosci
string Exception::what() {
    return wiadomosc;
}
