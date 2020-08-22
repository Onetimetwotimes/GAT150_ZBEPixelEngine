#pragma once
#include "Compenent.h"

namespace zbe {
	class RenderComponent : public Component {
	public :
		virtual void Draw() = 0;
	};
}