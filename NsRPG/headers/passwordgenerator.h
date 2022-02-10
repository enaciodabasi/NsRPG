#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include "mainwidget.h"

#include <QObject>
#include <QWidget>
#include <QString>
#include <string>
#include <iostream>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QSizePolicy>
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <random>

class PasswordGenerator : public QWidget
{
    Q_OBJECT
public:
    PasswordGenerator(QWidget *parent = nullptr);

    // Member variables:
private:

    QString m_RandomPassword;

    QVBoxLayout* m_pgMainLayout;
    QFormLayout* m_informationDisplayLayout;
    QHBoxLayout* m_radioBtnLayout;
    QLineEdit* m_randomPasswordLedit;
    QLineEdit* m_emailLEdit;
    QLineEdit* m_websiteLEdit;
    QRadioButton* m_length16;
    QRadioButton* m_length12;
    QLabel* m_informativeText;
    QPushButton* m_generatePassBtn;

    std::array<unsigned char, 63> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', ':', ';', '!', '?', '*', '/', '-', '_', '|', '#', '+', '%', '&', '(', ')', '=', '[', ']', '{', '}', '~', '@', '<', '>', '"'};

public:

    QString m_username;
    QString m_password;
    QString m_website;

    std::vector<QString> m_passwords;

    // Functions:
public:

    void GenerateRandomPassword();
    void SetUserInformation();

signals:

};

#endif // PASSWORDGENERATOR_H
