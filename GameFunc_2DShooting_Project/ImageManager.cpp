#include "DXUT.h"
#include "ImageManager.h"


ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
	for (auto Iter : mTexs)
	{
		SAFE_RELEASE(Iter.second->lpD3DTex);
		SAFE_DELETE(Iter.second);
	}
	mTexs.clear();
}

texture * ImageManager::LoadTexture(const string & key, const string & path, bool _bNoneDestory)
{
	if (auto find = mTexs.find(key); find != mTexs.end())
		return find->second;

	LPDIRECT3DTEXTURE9 lpD3DTex;
	D3DXIMAGE_INFO info;

	if (FAILED(D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &lpD3DTex)))
	{
		DEBUG_LOG("Failed Loadtexture : " << key << "  " << path);
		return nullptr;
	}
	texture * lpTex = mTexs.insert(make_pair(key, new texture(lpD3DTex, info))).first->second;
	lpTex->bNoneDestroy = _bNoneDestory;
	
	return lpTex;
}

void ImageManager::LoadTextures(const string & keys, const string & paths, int mn, int mx, bool _bNoneDestory)
{
	for (int i = mn; i <= mx; ++i)
	{
		char key[256];
		sprintf(key, keys.c_str(), i);

		char path[256];
		sprintf(path, paths.c_str(), i);

		LoadTexture(key, path, _bNoneDestory);
	}
}

void ImageManager::DeleteImages()
{
	for (auto Iter = mTexs.begin(); Iter != mTexs.end();)
	{
		if (!Iter->second->bNoneDestroy)
		{
			SAFE_RELEASE((*Iter).second->lpD3DTex);
			SAFE_DELETE((*Iter).second);

			Iter = mTexs.erase(Iter);
		}
		else
			++Iter;
	}
}

void ImageManager::drawText(LPD3DXSPRITE sprite, const string & str, const Vector2 & pos, int size, D3DXCOLOR color)
{
	LPD3DXFONT font;
	
	D3DXCreateFontA(g_device, size, 0, 0, 1, 0, DEFAULT_CHARSET, D3DX_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, "±¼¸²", &font);

	RECT re = { 0 };
	
	D3DXMATRIX mat;
	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0.f);
	sprite->SetTransform(&mat);

	font->DrawTextA(sprite, str.c_str(), -1, &re, DT_NOCLIP | DT_CENTER, color);

	SAFE_RELEASE(font);
}
