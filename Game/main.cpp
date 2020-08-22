#include <iostream>
#include "Engine.h"

zbe::Engine e;

int main(int, char**) {
	e.Startup();
	

	SDL_Event event;
	bool Q = false;
	while (!Q) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			Q = true;
			break;
		}

		e.Update();

		e.GetSystem<zbe::Graphics::Renderer>()->BeginFrame();


		e.GetSystem<zbe::Graphics::Renderer>()->EndFrame();
	}

	e.Shutdown();
		return 0; 
	}