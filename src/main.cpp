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
    if(operacja == "tablica"){
        for (int i = 0; i < 100; i++){
            cout << "nauraa";
        }
    }
}
