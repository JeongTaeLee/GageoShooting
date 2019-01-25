#pragma once
#include "singleton.h"
class CameraManager :
	public singleton<CameraManager>
{
private:
	Vector2 vEyePos;
	Vector2 vEyeScale;
	Vector2 vEyeSize;

	Vector2 vScroll;

	Matrix matView;
	Matrix matProj;

	Vector2 vMinLock;
	Vector2 vMaxLock;

	Vector2 vTargetPos;
	bool bTargeting;
	float fS;

	float fShakePower;
	float fShakeDamage;
	float fMulti;
public:
	CameraManager();
	virtual ~CameraManager();

	void Reset();
	void Update();
	void SetTransform();

	void SetViewMatrix();

public:
	void SetTarget(const Vector2 & targetPos, float s);
	const Vector2 & GetScroll() { return vScroll; }

	void SetLock(const Vector2 & minLock, const Vector2 & maxLock);
	void StartShake(float fPower, float s);
};

#define CAMERA CameraManager::GetInst()