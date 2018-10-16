#include "Map.h"
#include "Game.h"


CMap::CMap(CGame& Game) : m_Game(Game)
{
	static sf::Image BackgroundImage;
	BackgroundImage.LoadFromFile("Data/StarBackground.jpg");
	m_Background1.SetImage(BackgroundImage);
	m_Background1.SetPosition(0, -600);
}

void CMap::Update()
{
	m_Background1.Move(0,300 * m_Game.GetWindow().GetFrameTime());
}

void CMap::Draw()
{
	m_Game.GetWindow().Draw(m_Background1);
	if (m_Background1.GetPosition().y > 0)
	{
		sf::Vector2f OldPosition(m_Background1.GetPosition());
		m_Background1.SetPosition(0,-1200 + OldPosition.y);
		m_Game.GetWindow().Draw(m_Background1);
		if (OldPosition.y < 800)
		{
			m_Background1.SetPosition(OldPosition);
		}
	}
}