#ifndef QSFMLCANVAS_HPP
#define QSFMLCANVAS_HPP
#include <SFML/Graphics.hpp>
#include <qwidget.h>
#include <qtimer.h>

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public :

    QSFMLCanvas(QWidget* Parent, unsigned int FrameTime = 0);
    virtual ~QSFMLCanvas();

private :
    virtual void OnInit();
    virtual void OnUpdate();
    virtual QPaintEngine* paintEngine() const;
    virtual void showEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);
    QTimer myTimer;
    bool   myInitialized;
};


#endif // QSFMLCANVAS_HPP
