#pragma once
#include "System.h"

namespace zbe {
	namespace Graphics {
		class Renderer : public System {
		public :
			virtual bool Init() override;
			virtual void Close() override;
			virtual void Update() override;

			bool Create(const std::string name, int width, int height);

			void BeginFrame();
			void EndFrame();


			friend class Sprite;
		protected:
			SDL_Window* window;
			SDL_Renderer* renderer;
		};
	}
}