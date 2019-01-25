#pragma once
#include "singleton.h"

class Renderer;
class Collider;
class UIRenderer;
class GameObject;

class ObjectManager :
	public singleton<ObjectManager>
{
private:
	list<GameObject*> liObjects;

	list<Renderer*> liObjsRenderer;
	list<UIRenderer*> liUIsRenderer;

	list<Collider*> liCollider;

	bool CollisionCheckStart;
public:
	ObjectManager();
	virtual ~ObjectManager();

	template <class T>
	T * AddObject(T * _lpObject = nullptr, GameObject * parentObject = nullptr) {
		T * lpObject = _lpObject;

		if (!lpObject)
			lpObject = new T;

		liObjects.push_back(lpObject);

		if (parentObject)
			parentObject->AddChild(lpObject);

		lpObject->Init();
		lpObject->transform->UpdateTransform();

		return lpObject;
	}

	Renderer * AddObjRenderer(Renderer * renderer);
	void DeleteObjRenderer(Renderer * renderer);

	UIRenderer * AddUIRenderer(UIRenderer * renderer);
	void DeleteUIRenderer(UIRenderer * renderer);

	Collider * AddCollider(Collider * collider);
	void DeleteCollider(Collider * collider);
public:
	void Reset();
	void Update();
	void Render(LPD3DXSPRITE sprite);

	void DestoryCheck();
	void ColliderUpdate();

	template<class T>
	T * FindObject(const string & key)
	{
		for (auto Iter : liObjects)
		{
			if (Iter->tag == key)
			{
				T * t = dynamic_cast<T*>(Iter);

				if (t)
					return t;
			}
		}

		return nullptr;
	}
};

#define OBJECT ObjectManager::GetInst()
#define AddObj(obj) OBJECT.AddObject<obj>()