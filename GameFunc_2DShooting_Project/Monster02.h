#pragma once
#include "Monster.h"
class Monster02 :
	public Monster
{
public:
	Monster02();
	virtual ~Monster02();

	virtual void Init()	override;
	virtual void Behavior()	override;
};

