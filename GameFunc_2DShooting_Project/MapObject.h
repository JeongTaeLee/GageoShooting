#pragma once
#include "GameObject.h"
class MapObject :
	public GameObject
{
private:
	Renderer * lpRenderer;

public:
	MapObject();
	virtual ~MapObject();

	void SetOpaque(bool _bOpaque);
	void SetTex(texture * lpTex);
};

