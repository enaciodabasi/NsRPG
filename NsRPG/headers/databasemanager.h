#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QVector>
#include <QString>
#include <iostream>
#include <vector>
#include <string>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>


class DatabaseManager
{

    // Constructors
public:
    DatabaseManager(QString hostName,
                    QString databaseName,
                    QString username,
                    QString password);

    // Member variables
private:

    QSqlDatabase m_db;
    QString m_hostName;
    QString m_databaseName;
    QString m_username;
    QString m_password;
    bool m_ok;

    std::vector<QString> m_usernames;
    std::vector<QString> m_passwords;
    std::vector<QString> m_websites;

    // Functions
public:

    void ConnectToMySqlDB();
    void InsertData(QString username, QString password, QString website);
    std::vector<std::vector<QString>> GetAllData();


};

#endif // DATABASEMANAGER_H
