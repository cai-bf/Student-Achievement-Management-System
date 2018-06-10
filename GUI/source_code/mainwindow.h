#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"admin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Admin
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString s2q(string);
    string q2s(QString);
    void addMsg();
    void reviseMsg();
    void deleteMsg();
    void sortMsg();
    void queryMsg();
    void mergeMsg();
    void getMsg();
    void showAll(bool, StudentMsg* ms);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
