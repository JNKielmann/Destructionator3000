#include "Instruction.h"
#include "Game.h"

CInstruction::CInstruction( CGame* Game, sf::RenderWindow* Window ) : CGameState(Game, Window),
	m_Back ("", sf::Vector2f(710.0f, 570.0f), false, sf::Font::GetDefaultFont(), m_Window, Game->GetImageManager().GetResource("Data/Anleitung/PreviousButton.png")),
	m_Forward ("", sf::Vector2f(750.0f, 570.0f), false, sf::Font::GetDefaultFont(), m_Window, Game->GetImageManager().GetResource("Data/Anleitung/NextButton.png")),
	m_Sites (2)
{
	m_scrshot1.SetImage (*m_Game->GetImageManager().GetResource("Data/Anleitung/scrshot1.png"));
	m_Tipps.SetImage (*m_Game->GetImageManager().GetResource("Data/Anleitung/Tipps.png"));
}

CInstruction::~CInstruction( void )
{
}

void CInstruction::Init(void* InitializationData)
{
	m_CurrentSite = 1;

	ClickTimer.Reset();
}

void CInstruction::Exit()
{}

void CInstruction::Move(float ElapsedTime)
{
	if (m_CurrentSite <= 0)
	{
		m_CurrentSite = 0;

		m_Game->ChangeGameState (STATE_MAIN_MENU);
	}
	
	else if (m_CurrentSite >= m_Sites)
	{
		m_CurrentSite = m_Sites;

		m_Forward.SetHidden (true);
	}
	else {
		m_Forward.SetHidden (false);
	}

	if (m_Back.IsClicked() && ClickTimer.GetElapsedTime() >= 0.5f)
	{
		m_CurrentSite -= 1;
		ClickTimer.Reset();
	}
	else if (m_Forward.IsClicked() && ClickTimer.GetElapsedTime() >= 0.5f)
	{
		m_CurrentSite += 1;
		ClickTimer.Reset();
	}

	m_Back.Update();
	m_Forward.Update();

}

void CInstruction::Render()
{
	if (m_CurrentSite == 1)
	{
		m_Window->Draw (m_Tipps);
	}
	else if (m_CurrentSite == 2)
	{
		m_Window->Draw (m_scrshot1);
	}

	m_Back.Render();
	m_Forward.Render();
}
