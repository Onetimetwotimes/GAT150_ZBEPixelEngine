#include "pch.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "Timer.h"
namespace zbe {
	void PhysicsComponent::Create(void* data)
	{
	}

	void PhysicsComponent::Destroy()
	{
	}

	void PhysicsComponent::Read(const rapidjson::Value& value)
	{
	}

	void PhysicsComponent::Update() {
		velocity += force;
		velocity *= damping;
		owner->transform.position += velocity;
	}
}