#include "DXUT.h"
#include "Player.h"

#include "PlayerUpBody.h"
#include "PlayerDownBody.h"

#include "HpBar.h"
#include "GoldUI.h"
#include "ScoreUI.h"

#include "MonserBullet.h"
#include "GameOver.h"

Player::Player()
	:lpUpBody(nullptr), lpDownBody(nullptr), lpCollider(nullptr), fHp(0.f), iSkillPoint(10),
	bHit(false), fHitEffectAccrue(0.f), fHitEffectDelay(0.f), lpHpBar(nullptr),
	lpGoldUi(nullptr), iGold(0), lpScoreUi(nullptr), iScore(0)
{
	tag = "Player";
}


Player::~Player()
{
}

void Player::Init()
{
	fHp = 100.f;

	transform->pos = Vector2(0, 0);

	lpDownBody = OBJECT.AddObject<PlayerDownBody>(nullptr, this);
	lpUpBody = OBJECT.AddObject<PlayerUpBody>(nullptr, this);

	lpCollider = AC(Collider);
	lpCollider->SetCollider(Vector2(50, 50), true);

	AC(MiniMapUnit)->SetTex(LOADTEX("MiniMap_Player", " "));

	lpHpBar = AddObj(HpBar);
	lpHpBar->SetHpBar(Vector2(WINSIZEX / 2, WINSIZEY / 2 + 300), LOADTEX("PlayerHpInBar", " "), LOADTEX("PlayerHpOutBar", " "), fHp, fHp);

	iGold = 1000;
	lpGoldUi = AddObj(GoldUI);
	lpGoldUi->SetGold(iGold);
	lpGoldUi->transform->pos = Vector2(50, 50);

	iScore = 0;
	lpScoreUi = AddObj(ScoreUI);
	lpScoreUi->SetScore(iScore);
	lpScoreUi->transform->pos = Vector2(300, 50);
}

void Player::Update()
{
	if (bHit)
	{
		fHitEffectAccrue += Et;

		if (fHitEffectDelay <= fHitEffectAccrue)
		{
			lpUpBody->GC(Renderer)->SetColor(D3DCOLOR_XRGB(255, 255, 255));
			lpDownBody->GC(Renderer)->SetColor(D3DCOLOR_XRGB(255, 255, 255));

			bHit = false;
		}
	}

	CAMERA.SetTarget(transform->pos, 0.1f);
}

void Player::SetMiniMap(texture * lpTex)
{
	lpDownBody->SetMiniMap(lpTex);
	lpUpBody->SetMiniMap(lpTex);

	for (int i = 0; i < lpTex->info.Width * lpTex->info.Height; ++i)
	{
		D3DLOCKED_RECT locked;
		lpTex->lpD3DTex->LockRect(0, &locked, nullptr, D3DLOCK_DISCARD);

		DWORD * pColor = (DWORD*)locked.pBits;

		D3DXCOLOR color(pColor[i]);

		if (color == D3DXCOLOR(0.f, 0.f, 1.f, 1.f))
		{
			Vector2 pos;
			pos.x = (i % (lpTex->info.Width)) * 10.f;
			pos.y = (i / (lpTex->info.Width)) * 10.f;

			transform->pos = pos;
			transform->UpdateTransform();
			lpTex->lpD3DTex->UnlockRect(0);
			break;
		}

		lpTex->lpD3DTex->UnlockRect(0);
	}
	
}

void Player::OnCollision(Collider * collider)
{
	if (collider->gameObject->tag == "MonsterBullet")
	{
		MonserBullet * bullet = dynamic_cast<MonserBullet*>(collider->gameObject);

		fHp -= bullet->GetDamage();

		if (fHp <= 0.f)
		{
			SCENE.ChanScene("GameFailed");
		}
		else
		{
			lpHpBar->UpdateHpBar(fHp);

			fHitEffectAccrue = 0.f;
			fHitEffectDelay = 0.05f;

			lpUpBody->GC(Renderer)->SetColor(D3DCOLOR_XRGB(255, 0, 0));
			lpDownBody->GC(Renderer)->SetColor(D3DCOLOR_XRGB(255, 0, 0));

			bHit = true;
		}
	}
}

void Player::ChangeGun(PlayerUpBody * body)
{
	body->SetMiniMap(lpUpBody->GetMiniMap());

	lpUpBody->SetDestroy();
	lpUpBody = nullptr;
	lpUpBody = body;
}

void Player::UsingGold(int _iGold)
{
	iGold -= _iGold;
	lpGoldUi->SetGold(iGold);
}

void Player::AddGold(int _iGold)
{
	iGold += _iGold;
	lpGoldUi->SetGold(iGold);
}

void Player::AddScore(int _iScore)
{
	iScore += _iScore;
	lpScoreUi->SetScore(iScore);
}

void Player::ReHp()
{
	fHp = 100;
	lpHpBar->UpdateHpBar(fHp);
}
