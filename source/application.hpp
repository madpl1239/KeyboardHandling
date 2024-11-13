/*
 * application.hpp 
 * 
 * 02-11-2022 by madpl
 */
#pragma once

#include <SFML/Graphics.hpp>
#include "defs.hpp"


class CApp final
{
public:
	explicit CApp()
	{
		m_win.create(sf::VideoMode(WIDTH, HEIGHT, 32), "", sf::Style::Default);
		m_win.setTitle("SFML Window");
		m_win.setPosition(sf::Vector2i(700, 200));
		m_win.setKeyRepeatEnabled(false);
		
		std::cout << "CApp::ctor\n";
	}
	
	~CApp()
	{
		if(m_win.isOpen())
			m_win.close();
		
		memset(&m_event, 0, sizeof(sf::Event));
		
		std::cout << "CApp::dtor\n";
	}
	
	void draw(void)
	{
		m_win.clear(sf::Color(BLACK));
		m_win.display();
	}
	
	sf::Event& getEvent()
	{
		return m_event;
	}
	
	sf::RenderWindow& getWin()
	{
		return m_win;
	}
	
private:
	sf::RenderWindow m_win;
	sf::Event m_event;
};

inline CApp app{};
