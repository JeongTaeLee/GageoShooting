#include "DXUT.h"
#include "CameraManager.h"


CameraManager::CameraManager()
	:vTargetPos(0.f, 0.f), bTargeting(false), vMinLock(Vector2(0.f, 0.f)), vMaxLock(Vector2(0.f, 0.f)), fShakePower(0.f), fShakeDamage(0.f), fMulti(1.f)
{
	vEyePos = Vector2((float)WINSIZEX / 2.f, (float)WINSIZEX / 2.f);
	vEyeScale = Vector2(1.f, 1.f);
	vEyeSize = Vector2((float)WINSIZEX, (float)WINSIZEY);

	vScroll = Vector2(0.f, 0.f);

	SetViewMatrix();
	D3DXMatrixOrthoLH(&matProj, vEyeSize.x, -vEyeSize.y, 0.f, 1.f);
}


CameraManager::~CameraManager()
{
}

void CameraManager::Reset()
{
	vEyePos = Vector2((float)WINSIZEX / 2.f, (float)WINSIZEX / 2.f);
	vEyeScale = Vector2(1.f, 1.f);
	vEyeSize = Vector2((float)WINSIZEX, (float)WINSIZEY);

	vScroll = Vector2(0.f, 0.f);

	SetViewMatrix();
	D3DXMatrixOrthoLH(&matProj, vEyeSize.x, -vEyeSize.y, 0.f, 1.f);
	
	bTargeting = false;
}

void CameraManager::Update()
{
	if (fShakePower > 0.f)
	{
		vEyePos.x += fShakePower * fMulti;
		vEyePos.y += fShakePower * fMulti;

		fShakePower -= fShakeDamage;

		fMulti *= -1;
	}

	if (bTargeting)
	{
		D3DXVec2Lerp(&vEyePos, &vEyePos, &vTargetPos, fS);

		Vector2 vDistance = vTargetPos - vEyePos;
		float fDistance = D3DXVec2Length(&vDistance);

		if (fDistance < 0.1f)
		{
			bTargeting = false;
			vEyePos = vTargetPos;
			vTargetPos = Vector2(0.f, 0.f);
		}
	}

	Vector2 OriginPos;
	OriginPos.x = (float)WINSIZEX / 2.f;
	OriginPos.y = (float)WINSIZEY / 2.f;

	vScroll = Vector2(vEyePos.x - OriginPos.x, vEyePos.y - OriginPos.y);

	SetViewMatrix();
}

void CameraManager::SetTransform()
{
	g_device->SetTransform(D3DTS_PROJECTION, &matProj);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

void CameraManager::SetViewMatrix()
{
	matView = {
	vEyeScale.x, 0.f, 0.f, 0.f,
	0.f, vEyeScale.y, 0.f, 0.f,
	0.f, 0.f, 1.f, 0.f,
	-vEyePos.x, -vEyePos.y, 0.f, 1.f
	};
}

void CameraManager::SetTarget(const Vector2 & targetPos, float s)
{
	bTargeting = true;
	vTargetPos = targetPos;

	fS = s;
}

void CameraManager::SetLock(const Vector2 & minLock, const Vector2 & maxLock)
{
	vMinLock = minLock;
	vMaxLock = maxLock;

}

void CameraManager::StartShake(float power, float s)
{
	fShakePower = power;
	fShakeDamage = fShakePower / s;
	fMulti = 1;
}
