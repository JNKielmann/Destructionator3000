#ifndef RapidFire_h__
#define RapidFire_h__


#include "WeaponSystem.h"

class CNormalWeaponSystem :	public CWeaponSystem
{
public:
	CNormalWeaponSystem(CGame& Game, CBulletManager& BulletManager, float ShootsPerSek,  bool PlayerWeapon);
	~CNormalWeaponSystem();

	virtual float GetEnegriePerShoot()
	{
		switch(m_Level)
		{
		case 1:
			return 4;
			break;
		case 2:
			return 4;
			break;
		case 3:
			return 6;
			break;
		case 4:
			return 8;
			break;
		case 5:
			return 9;
			break;
		default:
			return 0;
		}
	}
	float GetTimeBetweenShoots()
	{
		if (m_Level == 2)
		{
			return m_TimeBetweenShoots - 0.035f;
		}
		return m_TimeBetweenShoots;
	}
protected:
	CGame& m_Game;
	virtual void Shoot(sf::Vector2f Position, sf::Vector2f Direction);

	virtual int GetMaxLevel()
	{
		return 5;
	}

};

#endif // RapidFire_h__
