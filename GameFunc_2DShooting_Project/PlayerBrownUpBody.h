#pragma once
#include "PlayerUpBody.h"
class PlayerBrownUpBody :
	public PlayerUpBody
{
public:
	PlayerBrownUpBody();
	virtual ~PlayerBrownUpBody();

	virtual void Init()	override;
	virtual void Attack(const Vector2 & dir) override;
};

