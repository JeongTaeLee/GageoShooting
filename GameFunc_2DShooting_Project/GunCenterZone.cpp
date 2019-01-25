#include "DXUT.h"
#include "GunCenterZone.h"
#include "GunCenterPop.h"

#include "MissionImage.h"

GunCenterZone::GunCenterZone()
{
}


GunCenterZone::~GunCenterZone()
{
}

void GunCenterZone::Init()
{
	lpRenderer = AC(Renderer);
	lpRenderer->SetTex(LOADTEX("GunCenterZone", " "));
	lpRenderer->SetRenderingSort(-1);

	lpCollider = AC(Collider);
	lpCollider->SetCollider(Vector2(400, 120), true);
}

void GunCenterZone::OnCollision(Collider * collider)
{
	if (collider->gameObject->tag == "Player")
	{
		if (KEYUP('F'))
		{
			if (!OBJECT.FindObject<GunCenterPop>("GunCenterPopUp"))
				AddObj(GunCenterPop);
		}
		else
		{
			if (!OBJECT.FindObject<MissionImage>("GunCenterCheck") && !OBJECT.FindObject<GunCenterPop>("GunCenterPopUp"))
			{
				MissionImage * mission = AddObj(MissionImage);
				mission->tag = "GunCenterCheck";
				mission->SetTex(LOADTEX("GunCenterCheck", " "));
			}
		}
	}
	
}
