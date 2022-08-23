#include "parking.h"

int Parking::getId() const
{
    return id;
}

void Parking::setId(int newId)
{
    id = newId;
}

int Parking::getIdClient() const
{
    return idClient;
}

void Parking::setIdClient(int newIdClient)
{
    idClient = newIdClient;
}

const QString &Parking::getDate() const
{
    return date;
}

void Parking::setDate(const QString &newDate)
{
    date = newDate;
}

const QString &Parking::getEtat() const
{
    return etat;
}

void Parking::setEtat(const QString &newEtat)
{
    etat = newEtat;
}

Parking::Parking()
{

}

Parking::Parking(int id, int idClient, const QString &date, const QString &etat) : id(id),
    idClient(idClient),
    date(date),
    etat(etat)
{}

bool Parking::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO parking (idClient, date, etat) VALUES( ?, ?, ? )");
    query.addBindValue(this->idClient);
    query.addBindValue(this->date);
    query.addBindValue(this->etat);

    return query.exec();
}

bool Parking::update()
{
    QSqlQuery query;
    query.prepare("UPDATE parking SET idClient=?, date=?, etat=? WhERE id = ?");
    query.addBindValue(this->idClient);
    query.addBindValue(this->date);
    query.addBindValue(this->etat);
    query.addBindValue(this->id);

    return query.exec();
}

bool Parking::remove()
{
    QSqlQuery query;
    query.prepare("DELETE FROM parking WHERE id = ?");
    query.addBindValue(this->id);

    return query.exec();
}

QSqlQueryModel *Parking::read()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT p.id, p.date, p.etat, CONCAT(c.firstname, ' ', c.lastname) FROM parking p LEFT JOIN client c ON p.idClient = c.id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Client"));

    return model;
}

QSqlQueryModel *Parking::search(QString input)
{
    QSqlQuery query;
    query.prepare("SELECT p.id, p.date, p.etat, CONCAT(c.firstname, ' ', c.lastname) FROM parking p LEFT JOIN client c ON p.idClient = c.id WHERE p.date LIKE ? OR p.etat LIKE ? OR CONCAT(c.firstname, ' ', c.lastname) LIKE ?");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");

    query.exec();

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Client"));

    return model;
}

QSqlQueryModel *Parking::sort(QString input)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT p.id, p.date, p.etat, CONCAT(c.firstname, ' ', c.lastname) FROM parking p LEFT JOIN client c ON p.idClient = c.id ORDER BY "+input);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Client"));

    return model;
}

