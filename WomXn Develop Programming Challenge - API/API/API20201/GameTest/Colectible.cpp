#include "stdafx.h"
#include "Colectible.h"

Colectible_item::Colectible_item(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point)
	:ExtraLife_Or_Colectible_Base(x, y, height, width, speed, COLECTIBLE, sprite, random_point)
{
}

Colectible_item* CreateNewColectible(float x, float y, float height, float width, int speed, CSimpleSprite* sprite, int random_point)
{
	return new Colectible_item(x,y,height,width,speed,sprite,random_point);
}
