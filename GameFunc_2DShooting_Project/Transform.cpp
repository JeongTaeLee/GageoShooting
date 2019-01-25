#include "DXUT.h"
#include "Transform.h"


Transform::Transform()
	:pos(0.f, 0.f), scale(1.f, 1.f), rot(0.f)
{
	D3DXMatrixIdentity(&matWorld);
}


Transform::~Transform()
{
}

void Transform::UpdateTransform()
{
	D3DXMATRIX matPos;
	D3DXMatrixTranslation(&matPos, pos.x, pos.y, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scale.x, scale.y, 0.f);

	D3DXMATRIX matRot;
	D3DXMatrixRotationZ(&matRot, rot);

	matWorld = matScale * matRot * matPos;

	if (gameObject->lpParentObject)
		matWorld = gameObject->lpParentObject->transform->matWorld * matWorld;

	worldPos = Vector2(matWorld._41, matWorld._42);
}

void Transform::SetTransform(LPD3DXSPRITE sprite)
{
	sprite->SetTransform(&matWorld);
}
