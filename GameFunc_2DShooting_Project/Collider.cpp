#include "DXUT.h"
#include "Collider.h"


Collider::Collider()
{
}


Collider::~Collider()
{
}

void Collider::Init()
{
	OBJECT.AddCollider(this);
}

void Collider::Release()
{
	OBJECT.DeleteCollider(this);
}

void Collider::Update()
{
	SetRgn();
}

void Collider::SetCollider(const Vector2 & _vSize, bool center)
{
	vSize = _vSize;
	bCenter = center;

	SetRgn();
}

void Collider::SetRgn()
{
	if (bCenter)
	{
		int minX = transform->worldPos.x - vSize.x / 2;
		int minY = transform->worldPos.y - vSize.y / 2;

		int maxX = transform->worldPos.x + vSize.x / 2;
		int maxY = transform->worldPos.y + vSize.y / 2;

		SetRect(&reRgn, minX, minY, maxX, maxY);
	}
	else
	{
		int minX = transform->worldPos.x;
		int minY = transform->worldPos.y;

		int maxX = transform->worldPos.x + vSize.x;
		int maxY = transform->worldPos.y + vSize.y;

		SetRect(&reRgn, minX, minY, maxX, maxY);
	}
}
