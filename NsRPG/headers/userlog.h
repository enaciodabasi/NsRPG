#ifndef USERLOG_H
#define USERLOG_H

#include <QWidget>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>

// to do
// actually construct an user class to store information
// serialize the user objects for later use
// add a true check mechanism

class UserLog : public QDockWidget
{
public:
    UserLog(QWidget* parent = nullptr);

    // Inner classes
public:

    // Class for user login screen
    class UserLogin : public QWidget
    {
    public:


        // Constructor and Deconstructor:
    public:
        UserLogin(QWidget* parent = nullptr);

        // Class members:
    private:
        QVBoxLayout* m_userLoginLayout;
        QFormLayout* m_userInfoInputLayout;
        QLineEdit* m_emailInput;
        QLineEdit* m_passwordInput;
        QLabel* m_logintext;

    public:
        QPushButton* m_loginBtn;

        // Functions:
    public:


    };

    // Class to display user info
    class UserInfo : public QWidget
    {
        // Constructors and Deconstruct
    public:

        UserInfo(QWidget* parent = nullptr);

        // Class member variables:
    private:

        QGridLayout* m_iconLayout; // To place the user icon in the middle ??
        QVBoxLayout* m_userInfoMainLayout; // Main layout of the widget
        QFormLayout* m_userInfolayout;
        QLineEdit* m_emailLEdit;
        QLineEdit* m_passwordLEdit;
        QPixmap* m_usericon;

    public:
        QPushButton* m_logoutBtn;


        // Functions:
    public:

    };

    // Class members:
private:

    QVBoxLayout* m_dockMainLayout;
    UserLogin* m_loginWidget;
    UserInfo* m_userInfoWidget;
    QMessageBox m_logoutMsgBox;
    QMessageBox m_loginErrorMsgBox;

    bool m_isLoginSuccess = true;
    bool m_isLogoutCertain = false;

    // Functions:
public:

    void InitLogoutMsg(QMessageBox& msg);
    void InitLoginErrorMsg(QMessageBox& msg);

    void OnSuccessfulLogin();
    void OnLogoutBtnClicked();

};

#endif // USERLOG_H
