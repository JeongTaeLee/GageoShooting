#include "DXUT.h"
#include "Button.h"


Button::Button()
	:lpRenderer(nullptr), Func(nullptr), reSrc({ 0, 0, 0, 0 })
{
}


Button::~Button()
{
}

void Button::Init()
{
}

void Button::Update()
{
	Vector2 vMousePos;

	vMousePos = INPUT.GetMousePos();

	SetRect(&reSrc, transform->worldPos.x - vSize.x / 2, transform->worldPos.y - vSize.y / 2,
		transform->worldPos.x + vSize.x / 2, transform->worldPos.y + vSize.y / 2);

	POINT ptMouse;
	ptMouse.x = vMousePos.x;
	ptMouse.y = vMousePos.y;

	if (PtInRect(&reSrc, ptMouse))
	{
		fColor = LinerInterpolation(fColor, 0.5f, 0.2f);
		
		if (KEYUP(VK_LBUTTON))
			Func();
	}
	else
		fColor = LinerInterpolation(fColor, 1.f, 0.2f);
			
	lpRenderer->SetColor(D3DXCOLOR(fColor, fColor, fColor, 1.f));
}

void Button::SetButton(texture * tex, function<void()> _Func, const Vector2 & pos, const Vector2 & size)
{
	lpRenderer = gameObject->AC(UIRenderer);
	lpRenderer->SetTex(tex);
	
	fColor = lpRenderer->GetColor().r;

	transform->pos = pos;

	Func	= _Func;
	vSize = size;

	SetRect(&reSrc, transform->worldPos.x - vSize.x / 2, transform->worldPos.y - vSize.y / 2,
		transform->worldPos.x + vSize.x / 2, transform->worldPos.y + vSize.y / 2);
}
