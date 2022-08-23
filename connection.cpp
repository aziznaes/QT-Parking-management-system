#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("projetqt");
    db.setUserName("root");
    db.setPassword("");
    db.setPort(3306);
    if (db.open())
        return true;
    return false;
}
void Connection::closeConnection(){db.close();}
