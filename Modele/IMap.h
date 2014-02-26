#ifndef IMAP_H
#define IMAP_H

#include <QRect>
#include "IDisplayable.h"
#include "IManager.h"
namespace Model
{
class BlocMap;

class IMap : public IDisplayable, public IManager
{
public:
    virtual QSize getSize() const =0;
    virtual const BlocMap * getBloc(QPoint&) const =0;
    virtual QString getChipset() const =0;

    virtual bool load(QString filename) =0;

};
}

#endif // IMAP_H
