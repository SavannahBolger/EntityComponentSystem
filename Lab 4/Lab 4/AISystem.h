#pragma once
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"
#include <SFML/Graphics.hpp>

//
class AISystem
{
	std::vector<Entity> entities;
public:
	AISystem() {};
	void addEntity(Entity e) { entities.push_back(e); }
	void update()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			sf::Vector2f position = entities[i].m_playerSprite.getPosition();
			position.x += 0.1;

			//if the player is outside the boundaries of the window
			if (position.x >= 1000)
			{
				position = sf::Vector2f(0 - entities[i].m_playerSprite.getSize().x, position.y);
			}
			else if (position.x <= 0)
			{
				position = sf::Vector2f(1000, position.y);
			}

			entities[i].m_playerSprite.setPosition(position);
		}
		std::cout << "AISystem Update" << std::endl;
	}
private:
	sf::Vector2f m_velocity;
};
