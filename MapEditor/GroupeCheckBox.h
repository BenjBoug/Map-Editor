#ifndef GROUPECHECKBOX_H
#define GROUPECHECKBOX_H

#include <QObject>
#include <QAction>
#include <QSignalMapper>
#include<QDebug>

class GroupeCheckBox : public QObject
{
    Q_OBJECT
public:
    GroupeCheckBox();

    void addAction(QAction * act);

public slots:
    void disableOther(QObject *i);

private:

    QSignalMapper * mapper;
    QList<QAction*> listAction;
};

#endif // GROUPECHECKBOX_H
