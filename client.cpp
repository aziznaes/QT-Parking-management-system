#include "client.h"

int Client::getId() const
{
    return id;
}

void Client::setId(int newId)
{
    id = newId;
}

const QString &Client::getFirstname() const
{
    return firstname;
}

void Client::setFirstname(const QString &newFirstname)
{
    firstname = newFirstname;
}

const QString &Client::getLastname() const
{
    return lastname;
}

void Client::setLastname(const QString &newLastname)
{
    lastname = newLastname;
}

const QString &Client::getAdress() const
{
    return adress;
}

void Client::setAdress(const QString &newAdress)
{
    adress = newAdress;
}

const QString &Client::getCin() const
{
    return cin;
}

void Client::setCin(const QString &newCin)
{
    cin = newCin;
}

const QString &Client::getEmail() const
{
    return email;
}

void Client::setEmail(const QString &newEmail)
{
    email = newEmail;
}

Client::Client()
{
}

Client::Client(int id, const QString &firstname, const QString &lastname, const QString &adress, const QString &cin, const QString &email) : id(id),
    firstname(firstname),
    lastname(lastname),
    adress(adress),
    cin(cin),
    email(email)
{}

bool Client::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO client (firstname, lastname, adress, cin, email) VALUES( ?, ?, ?, ?, ? )");
    query.addBindValue(this->firstname);
    query.addBindValue(this->lastname);
    query.addBindValue(this->adress);
    query.addBindValue(this->cin);
    query.addBindValue(this->email);

    return query.exec();
}

bool Client::update()
{
    QSqlQuery query;
    query.prepare("UPDATE client SET firstname=?, lastname=?, adress=?, cin=?, email=? WhERE id = ?");
    query.addBindValue(this->firstname);
    query.addBindValue(this->lastname);
    query.addBindValue(this->adress);
    query.addBindValue(this->cin);
    query.addBindValue(this->email);
    query.addBindValue(this->id);

    return query.exec();
}

bool Client::remove()
{
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id = ?");
    query.addBindValue(this->id);

    return query.exec();
}

QSqlQueryModel *Client::read()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fisrtname"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LastName"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

QSqlQueryModel *Client::search(QString input)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE firstname LIKE ? OR lastname LIKE ? OR adress LIKE ? OR cin LIKE ? OR email LIKE ? OR id LIKE ?");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");
    query.addBindValue("%"+input+"%");

    query.exec();

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fisrtname"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LastName"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

QSqlQueryModel *Client::sort(QString input)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM client ORDER BY "+input);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("#"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fisrtname"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LastName"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}


void Client::comboBoxId(QComboBox * cmbbId, QComboBox * cmbbName)
{
    cmbbId->clear();
    cmbbName->clear();
    QSqlQuery query;
    query.prepare("SELECT id, CONCAT(firstname, ' ', lastname) FROM client");
    query.exec();
    while(query.next()) {
        cmbbId->addItem(query.value(0).toString());
        cmbbName->addItem(query.value(1).toString());
    }
}

