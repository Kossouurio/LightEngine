#include "Zombie.h"
#include <iostream>
#include "Plante.h"
#include "Gun.h"

void Zombie::OnCollision(Entity* other)
{
	//std::cout << "Zombie::OnCollision(Plante*)" << std::endl;

	if (other->IsTag(33))
	{
		SetSpeed(0.0f);
	}

	if (other->IsTag(14))
	{
		Gun* ptm = dynamic_cast<Gun*>(other);
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

	SetDirection(-1.0f, 0, 100.0f);
}

int Zombie::GetDamage() const
{
	return mDamage;
}

