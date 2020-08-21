#pragma once
#include "pch.h"
#include "Sprite.h"
#include "Vector2.h"
#include "SDL_image.h"

bool zbe::Graphics::Sprite::Create(const std::string filename, void* renderer) {
	this->renderer = static_cast<SDL_Renderer*>(renderer);

	SDL_Surface* s = IMG_Load(filename.c_str());
	if (s == nullptr)
		return false;

	texture = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);
	if (texture == nullptr)
		return false;

	return true;
}

zbe::math::Vector2 zbe::Graphics::Sprite::GetSize() {
	int x, y;
	SDL_QueryTexture(texture, NULL, NULL, &x, &y);
	return { x, y };
}

void zbe::Graphics::Sprite::Destroy() {
	delete texture;
}

bool zbe::Graphics::Sprite::Draw(zbe::math::Vector2 position, zbe::math::Vector2 scale, float rotation) {
	SDL_Rect rect;
	zbe::math::Vector2 v = scale * GetSize();

	rect.x = position.x;
	rect.y = position.y;

	rect.w = v.x;
	rect.h = v.y;


	
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	return true;
}

