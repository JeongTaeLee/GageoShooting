#pragma once
#include "GameObject.h"
class ScoreText :
	public GameObject
{
public:
	UIText * lpUiText;
public:
	ScoreText();
	virtual ~ScoreText();

	virtual void Init()	override;
};

