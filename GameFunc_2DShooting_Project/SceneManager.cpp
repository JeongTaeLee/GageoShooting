#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
	:lpNowScene(nullptr), lpNextScene(nullptr), loadingThread (nullptr), bLoading(false),
	iCount(0), fDelay(0.1f), fAccrue(0.f)
{
	for (int i = 1; i <= 10; ++i)
	{
		char key[256];
		char path[256];

		sprintf(key, "(%d)", i);
		sprintf(path, "./rs/Loading/(%d).png", i);

		loading.push_back(NONEDESTROYTEX(key, path));
	}
	lpLoadingTexture = loading[0];

}


SceneManager::~SceneManager()
{
	if (lpNowScene)
		lpNowScene->Release();

	lpNowScene = nullptr;
	lpNextScene = nullptr;

	for (auto Iter : scenes)
		SAFE_DELETE(Iter.second);
	
	scenes.clear();
}

Scene * SceneManager::AddScene(const string & key, Scene * scene)
{
	if (!scene)
		return nullptr;

	if (auto find = scenes.find(key); find != scenes.end())
		return find->second;

	return scenes.insert(make_pair(key, scene)).first->second;
}

Scene * SceneManager::ChanScene(const string & key)
{
	if (auto find = scenes.find(key); find != scenes.end())
	{
		nowScene = find->first;
		return (lpNextScene = find->second);
	}
	
	return nullptr;
}



void SceneManager::Update()
{
	Sleep(1);
	if (lpNextScene && !bLoading)
	{
		SOUND.Play("Loading", 1);

		if (lpNowScene)
			lpNowScene->Release();
		
		lpNowScene = lpNextScene;
		lpNextScene = nullptr;

		if (!bLoading)
		{
			loadingThread = new thread([&]() { lpNowScene->ResourceLoading(); });
			bLoading = true;
		}
	}

	if (bLoading)
	{
		fAccrue += Et;

		if (fAccrue >= fDelay)
		{
			fAccrue = 0.f;
			if (iCount < 10 - 1)
			{
				iCount++;
				lpLoadingTexture = loading[iCount];
			}
			else
			{
				iCount = 0;
				lpLoadingTexture = loading[iCount];
			}

		}

		if (lpNowScene->GetLoadingComplete())
		{
			if (loadingThread->joinable())
			{
				loadingThread->join();

				lpNowScene->Init();

				SAFE_DELETE(loadingThread);

				iCount = 0;
			
				bLoading = false;

				SOUND.Stop("Loading");
			}
		}
	}

	if (lpNowScene && !bLoading)
		lpNowScene->Update();
}

void SceneManager::Render(LPD3DXSPRITE sprite)
{
	if (bLoading)
	{
		D3DXMATRIX mat;
		D3DXMatrixTranslation(&mat, WINSIZEX / 2, WINSIZEY / 2, 0.f);
		sprite->SetTransform(&mat);

		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		sprite->Draw(lpLoadingTexture->lpD3DTex, nullptr, 
			&Vector3(lpLoadingTexture->info.Width / 2, lpLoadingTexture->info.Height / 2, 0.f), 
			nullptr, 
			D3DCOLOR_XRGB(255, 255, 255));
		sprite->End();
	}

	if (lpNowScene && !bLoading)
		lpNowScene->Render(sprite);

}