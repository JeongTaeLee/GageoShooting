#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
	:lpParentObject(nullptr), tag("None"), bDestory(false), bActive(true), bNoneDestroy(false)
{
	transform = AddComponent<Transform>();
}


GameObject::~GameObject()
{
	ComRelease();

	for (auto Iter : liChildObjects)
	{
		Iter->SetUnParent();
		Iter->SetDestroy();
	}
	liChildObjects.clear();

	if (lpParentObject)
		lpParentObject->DeleteChild(this);
}

void GameObject::ComRelease()
{
	for (auto Iter : liComponent)
	{
		Iter->Release();
		SAFE_DELETE(Iter);
	}
	liComponent.clear();
}

void GameObject::ComUpdate()
{
	for (auto Iter : liComponent)
	{
		if(Iter->bEnable)
			Iter->Update();
	}
}


GameObject * GameObject::AddChild(GameObject* lpChildObject)
{
	if (!lpChildObject)
		return nullptr;

	liChildObjects.push_back(lpChildObject);
	lpChildObject->SetParent(this);

	return lpChildObject;
}

GameObject * GameObject::SetParent(GameObject * _lpParentObject)
{
	if (!_lpParentObject)
		return nullptr;

	if (lpParentObject)
		return nullptr;
	
	return (lpParentObject = _lpParentObject);
}

void GameObject::SetUnParent()
{
	lpParentObject = nullptr;
}

void GameObject::DeleteChild(GameObject * lpChildObject)
{
	if (!lpChildObject)
		return;

	for (auto Iter = liChildObjects.begin(); Iter != liChildObjects.end();)
	{
		if ((*Iter) == lpChildObject)
		{
			liChildObjects.erase(Iter);
			break;
		}
		else
			++Iter;
	}
}

void GameObject::SetActive(bool active)
{
	for (auto Iter : liChildObjects)
		Iter->SetActive(active);

	bActive = active;

	if (bActive)
		OnActive();
}

void GameObject::SendMsg(const string & msg)
{
	Receive(msg);

	for (auto Iter : liComponent)
		Iter->Receive(msg);	
}

void GameObject::SendCollider(Collider * collider)
{
	OnCollision(collider);

	for (auto Iter : liComponent)
		Iter->OnCollision(collider);
}
