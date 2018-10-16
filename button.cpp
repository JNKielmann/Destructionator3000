#include "Button.h"

CButton::CButton (const std::string &Text, sf::Vector2f Position, bool hidden, const sf::Font &FontToUse, sf::RenderWindow *Window, sf::Image *ButtonImage)
{
	// Text initialisieren
	m_Text.SetFont (FontToUse);
	m_Text.SetText (Text);
	m_Text.SetPosition (Position.x + 10, Position.y + 5);
	m_Text.SetSize (40);

	// Button-Sprite initialisieren
	m_ButtonSprite.SetImage (*ButtonImage);
	m_ButtonSprite.SetPosition (Position);

	// Setzen, ob der Button Sichtbar ist
	m_Hidden = hidden;

	// Zeiger auf das Render-Window speichern
	m_Window = Window;

	// Das KollisionsRect initialisieren
	m_CollisionRect.Left = Position.x;
	m_CollisionRect.Top = Position.y;
	m_CollisionRect.Right = Position.x + m_ButtonSprite.GetImage()->GetWidth();
	m_CollisionRect.Bottom = Position.y + m_ButtonSprite.GetImage()->GetHeight();

	m_MouseButtonDown = false;
} 


bool CButton::IsClicked()
{
	// Wenn der Button nicht deaktiviert ist
	if (m_Hidden == false && m_MouseButtonDown == false)
	{
		// Befindet sich die Maus im Rect?
		if (m_CollisionRect.Contains (static_cast <float> (m_Window->GetInput().GetMouseX()), static_cast <float> (m_Window->GetInput().GetMouseY())))
		{
			// Ist die Maus gedrückt?
			if (m_Window->GetInput().IsMouseButtonDown(sf::Mouse::Left))
			{
					return true;
			}
		}
	}

	return (false);
}


void CButton::SetHidden (bool NewHidden)
{
	m_Hidden = NewHidden;
}

void CButton::Update ()
{
	// Beim hovern über den Button
	if (m_CollisionRect.Contains (static_cast <float> (m_Window->GetInput().GetMouseX()), static_cast <float> (m_Window->GetInput().GetMouseY())))
	{
		// Opacity der Sprite setzen
		m_ButtonSprite.SetColor (sf::Color (255, 255, 255, 220));

		// Wenn der Button gedrückt wird
		if (m_Window->GetInput().IsMouseButtonDown(sf::Mouse::Left))
		{
			m_ButtonSprite.SetColor (sf::Color (200, 200, 200, 255));
		}
	}
	else
	{
		// Der Button wird auf das normale Aussehen gesetzt
		m_ButtonSprite.SetColor (sf::Color (255, 255, 255, 127));
	}
	if (m_Window->GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		m_MouseButtonDown = true;
	}
	else
	{
		m_MouseButtonDown = false;
	}
} 


void CButton::Render ()
{
	if (m_Hidden == false)
	{
		m_Window->Draw (m_ButtonSprite);
		m_Window->Draw (m_Text);
	}
}