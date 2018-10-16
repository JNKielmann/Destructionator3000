//#ifndef LaserBullet_h__
//#define LaserBullet_h__
//
//#include "Bullet.h"
//class CLaserBullet : public CBullet
//{
//public:
//	CLaserBullet(CGame& Game, sf::Vector2f SpawnPosition, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet);
//	~CLaserBullet();
//
//	virtual void Update();
//	virtual void Draw();
//
//	virtual void OnDerstroy();
//
//	virtual sf::Vector2f GetPosition() const
//	{
//		return m_Laser.GetPosition();
//	}
//	virtual sf::FloatRect GetBoundingBox() const
//	{
//		//return sf::FloatRect(m_Laser.get, m_Laser.GetPosition().y, m_Laser.GetPosition().x + m_Laser.getw)
//		return sf::FloatRect(1,1,1,1);
//	}
//	virtual float GetDamage()
//	{
//		return 1.0;
//	}
//protected:
//	//sf::Sprite m_BulletSprite;
//	sf::Shape m_Laser;
//};
//#endif // LaserBullet_h__