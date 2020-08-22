#include "pch.h"
#include "GameObject.h"
#include "Compenent.h"
#include "RenderComponent.h"

void zbe::GameObject::Update() {
	for (Component* c : components) {
		c->Update();
	}
}

void zbe::GameObject::Draw() {
	RenderComponent* r = GetComponent<RenderComponent>();

	if(r)
		r->Draw();
}

void zbe::GameObject::AddComponent(Component* c) {
	c->owner = this;
	components.push_back(c);
}

void zbe::GameObject::RemoveComponent(Component* c) {
	auto iter = std::find(components.begin(), components.end(), c);
	if (iter != components.end()) {
		(*iter)->Destroy();
		delete(*iter);
	}
}

void zbe::GameObject::RemoveAllComponents() {
	for (Component* c : components) {
		c->Destroy();
		delete c;
	}
	components.clear();
}

void zbe::GameObject::Create(void* data) {

}

void zbe::GameObject::Destroy() {
	RemoveAllComponents();
}

void zbe::GameObject::Read(const rapidjson::Value& value)
{
}
