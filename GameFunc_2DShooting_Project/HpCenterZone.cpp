#include "DXUT.h"
#include "HpCenterZone.h"
#include "HpCenterPop.h"
#include "MissionImage.h"

HpCenterZone::HpCenterZone()
{
}


HpCenterZone::~HpCenterZone()
{
}

void HpCenterZone::Init()
{
	lpRenderer = AC(Renderer);
	lpRenderer->SetTex(LOADTEX("HpCenterZone", " "));
	lpRenderer->SetRenderingSort(-1);

	lpCollider = AC(Collider);
	lpCollider->SetCollider(Vector2(400, 120), true);
}

void HpCenterZone::Update()
{
}

void HpCenterZone::OnCollision(Collider * collider)
{	
	if (collider->gameObject->tag == "Player")
	{
		if (KEYUP('F'))
		{
			if (!OBJECT.FindObject<HpCenterPop>("HpCenterPopUp"))
				AddObj(HpCenterPop);
		}
		else
		{
			if (!OBJECT.FindObject<MissionImage>("HpCenterCheck") && !OBJECT.FindObject<HpCenterPop>("HpCenterPopUp"))
			{
				MissionImage * mission = AddObj(MissionImage);
				mission->tag = "HpCenterCheck";
				mission->SetTex(LOADTEX("HpCenterCheck", " "));
			}
		}
	}
}
