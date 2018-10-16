#include "PowerUpManager.h"
#include "Game.h"

CPowerUpManager::CPowerUpManager(CGame& Game, sf::RenderWindow& Window, CPlayer& Player ) : m_Game(Game), m_Window(Window), m_Player(Player)
{
	m_PowerUpParams[0] = SPowerUpParameters(&LivePowerUp, Game.GetImageManager().GetResource("Data/health_powerup.png"));
	m_PowerUpParams[1] = SPowerUpParameters(&FullEnergyPowerUp, Game.GetImageManager().GetResource("Data/energy_powerup.png"));
	m_PowerUpParams[2] = SPowerUpParameters(&AddRocketPowerUp, Game.GetImageManager().GetResource("Data/Pickup_rocket.png"));
	m_PowerUpParams[3] = SPowerUpParameters(&AddPlasmaPowerUp, Game.GetImageManager().GetResource("Data/Pickup_plasma.png"));
	m_PowerUpParams[4] = SPowerUpParameters(&AddMinigunPowerUp, Game.GetImageManager().GetResource("Data/Pickup_blast.png"));
}

CPowerUpManager::~CPowerUpManager()
{
	for(std::list<CPowerUp*>::iterator It = m_PowerUps.begin(); It != m_PowerUps.end(); ++It)
	{
		delete *It;
	}
	m_PowerUps.clear();
}

void CPowerUpManager::Update()
{
	for(std::list<CPowerUp*>::iterator It = m_PowerUps.begin(); It != m_PowerUps.end(); ++It)
	{
		if (!(*It)->Update())
		{
			delete *It;
			It = m_PowerUps.erase(It);
			if (It == m_PowerUps.end())
			{
				break;
			}
		}
	}
}

void CPowerUpManager::Draw()
{
	std::for_each(m_PowerUps.begin(), m_PowerUps.end(), std::mem_fun(&CPowerUp::Draw));
}

void CPowerUpManager::AddPowerUp(sf::Vector2f Position, CPowerUp::CollisionFunction OnCollision, sf::Image* Image)
{
	m_PowerUps.push_back(new CPowerUp(Position, m_Window, OnCollision, Image, m_Player));
}

void CPowerUpManager::AddRandomPowerUp(sf::Vector2f Position)
{
	int Random = sf::Randomizer::Random(0, m_NumPowerUps-1);
	m_PowerUps.push_back(new CPowerUp(Position, m_Window, m_PowerUpParams[Random].m_Function, m_PowerUpParams[Random].m_Image, m_Player));
}

