#include "DXUT.h"
#include "UIRenderer.h"


UIRenderer::UIRenderer()
{
}


UIRenderer::~UIRenderer()
{
}

void UIRenderer::Init()
{
	OBJECT.AddUIRenderer(this);
}

void UIRenderer::Release()
{
	OBJECT.DeleteUIRenderer(this);
}
