#ifndef NormalBullet_h__
#define NormalBullet_h__

#include "Bullet.h"
class CNormalBullet : public CBullet
{
public:
	CNormalBullet(CGame& Game, sf::Vector2f SpawnPosition, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet);
	~CNormalBullet();

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
		return 4.0f;
	}
protected:
	sf::Sprite m_BulletSprite;
};
#endif // NormalBullet_h__