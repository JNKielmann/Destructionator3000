#include "ImageManager.h"

sf::Image* CImageManager::Load( const std::string& FileName )
{
	// Den absoluten Pfad des Bildes herausfinden
	//string sFullPath = GetFullPath (FileName);

	// Neues Bild erstellen
	sf::Image* Image = new sf::Image();
	// Bild Laden
	if(!Image->LoadFromFile(FileName)) 
	{
		// Bild Löschen
		delete Image;
		Image = NULL;
		throw std::exception("Fehler im ImageManager!");
	}
	return Image;
}
