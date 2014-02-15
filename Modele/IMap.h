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
    virtual QSize getDim() const =0;
    virtual const BlocMap * getBloc(QPoint&) const =0;
    virtual QString getChipset() const =0;
    virtual void load() =0;


};
}

#endif // IMAP_H
