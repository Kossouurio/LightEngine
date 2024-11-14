#pragma once
#include "Entity.h"
#include "Gun.h"

class Plante : public Entity
{
public:
	enum State
	{
		Idle,
		Shooting,
		Reloading,

		StateCount
	};
	static const int STATE_COUNT = (int)State::StateCount;

private:
	State mState = State::Idle;

	int mTransitions[STATE_COUNT][STATE_COUNT] =
	{
		// Idle, Shooting, Reloading
		{  0,    1,     1}, // Idle
		{  1,    0,     1}, // Shooting
		{  1,    0,     0}, // Reloading
	};

	int mHealth;
	int mDamage;
	int mAmmo = 2;
	bool mIsReloading = false;
	bool mIsShooting = false;
	float mReloadTime = 4.5f;
	float mShootTime = 2.0f;
	float mReloadProgress = 0.0f;
	float mShootProgress = 0.0f;

public:
	Plante(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
		mHealth = 3;
		mDamage = 1;
	}

	void OnCollision(Entity* other) override;

	void OnUpdate() override;

	int GetDamage() const;

	void Shoot();
	void Reload();
	bool TransitionTo(State newState);
};
