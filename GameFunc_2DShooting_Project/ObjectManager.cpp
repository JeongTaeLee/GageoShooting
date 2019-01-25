#include "DXUT.h"
#include "ObjectManager.h"



ObjectManager::ObjectManager()
	:CollisionCheckStart(false)
{
}


ObjectManager::~ObjectManager()
{
	Reset();
}

Renderer * ObjectManager::AddObjRenderer(Renderer * renderer)
{
	if (!renderer)
		return nullptr;

	liObjsRenderer.push_back(renderer);

	return renderer;
}

void ObjectManager::DeleteObjRenderer(Renderer * renderer)
{
	for (auto Iter = liObjsRenderer.begin(); Iter != liObjsRenderer.end();)
	{
		if ((*Iter) == renderer)
			Iter = liObjsRenderer.erase(Iter);
		else
			++Iter;
	}
}

UIRenderer * ObjectManager::AddUIRenderer(UIRenderer * renderer)
{
	if (!renderer)
		return nullptr;

	liUIsRenderer.push_back(renderer);

	return renderer;
}

void ObjectManager::DeleteUIRenderer(UIRenderer * renderer)
{
	for (auto Iter = liUIsRenderer.begin(); Iter != liUIsRenderer.end();)
	{
		if ((*Iter) == renderer)
			Iter = liUIsRenderer.erase(Iter);
		else
			++Iter;
	}
}

Collider * ObjectManager::AddCollider(Collider * collider)
{
	liCollider.push_back(collider);
	return collider;
}

void ObjectManager::DeleteCollider(Collider * collider)
{
	for (auto Iter = liCollider.begin(); Iter != liCollider.end();)
	{
		if ((*Iter) == collider)
		{
			Iter = liCollider.erase(Iter);
			break;
		}
		else
			++Iter;
	}
}

void ObjectManager::Reset()
{
	for (auto Iter : liObjects)
	{
		Iter->Release();
		SAFE_DELETE(Iter);
	}
	liObjects.clear();

	liObjsRenderer.clear();
	liUIsRenderer.clear();
}

void ObjectManager::Update()
{
	for (auto Iter : liObjects)
	{
		Iter->Update();
		Iter->ComUpdate();

		Iter->transform->UpdateTransform();
	}

	if(CollisionCheckStart)
		ColliderUpdate();

	DestoryCheck();

	CollisionCheckStart = true;
}

void ObjectManager::Render(LPD3DXSPRITE sprite)
{
	liObjsRenderer.sort(Renderer::RenderingSort);
	liObjsRenderer.sort(Renderer::YSorting);
	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	for (auto Iter : liObjsRenderer)
		Iter->Render(sprite);
	sprite->End();

	
	liUIsRenderer.sort(Renderer::RenderingSort);
	//liUIsRenderer.sort(Renderer::YSorting);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	for (auto Iter : liUIsRenderer)
		Iter->Render(sprite);
	sprite->End();
}

void ObjectManager::DestoryCheck()
{
	for (auto Iter = liObjects.begin(); Iter != liObjects.end();)
	{
		if ((*Iter)->bDestory)
		{
			(*Iter)->Release();
			SAFE_DELETE((*Iter));
			Iter = liObjects.erase(Iter);
			continue;
		}
		else
			++Iter;
	}
}

void ObjectManager::ColliderUpdate()
{
	for (auto Iter01 : liCollider)
	{
		if (!Iter01->gameObject->bActive)
			continue;

		if (!Iter01->bEnable)
			continue;

		for (auto Iter02 : liCollider)
		{
			if (!Iter02->gameObject->bActive || !Iter01->gameObject->bActive)
				continue;

			if (!Iter02->bEnable || !Iter01->bEnable)
				continue;

			if (Iter01 == Iter02)
				continue;
			RECT re;
			if (IntersectRect(&re, &Iter01->reRgn, &Iter02->reRgn))
			{
				Iter01->gameObject->SendCollider(Iter02);
				Iter02->gameObject->SendCollider(Iter01);
			}
		}
	}
}

