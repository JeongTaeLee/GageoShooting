#pragma once
#include "Component.h"
class Collider :
	public Component
{
public:
	Vector2 vSize;

	RECT reRgn;
	bool bCenter;
public:
	Collider();
	virtual ~Collider();

	virtual void Init()		override;
	virtual void Release()	override;
	virtual void Update()	override;

	void SetCollider(const Vector2 & vSize, bool center);
	void SetRgn();
};