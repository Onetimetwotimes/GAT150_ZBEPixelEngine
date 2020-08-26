#pragma once
#include "Object.h"
#include <list>

namespace zbe {
	class Engine;
	class GameObject;


	class Scene : public Object {
	public :
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual void Read(const rapidjson::Value& v) override;

		void Draw();

		void Update();

		GameObject* Find(const std::string& name);

		void AddGameObject(GameObject* object);
		void RemoveGameObject(GameObject* object);
		void RemoveAllObjects();

	protected:
		Engine* engine{ nullptr };
		std::list<GameObject*> gameObjects;
	};
}