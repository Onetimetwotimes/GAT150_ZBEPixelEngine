#pragma once
#include "Compenent.h"

namespace zbe {
	class PhysicsComponent : public Component {
	public:

		virtual void Create(void* data) override;
		virtual void Destroy() override;
		virtual void Read(const rapidjson::Value& value) override;

		virtual void Update() override;


	protected:
		zbe::math::Vector2 velocity;
		zbe::math::Vector2 force;

		float damping = 1;
	};
}