#include "PowerUpBase.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

ExtraLife_Or_Colectible_Base::ExtraLife_Or_Colectible_Base(float x, float y, float height, float width, int speed, int type, CSimpleSprite* sprite,int random_point)
    : BaseObject(x, y, width, height, speed, type)
{
    this->initial_position_x = x;
    this->sprite = sprite;
    this->hit = false;
    this->random_point = random_point;
}

void ExtraLife_Or_Colectible_Base::MoveForward()
{
    this->sprite->SetAnimation(ANIM_FORWARDS);
    this->x -= gravity_or_incoming_obj_speed;
    this->sprite->SetPosition(this->x, this->y);
}

bool ExtraLife_Or_Colectible_Base::DetectCollision(BaseObject* another)
{
    return false;
}

void ExtraLife_Or_Colectible_Base::Draw()
{
    if (this->hit == false)
    {
        this->sprite->Draw();
    }
}

void ExtraLife_Or_Colectible_Base::Restart()
{
    this->x = initial_position_x;
    this->hit = false;
    this->sprite->SetPosition(this->x, this->y);
}

void ExtraLife_Or_Colectible_Base::Reset(float final_x)
{
    if (this->x <= 0)
    {
        //we use srand so we can get a different sequence at each run
        srand(time(0));
        //we generate a random number from 0 to 100
        int random = rand() % 100;
        if (random < this->random_point)
        {
            this->x = final_x;
            this->hit = false;
            this->sprite->SetPosition(this->x, this->y);
        }
    }
}

ExtraLife_Or_Colectible_Base::~ExtraLife_Or_Colectible_Base()
{
    delete this->sprite;
}
