#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

#include "./source/util.h"

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit settingDialog(QWidget *parent = 0);
    ~settingDialog();

    void setConfig(CConfig*);

public slots:
    void changeConfig(int);
    void changeConfig(double);

signals:
    void sendConfig(CConfig);
    
private:
    Ui::settingDialog *ui;
    CConfig *conf;
};

#endif // SETTINGDIALOG_H
