#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class GraphicsView: public QGraphicsView
{
  Q_OBJECT
public:
 GraphicsView( QWidget *parent = 0) : QGraphicsView(parent), addText(false) {}
  void setAddText(bool state) {addText = state;}
  public slots:
  void mousePressEvent( QMouseEvent * event );

 private:
  bool addText;

};
#endif // MAINWINDOW_H
