#include "DXUT.h"
#include "MiniMap.h"
#include "MiniMaps.h"

MiniMap::MiniMap()
	:renderer(nullptr)
{
}


MiniMap::~MiniMap()
{
}

void MiniMap::SetMiniMap(texture * lpTex)
{
	renderer = AC(UIRenderer);
	renderer->SetTex(lpTex, true);
	renderer->SetRenderingSort(0);
}
