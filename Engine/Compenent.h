#pragma once
#include "Object.h"

namespace zbe {
	class Component : public Object {
	public:
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		GameObject* owner{ nullptr };
	};
}