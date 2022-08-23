#ifndef PARKING_H
#define PARKING_H

#include "includes.h"

class Parking
{
private:
    int id;
    int idClient;
    QString date;
    QString etat;

public:
    Parking();
    Parking(int id, int idClient, const QString &date, const QString &etat);
    int getId() const;
    void setId(int newId);
    int getIdClient() const;
    void setIdClient(int newIdClient);
    const QString &getDate() const;
    void setDate(const QString &newDate);
    const QString &getEtat() const;
    void setEtat(const QString &newEtat);

    bool add();
    bool update();
    bool remove();
    QSqlQueryModel * read();
    QSqlQueryModel * search(QString input);
    QSqlQueryModel * sort(QString input);
};

#endif // PARKING_H
