#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refresh();
    ui->stackedWidget->setCurrentIndex(0); //menu

    ui->cbCSort->addItem("Firstname");
    ui->cbCSort->addItem("Lastname");
    ui->cbCSort->addItem("Adress");
    ui->cbCSort->addItem("Cin");
    ui->cbCSort->addItem("Email");

    ui->cbPSort->addItem("Date");
    ui->cbPSort->addItem("Etat");

    ui->cbEtatAddp->addItem("disponible");
    ui->cbEtatAddp->addItem("non-disponible");

    ui->cbEtatUpdatep->addItem("disponible");
    ui->cbEtatUpdatep->addItem("non-disponible");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
{
    ui->tvClient->setModel(_client.read());
    ui->tvParking->setModel(_parking.read());
   _client.comboBoxId(ui->cbClientidAddp, ui->cbClientAddP);
   _client.comboBoxId(ui->cbClientidUpdatep, ui->cbClientUpdateP);
}

void MainWindow::on_btnClient_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //Client
}

void MainWindow::on_btnParking_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //Parking

}

void MainWindow::on_btnRetour2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnAddClient_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Add Client
}


void MainWindow::on_leSearchClient_textChanged(const QString &arg1)
{
    ui->tvClient->setModel(_client.search(arg1));
}


void MainWindow::on_btnAddCRetour_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(1); //Client
}


void MainWindow::on_btnAddC_clicked()
{
    QString firstname = ui->leAddCFirst->text();
    QString lastname = ui->leAddCLast->text();
    QString adress = ui->leAddCAdress->text();
    QString cin = ui->leAddCCIN->text();
    QString email = ui->leAddCEmail->text();
    if (firstname != "" && lastname != "" && adress != "" && cin != "" && email != "") {
        Client c = Client(0, firstname, lastname, adress, cin, email);
        if (c.add()) {
            QMessageBox::information(nullptr, QObject::tr("Ajouter Client"),
                        QObject::tr("Client added successfuly "), QMessageBox::Ok);
            refresh();
            ui->stackedWidget->setCurrentIndex(1);
            ui->leAddCFirst->setText("");
            ui->leAddCLast->setText("");
            ui->leAddCAdress->setText("");
            ui->leAddCCIN->setText("");
            ui->leAddCEmail->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                        QObject::tr("Error 8152"), QMessageBox::Cancel);
        }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                    QObject::tr("Error: Empty fields"), QMessageBox::Cancel);
    }
}


void MainWindow::on_btnUpdateRetour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //Client
}

void MainWindow::on_btnAddCRetour_2_clicked()
{
    //chaalik
}


void MainWindow::on_btnUpdateC_clicked()
{
    QString firstname = ui->leAddCFirst_2->text();
    QString lastname = ui->leAddCLast_2->text();
    QString adress = ui->leAddCAdress_2->text();
    QString cin = ui->leAddCCIN_2->text();
    QString email = ui->leAddCEmail_2->text();
    if (firstname != "" && lastname != "" && adress != "" && cin != "" && email != "") {
        _client.setFirstname(firstname);
        _client.setLastname(lastname);
        _client.setAdress(adress);
        _client.setCin(cin);
        _client.setEmail(email);
        if (_client.update()) {
            QMessageBox::information(nullptr, QObject::tr("Modifier Client"),
                        QObject::tr("Client Updated successfuly "), QMessageBox::Ok);
            refresh();
            ui->stackedWidget->setCurrentIndex(1);
            ui->leAddCFirst_2->setText("");
            ui->leAddCLast_2->setText("");
            ui->leAddCAdress_2->setText("");
            ui->leAddCCIN_2->setText("");
            ui->leAddCEmail_2->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Modifier Client"),
                        QObject::tr("Error 6487"), QMessageBox::Cancel);
        }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Client"),
                    QObject::tr("Error: Empty fields"), QMessageBox::Cancel);
    }
}


void MainWindow::on_tvClient_doubleClicked(const QModelIndex &index)
{
    int id = ui->tvClient->model()->index(index.row(), 0).data().toInt();
    QString firstname = ui->tvClient->model()->index(index.row(), 1).data().toString();
    QString lastname = ui->tvClient->model()->index(index.row(), 2).data().toString();
    QString adress = ui->tvClient->model()->index(index.row(), 3).data().toString();
    QString cin = ui->tvClient->model()->index(index.row(), 4).data().toString();
    QString email = ui->tvClient->model()->index(index.row(), 5).data().toString();
    _client.setId(id);
    _client.setFirstname(firstname);
    _client.setLastname(lastname);
    _client.setAdress(adress);
    _client.setCin(cin);
    _client.setEmail(email);
    ui->leAddCFirst_2->setText(firstname);
    ui->leAddCLast_2->setText(lastname);
    ui->leAddCAdress_2->setText(adress);
    ui->leAddCCIN_2->setText(cin);
    ui->leAddCEmail_2->setText(email);
    ui->stackedWidget->setCurrentIndex(4); // Update Client
}


void MainWindow::on_btnRemoveC_clicked()
{
    if (_client.remove()) {
        QMessageBox::information(nullptr, QObject::tr("Supprimer Client"),
                    QObject::tr("Client Removed successfuly "), QMessageBox::Ok);
        refresh();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Client"),
                    QObject::tr("Error 5148"), QMessageBox::Cancel);
    }
}


void MainWindow::on_cbCSort_currentTextChanged(const QString &arg1)
{
    ui->tvClient->setModel(_client.sort(arg1));
}


void MainWindow::on_leSearchParking_textChanged(const QString &arg1)
{
    ui->tvParking->setModel(_parking.search(arg1));
}


void MainWindow::on_cbPSort_currentTextChanged(const QString &arg1)
{
    ui->tvParking->setModel(_parking.sort(arg1));
}


void MainWindow::on_btnAddRetourP_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //Parking
}


void MainWindow::on_cbClientAddP_currentIndexChanged(int index)
{
    ui->cbClientidAddp->setCurrentIndex(index);
}


void MainWindow::on_btnAddP_clicked()
{
    QString date = ui->dateTimeEdit->text();
    QString etat = ui->cbEtatAddp->currentText();
    int idClient = ui->cbClientidAddp->currentText().toInt();

    Parking p = Parking(0, idClient, date, etat);
    if (p.add()) {
        QMessageBox::information(nullptr, QObject::tr("Ajouter Parking"),
            QObject::tr("Parking added successfuly "), QMessageBox::Ok);
        refresh();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Parking"),
            QObject::tr("Error 8152"), QMessageBox::Cancel);
    }
}


void MainWindow::on_btnAddParking_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); //Parking Add
}

void MainWindow::on_btnUpdateRetourP_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //Parking
}

void MainWindow::on_btnRemoveP_clicked()
{
    if (_parking.remove()) {
        QMessageBox::information(nullptr, QObject::tr("Supprimer Parking"),
                    QObject::tr("Parking Removed successfuly "), QMessageBox::Ok);
        refresh();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Parking"),
                    QObject::tr("Error 5148"), QMessageBox::Cancel);
    }
}


void MainWindow::on_btnUpdateP_clicked()
{
    _parking.setDate(ui->dteUpdateP->text());
    _parking.setEtat(ui->cbEtatUpdatep->currentText());
    _parking.setIdClient(ui->cbClientidUpdatep->currentText().toInt());

    if (_parking.update()) {
        QMessageBox::information(nullptr, QObject::tr("Modifier Parking"),
            QObject::tr("Parking updated successfuly "), QMessageBox::Ok);
        refresh();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Parking"),
            QObject::tr("Error 8152"), QMessageBox::Cancel);
    }
}


void MainWindow::on_tvParking_doubleClicked(const QModelIndex &index)
{
    int id = ui->tvParking->model()->index(index.row(), 0).data().toInt();
    QString date = ui->tvParking->model()->index(index.row(), 1).data().toString();
    QString etat = ui->tvParking->model()->index(index.row(), 2).data().toString();
    QString client = ui->tvParking->model()->index(index.row(), 3).data().toString();

    _parking.setId(id);

    QStringList pieces = date.split(" ");
    QString d = pieces.value(0);
    QString time = pieces.value(1);


    ui->dteUpdateP->setDate(QDate::fromString(d, "dd/MM/yyyy"));
    ui->dteUpdateP->setTime(QTime::fromString(time, "hh:mm"));
    ui->cbClientUpdateP->setCurrentText(client);
    ui->cbEtatUpdatep->setCurrentText(etat);

    ui->stackedWidget->setCurrentIndex(6);

}


void MainWindow::on_cbClientUpdateP_currentIndexChanged(int index)
{
    ui->cbClientidUpdatep->setCurrentIndex(index);
}

