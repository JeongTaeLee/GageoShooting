#pragma once
#include "GameObject.h"

class ScoreText;

class ScoreUI :
	public GameObject
{
private:
	ScoreText * lpScoreText;

	UIRenderer * lpUiRenderer;
public:
	ScoreUI();
	virtual ~ScoreUI();

	virtual void Init()	override;

	void SetScore(int _iScore);
};

