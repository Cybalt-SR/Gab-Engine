#include "AnchorSpring.h"


void gbe::AnchorSpring::InvokeUpdate(float deltatime)
{
	if (to_rbody == nullptr) return;

	Vector3 pos = to_rbody->World().position.Get();

	Vector3 force = pos - this->World().position.Get();
	float mag = force.Magnitude();
	float springForce_mag = -springConst * abs(mag - this->restLen);

	auto force_dir = force * (1.0f / mag);
	Vector3 spring_force = force_dir * springForce_mag;

	to_rbody->body.AddForce(spring_force);
	if (this->this_rbody != nullptr) this->this_rbody->body.AddForce((physics::PhysicsVector3) - spring_force);
}

void gbe::AnchorSpring::SetParent(Object* newParent)
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
