#include "DXUT.h"
#include "MapObject.h"


MapObject::MapObject()
	:lpRenderer(nullptr)
{
}


MapObject::~MapObject()
{
}

void MapObject::SetOpaque(bool _bOpaque)
{
	if (!lpRenderer)
		return;

	if (_bOpaque)
		lpRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 0.5f));
	else
		lpRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 1.f));
}
  
void MapObject::SetTex(texture * lpTex)
{
	lpRenderer = AC(Renderer);
	lpRenderer->SetTex(lpTex, false);
	lpRenderer->SetMiddleCenter();
}
