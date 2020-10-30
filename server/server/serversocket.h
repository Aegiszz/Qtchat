#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <sql.h>

class ServerSocket : public QTcpServer
{
    Q_OBJECT

public:
    ServerSocket();
private:
    SQL* sql;
};

#endif // SERVERSOCKET_H
