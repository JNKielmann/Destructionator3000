#ifndef BigRocket_h__
#define BigRocket_h__

class CExplosionManager;

#include "Bullet.h"
class CBigRocket : public CBullet
{
public:
	CBigRocket(CGame& Game, CExplosionManager& ExplosionManager, sf::Vector2f SpawnPosition, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet);
	~CBigRocket();

	virtual void Update();
	virtual void Draw();

	virtual void OnDerstroy();

	virtual sf::Vector2f GetPosition() const
	{
		return m_BulletSprite.GetPosition();
	}
	virtual sf::FloatRect GetBoundingBox() const
	{
		return sf::FloatRect(m_BulletSprite.GetPosition().x - m_BulletSprite.GetSize().x/2, m_BulletSprite.GetPosition().y - m_BulletSprite.GetSize().y/2, m_BulletSprite.GetPosition().x + m_BulletSprite.GetSize().x/2, m_BulletSprite.GetPosition().y + m_BulletSprite.GetSize().y/2);
	}
	virtual float GetDamage()
	{
		// Hauptschaden wird durch die Explosion verursacht!
		return 0.0;
	}
protected:
	CExplosionManager& m_ExplosionManager;
	sf::Sprite m_BulletSprite;
	sf::Clock m_Timer;
	static bool m_LeftStatic;
	bool m_Left;
};
#endif // BigRocket_h__