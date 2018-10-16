#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>


// Klasse für die Buttons
class CButton
{
public:
	CButton (const std::string &Text, sf::Vector2f Position, bool hidden, const sf::Font &FontToUse, sf::RenderWindow *pWindow, sf::Image *pButtonImage);

	bool IsClicked();
	void SetHidden(bool NewHidden);

	void Update();
	void Render();
private:
	sf::Sprite m_ButtonSprite;		// Sprite für die Buttons

	bool m_Hidden;					// Wird der Button angezeigt?
	sf::String m_Text;				// Der Text des Buttons
	
	bool m_MouseButtonDown;

	sf::FloatRect m_CollisionRect;	// Das Rect, welches bestimmt, ob der Cursor auf dem Button ist
	sf::RenderWindow *m_Window;	// Pointer auf das RenderWindow auf welches gezeichnet wird
};

#endif