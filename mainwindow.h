#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include<QPixmap>
#include<QImage>

#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "point.h"
#include "arc.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void wheelEvent(QWheelEvent* event);

private:
    Ui::MainWindow *ui;
    bool mFirstClick;
    bool mPaintFlag;
    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;
    QGraphicsScene *scene;
    QPainter *painter;
    point *item;
    line *item1;
    circle *item2;
    ellipse *item3;
    arc *item4;
    QPixmap image;
    QImage *imageObject;

private slots:
    void drawPoint();
    void drawLine();
    void drawCircle();
    void drawEllipse();
    void drawArc();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionQuit_2_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionInsert_Image_triggered();
};

#endif // MAINWINDOW_H
