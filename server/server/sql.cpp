#include "sql.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>

SQL::SQL(QObject *parent) : QObject(parent){}

bool SQL::initSql(){
    if(QSqlDatabase::contains("ChatUsers")){
        this->printStr("数据库已经连接，无需再次初始化");
        return true;
    }else{
        this->db=new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
        this->db->setDatabaseName("ChatUsers.db");
        if(db->open()){
            this->close();
            this->printStr("数据库初始化成功");
            return true;
        }else{
            this->printStr("数据库初始化失败");
            return false;
        }
    }
}

bool SQL::open(){
    if(db->isValid() && !db->isOpen()){
        if(db->open()){
            printStr("数据库开启成功");
            return true;
        }else{
            printStr("数据库开启失败");
            return false;
        }
    }else{
        printStr("数据库开启失败");
        return false;
    }
}

bool SQL::close(){
    if(db->isValid() && db->open()){
        QSqlQuery query;
        query.exec("delete from onlineUser");
        db->close();
        printStr("数据库关闭成功");
        return true;
    }
    else{
        printStr("数据库关闭失败");
        return false;
    }
}

bool SQL::isOnline(QString userName){
    if(!db->open()){
        printStr("服务器数据库未打开，无法处理查询业务");
        return false;
    }else{
        QSqlQuery query;
        QString str="select * from onlineUser where 用户名="+userName+";";
        query.exec(str);
        if(query.first()){
            printStr(userName.toStdString()+"在线");
            return true;
        }else{
            printStr(userName.toStdString()+"离线");
            return false;
        }
    }
}

void SQL::printStr(std::string str){
    std::string nowtime=QDateTime::currentDateTime().toString().toLocal8Bit().toStdString();
    std::cout<<nowtime<<" : "<<QString::fromStdString(str).toLocal8Bit().toStdString();
}
