#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refresh();

private slots:
    void on_btnClient_clicked();

    void on_btnParking_clicked();

    void on_btnRetour2_clicked();

    void on_btnRetour1_clicked();

    void on_btnAddClient_clicked();

    void on_leSearchClient_textChanged(const QString &arg1);

    void on_btnAddCRetour_clicked(bool checked);

    void on_btnAddC_clicked();

    void on_btnUpdateRetour_clicked();

    void on_btnAddCRetour_2_clicked();

    void on_btnUpdateC_clicked();

    void on_tvClient_doubleClicked(const QModelIndex &index);

    void on_btnRemoveC_clicked();

    void on_cbCSort_currentTextChanged(const QString &arg1);

    void on_leSearchParking_textChanged(const QString &arg1);

    void on_cbPSort_currentTextChanged(const QString &arg1);

    void on_btnAddRetourP_clicked();

    void on_cbClientAddP_currentIndexChanged(int index);

    void on_btnAddP_clicked();

    void on_btnAddParking_clicked();

    void on_btnUpdateRetourP_clicked();

    void on_btnRemoveP_clicked();

    void on_btnUpdateP_clicked();

    void on_tvParking_doubleClicked(const QModelIndex &index);

    void on_cbClientUpdateP_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Client _client;
    Parking _parking;
};
#endif // MAINWINDOW_H
