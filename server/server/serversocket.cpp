#include "serversocket.h"
#include "sql.h"

ServerSocket::ServerSocket(){
    sql =new SQL();
    sql->initSql();
    sql->open();
}
