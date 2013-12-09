#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    optionsWidget(new OptionsWidget()),
    graphicsScene(new MyGraphicsScene(this)),
    greenTimer(new QTimer),
    yellowTimer(new QTimer),
    redTimer(new QTimer)
{
    ui->setupUi(this);

    connectSignalSlots();

    drawStreetLights();

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showOptionsWidget(){
    optionsWidget->show();
}

void MainWindow::drawStreetLights(){
    int height = ui->graphicsView->height();
    int width = ui->graphicsView->width();
    int lightSize= int(0.7 * width);
    rectangle = graphicsScene->addRect(5,5,width-10,height-10,QPen(Qt::black),QBrush(Qt::black));
    redLight = graphicsScene->addEllipse((width-lightSize)/2,0+10,lightSize,lightSize,QPen(Qt::black),QBrush(Qt::red));
    yellowLight = graphicsScene->addEllipse((width-lightSize)/2,height*1/3+10,lightSize,lightSize,QPen(Qt::black),QBrush(Qt::red));
    greenLight = graphicsScene->addEllipse((width-lightSize)/2,height*2/3+10,lightSize,lightSize,QPen(Qt::black),QBrush(Qt::red));

    this->ui->graphicsView->setScene(graphicsScene);
}

void MainWindow::stopStreetLights(){
    ui->pushButton->setText("Start");

    redTimer->stop();
    greenTimer->stop();
    yellowTimer->stop();
    isRunning=false;

}
void MainWindow::startStreetLights(){
    ui->pushButton->setText("Stop");

    redOn();
    greenOff();
    yellowOff();
    redTimer->start();

    isRunning=true;
}
void MainWindow::connectSignalSlots(){

    connect(this->graphicsScene,SIGNAL(keyPressed(QKeyEvent*)),this,SLOT(handleKeyPress(QKeyEvent*)));
    connect(this->graphicsScene,SIGNAL(mouseClicked(QGraphicsSceneMouseEvent*)),this,SLOT(handleMousePress(QGraphicsSceneMouseEvent*)));
    connect(this->ui->actionEdit_Options,SIGNAL(triggered()),this,SLOT(showOptionsWidget()));
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(buttonPushed()));
    connect(this->yellowTimer,SIGNAL(timeout()),this,SLOT(yellowLightTimeout()));
    connect(this->greenTimer,SIGNAL(timeout()),this,SLOT(greenLightTimeout()));
    connect(this->redTimer,SIGNAL(timeout()),this,SLOT(redLightTimeout()));
}
void MainWindow::buttonPushed(){
    if(isRunning)
        stopStreetLights();
    else
        startStreetLights();
}

void MainWindow::redLightTimeout(){
    redOff();
    yellowOn();
    redTimer->stop();
    yellowTimer->setInterval(optionsWidget->getYellowTime());
    yellowTimer->start();
}
void MainWindow::greenLightTimeout(){
    greenOff();
    redOn();
    greenTimer->stop();
    redTimer->setInterval(optionsWidget->getRedTime());
    redTimer->start();
}
void MainWindow::yellowLightTimeout(){
    yellowOff();
    greenOn();
    yellowTimer->stop();
    greenTimer->setInterval(optionsWidget->getGreenTime());
    greenTimer->start();
}
void MainWindow::handleKeyPress(QKeyEvent *event){
    qDebug()<<event->key();
    if(event->key()==Qt::Key_A)
        buttonPushed();
}
void MainWindow::handleMousePress(QGraphicsSceneMouseEvent *event){

    graphicsScene->addEllipse((int)event->scenePos().x(),(int)event->scenePos().y(),2,2,QPen(Qt::white),QBrush(Qt::white));
}
