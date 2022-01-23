#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./system.h"
#include "./grykarcianeokno.h"
#include "./grykomputeroweokno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_zakup_pushButton_clicked();

    void on_wyswietlKomputerowe_pushButton_clicked();

    void on_wyswietlKarciane_pushButton_clicked();

    void on_wyswietlOpis_pushButton_clicked();

    void on_actionOdswierz_triggered();

private:
    Ui::MainWindow *ui;
    bool KarcianeZaladowane = 0;
    bool KomputeroweZaladowane = 0;
    GryKarcianeOkno oknoKarciane;
    GryKomputeroweOkno oknoKomputerowe;
    vector<GraKomputerowa> polkaKomputerowe;
    vector<GraKarciana> polkaKarciane;
    ListaZakupow lista;
};
#endif // MAINWINDOW_H
