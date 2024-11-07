#include "ContactResolver.h"

void gde::ContactResolver::ResolveContacts(std::vector<CollisionContact*> contacts, float time)
{
	int iterations = 0;
	while (iterations < this->max_iterations)
	{
		for (auto& contact : contacts)
		{
			contact->Resolve(time);
		}

		iterations++;
	}
}