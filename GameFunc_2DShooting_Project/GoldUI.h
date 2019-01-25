#pragma once
#include "GameObject.h"

class GoldText;

class GoldUI :
	public GameObject
{
private:
	GoldText * lpGoldText;

	UIRenderer * lpUiRenderer;
public:
	GoldUI();
	virtual ~GoldUI();

	virtual void Init()	override;
	
	void SetGold(int iGold);
};

