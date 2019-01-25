#include "DXUT.h"
#include "MainGame.h"
#include "Stage01.h"
#include "Stage02.h"
#include "MainManu.h"
#include "GameVictory.h"
#include "GameFailed.h"
#include "IntroScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	SOUND.AddSound("Explosion", "./rs/Explosion.wav");
	SOUND.AddSound("InGameBGM", "./rs/Ingame.wav");
	SOUND.AddSound("ManuBGM", "./rs/MainManu.wav");
	SOUND.AddSound("Fire", "./rs/Fire.wav");
	SOUND.AddSound("Intro", "./rs/Intro.wav");
	SOUND.AddSound("Loading", "./rs/Loading.wav");
	SOUND.AddSound("Failed", "./rs/Failed.wav");

	D3DXCreateSprite(g_device, &sprite);

	SCENE.AddScene("MainManu", new MainManu);
	SCENE.AddScene("Intro", new IntroScene);
	SCENE.AddScene("Ingame01", new Stage01);
	SCENE.AddScene("Ingame02", new Stage02);
	SCENE.AddScene("GameVictory", new GameVictory);
	SCENE.AddScene("GameFailed", new GameFailed);
	SCENE.ChanScene("Intro");
}

void MainGame::Release()
{
	SceneManager::ReleaseInst();
	ObjectManager::ReleaseInst();
	ImageManager::ReleaseInst();
	InputManager::ReleaseInst();
	CameraManager::ReleaseInst();
	TimeManager::ReleaseInst();
	SoundManager::ReleaseInst();

	SAFE_RELEASE(sprite);
}

void MainGame::Update()
{
	INPUT.Update();
	SCENE.Update();
}

void MainGame::Render()
{
	SCENE.Render(sprite);
}
