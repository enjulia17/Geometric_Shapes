#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Rectangle : public  Shapes
{
private:
	int side_1;
	int side_2;
	T** Array;
public:
	Rectangle();
	Rectangle(int _side_1, int _side_2, T _value);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();

	int GetSide_1();
	int GetSide_2();
	T GetValue();
	void SetSide(int _side_1, int _side_2);

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Rectangle& opt);
};


inline Rectangle<char>::Rectangle()
{
	side_1 = 1;
	side_2 = 1;
	Array = new char*[1];
	Array[0] = new char[1];
	Array[0][0] = '+';
}

template<class T>
inline Rectangle<T>::Rectangle(int _side_1, int _side_2, T _value)
{
	side_1 = _side_1;
	side_2 = _side_2;
	Array = new T *[side_1];
	for (int i = 0; i < side_1; i++)
		Array[i] = new T[side_2];

	for (int i = 0; i < side_1; i++)
		for (int j = 0; j < side_2; j++)
			Array[i][j] = _value;
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& rectangle)
{
	if (Array != 0)
	{
		for (int i = 0; i < side_1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side_1 = rectangle.side_1;
	side_2 = rectangle.side_2;
	Array = new T *[side_1];
	for (int i = 0; i < side_1; i++)
		Array[i] = new T[side_2];

	for (int i = 0; i < side_1; i++)
		for (int j = 0; j < side_2; j++)
			Array[i][j] = rectangle.Array[i][j];
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
	if (Array != 0)
	{
		for (int i = 0; i < side_1; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		side_1 = 0;
		side_2 = 0;
	}
}

template<class T>
inline int Rectangle<T>::GetSide_1()
{
	return side_1;
}

template<class T>
inline int Rectangle<T>::GetSide_2()
{
	return side_2;
}

template<class T>
inline T Rectangle<T>::GetValue()
{
	return Array[0][0];
}

template<class T>
inline void Rectangle<T>::SetSide(int _side_1, int _side_2)
{
	T tmp = Array[0][0];
	if (Array != 0)
	{
		for (int i = 0; i < side_1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side_1 = _side_1;
	side_2 = _side_2;
	Array = new T *[side_1];
	for (int i = 0; i < side_1; i++)
		Array[i] = new T[side_2];

	for (int i = 0; i < side_1; i++)
		for (int j = 0; j < side_2; j++)
			Array[i][j] = tmp;
}


template<class T>
inline float Rectangle<T>::Perimeter()
{
	return 2*(side_1+side_2);
}

template<class T>
inline ostream& Rectangle<T>::print(ostream& off)
{
	for (int i = 0; i < side_1; i++)
	{
		for (int j = 0; j < side_2; j++)
			off << Array[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Rectangle<T>::operator==(const Rectangle& opt)
{
	if (side_1 == opt.side_1 && side_2 == opt.side_2 && Array[0][0] == opt.Array[0][0])
		return true;
	return false;
}
