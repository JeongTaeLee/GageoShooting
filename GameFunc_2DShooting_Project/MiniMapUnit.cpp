#include "DXUT.h"
#include "MiniMapUnit.h"


MiniMapUnit::MiniMapUnit()
{
}


MiniMapUnit::~MiniMapUnit()
{
}

void MiniMapUnit::Render(LPD3DXSPRITE sprite)
{
	Vector2 pos(transform->worldPos.x / MINIMAP_S, transform->worldPos.y / MINIMAP_S);
	pos.x += MINIMAPUNITX;
	pos.y += MINIMAPUNITY;
			
	Matrix mat;
	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0.f);
	sprite->SetTransform(&mat);

	sprite->Draw(lpTex->lpD3DTex, nullptr, &Vector3(lpTex->info.Width / 2.f, lpTex->info.Height / 2.f, 0.f),
		nullptr, D3DCOLOR_XRGB(255, 255, 255));
}
