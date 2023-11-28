/*
 * main.cpp
 * 
 * Keyboard and mouse support using std::map.
 * 
 * 02-11-2022 by madpl
 */
#include <cstring>
#include <iostream>
#include <map>
#include <functional>
#include "application.hpp"
#include "input.hpp"

bool quit = false;


void funcW(void)
{
	std::cout << "pressed key W\n";
}


void funcS(void)
{
	std::cout << "pressed key S\n";
}


void funcA()
{
	std::cout << "pressed key A\n";
}


void funcD()
{
	std::cout << "pressed key D\n";
}


void funcP()
{
	std::cout << "pressed key P\n";
}


void funcSpace()
{
	std::cout << "pressed key Space\n";
}


void funcQuit()
{
	quit = true;
}


int main(void)
{
	keyboard.bindKbd(sf::Keyboard::W, funcW);
	keyboard.bindKbd(sf::Keyboard::S, funcS);
	keyboard.bindKbd(sf::Keyboard::A, funcA);
	keyboard.bindKbd(sf::Keyboard::D, funcD);
	keyboard.bindKbd(sf::Keyboard::P, funcP);
	keyboard.bindKbd(sf::Keyboard::Space, funcSpace);
	keyboard.bindKbd(sf::Keyboard::Q, funcQuit);
	
	while(not quit)
	{
		while(app.getWin().pollEvent(app.getEvent()))
		{
			if(app.getEvent().type == sf::Event::Closed)
				quit = true;
			
			keyboard.monitorKbd(app.getEvent());
			keyboard.handleKbd();
		}
		
		app.draw();
	}
	
	return 0;
}
