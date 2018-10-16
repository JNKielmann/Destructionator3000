#include "BigRocket.h"
#include <math.h>
#include "ExplosionManager.h"

CBigRocket::CBigRocket( CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f SpawnPosition, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet ) 
	: CBullet(Game, Direction, MoveSpeed, PlayerBullet),
	m_ExplosionManager(ExplosionManager)
{
	m_BulletSprite.SetImage(*m_Game.GetImageManager().GetResource("Data/Rocket.png"));
	m_BulletSprite.SetCenter(m_BulletSprite.GetSize().x / 2, m_BulletSprite.GetSize().y / 2);
	m_BulletSprite.SetPosition(SpawnPosition);
	float Rotation = CMathVektor2d<float>(0,-1).dotProduct(m_Direction);
	Rotation = static_cast<float>(acos (Rotation) * 180.0 / 3.1415926535898);
	if (m_Direction.x < 0)
	{
		Rotation = 360.0f - Rotation;
	}
	m_BulletSprite.SetRotation(Rotation);
	m_LeftStatic = !m_LeftStatic;
	m_Left = m_LeftStatic;
}

CBigRocket::~CBigRocket()
{

}
void CBigRocket::Update()
{
	if (m_Timer.GetElapsedTime() < 0.5)
	{
		if (m_Left)
		{
			m_BulletSprite.Move(-100 * m_Game.GetWindow().GetFrameTime(), 0);
		}
		else
		{
			m_BulletSprite.Move(100 * m_Game.GetWindow().GetFrameTime(), 0);
		}		
	}
	else
	{
		m_BulletSprite.Move(m_Direction * m_MoveSpeed * m_Game.GetWindow().GetFrameTime());
	}
}

void CBigRocket::Draw()
{
	m_Game.GetWindow().Draw(m_BulletSprite);
}

void CBigRocket::OnDerstroy()
{
	m_ExplosionManager.AddExplosion(m_BulletSprite.GetPosition(), sf::Vector2f(200, 200));
}

bool CBigRocket::m_LeftStatic = false;


