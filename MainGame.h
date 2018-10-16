#ifndef MainGame_h__
#define MainGame_h__


#include "Player.h"
#include "Map.h"
#include "BulletManager.h"
#include "GameState.h"
#include "EnemyManager.h"
#include "ExplosionManager.h"
#include "PowerUpManager.h"
#include <SFML/Audio.hpp>
#include "button.h"

class CMainGame : public CGameState
{
public:
	CMainGame(CGame* Game, sf::RenderWindow* Window);
	virtual ~CMainGame(void);

	virtual void Init(void* InitializationData);
	virtual void Exit();
	virtual void Move(float ElapsedTime);
	virtual void Render();
	virtual void ProcessEvent(const sf::Event& Event);

private:
	CPlayer m_Player;
	CMap m_Map;
	CBulletManager m_BulletManager;
	CEnemyManager m_EnemyManager;
	CExplosionManager m_ExplosionManager;
	CPowerUpManager m_PowerUpManager;

	bool m_GameOver;
	sf::String m_GameOverText;
	bool m_Win;
	sf::String m_WinText;
	CButton m_BackToMenuButton;
	CButton m_RestartButton;

	sf::Music m_Music;
	sf::Sound m_GoSound;
};
#endif // MainGame_h__