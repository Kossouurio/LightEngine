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
		mReloadProgress = 0.0f;
		mShootProgress = 0.0f;
		break;

	case Plante::Shooting:
		mShootProgress += 0.1f;
		if (mShootProgress >= mShootTime)
		{
			mIsShooting = true;
			mShootProgress = 0.0f;
			std::cout << "Shooting..." << std::endl;
			Shoot();
		}
		break;

	case Plante::Reloading:
		mReloadProgress += 0.1f;
		if (mReloadProgress >= mReloadTime)
		{
			mIsReloading = true;
			mReloadProgress = 0.0f;
			std::cout << "Reloading..." << std::endl;
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
		mAmmo -= 1;

		// Créer un Gun et le positionner
		Gun* gun = GetScene()->CreateEntity<Gun>(25, sf::Color::Blue);
		gun->SetPosition(GetPosition().x, GetPosition().y);
		gun->SetTag(14);
	}
	else
	{
		TransitionTo(Plante::Reloading);
	}
}

void Plante::Reload()
{
	mAmmo = 2;
	TransitionTo(Plante::Idle);
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
