#include "pch.h"
#include "GameObject.h"
#include "Compenent.h"
#include "RenderComponent.h"
#include "ObjectFactory.h"

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
	engine = static_cast<zbe::Engine*>(data);
}

void zbe::GameObject::Destroy() {
	RemoveAllComponents();
}

void zbe::GameObject::Read(const rapidjson::Value& value) {
	zbe::IO::GetJSON(value, "position", transform.position);
	zbe::IO::GetJSON(value, "scale", transform.scale);
	zbe::IO::GetJSON(value, "angle", transform.rotation);
	
	auto iter = value.FindMember("components");

	if (iter != value.MemberEnd()) {
		auto& comps = iter->value;
		if (comps.IsArray()) {
			for (int i = 0; i < comps.Size(); i++) {
				std::string type;
				IO::GetJSON(comps[i], "type", type);
				if (type.empty())
					continue;

				Component* comp = ObjectFactory::Instance().Create<Component>(type);
				comp->Read(comps[i]);
				comp->owner = this;
				comp->Create(nullptr);
				components.push_back(comp);
			}
		}
	}
}

void zbe::GameObject::setScene(Scene* scene) {
	this->scene = scene;
}