#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle(float x, float y, float height, float width, int speed, CSimpleSprite* sprite)
    : BaseObject(x, y, width, height, speed,OBSTACLE)
{
    this->initial_position_x = x;
    this->sprite = sprite;
    this->hit = false;
}

void Obstacle::MoveForward()
{
    this->x -= gravity_or_incoming_obj_speed;
    this->SetAnimationSprite();
}

void Obstacle::SetAnimationSprite()
{
    if (this->sprite != nullptr)
    {
        this->sprite->SetAnimation(ANIM_FORWARDS);
        this->sprite->SetPosition(this->x, this->y);
    }
}
//we do not check for the collision in this class but in the avatar class but we must have this function
//since we have it in the class BaseObject
bool Obstacle::DetectCollision(BaseObject* another)
{
    return false;
}

void Obstacle::Draw()
{
    if (this->sprite != nullptr)
    {
        this->sprite->Draw();
    }
}

void Obstacle::Restart()
{
    this->x = initial_position_x;
    this->hit = false;
    this->SetPositionSprite();
}
//we need this function because the sprite is private and we cannot access it within the 
//enemy class
void Obstacle::SetPositionSprite()
{
    this->sprite->SetPosition(this->x, this->y);
}

void Obstacle::Reset(float final_x)
{
    if (this->x <= 0)
    {
        this->x = final_x;
        this->hit = false;
        this->sprite->SetPosition(this->x, this->y);
    }
}

Obstacle::~Obstacle()
{
    delete this->sprite;
}


Obstacle* CreateNewObstacle(float x, float y, float height, float width, int speed, CSimpleSprite* sprite)
{
    return new Obstacle(x,y,height,width,speed,sprite);
}
