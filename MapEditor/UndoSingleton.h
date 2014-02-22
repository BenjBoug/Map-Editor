#ifndef UNDOSINGLETON_H
#define UNDOSINGLETON_H

#include <QObject>
#include <QStack>
#include "ICommand.h"

class UndoSingleton : public QObject
{
    Q_OBJECT
public:

    static UndoSingleton * getInstance()
    {
        if (instance==NULL)
            instance = new UndoSingleton();

        return instance;
    }

    void execute(ICommand *cmd);

signals:
    void undoEmpty(bool);
    void redoEmpty(bool);

public slots:
    void undo();
    void redo();

private:
    UndoSingleton();
    QStack<ICommand*> stackUndoCommand;
    QStack<ICommand*> stackRedoCommand;
    static UndoSingleton * instance;
};


#endif // UNDOSINGLETON_H
