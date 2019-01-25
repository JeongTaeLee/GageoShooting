#pragma once
#include "Scene.h"

class Map;

class Stage02 :
	public Scene
{
public:
	Stage02();
	virtual ~Stage02();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	void MonsterLoading(Map * map);

	virtual void ResourceLoading() override;
};

