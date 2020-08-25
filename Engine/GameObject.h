#pragma once
#include "Object.h"
#include "Transform.h"
#include "Engine.h"

namespace zbe {
	class Component;
	class Scene;

	class GameObject : public Object {
	public:
		
		virtual void Create(void* data) override;
		virtual void Destroy() override;
		virtual void Read(const rapidjson::Value& value) override;
		void setScene(Scene* scene);

		void Update();
		void Draw();

		void AddComponent(Component* c);
		void RemoveComponent(Component* c);
		void RemoveAllComponents();

		template<typename T>
		T* GetComponent() {
			T* result{ nullptr };

			for (auto component : components) {
				result = dynamic_cast<T*>(component);
				if (result)
					break;
			}

			return result;
		}

		std::string Name() { return name; }

		zbe::math::Transform getTransform() { return transform;	}
		zbe::math::Transform transform;
		zbe::Engine* engine;

	protected:
		std::vector<Component*> components;
		zbe::Scene* scene;
		std::string name;


	};
}