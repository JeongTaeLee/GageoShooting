#include "DXUT.h"
#include "Map.h"
#include "MapObject.h"
#include "Portal.h"
#include "Player.h"
#include "Boss.h"


Map::Map()
	:lpRenderer(nullptr), lpPlayer(nullptr), lpMiniMapTex(nullptr), iMonsterCount(0)
{
	tag = "Map";
}


Map::~Map()
{
}

void Map::Init()
{
}

void Map::Release()
{

}

void Map::Update()
{
	Vector2 pos = Vector2(lpPlayer->transform->pos.x / 10, lpPlayer->transform->pos.y / 10);

	UINT iWidth = lpMiniMapTex->info.Width;
	UINT iHeight = lpMiniMapTex->info.Height;

	bool s = false;;

	if ((0 < pos.x && pos.x < iWidth) &&
		(0 < pos.y && pos.y < iHeight))
	{
		D3DLOCKED_RECT locked;
		lpMiniMapTex->lpD3DTex->LockRect(0, &locked, nullptr, D3DLOCK_DISCARD);

		DWORD * pColor = (DWORD*)locked.pBits;

		unsigned int posX = (unsigned int)pos.x;
		unsigned int posY = (unsigned int)pos.y;

		D3DXCOLOR color(pColor[posY * iWidth + posX]);

		lpMiniMapTex->lpD3DTex->UnlockRect(0);

		if (color == D3DXCOLOR(0, 1.f, 1.f, 1.f))
			s = true;
	}

	if (s)
	{
		for (auto Iter : veMapObject)
			Iter->SetOpaque(true);
	}
	else
	{
		for (auto Iter : veMapObject)
			Iter->SetOpaque(false);

	}
}

void Map::AddMapObject(const Vector2 & pos, texture * lpTex)
{
	MapObject * object = AddObj(MapObject);
	veMapObject.push_back(object);

	object->transform->pos = pos;
	object->SetTex(lpTex);

	
}

void Map::SetMapTexture(texture * maptex)
{
	lpRenderer = AC(Renderer);
	lpRenderer->SetRenderingSort(-1);
	lpRenderer->SetTex(maptex, false);
}

void Map::AddMonsterCount()
{
	++iMonsterCount;
}

void Map::MinusMonsterCount()
{
	--iMonsterCount;

	if (iMonsterCount == 0)
	{
		if(SCENE.GetSceneStr() == "Ingame01")
			AddObj(Portal)->transform->pos = Vector2(80, 444);

		if (SCENE.GetSceneStr() == "Ingame02")
		{
			texture * tex = LOADTEX("StageB_CollisionMap", "");
			Boss * boss = AddObj(Boss);
			boss->SetMiniMap(tex);
			boss->SetMap(this);
		}
	}
}
