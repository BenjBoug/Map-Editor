#ifndef DEF_CONSTANTESMODEL
#define DEF_CONSTANTESMODEL

#define TAILLE_BLOC         50
#define NB_BLOCS_LARGEUR    17
#define NB_BLOCS_HAUTEUR    13
#define LARGEUR_FENETRE     (TAILLE_BLOC * NB_BLOCS_LARGEUR)
#define HAUTEUR_FENETRE     (TAILLE_BLOC * NB_BLOCS_HAUTEUR)
#define MOITIER_ECRAN_X     (NB_BLOCS_LARGEUR/2)*TAILLE_BLOC
#define MOITIER_ECRAN_Y     (NB_BLOCS_HAUTEUR/2)*TAILLE_BLOC
#define TRANSPANCE(surface) SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 255, 103, 139));

#include <iostream>
#include <exception>
namespace Model
{
enum Direction
{
    bas=0,droite=1,haut=2,gauche=3
};
}


#endif

