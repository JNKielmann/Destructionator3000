////////////////////////////////////JNK Framework////////////////////////////////////
//Datei: AnimationInfo.h
//Erstellungsdatum: 2011/01/15
//Author: Jan Niklas Kielmann
//Beschreibung : Informationen die die Animationsklasse benötigt
//////////////////////////////////////////////////////////////////////////////////////

#ifndef AnimationInfo_h__
#define AnimationInfo_h__

#include <sfml/Graphics.hpp>
#include <string>


namespace JNK
{
	class AnimationInfo
	{
	public:
		AnimationInfo(){}

		// Lädt die Animationsinformationen aus einer Textdatei
		bool LoadFromFile(const std::string& FilePath, ImageManager& ImageMgr);
		bool Load(sf::Image* Image,	sf::Vector2i StartPosition,	sf::Vector2i FrameSize,	int FramesPerRow, int NumOfFrames, float TimeBetweenFrames,	sf::IntRect BoundingBox);
	
	public:
		sf::Image* m_Image;
		sf::Vector2i m_StartPosition;
		sf::Vector2i m_FrameSize;
		int m_FramesPerRow;
		int m_NumOfFrames;
		float m_TimeBetweenFrames;
		sf::IntRect m_BoundingBox;
	};
}
#endif // AnimationInfo_h__