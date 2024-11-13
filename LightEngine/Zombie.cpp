#include "Zombie.h"
#include <iostream>
#include "Plante.h"

void Zombie::OnCollision(Entity* other)
{
	std::cout << "Zombie::OnCollision(Plante*)" << std::endl;

	if (other->IsTag(33))
	{
		Plante* ptm = dynamic_cast<Plante*>(other);

		mHealth -= ptm->GetDamage();
		if (mHealth <= 0)
		{
			Destroy();
		}
	}
}

void Zombie::OnUpdate()
{
	//std::cout << "Zombie::OnUpdate" << std::endl;

	SetDirection(-1.0f, 0, 60.0f);
}

int Zombie::GetDamage() const
{
	return mDamage;
}

