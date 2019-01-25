#pragma once
#include "GameObject.h"

class VictoryEnding :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Animater * lpAnimater;
public:
	VictoryEnding();
	virtual ~VictoryEnding();

	virtual void Init()	override;
	virtual void Update()	override;
	virtual void Receive(const string & msg) override;

};

