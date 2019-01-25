#pragma once

class Component;
class Transform;

class GameObject
{
protected:
	list<Component*> liComponent;
	list<GameObject*> liChildObjects;
public:
	Transform * transform;
	GameObject * lpParentObject;

	string tag;

	bool bDestory;
	bool bActive;
	bool bNoneDestroy;
public:
	GameObject();
	virtual ~GameObject();

	virtual void OnActive() {}
	virtual void Init() {}
	virtual void Release() {}
	virtual void Update() {}
private:
	virtual void ComRelease();
public:
	virtual void ComUpdate();
public:
	GameObject * AddChild(GameObject* lpChildObject);
	GameObject * SetParent(GameObject * _lpParentObject);

	void SetUnParent();
	void DeleteChild(GameObject * lpChildObject);

public:
	void SetDestroy(bool destroy = true) { bDestory = destroy; };
	void SetActive(bool active);

public:
	void SendMsg(const string & msg);
	virtual void Receive(const string & msg) {}
	
	void SendCollider(Collider * collider);
	virtual void OnCollision(Collider * collider) {}
public:
	template<class T>
	T * GetComponent()
	{
		T * component = nullptr;

		for (auto Iter : liComponent)
		{
			component = dynamic_cast<T*>(Iter);
		
			if (component)
				return component;
		}

		return nullptr;
	}
	template<class T>
	T * AddComponent()
	{
		T * component = new T;

		component->gameObject = this;
		component->transform = transform;
		liComponent.push_back(component);

		component->Init();
		return component;
	}
	template <class T>
	void DeleteComponent()
	{
		T * component = nullptr;
		
		for (auto Iter = liComponent.begin(); Iter != liComponent.end();)
		{
			component = dynamic_cast<T*>((*Iter));

			if (component)
			{
				component->Release();
				SAFE_DELETE(component);
				Iter = liComponent.erase(Iter);
			}
			else
				++Iter;
		}	
	}
};

#define AC(dd) AddComponent<##dd##>()
#define GC(dd) GetComponent<##dd##>()
#define DC(dd) DeleteComponent<##dd##>()
