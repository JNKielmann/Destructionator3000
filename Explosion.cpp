#include "Explosion.h"
#include "Game.h"

CExplosion::CExplosion(CGame& Game, sf::Vector2f Position, const std::string& ImageName, int FrameNum, int FramesPerRow, float TimePerFrame, sf::Vector2i FrameSize, sf::Vector2f ExplosionSize)
	: m_Window(Game.GetWindow()),
	m_ExplosionSprite(*Game.GetImageManager().GetResource(ImageName)),
	m_CurrentFrame(1),
	m_FrameNum(FrameNum),
	m_TimePerFrame(TimePerFrame),
	m_FrameSize(FrameSize),
	m_FramesPerRow(FramesPerRow)
{
	float RandomSize = sf::Randomizer::Random(-10.0f, 10.0f);
	ExplosionSize += sf::Vector2f(RandomSize, RandomSize);

	m_ExplosionSprite.Scale(ExplosionSize.x / FrameSize.x, ExplosionSize.y / FrameSize.y);
	m_ExplosionSprite.SetCenter(sf::Vector2f(FrameSize.x / 2.0f, FrameSize.y / 2.0f));
	m_ExplosionSprite.SetPosition(Position);
	m_ExplosionSprite.SetSubRect(sf::IntRect(static_cast<int>((m_CurrentFrame - 1) * m_FrameSize.x), 0, static_cast<int>(m_CurrentFrame * m_FrameSize.x), static_cast<int>(m_FrameSize.y)));
	m_ExplosionSprite.SetBlendMode(sf::Blend::Add);
	float RandomRotation = sf::Randomizer::Random(0.0f, 45.0f);
	m_ExplosionSprite.Rotate(RandomRotation);
}

bool CExplosion::Update()
{
	if(m_AnimationTimer.GetElapsedTime() > m_TimePerFrame)
	{
		++m_CurrentFrame;
		if (m_CurrentFrame > m_FrameNum)
		{
			return false;
		}
		int Left = (m_CurrentFrame-1 + m_FramesPerRow) % m_FramesPerRow * m_FrameSize.x;
		int Top = m_CurrentFrame / (m_FramesPerRow+1) * m_FrameSize.y;
		m_ExplosionSprite.SetSubRect(sf::IntRect(Left, Top, Left + m_FrameSize.x, Top + m_FrameSize.y));
		m_AnimationTimer.Reset();
	}
	return true;
}

void CExplosion::Draw()
{
	m_Window.Draw(m_ExplosionSprite);
}
