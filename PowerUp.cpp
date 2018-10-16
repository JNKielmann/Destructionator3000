#include "PowerUp.h"
#include "Vektor2d.h"

CPowerUp::CPowerUp(sf::Vector2f Position, sf::RenderWindow& Window, CollisionFunction OnCollision, sf::Image* Image, CPlayer& Player) : m_Window(Window), m_Player(Player), m_OnCollision(OnCollision)
{
	m_PowerUpSprite.SetImage(*Image);
	m_PowerUpSprite.SetCenter(m_PowerUpSprite.GetSize() / 2.0f);
	m_PowerUpSprite.SetPosition(Position);
}

bool CPowerUp::Update()
{
	m_PowerUpSprite.Move(0, 150 * m_Window.GetFrameTime());
	if (CMathVektor2d<float>(m_PowerUpSprite.GetPosition() - m_Player.GetPosition()).getLength() < 50 + m_Player.GetRadius())
	{
		m_OnCollision(m_Player);
		return false;
	}
	return true;
}

void CPowerUp::Draw()
{
	m_Window.Draw(m_PowerUpSprite);
}




// Funktionen

void LivePowerUp(CPlayer& Player)
{
	Player.AddLife(20);
}

void FullEnergyPowerUp(CPlayer& Player)
{
	Player.SetEnergyToMax();
}

void AddRocketPowerUp( CPlayer& Player )
{
	Player.AddWeapon(CPlayer::WEAPON_ROCKETLAUNCHER);
}

void AddPlasmaPowerUp( CPlayer& Player )
{
	Player.AddWeapon(CPlayer::WEAPON_PLASMAGUN);
}

void AddMinigunPowerUp( CPlayer& Player )
{
	Player.AddWeapon(CPlayer::WEAPON_MINIGUN);
}

