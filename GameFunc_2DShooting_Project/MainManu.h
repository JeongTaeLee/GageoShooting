#pragma once
#include "Scene.h"
class MainManu :
	public Scene
{
private:
	GameObject * lpBackGround;
	GameObject * lp01;

	GameObject * lpStartButton;
	GameObject * lpAdviceButton01;
	GameObject * lpAdviceButton02;
	GameObject * lpGameExit;
	
public:
	MainManu();
	virtual ~MainManu();

	virtual void Init()	override;
	virtual void Release()	override;
	virtual void Update()	override;
	virtual void Render(LPD3DXSPRITE sprite)	override;
};

