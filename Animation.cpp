#include "Animation.h"
#include "JNK_Framework.h"

namespace JNK
{
	void Animation::Render( sf::RenderTarget& target, sf::Renderer& renderer ) const
	{
		target.Draw(m_AnimationSprite);
	}

	void Animation::UpdateAnimation( float ElapsedTime )
	{
		if(!m_Paused)
		{
			m_AnimationTime += ElapsedTime;
			if (m_AnimationTime > m_AnimationInfo->m_TimeBetweenFrames / m_SpeedFactor)
			{
				m_AnimationTime = 0;
				if((m_CurrentFrame+1) > m_AnimationInfo->m_NumOfFrames)
				{
					if (m_Loop)
					{
						m_CurrentFrame = 1;
					}					
				}
				else
				{
					++m_CurrentFrame;
				}
				int Left = m_AnimationInfo->m_StartPosition.x + (m_CurrentFrame-1 + m_AnimationInfo->m_FramesPerRow) % m_AnimationInfo->m_FramesPerRow * m_AnimationInfo->m_FrameSize.x;
				int Top = m_AnimationInfo->m_StartPosition.y + m_CurrentFrame / (m_AnimationInfo->m_FramesPerRow+1) * m_AnimationInfo->m_FrameSize.y;
				m_AnimationSprite.SetSubRect(sf::IntRect(Left, Top, m_AnimationInfo->m_FrameSize.x, m_AnimationInfo->m_FrameSize.y));
			}
		}
		
	}
}

