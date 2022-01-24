#include "grykomputeroweokno.h"
#include "ui_grykomputeroweokno.h"

GryKomputeroweOkno::GryKomputeroweOkno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GryKomputeroweOkno)
{
    ui->setupUi(this);
}

GryKomputeroweOkno::~GryKomputeroweOkno()
{
    delete ui;
}

// @brief obsługa przycisku - dodaje gre komputerowa do koszyka
void GryKomputeroweOkno::on_DodajDoKoszyka_pushButton_clicked()
{
    int tmp = ui->listWidget->currentRow();
    koszyk->dodajProdukt(&polkaKomputerowe.at(tmp));
}

// @brief obsługa przycisku - zamyka okno
void GryKomputeroweOkno::on_Powrot_pushButton_clicked()
{
    this->close();
}

// @brief obsługa przycisku - wyswietla opis gry
void GryKomputeroweOkno::on_WyswietlOpis_pushButton_clicked()
{
    int tmp = ui->listWidget->currentRow();
    string opis = polkaKomputerowe.at(tmp).opisGry();
    QString temp = QString::fromStdString(opis);
    QMessageBox::information(this,"opis gry",temp);
}

// @brief udostępnia vectory z mainWindow do okna gier komputerowych
void GryKomputeroweOkno::setVector(ListaZakupow* koszyk, vector<GraKomputerowa> polkaKomputerowe){
    this->koszyk = koszyk;
    this->polkaKomputerowe = polkaKomputerowe;
}

// @brief wczytuje nazwy gier z vectora do listWitget
void GryKomputeroweOkno::wczytajVectora(){
    QString temp;
    int lenght = polkaKomputerowe.size();
    for(int i = 0; i < lenght; i++){
          temp = QString::fromUtf8(polkaKomputerowe.at(i).nazwa);
          ui->listWidget->addItem(temp);
    }
}
