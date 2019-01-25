#pragma once
#include "UIRenderer.h"
class UIText :
	public UIRenderer
{
public:
	string		str;
	D3DXCOLOR	color;

	int size;
public:
	UIText();
	virtual ~UIText();

	virtual void Render(LPD3DXSPRITE sprite)	override;

	void SetStr(const string & _str) { str = _str; }
	void SetColor(D3DXCOLOR _color) { color = _color; }	
	void SetSize(float _size) { size = _size; }
};

