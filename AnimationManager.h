////////////////////////////////////JNK Framework////////////////////////////////////
//Datei: AnimationManager.h
//Erstellungsdatum: 2011/02/14
//Author: Jan Niklas Kielmann
//Beschreibung : Managt alle Animationen
//////////////////////////////////////////////////////////////////////////////////////

#ifndef AnimationManager_h__
#define AnimationManager_h__

#include "ResourceManager.h"
#include "AnimationInfo.h"

namespace JNK
{
	class AnimationManager : public ResourceManager<TiXmlElement*, AnimationInfo>
	{
	public:
		//virtual AnimationInfo* Load(const TiXmlElement& AnimElm);
		JNK::AnimationInfo *Load(const TiXmlElement* FileName);
	};
}

#endif // AnimationManager_h__
