#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QWidget>
#include <QRegularExpression>
#include <QMessageBox>
#include "email.h"
#include "identity_choose.h"
#include "creatConnection.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr, QMainWindow *mainwindow = nullptr);
    ~Register();

private slots:
    void on_exitButton_r_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_confirm_clicked();

    void onIdentityChooseHide();

private:
    Ui::Register *ui;
    QMainWindow* mainwindow;
    void resizeEvent(QResizeEvent* event);

    QString account;
    QString password;
    QString code;
    identity_choose* c;

};

#endif // REGISTER_H
