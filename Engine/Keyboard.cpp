#include "pch.h"
#include "Keyboard.h"
#include <string>
#include <iostream>

bool zbe::Input::Keyboard::Init() {
	const Uint8* keystate = SDL_GetKeyboardState(&numKeys);

	currKeystate = new Uint8[numKeys];
	prevKeystate = new Uint8[numKeys];

	std::memcpy(currKeystate, keystate, numKeys);
	std::memcpy(prevKeystate, keystate, numKeys);

	return true;
}

void zbe::Input::Keyboard::Close() {
	delete[] currKeystate;
	delete[] prevKeystate;
}

void zbe::Input::Keyboard::Update() {	
	std::memcpy(prevKeystate, currKeystate, numKeys);
	const Uint8* keystate = SDL_GetKeyboardState(nullptr);
	std::memcpy(currKeystate, keystate, numKeys);
}

zbe::Input::Keyboard::e_ButtonState zbe::Input::Keyboard::getButtonState(int buttonId)
{
	short currdown =  1 * currKeystate[buttonId];
	short prevDown =  2 * prevKeystate[buttonId];
	short state = currdown + prevDown;
	return static_cast<e_ButtonState>(state);
}

bool zbe::Input::Keyboard::ButtonDown(int buttonId)
{
	Uint8 state = currKeystate[buttonId];
	std::cout << state;
	return currKeystate[buttonId];
}

bool zbe::Input::Keyboard::ButtonHeld(int buttonId) {
	return
		currKeystate[buttonId] &&
		prevKeystate[buttonId];

}

bool zbe::Input::Keyboard::ButtonPressed(int buttonId) {
	return
		 currKeystate[buttonId] &&
		!prevKeystate[buttonId];

}

bool zbe::Input::Keyboard::ButtonReleased(int buttonId) {
	return
		!currKeystate[buttonId] &&
		 prevKeystate[buttonId];
}
