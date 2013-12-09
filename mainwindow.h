#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <optionswidget.h>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <mygraphicsscene.h>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    OptionsWidget *optionsWidget;

    MyGraphicsScene *graphicsScene;

    QTimer *greenTimer;
    QTimer *yellowTimer;
    QTimer *redTimer;

    QGraphicsEllipseItem *yellowLight;
    QGraphicsEllipseItem *greenLight;
    QGraphicsEllipseItem *redLight;
    QGraphicsRectItem *rectangle;

    bool isRunning;

private:

    void connectSignalSlots();
    void drawStreetLights();

    void yellowOff(){yellowLight->setBrush(Qt::black);}
    void redOff(){redLight->setBrush(Qt::black);}
    void greenOff(){greenLight->setBrush(Qt::black);}
    void redOn(){redLight->setBrush(Qt::red);}
    void yellowOn(){yellowLight->setBrush(Qt::yellow);}
    void greenOn(){greenLight->setBrush(Qt::green);}

private slots:

    void handleKeyPress(QKeyEvent*);
    void handleMousePress(QGraphicsSceneMouseEvent *event);
    void greenLightTimeout();
    void redLightTimeout();
    void yellowLightTimeout();

    void showOptionsWidget();
    void startStreetLights();
    void stopStreetLights();
    void buttonPushed();
};

#endif // MAINWINDOW_H
