#pragma once
#include "PowerUpBase.h"
//extra_life class, we have all the functions implemented in the base class
class Extra_Life : public ExtraLife_Or_Colectible_Base
{
public:
	Extra_Life(float x, float y, float height, float width, int speed,CSimpleSprite* sprite, int random_point);
	~Extra_Life();
};
Extra_Life* CreateNewExtraLife(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point);