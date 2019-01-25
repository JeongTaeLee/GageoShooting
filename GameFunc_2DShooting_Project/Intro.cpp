#include "DXUT.h"
#include "Intro.h"


Intro::Intro()
{
}


Intro::~Intro()
{
}

void Intro::Init()
{
	transform->pos = Vector2((float)WINSIZEX / 2.f, (float)WINSIZEX / 2.f);

	lpRenderer = AC(Renderer);
	lpAnimater = AC(Animater);

	lpAnimater->Add("Intro", "Intro%d", "./rs/Intro/(%d).png", 1, 51);
	lpAnimater->Play("Intro");
	lpAnimater->SetDelay(0.1f);
	lpRenderer->SetMiddleCenter();
}

void Intro::Receive(const string & msg)
{
	if (msg == "EndAnimation")
	{
		SCENE.ChanScene("MainManu");
		bActive = false;
	}
}
