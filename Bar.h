// bars.h
//
// copyright DeyDoo Itec
//
#ifndef BARS_H
#define BARS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

using namespace std;

class CBar
{
public:
	void Init (string D_Bar, string A_Bar, sf::Vector2f Position, float fMaximalValue, float fStartValue);

	void SetValue (float fNewValue);
	
	void SetPosition (sf::Vector2f NewPosition);

	void Render (sf::RenderWindow &Window);

private:	
	sf::Image ShowedBarI;
	sf::Image BackgroundBarI;
	
	sf::Sprite m_BackgroundBar;
	sf::Sprite m_ShowedBar;

	float m_fMaximalValue;
	float m_fCurrentValue;
};

#endif