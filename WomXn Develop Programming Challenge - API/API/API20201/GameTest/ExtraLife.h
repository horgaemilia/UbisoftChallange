#pragma once
#include "PowerUpBase.h"

class Extra_Life : public ExtraLife_Or_Colectible_Base
{
public:
	Extra_Life(float x, float y, float height, float width, int speed,CSimpleSprite* sprite, int random_point);
	~Extra_Life();
};
Extra_Life* CreateNewExtraLife(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point);