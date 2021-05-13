#pragma once
#include "PowerUpBase.h"
//collectible class, we have all the functions implemented in the base class
class Colectible_item : public ExtraLife_Or_Colectible_Base
{
public:
	Colectible_item(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point);
};
Colectible_item* CreateNewColectible(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point);