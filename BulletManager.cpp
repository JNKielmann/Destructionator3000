#include "Bullet.h"
#include "BulletManager.h"


CBulletManager::~CBulletManager()
{
	for(BulletList::iterator It = m_Bullets.begin(); It != m_Bullets.end(); ++It)
	{
		delete *It;
	}
	m_Bullets.clear();
}

void CBulletManager::Update(CEnemyManager& EnemyManager, CPlayer& Player)
{
	// Prüfen ob es Bullets gibt die auserhalbs des Fensters sind
	for(BulletList::iterator It = m_Bullets.begin(); It != m_Bullets.end();	++It)
	{
		(*It)->Update();
		sf::Vector2f Position = (*It)->GetPosition();
		if (((*It)->IsPlayerBullet() ? EnemyManager.TestCollisionWithBullet(**It) : Player.TestCollisionWithBullet(**It)) || Position.y < -50 || Position.x < -30 || Position.y > 630 || Position.x > 830)
		{
			delete *It;
			It = m_Bullets.erase(It);
			if (It == m_Bullets.end())
			{
				break;
			}
		}
	}
}

void CBulletManager::Draw()
{
	std::for_each(m_Bullets.begin(), m_Bullets.end(), std::mem_fun(&CBullet::Draw));
}

void CBulletManager::AddBullet(CBullet* Bullet)
{
		m_Bullets.push_back(Bullet);
}