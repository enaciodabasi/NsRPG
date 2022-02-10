#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QPalette>
#include <vector>
#include <QString>
#include <QLineEdit>
#include <QTableWidgetItem>
#include <QDebug>
#include <QStringList>
#include <QList>

class UserInfoWidget : public QWidget
{
    Q_OBJECT
public:
    UserInfoWidget(QWidget *parent = nullptr);

private:

    QVBoxLayout* m_mainLayout;
    QHBoxLayout* m_btnLayout;
    QHBoxLayout* m_filterLayout;

    QPushButton* m_hideAllBtn;
    QPushButton* m_filterBtn;

    QLineEdit* m_filterLEdit;

    QTableWidget* m_userInfoTable;
    QLabel* m_tempLabel;
    QPalette m_whiteBgPalette = QPalette(QPalette::Window, Qt::white);
    QStringList m_horizontalHeaderLabels = {"Website", "Username", "Password"};

    std::vector<QString> m_usernames;
    std::vector<QString> m_passwords;
    std::vector<QString> m_websites;
    int itemCount;

public:

    QPushButton* m_showAllBtn;

public:

    void OnShowAllBtn();
    void OnHideAllBtn();
    void OnFilterBtn();
    void SetUserInfo(std::vector<std::vector<QString>> infos);


};

#endif // USERINFOWIDGET_H
