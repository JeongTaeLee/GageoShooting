#include "DXUT.h"
#include "Stage02.h"

#include "Map.h"
#include "Player.h"
#include "MiniMap.h"
#include "MissionImage.h"
#include "MiniMaps.h"
#include "HpCenterZone.h"
#include "GunCenterZone.h"

#include "Monster01.h"
#include "Monster02.h"

#include "Boss.h"

Stage02::Stage02()
{
}


Stage02::~Stage02()
{
}

void Stage02::Init()
{
	SOUND.Play("InGameBGM", 1);
	SOUND.SetVol("InGameBGM", 85);

	Map * map = AddObj(Map);
	map->SetMapTexture(LOADTEX("StageB_BackGround", " "));
	map->SetMiniMap(LOADTEX("StageB_CollisionMap", " "));

	map->AddMapObject(Vector2(503, 2460), LOADTEX("StageB_OBJECT01", " "));
	map->AddMapObject(Vector2(1591, 1280), LOADTEX("StageB_HpCenter", " "));
	map->AddMapObject(Vector2(2224, 2244), LOADTEX("StageB_GunCenter", " "));

	MiniMaps * miniMap = AddObj(MiniMaps);
	miniMap->SetMiniMap(LOADTEX("StageB_MiniMap", " "));

	Player * player = AddObj(Player);
	map->SetPlayer(player);
	player->SetMiniMap(LOADTEX("StageB_CollisionMap", " "));

	MissionImage * mission = AddObj(MissionImage);
	mission->SetTex(LOADTEX("MissionText01", " "));

	AddObj(HpCenterZone)->transform->pos = Vector2(1492, 1688);
	AddObj(GunCenterZone)->transform->pos = Vector2(2120, 2644);

	/*
	texture * tex = LOADTEX("StageB_CollisionMap", "");
	Boss * boss = AddObj(Boss);
	boss->SetMiniMap(tex);
	boss->SetMap(map);
	*/

	MonsterLoading(map);
}

void Stage02::Release()
{
	SOUND.Stop("InGameBGM");
	CAMERA.Reset();
	IMAGE.DeleteImages();
	OBJECT.Reset();
}

void Stage02::Update()
{
	CAMERA.Update();
	OBJECT.Update();
}

void Stage02::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void Stage02::MonsterLoading(Map * map)
{
	texture * tex = LOADTEX("StageB_CollisionMap", "");

	D3DLOCKED_RECT LockRect;
	tex->lpD3DTex->LockRect(0, &LockRect, nullptr, D3DLOCK_DISCARD);

	int iWidth = tex->info.Width;
	int iHeight = tex->info.Height;

	DWORD * dwBit = (DWORD*)LockRect.pBits;

	for (int i = 0; i < iWidth * iHeight; ++i)
	{
		D3DXCOLOR color = dwBit[i];

		Vector2 pos;
		pos.x = (i % iWidth) * 10.f;
		pos.y = (i / iWidth) * 10.f;

		if (color == D3DXCOLOR(1.f, 0.f, 0.f, 1.f))
		{
			Monster01 * monster = AddObj(Monster01);

			monster->SetMiniMap(tex);
			monster->transform->pos = pos;
			monster->SetMap(map);

			map->AddMonsterCount();
		}

		if (color == D3DXCOLOR(0.f, 0.f, 0.f, 1.f))
		{
			Monster02 * monster = AddObj(Monster02);

			monster->SetMiniMap(tex);
			monster->transform->pos = pos;
			monster->SetMap(map);

			map->AddMonsterCount();

		}
	}

	tex->lpD3DTex->UnlockRect(0);
}

void Stage02::ResourceLoading()
{
	//Map
	LOADTEX("StageB_BackGround", "./rs/StageB/StageB_1.png");
	LOADTEX("StageB_CollisionMap", "./rs/StageB/StageB_.png");
	LOADTEX("StageB_MiniMap", "./rs/stageB/StageB_MiniMap.png");

	LOADTEX("StageB_OBJECT01", "./rs/StageB/StageB_4.png");
	LOADTEX("StageB_HpCenter", "./rs/StageB/StageB_2.png");
	LOADTEX("StageB_GunCenter", "./rs/StageB/StageB_3.png");

	NONEDESTROYTEXS("Boss%d", "./rs/Boss/Boss_Idle/(%d).png", 1, 120);
	NONEDESTROYTEXS("Boss_Die%d", "./rs/Boss/Boss_Jump/(%d).png", 1, 10);

	bLoadingComplete = true;
}
