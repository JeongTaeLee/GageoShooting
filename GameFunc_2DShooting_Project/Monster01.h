#pragma once
#include "Monster.h"
class Monster01 :
	public Monster
{

public:
	Monster01();
	virtual ~Monster01();

public:
	virtual void Init()	override;
	virtual void Behavior() override;
};

