#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(this)
{
    qRegisterMetaType<cv::vector<cv::Mat*> >("cv::vector<cv::Mat*>");
    qRegisterMetaType<std::vector<detectionResult*> >("std::vector<detectionResult*>");
    qRegisterMetaType<CConfig>("CConfig");
    qRegisterMetaType<CTestDataset>("CTestDataset");

    ui->setupUi(this);

    settingD = new settingDialog(this);
    connect(ui->actionSetting_Window,SIGNAL(triggered()),settingD,SLOT(show()));

    //load forest file
    conf = new CConfig;
    conf->loadConfig("../hfConfig.xml");
    forest = new CRForest(*conf);
    settingD->setConfig(conf);

    connect(forest,SIGNAL(sendClassNames(QStringList)),&dialog,SLOT(receiveClassNames(QStringList)));
    forest->loadForest();



    connect(forest,SIGNAL(sendVoteImage(cv::vector<cv::Mat*>)),&dialog,SLOT(receiveShowImage(cv::vector<cv::Mat*>)));

    // make kinect control thread
    m_thread = new QThread;
    m_kinect.moveToThread(m_thread);

    // make detection control thread
    m_thread2 = new QThread;
    forest->moveToThread(m_thread2);

    connect(&m_kinect,SIGNAL(getData(cv::Mat*,cv::Mat*)),
            this,SLOT(getData(cv::Mat*,cv::Mat*)));
    connect(this, SIGNAL(startSensing()),&m_kinect,
            SLOT(getRGBDData()));
    connect(&m_kinect, SIGNAL(errorOccurred(int)),
            this,SLOT(errorMsg(int)));

    connect(this,SIGNAL(gotImage(CTestDataset)),forest,SLOT(detection(CTestDataset)));
    connect(forest,SIGNAL(detectedResult(std::vector<detectionResult*>)),this,SLOT(showResult(std::vector<detectionResult*>)));

    connect(ui->actionView_vote_image,SIGNAL(triggered()),&dialog,SLOT(show()));

    connect(dialog.ui->comboBox,SIGNAL(activated(QString)),this,SLOT(keiyuUkeru(QString)));

    connect(this,SIGNAL(keiyuOkuru(QString)),forest,SLOT(recieveWhatDialogWantToShow(QString)));

    connect(forest,SIGNAL(checkWhatIShouldShow(int*)),&dialog,SLOT(teachWhatYouShouldShow(int*)));

    connect(settingD,SIGNAL(sendConfig(CConfig)),forest,SLOT(receiveConfig(CConfig)));


    // start kinect control thread
    m_thread->start();
    m_thread2->start();
    emit startSensing();

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(takePhoto()));

    photoCount = 0;

}

MainWindow::~MainWindow()
{
    m_thread->terminate();
    delete ui;
    delete m_thread;
    delete forest;
}

void MainWindow::getData(cv::Mat *rgb, cv::Mat *depth){
    //qDebug() << tr("receive data!");

//    cv::Mat *rgbTemp = new cv::Mat(rgb->rows, rgb->cols, rgb->type());
//    rgb->copyTo(*rgbTemp);
//    cv::Mat *depthTemp = new cv::Mat(depth->rows, depth->cols, depth->type());
//    depth->copyTo(*depthTemp);

//    delete rgb;
//    delete depth;

    p_rgb = rgb;
    p_depth = depth;

    //qDebug() << tr("%1").arg(p_depth->type());
    //qDebug() << tr("CV_16U is %1").arg(CV_16U);
    //qDebug() << tr("CV_8U is %1").arg(CV_8U);

    cv::vector<cv::Mat *> inputImage(0);

    inputImage.push_back(p_rgb);
    inputImage.push_back(p_depth);

    CTestDataset receiveImages;
    receiveImages.img.push_back(rgb);
    receiveImages.img.push_back(depth);

    emit gotImage(receiveImages);

//    std::vector<detectionResult> result;
//    result = forest->detection(inputImage);

}

void MainWindow::errorMsg(int errorType){
    QMessageBox msgBox(this);

    switch(errorType){
    case 0:

        msgBox.setText(tr("Can't read XML file!"));
        msgBox.exec();
        break;
    case 1:

        msgBox.setText(tr("error image generator"));
        msgBox.exec();
        break;
    case 2:

        msgBox.setText(tr("No depth node exists! Check your XML."));
        msgBox.exec();
        break;
    default:

        msgBox.setText(tr("Unkown error!"));
        msgBox.exec();
        break;
    }
}

void MainWindow::takePhoto(){
    cv::Mat rgbForSave = p_rgb->clone();

    cv::cvtColor(rgbForSave,rgbForSave,CV_RGB2BGR);

    std::stringstream ss1,ss2;
    ss1 << "rgb_" <<  photoCount << ".png";
    ss2 << "depth_" <<  photoCount << ".png";


    cv::imwrite(ss1.str().c_str(),rgbForSave);
    cv::imwrite(ss2.str().c_str(),*p_depth);

    photoCount++;
}

void MainWindow::showResult(std::vector<detectionResult*> result){
    cv::Mat rgbForDisp = p_rgb->clone();
    cv::Mat depthForDisp = p_depth->clone();

    cv::Mat depthForDisp2 = cv::Mat(640,480,CV_8UC3);

    cv::cvtColor(depthForDisp,depthForDisp,CV_GRAY2BGR);
    //cv::cvtColor(depthForDisp,depthForDisp,CV_GRAY2RGB);
    //depthForDisp.convertTo(depthForDisp,CV_8UC1);
    depthForDisp.convertTo( depthForDisp, CV_8UC3, 255.0 / 1000 );
    //cv::convertScaleAbs(depthForDisp,depthForDisp2);

    cv::resize(depthForDisp,depthForDisp2,cv::Size(),0.5,0.5);

    for(int i = 0;i < result.size(); ++i){
        cv::Rect tempbox = result.at(i)->bbox;
        cv::rectangle(rgbForDisp,tempbox,cv::Scalar(200,0,0),3);
        cv::putText(rgbForDisp,result.at(i)->className,cv::Point(tempbox.x,tempbox.y),cv::FONT_HERSHEY_SIMPLEX,1.2, cv::Scalar(0,0,200), 2, CV_AA);
    }

    m_rgb = QImage(rgbForDisp.data, rgbForDisp.cols, rgbForDisp.rows, QImage::Format_RGB888);
    m_depth = QImage(depthForDisp2.data, depthForDisp2.cols, depthForDisp2.rows, QImage::Format_RGB888);

    //std::cout << "detected object num:" << result.size() << std::endl;

    ui->label->setPixmap(QPixmap::fromImage(m_rgb));
    ui->label_2->setPixmap(QPixmap::fromImage(m_depth));
    ui->label->show();
    ui->label_2->show();

    for(int i = 0; i < result.size(); ++i)
        delete result.at(i);

    double aT = t.elapsed();
    std::cout << aT - bT << std::endl;
    bT = aT;

}

void MainWindow::keiyuUkeru(QString uketa){
    emit keiyuOkuru(uketa);
}
