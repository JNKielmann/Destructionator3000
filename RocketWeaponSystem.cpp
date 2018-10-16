#include "Game.h"
#include "BigRocket.h"
#include "RocketWeaponSystem.h"


CRocketWeaponSystem::CRocketWeaponSystem(CGame& Game, CExplosionManager& ExplosionManager, CBulletManager& BulletManager, float ShootsPerSek,  bool PlayerWeapon)  : CWeaponSystem(Game, BulletManager, ShootsPerSek, PlayerWeapon), m_Game(Game), m_ExplosionManager(ExplosionManager)
{

}


CRocketWeaponSystem::~CRocketWeaponSystem()
{
}

void CRocketWeaponSystem::Shoot( sf::Vector2f Position, sf::Vector2f Direction )
{
	switch(m_Level)
	{
	case 1:
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		break;
	case 2:
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		break;
	case 3:
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		break;
	case 4:
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CBigRocket(m_Game, m_ExplosionManager, Position, Direction, 500, m_PlayerWeapon));
		break;
	}
}
