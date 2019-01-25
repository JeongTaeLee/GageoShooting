#pragma once
#include "GameObject.h"
class MissionImage :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;

	float fAlpha;

	float fAccrue;
	float fDelay;
public:
	MissionImage();
	virtual ~MissionImage();

	virtual void Init()	override;
	virtual void Update()	override;

public:
	void SetTex(texture * tex) { lpUiRenderer->SetTex(tex); }
};

