#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <QPointF>

class Storagemanager
{
public:
    Storagemanager();
    ~Storagemanager();
    void set_point(QPointF);
    QPointF getValue();
private:
    QPointF _p;
};

#endif // STORAGEMANAGER_H
\
\

