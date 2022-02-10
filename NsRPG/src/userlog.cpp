#include "userlog.h"

UserLog::UserLog(QWidget* parent)
    : QDockWidget(tr("User Log"), parent)
{

    //m_dockMainLayout = new QVBoxLayout();

    this->setAllowedAreas(Qt::RightDockWidgetArea |
                                   Qt::LeftDockWidgetArea);
    this->setFloating(false);

    m_loginWidget = new UserLogin(this);
    this->setWidget(m_loginWidget);

    QObject::connect(this->m_loginWidget->m_loginBtn,
                     &QPushButton::clicked,
                     this,
                     &UserLog::OnSuccessfulLogin);   
}

UserLog::UserLogin::UserLogin(QWidget* parent)
    : QWidget(parent)
{

    m_userLoginLayout = new QVBoxLayout();
    m_userInfoInputLayout = new QFormLayout();
    m_loginBtn = new QPushButton("Login");

    m_emailInput = new QLineEdit();
    m_passwordInput = new QLineEdit();

    m_userInfoInputLayout->addRow(tr("E-Mail"), m_emailInput);
    m_userInfoInputLayout->addRow(tr("Password"), m_passwordInput);

    m_userLoginLayout->addLayout(m_userInfoInputLayout);
    m_userLoginLayout->addWidget(m_loginBtn);

    this->setLayout(m_userLoginLayout);
}

UserLog::UserInfo::UserInfo(QWidget *parent)
    :QWidget(parent)
{

    m_userInfoMainLayout = new QVBoxLayout();
    m_iconLayout = new QGridLayout();
    m_userInfolayout = new QFormLayout();

    m_emailLEdit = new QLineEdit();
    m_emailLEdit->setReadOnly(true);
    m_passwordLEdit = new QLineEdit();
    m_passwordLEdit->setReadOnly(true);

    m_userInfolayout->addRow(tr("E-Mail:"), m_emailLEdit);
    m_userInfoMainLayout->addLayout(m_userInfolayout);

    m_logoutBtn = new QPushButton("Logout");
    m_userInfolayout->addWidget(m_logoutBtn);

    this->setLayout(m_userInfoMainLayout);

}

void UserLog::InitLoginErrorMsg(QMessageBox &msg)
{
    msg.setText("Error");
    msg.setInformativeText("Email or Password is wrong.");
}

void UserLog::InitLogoutMsg(QMessageBox &msg)
{
    msg.setText("Logout from your NSRPG Account");
    msg.setInformativeText("Are you certain?");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Cancel);
}
void UserLog::OnSuccessfulLogin()
{


    if(this->m_isLoginSuccess)
    {
        delete this->m_loginWidget;

        this->m_userInfoWidget = new UserInfo(this);
        // Check for nullptr init.
        if(this->m_userInfoWidget != nullptr)
            this->setWidget(m_userInfoWidget);

        QObject::connect(this->m_userInfoWidget->m_logoutBtn,
                         &QPushButton::clicked,
                         this,
                         &UserLog::OnLogoutBtnClicked);
    }
    else
    {
        // Display error dialog
        InitLoginErrorMsg(this->m_loginErrorMsgBox);
        this->m_loginErrorMsgBox.exec();
    }
}


void UserLog::OnLogoutBtnClicked()
{

    InitLogoutMsg(this->m_logoutMsgBox);
    int ret = this->m_logoutMsgBox.exec();

    if(ret == QMessageBox::Ok)
    {
        delete this->m_userInfoWidget;

        this->m_loginWidget = new UserLogin(this);
        if(this->m_loginWidget != nullptr)
            this->setWidget(m_loginWidget);

    }
    else if(ret == QMessageBox::Cancel)
    {
        ;
    }
}
