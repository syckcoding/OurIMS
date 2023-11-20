#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "register.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();
    void resizeEvent(QResizeEvent* event);

    void on_pushButton_register_clicked();

private:
    Ui::MainWindow *ui;
    Register *r;
};
#endif // MAINWINDOW_H
