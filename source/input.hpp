/*
 * input.hpp
 * 
 * Simple keyboard handling.
 * 
 * 02-11-2022 by madpl
 */
#pragma once


class CKeyboard final
{
public:
	explicit CKeyboard()
	{
		clearKbd();
	}
	
	~CKeyboard()
	{
		clearKbd();
	}
	
	void bindKbd(int button, std::function<void(void)> f)
	{
		m_funcKeyb[button] = f;
	}
	
	void monitorKbd(sf::Event& e)
	{
		if(e.type == sf::Event::KeyPressed)
			m_mapKeyb[e.key.code] = true;
	}

	void handleKbd(void)
	{
		for(auto& [button, func] : m_funcKeyb)
			if(m_mapKeyb[button])
			{
				m_mapKeyb[button] = false;
				func();
			}
	}

private:
	void clearKbd()
	{
		if(not m_mapKeyb.empty())
			m_mapKeyb.clear();
	
		if(not m_funcKeyb.empty())
			m_funcKeyb.clear();
	}
	
	std::map<int, bool> m_mapKeyb{};
	std::map<int, std::function<void(void)>> m_funcKeyb{};
};

inline CKeyboard keyboard{};
