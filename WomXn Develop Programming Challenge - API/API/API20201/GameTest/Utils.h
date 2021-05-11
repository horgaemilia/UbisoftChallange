#pragma once
#include "ExtraLife.h"
#include "Colectible.h"
float CHARACTER_HEIGHT = 35.0f;
float CHARACTER_WIDTH = 55.0f;
float OBSTACLE_HEIGHT = 20.0f;
float OBSTACLE_WIDTH = 25.0f;
float colectible_initial_x = 1200.0f;
float colectible_initial_y = 220.0f;
float colectible_height = 25.0f;
float colectible_width = 25.0f;
float life_initial_x = 1400.0f;
float life_initial_y = 220.0f;
float life_height = 20.0f;
float life_width = 40.0f;
float character_initial_x = 150.0f;
float character_initial_y = 152.0f;
float obstacle_initial_x = 1000.0f;
float obstacle_initial_y = 143.0f;
float second_obstacle_x = obstacle_initial_x + 330.0f;
float third_obstacle_x = second_obstacle_x + 330.0f;
int frequence = 40;
bool end_game = false;
float speed = 1.0f / 15.0f;
CSimpleSprite* characterSprite;
CSimpleSprite* obstacle1;
CSimpleSprite* obstacle2;
CSimpleSprite* obstacle3;
CSimpleSprite* ground;
CSimpleSprite* colectible_sprite;
CSimpleSprite* life_sprite;

Extra_Life* extraLife;
Colectible_item* colectible;
Character* myCharacter;
Obstacle* myObstacle;
Obstacle* mySecondObstacle;
Obstacle* myThirdObstacle;


template<typename Base, typename T>
inline bool instanceof(const T*)
{
	return std::is_base_of<Base, T>::value;
}

void initializeCharacter()
{
	characterSprite = App::CreateSprite(".\\TestData\\dog.bmp", 4, 9);
	characterSprite->SetPosition(150.0f, 152.0f);
	characterSprite->CreateAnimation(ANIM_FORWARDS, speed, { 4,5,6,7 });
	characterSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 12,13,14,15 });
	characterSprite->SetScale(2.0f);
	myCharacter = CreateNewCharacter(character_initial_x, character_initial_y, CHARACTER_HEIGHT, CHARACTER_WIDTH, 12, characterSprite);
}

void initializeColectibles()
{
	colectible_sprite = App::CreateSprite(".\\TestData\\coins.bmp",6,1);
	colectible_sprite->SetPosition(1000.0f, 200.0f);
	colectible_sprite->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3,4,5 });
	colectible_sprite->SetScale(2.0f);
	colectible = CreateNewColectible(colectible_initial_x, colectible_initial_y, colectible_height, colectible_width, speed, colectible_sprite, frequence);
}

void initializeExtraLife()
{
	life_sprite = App::CreateSprite(".\\TestData\\bone.bmp", 1, 1);
	life_sprite->SetPosition(1000.0f, 200.0f);
	life_sprite->SetFrame(0);
	life_sprite->CreateAnimation(ANIM_FORWARDS, speed, { 0 });
	life_sprite->SetScale(0.3f);
	extraLife = CreateNewExtraLife(life_initial_x, life_initial_y, life_height, life_width, speed, life_sprite, frequence);
}

void initializeObstacles()
{
	obstacle1 = App::CreateSprite(".\\TestData\\cat.bmp", 2, 2);
	obstacle1->SetPosition(700.0f, 143.0f);
	obstacle1->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3 });
	obstacle1->SetScale(0.7f);
	myObstacle = CreateNewObstacle(obstacle_initial_x, obstacle_initial_y, OBSTACLE_HEIGHT, OBSTACLE_WIDTH, 12, obstacle1);


	obstacle2 = App::CreateSprite(".\\TestData\\cat.bmp", 2, 2);
	obstacle2->SetPosition(700.0f, 143.0f);
	obstacle2->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3 });
	obstacle2->SetScale(0.7f);
	mySecondObstacle = CreateNewObstacle(second_obstacle_x, obstacle_initial_y, OBSTACLE_HEIGHT, OBSTACLE_WIDTH, 12, obstacle2);

	obstacle3 = App::CreateSprite(".\\TestData\\cat.bmp", 2, 2);
	obstacle3->SetPosition(700.0f, 143.0f);
	obstacle3->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3 });
	obstacle3->SetScale(0.7f);
	myThirdObstacle = CreateNewObstacle(third_obstacle_x, obstacle_initial_y, OBSTACLE_HEIGHT, OBSTACLE_WIDTH, 12, obstacle3);
}
void MoveForward()
{
	myCharacter->MoveForward();
	myObstacle->MoveForward();
	mySecondObstacle->MoveForward();
	myThirdObstacle->MoveForward();
	extraLife->MoveForward();
	colectible->MoveForward();
}
void Reset()
{
	myObstacle->Reset(obstacle_initial_x);
	mySecondObstacle->Reset(obstacle_initial_x);
	myThirdObstacle->Reset(obstacle_initial_x);
	extraLife->Reset(life_initial_x);
	colectible->Reset(colectible_initial_x);
}
void DetectCollision()
{
	myCharacter->DetectCollision(myObstacle);
	myCharacter->DetectCollision(mySecondObstacle);
	myCharacter->DetectCollision(myThirdObstacle);
	myCharacter->DetectCollision(extraLife);
	myCharacter->DetectCollision(colectible);
}

void initializeGameObjects()
{
	initializeCharacter();
	initializeObstacles();
	initializeColectibles();
	initializeExtraLife();
}

void Draw()
{
	myCharacter->Draw();
	ground->Draw();
	myObstacle->Draw();
	mySecondObstacle->Draw();
	myThirdObstacle->Draw();
	extraLife->Draw();
	colectible->Draw();
}

void PrintScore()
{
	std::string message = "Score: " + std::to_string(myCharacter->GetScore());
	const char* msg = message.c_str();
	App::Print(400, 600, msg, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);
}

void PrintColectibles()
{
	std::string message = "Colectibles: " + std::to_string(myCharacter->GetColectibles());
	const char* msg = message.c_str();
	App::Print(400, 700, msg, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);
}

void Restart()
{
	end_game = false;
	myCharacter->Restart();
	myObstacle->Restart();
	mySecondObstacle->Restart();
	myThirdObstacle->Restart();
	colectible->Restart();
	extraLife->Restart();
}