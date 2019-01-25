#pragma once
#include "Scene.h"
class IntroScene :
	public Scene
{
private:
	
public:
	IntroScene();
	virtual ~IntroScene();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void ResourceLoading() override;

};

