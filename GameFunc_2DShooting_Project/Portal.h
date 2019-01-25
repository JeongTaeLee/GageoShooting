#pragma once
#include "GameObject.h"
class Portal :
	public GameObject
{ 
private:
	Renderer * renderer;
	Collider * collider;
public:
	Portal();
	virtual ~Portal();

	virtual void Init()	override;
	
	virtual void OnCollision(Collider * collider) override;
};

