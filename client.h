#ifndef CLIENT_H
#define CLIENT_H

#include "includes.h"


class Client
{
private:
    int id;
    QString firstname;
    QString lastname;
    QString adress;
    QString cin;
    QString email;

public:
    Client();
    Client(int id, const QString &firstname, const QString &lastname, const QString &adress, const QString &cin, const QString &email);
    int getId() const;
    void setId(int newId);
    const QString &getFirstname() const;
    void setFirstname(const QString &newFirstname);
    const QString &getLastname() const;
    void setLastname(const QString &newLastname);
    const QString &getAdress() const;
    void setAdress(const QString &newAdress);
    const QString &getCin() const;
    void setCin(const QString &newCin);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);

    bool add();
    bool update();
    bool remove();
    QSqlQueryModel * read();
    void comboBoxId(QComboBox *, QComboBox *);
    QSqlQueryModel * search(QString input);
    QSqlQueryModel * sort(QString input);
};

#endif // CLIENT_H
