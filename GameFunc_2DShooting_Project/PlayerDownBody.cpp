#include "DXUT.h"
#include "PlayerDownBody.h"


PlayerDownBody::PlayerDownBody()
	:eDir(PD_U), renderer(nullptr), animater(nullptr), pixelCollider(nullptr)
{
	tag = "PlayerDownBody";
}


PlayerDownBody::~PlayerDownBody()
{
}

void PlayerDownBody::Init()
{
	renderer = AC(Renderer);
	animater = AC(Animater);

	animater->Add("WD" ,"PD_W%d" ,"", 1, 15);
	animater->Add("WDL","PD_W%d","", 16, 30);
	animater->Add("WL" ,"PD_W%d" ,"", 31, 45);
	animater->Add("WUL","PD_W%d","", 46, 60);
	animater->Add("WU" ,"PD_W%d" ,"", 61, 75);
	animater->Add("WUR","PD_W%d","", 76, 90);
	animater->Add("WR" ,"PD_W%d" ,"", 91, 105);
	animater->Add("WDR","PD_W%d","", 106, 120);

	animater->Play("WUL");
	animater->SetDelay(0.03f);

	//renderer->SetMiddleCenter(Vector3(0.f, 15.f, 0.f));
	renderer->SetMiddleCenter();
}

void PlayerDownBody::Update()
{
	Input();
}

void PlayerDownBody::Input()
{
	Vector2 vDir = Vector2(0.f, 0.f);
	bool bBehavior = false;

	if (KEYPRESS('A'))
	{
		vDir = Vector2(-1.f, 0.f);
		eDir = PD_L;

		bBehavior = true;
	}
	if (KEYPRESS('D'))
	{
		vDir = Vector2(1.f, 0.f);
		eDir = PD_R;
	
		bBehavior = true;
	}
	if (KEYPRESS('W'))
	{
		vDir = Vector2(0.f, -1.f);
		if (eDir == PD_L)
		{
			vDir = Vector2(-1.f, -1.f);
			eDir = PD_UL;
		}
		else if (eDir == PD_R)
		{
			vDir = Vector2(1.f, -1.f);
			eDir = PD_UR;
		}
		else
			eDir = PD_U;
	
		bBehavior = true;
	}
	if (KEYPRESS('S'))
	{
		vDir = Vector2(0.f, 1.f);
		if (eDir == PD_L)
		{
			vDir = Vector2(-1.f, 1.f);
			eDir = PD_DL;
		}
		else if (eDir == PD_R)
		{
			vDir = Vector2(1.f, 1.f);
			eDir = PD_DR;
		}
		else
			eDir = PD_D;
	
		bBehavior = true;
	}
	string str;
	switch (eDir)
	{
	case PD_D:
		str = "WD";
		break;
	case PD_DR:
		str = "WDR";
		break;
	case PD_R:
		str = "WR";
		break;
	case PD_UR:
		str = "WUR";
		break;
	case PD_U:
		str = "WU";
		break;
	case PD_UL:
		str = "WUL";
		break;
	case PD_L:
		str = "WL";
		break;
	case PD_DL:
		str = "WDL";
		break;
	}

	if (animater->GetString() != str)
		animater->Play(str);

	if (!pixelCollider->GetCollision())
	{
		lpParentObject->transform->pos += vDir * (200 *Et);
		pixelCollider->PixelCollision(Vector2(lpParentObject->transform->pos.x / PIXELCOLLISION, lpParentObject->transform->pos.y / PIXELCOLLISION), vDir, 200);
	}

	if (!bBehavior)
		animater->Stop(0);
	else
		animater->UnStop();
}

void PlayerDownBody::SetMiniMap(texture * tex)
{
	pixelCollider = AC(PixelCollider);
	pixelCollider->SetCollisionTex(tex, WallColliderColor);
}
