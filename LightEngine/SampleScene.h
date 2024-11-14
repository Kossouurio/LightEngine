#pragma once

#include <vector>
#include "Scene.h"

class DummyEntity;
class Zombie;
class Plante;
class Gun;

class SampleScene : public Scene
{
	Plante* pEntity1;
	Plante* pEntity2;
	Plante* pEntity3;

	Zombie* pZombie;

	Gun* mGun;

	std::vector<Zombie*> Zombies1;
	std::vector<Zombie*> Zombies2;
	std::vector<Zombie*> Zombies3;

private:
	

public:
	std::vector<Zombie*>* GetZombies1();
	std::vector<Zombie*>* GetZombies2();
	std::vector<Zombie*>* GetZombies3();
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


