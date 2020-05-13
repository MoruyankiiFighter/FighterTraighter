#pragma once
#include "Vector2D.h"
#include "Component.h"
#include "PhysicsTransform.h"
class Shake :public Component
{
   
public:

    Shake(uint32 shakeTime,int shakeOffset) : Component(ecs::Shake) ,SHAKE_TIME_MS(shakeTime),SHAKE_OFFSET(shakeOffset){};
    Shake(uint32 shakeTime) : Component(ecs::Shake) ,SHAKE_TIME_MS(shakeTime),SHAKE_OFFSET(20){};
    Shake() : Component(ecs::Shake) ,SHAKE_TIME_MS(2000),SHAKE_OFFSET(20){};
   

    //Shaking will take 200ms
    uint32 SHAKE_TIME_MS ;

    //The screen will be moved 20 pixels forth and back
    int SHAKE_OFFSET ;

    //Indicates the shake move direction
    bool shakeDirection = false;

    //Indicates if the screen is currently shaking
    bool  shaking=true;
    bool getShake()
    {
        return shaking;
    }

    //delta is the ms passed since last update
    virtual void update()override;
    void init()override
    {
        cam = entity_->getComponent<Transform>(ecs::Transform);
        timeStart_ = SDL_GetTicks();
        xOffset = 0;
        yOffset = 0;
    }
private:
    void updateShake();
    void applyScreenShake();

   
    Transform* cam;
    Uint32 timeStart_;
    Uint32 delta;
    float xOffset = 0;
    float yOffset = 0;
    int shakeTimer = 0;


};