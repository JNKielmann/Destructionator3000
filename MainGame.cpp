#include "MainGame.h"
#include "Game.h"
#include <sstream>

CMainGame::CMainGame(CGame* Game, sf::RenderWindow* Window) 
	: CGameState(Game, Window),
	m_BulletManager(),
	m_Player(*m_Game, m_BulletManager, m_ExplosionManager), m_Map(*m_Game),
	m_ExplosionManager(*m_Game, m_EnemyManager),
	m_EnemyManager(*m_Game, m_BulletManager, m_ExplosionManager, m_PowerUpManager, m_Player),
	m_PowerUpManager(*Game, *Window, m_Player),
	m_BackToMenuButton("Hauptmenü", sf::Vector2f(50, 500), false, sf::Font::GetDefaultFont(), Window, Game->GetImageManager().GetResource("Data/Button.png")),
	m_RestartButton("Nochmal", sf::Vector2f(400, 500), false, sf::Font::GetDefaultFont(), Window, Game->GetImageManager().GetResource("Data/Button.png")),
	m_GameOverText("Game Over"),
	m_WinText("")
{
	m_GameOverText.SetPosition(sf::Vector2f(100, 150));
	m_GameOverText.SetSize(100);
	m_WinText.SetPosition(sf::Vector2f(150, 150));
	m_WinText.SetSize(70);

	m_Music.OpenFromFile("Data/Steam.ogg");
	m_Music.SetLoop(true);
	m_GoSound.SetBuffer(*Game->GetSoundBufferManager().GetResource("Data/go.wav"));
}

CMainGame::~CMainGame(void)
{}

void CMainGame::Init( void* InitializationData )
{
	m_Music.Play();
	m_Window->SetCursorPosition(400, 500);
	m_Player.SetPosition(sf::Vector2f(400,500));
	m_GameOver = false;
	m_Win = false;
	m_EnemyManager.LoadEnemyFromFile("Data/Enemys.map");
	m_Player.Init();
	m_GoSound.Play();
	m_EnemyManager.ResetTimer();
}

void CMainGame::Exit()
{
	m_Music.Stop();
}


void CMainGame::ProcessEvent( const sf::Event& Event )
{
	if (Event.Type == sf::Event::MouseWheelMoved)
	{
		int Delta = Event.MouseWheel.Delta;
		if (Delta < 0)
		{
			while(Delta != 0)
			{
				m_Player.PreviousWeapon();
				++Delta;
			}
		}
		else if(Delta > 0)
		{
			while(Delta != 0)
			{
				m_Player.PreviousWeapon();
				--Delta;
			}
		}
	}
	else if(Event.Type == sf::Event::KeyPressed)
	{
		if (Event.Key.Code == sf::Key::Num1)
		{
			m_Player.SetWeapon(0);
		}
		else if (Event.Key.Code == sf::Key::Num2)
		{
			m_Player.SetWeapon(1);
		}
		else if (Event.Key.Code == sf::Key::Num3)
		{
			m_Player.SetWeapon(2);
		}
	}
}


void CMainGame::Move( float ElapsedTime )
{
	if (m_Player.IsDead())
	{
		m_GameOver = true;
	}
	else if (!m_EnemyManager.EnemysLeft())
	{
		m_Win = true;
	}
	m_Map.Update();
	m_EnemyManager.Update(m_Player.GetPosition());
	m_BulletManager.Update(m_EnemyManager, m_Player);
	
	m_ExplosionManager.Update();
	m_PowerUpManager.Update();
	if (m_GameOver || m_Win)
	{
		
		if (m_BackToMenuButton.IsClicked())
		{
			m_Game->ChangeGameState(STATE_MAIN_MENU);
		}
		else if (m_RestartButton.IsClicked())
		{
			m_Game->ChangeGameState(STATE_MAIN_GAME);
		}
		m_RestartButton.Update();
		m_BackToMenuButton.Update();
	}
	else
	{
		m_Player.Update(m_EnemyManager);
	}
}

void CMainGame::Render()
{
	m_Map.Draw();
	m_BulletManager.Draw();
	m_EnemyManager.Draw();
	m_ExplosionManager.Draw();
	m_PowerUpManager.Draw();
	if (m_GameOver || m_Win)
	{
		if (m_GameOver)
		{
			m_Window->Draw(m_GameOverText);
		}
		else
		{
			std::stringstream StringStream;
			StringStream << "Gewonnen! \nPunkte : " << m_Player.GetPoints();
			m_WinText.SetText(StringStream.str());
			m_Window->Draw(m_WinText);
		}
		m_RestartButton.Render();
		m_BackToMenuButton.Render();
	}
	else
	{
		m_Player.Draw();
	}
}

