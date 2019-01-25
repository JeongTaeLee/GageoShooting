#include "DXUT.h"
#include "MonsterBullet02.h"


MonsterBullet02::MonsterBullet02()
{
}


MonsterBullet02::~MonsterBullet02()
{
}

void MonsterBullet02::Init()
{
	MonserBullet::Init();

	lpAnimater->Add("Bullet", "Monster02Bullet%d", " ", 1, 8);
	lpAnimater->SetDelay(0.05f);
	lpRenderer->SetMiddleCenter();
}
