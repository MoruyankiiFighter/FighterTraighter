#include "Shake.h"

void Shake::update()
{
    if (shaking)
    {
        updateShake();
    }
    else
    {
        cam->setPosition(xOffset, yOffset);

    }
}

void Shake::updateShake()
{

    //Add passed milliseconds to timer... If timer exceeds configuration, shaking ends
    delta = SDL_GetTicks() - timeStart_;
   // shakeTimer += delta;
    if (delta > SHAKE_TIME_MS)
    {
       //Shaking ends 
      //shakeTimer = 0;
        timeStart_ = SDL_GetTicks();
        shaking = false;
        xOffset = 0;
        yOffset = 0;
    }
    else
    {
        applyScreenShake();
    }
}

void Shake::applyScreenShake()
{
    //Depending on shake direction, the screen is moved either to the top left, or the bottom right
    if (shakeDirection)
    {
        xOffset -= 1.5f * delta;
        if (xOffset < -SHAKE_OFFSET)
        {
            //SWITCH DIRECTION
            xOffset = -SHAKE_OFFSET;
            shakeDirection = !shakeDirection;
        }
        yOffset = xOffset;
    }
    else
    {
        xOffset += 1.5f * delta;
        if (xOffset > SHAKE_OFFSET)
        {
            //SWITCH DIRECTION
            xOffset = SHAKE_OFFSET;
            shakeDirection = !shakeDirection;
        }
        yOffset = xOffset;
    }
    cam->setPosition(xOffset, yOffset);
}
