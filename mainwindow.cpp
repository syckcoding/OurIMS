#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "email.h"
#include "register.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(225, 202, 255, 255), stop:0.955556 rgba(0, 140, 161, 255));");
    ui->exitButton->setGeometry(this->width() - 50, 10, 40, 20);//设置退出按钮的位置
    ui->exitButton->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255); border-radius: 5px; }");

    ui->widget->setObjectName("wid");
    ui->widget->setStyleSheet("QWidget#wid{background-color: rgba(255,255,255,0.5); border-radius: 5px;}");//设置透明度

//    ui->lineEdit_account->setStyleSheet("border: 5px;");
//    ui->lineEdit_password->setStyleSheet("border: 5px;");//设置圆角

    ui->lineEdit_account->setPlaceholderText("请输入用户名");
    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    ui->label_logo->setStyleSheet("image: url(:/new/prefix1/Resources/Login/person.png);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    ui->exitButton->setGeometry(this->width() - 50, 10, 40, 20);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_register_clicked()
{
    r = new Register(nullptr,this);
    r->setWindowTitle("注册");
    r->show();
    this->hide();
}

