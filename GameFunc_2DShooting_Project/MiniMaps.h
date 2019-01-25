#pragma once
#include "GameObject.h"
class MiniMaps :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;
public:
	MiniMaps();
	virtual ~MiniMaps();

	virtual void Init()	override;

	void SetMiniMap(texture * lpTex);
};

