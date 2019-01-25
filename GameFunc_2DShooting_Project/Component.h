#pragma once

class Transform;

class Component
{
public:
	GameObject * gameObject;
	Transform * transform;

	bool bEnable;
public:
	Component();
	virtual ~Component();

	virtual void Init() {}
	virtual void Release() {}
	virtual void Update() {}
	virtual void Render(LPD3DXSPRITE sprite) {}

public:
	void SetGameObject(GameObject * object) { gameObject = object; }
	void SetEnable(bool enable) { bEnable = enable; }

public:
	virtual void OnCollision(Collider * collider);
	virtual void Receive(const string & key) {}
};

