#pragma once
#include "Resource.h"
#include <string>
#include "Vector2.h"
#include "Renderer.h"

namespace zbe {
	namespace Graphics {
		class Sprite : public zbe::Resource {
		public:
			bool Create(const std::string name, void* renderer) override;

			void Destroy() override;

			bool Draw(zbe::math::Vector2 position, zbe::math::Vector2 scale, float rotation);

			zbe::math::Vector2 GetSize();

		private:
			SDL_Texture* texture;
			Renderer* renderer;
		};
	}
}