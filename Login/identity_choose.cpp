#include "identity_choose.h"
#include "ui_identity_choose.h"

identity_choose::identity_choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::identity_choose)
{
    ui->setupUi(this);
    choose = 0;
}

identity_choose::~identity_choose()
{
    delete ui;
}

void identity_choose::on_pushButton_admin_clicked()
{
    choose = 1;//教务
    this->hide();
}


void identity_choose::on_pushButton_teacher_clicked()
{
    choose = 2;//教师
    this->hide();
}


void identity_choose::on_pushButton_student_clicked()
{
    choose = 3;//学生
    this->hide();
}

int identity_choose::getChoose(){
    return choose;
}
