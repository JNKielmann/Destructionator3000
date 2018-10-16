#ifndef Explosion_h__
#define Explosion_h__
#include <SFML/Graphics.hpp>

class CGame;

class CExplosion
{
public:
	CExplosion(CGame& Game, sf::Vector2f Position, const std::string& ImageName, int FrameNum, int FramesPerRow, float TimePerFrame, sf::Vector2i FrameSize, sf::Vector2f ExplosionSize);

	// Gibt false zurück wenn die Explosionanimation zuende ist
	bool Update();
	void Draw();

private:
	sf::RenderWindow& m_Window;
	sf::Sprite m_ExplosionSprite;
	sf::Clock m_AnimationTimer;
	int m_CurrentFrame;
	bool m_Dead;
	int m_FrameNum;
	int m_FramesPerRow;
	float m_TimePerFrame;
	sf::Vector2i m_FrameSize;
};

#endif // Explosion_h__