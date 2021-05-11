#pragma once
#include "BasicObject.h"
class ExtraLife_Or_Colectible_Base : public BaseObject
{
private:
	CSimpleSprite* sprite;
	float initial_position_x;
	int random_point;
public:
	ExtraLife_Or_Colectible_Base(float x, float y, float height, float width, int speed, int type, CSimpleSprite* sprite,int random_point);
	void MoveForward();
	bool DetectCollision(BaseObject* another);
	void Draw();
	void Restart();
	void Reset(float final_x);
	~ExtraLife_Or_Colectible_Base();
};