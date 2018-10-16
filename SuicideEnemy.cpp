#include "SuicideEnemy.h"
#include "BasicEnemy.h"
#include "Game.h"
#include "Vektor2d.h"


CSuicideEnemy::CSuicideEnemy(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, CPowerUpManager& PowerUpManager) : CEnemy(Game, ExplosionManager, Position, 30, "Data/Drone.png", PowerUpManager)
{
	m_FastMode = false;
}


CSuicideEnemy::~CSuicideEnemy(void)
{
	Destroyed();
}

void CSuicideEnemy::Update( sf::Vector2f PlayerPosition )
{
	CMathVektor2d<float> Temp = PlayerPosition - m_Sprite.GetPosition();
	if(Temp.getLength() < 350)
		m_FastMode = true;
	if(m_FastMode)
	{		
		Temp.normalize();
		m_Sprite.Move(Temp.X * m_Game.GetWindow().GetFrameTime() * 500 ,700 * m_Game.GetWindow().GetFrameTime());
	}
	else
	{
		Temp.normalize();
		m_Sprite.Move(Temp.X * m_Game.GetWindow().GetFrameTime() * 400,80 * m_Game.GetWindow().GetFrameTime());
	}
	
}

void CSuicideEnemy::DestroyedImp()
{
	m_ExplosionManager.AddExplosion(GetPosition(), sf::Vector2f(100, 100));
}
