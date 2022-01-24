#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    string operacja = argv[1];
    if(operacja == "sklep"){
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    else if(operacja == "argument"){
        for (int i = 0; i < 100; i++){
            cout << "czesc nie mialem pomyslu na obsluge argumentu wiec wyswietla sie ta wiadomosc 100 razy zycze milego dnia ";
        }
    }
    else {
        cout << "nie podano argumentu" << endl;
        return 0;
    }
}
