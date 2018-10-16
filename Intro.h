/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////Bless of Magic////////////////////////////////////////////////////
/* Dateiname: Hauptmenü.h
   Erstellungsdatum: 11.9.2010
   Autor: Jan Niklas Kielmann
   Beschreibung: Zustandsklasse des Intros
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Letzte änderungen:
/*

*/

#ifndef Intro_h__
#define Intro_h__


#include "GameState.h"


class CIntro : public CGameState
{
public:
	CIntro(CGame* Game, sf::RenderWindow* Window);
	virtual ~CIntro(void);

	virtual void Init(void* InitializationData);
	virtual void Exit();
	virtual void Move(float ElapsedTime);
	virtual void Render();

private:
};
#endif // Intro_h__