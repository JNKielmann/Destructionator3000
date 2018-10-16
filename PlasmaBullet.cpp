#include "PlasmaBullet.h"

CPlasmaBullet::CPlasmaBullet(CGame& Game, sf::Vector2f Position,  CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet)
	:CBullet(Game, Direction, MoveSpeed, PlayerBullet),
	m_Param(0)
{ 
	m_BulletSprite.SetImage(*m_Game.GetImageManager().GetResource("Data/Plasma_bullet.png"));
	m_BulletSprite.SetCenter(m_BulletSprite.GetSize().x / 2, m_BulletSprite.GetSize().y / 2);
	m_BulletSprite.SetPosition(Position);
	m_BulletSprite.SetBlendMode(sf::Blend::Add);
// 	float Rotation = CMathVektor2d<float>(0,1).dotProduct(m_Direction);
// 	Rotation = static_cast<float>(acos (Rotation) * 180.0 / 3.1415926535898);
// 	if (m_Direction.x < 0)
// 	{
// 		Rotation = 360.0f - Rotation;
// 	}
// 	m_BulletSprite.SetRotation(Rotation);
}
CPlasmaBullet::~CPlasmaBullet()
{}


void CPlasmaBullet::Update()
{
	m_Param += m_Game.GetWindow().GetFrameTime() * 20;
	m_BulletSprite.Move(Rotate(m_Direction, sin(m_Param)*30) * m_MoveSpeed * m_Game.GetWindow().GetFrameTime());
	//m_BulletSprite.Move(sin(m_Param),0);
}
void CPlasmaBullet::Draw()
{
	m_Game.GetWindow().Draw(m_BulletSprite);
}

void CPlasmaBullet::OnDerstroy()
{

}
