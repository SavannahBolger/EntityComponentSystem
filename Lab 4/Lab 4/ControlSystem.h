#pragma once
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"
#include "InputComponent.h"

class ControlSystem
{
	std::vector<Entity> entities;
public:
	ControlSystem() {};
	~ControlSystem() {};
	void addEntity(Entity e) { entities.push_back(e); }
	void update()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			sf::Vector2f position = entities[i].m_playerSprite.getPosition();
			//right key press
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				position.x += 0.1;
				std::cout << "Right Update" << std::endl;
			}
			//left key press
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				position.x -= 0.1;
				std::cout << "Left Update" << std::endl;
			}

			//up key press
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				position.y -= 0.1;
				std::cout << "Up Update" << std::endl;
			}

			//down key press
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				position.y += 0.1;
				std::cout << "Down Update" << std::endl;
			}

			//if the player is outside the boundaries of the window
			if (position.x >= 1000)
			{
				position = sf::Vector2f(0 - entities[i].m_playerSprite.getSize().x, position.y);
			}
			else if (position.x <= 0)
			{
				position = sf::Vector2f(1000, position.y);
			}

			if (position.y >= 1000)
			{
				position = sf::Vector2f(position.x, 0 - entities[i].m_playerSprite.getSize().y);
			}
			else if (position.y <= 0)
			{
				position = sf::Vector2f(position.y, 1000);
			}
			entities[i].m_playerSprite.setPosition(position);
		}
		std::cout << "ControlSystem Update" << std::endl;
	}
};
