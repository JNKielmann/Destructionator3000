#ifndef Instruction_h__
#define Instruction_h__


#include "Button.h"
#include "GameState.h"

class CInstruction : public CGameState
{
public:
	CInstruction(CGame* Game, sf::RenderWindow* Window);
	virtual ~CInstruction(void);

	virtual void Init(void* InitializationData);
	virtual void Exit();
	virtual void Move(float ElapsedTime);
	virtual void Render();
private:
	CButton m_Back;
	CButton m_Forward;

	unsigned short m_CurrentSite;
	const unsigned short m_Sites;

	sf::Sprite m_scrshot1;
	sf::Sprite m_Tipps;

	sf::Clock ClickTimer;
};
#endif // Instruction_h__
