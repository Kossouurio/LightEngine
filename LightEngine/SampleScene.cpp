#include <iostream>
#include "SampleScene.h"
#include "DummyEntity.h"
#include "Zombie.h"
#include "Plante.h"
#include "Gun.h"

#include "Debug.h"


std::vector<Zombie*>* SampleScene::GetZombies1()
{
	return &Zombies1;
}

std::vector<Zombie*>* SampleScene::GetZombies2()
{
	return &Zombies2;
}

std::vector<Zombie*>* SampleScene::GetZombies3()
{
	return &Zombies3;
}

void SampleScene::Initialize()
{
	pEntity1 = CreateEntity<Plante>(75, sf::Color::Green);
	pEntity1->SetPosition(100, (GetWindowHeight() / 3) / 2);
	pEntity1->SetTag(33);

	pEntity2 = CreateEntity<Plante>(75, sf::Color::Green);
	pEntity2->SetPosition(100, (GetWindowHeight() / 3 * 2) - (GetWindowHeight() / 3) / 2);
	pEntity2->SetTag(33);

	pEntity3 = CreateEntity<Plante>(75, sf::Color::Green);
	pEntity3->SetPosition(100, GetWindowHeight() - (GetWindowHeight() / 3) / 2);
	pEntity3->SetTag(33);	
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		if (event.mouseButton.y < (GetWindowHeight() / 3))
		{
			Zombies1.push_back(CreateEntity<Zombie>(50, sf::Color::Red));
			Zombies1.back()->SetPosition(GetWindowWidth(), (GetWindowHeight() / 3) / 2);
			Zombies1.back()->SetTag(7);
		}
		else if (event.mouseButton.y > (GetWindowHeight() / 3) * 2)
		{
			Zombies3.push_back(CreateEntity<Zombie>(50, sf::Color::Red));
			Zombies3.back()->SetPosition(GetWindowWidth(), (GetWindowHeight() - (GetWindowHeight() / 3) / 2));
			Zombies3.back()->SetTag(7);
		}
		else
		{
			Zombies2.push_back(CreateEntity<Zombie>(50, sf::Color::Red));
			Zombies2.back()->SetPosition(GetWindowWidth(), (GetWindowHeight() / 3 * 2) - (GetWindowHeight() / 3) / 2);
			Zombies2.back()->SetTag(7);
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (event.mouseButton.y < (GetWindowHeight() / 3))
		{
			mGun = CreateEntity<Gun>(25, sf::Color::Blue);
			mGun->SetPosition(100, (GetWindowHeight() / 3) / 2);
			mGun->SetTag(14);

		}
		else if (event.mouseButton.y > (GetWindowHeight() / 3) * 2)
		{
			mGun = CreateEntity<Gun>(25, sf::Color::Blue);
			mGun->SetPosition(100, (GetWindowHeight() - (GetWindowHeight() / 3) / 2));
			mGun->SetTag(14);
		}
		else
		{
			mGun = CreateEntity<Gun>(25, sf::Color::Blue);
			mGun->SetPosition(100, ((GetWindowHeight() / 3 * 2) - (GetWindowHeight() / 3) / 2));
			mGun->SetTag(14);
		}
	}
}

void SampleScene::Update()
{
	Debug::DrawLine(0, GetWindowHeight() / 3, GetWindowWidth(), GetWindowHeight() / 3, sf::Color::White);
	Debug::DrawLine(0, GetWindowHeight() / 3 * 2, GetWindowWidth(), GetWindowHeight() / 3 * 2, sf::Color::White);

	if (Zombies1.size() > 0)
	{
		pEntity1->TransitionTo(Plante::Shooting);
	}
	else
	{
		pEntity1->TransitionTo(Plante::Idle);
	}

	if (Zombies2.size() > 0)
	{
		pEntity2->TransitionTo(Plante::Shooting);
	}
	else
	{
		pEntity2->TransitionTo(Plante::Idle);
	}

	if (Zombies3.size() > 0)
	{
		pEntity3->TransitionTo(Plante::Shooting);
	}
	else
	{
		pEntity3->TransitionTo(Plante::Idle);
	}
}