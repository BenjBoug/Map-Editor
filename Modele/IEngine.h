#ifndef ENGINE_H
#define ENGINE_H
namespace Model
{
class IEngine
{
public:
    virtual void init() = 0;
    virtual void run() = 0;


};
}

#endif // ENGINE_H
