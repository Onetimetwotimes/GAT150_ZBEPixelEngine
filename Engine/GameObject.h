#pragma once
#include "Object.h"
#include "Transform.h"

namespace zbe {
	class Component;

	class GameObject : Object {
	public:
		
		virtual void Create(void* data) override;
		virtual void Destroy() override;
		virtual void Read(const rapidjson::Value& value) override;


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

		std::string Name() {
			return name;
		}

		friend class Component;
		friend class PhysicsComponent;
	protected:
		std::vector<Component*> components;
		zbe::math::Transform transform;
		std::string name;


	};
}