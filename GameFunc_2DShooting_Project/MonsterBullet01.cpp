#include "DXUT.h"
#include "MonsterBullet01.h"


MonsterBullet01::MonsterBullet01()
{
}


MonsterBullet01::~MonsterBullet01()
{
}

void MonsterBullet01::Init()
{
	MonserBullet::Init();

	lpAnimater->Add("Bullet", "Monster01Bullet%d", " ", 1, 8);
	lpAnimater->SetDelay(0.05f);
	lpRenderer->SetMiddleCenter();
}
