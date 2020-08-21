#pragma once
#include "SDL.h"
#include "System.h"

enum class KeyCodes {

};

namespace zbe {
	namespace Input {
		class Keyboard : public System {
		public:
			enum e_ButtonState {
				IDLE = 0,
				PRESSED = 1,
				RELEASED = 2,
				HELD = 3
			};

			bool Init() override;
			void Close() override;
			void Update() override;

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
