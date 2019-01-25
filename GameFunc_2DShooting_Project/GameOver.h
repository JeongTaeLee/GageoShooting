#pragma once
#include "Scene.h"
class GameOver :
	public Scene
{
public:
	GameOver();
	virtual ~GameOver();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void ResourceLoading() override;
};

