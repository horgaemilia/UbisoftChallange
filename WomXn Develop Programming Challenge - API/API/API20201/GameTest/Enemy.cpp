#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(float x, float y, float height, float width, int speed, CSimpleSprite* sprite)
	:Obstacle(x,y,height,width,speed,sprite)
{
	this->initial_position_y = y;
}

void Enemy::MoveForward()
{
    this->x -= gravity_or_incoming_obj_speed;
	//i decided that the point from where our bird enemy should go towards the avatar is 600
	//we change both the x and the y
	if (this->x < 600.0f)
	{
		this->y -= 1.55;
	}
	this->SetAnimationSprite();
}
void Enemy::Reset(float final_x)
{
	if (this->x <= 0)
	{
		this->x = final_x;
		this->hit = false;
		this->y = initial_position_y;
		this->SetPositionSprite();
	}
}
void Enemy::Restart()
{
	this->y = initial_position_y;
	Obstacle::Restart();
}

Enemy::~Enemy()
{

}

Enemy* CreateNewEnemy(float x, float y, float height, float width, int speed, CSimpleSprite* sprite)
{
	return new Enemy(x, y, height, width, speed, sprite);
}
