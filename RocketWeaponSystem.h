#ifndef RocketWeaponSystem_h__
#define RocketWeaponSystem_h__

#include "WeaponSystem.h"

class CExplosionManager;

class CRocketWeaponSystem :	public CWeaponSystem
{
public:
	CRocketWeaponSystem(CGame& Game, CExplosionManager& ExplosionManager, CBulletManager& BulletManager, float ShootsPerSek,  bool PlayerWeapon);
	~CRocketWeaponSystem();

	virtual float GetEnegriePerShoot()
	{
		switch(m_Level)
		{
		case 1:
			return 50;
			break;
		case 2:
			return 50;
			break;
		case 3:
			return 70;
			break;
		case 4:
			return 70;
			break;
		default:
			return 0;
			break;
		}
	}
	float GetTimeBetweenShoots()
	{
		if (m_Level == 2 || m_Level == 4)
		{
			return m_TimeBetweenShoots - 0.02f;
		}
		return m_TimeBetweenShoots;
		return m_TimeBetweenShoots;
	}
protected:
	CGame& m_Game;
	CExplosionManager& m_ExplosionManager;
	virtual void Shoot(sf::Vector2f Position, sf::Vector2f Direction);

	virtual int GetMaxLevel()
	{
		return 4;
	}

};
#endif // RocketWeaponSystem_h__