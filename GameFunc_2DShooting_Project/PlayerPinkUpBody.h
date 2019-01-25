#pragma once
#include "PlayerUpBody.h"
class PlayerPinkUpBody :
	public PlayerUpBody
{
private:
	
public:
	PlayerPinkUpBody();
	virtual ~PlayerPinkUpBody();

	virtual void Init()	override;
	virtual void Attack(const Vector2& dir) override;
};

