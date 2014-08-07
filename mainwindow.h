#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QtCore>
#include<QPixmap>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QWidget>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>

#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "point.h"
#include "arc.h"
//#include "graphicsview.h"


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();



protected:
    void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    bool mFirstClick;
    bool mPaintFlag;
    bool addText;

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
   // mtext *item5;
    QPrinter *printer;
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
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionInsert_Image_triggered();
    void on_actionMirror_triggered();
    void on_actionMirror_y_triggered();
    void on_actionQuit_triggered();

    void filePrintPreview();
    void filePrint();
    void print(QPrinter *);
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent( QKeyEvent * event );

//public slots:

//void on_toolButton_clicked( bool checked ) {
//  graphicsView->setAddText(checked); }





};

#endif // MAINWINDOW_H



