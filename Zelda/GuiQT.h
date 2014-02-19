#ifndef GUIQT_H
#define GUIQT_H
#include "IGui.h"

using namespace Model;

class GuiQT : public IGui
{
public:
    GuiQT();
    virtual void init();
    virtual void clearScreen();
    virtual void display();
    virtual void blit(QString chipset,QPoint position, QRect rect);
    virtual void quit();
};

#endif // GUIQT_H
