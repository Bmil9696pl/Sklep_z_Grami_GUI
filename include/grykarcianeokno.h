#ifndef GRYKARCIANEOKNO_H
#define GRYKARCIANEOKNO_H

#include <QWidget>
#include "system.h"
#include "QMessageBox"



namespace Ui {
class GryKarcianeOkno;
}

class GryKarcianeOkno : public QWidget
{
    Q_OBJECT

public:
    explicit GryKarcianeOkno(QWidget *parent = nullptr);
    ~GryKarcianeOkno();
    void setVector(ListaZakupow* koszyk ,vector<GraKarciana> polkaKarciane);
    void wczytajVectora();

private slots:
    void on_DodajDoKoszyka_pushButton_clicked();

    void on_Powrot_pushButton_clicked();

    void on_OpisGry_pushButton_clicked();

private:
    Ui::GryKarcianeOkno *ui;
    ListaZakupow* koszyk;
    vector<GraKarciana> polkaKarciane;
    GraKarciana* Pomocniczy;
};

#endif // GRYKARCIANEOKNO_H
