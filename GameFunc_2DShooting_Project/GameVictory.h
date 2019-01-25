#pragma once
#include "Scene.h"
class GameVictory :
	public Scene
{
private:
public:
	GameVictory();
	virtual ~GameVictory();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void ResourceLoading() override;
};

