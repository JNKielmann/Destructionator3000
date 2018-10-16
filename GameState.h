/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////Bless of Magic////////////////////////////////////////////////////
/* Dateiname: GameState.h
   Erstellungsdatum: 11.9.2010
   Autor: Jan Niklas Kielmann
   Beschreibung: Basisklasse für die Gamestates
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Letzte änderungen:
/*
	
*/

#ifndef GameState_h__
#define GameState_h__


#include <sfml/Graphics.hpp>

// Die Gameklasse deklarieren
class CGame;

// Basklasse für einen Zustand/State
class CGameState
{
public:
	// Konstruktor
	// Parameter 1: Zeiger auf die Spielklasse
	// Parameter 2: Zeiger auf das Fenstere auf das gerendert werden soll
	CGameState(CGame* Game, sf::RenderWindow* Window) : m_Game(Game), m_Window(Window)
	{}
	// Virtueller Destruktor
	virtual ~CGameState() {}

	// Initialisiert den Zustand
	// Parameter: Zeiger auf Daten die der Spielzustand übergeben bekommen soll (z.B übergibt der Hauptspielzustand dem Highscorezustand die Punktzahl die der Spieler erreicht hat 
	virtual void Init(void* InitializationData) = 0;

	// Fährt den Spielzustand herunter
	virtual void Exit() = 0;

	// Bewegt den Spielzustand
	// Parameter : Vergangangene Zeit seit dem letztdem Frame
	virtual void Move(float ElapsedTime) = 0;

	// Rendert den Spielzustand
	virtual void Render() = 0; 

	virtual void ProcessEvent(const sf::Event& Event){};
protected:
	CGame* m_Game;

	sf::RenderWindow* m_Window;
};
#endif // GameState_h__