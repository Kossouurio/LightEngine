#include <iostream>
#include "Gun.h"
#include "Zombie.h"

void Gun::OnCollision(Entity* other)
{
	if (other->IsTag(7))
	{
		Zombie* ptm = dynamic_cast<Zombie*>(other);

		mHealth -= ptm->GetDamage();
		if (mHealth <= 0)
		{
			Destroy();
		}
	}
}

void Gun::OnUpdate()
{
	SetDirection(1.0f, 0, 100.0f);
}

int Gun::GetDamage() const
{
	return mDamage;
}
