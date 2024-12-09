#pragma once

#include "../Datatypes/Vector3.h"
#include "../Datatypes/Matrix4.h"

namespace gbe {
	class Transform {
	public:
		Vector3 Right;
		Vector3 Up;
		Vector3 Forward;
		Vector3 position;
		Vector3 scale;
		Vector3 rotation;

		Matrix4 GetMatrix();
	};
}