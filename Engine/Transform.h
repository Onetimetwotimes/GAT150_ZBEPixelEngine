#include "Vector2.h"
#pragma once



namespace zbe {
	namespace math {
		struct Transform {
			zbe::math::Vector2 position;
			float scale;
			float rotation;

			Transform() : position{ 0,0 }, scale{ 1 }, rotation{ 0 } {}
			Transform(const zbe::math::Vector2 position, const float scale = 1, const float rotation = 0) {
				this->position = position;
				this->scale = scale;
				this->rotation = rotation;
			}


		};

	}
}