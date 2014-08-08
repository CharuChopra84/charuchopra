#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QShortcut>
#include<QMouseEvent>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextEdit>
#include<QString>
#include<QFileDialog>
#include<QString>
#include<QDateTime>
#include<memory>
#include<QGLWidget>


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(tr("GD CAD"));

   toolButton->setCheckable(true);
   scene =  new QGraphicsScene;
    graphicsView->setScene(scene);

    qApp->installEventFilter(this);

    connect(pointButton, SIGNAL(clicked()), this, SLOT(drawPoint()));
    connect(lineButton, SIGNAL(clicked()), this, SLOT(drawLine()));
    connect(circleButton, SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(ellipseButton, SIGNAL(clicked()), this, SLOT(drawEllipse()));
    connect(arcButton, SIGNAL(clicked()),this, SLOT(drawArc()));
    connect(actionPoints, SIGNAL(triggered()), this, SLOT(drawPoint()));
    connect(actionLine, SIGNAL(triggered()), this, SLOT(drawLine()));
    connect(actionCircle, SIGNAL(triggered()), this, SLOT(drawCircle()));
    connect(actionEllipse, SIGNAL(triggered()), this, SLOT(drawEllipse()));
    connect(actionZoom_In, SIGNAL(triggered()), this, SLOT(on_actionZoom_In_triggered()));
    connect(actionZoom_Out, SIGNAL(triggered()), this, SLOT(on_actionZoom_Out_triggered()));

    //connect(toolButton,SIGNAL(clicked(bool)),this,SLOT(on_toolButton_clicked(bool)));
    connect(actionPrint, SIGNAL(triggered()), this, SLOT(filePrint()));
    connect(actionPrintPreview, SIGNAL(triggered()), this, SLOT(filePrintPreview()));
    connect(actionInsert_Image,SIGNAL(triggered()),this,SLOT(on_actionInsert_Image_triggered()));

}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QMainWindow::statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
    }
    return false;
}


void  MainWindow::filePrintPreview()
{
    // display print preview dialog
    QPrinter printer( QPrinter::HighResolution );
    QPrintPreviewDialog preview( &printer, this );
    connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
    preview.exec();
}

void  MainWindow::filePrint()
{
    // display print dialog and if accepted print
    QPrinter printer( QPrinter::HighResolution );
    QPrintDialog dialog( &printer, this );
    if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}

void  MainWindow::print( QPrinter* printer )
{
    QPainter painter( printer );
    int w = printer->pageRect().width();
    int h = printer->pageRect().height();
    QRect page( 0, 0, w, h );

    QFont font = painter.font();
    font.setPixelSize( (w+h) / 100 );
    painter.setFont( font );

    painter.drawText( page, Qt::AlignBottom | Qt::AlignRight,
                      QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );

    page.adjust( w/20, h/20, -w/20, -h/20 );
    scene->render( &painter, page );
}





void MainWindow::drawPoint(){
    item = new point;
    scene->addItem(item);
    qDebug() << "Point Created";
    connect(item, SIGNAL(DrawFinished()), this, SLOT(drawPoint()));
    qDebug() << "point";

}

void MainWindow::drawLine(){
    graphicsView->setScene(scene);
    item1 = new line;
    scene->addItem(item1);
    qDebug() << "Line Created";
    connect(item1, SIGNAL(DrawFinished()), this, SLOT(drawLine()));

}

void MainWindow::drawCircle(){
    graphicsView->setScene(scene);
    item2 = new circle;
    scene->addItem(item2);
    qDebug() << "Circle Created";
    item2->setFlag(QGraphicsItem::ItemIsSelectable);

    connect(item2, SIGNAL(DrawFinished()), this, SLOT(drawCircle()));
}
void MainWindow::drawArc(){
    graphicsView->setScene(scene);
    item4 = new arc;
    scene->addItem(item4);
    qDebug() << "Arc Created";
    connect(item4, SIGNAL(DrawFinished()), this, SLOT(drawArc()));
}

void MainWindow::on_actionMirror_triggered(){
    graphicsView->scale(1,-1);
}

void MainWindow::on_actionMirror_y_triggered(){
    graphicsView->scale(-1,1);
}

void MainWindow::drawEllipse(){
    graphicsView->setScene(scene);
    item3 = new ellipse;
    scene->addItem(item3);
    qDebug() << "Ellipse Created";
    connect(item3, SIGNAL(DrawFinished()), this, SLOT(drawEllipse()));
}



void MainWindow::wheelEvent(QWheelEvent* event) {
    graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        graphicsView->scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {

        QGraphicsPixmapItem *pix= new QGraphicsPixmapItem();
        pix->setPixmap(QPixmap(fileName, 0, Qt::AutoColor));
        scene->addItem(pix);
        graphicsView->setScene(scene);
    }


    return ;

}

void MainWindow::on_actionSave_triggered()
{

    QString filename=QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                QString(),
                tr("file Name(*.txt)")
                );
    if(!filename.isEmpty()) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        } else {
            QTextStream stream(&file);
            QTextEdit *textEdit;
            stream << textEdit->toPlainText();
            stream.flush();
            file.close();
        }

    }

}
void MainWindow::on_actionQuit_triggered(){
    MainWindow *window;
    window->close();
}
void MainWindow::on_actionZoom_In_triggered(){
    QWheelEvent *event;
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        graphicsView->scale(scaleFactor, scaleFactor);

    }
}
void MainWindow::on_actionZoom_Out_triggered(){
    QWheelEvent *event;
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom out
        graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);

    }
}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}
void MainWindow::on_actionInsert_Image_triggered(){
    QString imagePath =QFileDialog::getOpenFileName(this,tr("open File"),"",tr("JPEG(*.jpg *.jpeg);;PNG(*.png)"));
    imageObject =new QImage();
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);
    scene =new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    graphicsView->setScene(scene);

}
