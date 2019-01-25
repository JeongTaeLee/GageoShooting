#pragma once
#include "singleton.h"

class Scene;

class SceneManager :
	public singleton<SceneManager>
{
private:
	vector<texture *> loading;
	int iCount;
	float fDelay;
	float fAccrue;

	texture * lpLoadingTexture;
	map<string, Scene* > scenes;

	string nowScene;

	Scene * lpNowScene;
	Scene * lpNextScene;

	thread * loadingThread;

	bool bLoading;
public:
	SceneManager();
	virtual ~SceneManager();
		
public:
	Scene * AddScene(const string & key, Scene * scene);
	Scene * ChanScene(const string & key);
	
	void Update();
	void Render(LPD3DXSPRITE sprite);

	const string & GetSceneStr() {
		return nowScene;
	}
};

#define SCENE SceneManager::GetInst()
