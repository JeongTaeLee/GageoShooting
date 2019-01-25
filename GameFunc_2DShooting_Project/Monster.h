#pragma once
#include "GameObject.h"

class Player;
class Map;
class HpBar;

class Monster :
	public GameObject
{
public:
	Renderer * lpRenderer;
	Animater * lpAnimater;
	Collider * lpCollider;
	PixelCollider * lpPixelCollider;
	
	Player * lpPlayer;
	Map * lpMap;
	texture * lpMiniMapTex;

	Vector2 vDir;

	int iGiveGold;
	int iGiveScore;

	float fHp;
	float fRgn;
	float fSpeed;

	bool bTargeting;
	bool bHit;

	float fHitEffectAcrrue;
	float fHitEffectDelay;

	float fAttackAccrue;
	float fAttackDelay;
public:
	Monster();
	virtual ~Monster();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;
public:
	virtual void Behavior() PURE; 
	void Targeting();

	void SetDir();
	void SetMiniMap(texture * tex);
	void SetMap(Map * map);

	virtual void OnCollision(Collider * collider) override;
};

