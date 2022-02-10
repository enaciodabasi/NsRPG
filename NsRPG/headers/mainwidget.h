#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "passwordgenerator.h"
#include "databasemanager.h"
#include "userinfowidget.h"


#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QFormLayout>
#include <QDebug>
#include <QLabel>


class PasswordGenerator;
class DatabaseManager;

class MainWidget : public QWidget
{
private:

    Q_OBJECT

public:


    MainWidget(QWidget *parent = nullptr); // Default constructor to show before login / Could be changed later

    // Variables:
private:

    PasswordGenerator* m_pg = nullptr;
    UserInfoWidget* m_uig = nullptr;
    DatabaseManager* m_dbm = nullptr;
    // Temporary database identifiers:
    QString hostname = "localhost";
    QString dbname = "nsrpg_db";
    QString username = "nsrpg_user";
    QString pass = "admin123";


    QHBoxLayout* m_mainLayout;
    QVBoxLayout* m_vlayout;
    QPushButton* m_saveInfoBtn;

    // Functions:
public:

    void TransferData();
    void OnSaveInformationBtn();

};

#endif // MAINWIDGET_H
