#include "Enemy.h"
#include "NormalWeaponSystem.h"

class CCargoShip : public CEnemy
{
public:
	CCargoShip(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager);
	~CCargoShip();

	virtual void Update(sf::Vector2f PlayerPosition);

	virtual float GetBoundingSphereRadius()
	{
		return 83;
	}
	virtual float GetDamageOnDestroy()
	{
		return 80.0f;
	}
	unsigned int GetPoints()
	{
		return 250;
	}
protected:
	virtual void DestroyedImp();
};