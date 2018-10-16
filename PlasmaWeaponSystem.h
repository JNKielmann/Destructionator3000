#ifndef PlasmaWeaponSystem_h__
#define PlasmaWeaponSystem_h__

#include "WeaponSystem.h"
#include <SFML/Audio.hpp>
class CPlasmaWeaponSystem : public CWeaponSystem
{
public:
	CPlasmaWeaponSystem(CGame& Game, CBulletManager& BulletManager, float ShootsPerSek,  bool PlayerWeapon);
	~CPlasmaWeaponSystem();


	virtual float GetEnegriePerShoot()
	{
		switch(m_Level)
		{
		case 1:
			return 20;
			break;
		case 2:
			return 20;
			break;
		case 3:
			return 25;
			break;
		case 4:
			return 25;
			break;
		case 5:
			return 30;
			break;
		default:
			return 0;
		}
		
	}
	float GetTimeBetweenShoots()
	{
		if (m_Level == 2 || m_Level == 4)
		{
			return m_TimeBetweenShoots - 0.04f;
		}
		return m_TimeBetweenShoots;
		return m_TimeBetweenShoots;
	}
protected:
	CGame& m_Game;
	virtual void Shoot(sf::Vector2f Position, sf::Vector2f Direction);

	virtual int GetMaxLevel()
	{
		return 5;
	}

	static sf::Sound m_PlasmaSound;
	static bool m_SoundLoaded;
};

#endif // PlasmaWeaponSystem_h__
