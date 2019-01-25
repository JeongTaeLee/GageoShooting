#include "DXUT.h"
#include "Stage01.h"

#include "Player.h"

#include "HpCenterZone.h"
#include "GunCenterZone.h"

#include "Map.h"
#include "MiniMaps.h"

#include "MissionImage.h"

#include "Monster01.h"
#include "Monster02.h"

Stage01::Stage01()
	: fAccrue(0.f), fDelay(3.f)
{
}


Stage01::~Stage01()
{
}

void Stage01::Init()
{


	SOUND.Play("InGameBGM", 1);
	SOUND.SetVol("InGameBGM", 85);

	Sleep(100);

#pragma region MAP
	Map * map = AddObj(Map);
	map->SetMapTexture(LOADTEX("StageA_BackGround", ""));
	map->SetMiniMap(LOADTEX("StageA_CollisionMap", ""));
	
	map->AddMapObject(Vector2(2160, 808), LOADTEX("StageA_GunCenter", ""));
	map->AddMapObject(Vector2(856, 808), LOADTEX("StageA_HpCenter", ""));
	map->AddMapObject(Vector2(1488, 156), LOADTEX("StageA_OBJECT01", ""));
	map->AddMapObject(Vector2(56, 1796), LOADTEX("StageA_OBJECT02", ""));
	map->AddMapObject(Vector2(1220, 1540), LOADTEX("StageA_OBJECT03", ""));
	map->AddMapObject(Vector2(2472, 1556), LOADTEX("StageA_OBJECT04", ""));
	map->AddMapObject(Vector2(1944, 2260), LOADTEX("StageA_OBJECT05", ""));
	map->AddMapObject(Vector2(808, 2208), LOADTEX("StageA_OBJECT06", ""));
	map->AddMapObject(Vector2(1504, 2884), LOADTEX("StageA_OBJECT07", ""));
	map->AddMapObject(Vector2(1508, 812), LOADTEX("StageA_OBJECT08", ""));

	MiniMaps * miniMap = AddObj(MiniMaps);
	miniMap->SetMiniMap(LOADTEX("StageA_MiniMap", " "));

	MonsterLoading(map);

	AddObj(HpCenterZone)->transform->pos = Vector2(868, 1079);
	AddObj(GunCenterZone)->transform->pos = Vector2(2167, 1079);
#pragma endregion MAP

	Player * player = AddObj(Player);	
	player->SetMiniMap(LOADTEX("StageA_CollisionMap", ""));
	map->SetPlayer(player);
	
	MissionImage * mission = AddObj(MissionImage);
	mission->SetTex(LOADTEX("MissionText01", " "));
}

void Stage01::Release()
{
	SOUND.Stop("InGameBGM");
	CAMERA.Reset();
	OBJECT.Reset();
	IMAGE.DeleteImages();
}

void Stage01::Update()
{
	if (KEYDOWN(VK_F2))
	{
		SCENE.ChanScene("Ingame02");
	}

	CAMERA.Update();
	OBJECT.Update();
}

void Stage01::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void Stage01::MonsterLoading(Map * map)
{
	texture * tex = LOADTEX("StageA_CollisionMap", "");

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

void Stage01::ResourceLoading()
{
	//Player
	NONEDESTROYTEXS("PU01%d", "./rs/Player/UpBody/(%d).png", 1, 8);

	NONEDESTROYTEXS("PU02%d", "./rs/Player/UpBody/(%d).png", 9, 16);

	NONEDESTROYTEXS("PU03%d", "./rs/Player/UpBody/(%d).png", 17, 24);

	NONEDESTROYTEXS("PD_W%d", "./rs/Player/DownBody/(%d).png", 1, 120);

	NONEDESTROYTEX("BulletInfo", "./rs/BulletInfo.png");
	NONEDESTROYTEX("PlayerBullet01", "./rs/player/PlayerBullet01.png");
	NONEDESTROYTEXS("Monster01Bullet%d", "./rs/Monster01/Monster01Bullet/(%d).png", 1, 8);
	NONEDESTROYTEXS("Monster02Bullet%d", "./rs/Monster02/Monster02Bullet/(%d).png", 1, 8);
	//Map
	LOADTEX("StageA_BackGround", "./rs/stage01/StageA_Background.png");
	LOADTEX("StageA_CollisionMap", "./rs/stage01/StageA_CollisionMap.png");
	LOADTEX("StageA_MiniMap", "./rs/stage01/StageA_MiniMap.png");

	LOADTEX("StageA_OBJECT01", "./rs/stage01/StageA_OBJECT01.png");
	LOADTEX("StageA_OBJECT02", "./rs/stage01/StageA_OBJECT02.png");
	LOADTEX("StageA_OBJECT03", "./rs/stage01/StageA_OBJECT03.png");
	LOADTEX("StageA_OBJECT04", "./rs/stage01/StageA_OBJECT04.png");
	LOADTEX("StageA_OBJECT05", "./rs/stage01/StageA_OBJECT05.png");
	LOADTEX("StageA_OBJECT06", "./rs/stage01/StageA_OBJECT06.png");
	LOADTEX("StageA_OBJECT07", "./rs/stage01/StageA_OBJECT07.png");
	LOADTEX("StageA_OBJECT08", "./rs/stage01/StageA_OBJECT08.png");
	LOADTEX("StageA_HpCenter", "./rs/stage01/StageA_HpCenter.png");
	LOADTEX("StageA_GunCenter", "./rs/stage01/StageA_GunCenter.png");

	NONEDESTROYTEXS("MonsterA_Idle%d", "./rs/Monster01/MonsterA/(%d).png", 1, 80);
	NONEDESTROYTEXS("MonsterA_Die%d", "./rs/Monster01/MonsterA_DIE/(%d).png", 1, 80);

	NONEDESTROYTEXS("MonsterB_Idle%d", "./rs/Monster02/MonsterB/(%d).png", 1, 120);
	NONEDESTROYTEXS("MonsterB_Die%d", "./rs/Monster02/MonsterB_DIE/(%d).png", 1, 80);
	
	//UI
	NONEDESTROYTEX("MissionText01", "./rs/MissionText01.png");
	NONEDESTROYTEX("MissionText02", "./rs/MissionText02.png");

	NONEDESTROYTEX("MiniMap_Player", "./rs/MiniMap/MiniMapUnit_Player.png");
	NONEDESTROYTEX("MiniMap_Monster", "./rs/MiniMap/MiniMapUnit_Monster.png");
	NONEDESTROYTEX("MiniMap_Portal", "./rs/MiniMap/MiniMapUnit_Portal.png");
	NONEDESTROYTEX("MiniMapGuide", "./rs/MiniMap/MiniMapGuide.png");
	NONEDESTROYTEX("Portal", "./rs/Portal.png");


	NONEDESTROYTEX("GunCenterZone", "./rs/GunCenter/GunCenter.png");
	NONEDESTROYTEX("GunCenterPopUp", "./rs/GunCenter/GunCenterPopUp.png");
	NONEDESTROYTEX("GunCenterCheck", "./rs/GunCenter/GunCenterCheck.png");

	NONEDESTROYTEX("Button01", "./rs/GunCenter/Button01.png");
	NONEDESTROYTEX("Button02", "./rs/GunCenter/Button02.png");
	NONEDESTROYTEX("Button03", "./rs/GunCenter/Button03.png");

	NONEDESTROYTEX("HpCenterZone", "./rs/HpCenter/HpCenter.png");
	NONEDESTROYTEX("HpCenterPopup", "./rs/HpCenter/HpCenterPopUp.png");
	NONEDESTROYTEX("HpCenterCheck", "./rs/HpCenter/HpCenterCheck.png");
	
	NONEDESTROYTEX("OkButton", "./rs/OkButton.png");
	NONEDESTROYTEX("XButton", "./rs/XButton.png");

	NONEDESTROYTEX("PlayerHpInBar", "./rs/Bar/PlayerHpInBar.png");
	NONEDESTROYTEX("PlayerHpOutBar", "./rs/Bar/PlayerHpOutBar.png");

	NONEDESTROYTEX("MonsterHpInBar", "./rs/Bar/MonsterHpInBar.png");
	NONEDESTROYTEX("MonsterHpOutBar", "./rs/Bar/MonsterHpOutBar.png");

	NONEDESTROYTEXS("MonsterHitEffect%d", "./rs/MonsterHitEffect/(%d).png", 1, 6);
	NONEDESTROYTEXS("PlayerHitEffect%d", "./rs/PlayerHitEffect/(%d).png", 1, 7);

	NONEDESTROYTEX("GoldUI", "./rs/GoldUI.png");
	NONEDESTROYTEX("ScoreUI", "./rs/ScoreUI.png");
	NONEDESTROYTEX("BossAttackZone", "./rs/BossAttackZone.png");

	bLoadingComplete = true;
}
