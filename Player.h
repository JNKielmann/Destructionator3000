#ifndef Player_h__
#define Player_h__

#include "NormalWeaponSystem.h"
#include "Bar.h"
#include "PlasmaWeaponSystem.h"
#include "RocketWeaponSystem.h"
#include "Shield.h"

class CBullet;
class CBulletManager;
class CGame;
class CEnemyManager;
class CExplosionManager;

class CPlayer
{
public:
	enum EPlayerWeapons
	{
		WEAPON_MINIGUN,
		WEAPON_PLASMAGUN,
		WEAPON_ROCKETLAUNCHER,

		NUM_PLAYER_WEAPONS
	};
public:
	CPlayer(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager);
	~CPlayer();

	void Init();

	void Update(CEnemyManager& EnemyManager);
	void Draw();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f Position)
	{
		m_PlayerSprite.SetPosition(Position);
	}
	sf::FloatRect GetBoundingBox()
	{
		if (IsDead())
		{
			return sf::FloatRect(0,0,0,0);
		}
		else
		{
			return sf::FloatRect(m_PlayerSprite.GetPosition().x - m_PlayerSprite.GetSize().x/2, m_PlayerSprite.GetPosition().y - m_PlayerSprite.GetSize().y/2, m_PlayerSprite.GetPosition().x + m_PlayerSprite.GetSize().x/2, m_PlayerSprite.GetPosition().y + m_PlayerSprite.GetSize().y/2); 
		}
	}

	bool TestCollisionWithBullet(CBullet& Bullet);

	void AddLife(float Live)
	{
		m_Life += Live;
		if (m_Life > 100)
		{
			m_Life = 100;
		}
		m_LifeBar.SetValue(m_Life);
	}
	void SetEnergyToMax()
	{
		m_Energy = 360;
	}

	float GetRadius()
	{
		if (IsDead())
		{
			return 0;
		}
		else
		{
			return 59.5;
		}
		
	}
	bool IsDead()
	{
		return m_Life <= 0;
	}
	void Damage(float Damage);

	void NextWeapon();
	void PreviousWeapon();
	void SetWeapon(int Index);
	void AddWeapon(EPlayerWeapons Weapon);

	void AddPoints(unsigned int Points)
	{
		m_Points += Points;
	}
	unsigned int GetPoints()
	{
		return m_Points;
	}
private:
	void UpdateWeaponCursor();

private:
 	sf::Sprite m_PlayerSprite;
	
 	CGame& m_Game;

	CExplosionManager& m_ExplosionManager;
	CBulletManager& m_BulletManager;

 	sf::Vector2f m_MoveVector;
	
	CWeaponSystem* m_Weapons[NUM_PLAYER_WEAPONS];
	int m_CurrentWeapon;
	
	CBar m_LifeBar;
	CBar m_EnergyBar;

	CShield m_PlayerShield;

	float m_Life;
	float m_Energy;

	sf::Sprite m_WeaponBar;
	sf::Sprite m_WeaponCursor;
	sf::String m_MinigunWeaponLevel;
	sf::String m_PlasmaWeaponLevel;
	sf::String m_RocketWeaponLevel;

	unsigned int m_Points;
	sf::String m_PointsText;
};
#endif // Player_h__

