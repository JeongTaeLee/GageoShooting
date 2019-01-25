#pragma once
#include "Renderer.h"
class UIRenderer :
	public Renderer
{
private:
public:
	UIRenderer();
	virtual ~UIRenderer();

	virtual void Init()	override;
	virtual void Release()	override;
};

