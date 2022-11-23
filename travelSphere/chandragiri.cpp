#include "chandragiri.h"
#include "ui_chandragiri.h"

chandragiri::chandragiri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chandragiri)
{
    ui->setupUi(this);
}

chandragiri::~chandragiri()
{
    delete ui;
}
