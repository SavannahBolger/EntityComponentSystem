#pragma once
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"
#include <SFML/Graphics.hpp>

class RenderSystem
{
	std::vector<Entity> entities;
public:
	RenderSystem() {};
	~RenderSystem() {};
	void addEntity(Entity e) { entities.push_back(e); }
	void update(sf::RenderWindow &window)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i].m_playerSprite.setPosition(entities[i].m_playerSprite.getPosition());
			window.draw(entities[i].m_playerSprite);
		}
		std::cout << "RenderSystem Update" << std::endl;
	}
private:
	PositionComponent position;
};
