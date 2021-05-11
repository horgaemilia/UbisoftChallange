#include "stdafx.h"
#include "ExtraLife.h"

Extra_Life::Extra_Life(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point)
	:ExtraLife_Or_Colectible_Base(x, y, height, width, speed,LIFE,sprite,random_point)
{
}

Extra_Life::~Extra_Life()
{
}

Extra_Life* CreateNewExtraLife(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point)
{
	return new Extra_Life(x,y,height,width,speed,sprite,random_point);
}
