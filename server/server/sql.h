#ifndef SQL_H
#define SQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <string>

class SQL : public QObject
{
    Q_OBJECT

public:
    explicit SQL(QObject *parent = nullptr);
    bool initSql();
    void printStr(std::string str);
    bool open();
    bool close();
    bool isOnline(QString userName);

private:
    QSqlDatabase* db;
};

#endif // SQL_H
