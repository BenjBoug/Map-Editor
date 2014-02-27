#include "GroupeCheckBox.h"

GroupeCheckBox::GroupeCheckBox()
{
    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(disableOther(QObject*)));
}

void GroupeCheckBox::addAction(QAction *act)
{
    listAction.push_back(act);
    connect(act,SIGNAL(triggered()),mapper,SLOT(map()));
    mapper->setMapping(act,act);
}

void GroupeCheckBox::disableOther(QObject* i)
{
    QList<QAction*>::iterator it;
    for(it=listAction.begin();it!=listAction.end();it++)
    {
        (*it)->setChecked(false);
    }
    ((QAction*)i)->setChecked(true);
    emit groupToggle();
}

