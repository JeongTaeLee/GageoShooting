#include "DXUT.h"
#include "PopUpScreen.h"
#include "Button.h"

PopUpScreen::PopUpScreen()
	:lpUiRenderer(nullptr)
{
}


PopUpScreen::~PopUpScreen()
{
}

void PopUpScreen::Init()
{
	XButton = OBJECT.AddObject<GameObject>(nullptr, this);
	XButton->AC(Button)->SetButton(LOADTEX("XButton", "./rs/XButton.png"), [&]() { ClickXButton(); }, Vector2(400, -300), Vector2(33.f, 33.f));
}

void PopUpScreen::ClickXButton()
{
	SetDestroy();
}

void PopUpScreen::SetPopUp(texture * lpTex)
{
	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(lpTex);

	transform->pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
}
