#pragma once
#include "singleton.h"

struct texture
{
	LPDIRECT3DTEXTURE9	lpD3DTex;	
	D3DXIMAGE_INFO		info;
	bool bNoneDestroy;

	texture(LPDIRECT3DTEXTURE9 _lpD3DTex, D3DXIMAGE_INFO _info)
		:lpD3DTex(_lpD3DTex), info(_info), bNoneDestroy(false)
	{

	}
	~texture()
	{
		SAFE_RELEASE(lpD3DTex);
	}
};

class ImageManager :
	public singleton<ImageManager>
{
private:
	map<string, texture*> mTexs;

public:
	ImageManager();
	~ImageManager();

	texture * LoadTexture(const string & key, const string & path, bool _bNoneDestory = false);
	void LoadTextures(const string & keys, const string & paths, int mn, int mx, bool _bNoneDestory = false);

	void DeleteImages();

	void drawText(LPD3DXSPRITE sprite, const string & str, const Vector2 & pos, int size, D3DXCOLOR color = D3DXCOLOR(1.f, 1.f, 1.f, 1.f));
};

#define IMAGE ImageManager::GetInst()

#define LOADTEX(k, p) IMAGE.LoadTexture(k, p, false)
#define LOADTEXS(k, p, mn, mx) IMAGE.LoadTextures(k, p, mn, mx, false)

#define NONEDESTROYTEX(k, p) IMAGE.LoadTexture(k, p, true)
#define NONEDESTROYTEXS(k, p, mn, mx) IMAGE.LoadTextures(k, p, mn, mx, true)
