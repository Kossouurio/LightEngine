#include "Plante.h"
#include <iostream>
#include "Zombie.h"

void Plante::OnCollision(Entity* other)
{
	//std::cout << "Plante::OnCollision(Zombie*)" << std::endl;

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

void Plante::OnUpdate()
{
	//std::cout << "Plante::OnUpdate" << std::endl;

	switch (mState)
	{
	case Plante::Idle:
		mIsReloading = false;
		mIsShooting = false;
		break;

	case Plante::Shooting:
		mShootProgress += 0.1f;
		if (mShootProgress >= mShootTime)
		{
			mIsShooting = false;
			mShootProgress = 0.0f;
			Shoot();
		}
		break;

	case Plante::Reloading:
		mReloadProgress += 0.1f;
		if (mReloadProgress >= mReloadTime)
		{
			mIsReloading = false;
			mReloadProgress = 0.0f;
			Reload();
		}
		break;

	case Plante::StateCount:

		break;
	default:
		break;
	}
}



int Plante::GetDamage() const
{
	return mDamage;
}

void Plante::Shoot()
{
	if (mAmmo > 0)
	{
		mIsShooting = true;
		mAmmo -= 1;
	}
	else
	{
		mIsReloading = true;
	}
}

void Plante::Reload()
{
	mIsReloading = true;
	mAmmo = 2;
}

bool Plante::TransitionTo(State newState)
{
	if (mTransitions[(int)mState][(int)newState] == 0)
	{
		return false;
	}

	mState = newState;

	return true;
}
