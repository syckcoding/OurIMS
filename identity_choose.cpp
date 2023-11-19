#include "identity_choose.h"
#include "ui_identity_choose.h"

identity_choose::identity_choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::identity_choose)
{
    ui->setupUi(this);
}

identity_choose::~identity_choose()
{
    delete ui;
}
