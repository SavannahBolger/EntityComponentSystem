/// <summary>
/// Entity Component System
/// @author: Savannah Bolger
/// @date: 10/10/2019
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "InputComponent.h"
#include "HealthSystem.h"
#include "AISystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"

int main(void*)
{
	//create window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lab 1!!");
	Entity player("player");	//player entity
	Entity alien("alien");		//alien entity
	Entity dog("dog");			//dog entity
	Entity cat("cat");			//cat entity
	HealthComponent hc;			//health component
	PositionComponent pc;		//position component
	InputComponent ic;			//input component
	HealthSystem hs;			//health system
	RenderSystem rs;			//render system
	AISystem as;				//ai system
	ControlSystem cs;			//control system

	//setup player component system
	player.addComponent(hc);
	player.addComponent(pc);
	player.addComponent(ic);
	hs.addEntity(player);
	cs.addEntity(player);
	rs.addEntity(player);

	//setup alien component system
	alien.addComponent(hc);
	alien.addComponent(pc);
	hs.addEntity(alien);
	as.addEntity(alien);
	rs.addEntity(alien);

	//setup dog component system
	dog.addComponent(hc);
	dog.addComponent(pc);
	hs.addEntity(dog);
	as.addEntity(dog);
	rs.addEntity(dog);

	//setup cat component system
	cat.addComponent(pc);
	as.addEntity(cat);
	rs.addEntity(cat);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (sf::Event::Closed == event.type) // window message
				{
					window.close();
				}
			}
			//clear message screen
			system("cls");
			timeSinceLastUpdate -= timePerFrame;
			//update systems
			hs.update();
			as.update();
			cs.update();
		}
		window.clear(sf::Color::Black);
		rs.update(window);
		window.display();
	}

	return 0;
}