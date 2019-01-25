#pragma once
#include "GameObject.h"
class MiniMap :
	public GameObject
{
private:
	UIRenderer * renderer;
public:
	MiniMap();
	virtual ~MiniMap();

	void SetMiniMap(texture * lpTex);
};

