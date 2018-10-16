#include <string>
#include <map>
#include "Singleton.h"
#include <fstream>
#include "SFML/System.hpp"


#ifndef ResourceManager_h__
#define ResourceManager_h__

template< class T >
class CResourceManager : private sf::Thread
{
public:
	typedef std::map< std::string, std::tr1::shared_ptr<T>> ResourceMap;

	CResourceManager() 
	{
		m_ResourcesLoaded = false;
	}

	void LoadAllResources(std::string FileName)
	{
		m_File.open(FileName);
		if (!m_File)
		{
			std::cout << "Die Datei " << FileName << "konnte nicht gefunden werden!!" << std::endl;
			m_ResourcesLoaded = true;
			return;
		}
		Launch();
	}

	bool FinishedLoading()
	{
		return m_ResourcesLoaded;
	}
	virtual ~CResourceManager() 
	{}
	T* GetResource(const std::string& FileName)
	{
		// Prüfen ob die Resource schon geladen ist
		T* Resource = Find(FileName);
		if(Resource == NULL)
		{
			// Resource laden
			Resource = Load(FileName);
			// Wenn die Ressource erfolgreich geladen wurde 
			m_Resource.insert(make_pair( FileName, std::tr1::shared_ptr<T>(Resource)));

		}
		return Resource;
	}

protected:
	virtual T* Load(const std::string& FileName) = 0;

private:
	ResourceMap m_Resource;

	bool m_ResourcesLoaded;

	T* Find( const std::string& FileName)
	{
		// Nach der Ressource suchen
		typename ResourceMap::iterator it = m_Resource.find(FileName);
		if(it != m_Resource.end())
		{
			// Eintrag gefunden! Zurückgeben!
			return it->second.get();
		}
		else
		{
			// Eintrag nicht gefunden! Null zurückgeben
			return NULL;
		}
	}

	virtual void Run()
	{
		while(!m_File.eof())
		{
			std::string ResourceName;
			m_File >> ResourceName;
			m_Resource.insert(make_pair(ResourceName, std::tr1::shared_ptr<T>(Load(ResourceName))));
		}
		m_File.close();
		m_ResourcesLoaded = true;
	}

	std::ifstream m_File;

};
#endif // ResourceManager_h__