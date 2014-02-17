#ifndef FRAME_H
#define FRAME_H

#include "Object.h"
#include "Constantes.h"


namespace Model
{
class Frame : public Object
{
    public:
        Frame();
        Frame(QRect c, int d, QPoint de)
        {
            coord =c;
            delay =d;
            decalage=de;
        }

        QPoint getDecalage() {return decalage;}

        int getDelay()
        {
            return delay;
        }

        virtual ~Frame();

    private:
    int delay;
    QPoint decalage;
};
}
#endif // FRAME_H
