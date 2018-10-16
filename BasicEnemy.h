#ifndef BasicEnemy_h__
#define BasicEnemy_h__

#include "Enemy.h"
#include "NormalWeaponSystem.h"

class CBasicEnemy : public CEnemy
{
public:
	CBasicEnemy(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager);
	~CBasicEnemy();

	virtual void Update(sf::Vector2f PlayerPosition);
	
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
		return 50;
	}
protected:
	virtual void DestroyedImp();

protected:
	CNormalWeaponSystem m_WeaponSystem;
};

#endif // BasicEnemy_h__
