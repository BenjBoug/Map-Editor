#ifndef ANIMATION_H
#define ANIMATION_H

#include "Constantes.h"
#include "Frame.h"
#include <QMap>
#include <QVector>
#include "IAnimation.h"
#include <QElapsedTimer>

namespace Model
{
class Animation : public IAnimation
{
    public:
        Animation(QString, Direction *);
        virtual ~Animation();


        virtual void manage(const IGame *);

        int getState()
        {
            return state;
        }

        void prepare();
        virtual void play();
        virtual void stop() ;

        int getDelayTotal();


        void forceFrame(int i)
        {
            position=i;
        }

        virtual void display(IGui*gui, ICamera*cam);


    protected:
    private:
    QMap<Direction,QVector<Frame*> > frames;
    Frame* frameActuel;
    Direction * direction;
    QString nomFichier;
    QString nomCharset;

    int state;

    int position;

    int tempsPrecedent;
    QElapsedTimer timer;

};
}
#endif // ANIMATION_H
