#pragma once
class Scene
{
public:
	bool bLoadingComplete;
public:
	Scene();
	virtual ~Scene();

	virtual void Init() PURE;
	virtual void Release() PURE;
	virtual void Update() PURE;
	virtual void Render(LPD3DXSPRITE sprite) PURE;

	virtual void ResourceLoading() {

		bLoadingComplete = true;
	}

	bool GetLoadingComplete() { return bLoadingComplete; }
};

