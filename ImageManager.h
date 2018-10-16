

#ifndef ImageManager_h__
#define ImageManager_h__


#include "ResourceManager.h"
#include <sfml/Graphics.hpp>

class CImageManager : public CResourceManager<sf::Image>
{
protected:
	virtual sf::Image* Load(const std::string& FileName);
};
#endif // ImageManager_h__