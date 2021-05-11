#pragma once
#include "app\app.h"

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};

enum
{
	OBSTACLE,
	CHARACTER,
	LIFE,
	BASE,
	COLECTIBLE,
};
#define gravity_or_incoming_obj_speed  3.0f;


class BaseObject
{
protected:
	double x;
	double y;
	double width;
	double height;
	int speed;
	int type;
	bool hit;
public:
	BaseObject(double x, double y, double width, double height, int speed,int type )
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->speed = speed;
		this->type = type;
		this->hit = false;
	}

	const bool GetHit();

	void SetHit();

	const double GetX();

	const double GetY();

	const double GetWidth();

	const double GetHeight();

	const int GetType();

	virtual bool DetectCollision(BaseObject* other) = 0;

	virtual void MoveForward() = 0;

	virtual void Draw() = 0;

	virtual void Restart() = 0;

	~BaseObject() {};
};

