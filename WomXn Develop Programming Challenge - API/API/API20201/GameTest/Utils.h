#pragma once
#include "ExtraLife.h"
#include "Colectible.h"
#include "Enemy.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include "BackgroundAnimation.h"
float CHARACTER_HEIGHT = 35.0f;
float CHARACTER_WIDTH = 55.0f;
float OBSTACLE_HEIGHT = 35.0f;
float OBSTACLE_WIDTH = 35.0f;
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
float enemy_initial_y = 400.0f;
int frequence = 40;
bool end_game = false;
float speed = 1.0f / 15.0f;
float moving_clouds_speed = 0.2f;
float cloud1_x = 1000.0f;
float cloud2_x = 1600.0f;
float clouds_y = 500.0f;

CSimpleSprite* characterSprite;
CSimpleSprite* obstacle1;
CSimpleSprite* obstacle2;
CSimpleSprite* obstacle3;
CSimpleSprite* ground;
CSimpleSprite* colectible_sprite;
CSimpleSprite* life_sprite;
CSimpleSprite* life_hud;
CSimpleSprite* coin_hud;
CSimpleSprite* cloud1;
CSimpleSprite* cloud2;
CSimpleSprite* background_hud;

Extra_Life* extraLife;
Colectible_item* colectible;
Character* myCharacter;
Obstacle* myObstacle;
Enemy* mySecondObstacle;
Obstacle* myThirdObstacle;
BackgroundAnimation* cloud1_animation;
BackgroundAnimation* cloud2_animation;



int bestScore;
int current_time_in_minutes;
int current_time_in_seconds;
int total_in_game_time_minutes;
int total_in_game_time_seconds;
auto start_time = std::chrono::steady_clock::now();

template<typename Base, typename T>
inline bool instanceof(const T*)
{
	return std::is_base_of<Base, T>::value;
}

void ReadTimeAndScore()
{
	std::fstream myfile;
	std::string line;
	myfile.open(".\\TestData\\stats.txt");
	std::getline(myfile, line);
	bestScore = stoi(line);
	std::getline(myfile, line);
	total_in_game_time_minutes = stoi(line);
	std::getline(myfile, line);
	total_in_game_time_seconds = stoi(line);
	myfile.close();
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

void initializeClouds()
{
	cloud1 = App::CreateSprite(".\\TestData\\clouds.bmp", 1, 1);
	cloud1->SetFrame(0);
	cloud1->SetScale(2.0f);

	cloud2 = App::CreateSprite(".\\TestData\\clouds.bmp", 1, 1);
	cloud2->SetFrame(0);
	cloud2->SetScale(2.0f);

	cloud1_animation = CreateNewBackgroundAnimation(cloud1_x, clouds_y, moving_clouds_speed, cloud1);
	cloud2_animation = CreateNewBackgroundAnimation(cloud2_x, clouds_y, moving_clouds_speed, cloud2);
}

void initializeHud()
{
	background_hud = App::CreateSprite(".\\TestData\\background.bmp", 1, 1);
	background_hud->SetPosition(512.0f, 724.0f);
	background_hud->SetFrame(1);
	background_hud->SetScale(1.0f);

	life_hud = App::CreateSprite(".\\TestData\\bone.bmp", 1, 1);
	life_hud->SetPosition(250.0f, 710.0f);
	life_hud->SetFrame(0);
	life_hud->SetScale(0.3f);

	coin_hud = App::CreateSprite(".\\TestData\\coins.bmp", 6, 1);
	coin_hud->SetPosition(80.0f, 710.0f);
	coin_hud->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3,4,5 });
	coin_hud->SetAnimation(ANIM_FORWARDS);
	coin_hud->SetScale(2.0f);

	ReadTimeAndScore();

}

void DrawHud()
{
	background_hud->Draw();
	coin_hud->Draw();
	life_hud->Draw();
	std::string collectibles_nr = " X " + std::to_string(myCharacter->GetColectibles());
	const char* message_collectible = collectibles_nr.c_str();
	App::Print(100, 700, message_collectible, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);

	std::string life_nr = " X " + std::to_string(myCharacter->GetHealth());
	const char* message_life = life_nr.c_str();
	App::Print(300, 700, message_life, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);

	std::string message = "Score: " + std::to_string(int(myCharacter->GetScore()));
	const char* msg = message.c_str();
	App::Print(360, 700, msg, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);

	std::string message_best_score = "Best Score: " + std::to_string(bestScore);
	const char* msg_best_score = message_best_score.c_str();
	App::Print(480, 700, msg_best_score, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);

	std::string current_time = "Time: m:" + std::to_string(current_time_in_minutes) + "s:" + std::to_string(current_time_in_seconds);
	const char* msg_time = current_time.c_str();
	App::Print(670, 700, msg_time, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);

	std::string total_time = "Total Time:" + std::to_string(total_in_game_time_minutes);
	const char* msg_total = total_time.c_str();
	App::Print(850, 700, msg_total, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);	
}

void UpdateTime()
{
	auto end = std::chrono::steady_clock::now();
	current_time_in_minutes = std::chrono::duration_cast<std::chrono::minutes>(end - start_time).count();
	current_time_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start_time).count();
	current_time_in_seconds = current_time_in_seconds % 60;
}

void WriteTimeAndScore()
{
	std::ofstream myfile;
	myfile.open(".\\TestData\\stats.txt");
	myfile << bestScore <<"\n"<< total_in_game_time_minutes<<"\n"<<total_in_game_time_seconds;
	myfile.close();
}

void UpdateValues()
{
	if (bestScore < int(myCharacter->GetScore()))
	{
		bestScore = int(myCharacter->GetScore());
	}
	WriteTimeAndScore();
}

void UpdateTotalTime()
{
	total_in_game_time_minutes += current_time_in_minutes;
	total_in_game_time_seconds += current_time_in_seconds % 60;
	if (total_in_game_time_seconds >= 60)
	{
		total_in_game_time_minutes += 1;
		total_in_game_time_seconds = total_in_game_time_seconds % 60;
	}
	WriteTimeAndScore();
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


	obstacle2 = App::CreateSprite(".\\TestData\\bat.bmp", 4, 4);
	obstacle2->SetPosition(700.0f, 143.0f);
	obstacle2->CreateAnimation(ANIM_FORWARDS, speed, { 12,13,14,15 });
	obstacle2->SetFrame(13);
	obstacle2->SetScale(4.0f);
	mySecondObstacle = CreateNewEnemy(second_obstacle_x, enemy_initial_y, OBSTACLE_HEIGHT, OBSTACLE_WIDTH, 12, obstacle2);

	obstacle3 = App::CreateSprite(".\\TestData\\cat.bmp", 2, 2);
	obstacle3->SetPosition(700.0f, 143.0f);
	obstacle3->CreateAnimation(ANIM_FORWARDS, speed, { 0,1,2,3 });
	obstacle3->SetScale(0.7f);
	myThirdObstacle = CreateNewObstacle(third_obstacle_x, obstacle_initial_y, OBSTACLE_HEIGHT, OBSTACLE_WIDTH, 12, obstacle3);
}
void MoveForward()
{
	cloud1_animation->MoveForward();
	cloud2_animation->MoveForward();
	myCharacter->MoveForward();
	myObstacle->MoveForward();
	mySecondObstacle->MoveForward();
	myThirdObstacle->MoveForward();
	extraLife->MoveForward();
	colectible->MoveForward();
}
void Reset()
{
	cloud1_animation->Reset(cloud1_x);
	cloud2_animation->Reset(cloud1_x);
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
	initializeClouds();
	initializeCharacter();
	initializeObstacles();
	initializeColectibles();
	initializeExtraLife();
	initializeHud();
}

void Draw()
{
	cloud1_animation->Draw();
	cloud2_animation->Draw();
	myCharacter->Draw();
	ground->Draw();
	myObstacle->Draw();
	mySecondObstacle->Draw();
	myThirdObstacle->Draw();
	extraLife->Draw();
	colectible->Draw();
	DrawHud();
}

void PrintScore()
{
	std::string message = "Score: " + std::to_string(myCharacter->GetScore());
	const char* msg = message.c_str();
	App::Print(400, 600, msg, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);
}
void Restart()
{
	end_game = false;
	cloud1_animation->Restart();
	cloud2_animation->Restart();
	myCharacter->Restart();
	myObstacle->Restart();
	mySecondObstacle->Restart();
	myThirdObstacle->Restart();
	colectible->Restart();
	extraLife->Restart();
}