#include "Avatar.h"
#include "Obstacle.h"
#include <iostream>

Character::Character(float x, float y, float height, float width,int type, CSimpleSprite* sprite)
: BaseObject(x, y, width, height, speed,CHARACTER)
{
	this->currentY = y;
	this->health = INITIAL_HEALTH;
	this->force = 0;
	this->sprite = sprite;
	this->collectibles = 0;
	this->score = 0;
	this->initialY = y;
}
bool Character::DetectCollision(BaseObject* another)
{
	//if (instanceof<Obstacle>(another)) ?
	int type = another->GetType();
	//we will get the type of the other object and then do different actions based
	//on its type
	switch (type)
	{
	case OBSTACLE:
		if (another->GetHit() == false)
		{
			if (this->Aux_Hit(another) == true)
			{
				// collision detected with an obstacle or an enemy
				another->SetHit();
				//we need to set the hit field so we do not intersect multiple times 
				//with an object when he didn't go out of the map yet
				this->health -= 1;
				this->DecreaseScore();
				return true;
			}
		}
	case LIFE:
		if(another->GetHit() == false )
		{
			if (this->Aux_Hit(another) == true)
			{
				// collision detected with extra life!
				another->SetHit();
				this->GainLife();
				this->IncreaseScore();
				return true;
			}
		}
	case COLECTIBLE:
		if (another->GetHit() == false)
		{
			if (this->Aux_Hit(another) == true)
			{
				// collision detected with a collectible!
				another->SetHit();
				this->IncreaseColectibles();
				this->IncreaseScore();
				return true;
			}
		}
	}

	return false;
}

int Character::GetColectibles()
{
	return this->collectibles;
}

void Character::IncreaseColectibles()
{
	this->collectibles += 1;
}
//we created an auxiliar function for the hit where we compute their hitboxes and then we
//check if they intersect
bool Character::Aux_Hit(BaseObject* another)
{
	return (another->GetX() < this->x + this->width &&
		another->GetX() + another->GetWidth() > this->x &&
		another->GetY() < this->currentY + this->height &&
		another->GetY() + another->GetHeight() > this->currentY);
}

Character* CreateNewCharacter(float x, float y, float height, float width, int speed,CSimpleSprite* sprite)
{
	return new Character(x,y,height,width,speed,sprite);
}


void Character::MoveForward()
{
	this->sprite->SetAnimation(ANIM_FORWARDS);
}

float Character::GetScore()
{
	return this->score;
}

void Character::DefaultIncreaseScore()
{
	this->score += 0.10f;
}

void Character::IncreaseScore()
{
	this->score += 1;
}

void Character::DecreaseScore()
{
	if (this->score >= 1)
	{
		this->score -= 1;
	}
}

void Character::Draw()
{
	if (this->sprite != nullptr)
	{
		this->sprite->Draw();
	}
}

void Character::GainLife()
{
	if (this->health < 5)
	{
		this->health += 1;
	}
}

bool Character::IsAlive()
{
	return this->health != 0;
}

bool Character::IsJumping()
{
	//we check if the current y is at the level of the ground or not
	return this->currentY != this->y;
}

void Character::SetForce(float force)
{
	this->force = force;
}

void Character::Jump()
{
	this->currentY = this->y + this->force;
	this->sprite->SetPosition(this->x, this->currentY);
}

//auxiliar function for the jump so he doesn't instantly get on the ground
void Character::DecreaseVelocity()
{
	this->force -= gravity_or_incoming_obj_speed;
}


float Character::GetForce()
{
	return this->force;
}

void Character::Restart()
{
	//we reset the properties to their initial value so we can play again
	this->currentY = this->initialY;
	this->y = this->initialY;
	this->sprite->SetPosition(this->x, this->y);
	this->health = INITIAL_HEALTH;
	this->force = 0;
	this->collectibles = 0;
	this->score = 0;
}

int Character::GetHealth()
{
	return this->health;
}


Character::~Character() 
{
	delete this->sprite;
};