#include "mtext.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QInputDialog>
#include <QGraphicsTextItem>
#include <QMouseEvent>

void mtext::mousePressEvent( QMouseEvent * event )
{
    if( ! addText) return;

    const QPoint & pos = event->pos();
    bool ok;
    QString text = QInputDialog::getMultiLineText(this, tr("QInputDialog::getMultiLineText()"),
                                                     tr("Address:"), "John Doe\nFreedom Street", &ok);

    if ( !ok || text.isEmpty()) return;

    QGraphicsTextItem *textItem = this->scene()->addText(text);
    textItem->setPos(mapToScene(pos));

}
