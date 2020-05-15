#pragma once
#include"Shapes.h"
#include"Square.h"
#include <iostream>
using namespace std;


template <class T>
class Cube : public  Shapes
{
private:
	int edge;
	T*** Array;
public:
	Cube();
	Cube(int e, T _value);
	Cube(const Cube& cube);
	~Cube();

	int GetEdge();
	T GetValue();
	void SetEdge(int _edge);

	float Perimeter() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Cube& opt);
};

template<class T>
inline Cube<T>::Cube()
{
	edge = 3;
	Array = new T * *[edge];
	for (int i = 0; i < edge; i++)
	{
		Array[i] = new T *[edge];
		for (int j = 0; j < edge; j++)
			Array[i][j] = new T[edge];
	}
	Array[0][0][0] = '&';
}

template<class T>
inline Cube<T>::Cube(int e, T _value)
{
	edge = e;
	Array = new T * *[edge];
	for (int i = 0; i < edge; i++)
	{
		Array[i] = new T *[edge];
		for (int j = 0; j < edge; j++)
			Array[i][j] = new T[edge];
	}
	for (int i = 0; i < edge; i++)
		for (int j = 0; j < edge; j++)
			for (int l = 0; l < edge; l++)
				Array[i][j][l] = _value;
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
	if (Array != 0)
	{
		for (int i = 0; i < edge; i++)
			for (int j = 0; j < edge; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge; i++)
			delete[] Array[i];
		delete[] Array;
	}
	edge = cube.edge;
	Array = new T * *[edge];
	for (int i = 0; i < edge; i++)
	{
		Array[i] = new T *[edge];
		for (int j = 0; j < edge; j++)
			Array[i][j] = new T[edge];
	}
	for (int i = 0; i < edge; i++)
		for (int j = 0; j < edge; j++)
			for (int l = 0; l < edge; l++)
				Array[i][j][l] = cube.Array[i][j][l];
}

template<class T>
inline Cube<T>::~Cube()
{
	if (Array != 0)
	{
		for (int i = 0; i < edge; i++)
			for (int j = 0; j < edge; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		edge = 0;
	}
}

template<class T>
inline int Cube<T>::GetEdge()
{
	return edge;
}

template<class T>
inline T Cube<T>::GetValue()
{
	return Array[0][0][0];
}

template<class T>
inline void Cube<T>::SetEdge(int _edge)
{
	T tmp = Array[0][0][0];
	if (Array != 0)
	{
		for (int i = 0; i < edge; i++)
			for (int j = 0; j < edge; j++)
				delete[] Array[i][j];
		for (int i = 0; i < edge; i++)
			delete[] Array[i];
		delete[] Array;
	}
	edge = _edge;
	Array = new T * *[edge];
	for (int i = 0; i < edge; i++)
	{
		Array[i] = new T *[edge];
		for (int j = 0; j < edge; j++)
			Array[i][j] = new T[edge];
	}
	for (int i = 0; i < edge; i++)
		for (int j = 0; j < edge; j++)
			for (int l = 0; l < edge; l++)
				Array[i][j][l] = tmp;
}

template<class T>
inline float Cube<T>::Perimeter()
{
	return 12*edge;
}

template<class T>
inline ostream& Cube<T>::print(ostream& off)
{
	Square<T> tmp(edge, Array[0][0][0]);
	tmp.print(off);
	return off;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& opt)
{
	if (edge == opt.edge && Array[0][0][0] == opt.Array[0][0][0])
		return true;
	return false;
}
