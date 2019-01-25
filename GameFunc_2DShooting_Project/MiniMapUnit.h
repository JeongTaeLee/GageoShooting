#pragma once
#include "UIRenderer.h"
class MiniMapUnit :
	public UIRenderer
{
private:
public:
	MiniMapUnit();
	virtual ~MiniMapUnit();

	virtual void Render(LPD3DXSPRITE sprite) override;
};

