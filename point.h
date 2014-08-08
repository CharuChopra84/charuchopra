#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"

class point: public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    point();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int x1, y1;
    bool mClick;
    bool mPaintFlag;
    QVector<QPointF> stuff;

signals:
    void DrawFinished();
};

#endif // POINT_H
