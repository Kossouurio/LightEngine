#include "Plante.h"
#include <iostream>
#include "Zombie.h"

void Plante::OnCollision(Entity* other)
{
	std::cout << "Plante::OnCollision(Zombie*)" << std::endl;

	if (other->IsTag(33))
	{
		Zombie* ptm = dynamic_cast<Zombie*>(other);

		mHealth -= ptm->GetDamage();
		if (mHealth <= 0)
		{
			Destroy();
		}
	}
}

void Plante::OnUpdate()
{
	//std::cout << "Plante::OnUpdate" << std::endl;
}

int Plante::GetDamage() const
{
	return mDamage;
}
