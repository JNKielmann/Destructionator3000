#pragma once
#include "ResourceManager.h"
#include <sfml/Audio.hpp>
#include <list>

class CSoundManager : public CResourceManager<sf::SoundBuffer>
{
public:
	void PlaySound(const std::string& FileName);
	void Update();
protected:
	virtual sf::SoundBuffer* Load(const std::string& FileName);
private:
	std::list<sf::Sound> m_Souds;
};