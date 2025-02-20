#include "ForceVolume.h"

#include <iostream>

void gbe::ForceVolume::TryApply(RigidObject* object)
{
	Vector3 delta = object->World().position.Get() - this->World().position.Get();

	if (this->shape == SPHERE)
		if (delta.SqrMagnitude() > this->radius * this->radius)
			return;
	if (this->shape == BOX) {
		if (abs(delta.x) > this->half_bounds.x)
			return;
		if (abs(delta.y) > this->half_bounds.y)
			return;
	}

	auto final_dir = Vector3::zero;

	if (this->mode == DIRECTIONAL)
		final_dir = this->vector;

	auto final_force = final_dir;

	if (this->forceMode == VELOCITY)
		final_force *= object->GetRigidbody()->Get_mass();

	object->GetRigidbody()->AddForce(final_force);
}
