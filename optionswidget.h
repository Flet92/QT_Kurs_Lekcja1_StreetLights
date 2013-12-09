#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QWidget>

namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsWidget(QWidget *parent = 0);
    ~OptionsWidget();
    int getYellowTime() const {return yellowTime;}
    int getRedTime() const {return redTime;}
    int getGreenTime() const {return greenTime;}
private:
    Ui::OptionsWidget *ui;

    int greenTime;
    int yellowTime;
    int redTime;
private:

    void connectSignalSlots();
    void setInitialValues();
private slots:
    void greenSliderValueChanged(int);
    void redSliderValueChanged(int);
    void yellowSliderValueChanged(int);
};

#endif // OPTIONSWIDGET_H
