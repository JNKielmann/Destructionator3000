#include "Player.h"
#include "Vektor2d.h"
#include "Game.h"
#include "Bullet.h"
#include "PlasmaWeaponSystem.h"
#include <sstream>


CPlayer::CPlayer(CGame& Game, CBulletManager& BulletManager, CExplosionManager& ExplosionManager)
	: m_Game(Game),
	m_ExplosionManager(ExplosionManager),
	m_BulletManager(BulletManager),
	m_WeaponBar(*m_Game.GetImageManager().GetResource("Data/WeaponBar.png"), sf::Vector2f(10, 500)),
	m_WeaponCursor(*m_Game.GetImageManager().GetResource("Data/Auswahl.png"), sf::Vector2f(10, 519)),
	m_MinigunWeaponLevel("1", sf::Font::GetDefaultFont(), 20.0f),
	m_PlasmaWeaponLevel("--", sf::Font::GetDefaultFont(), 20.0f),
	m_RocketWeaponLevel("--", sf::Font::GetDefaultFont(), 20.0f),
	m_PointsText("")
{
	m_PointsText.SetPosition(sf::Vector2f(550,10));
	static sf::Image PlayerImage;
	m_PlayerSprite.SetImage(*Game.GetImageManager().GetResource("Data/PlayerShip.png"));
	m_PlayerSprite.SetCenter(m_PlayerSprite.GetSize().x / 2, m_PlayerSprite.GetSize().y / 2);

	m_Life = 100;
	m_Energy = 360;
	m_LifeBar.Init ("Data/bar_d.png", "Data/bar_live_a.png", sf::Vector2f (10.0f, 20.0f), m_Life, m_Life);
	m_EnergyBar.Init ("Data/bar_d.png", "Data/bar_energy_a.png", sf::Vector2f (10.0f, 50.0f), m_Energy, m_Energy);

	for(int i = 0; i < NUM_PLAYER_WEAPONS; ++i)
	{
		m_Weapons[i] = NULL;
	}
	m_Weapons[0] = new CNormalWeaponSystem(Game, BulletManager, 7, true);
	m_CurrentWeapon = 0;

	m_MinigunWeaponLevel.SetPosition(sf::Vector2f(m_WeaponBar.GetPosition() + sf::Vector2f(30,40)));
	m_MinigunWeaponLevel.SetColor(sf::Color(255,0,0));
	m_MinigunWeaponLevel.SetStyle(sf::String::Bold);

	m_PlasmaWeaponLevel.SetPosition(sf::Vector2f(m_WeaponBar.GetPosition() + sf::Vector2f(81,40)));
	m_PlasmaWeaponLevel.SetColor(sf::Color(255,0,0));
	m_PlasmaWeaponLevel.SetStyle(sf::String::Bold);

	m_RocketWeaponLevel.SetPosition(sf::Vector2f(m_WeaponBar.GetPosition() + sf::Vector2f(132,40)));
	m_RocketWeaponLevel.SetColor(sf::Color(255,0,0));
	m_RocketWeaponLevel.SetStyle(sf::String::Bold);
}


CPlayer::~CPlayer(void)
{
	for(int i = 0; i < NUM_PLAYER_WEAPONS; ++i)
	{
		if(m_Weapons[i])
		{
			delete m_Weapons[i];
		}
	}
}

void CPlayer::Init()
{
	m_Life = 100;
	m_Energy = 360;
	m_LifeBar.SetValue(m_Life);
	m_EnergyBar.SetValue(m_Energy);
	m_Weapons[0]->ResetLevel();
	for(int i = 1; i < NUM_PLAYER_WEAPONS; ++i)
	{
		if(m_Weapons[i])
		{
			delete m_Weapons[i];
		}
		m_Weapons[i] = NULL;
	}
	m_CurrentWeapon = 0;
	m_MinigunWeaponLevel.SetText("1");
	m_PlasmaWeaponLevel.SetText("--");
	m_RocketWeaponLevel.SetText("--");
	m_PlayerShield.Reset();
	m_Points = 0;
	m_PointsText.SetText("Punkte: 0");
	m_WeaponCursor.SetPosition(sf::Vector2f(10, 519));
}

void CPlayer::Update(CEnemyManager& EnemyManager)
{
	sf::RenderWindow& Window = m_Game.GetWindow();
	if (Window.GetInput().IsMouseButtonDown(sf::Mouse::Left) && m_Energy >= m_Weapons[m_CurrentWeapon]->GetEnegriePerShoot())
	{
		if (m_Weapons[m_CurrentWeapon]->TryToShoot(m_PlayerSprite.GetPosition() + sf::Vector2f(0, -m_PlayerSprite.GetSize().y / 2),sf::Vector2f(0,-1)))
		{
			m_Energy -= m_Weapons[m_CurrentWeapon]->GetEnegriePerShoot();

			if (m_Energy < 0)
			{
				m_Energy = 0;
			}
		}
	}
	m_Energy += 20.0f * Window.GetFrameTime();
	if(m_Energy > 360)
	{
		m_Energy = 360;
	}
	m_EnergyBar.SetValue(m_Energy);

	CMathVektor2d<float> ConnectionVector = sf::Vector2f(static_cast<float>(Window.GetInput().GetMouseX()), static_cast<float>(Window.GetInput().GetMouseY())) - m_PlayerSprite.GetPosition();
	float MoveSpeed = ConnectionVector.getLength() * 6 ;
	ConnectionVector.normalize();

	m_PlayerSprite.Move(ConnectionVector * MoveSpeed * Window.GetFrameTime());
	EnemyManager.TestCollisionWithPlayer();

	m_PlayerShield.Update (m_PlayerSprite.GetPosition(), m_Game.GetWindow().GetFrameTime());

	std::stringstream StringStream;
	StringStream << "Punkte: " << m_Points;
	m_PointsText.SetText(StringStream.str());
}

void CPlayer::Draw()
{
	m_Game.GetWindow().Draw(m_PlayerSprite);
	m_PlayerShield.Render (m_Game.GetWindow());
	m_LifeBar.Render (m_Game.GetWindow());
	m_EnergyBar.Render (m_Game.GetWindow());
	m_Game.GetWindow().Draw(m_WeaponBar);
	m_Game.GetWindow().Draw(m_WeaponCursor);
	m_Game.GetWindow().Draw(m_MinigunWeaponLevel);
	m_Game.GetWindow().Draw(m_PlasmaWeaponLevel);
	m_Game.GetWindow().Draw(m_RocketWeaponLevel);
	m_Game.GetWindow().Draw(m_PointsText);
	
}

sf::Vector2f CPlayer::GetPosition()
{
	if (IsDead())
	{
		return sf::Vector2f(static_cast<float>(m_Game.GetWindow().GetInput().GetMouseX()), static_cast<float>(m_Game.GetWindow().GetInput().GetMouseY()));
	}
	else
	{
		return m_PlayerSprite.GetPosition();
	}
}

bool CPlayer::TestCollisionWithBullet( CBullet& Bullet )
{
	if (Bullet.GetBoundingBox().Intersects(GetBoundingBox()))
	{
		Damage(m_PlayerShield.GetAbsoluteDamage (Bullet.GetDamage()));
		return true;
	}
	return false;
}

void CPlayer::NextWeapon()
{
	do 
	{
		++m_CurrentWeapon;
		if (m_CurrentWeapon > NUM_PLAYER_WEAPONS-1)
		{
			m_CurrentWeapon = 0;
		}
	} 
	while(m_Weapons[m_CurrentWeapon] == NULL);
	UpdateWeaponCursor();
}

void CPlayer::PreviousWeapon()
{
	do 
	{
		--m_CurrentWeapon;
		if (m_CurrentWeapon < 0)
		{
			m_CurrentWeapon = NUM_PLAYER_WEAPONS-1;
		}
	} 
	while(m_Weapons[m_CurrentWeapon] == NULL);
	UpdateWeaponCursor();
}

void CPlayer::SetWeapon( int Index )
{
	if (Index < NUM_PLAYER_WEAPONS-1 && Index >= 0 && m_Weapons[Index] != NULL)
	{
		m_CurrentWeapon = Index;
		UpdateWeaponCursor();
	}
	
}

void CPlayer::AddWeapon( EPlayerWeapons Weapon )
{
	if (m_Weapons[Weapon] == NULL)
	{
		switch(Weapon)
		{
		case WEAPON_ROCKETLAUNCHER:
			m_Weapons[Weapon] = new CRocketWeaponSystem(m_Game, m_ExplosionManager, m_BulletManager, 1, true);
			break;
		case  WEAPON_MINIGUN:
			m_Weapons[Weapon] = new CNormalWeaponSystem(m_Game, m_BulletManager, 5, true);
			break;
		case  WEAPON_PLASMAGUN:
			m_Weapons[Weapon] = new CPlasmaWeaponSystem(m_Game, m_BulletManager, 3, true);
			break;
		default:
			return;
		}
	}
	else
	{
		m_Weapons[Weapon]->NextWeaponLevel();
	}
	m_CurrentWeapon = Weapon;
	UpdateWeaponCursor();
	char Buffer[5];
	m_MinigunWeaponLevel.SetText(_itoa(m_Weapons[0]->GetWeaponLevel(), Buffer, 10));
	if (m_Weapons[1])
	{
		m_PlasmaWeaponLevel.SetText(_itoa(m_Weapons[1]->GetWeaponLevel(), Buffer, 10));
	}
	if (m_Weapons[2])
	{
		m_RocketWeaponLevel.SetText(_itoa(m_Weapons[2]->GetWeaponLevel(), Buffer, 10));
	}
	
}

void CPlayer::UpdateWeaponCursor()
{
	m_WeaponCursor.SetPosition(51.0f * m_CurrentWeapon + 10.0f, 519.0f);
}

void CPlayer::Damage( float Damage )
{
	m_Life -= m_PlayerShield.GetAbsoluteDamage(Damage);
	m_LifeBar.SetValue (m_Life);
	if (IsDead())
	{
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition(), sf::Vector2f(150, 150));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(60,0), sf::Vector2f(50, 50));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(-60,0), sf::Vector2f(100, 100));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(0, 60), sf::Vector2f(70, 70));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(0, -60), sf::Vector2f(110, 110));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(60, 60), sf::Vector2f(80, 80));
		m_ExplosionManager.AddExplosion(m_PlayerSprite.GetPosition() + sf::Vector2f(-60, -60), sf::Vector2f(120, 120));
	}
}
