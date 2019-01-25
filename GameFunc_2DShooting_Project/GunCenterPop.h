#pragma once
#include "GameObject.h"
class GunCenterPop :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;

	GameObject * lpButton01;
	GameObject * lpButton02;
	GameObject * lpButton03;
	GameObject * lpXButton;
public:
	GunCenterPop();
	virtual ~GunCenterPop();

	virtual void Init()	override;
	

	void Click01Button();
	void Click02Button();
	void Click03Button();
	void ClickXButton();
};

