#pragma once
#include "GameObject.h"
class BulletInfo :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;

	UIText * lpMaxBullet;
	UIText * lpNowBullet;
public:
	BulletInfo();
	virtual ~BulletInfo();

	virtual void Init()	override;

	void SetBulletInfo(int _iMaxBullet, int _iNowBullet);
	void SetNowBulletInfo(int _iNowBullet);
};

