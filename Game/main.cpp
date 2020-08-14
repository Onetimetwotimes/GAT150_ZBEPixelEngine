#include <iostream>
#include <SDL_image.h>
#include <Keyboard.h>
#include <stdio.h>

zbe::Input::Keyboard keyboard;

	int main(int, char**){


		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
		

		SDL_Window* window = SDL_CreateWindow("zbePixelEngine", 100, 100, 800, 600, SDL_WINDOW_SHOWN); 
		if (window == nullptr) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl; SDL_Quit(); return 1; 
		}

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_WINDOW_SHOWN);
		if (renderer == nullptr) {
			std::cout << "SDL_Renderer Error: " << SDL_GetError() << std::endl; SDL_Quit(); return 1;
		}

		keyboard.Init();


		SDL_Surface* surface = IMG_Load("assets/waterdoods.png");
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect rect;
		rect.x = 100;
		rect.y = 100;
		rect.w = 64;
		rect.h = 64;

		SDL_Event event;
		bool quit = false;
		while (!quit) {
			SDL_PollEvent(&event);

			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);


			SDL_RenderCopy(renderer, texture, NULL, &rect);
			SDL_RenderPresent(renderer);

			

			keyboard.Update();

		}

		keyboard.Close();
		IMG_Quit();
		SDL_Quit(); 
		return 0; 
	}