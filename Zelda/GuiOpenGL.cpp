#include "GuiOpenGL.h"

GuiOpenGL::GuiOpenGL()
{
}

void GuiOpenGL::init()
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("The legend of Zelda", NULL);
    SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    SDL_initFramerate(&manager);
    SDL_setFramerate(&manager,30);
}

void GuiOpenGL::clearScreen()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ();

    glOrtho (0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 10);

    glClearColor((double)107/255, (double)189/255, (double)107/255, 1);
}

void GuiOpenGL::display()
{
    glFlush();
    SDL_GL_SwapBuffers();
    SDL_framerateDelay(&manager);
}

void GuiOpenGL::draw(QString chipset, QPoint position, QRect rect)
{

    glBindTexture(GL_TEXTURE_2D, factory.build(QString("images/chipset/map.png")));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);

    double width = 1500;
    double height = 800;
    rect.setWidth(BLOCSIZE);
    rect.setHeight(BLOCSIZE);

    glTexCoord2d((double)rect.left()/width,1-((double)rect.bottom()/height));
    glVertex2d(position.x(),position.y()+rect.height());

    glTexCoord2d((double)rect.right()/width,1-((double)rect.bottom()/height));
    glVertex2d(position.x()+rect.width(),position.y()+rect.height());

    glTexCoord2d((double)rect.right()/width,1-((double)rect.top()/height));
    glVertex2d(position.x()+rect.width(),position.y());

    glTexCoord2d((double)rect.left()/width,1-((double)rect.top()/height));
    glVertex2d(position.x(),position.y());


    glEnd();
}

void GuiOpenGL::quit()
{
    SDL_Quit();
}
