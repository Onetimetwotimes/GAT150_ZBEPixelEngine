#include "pch.h"
#include "Renderer.h"
#include <iostream>

bool zbe::Graphics::Renderer::Init() {
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	return true;
}

void zbe::Graphics::Renderer::Close() {
	IMG_Quit();
}

void zbe::Graphics::Renderer::Update()
{
}

bool zbe::Graphics::Renderer::Create(const std::string name, int width, int height)
{
	SDL_Window* _window = SDL_CreateWindow(name.c_str(), 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl; return false;
	}
	window = _window;

	SDL_Renderer* _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_WINDOW_SHOWN);
	if (renderer == nullptr) {
		std::cout << "SDL_Renderer Error: " << SDL_GetError() << std::endl; return false;
	}
	renderer = _renderer;

	return true;
}

void zbe::Graphics::Renderer::BeginFrame() { SDL_RenderClear(renderer); }

void zbe::Graphics::Renderer::EndFrame() { SDL_RenderPresent(renderer); }
