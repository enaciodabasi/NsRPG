#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwidget.h"
#include "userlog.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    MainWidget *m_mainwidget;
    UserLog* m_userlog;
};
#endif // MAINWINDOW_H
