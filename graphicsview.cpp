#include "graphicsview.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QInputDialog>
#include <QGraphicsTextItem>
#include <QMouseEvent>

void GraphicsView::mousePressEvent( QMouseEvent * event )
{
    if( ! addText) return;

    const QPoint & pos = event->pos();
    bool ok;

    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                       tr("Please enter your text"), QLineEdit::Normal,
                                       "Replace with your text", &ok);

    if ( !ok || text.isEmpty()) return;

    QGraphicsTextItem *textItem = this->scene()->addText(text);
    textItem->setPos(mapToScene(pos));

}
