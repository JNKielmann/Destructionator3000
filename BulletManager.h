#ifndef BulletManager_h__
#define BulletManager_h__

#include <list>
#include "EnemyManager.h"
#include "Player.h"

class CBullet;

class CBulletManager
{
public:
	typedef std::list<CBullet*> BulletList;
	CBulletManager()
	{}
	~CBulletManager();

	void Update(CEnemyManager& EnemyManager, CPlayer& Player);
	void Draw();

	void AddBullet(CBullet* Bullet);
private:
	BulletList m_Bullets;
};
#endif // BulletManager_h__