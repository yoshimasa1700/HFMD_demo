#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::receiveClassNames(QStringList classNameList){
    ui->comboBox->clear();
    ui->comboBox->addItems(classNameList);

}

void Dialog::receiveShowImage(cv::vector<cv::Mat*> receiveImage){
    qDebug() << "show! hey!";
    cv::Mat temp = receiveImage.at(ui->comboBox->currentIndex())->clone();
    cv::Mat tempImage(ui->label->height(),ui->label->width(),temp.type());
    cv::resize(temp,tempImage,cv::Size(),
               0.5,//(double)((double)temp.rows / (double)ui->label->width()),
               0.5);//(double)((double)temp.cols / (double)ui->label->height()));

    cv::cvtColor(tempImage,tempImage,CV_GRAY2BGR);
    showImage = QImage(tempImage.data,tempImage.cols,tempImage.rows, QImage::Format_RGB888);

    ui->label->setPixmap((QPixmap::fromImage(showImage)));
    ui->label->show();
//    cv::Mat rgbForDisp = p_rgb->clone();
//    cv::Mat depthForDisp = p_depth->clone();


//    depthForDisp.convertTo(depthForDisp,CV_8UC3);
//    cv::cvtColor(depthForDisp,depthForDisp,CV_GRAY2RGB);

//    for(int i = 0;i < result.size(); ++i){
//        cv::Rect tempbox = result.at(i)->bbox;
//        cv::rectangle(rgbForDisp,tempbox,cv::Scalar(200,0,0),3);
//        cv::putText(rgbForDisp,result.at(i)->className,cv::Point(tempbox.x,tempbox.y),cv::FONT_HERSHEY_SIMPLEX,1.2, cv::Scalar(0,0,200), 2, CV_AA);
//    }

//    m_rgb = QImage(rgbForDisp.data, rgbForDisp.cols, rgbForDisp.rows, QImage::Format_RGB888);
//    m_depth = QImage(depthForDisp.data, depthForDisp.cols, depthForDisp.rows, QImage::Format_RGB888);

//    //std::cout << "detected object num:" << result.size() << std::endl;

//    ui->label->setPixmap(QPixmap::fromImage(m_rgb));
//    ui->label_2->setPixmap(QPixmap::fromImage(m_depth));
//    ui->label->show();
//    ui->label_2->show();

//    for(int i = 0; i < result.size(); ++i)
//        delete result.at(i);

//    double aT = t.elapsed();
//    std::cout << aT - bT << std::endl;
//    bT = aT;
}

void Dialog::teachWhatYouShouldShow(int *classNum){
    *classNum = ui->comboBox->currentIndex();
    std::cout << "yobareta don " << ui->comboBox->currentIndex();
}
