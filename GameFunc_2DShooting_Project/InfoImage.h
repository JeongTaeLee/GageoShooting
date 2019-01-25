#pragma once
#include "GameObject.h"
class InfoImage :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;

	float fAlpha;
public:
	InfoImage();
	virtual ~InfoImage();

	virtual void Init()	override;
	virtual void OnActive() override;

	virtual void Update()	override;

	virtual void SetTex(texture * lpTex) { lpUiRenderer->SetTex(lpTex); }
};

