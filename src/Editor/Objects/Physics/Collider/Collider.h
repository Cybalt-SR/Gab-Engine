#pragma once

#include "../../Object.h"

namespace gde {
	class Collider : public Object {
	private:
		float radius;
	public:
		Collider(float radius);
		float GetWorldRadius();
	};
}