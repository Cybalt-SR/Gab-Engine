#include "RigidObject.h"

gbe::RigidObject::RigidObject() {
	this->mass = 1;
	this->frame_force = Vector3::zero;
	this->velocity = Vector3(0, 0, 0);
	this->acceleration = Vector3(0, 0, 0);
}

gbe::RigidObject::~RigidObject()
{
}


void gbe::RigidObject::AddForce(Vector3 force)
{
	this->frame_force += force;
}

float gbe::RigidObject::MomentOfInertia()
{
	float final = 0.0f;

	for (auto col : colliders)
	{
		final += ((float)2 / 5) * mass * (col->GetWorldRadius() * col->GetWorldRadius());
	}

	return final;
}

void gbe::RigidObject::AddForceAtPoint(Vector3 force, Vector3 relativeWorldPoint)
{
	this->AddForce(force);
	this->accumulatedTorque = relativeWorldPoint.Cross(force);
}

void gbe::RigidObject::OnEnterHierarchy(Object* newChild)
{
	Object::OnEnterHierarchy(newChild);

	auto col = dynamic_cast<Collider*>(newChild);

	if (col == nullptr)
		return;

	this->colliders.push_back(col);
}