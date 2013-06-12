#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QImage>
#include <QPixmap>
#include <QAction>

#include "ctlkinect.h"
#include "CRForest.h"
#include "dialog.h"
#include "settingdialog.h"

#include <boost/timer.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();//    ui->label->setPixmap(QPixmap::fromImage(m_rgb));
    //    ui->label_2->setPixmap(QPixmap::fromImage(m_depth));
    //    ui->label->show();
    //    ui->label_2->show();

public slots:
    void getData(cv::Mat*, cv::Mat*);
    void errorMsg(int errorType);
    void takePhoto();
    void showResult(std::vector<detectionResult*>);

    void keiyuUkeru(QString);
    
private:
    Ui::MainWindow *ui;
    CtlKinect m_kinect;
    QThread *m_thread, *m_thread2;

    QImage m_rgb, m_depth;

    cv::Mat *p_rgb,*p_depth;

    CRForest *forest;
    CConfig *conf;

    boost::timer t;
    double bT;
    Dialog dialog;
    settingDialog *settingD;

    int photoCount;

signals:
    void startSensing();
    void gotImage(cv::Mat*,cv::Mat*);
    void keiyuOkuru(QString);
};

#endif // MAINWINDOW_H
