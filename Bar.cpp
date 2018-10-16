#include "Bar.h"

void CBar::Init (string D_Bar, string A_Bar, sf::Vector2f Position, float fMaximalValue, float fStartValue)
{
	BackgroundBarI.LoadFromFile (D_Bar);
	ShowedBarI.LoadFromFile (A_Bar);

	m_BackgroundBar.SetImage (BackgroundBarI);
	m_ShowedBar.SetImage (ShowedBarI);

	m_fMaximalValue = fMaximalValue;
	m_fCurrentValue = fStartValue;

	m_BackgroundBar.SetPosition (Position);
	m_ShowedBar.SetPosition (Position);
}

void CBar::SetValue (float fNewValue)
{
	m_fCurrentValue = fNewValue;

	int width = static_cast <int> ((m_fCurrentValue * BackgroundBarI.GetWidth()) / m_fMaximalValue);

	sf::IntRect BarSubRect (0, 0, width, BackgroundBarI.GetHeight());
	m_ShowedBar.SetSubRect (BarSubRect);
}

void CBar::Render (sf::RenderWindow &Window)
{
	Window.Draw (m_BackgroundBar);
	Window.Draw (m_ShowedBar);
}

void CBar::SetPosition (sf::Vector2f NewPosition)
{
	m_BackgroundBar.SetPosition (NewPosition);
	m_ShowedBar.SetPosition (NewPosition);
}