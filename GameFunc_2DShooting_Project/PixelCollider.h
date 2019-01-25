#pragma once
#include "Component.h"
class PixelCollider :
	public Component
{
private:
	texture * lpCollisionTex;
	D3DXCOLOR d3dCollColor;

	Vector2 vBackDir;

	bool	bInCollision;
	float	fSpeed;

	int iWidth;
	int iHeight;
public:
	PixelCollider();
	virtual ~PixelCollider();

public:
	virtual void Update()	override;

	void Push();
	bool PixelCollision(const Vector2 & pos, const Vector2 & dir, float speed);

public:
	void SetCollisionTex(texture * lpTex, const D3DXCOLOR & collColor);
	bool GetCollision() { return bInCollision; }
};

