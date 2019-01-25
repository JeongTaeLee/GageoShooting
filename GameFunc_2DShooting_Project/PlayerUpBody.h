#pragma once
#include "GameObject.h"

class BulletInfo;

class PlayerUpBody
	:public GameObject
{
protected:
	Renderer * renderer;
	Animater * animater;
	texture * lpMiniMapTex;

	float fDistance;
	float fAttackDelay;
	float fAttackAccrue;

	BulletInfo * lpBulletInfo;

	int		iTotalBullet;
	int		iNowTanchang;
	int		iMaxTanchang;

	float	fReloadDelay;
	float	fReloadAccrue;
	bool	bReLoad;
public:
	PlayerUpBody();
	virtual ~PlayerUpBody();

	virtual void Init()	override;
	virtual void Release() override;
	virtual void Update() override;

	void Input();
	virtual void Attack(const Vector2 & vDir);

	void SetMiniMap(texture * tex);
	texture * GetMiniMap() { return lpMiniMapTex; }

	void InitBulletInfo();
};

