#pragma once
#include "App/SimpleSprite.h"

//class for the extra props we want to add like clouds or trees 
class BackgroundAnimation
{
private:
	float x;
	float y;
	float initial_x;
	float moving_speed;
	CSimpleSprite* sprite;
public:
	BackgroundAnimation(float x, float y,float moving_speed, CSimpleSprite* sprite);
	void Reset(float final_x);
	void Restart();
	void MoveForward();
	void Draw();
	~BackgroundAnimation();
};
BackgroundAnimation* CreateNewBackgroundAnimation(float x, float y, float moving_speed, CSimpleSprite* sprite);
