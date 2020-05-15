#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Square : public  Shapes
{
private:
	int side;
	T** Array;
public:
	Square();
	Square(int s, T _value);
	Square(const Square& square);
	~Square();

	int GetSide();
	T GetValue();
	void SetSide(int _side);

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Square& opt);
};


inline Square<char>::Square()
{
	side = 2;
	Array = new char *[2];
	Array[0] = new char[2];
	Array[0][0] = '#';
}

template<class T>
inline Square<T>::Square(int s, T _value)
{
	side = s;
	Array = new T *[side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];

	for (int i = 0; i<side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = _value;
}

template<class T>
inline Square<T>::Square(const Square& square)
{
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = square.side;
	Array = new T *[side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];

	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = square.Array[i][j];
}

template<class T>
inline Square<T>::~Square()
{
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		side = 0;
	}
}

template<class T>
inline int Square<T>::GetSide()
{
	return side;
}

template<class T>
inline T Square<T>::GetValue()
{
	return Array[0][0];
}

template<class T>
inline void Square<T>::SetSide(int _side)
{
	T tmp = Array[0][0];
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = _side;
	Array = new T *[side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];

	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = tmp;
}


template<class T>
inline float Square<T>::Perimeter()
{
	return 4 * side;
}

template<class T>
inline ostream& Square<T>::print(ostream& off)
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
			off << Array[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Square<T>::operator==(const Square& opt)
{
	if (side == opt.side && Array[0][0] == opt.Array[0][0])
		return true;
	return false;
}