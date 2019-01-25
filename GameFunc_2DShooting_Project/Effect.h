#pragma once
#include "GameObject.h"
class Effect :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Animater * lpAnimater;
public:
	Effect();
	virtual ~Effect();

	void SetEffect(const Vector2 & pos, float size, const string & keys, int mn, int mx);

	virtual void Receive(const string & msg) override;
};

