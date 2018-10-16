#include "Enemy.h"
#include "Game.h"


CEnemy::CEnemy(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, float Live, const std::string& ImageName, CPowerUpManager& PowerUpManager) : m_Game(Game), m_Life(Live), m_ExplosionManager(ExplosionManager), m_PowerUpManager(PowerUpManager)
{
	m_Sprite.SetImage(*m_Game.GetImageManager().GetResource(ImageName));
	m_Sprite.SetCenter(m_Sprite.GetSize() / 2.0f);
	m_Sprite.SetPosition(Position);
	m_Sprite.Rotate(180.0f);
}


CEnemy::~CEnemy(void)
{
	// ist der gegner tot und nicht durch kollision mit dem spieler gestorben?
	if (IsDead() && m_Life > -3000)
	{
		if (sf::Randomizer::Random(0, 100) <= 35)
		{
			m_PowerUpManager.AddRandomPowerUp(m_Sprite.GetPosition());
		}
	}
}

void CEnemy::Draw()
{
	m_Game.GetWindow().Draw(m_Sprite);
}

