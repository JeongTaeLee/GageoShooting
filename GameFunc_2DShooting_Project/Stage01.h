#pragma once
#include "Scene.h"
class Map;

class Stage01 :
	public Scene
{
private:
	float fAccrue;
	float fDelay;
public:
	Stage01();
	virtual ~Stage01();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	void MonsterLoading(Map * map);
	
	virtual void ResourceLoading() override;
};
