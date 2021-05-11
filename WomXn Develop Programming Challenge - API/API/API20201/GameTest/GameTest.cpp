//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "Domain.h"
#include "Obstacle.h"
#include "Utils.h"
//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------
CSimpleSprite* test;
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....

	//myCharacter = CreateNewCharacter( 400.0f, 400.0f, 2.0f, 2.0f, 12);
	/*
	testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	testSprite->SetPosition(400.0f, 400.0f);
	float speed = 1.0f / 15.0f;
	testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
	testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
	testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
	testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
	testSprite->SetScale(2.0f);

	testSprite2 = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	testSprite2->SetPosition(400.0f, 400.0f);	
	testSprite2->SetFrame(2);
	testSprite2->SetScale(1.0f);
	//------------------------------------------------------------------------


	*/

	ground = App::CreateSprite(".\\TestData\\finalGround.bmp", 1, 1);
	ground->SetPosition(400.0f, 100.0f);
	ground->SetFrame(1);
	ground->SetScale(2.0f);

	initializeGameObjects();



}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	if (myCharacter->IsAlive())
	{
		myCharacter->DefaultIncreaseScore();
		MoveForward();
		Reset();
		DetectCollision();
		//testSprite3->Update(deltaTime);
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
		{
			if (myCharacter->IsJumping() == false)
			{
				myCharacter->SetForce(FORCE);
				myCharacter->Jump();
			}
		}
		if (myCharacter->IsJumping())
		{
			myCharacter->DecreaseVelocity();
			myCharacter->Jump();
		}
		characterSprite->Update(deltaTime);
	}
	else
	{
		end_game = true;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
		{
			Restart();
		}
	}
	/*
	testSprite->Update(deltaTime);
	testSprite2->Update(deltaTime);
	testSprite3->Update(deltaTime);
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		testSprite->SetAnimation(ANIM_RIGHT);
		float x, y;
		testSprite->GetPosition(x, y);
		x += 1.0f;
		testSprite->SetPosition(x, y);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_LEFT);
		float x, y;
		testSprite->GetPosition(x, y);
		x -= 1.0f;
		testSprite->SetPosition(x, y);
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		testSprite->SetAnimation(ANIM_FORWARDS);
		float x, y;
		testSprite->GetPosition(x, y);
		y += 1.0f;
		testSprite->SetPosition(x, y);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_BACKWARDS);
		float x, y;
		testSprite->GetPosition(x, y);
		y -= 1.0f;
		testSprite->SetPosition(x, y);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{
		testSprite->SetScale(testSprite->GetScale() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		testSprite->SetScale(testSprite->GetScale() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		//testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
		testSprite3->SetAnimation(ANIM_BACKWARDS);
		float x, y;
		testSprite3->GetPosition(x, y);
		x -= 1.0f;
		testSprite3->SetPosition(x, y);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		//testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
		testSprite3->SetAnimation(ANIM_FORWARDS);
		float x, y;
		testSprite3->GetPosition(x, y);
		x += 1.0f;
		testSprite3->SetPosition(x, y);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		testSprite->SetAnimation(-1);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		testSprite->SetVertex(0, testSprite->GetVertex(0) + 5.0f);
	}
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
	*/
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	

	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	/*
	static float a = 0.0f;
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	a += 0.1f;
	for (int i = 0; i < 20; i++)
	{

		float sx = 200 + sinf(a + i * 0.1f)*60.0f;
		float sy = 200 + cosf(a + i * 0.1f)*60.0f;
		float ex = 700 - sinf(a + i * 0.1f)*60.0f;
		float ey = 700 - cosf(a + i * 0.1f)*60.0f;
		g = (float)i / 20.0f;
		b = (float)i / 20.0f;
		App::DrawLine(sx, sy, ex, ey,r,g,b);
	}
	*/
	//------------------------------------------------------------------------
	// Example Sprite Code....
	//testSprite->Draw();
	//testSprite2->Draw();
	//testSprite3->Draw();
	Draw();
	//obstacle->Draw();
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	//App::Print(100, 100, "Sample Text");

	if (end_game)
	{
		App::Print(100, 100, "GAME OVER", 255, 255, 255,GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(100, 900, "PRESS LEFT ARROW TO RESTART", 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	std::string message = "Curent Lives: "+std::to_string(myCharacter->GetHealth());
	const char* msg = message.c_str();
	App::Print(400, 400,msg, 255, 255, 255, GLUT_BITMAP_TIMES_ROMAN_24);
	PrintScore();
	PrintColectibles();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete ground;
	delete myCharacter;
	delete myThirdObstacle;
	delete mySecondObstacle;
	delete myObstacle;
	//------------------------------------------------------------------------
}