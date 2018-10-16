#include "StealthEnemy.h"
#include "Game.h"



CStealthEnemy::CStealthEnemy(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager) : CEnemy(Game, ExplosionManager, Position, 100, "Data/Stealth_Ship.png", PowerUpManager), m_WeaponSystem(Game,BulletManager, 1.5, false)
{
	m_StealthMode = true;
	m_MoveLeft = true;
	m_Alpha = 70.0f;
}


CStealthEnemy::~CStealthEnemy(void)
{
	Destroyed();
}

void CStealthEnemy::Update(sf::Vector2f PlayerPosition)
{
	if (m_MoveLeft)
	{
		m_Sprite.Move(-50 * m_Game.GetWindow().GetFrameTime(), 20 * m_Game.GetWindow().GetFrameTime());
	}
	else
	{
		m_Sprite.Move(50 * m_Game.GetWindow().GetFrameTime(), 20 * m_Game.GetWindow().GetFrameTime());
	}
	if(m_Sprite.GetPosition().x <= 0)
	{
		m_Sprite.SetPosition(0 ,m_Sprite.GetPosition().y);
		m_MoveLeft = !m_MoveLeft;
	}
	if(m_Sprite.GetPosition().x >= 800)
	{
		m_Sprite.SetPosition(800 ,m_Sprite.GetPosition().y);
		m_MoveLeft = !m_MoveLeft;
	}
	if (m_StealthMode)
	{
		if (m_StealthTimer.GetElapsedTime() >= 4)
		{
			m_StealthMode = !m_StealthMode;
			m_StealthTimer.Reset();
		}

		if (m_Alpha> 70)
		{
			m_Alpha -= 100 * m_Game.GetWindow().GetFrameTime();
			if (m_Alpha < 70)
			{
				m_Alpha = 70;
			}
		}
	}
	else
	{
		if (m_StealthTimer.GetElapsedTime() >= 2)
		{
			m_StealthMode = !m_StealthMode;
			m_StealthTimer.Reset();
		}
		if (m_Alpha != 255)
		{
			m_Alpha += 200 * m_Game.GetWindow().GetFrameTime();
			if (m_Alpha > 255)
			{
				m_Alpha = 255;
			}
		}
		else
		{
			sf::Vector2f Direction(PlayerPosition - m_Sprite.GetPosition());
			if (Direction.y > 0)
			{
				m_WeaponSystem.TryToShoot(m_Sprite.GetPosition(), Direction);
			}
		}
	}
	m_Sprite.SetColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(m_Alpha)));
}

void CStealthEnemy::DestroyedImp()
{
	m_ExplosionManager.AddExplosion(GetPosition(), sf::Vector2f(100, 100));
}

