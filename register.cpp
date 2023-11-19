#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include<stdlib.h>

Register::Register(QWidget *parent, QMainWindow* mainwindow) :
    QWidget(parent),
    ui(new Ui::Register)
{
    this->mainwindow = mainwindow;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    ui->exitButton_r->setGeometry(this->width() - 30, 10, 40, 20);//设置退出按钮的位置

    ui->widget->setObjectName("wid");
    ui->widget->setStyleSheet("QWidget#wid{background-color: rgba(255,255,255,0.5); border-radius: 5px;}");//设置透明度

    ui->lineEdit_email->setPlaceholderText("请输入注册邮箱");
    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password_2->setPlaceholderText("再次输入密码");
    ui->lineEdit_code->setPlaceholderText("请输入验证码");

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password_2->setEchoMode(QLineEdit::Password);
}

void Register::resizeEvent(QResizeEvent* event)
{
    ui->exitButton_r->setGeometry(this->width() - 50, 10, 40, 20);
    QWidget::resizeEvent(event);
}

Register::~Register()
{
    delete ui;
}

void Register::on_exitButton_r_clicked()
{
    mainwindow->show();
    this->hide();
}


void Register::on_pushButton_send_clicked()
{
//    Smtp s("sy_ck_code@163.com","VLZDXHDHUXQKXEHZ");
//    s.send("zhangxy797@mail2.sysu.edu.cn","测试邮箱发送功能","成功了~");
    QString recvaddr0 = ui->lineEdit_email->text();
    QRegularExpression re("^[A-Za-z0-9]+([_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");
    QRegularExpressionMatch match = re.match(recvaddr0);
    if(match.hasMatch()){//验证邮箱格式
        QMessageBox::information(NULL,"提示","验证码将在30s内发送至您的邮箱，请耐心等待。");

        srand(time(0));
        code = 1000 + rand() % (9999 - 1000);

//        QTime time= QTime::currentTime();
//        qsrand(time.msec()+time.second()*1000);
//        code = 1000+qrand() % (9999-1000);    //产生1000~9999以内的随机数
        Smtp smtp("sy_ck_code@163.com","VLZDXHDHUXQKXEHZ");//按照刚才的方法实例化一个smtp对象
        QByteArray recvaddr=recvaddr0.toUtf8();//QString转QByteArray
        QString subject="教务系统注册验证码";
        QString content="欢迎注册OurIMS，注册验证码为："+QString::number(code);
        smtp.send(recvaddr,subject,content);
    }
    else{
        QMessageBox::warning(NULL,"提示","邮箱格式不正确,请重新输入。");
    }
}

void Register::on_pushButton_confirm_clicked()
{
    account = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();
}

