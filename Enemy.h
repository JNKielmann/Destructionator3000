#ifndef Enemy_h__
#define Enemy_h__

#include <sfml/Graphics.hpp>
#include "PowerUpManager.h"
class CBulletManager;
class CGame;
class CExplosionManager;

class CEnemy
{
public:
	CEnemy(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f Position, float Live, const std::string& ImageName, CPowerUpManager& PowerUpManager);
	virtual ~CEnemy();


	virtual void Update(sf::Vector2f PlayerPosition) = 0;
	virtual void Draw();

	virtual float GetDamageOnDestroy() = 0;

	sf::Vector2f GetPosition()
	{
		return m_Sprite.GetPosition();
	}

	virtual sf::FloatRect GetBoundingBox()
	{
		return sf::FloatRect(m_Sprite.GetPosition().x - m_Sprite.GetSize().x/2, m_Sprite.GetPosition().y - m_Sprite.GetSize().y/2, m_Sprite.GetPosition().x + m_Sprite.GetSize().x/2, m_Sprite.GetPosition().y + m_Sprite.GetSize().y/2);
	}

	virtual float GetBoundingSphereRadius() = 0;

	virtual unsigned int GetPoints() = 0;

	void Damage(float Damage)
	{
		m_Life -= Damage;
	}

	bool IsDead()
	{
		return m_Life <= 0;
	}

protected:
	void Destroyed()
	{
		if (IsDead())
		{
			DestroyedImp();
		}
	}
	virtual void DestroyedImp() = 0;

protected:
	sf::Sprite m_Sprite;

	CGame& m_Game;

	CExplosionManager& m_ExplosionManager;

	CPowerUpManager& m_PowerUpManager;

	float m_Life;
};
#endif // Enemy_h__

