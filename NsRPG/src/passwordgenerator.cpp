#include "passwordgenerator.h"

PasswordGenerator::PasswordGenerator(QWidget *parent) : QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pgMainLayout = new QVBoxLayout();


    m_informativeText = new QLabel("Random Password Generator");
    m_informativeText->setFont(QFont("Arial", 15, QFont::Bold));
    m_pgMainLayout->addWidget(m_informativeText);

    m_radioBtnLayout = new QHBoxLayout();
    m_length12 = new QRadioButton("12 Characters");
    m_length16 = new QRadioButton("16 Characters");
    m_radioBtnLayout->addWidget(m_length12);
    m_radioBtnLayout->addWidget(m_length16);

    m_pgMainLayout->addLayout(m_radioBtnLayout);

    m_randomPasswordLedit = new QLineEdit();
    m_emailLEdit = new QLineEdit();
    m_websiteLEdit = new QLineEdit();

    m_informationDisplayLayout = new QFormLayout();
    m_informationDisplayLayout->addRow(tr("Password:"),
                                       m_randomPasswordLedit);
    m_informationDisplayLayout->addRow(tr("E-Mail/Username:"),
                                       m_emailLEdit);
    m_informationDisplayLayout->addRow(tr("Website:"), m_websiteLEdit);

    m_pgMainLayout->addLayout(m_informationDisplayLayout);

    m_generatePassBtn = new QPushButton("Generate");
    m_pgMainLayout->addWidget(m_generatePassBtn);

    this->setLayout(m_pgMainLayout);


    QObject::connect(m_generatePassBtn, &QPushButton::clicked,
                     this, &PasswordGenerator::GenerateRandomPassword);
    QObject::connect(m_generatePassBtn, &QPushButton::clicked,
                     this, &PasswordGenerator::SetUserInformation);

}

void PasswordGenerator::GenerateRandomPassword()
{
    int length;
    QString password;

    if(m_length12->isChecked())
        length = 12;
    else if(m_length16->isChecked())
        length = 16;
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Please select a password length.");
        msgBox.exec();
    }

    std::array<unsigned char, 63> tempChars = chars;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(tempChars.begin(), tempChars.end(), gen);
    std::vector<unsigned char> tempPassChars;

    for(int i = 0; i < length; i++)
    {
        if(tempChars.at(i) == ' ')
            continue;
        else
            tempPassChars.push_back(tempChars[i]);
    }

    std::shuffle(tempPassChars.begin(), tempPassChars.end(), gen);

    for(int i = 0; i < tempPassChars.size(); i++)
        password += tempPassChars[i];

    this->m_randomPasswordLedit->setText(password);
}

void PasswordGenerator::SetUserInformation()
{
    this->m_username = this->m_emailLEdit->text();
    this->m_password = this->m_randomPasswordLedit->text();
    this->m_website = this->m_websiteLEdit->text();

    //qDebug() << m_username << " " << m_password << '\n';
}
