#include "QSFMLCanvas.hpp"

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif


QSFMLCanvas::QSFMLCanvas(QWidget* Parent, unsigned int FrameTime) :
    QWidget       (Parent),
    myInitialized (false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    myTimer.setInterval(FrameTime);
}

QSFMLCanvas::~QSFMLCanvas()
{
    // Nothing to do...
}

void QSFMLCanvas::OnInit()
{
    // Nothing to do by default...
}

void QSFMLCanvas::OnUpdate()
{
    // Nothing to do by default...
}

QPaintEngine* QSFMLCanvas::paintEngine() const
{
    return 0;
}

void QSFMLCanvas::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {
        #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif
        Create(winId());
        OnInit();
        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        myTimer.start();
        myInitialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent*)
{
    OnUpdate();
    Display();
}
