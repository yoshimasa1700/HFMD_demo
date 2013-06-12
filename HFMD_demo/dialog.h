#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include <QDebug>
#include <opencv2/opencv.hpp>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    Ui::Dialog *ui;
    ~Dialog();

public slots:
    void receiveClassNames(QStringList);
    void receiveShowImage(cv::vector<cv::Mat*>);
    void teachWhatYouShouldShow(int *);

signals:
    void sendShowImageNum(int);
    
private:

    QImage showImage;
};

#endif // DIALOG_H
