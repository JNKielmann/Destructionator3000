#ifndef PowerUpManager_h__
#define PowerUpManager_h__
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PowerUp.h"
#include <list>

class CPowerUpManager
{
public:
	CPowerUpManager(CGame& Game, sf::RenderWindow& Window, CPlayer& Player);
	~CPowerUpManager();

	void Update();
	void Draw();

	void AddPowerUp(sf::Vector2f Position, CPowerUp::CollisionFunction OnCollision, sf::Image* Image);
	void AddRandomPowerUp(sf::Vector2f Position);
private:
	struct SPowerUpParameters
	{
		SPowerUpParameters(){}
		SPowerUpParameters(CPowerUp::CollisionFunction Functoin, sf::Image* Image) : m_Function(Functoin), m_Image(Image)
		{}
		CPowerUp::CollisionFunction m_Function;
		sf::Image* m_Image;
	};
private:
	CGame& m_Game;
	CPlayer& m_Player;
	sf::RenderWindow& m_Window;
	std::list<CPowerUp*> m_PowerUps;
	static const int m_NumPowerUps = 5;
	SPowerUpParameters m_PowerUpParams[m_NumPowerUps];
};

#endif // PowerUpManager_h__