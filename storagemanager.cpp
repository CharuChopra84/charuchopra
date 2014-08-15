#include "storagemanager.h"

Storagemanager::Storagemanager()
{
}
Storagemanager::~Storagemanager()
{
}

void Storagemanager::set_point(QPointF p)
{
    _p = p;
}

QPointF Storagemanager::getValue()
{
    return _p;
}

