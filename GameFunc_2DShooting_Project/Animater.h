#pragma once
#include "Component.h"

using veTexture = vector<texture*>;

class Animater :
	public Component
{
private:
	Renderer * lpRenderer;

	string sNowAnimation;
	
	map<string, veTexture*> mAnimations;
	veTexture* lpNowAnimation;

	int iCount;
	int iAmount;

	float fAccrue;
	float fDelay;

	bool bStop;
public:
	Animater();
	virtual ~Animater();

	virtual void Init()	override;
	virtual void Update()	override;
	virtual void Release()	override;

public:
	void Add(const string & key, const string & keys, const string & paths, int mn, int mx);
	void Play(const string & key);
	void Stop(int index);
	void UnStop() { bStop = false; }
	void SetDelay(float _fDelay) { fDelay = _fDelay; }

	const string & GetString() { return sNowAnimation; }

	int GetCount() { return iCount; }
};

