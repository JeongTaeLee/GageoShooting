#pragma once
#include "GameObject.h"

enum PLAYERDIRECTION
{
	PD_D,
	PD_DR,
	PD_R,
	PD_UR,
	PD_U,
	PD_UL,
	PD_L,
	PD_DL,
};

class PlayerDownBody;
class PlayerUpBody;
class HpBar;
class GoldUI;
class ScoreUI;

class Player :
	public GameObject
{
private:
	PlayerUpBody * lpUpBody;
	PlayerDownBody * lpDownBody;

	Collider * lpCollider;

	HpBar * lpHpBar;

	bool bHit;
	float fHitEffectAccrue;
	float fHitEffectDelay;

	float fHp;
	int	iSkillPoint;

	GoldUI * lpGoldUi;
	int iGold;

	ScoreUI * lpScoreUi;
	int iScore;
public:
	Player();
	virtual ~Player();

	virtual void Init()	override;
	virtual void Update()	override;
public:
	void SetMiniMap(texture * lpTex);
	
	virtual void OnCollision(Collider * collider) override;
	void ChangeGun(PlayerUpBody * body);

	int		GetGold() { return iGold; }
	void	UsingGold(int _iGold);
	void	AddGold(int _iGold);

	int		GetScore() { return iScore; }
	void	AddScore(int _iScore);

	void ReHp();
};

