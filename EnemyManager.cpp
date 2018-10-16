#include "EnemyManager.h"
#include "BasicEnemy.h"
#include "Bullet.h"
#include "ExplosionManager.h"
#include <fstream>
#include <iostream>
#include "SuicideEnemy.h"
#include "StealthEnemy.h"
#include "CargoShip.h"


CEnemyManager::CEnemyManager(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, CPowerUpManager& PowerUpManager,  CPlayer& Player ) : m_Game(Game), m_BulletManager(BulletManager), m_ExplosionManager(ExplosionManager), m_PowerUpManager(PowerUpManager), m_Player(Player)
{
}


CEnemyManager::~CEnemyManager()
{
	for (std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end(); ++It)
	{
		delete *It;
	}
	m_EnemyList.clear();
}

void CEnemyManager::Update(sf::Vector2f PlayerPosition)
{
	// Prüfen ob neue Gegner hinzugefügt werden müssen
	if (!m_NextEnemys.empty() && m_NextEnemys.front().SpawnTime <= m_Timer.GetElapsedTime())
	{
		switch(m_NextEnemys.front().EnemyType)
		{
		case ENEMY_NORMAL:
			m_EnemyList.push_back(new CBasicEnemy(m_Game, m_BulletManager, m_ExplosionManager, sf::Vector2f(m_NextEnemys.front().PositionX, m_NextEnemys.front().PositionY), m_PowerUpManager));
			break;
		case ENEMY_SUICIDE:
			m_EnemyList.push_back(new CSuicideEnemy(m_Game, m_ExplosionManager, sf::Vector2f(m_NextEnemys.front().PositionX, m_NextEnemys.front().PositionY), m_PowerUpManager));
			break;
		case ENEMY_STEALTH:
			m_EnemyList.push_back(new CStealthEnemy(m_Game, m_BulletManager, m_ExplosionManager, sf::Vector2f(m_NextEnemys.front().PositionX, m_NextEnemys.front().PositionY), m_PowerUpManager));
			break;
		case ENEMY_CARGO:
			m_EnemyList.push_back(new CCargoShip(m_Game, m_ExplosionManager, sf::Vector2f(m_NextEnemys.front().PositionX, m_NextEnemys.front().PositionY), m_PowerUpManager));
			break;
		default:
			std::cout << "Den Gegnertyp " << m_NextEnemys.front().EnemyType << " gibt es nicht!" << std::endl;
		}
		m_NextEnemys.pop_front();
	}
	// Alle Gegner aktualisieren
	for(std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end();++It)
	{
		(*It)->Update(PlayerPosition);
		// Ist der Gegner zerstört??
		if((*It)->IsDead() || (*It)->GetPosition().y > 700)
		{	
			delete *It;
			It = m_EnemyList.erase(It);
			if (It == m_EnemyList.end())
			{
				break;
			}
		}
	}
}

void CEnemyManager::Draw()
{
	std::for_each(m_EnemyList.begin(), m_EnemyList.end(), std::mem_fun(&CEnemy::Draw));
}

bool CEnemyManager::TestCollisionWithBullet(CBullet& Bullet)
{
	bool Collision = false;
	for (std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end(); ++It)
	{
		if (Bullet.GetBoundingBox().Intersects((*It)->GetBoundingBox()))
		{
			Collision = true;
			(*It)->Damage(Bullet.GetDamage());
			if ((*It)->IsDead())
			{
				m_Player.AddPoints((*It)->GetPoints());
			}
			Bullet.OnDerstroy();
		}
	}
	return Collision;
}

void CEnemyManager::TestCollisionWithPlayer()
{
	for(std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end(); ++It)
	{
		if ((*It)->GetBoundingBox().Intersects(m_Player.GetBoundingBox()))
		{
			m_Player.Damage((*It)->GetDamageOnDestroy());
			m_Player.AddPoints((*It)->GetPoints());
			(*It)->Damage(10000); // Gegner zerstören
		}
	}
}

void CEnemyManager::LoadEnemyFromFile(const std::string& FileName)
{
	for (std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end(); ++It)
	{
		delete *It;
	}
	m_EnemyList.clear();
	m_NextEnemys.clear();

	std::ifstream File(FileName, ios::binary);
	if (!File)
	{
		exit(-1);
	}
	while(!File.eof())
	{
		SEnemyInfo EnemyInfo;
		File.read(reinterpret_cast<char*>(&EnemyInfo), sizeof(SEnemyInfo));
		m_NextEnemys.push_back(EnemyInfo);
	}
	m_NextEnemys.pop_back();
	File.close();
	m_Timer.Reset();
}

void CEnemyManager::ExplosionDamage( sf::Vector2f Position, float Radius, float Damage )
{
	for (std::list<CEnemy*>::iterator It = m_EnemyList.begin(); It != m_EnemyList.end(); ++It)
	{
		CMathVektor2d<float> Temp((*It)->GetPosition());
		if (Temp.getDistanceFrom(Position) < Radius + (*It)->GetBoundingSphereRadius())
		{
			(*It)->Damage(Damage);
			if ((*It)->IsDead())
			{
				m_Player.AddPoints((*It)->GetPoints());
			}
		}
	}
}
