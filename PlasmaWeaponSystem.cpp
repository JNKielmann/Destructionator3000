#include "PlasmaWeaponSystem.h"
#include "Game.h"
#include "PlasmaBullet.h"


CPlasmaWeaponSystem::CPlasmaWeaponSystem(CGame& Game, CBulletManager& BulletManager, float ShootsPerSek,  bool PlayerWeapon)  : CWeaponSystem(Game, BulletManager, ShootsPerSek, PlayerWeapon), m_Game(Game)
{
	if (!m_SoundLoaded)
	{
		m_PlasmaSound.SetBuffer(*m_Game.GetSoundBufferManager().GetResource("Data/Plasma.wav"));
	}
}


CPlasmaWeaponSystem::~CPlasmaWeaponSystem()
{
}

void CPlasmaWeaponSystem::Shoot( sf::Vector2f Position, sf::Vector2f Direction )
{
	m_Game.GetSoundBufferManager().PlaySound("Data/Plasma.wav");
	switch(m_Level)
	{
	case 1:
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position, Direction, 500, m_PlayerWeapon));
		break;
	case 2:
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position, Direction, 500, m_PlayerWeapon));
		break;
	case 3:
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(-15,0), Direction, 500, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(15,0), Direction, 500, m_PlayerWeapon));
		break;
	case 4:
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(-15,0), Direction, 500, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(15,0), Direction, 500, m_PlayerWeapon));
		break;
	case 5:
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(-20,0), Direction, 500, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(0,0), Direction, 400, m_PlayerWeapon));
		m_BulletManager.AddBullet(new CPlasmaBullet(m_Game, Position + sf::Vector2f(20,0), Direction, 500, m_PlayerWeapon));
		break;
	}
}

sf::Sound CPlasmaWeaponSystem::m_PlasmaSound;

bool CPlasmaWeaponSystem::m_SoundLoaded = false;
