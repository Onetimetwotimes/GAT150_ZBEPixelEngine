#include "pch.h"
#include "Engine.h"
#include "Keyboard.h"
#include <iostream>

bool zbe::Engine::Startup() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	systems.push_back(new zbe::Graphics::Renderer);
	systems.push_back(new zbe::Input::Keyboard);
	systems.push_back(new zbe::ResourceManager);

	for (auto s : systems) {
		if (!s->Init())
			return false;
	}

	GetSystem<zbe::Graphics::Renderer>()->Create("zbe", 800, 600);

	return true;
}

void zbe::Engine::Shutdown() {
	for (auto s : systems) {
		s->Close();
		delete s;
	}
	systems.clear();

	SDL_Quit();
}

void zbe::Engine::Update() {
	frameTime.Tick();

	for (auto s : systems) {
		s->Update();
	}
}
