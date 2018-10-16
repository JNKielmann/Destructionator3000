#include "NormalWeaponSystem.h"
#include "NormalBullet.h"
#include "BulletManager.h"


CNormalWeaponSystem::CNormalWeaponSystem(CGame& Game, CBulletManager& BulletManager, float ShootsPerSek, bool PlayerWeapon) : CWeaponSystem(Game, BulletManager, ShootsPerSek, PlayerWeapon), m_Game(Game)
{
}


CNormalWeaponSystem::~CNormalWeaponSystem()
{
}

void CNormalWeaponSystem::Shoot(sf::Vector2f Position, sf::Vector2f Direction)
{
	m_Game.GetSoundBufferManager().PlaySound("Data/Shoot.wav");
	switch(m_Level)
	{
	case 1:
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position, Direction, 1000, m_PlayerWeapon));
		break;
	case 2:
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position, Direction, 1000, m_PlayerWeapon));
		break;
	case 3:
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position + sf::Vector2f(-15,0), Direction, 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position + sf::Vector2f(15,0), Direction, 1000, m_PlayerWeapon));
		break;
	case 4:
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 345), 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position, Direction, 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 15),1000, m_PlayerWeapon));
		break;
	case 5:
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 340), 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 350), 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position, Direction, 1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 10),1000, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CNormalBullet(m_Game, Position,Rotate(Direction, 20),1000, m_PlayerWeapon));
		break;
	}
	
}