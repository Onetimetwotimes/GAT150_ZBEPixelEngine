#include "pch.h"
#include "scene.h"
#include "GameObject.h"
#include "ObjectFactory.h"

void zbe::Scene::Create(void* data) {
	engine = static_cast<Engine*>(data);
}

void zbe::Scene::Destroy() {
	RemoveAllObjects();
}

void zbe::Scene::Read(const rapidjson::Value& v) {
	auto iter = v.FindMember("objects");

	if (iter != v.MemberEnd()) {
		auto& objects = iter->value;

		if (objects.IsArray()) {
			for (int i = 0; i < objects.Size(); i++) {
				std::string type;
				IO::GetJSON(objects[i], "type", type);
				zbe::GameObject* o = zbe::ObjectFactory::Instance().Create<zbe::GameObject>(type);
				if (!o)
					continue;
				o->Create(engine);
				o->Read(objects[i]);
				o->setScene(this);
				gameObjects.push_back(o);
			}
		}
	}
	
}

void zbe::Scene::Draw() {
	for (GameObject* o : gameObjects) {
		o->Draw();
	}
}

void zbe::Scene::Update() {
	for (GameObject* o : gameObjects) {
		o->Update();
	}
}

 zbe::GameObject* zbe::Scene::Find(const std::string& name)
{
	 for (GameObject* p : gameObjects) {
		 if (p->Name() == name)
			 return p;
	}
}

void zbe::Scene::AddGameObject(zbe::GameObject* object) {
	gameObjects.push_back(object);
}

void zbe::Scene::RemoveGameObject(zbe::GameObject* object) {
	auto iter = std::find(gameObjects.begin(), gameObjects.end(), object);
	if (iter != gameObjects.end()) {
		(*iter)->Destroy();
		delete(*iter);
		gameObjects.remove(*iter);
	}

}

void zbe::Scene::RemoveAllObjects() {
	for (GameObject* o : gameObjects) {
		o->Destroy();
		delete o;
	}
	gameObjects.clear();
}
