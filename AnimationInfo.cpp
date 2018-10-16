#include "AnimationInfo.h"
#include "Logfile.h"

namespace JNK
{
	bool JNK::AnimationInfo::LoadFromFile(const std::string& FilePath, ImageManager& ImageMgr)
	{
		try
		{
			m_Image = AllResourceManager.GetImagemanager().GetResource(AnimationRootElement->Attribute("ImageName"));
		}
		catch (JNK::Exception& e)
		{
			Logfile::GetInstance() << Warning << "Fehler beim Laden des Bildes einer Aniamtion : " << e.what() << NewLine;
			return false;
		}
		AnimationRootElement->QueryIntAttribute("StartPositionX", &m_StartPosition.x);
		AnimationRootElement->QueryIntAttribute("StartPositionY", &m_StartPosition.y);
		AnimationRootElement->QueryIntAttribute("FrameWidth", &m_FrameSize.x);
		AnimationRootElement->QueryIntAttribute("FrameHeight", &m_FrameSize.y);
		AnimationRootElement->QueryIntAttribute("FramesPerRow", &m_FramesPerRow);
		AnimationRootElement->QueryIntAttribute("NumOfFrames", &m_NumOfFrames);
		AnimationRootElement->QueryFloatAttribute("FPS", &m_TimeBetweenFrames);
		m_TimeBetweenFrames = 1 / m_TimeBetweenFrames;
		AnimationRootElement->QueryIntAttribute("BoundingBoxX", &m_BoundingBox.Left);
		AnimationRootElement->QueryIntAttribute("BoundingBoxY", &m_BoundingBox.Top);
		AnimationRootElement->QueryIntAttribute("BoundingBoxWidth", &m_BoundingBox.Width);
		AnimationRootElement->QueryIntAttribute("BoundingBoxHeight", &m_BoundingBox.Height);
		return true;
	}

	bool AnimationInfo::Load( sf::Image* Image, sf::Vector2i StartPosition, sf::Vector2i FrameSize, int FramesPerRow, int NumOfFrames, float TimeBetweenFrames, sf::IntRect BoundingBox )
	{
		m_Image = Image;
		m_StartPosition = StartPosition;
		m_FrameSize = FrameSize;
		m_FramesPerRow = FramesPerRow;
		m_NumOfFrames = NumOfFrames;
		m_TimeBetweenFrames = TimeBetweenFrames;
		m_BoundingBox = BoundingBox;
		return true;
	}

}

