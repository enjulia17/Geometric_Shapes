#pragma once
#include"Shapes.h"
#include"Point.h"
#include"Line.h"
#include"Circle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Cube.h"
#include"Simplex.h"


class Container
{
private:
	Shapes** Array;
	int size;
public:
	Container();
	~Container();

	template <class A>
	void Add(A& elem);
	template <class A>
	void Delete(A& elem);
	template <class A>
	void Off(A& elem);

	Shapes* operator[](const int i);
	friend ostream& operator<<(ostream& off, Container& opt);
};


Container::Container()
{
	size = 0;
	Array = 0;
}


Container::~Container()
{
	delete[] Array;
}

Shapes* Container::operator[](const int i)
{
	return Array[i];
}


template<class A>
void Container::Add(A& elem)
{
	Shapes** tmp = new Shapes *[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Shapes *[size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	Array[size - 1] = &elem;
	delete[]tmp;
}

template<class A>
void Container::Delete(A& elem)
{
	Shapes** tmp = new Shapes *[size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (Array[i] == &elem)
		{
			k = 1;
		}
		else
		{
			tmp[j] = Array[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] Array;
	Array = new Shapes *[size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		Array[i] = tmp[i];
	delete tmp;
}

template<class A>
void Container::Off(A& elem)
{
	cout << elem;
}

ostream& operator<<(ostream& off, Container& opt)
{
	for (int i = 0; i < opt.size; i++)
	{
		off << *(opt[i]) << endl;
	}
	return off;
}