#include "databasemanager.h"

DatabaseManager::DatabaseManager(QString hostName,
                                 QString databaseName,
                                 QString username,
                                 QString password)
{
    this->m_hostName = hostName;
    this->m_databaseName = databaseName;
    this->m_username = username;
    this->m_password = password;
}

void DatabaseManager::ConnectToMySqlDB()
{

     this->m_db = QSqlDatabase::addDatabase("QMYSQL");
     this->m_db.setHostName(this->m_hostName);
     this->m_db.setDatabaseName(this->m_databaseName);
     this->m_db.setUserName(m_username);
     this->m_db.setPassword(this->m_password);
     this->m_ok = m_db.open();
     if(m_ok)
         qDebug() << "Connection OK.";
     else
         qDebug() << "Connection couldnt be established.";

}

void DatabaseManager::InsertData(QString username, QString password, QString website)
{
     QSqlQuery query;
     query.prepare("INSERT INTO userinfo (username, password, website) "
                   "VALUES (:username, :password, :website)");

     //qDebug() << "Inside the DatabaseManager::InsertData Function:" << '\n';
     //qDebug() << username << " " << password << '\n';

     query.bindValue(":username", username);
     query.bindValue(":password", password);
     query.bindValue(":website", website);

     query.exec();
}

std::vector<std::vector<QString>> DatabaseManager::GetAllData()
{
    if(m_db.isOpen())
    {

        QSqlQuery query("SELECT * FROM userinfo");

        int username_no = query.record().indexOf("username");
        int password_no = query.record().indexOf("password");
        int website_no = query.record().indexOf("website");

        while(query.next())
        {
            QString username = query.value(username_no).toString();
            QString password = query.value(password_no).toString();
            QString m_website = query.value(website_no).toString();

            m_usernames.push_back(username);
            m_passwords.push_back(password);
            m_websites.push_back(m_website);

            //qDebug() << user_id << " " << username << " " << password << '\n';

        }
    }

    std::vector<std::vector<QString>> temp;
    temp.push_back(m_usernames);
    temp.push_back(m_passwords);
    temp.push_back(m_websites);

    return temp;
}


