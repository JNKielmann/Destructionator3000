#ifndef WeaponSystem_h__
#define WeaponSystem_h__
#include <SFML/Graphics.hpp>

class CBulletManager;
class CGame;

class CWeaponSystem
{
public:
	CWeaponSystem(CGame& Game, CBulletManager& BulletManager, float ShootsPerSek, bool PlayerWeapon) 
		: m_Game(Game),
		m_BulletManager(BulletManager),
		m_TimeBetweenShoots(1/ShootsPerSek),
		m_PlayerWeapon(PlayerWeapon),
		m_Level(1)
	{}

	bool TryToShoot(sf::Vector2f Position, sf::Vector2f Direction)
	{
		if(m_ShootTimer.GetElapsedTime() >= GetTimeBetweenShoots())
		{
			Shoot(Position, Direction);
			m_ShootTimer.Reset();
			return true;
		}
		return false;
	}

	int GetWeaponLevel()
	{
		return m_Level;
	}

	void NextWeaponLevel()
	{
		if (m_Level < GetMaxLevel())
		{
			++m_Level;
		}		
	}

	void ResetLevel()
	{
		m_Level = 1;
	}

	virtual float GetEnegriePerShoot() = 0;

protected:
	virtual void Shoot(sf::Vector2f Position, sf::Vector2f Direction) = 0;

	virtual float GetTimeBetweenShoots()
	{
		return m_TimeBetweenShoots;
	}

	virtual int GetMaxLevel() = 0;
protected:
	CGame& m_Game;

	CBulletManager& m_BulletManager;

	float m_TimeBetweenShoots;

	sf::Clock m_ShootTimer;

	bool m_PlayerWeapon;

	// Das Level der Waffe
	int m_Level;
};
#endif // WeaponSystem_h__