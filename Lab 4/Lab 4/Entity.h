#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.h"

class Entity
{
public:
	Entity(std::string tag) 
	{
		if (tag == "player")
		{
			m_playerSprite.setSize(sf::Vector2f(100, 100));
			m_playerSprite.setFillColor(sf::Color::Blue);
			m_playerSprite.setPosition(/*getComponents<PositionComponent>().position*/100, 100);
		}
		else if (tag == "alien")
		{
			m_playerSprite.setSize(sf::Vector2f(100, 100));
			m_playerSprite.setFillColor(sf::Color::Green);
			m_playerSprite.setPosition(/*getComponents<PositionComponent>().position*/200, 200);
		}
		else if (tag == "dog")
		{
			m_playerSprite.setSize(sf::Vector2f(100, 100));
			m_playerSprite.setFillColor(sf::Color::Red);
			m_playerSprite.setPosition(/*getComponents<PositionComponent>().position*/300, 300);
		}
		else if (tag == "cat")
		{
			m_playerSprite.setSize(sf::Vector2f(100, 100));
			m_playerSprite.setFillColor(sf::Color::Magenta);
			m_playerSprite.setPosition(/*getComponents<PositionComponent>().position*/400, 400);
		}
	}
	~Entity() {}
	void addComponent(Component c) { components.push_back(c); }
	void removeComponent(Component c) { /* TBI */ }
	std::vector<Component> getComponents() { return components;  }
	sf::RectangleShape m_playerSprite; 
private:
	std::vector<Component> components;
};
