#ifndef UNDOSINGLETON_H
#define UNDOSINGLETON_H

#include <QObject>
#include <QStack>
#include "command/ICommand.h"
#include "command/GroupCommand.h"

#define CMD_BEGIN() UndoSingleton::getInstance()->beginGroup()
#define CMD_END() UndoSingleton::getInstance()->endGroup();
#define EXECUTE_CMD(cmd) UndoSingleton::getInstance()->execute(cmd)

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

	void beginGroup();
	void endGroup();

    void clearUndo();
    void clearRedo();

signals:
    void undoEmpty(bool);
    void redoEmpty(bool);

public slots:
    void undo();
    void redo();

protected:
	void cmdExecuted(ICommand* cmd);
	void cmdCanceled(ICommand* cmd);

private:
	UndoSingleton();
    QStack<ICommand*> stackUndoCommand;
    QStack<ICommand*> stackRedoCommand;
	static UndoSingleton * instance;
	GroupCommand * groupCmd;
	bool inGroup;
};


#endif // UNDOSINGLETON_H
