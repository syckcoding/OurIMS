#ifndef CREATCONNECTION_H
#define CREATCONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

static bool creatConnection(){
    QSqlDatabase dbcon;
    dbcon = QSqlDatabase::addDatabase("QODBC");  // ODBC 驱动
    dbcon.setHostName("127.0.0.1");                // MySQL 服务器ip地址，本机
    dbcon.setPort(3306);                          // 端口号，默认
    dbcon.setDatabaseName("OurIMS");           // ODBC 数据源名称
    bool ok = dbcon.open();
    if(!ok)
        qDebug() << "Error,  studentdatabase fails to open!";
    else
        qDebug() << "Success, studentdatabase open!";

    return ok;
}

#endif // CREATCONNECTION_H
