#pragma once
#include "BasicObject.h";
#define INITIAL_HEALTH  2;
#define INITIAL_POSITION_X 300.0;
#define DEFAULT_POSITION_Y 400.0;
#define HEIGHT 3.0;
#define WIDTH 4.0;
#define FORCE 150.0f
#define SPRITE_FILE ".\\TestData\\dog.bmp";
#define SPRITE_ROWS 9;
#define SPRITE_COLUMNS 4; 
#define ANIMATION_SPEED 1.0f / 15.0f;


//my avatar class which takes as parameters the x,y height, width and speed
class Character : public BaseObject
{
private:
	int health;
	int force;
	CSimpleSprite* sprite;
	int currentY;
	int collectibles;
	bool Aux_Hit(BaseObject* another);
	float score;

public:
	Character(float x, float y, float height, float width, int speed,CSimpleSprite* sprite);

	void SetY(float y);

	bool DetectCollision(BaseObject* another);

	float GetScore();

	void IncreaseScore();

	void DefaultIncreaseScore();

	void DecreaseScore();

	int GetHealth();

	void MoveForward();

	void Jump();

	void GainLife();

	void SetForce(float force);

	void DecreaseVelocity();

	void IncreaseVelocity();

	bool IsAlive();

	bool IsJumping();

	void Draw();

	void Restart();

	float GetForce();

	~Character();

	int GetColectibles();

	void IncreaseColectibles();

};
Character* CreateNewCharacter(float x, float y, float height, float width, int speed, CSimpleSprite* sprite);