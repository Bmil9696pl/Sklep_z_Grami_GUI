#ifndef GRYKOMPUTEROWEOKNO_H
#define GRYKOMPUTEROWEOKNO_H

#include <QWidget>
#include "./system.h"
#include "QMessageBox"



namespace Ui {
class GryKomputeroweOkno;
}

class GryKomputeroweOkno : public QWidget
{
    Q_OBJECT

public:
    explicit GryKomputeroweOkno(QWidget *parent = nullptr);
    ~GryKomputeroweOkno();
    void setVector(ListaZakupow* koszyk, vector<GraKomputerowa> polkaKomputerowe);
    void wczytajVectora();

private slots:
    void on_DodajDoKoszyka_pushButton_clicked();

    void on_Powrot_pushButton_clicked();

    void on_WyswietlOpis_pushButton_clicked();

private:
    Ui::GryKomputeroweOkno *ui;
    ListaZakupow* koszyk;
    vector<GraKomputerowa> polkaKomputerowe;
};

#endif // GRYKOMPUTEROWEOKNO_H
