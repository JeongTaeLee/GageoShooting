#pragma once
#include "Component.h"
class Renderer :
	public Component
{
protected:
	texture * lpTex;

	Vector3	vCenterPos;
	RECT	reSrc;

	D3DXCOLOR color;

	int iRenderingSort;


	bool bRenderingSort;
	bool bYSorting;
public:
	Renderer();
	virtual ~Renderer();

	virtual void Init() override;
	virtual void Release()	override;
	virtual void Render(LPD3DXSPRITE sprite) override;
public:
	texture * SetTex(texture * _lpTex, bool bCenter = true);
	texture * ChangTex(texture * _lpTex);

	void SetRenderingSortEnable(bool bEnable) { bRenderingSort = bEnable; }
	void SetYSortEnable(bool _bEnable) { bYSorting = _bEnable; }
	void SetRenderingSort(int _iRenderinSort) { iRenderingSort = _iRenderinSort; }
	void SetCenterPos(Vector3 center);
	void SetMiddleCenter(Vector3 add = Vector3(0.f, 0.f, 0.f));
	void SetColor(D3DXCOLOR _color) { color = _color; }
	void SetSrc(RECT src) { reSrc = src; }

	D3DXCOLOR GetColor() { return color; }
	texture * GetTex() { return lpTex; }

	static bool YSorting(Renderer *renderer01, Renderer * renderer02)
	{
		if ((renderer01->bYSorting == false) || (renderer02->bYSorting == false))
			return false;

		if (renderer01->iRenderingSort == renderer02->iRenderingSort)
		{
			if (renderer01->transform->worldPos.y < renderer02->transform->worldPos.y)
				return true;
		}
		return false;
	}
	static bool RenderingSort(Renderer * renderer01, Renderer * renderer02)
	{
		if (!renderer01->bRenderingSort || !renderer02->bRenderingSort)
			return false;

		if (renderer01->iRenderingSort < renderer02->iRenderingSort)
			return true;

		return false;
	}
};

