#pragma once
#include "SDL.h"

enum class KeyCodes {

};

namespace zbe {
	namespace Input {
		class Keyboard {
		public:
			enum e_ButtonState {
				IDLE = 0,
				PRESSED = 1,
				RELEASED = 2,
				HELD = 3
			};

			bool Init();
			void Close();
			void Update();

			e_ButtonState getButtonState(int buttonId);

			bool ButtonDown(int buttonId);
			bool ButtonHeld(int buttonId);
			bool ButtonPressed(int buttonId);
			bool ButtonReleased(int buttonId);




		private:
			Uint8* currKeystate;
			Uint8* prevKeystate;

			int numKeys;
		};
	}
}
