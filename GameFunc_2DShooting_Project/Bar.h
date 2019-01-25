#pragma once
#include "GameObject.h"
class Bar :
	public GameObject
{
protected:
	UIRenderer * lpUIRenderer;

	float fLength;
	float fMaxLength;

	UINT uiTexWidth;
	UINT uiTexHeight;
public:
	Bar();
	virtual ~Bar();

	void UpdateBar(float fNowValue);
	void SetBar(const Vector2 & vPos, texture * tex, float fMaxValue, float fNowValue);
};

