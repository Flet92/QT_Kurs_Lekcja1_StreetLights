#include "optionswidget.h"
#include "ui_optionswidget.h"

OptionsWidget::OptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsWidget),
    greenTime(1000),
    yellowTime(1000),
    redTime(1000)
{
    ui->setupUi(this);
    setInitialValues();
    connectSignalSlots();

}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::connectSignalSlots(){

    connect(this->ui->horizontalSlider_GreenLightTimer,SIGNAL(valueChanged(int)),this,SLOT(greenSliderValueChanged(int)));
    connect(this->ui->horizontalSlider_YellowLightTimer,SIGNAL(valueChanged(int)),this,SLOT(yellowSliderValueChanged(int)));
    connect(this->ui->horizontalSlider_RedLightTimer,SIGNAL(valueChanged(int)),this,SLOT(redSliderValueChanged(int)));
}
void OptionsWidget::greenSliderValueChanged(int value){
    this->greenTime=value;
    this->ui->lineEdit_GreenLightTimer->setText(QString::number(value)+" ms");
}

void OptionsWidget::yellowSliderValueChanged(int value){
    this->yellowTime=value;
    this->ui->lineEdit_YellowLightTimer->setText(QString::number(value)+" ms");
}

void OptionsWidget::redSliderValueChanged(int value){
    this->redTime=value;
    this->ui->lineEdit_RedLightTimer->setText(QString::number(value)+" ms");
}

void OptionsWidget::setInitialValues(){

    this->ui->lineEdit_GreenLightTimer->setText(QString::number(greenTime)+" ms");
    this->ui->lineEdit_YellowLightTimer->setText(QString::number(yellowTime)+ " ms");
    this->ui->lineEdit_RedLightTimer->setText(QString::number(redTime)+ " ms");
}
