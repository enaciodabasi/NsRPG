#include "userinfowidget.h"

UserInfoWidget::UserInfoWidget(QWidget* parent) : QWidget(parent)
{

    m_mainLayout = new QVBoxLayout();
    m_btnLayout = new QHBoxLayout();
    m_filterLayout = new QHBoxLayout();

    m_showAllBtn = new QPushButton("Show saved passwords");
    m_btnLayout->addWidget(m_showAllBtn);

    m_hideAllBtn = new QPushButton("Hide passwords");
    m_btnLayout->addWidget(m_hideAllBtn);

    m_filterLEdit = new QLineEdit();
    m_filterBtn = new QPushButton("Filter passwords");
    m_filterLayout->addWidget(m_filterLEdit);
    m_filterLayout->addWidget(m_filterBtn);

    m_mainLayout->addLayout(m_filterLayout);
    m_mainLayout->addLayout(m_btnLayout);

    m_tempLabel = new QLabel();
    m_tempLabel->setAutoFillBackground(true);
    m_tempLabel->setPalette(m_whiteBgPalette);
    m_mainLayout->addWidget(m_tempLabel);

    this->setLayout(m_mainLayout);

}


void UserInfoWidget::OnShowAllBtn()
{
    delete this->m_tempLabel;

    this->itemCount = this->m_usernames.size();
    //qDebug() << itemCount;
    m_userInfoTable = new QTableWidget(itemCount, 3, this);
    m_userInfoTable->setHorizontalHeaderLabels(m_horizontalHeaderLabels);


    for(int i = 0; i < itemCount; i++)
    {
        //m_userInfoTable->setItem(i, 0, new QTableWidgetItem(i));
        m_userInfoTable->setItem(i, 1, new QTableWidgetItem(m_usernames.at(i)));
        m_userInfoTable->setItem(i, 2, new QTableWidgetItem(m_passwords.at(i)));
        m_userInfoTable->setItem(i, 0, new QTableWidgetItem(m_websites.at(i)));
        //qDebug() << m_usernames[i] << m_passwords[i] << '\n';

    }

    this->m_mainLayout->addWidget(m_userInfoTable);
}

void UserInfoWidget::SetUserInfo(std::vector<std::vector<QString>> infos)
{
        this->m_usernames = infos[0];
        this->m_passwords = infos[1];
        this->m_websites = infos[2];

        //qDebug() << "Size of usernames: " << m_usernames.size() << '\n';
        //for(auto i : m_usernames)
        //    qDebug() << i;
        //for(auto i : m_passwords)
        //    qDebug() << i;
}

void UserInfoWidget::OnFilterBtn()
{

}
