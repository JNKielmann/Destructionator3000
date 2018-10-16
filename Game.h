/*********************************************************************************************************************
	*Projekt*:			Bless of Magic

	Dateiname:			Game.h
	Author:				Arne Dußin
	Erstellungsdatum: 	9.9.2010
	Beschreibung:		Hauptklasse des Spiels
**********************************************************************************************************************/

// Letzte Änderungen:
/*
	11.9.2010  Jan Niklas Kielmann
	StateManager hinzugefügt
*/


#ifndef Game_h__
#define Game_h__

#include "Intro.h"
#include "MainMenu.h"
#include "Instruction.h"
#include "MainGame.h"

#include "ImageManager.h"
#include "SoundBufferManager.h"


// Aufzählung aller Spielzustände
enum EGameState
{
	STATE_INTRO,		// Das Intro
	STATE_MAIN_MENU,	// Das Hauptmenü
	STATE_INSTRUCTION,  // Die Anleitung
	STATE_MAIN_GAME,	// Das eigendliche Spiel (Da wo man mit dem Spieler rum läuft)
};

/*************
	CGame
**************/
class CGame
{
public:
	CGame ();
	~CGame();

	// Führt das Spiel aus! Diese Methode kehrt erst zurück wenn das Spiel beendet wurde.
	// Sie sollte nur EINE mal in der Hauptfunktion aufgerufen werden!
	void Run ();

	// Ändert den Spielzustand
	// Parameter1: Neuer Spielzustand
	// Parameter2: Extradaten für den neuen Spielzustand (z.B die Punktzahl, die der Spieler erreicht hat) 
	void ChangeGameState(EGameState NewGameState, void* InitialisationData = 0);

	// Beendet die Hauptschleife
	void ExitGame()
	{
		// Spiel beenden durch schließen des Fensters
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

	// Spielzustände
	CIntro*		m_Intro;
	CMainMenu*	m_MainMenü;
	CInstruction* m_Instructoin;
	CMainGame*	m_MainGame;

	// Aktueller Spielzustand
	CGameState* m_CurrentGameState;

	sf::RenderWindow m_Window;	// RenderWindow für das Spiel

	sf::Sprite m_PositionCur;
};
#endif // Game_h__