#include "grykarcianeokno.h"
#include "ui_grykarcianeokno.h"


GryKarcianeOkno::GryKarcianeOkno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GryKarcianeOkno)
{
    ui->setupUi(this);
}

GryKarcianeOkno::~GryKarcianeOkno()
{
    delete ui;
}

// @brief obsługa przycisku
void GryKarcianeOkno::on_DodajDoKoszyka_pushButton_clicked()
{
    Pomocniczy = new GraKarciana;
    bool success = 1;
    int temp;
    try{
        temp = ui->spinBox->value();
            if(temp > 30){
                throw Exception("Nie ma tylu paczek!");
            }
    }
    catch(Exception exec){
        success = 0;
        QString WarningMessege = QString::fromStdString(exec.what());
        QMessageBox::warning(this,"Uwaga!",WarningMessege);
    }
    if(success == 1){
        int tmp = ui->listWidget->currentRow();
        GraKarciana pom = polkaKarciane.at(tmp);
        *Pomocniczy = pom;
        for(int i = 1; i < temp ; ++i){
            *Pomocniczy += pom;
        }
        koszyk->dodajProdukt(Pomocniczy);
    }
}

// @brief obsługa przycisku
void GryKarcianeOkno::on_Powrot_pushButton_clicked()
{
    this->close();
}

// @brief obsługa przycisku
void GryKarcianeOkno::on_OpisGry_pushButton_clicked()
{
    int tmp = ui->listWidget->currentRow();
    string opis = polkaKarciane.at(tmp).opisGry();
    QString temp = QString::fromStdString(opis);
    QMessageBox::information(this,"opis gry",temp);
}

// @brief udostępnia vectory z mainWindow do okna gier karcianych
void GryKarcianeOkno::setVector(ListaZakupow* koszyk, vector<GraKarciana> polkaKarciane){
    this->koszyk = koszyk;
    this->polkaKarciane = polkaKarciane;
}

// @brief wczytuje nazwy gier z vectora do listWitget
void GryKarcianeOkno::wczytajVectora(){
    QString temp;
    int lenght = polkaKarciane.size();
    for(int i = 0; i < lenght; i++){
          temp = QString::fromUtf8(polkaKarciane.at(i).nazwa);
          ui->listWidget->addItem(temp);
    }
}
