#include "DXUT.h"
#include "Portal.h"
#include "MissionImage.h"

Portal::Portal()
{
}


Portal::~Portal()
{
}

void Portal::Init()
{
	renderer = AC(Renderer);
	renderer->SetTex(LOADTEX("Portal", " "), true);
	
	collider = AC(Collider);
	collider->SetCollider(Vector2(100, 100), true);

	AC(MiniMapUnit)->SetTex(LOADTEX("MiniMap_Portal", " "));

	MissionImage * mission = AddObj(MissionImage);
	mission->SetTex(LOADTEX("MissionText02", " "));
}

void Portal::OnCollision(Collider * collider)
{
	if (collider->gameObject->tag == "Player")
	{
		SCENE.ChanScene("Ingame02");
	}
}
