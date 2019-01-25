#pragma once
#include "GameObject.h"
class GoldText :
	public GameObject
{
public:
	UIText * lpUiText;
public:
	GoldText();
	virtual ~GoldText();

	virtual void Init()	override;

};

