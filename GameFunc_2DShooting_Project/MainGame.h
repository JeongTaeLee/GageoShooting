#pragma once
class MainGame
{
public:
	LPD3DXSPRITE sprite;
public:
	MainGame();
	~MainGame();

	void Init();
	void Release();
	void Update();
	void Render();
};

