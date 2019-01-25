#include "DXUT.h"
#include "Renderer.h"


Renderer::Renderer()
	:lpTex(nullptr), vCenterPos(0.f, 0.f, 0.f), reSrc({ 0, 0, 0, 0 }), iRenderingSort(0), color(1.f, 1.f, 1.f, 1.f), bRenderingSort(true), bYSorting(true)
{

}


Renderer::~Renderer()
{
}

void Renderer::Init()
{
	OBJECT.AddObjRenderer(this);
}

void Renderer::Release()
{
	OBJECT.DeleteObjRenderer(this);
}

void Renderer::Render(LPD3DXSPRITE sprite)
{
	transform->SetTransform(sprite);
	sprite->Draw(lpTex->lpD3DTex, &reSrc, &vCenterPos, nullptr, color);
}

texture * Renderer::SetTex(texture * _lpTex, bool bCenter)
{
	lpTex = _lpTex;
	
	SetRect(&reSrc, 0, 0, lpTex->info.Width, lpTex->info.Height);

	if (bCenter)
		vCenterPos = Vector3(lpTex->info.Width / 2, lpTex->info.Height / 2, 0.f);

	return lpTex;
}

texture * Renderer::ChangTex(texture * _lpTex)
{
	SetRect(&reSrc, 0, 0, _lpTex->info.Width, _lpTex->info.Height);

	return (lpTex = _lpTex);
}

void Renderer::SetCenterPos(Vector3 center)
{
	vCenterPos = center;
}

void Renderer::SetMiddleCenter(Vector3 add)
{
	if (lpTex)
		vCenterPos = Vector3(lpTex->info.Width / 2, lpTex->info.Height / 2, 0.f) + add;
}
