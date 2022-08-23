#ifndef CONNECTION_H
#define CONNECTION_H

#include "includes.h"


class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
