#pragma once
#include"Shapes.h"
#include <iostream>
using namespace std;


template <class T>
class Circle : public Shapes
{
private:
	int diameter;
	T** Array;
public:
	Circle();
	Circle(int diam, T _value);
	Circle(const Circle& circle);
	~Circle();

	int GetDiameter();
	T GetValue();
	void SetDiameter(int _diameter);

	float Perimeter() override;
	ostream& print(ostream& off) override;


	bool operator ==(const Circle& opt);
};

inline Circle<char>::Circle()
{
	diameter = 2;
	Array = new char *[2 * diameter - 1];
	for (int i = 0; i < 2 * diameter - 1; i++)
		Array[i] = new char[2 * diameter];

	for (int i = 0; i < diameter; i++)
		for (int j = diameter - 1 - i; j < diameter + i + 1; j++)
			Array[i][j] = '@';

	for (int i = diameter; i < 2 * diameter - 1; i++)
		for (int j = 1 + i - diameter; j < 3 * diameter - 1 - i; j++)
			Array[i][j] = '@';

}

template<class T>
inline Circle<T>::Circle(int diam, T _value)
{
	diameter = diam;
	Array = new T*[2 * diameter - 1];
	for (int i = 0; i < 2 * diameter - 1; i++)
		Array[i] = new T[2 * diameter];

	for (int i = 0; i < diameter; i++)
		for (int j = diameter - 1 - i; j < diameter + i + 1; j++)
			Array[i][j] = _value;

	for (int i = diameter; i < 2 * diameter - 1; i++)
		for (int j = 1 + i - diameter; j < 3 * diameter - 1 - i; j++)
			Array[i][j] = _value;
}

template<class T>
inline Circle<T>::Circle(const Circle& circle)
{
	if (Array != 0)
	{
		for (int i = 0; i < 2 * diameter - 1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	diameter = circle.diameter;
	Array = new T *[2 * diameter - 1];
	for (int i = 0; i < 2 * diameter - 1; i++)
		Array[i] = new T[2 * diameter];

	for (int i = 0; i < diameter; i++)
		for (int j = diameter - 1 - i; j < diameter + i + 1; j++)
			Array[i][j] = circle.Array[i][j];

	for (int i = diameter; i < 2 * diameter - 1; i++)
		for (int j = 1 + i - diameter; j < 3 * diameter - 1 - i; j++)
			Array[i][j] = circle.Array[i][j];
}

template<class T>
inline Circle<T>::~Circle()
{
	if (Array != 0)
	{
		for (int i = 0; i < 2 * diameter - 1; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		diameter = 0;
	}
}

template<class T>
inline int Circle<T>::GetDiameter()
{
	return diameter;
}

template<class T>
inline T Circle<T>::GetValue()
{
	return Array[diameter][diameter];
}

template<class T>
inline void Circle<T>::SetDiameter(int _diameter)
{
	T tmp = this->GetValue();
	if (Array != 0)
	{
		for (int i = 0; i < 2 * diameter - 1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	diameter = _diameter;
	Array = new T *[2 * diameter - 1];
	for (int i = 0; i < 2 * diameter - 1; i++)
		Array[i] = new T[2 * diameter];

	for (int i = 0; i < diameter; i++)
		for (int j = diameter - 1 - i; j < diameter + i + 1; j++)
			Array[i][j] = tmp;

	for (int i = diameter; i < 2 * diameter - 1; i++)
		for (int j = 1 + i - diameter; j < 3 * diameter - 1 - i; j++)
			Array[i][j] = tmp;
}

template<class T>
inline float Circle<T>::Perimeter()
{
	return diameter*3.14;
}

template<class T>
inline ostream& Circle<T>::print(ostream& off)
{
	for (int i = 0; i < 2 * diameter - 1; i++)
	{
		for (int j = 0; j < 2 * diameter; j++)
		{
			if ((i < diameter && j >= (diameter - 1 - i) && j < (diameter + i + 1)) || (i >= diameter && i < (2 * diameter - 1) && j >= (1 + i - diameter) && j < (3 * diameter - 1 - i)))
				off << Array[i][j];
			else off << " ";
		}
		off << endl;
	}
	return off;
}

template<class T>
inline bool Circle<T>::operator==(const Circle& opt)
{
	if (diameter == opt.diameter && Array[diameter][diameter] == opt.Array[diameter][diameter])
		return true;
	return false;
}
