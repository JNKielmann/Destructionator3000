#ifndef ExplosionManager_h__
#define ExplosionManager_h__
#include "Explosion.h"
#include <list>
#include <SFML/Audio.hpp>
class CEnemyManager;

class CExplosionManager
{
public:
	CExplosionManager(CGame& Game, CEnemyManager& EnemyManager);
	~CExplosionManager();

	void Update();
	void Draw();

	void AddExplosion(sf::Vector2f Position, sf::Vector2f Size);
private:
	CGame& m_Game;
	CEnemyManager& m_EnemyManager;
	std::list<CExplosion*> m_ExplosionList;
	static const int m_NumExplosionSounds = 4;
	sf::Sound m_ExplosionSounds[m_NumExplosionSounds];
	
};
#endif // ExplosionManager_h__