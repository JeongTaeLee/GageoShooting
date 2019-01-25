#include "DXUT.h"
#include "Animater.h"


Animater::Animater()
	:lpRenderer(nullptr), sNowAnimation("None"), lpNowAnimation(nullptr), iCount(0), iAmount(0), fAccrue(0.f), fDelay(1.f), bStop(false)
{
}


Animater::~Animater()
{
}

void Animater::Init()
{
	lpRenderer = gameObject->GC(Renderer);
}

void Animater::Update()
{
	if (!lpRenderer)
		return;

	if (sNowAnimation == "None")
		return;

	if (!lpNowAnimation)
		return ;

	if (bStop)
		return;

	fAccrue += Et;

	if (fAccrue >= fDelay)
	{
		fAccrue = 0.f;

		if (iCount < iAmount - 1)
		{
			++iCount;
			lpRenderer->ChangTex((*lpNowAnimation)[iCount]);
		}
		else
		{
			iCount = 0;
			lpRenderer->ChangTex((*lpNowAnimation)[iCount]);
			gameObject->SendMsg("EndAnimation");
		}
	}
}

void Animater::Release()
{
	for (auto Iter : mAnimations)
		SAFE_DELETE(Iter.second);
	
	mAnimations.clear();
}

void Animater::Add(const string & key, const string & keys, const string & paths, int mn, int mx)
{
	if (auto find = mAnimations.find(key); find != mAnimations.end())
		return;

	veTexture * texture = new veTexture;

	for (int i = mn; i <= mx; ++i)
	{
		char key[256];
		sprintf(key, keys.c_str(), i);

		char path[256];
		sprintf(path, paths.c_str(), i);

		texture->push_back(IMAGE.LoadTexture(key, path));
	}

	mAnimations.insert(make_pair(key, texture)); 

	if (mAnimations.size() == 1)
	{
		sNowAnimation = key;
		lpNowAnimation = texture;

		iCount = 0;
		iAmount = (*lpNowAnimation).size();
		fAccrue = 0.f;

		lpRenderer->ChangTex((*lpNowAnimation)[0]);
	}
}

void Animater::Play(const string & key)
{
	if (auto find = mAnimations.find(key); find != mAnimations.end())
	{
		sNowAnimation = key;
		lpNowAnimation = find->second;

		fAccrue = 0.f;
		iCount = 0;
		iAmount = (*lpNowAnimation).size();

		lpRenderer->ChangTex((*lpNowAnimation)[0]);
	}
}

void Animater::Stop(int index)
{
	lpRenderer->ChangTex((*lpNowAnimation)[index]);
	bStop = true;
}
