#ifndef CLIPBOARDSINGLETON_H
#define CLIPBOARDSINGLETON_H

#include <QObject>
#include <QVector>
#include "MapView.h"
#include <QPaintEngine>
#include <QClipboard>
#include <QApplication>
#include "command/BlitCommand.h"

class ClipBoardSingleton : public QObject
{
	Q_OBJECT
public:

	static ClipBoardSingleton * getInstance()
	{
		if (instance==NULL)
			instance = new ClipBoardSingleton();

		return instance;
	}

	void copy(MapView * mapView, QRect tiles);

	void paste(MapView * mapView, int i, int j);

	QRect getRectSelected() const;

signals:
	void pasteReady(bool);

private:
	ClipBoardSingleton();

	QRect rect;

	static ClipBoardSingleton * instance;

	QVector<QVector<int> > tileCopied;
};

#endif // CLIPBOARDSINGLETON_H
