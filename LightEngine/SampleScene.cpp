#include "SampleScene.h"

#include "DummyEntity.h"
#include "Zombie.h"
#include "Plante.h"

#include "Debug.h"

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
			CreateEntity<Zombie>(50, sf::Color::Red)->SetPosition(GetWindowWidth(), (GetWindowHeight() / 3) / 2);

		}
		else if (event.mouseButton.y > (GetWindowHeight() / 3) * 2)
		{
			CreateEntity<Zombie>(50, sf::Color::Red)->SetPosition(GetWindowWidth(), (GetWindowHeight() - (GetWindowHeight() / 3) / 2));
		}
		else
		{
			CreateEntity<Zombie>(50, sf::Color::Red)->SetPosition(GetWindowWidth(), (GetWindowHeight() / 3 * 2) - (GetWindowHeight() / 3) / 2);
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		
	}
}

void SampleScene::Update()
{
	Debug::DrawLine(0, GetWindowHeight() / 3, GetWindowWidth(), GetWindowHeight() / 3, sf::Color::White);
	Debug::DrawLine(0, GetWindowHeight() / 3 * 2, GetWindowWidth(), GetWindowHeight() / 3 * 2, sf::Color::White);
}