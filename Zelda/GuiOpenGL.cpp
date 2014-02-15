#include "GuiOpenGL.h"

GuiOpenGL::GuiOpenGL()
{
}

void GuiOpenGL::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("The legend of Zelda", NULL);
    SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(70,(double)LARGEUR_FENETRE/HAUTEUR_FENETRE,1,1000);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    SDL_initFramerate(&manager);
    SDL_setFramerate(&manager,30);
}

void GuiOpenGL::clearScreen()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ();

    glOrtho (0, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, 0, 1);

    glClearColor((double)107/255, (double)189/255, (double)107/255, 1);
}

void GuiOpenGL::display()
{
    glFlush();
    SDL_GL_SwapBuffers();
    SDL_framerateDelay(&manager);
}

void GuiOpenGL::blit(QString chipset, QPoint position, QRect rect)
{
    glBindTexture(GL_TEXTURE_2D, factory.build(chipset));
    glBegin(GL_QUADS);

    double width = 1500;
    double height = 800;

    glTexCoord2d((double)rect.left()/width,1-((double)rect.bottom()/height));
    glVertex2d(position.x(),position.y()+TAILLE_BLOC);

    glTexCoord2d((double)rect.right()/width,1-((double)rect.bottom()/height));
    glVertex2d(position.x()+TAILLE_BLOC,position.y()+TAILLE_BLOC);

    glTexCoord2d((double)rect.right()/width,1-((double)rect.top()/height));
    glVertex2d(position.x()+TAILLE_BLOC,position.y());

    glTexCoord2d((double)rect.left()/width,1-((double)rect.top()/height));
    glVertex2d(position.x(),position.y());


/*
    glTexCoord2d((double)rect.right()/width,(double)rect.top()/height);
    glVertex2d(position.x(),position.y()+TAILLE_BLOC);


    glTexCoord2d((double)rect.left()/width,(double)rect.top()/height);
    glVertex2d(position.x()+TAILLE_BLOC,position.y()+TAILLE_BLOC);

    glTexCoord2d((double)rect.left()/width,(double)rect.bottom()/height);
    glVertex2d(position.x()+TAILLE_BLOC,position.y());

    glTexCoord2d((double)rect.right()/width,(double)rect.bottom()/height);
    glVertex2d(position.x(),position.y());
*/

 glEnd();
}
