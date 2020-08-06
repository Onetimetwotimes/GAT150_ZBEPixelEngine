#pragma once
#include "Drawable.h"
#include <string>

namespace zbe {
	class Sprite : public Drawable {
	public:
		bool Create(const std::string name);

		bool Destroy();

		bool Draw(zbe::math::Vector2 position, zbe::math::Vector2 scale, float rotation) override;
	private:

	};
}