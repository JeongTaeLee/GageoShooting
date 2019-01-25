#pragma once


#include "Player.h"
#include "GameObject.h"



class PlayerDownBody :
	public GameObject
{
private:
	Renderer * renderer;
	Animater * animater;
	PixelCollider * pixelCollider;
	

	PLAYERDIRECTION eDir;
public:
	PlayerDownBody();
	virtual ~PlayerDownBody();

	virtual void Init()	override;
	virtual void Update()	override;
	
	void Input();

	void SetMiniMap(texture * tex);
};

