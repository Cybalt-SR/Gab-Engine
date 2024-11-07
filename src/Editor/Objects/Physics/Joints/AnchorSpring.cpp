#include "AnchorSpring.h"


void gde::AnchorSpring::InvokeUpdate(float deltatime)
{
	if (to_rbody == nullptr) return;

	Vector3 pos = to_rbody->World()->position;

	Vector3 force = pos - this->World()->position;
	float mag = force.Magnitude();
	float springForce_mag = -springConst * abs(mag - this->restLen);

	auto force_dir = force * (1.0f / mag);
	auto spring_force = force_dir * springForce_mag;

	to_rbody->AddForce(spring_force);
	if (this->this_rbody != nullptr) this->this_rbody->AddForce(-spring_force);
}

void gde::AnchorSpring::SetParent(Object* newParent)
{
	Object::SetParent(newParent);

	this->this_rbody = nullptr;

	while (newParent != nullptr)
	{
		auto rigid_parent = dynamic_cast<RigidObject*>(newParent);

		if (rigid_parent == nullptr) {
			newParent = newParent->GetParent();
			continue;
		}

		this->this_rbody = rigid_parent;
		break;
	}
}
