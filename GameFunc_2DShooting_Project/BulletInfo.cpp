#include "DXUT.h"
#include "BulletInfo.h"


BulletInfo::BulletInfo()
	:lpUiRenderer(nullptr), lpMaxBullet(nullptr), lpNowBullet(nullptr)
{
}

BulletInfo::~BulletInfo()
{
}

void BulletInfo::Init()
{
	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("BulletInfo", " "));

	GameObject * object = OBJECT.AddObject<GameObject>(nullptr, this);
	object->transform->pos = Vector2(40, 10);
	lpMaxBullet = object->AC(UIText);

	object = OBJECT.AddObject<GameObject>(nullptr, this);
	object->transform->pos = Vector2(-40, 10);
	lpNowBullet = object->AC(UIText);
	
	lpMaxBullet->SetSize(50);
	lpNowBullet->SetSize(50);
	lpNowBullet->SetColor(D3DXCOLOR(0xff80dbef));
}

void BulletInfo::SetBulletInfo(int _iMaxBullet, int _iNowBullet)
{
	char str[128];
	
	sprintf(str, "%02d", _iMaxBullet);
	lpMaxBullet->SetStr(str);

	sprintf(str, "%02d", _iNowBullet);
	lpNowBullet->SetStr(str);

}

void BulletInfo::SetNowBulletInfo(int _iNowBullet)
{
	char str[128];

	sprintf(str, "%02d", _iNowBullet);
	lpNowBullet->SetStr(str);
}
