#include "DXUT.h"
#include "MiniMaps.h"
#include "MiniMap.h"

MiniMaps::MiniMaps()
{
}


MiniMaps::~MiniMaps()
{
}

void MiniMaps::Init()
{
	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("MiniMapGuide", ""), true);
	lpUiRenderer->SetRenderingSort(0);

	Vector2 pos;
	pos.x = MINIMAPX;
	pos.y = MINIMAPY;
	transform->pos = pos;
}

void MiniMaps::SetMiniMap(texture * lpTex)
{
	MiniMap * lpMiniMap = OBJECT.AddObject<MiniMap>(nullptr, this);
	lpMiniMap->SetMiniMap(lpTex);
}
