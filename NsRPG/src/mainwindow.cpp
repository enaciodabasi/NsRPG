#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(500, 500);
    m_mainwidget = new MainWidget(parent);
    this->setCentralWidget(m_mainwidget);

    //m_userlog = new UserLog(parent);
    //this->addDockWidget(Qt::LeftDockWidgetArea,
    //                    m_userlog);


}

MainWindow::~MainWindow()
{
}

