#include "stdafx.h"
#include "BackgroundAnimation.h"

BackgroundAnimation::BackgroundAnimation(float x, float y, float moving_speed, CSimpleSprite* sprite)
{
	this->x = x;
	this->initial_x = x;
	this->y = y;
	this->sprite = sprite;
	this->moving_speed = moving_speed;
}


//we have a parameter for this function because if we have multiple objects of the same type
//we want to keep the same distance throughout the game so it doesn't become unplayable
void BackgroundAnimation::Reset(float final_x)
{
	if (this->x <= 0)
	{
		this->x = final_x;
		if (this->sprite != nullptr)
		{
			this->sprite->SetPosition(this->x, this->y);
		}
	}
}

void BackgroundAnimation::Restart()
{
	this->x = initial_x;
	this->sprite->SetPosition(this->x, this->y);
}

void BackgroundAnimation::MoveForward()
{
	this->x -= this->moving_speed;
	if (this->sprite != nullptr)
	{
		this->sprite->SetPosition(this->x, this->y);
	}
	
}

void BackgroundAnimation::Draw()
{
	if (this->sprite != nullptr)
	{
		this->sprite->Draw();
	}
}

BackgroundAnimation::~BackgroundAnimation()
{
	delete this->sprite;
}

BackgroundAnimation* CreateNewBackgroundAnimation(float x, float y, float moving_speed, CSimpleSprite* sprite)
{
	return new BackgroundAnimation(x,y,moving_speed,sprite);
}
