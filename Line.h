#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Line : public  Shapes
{
private:
	int length;
	T* Array;
public:
	Line();
	Line(int leng, T _value);
	Line(const Line& line);
	~Line();

	int GetLeng();
	T GetValue();
	void SetLeng(int leng);


	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Line& opt);
};

template<class T>
inline Line<T>::Line()
{
	length = 8;
	Array = new char[length];
	for (int i = 0; i < length; i++)
		Array[i] = "-";
}

template<class T>
inline Line<T>::Line(int leng, T _value)
{
	length = leng;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = _value;
}

template<class T>
inline Line<T>::Line(const Line& line)
{
	if (Array != 0)
		delete[] Array;
	length = line.length;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = line.Array[i];
}

template<class T>
inline Line<T>::~Line()
{
	if (Array != 0)
	{
		delete[] Array;
		Array = 0;
		length = 0;
	}
}

template<class T>
inline int Line<T>::GetLeng()
{
	return length;
}

template<class T>
inline T Line<T>::GetValue()
{
	return Array[0];
}

template<class T>
inline void Line<T>::SetLeng(int leng)
{
	T tmp = Array[0];
	if (Array != 0)
		delete[] Array;
	length = leng;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = tmp;
}


template<class T>
inline float Line<T>::Perimeter()
{
	return 0;
}

template<class T>
inline ostream& Line<T>::print(ostream& off)
{
	for (int i = 0; i < length; i++)
		off << Array[i];
	off << endl;
	return off;
}

template<class T>
inline bool Line<T>::operator==(const Line& opt)
{
	if (length == opt.length && Array[0] == opt.Array[0])
		return true;
	return false;
}
