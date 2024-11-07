#pragma once

#include "Input/InputAction.h"
#include "../Datatypes/Vector2.h"

namespace gde {
	namespace input {
		struct MouseScroll : public InputAction {
			Vector2 delta;
		};
	}
}