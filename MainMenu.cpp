/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////Bless of Magic////////////////////////////////////////////////////
/* Dateiname: MainMenu.cpp
   Erstellungsdatum: 11.9.2010
   Autor: Jan Niklas Kielmann
   Beschreibung: Implementation des Hauptmenüs
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Letzte änderungen:
/*

*/
#include "MainMenu.h"
#include "Game.h"

#define GUI_GROUP_MAINMENU 1

CMainMenu::CMainMenu(CGame* Game, sf::RenderWindow* Window) 
	: CGameState(Game, Window),
	m_Logo(*Game->GetImageManager().GetResource("Data/Logo.png"), sf::Vector2f(150,10)),
	m_PlayButton("Start", sf::Vector2f(250, 250), false, sf::Font::GetDefaultFont(), m_Window, Game->GetImageManager().GetResource("Data/button.png")),
	m_InstructionButton("Anleitung", sf::Vector2f(250, 350), false, sf::Font::GetDefaultFont(), m_Window, Game->GetImageManager().GetResource("Data/button.png")),
	m_ExitButton("Beenden", sf::Vector2f(250, 450), false, sf::Font::GetDefaultFont(), m_Window, Game->GetImageManager().GetResource("Data/button.png")),
	FadingI (800, 600)
{
	if (!m_Music.OpenFromFile("Data/Ground Squad.ogg"))
	{
		exit(-1);
	}
	Fading.SetImage (FadingI);
}


CMainMenu::~CMainMenu(void)
{
	
}

void CMainMenu::Init( void* InitializationData )
{
	if (m_Music.GetStatus() == sf::Music::Stopped)
	{
		m_Music.Play();
		m_Music.SetVolume(100);
	}
	m_bIsFading = false;

	FadingTimer.Reset();
	
	Opacity = 0.0f;
	Volume = 100.0f;

	Fading.SetColor (sf::Color (255, 255, 255, static_cast<sf::Uint8>(Opacity)));
}

void CMainMenu::Exit()
{
}

void CMainMenu::Move( float ElapsedTime )
{
	
	if (m_PlayButton.IsClicked() && !m_bIsFading)
	{
		m_bIsFading = true;
	}
	else if(m_InstructionButton.IsClicked() && !m_bIsFading)
	{
		m_Game->ChangeGameState(STATE_INSTRUCTION);
	}
	else if (m_ExitButton.IsClicked() && !m_bIsFading)
	{
		m_Game->ExitGame();
	}

	if (m_bIsFading)
	{
		Opacity += (255 * (25.0f / 100.0f)) * FadingTimer.GetElapsedTime();
		Volume -= (100 * (25.0f / 100.0f)) * FadingTimer.GetElapsedTime();

		Fading.SetColor (sf::Color (255, 255, 255, static_cast<sf::Uint8>(Opacity)));
		m_Music.SetVolume (Volume);

		if (Volume <= 0.0f)
		{
			m_Music.Stop();

			m_Game->ChangeGameState (STATE_MAIN_GAME);
		}
	}
	m_PlayButton.Update();
	m_InstructionButton.Update();
	m_ExitButton.Update();
	FadingTimer.Reset();
}

void CMainMenu::Render()
{
	m_Window->Draw(m_Logo);
	m_PlayButton.Render();
	m_InstructionButton.Render();
	m_ExitButton.Render();
	m_Window->Draw (Fading);
}