#include "DXUT.h"
#include "PixelCollider.h"


PixelCollider::PixelCollider()
	:lpCollisionTex(nullptr), d3dCollColor(0.f, 0.f, 0.f, 0.f), vBackDir(0.f, 0.f), bInCollision(false), fSpeed(0.f),
	iWidth(0), iHeight(0)
{
}


PixelCollider::~PixelCollider()
{
}


void PixelCollider::Update()
{
	Push();
}

void PixelCollider::Push()
{
	if (!bInCollision)
		return;

	if (gameObject->lpParentObject)
		gameObject->lpParentObject->transform->pos += (-vBackDir) * (fSpeed * Et);
	else
		gameObject->transform->pos += (-vBackDir) * (fSpeed * Et);

	bInCollision = false;
	bInCollision = PixelCollision(gameObject->transform->pos, vBackDir, fSpeed);

	if (!bInCollision)
	{
		vBackDir = Vector2(0.f, 0.f);
		fSpeed = 0.f;
	}
}

bool PixelCollider::PixelCollision(const Vector2 & pos, const Vector2 & dir, float speed)
{

	if (bInCollision)
		return true;

	if ((0 < pos.x && pos.x < iWidth) &&
		(0 < pos.y && pos.y < iHeight))
	{
		D3DLOCKED_RECT locked;
		lpCollisionTex->lpD3DTex->LockRect(0, &locked, nullptr, D3DLOCK_DISCARD);

		DWORD * pColor = (DWORD*)locked.pBits;

		unsigned int posX = (unsigned int)pos.x;
		unsigned int posY = (unsigned int)pos.y;

		D3DXCOLOR color(pColor[posY * iWidth + posX]);

		lpCollisionTex->lpD3DTex->UnlockRect(0);
		
		if (color == d3dCollColor)
		{
			gameObject->SendMsg("PixelCollision");

			fSpeed = speed;
			vBackDir = dir;
			return (bInCollision = true);
		}
	}

	return (bInCollision = false);
}

void PixelCollider::SetCollisionTex(texture * lpTex, const D3DXCOLOR & collColor)
{
	lpCollisionTex = lpTex;

	iWidth = lpCollisionTex->info.Width;
	iHeight = lpCollisionTex->info.Height;

	d3dCollColor = collColor;
}
