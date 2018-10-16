#ifndef StealthEnemy_h__
#define StealthEnemy_h__

#include "Enemy.h"

class CStealthEnemy : public CEnemy
{
public:
	CStealthEnemy(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager);
	~CStealthEnemy();

	virtual void Update(sf::Vector2f PlayerPosition);

	virtual sf::FloatRect GetBoundingBox()
	{
		if (m_Alpha > 120)
		{
			return sf::FloatRect(m_Sprite.GetPosition().x - m_Sprite.GetSize().x/2, m_Sprite.GetPosition().y - m_Sprite.GetSize().y/2, m_Sprite.GetPosition().x + m_Sprite.GetSize().x/2, m_Sprite.GetPosition().y + m_Sprite.GetSize().y/2);
		}
		else
		{
			return sf::FloatRect(0,0,0,0);
		}
	}

	virtual float GetBoundingSphereRadius()
	{
		return 60;
	}
	virtual float GetDamageOnDestroy()
	{
		return 40.0f;
	}
	unsigned int GetPoints()
	{
		return 200;
	}
protected:
	virtual void DestroyedImp();

protected:
	CNormalWeaponSystem m_WeaponSystem;
	sf::Clock m_StealthTimer;
	bool m_StealthMode;
	float m_Alpha;
	bool m_MoveLeft;
};
#endif // StealthEnemy_h__
