#include "Enemy.h"

class CSuicideEnemy :
	public CEnemy
{
public:
	CSuicideEnemy(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager);
	~CSuicideEnemy(void);

	virtual void Update(sf::Vector2f PlayerPosition);

	virtual float GetBoundingSphereRadius()
	{
		return 48.0;
	}
	virtual float GetDamageOnDestroy()
	{
		return 40.0f;
	}

	unsigned int GetPoints()
	{
		return 40;
	}

protected:
	virtual void DestroyedImp();
	bool m_FastMode;
};

