#ifndef CAMERA_H
#define CAMERA_H

#include "ICamera.h"
#include "Constantes.h"
#include "IGame.h"
namespace Model
{
class Camera : public ICamera
{
public:
    Camera(IGame * game);
    virtual ~Camera();


    bool overflowMap();
    void replaceCamera();
    void centerCameraOnHeros();
    void manage(const IGame *);
    bool isInTheField(Object*);


private:
    IGame * game;
};
}

#endif // CAMERA_H
