#pragma once
#include <SDL.h>
#include "Vector2.h"

namespace zbe {
	class Drawable {
	public:

		static void SetRenderer(SDL_Renderer* renderer) {
			z_renderer = renderer;
		}

		virtual bool Draw(zbe::math::Vector2 position, zbe::math::Vector2 scale, float rotation) = 0;

	protected:
		static SDL_Renderer* z_renderer;
	};
}