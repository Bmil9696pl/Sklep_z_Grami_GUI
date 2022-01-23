#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    polkaKarciane = zaladojPolki<GraKarciana>("C:/Users/bartek-tominek/Documents/build-Sklep_z_Grami-Desktop_Qt_6_2_2_MSVC2019_64bit-Debug/graKarty");
    polkaKomputerowe = zaladojPolki<GraKomputerowa>("C:/Users/bartek-tominek/Documents/build-Sklep_z_Grami-Desktop_Qt_6_2_2_MSVC2019_64bit-Debug/graKomputerowa");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// @brief "kupuje" rzeczy z koszyka czyli zapisuje je w pliku
void MainWindow::on_zakup_pushButton_clicked()
{
    lista.zapisz();
}

// @brief wyswietla okno z grami kompyterowymi
void MainWindow::on_wyswietlKomputerowe_pushButton_clicked()
{
    if(KomputeroweZaladowane == 0){
        oknoKomputerowe.setVector(&lista, polkaKomputerowe);
        oknoKomputerowe.wczytajVectora();
        KomputeroweZaladowane = 1;
    }
    oknoKomputerowe.show();
}

// @brief wyswietla okno z grami karcianymi
void MainWindow::on_wyswietlKarciane_pushButton_clicked()
{
    if(KarcianeZaladowane == 0){
        oknoKarciane.setVector(&lista, polkaKarciane);
        oknoKarciane.wczytajVectora();
        KarcianeZaladowane = 1;
    }
    oknoKarciane.show();
}

// @brief wyświetla opis zaznaczonej gry
void MainWindow::on_wyswietlOpis_pushButton_clicked()
{
    int tmp = ui->listWidget->currentRow();
    string opis = lista.Koszyk.at(tmp)->opisGry();
    QString temp = QString::fromStdString(opis);
    QMessageBox::information(this,"opis gry",temp);
}

void MainWindow::on_actionOdswierz_triggered()
{
    ui->listWidget->clear();
    QString temp;
    int length = lista.Koszyk.size();
    for(int i = 0; i < length; i++){
        temp = QString::fromUtf8(lista.Koszyk.at(i)->nazwa);
        ui->listWidget->addItem(temp);
    }
}

