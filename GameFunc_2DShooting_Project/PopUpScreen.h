#pragma once
#include "GameObject.h"
class PopUpScreen :
	public GameObject
{
protected:
	GameObject * XButton;
	UIRenderer * lpUiRenderer;
public:
	PopUpScreen();
	virtual ~PopUpScreen();

	virtual void Init()	override;	
	
	void ClickXButton();

	void SetPopUp(texture * lpTex);
};

