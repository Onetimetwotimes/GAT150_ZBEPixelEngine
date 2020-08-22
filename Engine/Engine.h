#pragma once
#include "System.h"
#include <vector>
#include "json.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "Timer.h"

namespace zbe {
	class Engine {
	public:
		bool Startup();
		void Shutdown();

		void Update();

		template<typename T>
		T* GetSystem();

		zbe::FrameTime& GetTime() { return frameTime; }



	protected:
		std::vector<System*> systems;
		zbe::FrameTime frameTime;
	};
	template<typename T>
	inline T* Engine::GetSystem() {
		T* result{ nullptr };

		for (auto s : systems) {
			result = dynamic_cast<T*>(s);
			if (result)
				break;
		}

		return result;
	}
}