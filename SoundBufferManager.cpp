
#include "SoundBufferManager.h"
#include <iostream>



sf::SoundBuffer* CSoundManager::Load( const std::string& FileName )
{
	// den absoluten Pfad des SoundBuffers herausfinden
// 	string sFullPath = GetFullPath (FileName);
 
 	// Neuen Soundbuffer erstellen
 	sf::SoundBuffer* SoundBuffer = new sf::SoundBuffer();

	// Soundbuffer laden
	if(!SoundBuffer->LoadFromFile(FileName)) 
	{
		// Bild Löschen
		delete SoundBuffer;
		SoundBuffer = NULL;
		throw std::exception("Fehler im SoundBufferManager!");
	}
	std::cout << "Der Sound " << FileName << " wurde erfolgreich geladen." << std::endl;
	return SoundBuffer;
}

void CSoundManager::PlaySound( const std::string& FileName )
{
	sf::Sound Sound;
	Sound.SetVolume(60);
	m_Souds.push_back(Sound);
	m_Souds.back().SetBuffer(*GetResource(FileName));
	m_Souds.back().Play();

}

void CSoundManager::Update()
{
	for(std::list<sf::Sound>::iterator It = m_Souds.begin(); It != m_Souds.end(); ++It)
	{
		if (It->GetStatus() == sf::Sound::Stopped)
		{
			It = m_Souds.erase(It);
			if (It == m_Souds.end())
			{
				break;
			}
		}
	}
}
