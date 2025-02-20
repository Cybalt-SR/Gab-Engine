#include "TPCameraController.h"

#include "Engine/Input/Action/MouseDelta.h"
#include "Engine/Input/KeyDefines.h"

namespace gbe {
	void TPCameraController::Set_pivot(Object* other)
	{
		this->pivot = other;
	}
	TPCameraController::TPCameraController()
	{
		auto mousedelta = new InputCustomer<MouseDelta>([this](MouseDelta* value, bool changed) {
			if (value->state != MouseDelta::WHILE)
				return;

			Vector2 drag_delta = (Vector2)value->delta;
			drag_delta *= 0.5f;

			this->orbital_rotation.x -= drag_delta.x;
			this->orbital_rotation.y += drag_delta.y;
			if (this->orbital_rotation.y < -70)
				this->orbital_rotation.y = -70;
			if (this->orbital_rotation.y > 70)
				this->orbital_rotation.y = 70;

			this->pivot->Local().rotation.Set(Quaternion::Euler(Vector3(orbital_rotation.y, orbital_rotation.x, 0)));
			});

		this->inputreceivers.push_back(mousedelta);
	}
}