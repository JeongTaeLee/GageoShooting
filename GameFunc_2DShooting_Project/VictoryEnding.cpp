#include "DXUT.h"
#include "VictoryEnding.h"
#include "GameVictory.h"
#include "GameVictroyScreen.h"

VictoryEnding::VictoryEnding()
{
}


VictoryEnding::~VictoryEnding()
{
}

void VictoryEnding::Init()
{
	transform->pos = Vector2((float)WINSIZEX / 2.f, (float)WINSIZEX / 2.f);

	lpRenderer = AC(Renderer);
	lpAnimater = AC(Animater);

	lpAnimater->Add("Ending", "Ending%d", " ", 1, 50);
	lpAnimater->Play("Ending");
	lpAnimater->SetDelay(0.1f);

	lpRenderer->SetMiddleCenter();
}

void VictoryEnding::Update()
{
}

void VictoryEnding::Receive(const string & msg)
{
	if (msg == "EndAnimation")
	{
		AddObj(GameVictroyScreen);

		lpAnimater->bEnable = false;
	}
}
