#pragma once
#include "GameObject.h"

class MapObject;
class Player;

class Map :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Player * lpPlayer;

	vector<MapObject*> veMapObject;
	texture * lpMiniMapTex;

	int iMonsterCount; 
public:
	Map();
	virtual ~Map();

	virtual void Init()	override;
	virtual void Release() override;

	virtual void Update()	override;

	void AddMapObject(const Vector2 & pos, texture * lpTex);

	void SetPlayer(Player * player) { lpPlayer = player; }
	void SetMiniMap(texture * minimap) { lpMiniMapTex = minimap; }
	void SetMapTexture(texture * maptex);
	void AddMonsterCount();
	void MinusMonsterCount();
};

