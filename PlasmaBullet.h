#ifndef PlasmaBullet_h__
#define PlasmaBullet_h__

#include "Bullet.h"

class CPlasmaBullet : public CBullet
{
public:
	CPlasmaBullet(CGame& Game, sf::Vector2f SpawnPosition, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet);
	~CPlasmaBullet();

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
		return 15.0f;
	}
protected:
	sf::Sprite m_BulletSprite;

	float m_Param;
};
#endif // PlasmaBullet_h__