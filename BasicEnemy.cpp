#include "BasicEnemy.h"
#include "Game.h"



CBasicEnemy::CBasicEnemy(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager) : CEnemy(Game, ExplosionManager, Position, 50, "Data/BasicEnemy.png", PowerUpManager), m_WeaponSystem(Game,BulletManager, 1, false)
{
	m_WeaponSystem.NextWeaponLevel();
}


CBasicEnemy::~CBasicEnemy(void)
{
	Destroyed();
}

void CBasicEnemy::Update(sf::Vector2f PlayerPosition)
{
	m_Sprite.Move(0,100 * m_Game.GetWindow().GetFrameTime());
	m_WeaponSystem.TryToShoot(m_Sprite.GetPosition(), sf::Vector2f(0,1));	
}

void CBasicEnemy::DestroyedImp()
{
	m_ExplosionManager.AddExplosion(GetPosition(), sf::Vector2f(100, 100));
}

