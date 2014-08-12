#ifndef MTEXT_H
#define MTEXT_H

#include <QGraphicsView>
#include <QGraphicsScene>
class mtext:public QGraphicsView
{
    Q_OBJECT
public:
    mtext(QWidget *parent=0):QGraphicsView(parent), addText(false) {}
    void setAddText(bool state) {addText = state;}

public slots:
    void mousePressEvent( QMouseEvent * event );
private:
    bool addText;
};

#endif // MTEXT_H
