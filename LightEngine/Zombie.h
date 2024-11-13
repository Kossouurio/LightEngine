#pragma once
#include "Entity.h"

class Zombie: public Entity
{
public:
	Zombie(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
		mHealth = 4;
		mDamage = 444;
	}

	void OnCollision(Entity* other) override;

	void OnUpdate() override;

	int GetDamage() const;

private:
	int mHealth;
	int mDamage;
};
