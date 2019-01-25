#pragma once
#include "Component.h"
class Transform :
	public Component
{
public:
	Vector2 pos;
	Vector2 scale;
	float rot;

	D3DXMATRIX matWorld;
	Vector2 worldPos;
public:
	Transform();
	virtual ~Transform();

	void UpdateTransform();
	void SetTransform(LPD3DXSPRITE sprite);
};

