/*********************************************************************************************************************
	*Projekt*:			Bless of Magic

	Dateiname:			Game.h
	Author:				Arne Du�in
	Erstellungsdatum: 	9.9.2010
	Beschreibung:		Hauptklasse des Spiels
**********************************************************************************************************************/

// Letzte �nderungen:
/*
	11.9.2010  Jan Niklas Kielmann
	StateManager hinzugef�gt
*/


#ifndef Game_h__
#define Game_h__

#include "Intro.h"
#include "MainMenu.h"
#include "Instruction.h"
#include "MainGame.h"

#include "ImageManager.h"
#include "SoundBufferManager.h"


// Aufz�hlung aller Spielzust�nde
enum EGameState
{
	STATE_INTRO,		// Das Intro
	STATE_MAIN_MENU,	// Das Hauptmen�
	STATE_INSTRUCTION,  // Die Anleitung
	STATE_MAIN_GAME,	// Das eigendliche Spiel (Da wo man mit dem Spieler rum l�uft)
};

/*************
	CGame
**************/
class CGame
{
public:
	CGame ();
	~CGame();

	// F�hrt das Spiel aus! Diese Methode kehrt erst zur�ck wenn das Spiel beendet wurde.
	// Sie sollte nur EINE mal in der Hauptfunktion aufgerufen werden!
	void Run ();

	// �ndert den Spielzustand
	// Parameter1: Neuer Spielzustand
	// Parameter2: Extradaten f�r den neuen Spielzustand (z.B die Punktzahl, die der Spieler erreicht hat) 
	void ChangeGameState(EGameState NewGameState, void* InitialisationData = 0);

	// Beendet die Hauptschleife
	void ExitGame()
	{
		// Spiel beenden durch schlie�en des Fensters
		m_Window.Close();
	}

	sf::RenderWindow& GetWindow()
	{
		return m_Window;
	}

	CImageManager& GetImageManager()
	{
		return m_Imagemanager;
	}
	CSoundManager& GetSoundBufferManager()
	{
		return m_SoundBufferManager;
	}
private:
	void ProcessEvents();

private:
	CImageManager m_Imagemanager;
	CSoundManager m_SoundBufferManager;

	// Spielzust�nde
	CIntro*		m_Intro;
	CMainMenu*	m_MainMen�;
	CInstruction* m_Instructoin;
	CMainGame*	m_MainGame;

	// Aktueller Spielzustand
	CGameState* m_CurrentGameState;

	sf::RenderWindow m_Window;	// RenderWindow f�r das Spiel

	sf::Sprite m_PositionCur;
};
#endif // Game_h__