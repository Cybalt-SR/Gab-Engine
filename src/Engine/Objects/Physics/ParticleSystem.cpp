#include "ParticleSystem.h"

#include <iostream>

gbe::ParticleSystem::ParticleSystem(std::function<RigidObject* (void)> particle_function)
{
	this->particle_function = particle_function;
}

void gbe::ParticleSystem::Spawn()
{
	auto newparticle = this->particle_function();
	auto new_start_force = this->start_force.GetValue();
	newparticle->AddForce(new_start_force);

	if (this->world_space == false)
		newparticle->SetParent(this);
	if (this->world_space == true)
		newparticle->SetParent(this->parent);

	this->particles.insert_or_assign(newparticle, this->start_lifetime.GetValue());
}

void gbe::ParticleSystem::Spawn(int count)
{
	for (int i = 0; i < count; i++)
		this->Spawn();
}

void gbe::ParticleSystem::InvokeUpdate(float deltatime)
{
	this->time_last_spawned += deltatime;

	std::list<RigidObject*> toRemove;

	for (auto particle : this->particles)
	{
		particles[particle.first] -= deltatime;
		if (particles[particle.first] < 0) {
			particle.first->Destroy();
			toRemove.push_back(particle.first);
		}
	}

	for (auto removee : toRemove)
	{
		this->particles.erase(removee);
	}

	auto time_per_spawn = 1.0f / this->spawns_per_sec;

	while (this->time_last_spawned > time_per_spawn) {
		this->time_last_spawned -= time_per_spawn;
		this->Spawn();
	}
}
