#include "CargoShip.h"
#include "BasicEnemy.h"
#include "Game.h"



CCargoShip::CCargoShip(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager) : CEnemy(Game, ExplosionManager, Position, 200, "Data/Cargo_Ship.png", PowerUpManager)
{}


CCargoShip::~CCargoShip(void)
{
	Destroyed();
}

void CCargoShip::Update( sf::Vector2f PlayerPosition )
{
	m_Sprite.Move(0,30 * m_Game.GetWindow().GetFrameTime());
}

void CCargoShip::DestroyedImp()
{
	m_ExplosionManager.AddExplosion(GetPosition() + sf::Vector2f(0,-50), sf::Vector2f(150, 150));
	m_ExplosionManager.AddExplosion(GetPosition() + sf::Vector2f(-10, 0), sf::Vector2f(150, 150));
	m_ExplosionManager.AddExplosion(GetPosition() + sf::Vector2f(15, 50), sf::Vector2f(150, 150));
	m_PowerUpManager.AddPowerUp(m_Sprite.GetPosition() - sf::Vector2f(0,40), &LivePowerUp, m_Game.GetImageManager().GetResource("Data/health_powerup.png"));
	m_PowerUpManager.AddPowerUp(m_Sprite.GetPosition() - sf::Vector2f(40,40), &FullEnergyPowerUp, m_Game.GetImageManager().GetResource("Data/energy_powerup.png"));
}
