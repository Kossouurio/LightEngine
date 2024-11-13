#pragma once
#include "Entity.h"

class Plante : public Entity
{
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

private:
	int mHealth;
	int mDamage;
};
