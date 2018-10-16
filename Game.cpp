/*********************************************************************************************************************
	*Projekt*:			Bless of Magic

	Dateiname:				Game.cpp
	Author:					Arne Dußin
	Erstellungsdatum:		9.9.2010
	Beschreibung:			Implentierung der Spielklasse
**********************************************************************************************************************/

// Letzte Änderungen:
/*
	11.9.2010  Jan Niklas Kielmann
	 -StateManager implementiert
	 -Fehlermeldung eingefügt wenn vergessen wurde Init aufzurufen
	 -Kommentare, die ins log geschrieben werden hinzugefügt
*/

#include "Game.h"
#include <iostream>


/**************************
Konstruktor

allgemeine Initialisierung
***************************/
CGame::CGame () : m_Window(sf::VideoMode (800, 600, 32), "SCC16")
{
	// Cursor wird nicht gezeigt
	//m_Window.ShowMouseCursor (false);

	m_Window.SetFramerateLimit (60);
	m_Window.ShowMouseCursor (false);
	m_Window.EnableKeyRepeat(false);

	m_Imagemanager.LoadAllResources("Data/Images.dat");
	m_SoundBufferManager.LoadAllResources("Data/Sounds.dat");
	while(!m_Imagemanager.FinishedLoading() && !m_SoundBufferManager.FinishedLoading())
	{
		std::cout << "Es Wird geladen" << std::endl;
		sf::Sleep(0.2f);
	}

 	// Cursor laden und initialisieren
 	m_PositionCur.SetImage (*(m_Imagemanager.GetResource("Data/position_cur.png")));
 	m_PositionCur.SetCenter (m_PositionCur.GetSize() / 2.0f);

	sf::Randomizer::SetSeed(static_cast<unsigned int>(time(NULL)));

	// Spielzustände erstellen
	m_Intro = new CIntro(this, &m_Window);
	m_MainMenü = new CMainMenu(this, &m_Window);
	m_Instructoin = new CInstruction(this, &m_Window);
	m_MainGame = new CMainGame(this, &m_Window);

	// Am Anfang des Programmes ist der Zustand Intro aktiviert 
	m_CurrentGameState = m_MainMenü;
	m_CurrentGameState->Init(NULL);

}// Konstruktor



CGame::~CGame()
{
	// Sicherstellen, das der aktuelle Spielstand ordnugsgemäß heruntergefahren wird
	if(m_CurrentGameState) m_CurrentGameState->Exit();

	// Spielzustände löschen
	delete m_Intro;
	delete m_MainMenü;
	delete m_Instructoin;
	delete m_MainGame;
}

/*****************
	Run

	Spiel laufen
	lassen
******************/
void CGame::Run ()
{
	// Solange das Spiel läuft
	//
	while (m_Window.IsOpened())
	{
		// Wurde das Spiel geschlossen?
		ProcessEvents();

		m_SoundBufferManager.Update();
		// Spielzustand bewegen
		m_CurrentGameState->Move(m_Window.GetFrameTime());
		// Fenster leeren
		m_Window.Clear ();

		// Spielzustand rendern
		m_CurrentGameState->Render();

		// Cursorposition setzen und Cursor zeichnen
		m_PositionCur.SetPosition(static_cast<float>(m_Window.GetInput().GetMouseX()), static_cast<float>(m_Window.GetInput().GetMouseY()));
		m_Window.Draw (m_PositionCur);

		// Fenster rendern
		m_Window.Display ();

		//std::cout << "FPS = " << 1/m_Window.GetFrameTime() << std::endl;
	}
} // Run

/***************************
	ProcessEvents

	Feststellen, ob das Spiel
	geschlossen wurde
****************************/
void CGame::ProcessEvents ()
{
	// Event erstellen
	sf::Event Event;
	// ist noch ein Event zu verarbeiten
	while (m_Window.GetEvent(Event))
	{
		// Event-Typ erkennen
		switch (Event.Type)
		{
		case sf::Event::Closed:
			// App schließen
			m_Window.Close ();
			break;
		}
		m_CurrentGameState->ProcessEvent(Event);
	}
} // ProcessEvents

void CGame::ChangeGameState( EGameState NewGameState, void* InitialisationData )
{
	// Alten Spielzustand verlassen
	if(m_CurrentGameState) m_CurrentGameState->Exit();

	switch(NewGameState)
	{
	case STATE_INTRO:
		m_CurrentGameState = m_MainMenü;
		break;
	case STATE_MAIN_MENU:
		 m_CurrentGameState = m_MainMenü;
		break;
	case STATE_INSTRUCTION:
		m_CurrentGameState = m_Instructoin;
		break;
	case STATE_MAIN_GAME:
		m_CurrentGameState = m_MainGame;
		break;
	}
	// Neuen Spielzustand initialisieren
	m_CurrentGameState->Init(InitialisationData);

}