#pragma once
#include "Monster.h"

enum JUMPSTATE
{
	NONE,
	JUMPSTART,
	JUMPING,
	JUMPEND,
	BACKATTACK,
};

class Boss :
	public Monster
{
private:
	bool bAttacking;
	bool bJumpStart;
	

	float fAttackingDelay;
	float fAttackingAccrue;

	JUMPSTATE eJumpState;
	
	Vector2 vJumpStartPos;
	Vector2 vJumpEndPos;

	float	fJumpingAccrue;
	float	fJumpingDelay;

	float	fDownAccrue;
	float	fDownDelay;

	float	fStartAccrue;
	float	fStartDelay;

	float   fDieAccrue;
	float	fDieDelay;

	bool bDie;
public:
	Boss();
	virtual ~Boss();

	virtual void Init()	override;

	virtual void Update()	override;
	virtual void Behavior() override;

	void UnAttacking();
	void OnAttacking();

	virtual void OnCollision(Collider * collider) override;
};

