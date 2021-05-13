#pragma once
#include "Obstacle.h"
//the class enemy is very similar to obstacle the only difference is in the functions we overrided

class Enemy :
    public Obstacle
{
private:
    float initial_position_y;
public:
    Enemy(float x, float y, float height, float width, int speed, CSimpleSprite* sprite);
    void MoveForward();
    void Reset(float final_x);
    void Restart();
    ~Enemy();
};
Enemy* CreateNewEnemy(float x, float y, float height, float width, int speed, CSimpleSprite* sprite);
