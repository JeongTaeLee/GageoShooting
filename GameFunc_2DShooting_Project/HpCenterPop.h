#pragma once
#include "GameObject.h"
class HpCenterPop :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;

	GameObject * lpXButton;
	GameObject * lpOkButton;
public:
	HpCenterPop();
	virtual ~HpCenterPop();

	virtual void Init()	override;

	void ClickXButton();
	void ClickOkButton();
};

