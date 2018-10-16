#ifndef SINGLETON_HPP
#define SINGLETON_HPP
template <class T>
class TSingleton
{
protected:
	static T m_Singleton;
public:
	inline static T& GetInstance() {return m_Singleton;}
};
template <class T>
T TSingleton<T>::m_Singleton;
#endif