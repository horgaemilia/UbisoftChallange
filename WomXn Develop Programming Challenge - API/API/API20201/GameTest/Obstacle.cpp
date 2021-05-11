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
    if (this->sprite != nullptr)
    {
        this->sprite->SetAnimation(ANIM_FORWARDS);
        this->sprite->SetPosition(this->x, this->y);
    }
}

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
