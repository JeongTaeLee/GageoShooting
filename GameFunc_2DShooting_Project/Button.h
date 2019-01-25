#pragma once
#include "Component.h"
class Button :
	public Component
{
private:
	UIRenderer * lpRenderer;

	Vector2 vSize;
	RECT reSrc;

	function<void()> Func ;

	float fColor;
public:
	Button();
	virtual ~Button();

	virtual void Init()	override;
	virtual void Update() override;

	void SetButton(texture * tex, function<void()> _Func, const Vector2 & pos, const Vector2 & size);
	void SetTex(texture * tex) { lpRenderer->SetTex(tex); }
};

