#include "NormalBullet.h"
#include <math.h>


CNormalBullet::CNormalBullet(CGame& Game, sf::Vector2f SpawnPosition,  CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet)
	:CBullet(Game, Direction, MoveSpeed, PlayerBullet)
{ 
	m_BulletSprite.SetImage(*m_Game.GetImageManager().GetResource("Data/Bullet.png"));
	m_BulletSprite.SetCenter(m_BulletSprite.GetSize().x / 2, m_BulletSprite.GetSize().y / 2);
	m_BulletSprite.SetPosition(SpawnPosition);
	float Rotation = 0;
	if (m_PlayerBullet)
	{
		Rotation = CMathVektor2d<float>(0,-1).dotProduct(m_Direction);
		Rotation = static_cast<float>(acos (Rotation) * 180.0 / 3.1415926535898);
		if (m_Direction.x > 0)
		{
			Rotation = 360.0f - Rotation;
		}
	}
	else
	{
		Rotation = CMathVektor2d<float>(0,1).dotProduct(m_Direction);
		Rotation = static_cast<float>(acos (Rotation) * 180.0 / 3.1415926535898);
		if (m_Direction.x < 0)
		{
			Rotation = 360.0f - Rotation;
		}
	}	
	m_BulletSprite.SetRotation(Rotation);
}
CNormalBullet::~CNormalBullet()
{}

void CNormalBullet::Update()
{
	m_BulletSprite.Move(m_Direction * m_MoveSpeed * m_Game.GetWindow().GetFrameTime());
}
void CNormalBullet::Draw()
{
	m_Game.GetWindow().Draw(m_BulletSprite);
}

void CNormalBullet::OnDerstroy()
{

}
