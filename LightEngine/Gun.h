#pragma once
#include "Entity.h"

class Gun : public Entity
{
public:
	Gun(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
		mHealth = 1;
		mDamage = 1;
	}

	void OnCollision(Entity* other) override;

	void OnUpdate() override;

	int GetDamage() const;

private:
	int mDamage;
	int mHealth;
};