#include "AnimationManager.h"

namespace JNK
{
	JNK::AnimationInfo * AnimationManager::Load( const TiXmlElement* FileName )
	{
		// Neue Animation erstellen
		AnimationInfo* Anim = new AnimationInfo();
		// Bild Laden
		if(!Anim->LoadFromFile(FileName)) 
		{
			// Animation Löschen
			delete Anim;
			Anim = NULL;
			THROW_JNK_EXCEPTION("Eine Animation konnte nicht geladen werden");
		}
		return Anim;
	}


}
