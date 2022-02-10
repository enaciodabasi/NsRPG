#include "mainwidget.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
    m_mainLayout = new QHBoxLayout();

    m_pg = new PasswordGenerator(parent);
    m_vlayout = new QVBoxLayout();
    m_vlayout->addWidget(m_pg);

    m_saveInfoBtn = new QPushButton("Save password");
    m_vlayout->addWidget(m_saveInfoBtn);

    m_mainLayout->addLayout(m_vlayout);

    //m_emptyLabel = new QLabel();
    //m_emptyLabel->setStyleSheet("QLabel { background-color: white;}");
    //m_mainLayout->addWidget(m_emptyLabel);

    m_dbm = new DatabaseManager(hostname,
                                 dbname,
                                 username,
                                 pass);
    m_dbm->ConnectToMySqlDB();

    m_uig = new UserInfoWidget(parent);
    m_mainLayout->addWidget(m_uig);

    QObject::connect(m_uig->m_showAllBtn,
                     &QPushButton::clicked,
                     this,
                     &MainWidget::TransferData);

    QObject::connect(m_uig->m_showAllBtn,
                     &QPushButton::clicked,
                     m_uig,
                     &UserInfoWidget::OnShowAllBtn);

    QObject::connect(m_saveInfoBtn, &QPushButton::clicked,
                     this, &MainWidget::OnSaveInformationBtn);

    this->setLayout(m_mainLayout);
}

void MainWidget::TransferData()
{
   this->m_uig->SetUserInfo(m_dbm->GetAllData());
   this->m_pg->m_passwords = m_dbm->GetAllData().at(1);

}

void MainWidget::OnSaveInformationBtn()
{
    QString tempUsername = m_pg->m_username;
    QString tempPassword = m_pg->m_password;
    QString tempWebsite = m_pg->m_website;

    if(tempUsername == "" || tempPassword == "" || tempWebsite == "")
    {
        QMessageBox msgBox;
        msgBox.setText("Please enter an username and generate a password before saving your information.");
        msgBox.exec();
    }
    else
    {
    //
    //qDebug() << "Inside the MainWidget::OnSaveInformation Function:" << '\n';
    //qDebug() << tempUsername << " " << tempPassword << '\n';
    //

    this->m_dbm->InsertData(tempUsername, tempPassword, tempWebsite);
    }
}

