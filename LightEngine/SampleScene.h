#pragma once

#include "Scene.h"

class DummyEntity;
class Zombie;
class Plante;

class SampleScene : public Scene
{
	Plante* pEntity1;
	Plante* pEntity2;
	Plante* pEntity3;

private:
	

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


