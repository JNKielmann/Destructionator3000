////////Vektor2d.h[5/9/2010 Jan Niklas Kielmann]////////
/*
 *	Klasse zur darstellung von zweidemensionalen Vektoren
 */
#ifndef Vektor2d_h__
#define Vektor2d_h__

#include <sfml/Graphics.hpp>

sf::Vector2f Rotate(const sf::Vector2f &vec, float angleInDegrees);

template <class T>
class CMathVektor2d
{
public:
	//! Default constructor (null vector)
	CMathVektor2d() : X(0), Y(0) {}
	//! Constructor with two different values
	CMathVektor2d(T nx, T ny) : X(nx), Y(ny) {}
	//! Constructor with the same value for both members
	explicit CMathVektor2d(T n) : X(n), Y(n) {}
	//! Copy constructor
	CMathVektor2d(const CMathVektor2d<T>& other) : X(other.X), Y(other.Y) {}

	CMathVektor2d(const sf::Vector2<T>& other) : X(other.x), Y(other.y) {}

	operator sf::Vector2<T> () {return sf::Vector2<T>(X,Y);}

	// operators
	CMathVektor2d<T> operator-() const { return CMathVektor2d<T>(-X, -Y); }

	CMathVektor2d<T>& operator=(const CMathVektor2d<T>& other) { X = other.X; Y = other.Y; return *this; }

	CMathVektor2d<T>& operator=(const sf::Vector2<T>& other) { X = other.x; Y = other.y; return *this; }

	CMathVektor2d<T> operator+(const CMathVektor2d<T>& other) const { return CMathVektor2d<T>(X + other.X, Y + other.Y); }
	CMathVektor2d<T> operator+(const sf::Vector2<T>& other) const { return CMathVektor2d<T>(X + other.x, Y + other.y); }
	CMathVektor2d<T>& operator+=(const CMathVektor2d<T>& other) { X+=other.X; Y+=other.Y; return *this; }
	CMathVektor2d<T> operator+(const T v) const { return CMathVektor2d<T>(X + v, Y + v); }
	CMathVektor2d<T>& operator+=(const T v) { X+=v; Y+=v; return *this; }
	CMathVektor2d<T>& operator+=(const sf::Vector2<T>& other) { X += other.x; Y += other.y; return *this;  }

	CMathVektor2d<T> operator-(const CMathVektor2d<T>& other) const { return CMathVektor2d<T>(X - other.X, Y - other.Y); }
	CMathVektor2d<T> operator-(const sf::Vector2<T>& other) const { return CMathVektor2d<T>(X - other.x, Y - other.y); }
	CMathVektor2d<T>& operator-=(const CMathVektor2d<T>& other) { X-=other.X; Y-=other.Y; return *this; }
	CMathVektor2d<T> operator-(const T v) const { return CMathVektor2d<T>(X - v, Y - v); }
	CMathVektor2d<T>& operator-=(const T v) { X-=v; Y-=v; return *this; }
	CMathVektor2d<T>& operator-=(const sf::Vector2<T>& other) { X -= other.Width; Y -= other.Height; return *this;  }

	CMathVektor2d<T> operator*(const CMathVektor2d<T>& other) const { return CMathVektor2d<T>(X * other.X, Y * other.Y); }
	CMathVektor2d<T> operator*(const T v) const { return CMathVektor2d<T>(X * v, Y * v); }

	CMathVektor2d<T> operator/(const CMathVektor2d<T>& other) const { return CMathVektor2d<T>(X / other.X, Y / other.Y); }
	CMathVektor2d<T> operator/(const T v) const { return CMathVektor2d<T>(X / v, Y / v); }


	T getLength() const { return sqrt( X*X + Y*Y ); }


	T dotProduct(const CMathVektor2d<T>& other) const
	{
		return X*other.X + Y*other.Y;
	}
	
	T getDistanceFrom(const CMathVektor2d<T>& other) const
	{
		return CMathVektor2d<T>(X - other.X, Y - other.Y).getLength();
	}

	CMathVektor2d<T>& normalize()
	{
		float length = (float)(X*X + Y*Y);
		if (length == 0.0f)
			return *this;
		length = sqrt(length);
		X = (T)(X / length);
		Y = (T)(Y / length);
		return *this;
	}

	T X;

	T Y;
};

#endif // Vektor2d_h__