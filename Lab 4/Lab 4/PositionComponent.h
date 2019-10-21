#pragma once
#include <iostream>
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : position(10,10) {};
	sf::Vector2f getPosition() { return position; }
	void setPosition(sf::Vector2f position) { this->position = position; }
private:
	sf::Vector2f position;
};