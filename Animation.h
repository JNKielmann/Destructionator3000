////////////////////////////////////JNK Framework////////////////////////////////////
//Datei: Animation.h
//Erstellungsdatum: 2011/01/15
//Author: Jan Niklas Kielmann
//Beschreibung : Klasse zum malen von Animationen
//////////////////////////////////////////////////////////////////////////////////////

#ifndef Animation_h__
#define Animation_h__

#include "AnimationInfo.h"

namespace JNK
{
	class Animation  : public sf::Drawable
	{
	public:
		Animation()
		{
			m_AnimationTime = 0;
			m_CurrentFrame = 1;
			m_Loop = true;
			m_SpeedFactor = 1;
			m_Paused = false;
		}
		Animation(AnimationInfo& AnimInfo, bool Loop = true)
		{
			m_Loop = Loop;
			SetAnimInfo(AnimInfo);
			m_AnimationTime = 0;
			m_CurrentFrame = 1;
			m_SpeedFactor = 1;
			m_Paused = false;
		}
		void SetAnimInfo(AnimationInfo& AnimInfo)
		{
			m_AnimationInfo = &AnimInfo;
			m_AnimationSprite.SetImage(*AnimInfo.m_Image);
			int Left = m_AnimationInfo->m_StartPosition.x;
			int Top = m_AnimationInfo->m_StartPosition.y;
			m_AnimationSprite.SetSubRect(sf::IntRect(Left, Top, m_AnimationInfo->m_FrameSize.x, m_AnimationInfo->m_FrameSize.y));
		}
		void UpdateAnimation(float ElapsedTime);

		void Resize(float width, float height);

		void Resize(const sf::Vector2f& size);

		void FlipX(bool flipped);

		void FlipY(bool flipped);

		sf::Vector2f GetSize()
		{
			return m_AnimationSprite.GetSize();
		}

		sf::IntRect GetLocalBoundingBox()
		{
			return m_AnimationInfo->m_BoundingBox;
		}
		sf::Color GetPixel(unsigned int x, unsigned int y) const;

		void SetLoop(bool Loop)
		{
			m_Loop = Loop;
		}

		// Pausiert die Animation
		void Pause()
		{
			m_Paused = true;
		}
		void UnPause()
		{
			m_Paused = false;
		}
		bool IsPaused()
		{
			return m_Paused;
		}

		// Faktor um den die Animation schneller bzw. langsamer gemacht werden soll
		void SetAniamtionSpeed(float SpeedFactor)
		{
			m_SpeedFactor = SpeedFactor;
		}
		float GetAnimationSpeed()
		{
			return m_SpeedFactor;
		}
		
		const sf::Sprite& GetCurrentSprite() const
		{
			return m_AnimationSprite;
		}

		void Reset()
		{
			m_Paused = false;
			m_AnimationTime = 0;
			m_CurrentFrame = 1;
		}
	protected:
		// Malt die Animation
		virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;

	private:
		AnimationInfo* m_AnimationInfo;
		sf::Sprite m_AnimationSprite;
		bool m_Loop;
		bool m_Paused;
		float m_SpeedFactor;
		float m_AnimationTime;
		int m_CurrentFrame;
	};
}
#endif // Animation_h__