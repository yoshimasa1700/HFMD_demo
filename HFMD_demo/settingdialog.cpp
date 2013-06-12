#include "settingdialog.h"
#include "ui_settingdialog.h"

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);

    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeConfig(int)));
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(changeConfig(double)));
}

settingDialog::~settingDialog()
{
    delete ui;
}

void settingDialog::setConfig(CConfig* tempConfig){
    conf = tempConfig;
    ui->spinBox->setValue(conf->stride);
    ui->doubleSpinBox->setValue(conf->detectThreshold);
}
void settingDialog::changeConfig(int temp){
    conf->stride = temp;
    //emit sendConfig(conf);
}

void settingDialog::changeConfig(double temp){
    conf->detectThreshold = temp;
    //emit sendConfig(conf);
}
