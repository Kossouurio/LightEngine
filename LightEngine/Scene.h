#pragma once

class GameManager;

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>

class Scene
{
private:
	GameManager* mpGameManager;

private:
	void SetGameManager(GameManager* pGameManager) { mpGameManager = pGameManager; }
	
protected:
	Scene() = default;

	virtual void Initialize() = 0;
	virtual void HandleInput(const sf::Event& event) = 0;
	virtual void Update() = 0;

public:
	template<typename T>
	T* CreateEntity(float radius, const sf::Color& color);

	int GetWindowWidth() const;
	int GetWindowHeight() const;

	friend GameManager;
};

#include "Scene.inl"