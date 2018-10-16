#include "Shield.h"

CShield::CShield ()
{
	// Das Schild ist voll
	m_ShieldEnergy = 100.0f;

	m_ShieldImage.LoadFromFile ("Data/Shield.png");
	m_ShieldSprite.SetImage (m_ShieldImage);
	m_ShieldSprite.SetCenter (m_ShieldSprite.GetSize() / 2.0f);

	m_ShieldEnergyBar.Init ("Data/Shield_bar_d.png", "Data/Shield_bar_a.png", sf::Vector2f(0.0f, 0.0f), 100.0f, m_ShieldEnergy);

	m_IsVisible = false;
	m_IsActive = true;
}

void CShield::Update (sf::Vector2f ShieldPosition, float ElapsedTime)
{
	m_ShieldEnergy += 4.0f * ElapsedTime;

	if (m_ShieldEnergy > 100.0f)
	{
		m_ShieldEnergy = 100.0f;
	}

	if (ShowTimer.GetElapsedTime() <= 1.0f || m_ShieldEnergy < 100.0f)
	{
		m_IsVisible = true;
	}
	else {
		m_IsVisible = false;
	}

	if (m_ShieldEnergy >= 85.0f)
	{
		m_IsActive = true;
	}

	m_ShieldSprite.SetPosition (ShieldPosition);
	m_ShieldEnergyBar.SetPosition (sf::Vector2f (ShieldPosition.x - 50.0f, ShieldPosition.y - 100.0f));
	m_ShieldEnergyBar.SetValue (m_ShieldEnergy);
}

void CShield::Render (sf::RenderWindow &Window)
{
	if (m_IsActive == true)
	{
		Window.Draw (m_ShieldSprite);
	}
	if (m_IsVisible == true)
	{
		m_ShieldEnergyBar.Render (Window);
	}
}

float CShield::GetAbsoluteDamage (float RelativeDamage)
{
	ShowTimer.Reset();

	if (m_IsActive == true)
	{
		m_ShieldEnergy -= RelativeDamage * (250 / 100);
		if (m_ShieldEnergy <= 0.0f)
		{
			m_ShieldEnergy = 0.0f;
			m_IsActive = false;
		}

		return (RelativeDamage - RelativeDamage * (50 / 100));
	}
	else {
		return (RelativeDamage);
	}
}