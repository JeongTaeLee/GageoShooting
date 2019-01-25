#pragma once
#include "Scene.h"
class GameFailed :
	public Scene
{
public:
	GameFailed();
	virtual ~GameFailed();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void ResourceLoading() override;
};

