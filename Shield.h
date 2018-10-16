#ifndef SHIELD_H
#define SHIELD_H

#include "Bar.h"

class CShield
{
public:
	CShield ();

	void Reset()
	{
		m_ShieldEnergy = 100.0f;
		m_IsActive = true;
		m_ShieldEnergyBar.SetValue(m_ShieldEnergy);
	}

	void Update (sf::Vector2f ShieldPosition, float ElapsedTime);
	void Render (sf::RenderWindow &Window);

	float GetAbsoluteDamage (float RelativeDamage);

private:
	CBar m_ShieldEnergyBar;
	bool m_IsVisible;
	float m_ShieldEnergy;

	bool m_IsActive;

	sf::Sprite m_ShieldSprite;
	sf::Image m_ShieldImage;

	sf::Clock ShowTimer;
};

#endif