#ifndef EnemyManager_h__
#define EnemyManager_h__
#include <list>
#include <deque>
#include <sfml/Graphics.hpp>

class CEnemy;
class CGame;
class CBullet;
class CBulletManager;
class CPlayer;
class CExplosionManager;
class CPowerUpManager;

class CEnemyManager
{
public:
	CEnemyManager(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, CPowerUpManager& PowerUpManager,  CPlayer& Player);
	~CEnemyManager();

	void Update(sf::Vector2f PlayerPosition);
	void Draw();

	void LoadEnemyFromFile(const std::string& FileName);

	void ExplosionDamage(sf::Vector2f Position, float Radius, float Damage);

	bool TestCollisionWithBullet(CBullet& Bullet);
	void TestCollisionWithPlayer();

	void ResetTimer()
	{
		m_Timer.Reset();
	}

	bool EnemysLeft()
	{
		return !m_EnemyList.empty() || !m_NextEnemys.empty();
	}

private:
	enum EEnemyTypes
	{
		ENEMY_NORMAL = 0,
		ENEMY_SUICIDE,
		ENEMY_STEALTH,
		ENEMY_CARGO
	};
	struct SEnemyInfo
	{
		int EnemyType;
		float PositionX;
		float PositionY;
		int SpawnTime;
	};
private:
	std::list<CEnemy*> m_EnemyList;
	CGame& m_Game;
	CBulletManager& m_BulletManager;
	CExplosionManager& m_ExplosionManager;
	CPowerUpManager& m_PowerUpManager;
	CPlayer& m_Player;

	// Warteschlange der Gegner die noch erstellt werden
	std::deque<SEnemyInfo> m_NextEnemys;
	sf::Clock m_Timer;
};
#endif // EnemyManager_h__