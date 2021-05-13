#pragma once
#include "BasicObject.h"

class Obstacle : public BaseObject
{
private:
	CSimpleSprite* sprite;
	float initial_position_x;
public:
	Obstacle(float x, float y, float height, float width, int speed, CSimpleSprite* sprite);
	void MoveForward();
	void SetAnimationSprite();
	bool DetectCollision(BaseObject* another);
	void Draw();
	void Restart();
	void SetPositionSprite();
	void Reset(float final_x);
	~Obstacle();
};

Obstacle* CreateNewObstacle(float x, float y, float height, float width, int speed, CSimpleSprite* sprite);