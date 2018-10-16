#ifndef MainMenu_h__
#define MainMenu_h__

#include "GameState.h"
#include <sfml/Audio.hpp>
#include "button.h"

class CMainMenu : public CGameState
{
public:
	CMainMenu(CGame* Game, sf::RenderWindow* Window);
	virtual ~CMainMenu(void);

	virtual void Init(void* InitializationData);
	virtual void Exit();
	virtual void Move(float ElapsedTime);
	virtual void Render();

private:
	sf::Sprite m_Logo;
	CButton m_PlayButton;
	CButton m_InstructionButton;
	CButton m_ExitButton;
	
	sf::Music m_Music;
	float Volume;

	sf::Sprite m_Fader;
	float Opacity;

	bool m_bIsFading;
	sf::Image FadingI;
	sf::Sprite Fading;
	sf::Clock FadingTimer;
};
#endif // MainMenu_h__