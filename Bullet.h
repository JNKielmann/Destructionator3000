#ifndef Bullet_h__
#define Bullet_h__

#include "Game.h"
#include "Vektor2d.h"

class CBullet
{
public:
	CBullet(CGame& Game, CMathVektor2d<float> Direction, float MoveSpeed, bool PlayerBullet) : m_Game(Game), m_Direction(Direction.normalize()), m_MoveSpeed(MoveSpeed), m_PlayerBullet(PlayerBullet)
	{}
	virtual ~CBullet(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void OnDerstroy() = 0;

	sf::Vector2f GetDirection() const
	{
		return m_Direction;
	}
	void SetDirection(sf::Vector2f Direction)
	{
		m_Direction = Direction;
	}
	
	virtual sf::Vector2f GetPosition() const = 0;
	virtual sf::FloatRect GetBoundingBox() const = 0;

	// Gibt zur wie viel Schaden bei Kollision verursacht wird
	virtual float GetDamage() = 0;

	bool IsPlayerBullet()
	{
		return m_PlayerBullet;
	}

protected:
	CGame& m_Game;
	sf::Vector2f m_Direction;
	const float m_MoveSpeed;
	bool m_PlayerBullet;
};

#endif // Bullet_h__
