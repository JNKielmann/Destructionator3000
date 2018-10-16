#include "ExplosionManager.h"
#include "EnemyManager.h"
#include "Game.h"
#include <sstream>


CExplosionManager::CExplosionManager(CGame& Game, CEnemyManager& EnemyManager) : m_Game(Game), m_EnemyManager(EnemyManager)
{
	for(int i = 0; i < m_NumExplosionSounds; ++i)
	{
		std::stringstream StringStream;
		StringStream << "Data/explode" << i << ".wav";
		m_ExplosionSounds[i].SetBuffer(*m_Game.GetSoundBufferManager().GetResource(StringStream.str()));
		m_ExplosionSounds[i].SetVolume(70);
	}
}

CExplosionManager::~CExplosionManager()
{
	for(std::list<CExplosion*>::iterator It = m_ExplosionList.begin(); It != m_ExplosionList.end(); ++It)
	{
		delete *It;
	}
	m_ExplosionList.clear();
}
void CExplosionManager::Update()
{
	for(std::list<CExplosion*>::iterator It = m_ExplosionList.begin(); It != m_ExplosionList.end(); ++It)
	{
		if(!(*It)->Update())
		{
			delete *It;
			It = m_ExplosionList.erase(It);
			if (It == m_ExplosionList.end())
			{
				break;
			}
		}
	}
}

void CExplosionManager::Draw()
{
	std::for_each(m_ExplosionList.begin(), m_ExplosionList.end(), std::mem_fun(&CExplosion::Draw));
}
void CExplosionManager::AddExplosion( sf::Vector2f Position, sf::Vector2f Size)
{
	m_ExplosionSounds[sf::Randomizer::Random(0,3)].Play();
	m_ExplosionList.push_back(new CExplosion(m_Game, Position, "Data/Explosion.png", 6, 6, 1.0f/20.0f, sf::Vector2i(49, 46), Size));
	m_EnemyManager.ExplosionDamage(Position, Size.x / 2, 40);
}






