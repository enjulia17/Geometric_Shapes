#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Simplex : public  Shapes
{
private:
	int height;
	T** Array;

public:
	Simplex();
	Simplex(int _height, T _value);
	Simplex(const Simplex& simplex);
	~Simplex();

	int GetHeight();
	T GetValue();
	void SetHeight(int _height);

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Simplex& opt);
};


inline Simplex<char>::Simplex()
{
	height = 5;
	Array = new char *[height];
	for (int i = 0; i < height; i++)
		Array[i] = new char[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			Array[i][j] = '^';
}

template<class T>
inline Simplex<T>::Simplex(int _height, T _value)
{
	height = _height + 1;

	Array = new T *[height];
	for (int i = 0; i < height; i++)
		Array[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			Array[i][j] = _value;
}

template<class T>
inline Simplex<T>::Simplex(const Simplex& simplex)
{
	if (Array != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] Array[i];
		delete[] Array;
	}
	height = simplex.height;

	Array = new T *[height];
	for (int i = 0; i < height; i++)
		Array[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			Array[i][j] = simplex.Array[i][j];
}

template<class T>
inline Simplex<T>::~Simplex()
{
	if (Array != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		height = 0;
	}
}

template<class T>
inline int Simplex<T>::GetHeight()
{
	return height - 1;
}

template<class T>
inline T Simplex<T>::GetValue()
{
	return T();
}

template<class T>
inline void Simplex<T>::SetHeight(int _height)
{
	T tmp = this->GetValue();
	if (Array != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] Array[i];
		delete[] Array;
	}
	height = _height + 1;


	Array = new T *[height];
	for (int i = 0; i < height; i++)
		Array[i] = new T[height];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			Array[i][j] = tmp;
}

template<class T>
inline float Simplex<T>::Perimeter()
{
	return 3 * (height - 1);
}

template<class T>
inline ostream& Simplex<T>::print(ostream& off)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i; j++)
			off << Array[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Simplex<T>::operator==(const Simplex& opt)
{
	if (height == opt.height && Array[0][0] == opt.Array[0][0])
		return true;
	return false;
}
