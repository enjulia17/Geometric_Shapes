#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Point : public  Shapes
{
private:
	T value;
public:
	Point();
	Point(T _value);
	Point(const Point& point);

	T Get();

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Point& opt);

};

template<class T>
inline Point<T>::Point()
{
	value = '.';
}

template<class T>
inline Point<T>::Point(T _value)
{
	value = _value;
}

template<class T>
inline Point<T>::Point(const Point& point)
{
	value = point.value;
}

template<class T>
inline T Point<T>::Get()
{
	return value;
}



template<class T>
inline float Point<T>::Perimeter()
{
	return 0;
}

template<class T>
inline ostream& Point<T>::print(ostream& off)
{
	off << this->Get();
	return off;
}

template<class T>
inline bool Point<T>::operator==(const Point& opt)
{
	if (value == opt.value)
		return true;
	return false;
}

