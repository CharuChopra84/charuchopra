#include "point.h"

point::point()
{
    mClick = true;
    mPaintFlag = false;
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

QRectF point::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,1400,1400);
}

void point:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(mPaintFlag){
        QPen paintpen(Qt::red);
        paintpen.setWidth(4);

        QPoint p1;
        p1.setX(x1);
        p1.setY(y1);

        painter->setPen(paintpen);
        painter->drawPoint(p1);
    }
}

void point::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button()==Qt::LeftButton) {
        if(mClick){
            x1 = e->pos().x();
            y1 = e->pos().y();
            mClick = false;
            mPaintFlag = true;
            update();
            emit DrawFinished();
        }
    }
    QGraphicsItem::mousePressEvent(e);
    update();
}

void point::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->modifiers() & Qt::ShiftModifier) {
        stuff << e->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(e);
}

void point::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e);
    update();
}
