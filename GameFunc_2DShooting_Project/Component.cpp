#include "DXUT.h"
#include "Component.h"


Component::Component()
	:gameObject(nullptr), bEnable(true)
{
}


Component::~Component()
{
}

void Component::OnCollision(Collider * collider)
{
}
