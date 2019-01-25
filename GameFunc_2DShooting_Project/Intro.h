#pragma once
#include "GameObject.h"
class Intro :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Animater * lpAnimater;
public:
	Intro();
	virtual ~Intro();

	virtual void Init()	override;
	virtual void Receive(const string & msg);
};

