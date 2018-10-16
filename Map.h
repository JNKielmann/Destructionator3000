#ifndef Map_h__
#define Map_h__
#include <SFML/Graphics.hpp>

class CGame;

class CMap
{
public:
	CMap(CGame& Game);

	void Update();

	void Draw();

private:
	CGame& m_Game;

	sf::Sprite m_Background1;
};
#endif // Map_h__