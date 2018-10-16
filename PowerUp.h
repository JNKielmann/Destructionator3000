#ifndef PowerUp_h__
#define PowerUp_h__

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <functional>

class CPowerUp
{
public:
	typedef std::tr1::function<void (CPlayer&)> CollisionFunction;

	CPowerUp(sf::Vector2f Position, sf::RenderWindow& Window, CollisionFunction OnCollision, sf::Image* Image, CPlayer& Player);

	bool Update();
	void Draw();

private:
	sf::RenderWindow& m_Window;
	sf::Sprite m_PowerUpSprite;
	CPlayer& m_Player;
	CollisionFunction m_OnCollision;
};

void LivePowerUp(CPlayer& Player);
void FullEnergyPowerUp(CPlayer& Player);

void AddRocketPowerUp(CPlayer& Player);
void AddPlasmaPowerUp(CPlayer& Player);
void AddMinigunPowerUp(CPlayer& Player);

#endif // PowerUp_h__