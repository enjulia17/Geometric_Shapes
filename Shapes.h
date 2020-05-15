#pragma once
#include <iostream>
using namespace std;
class Shapes
{
public:
	virtual ~Shapes() {}
	virtual float Perimeter() = 0;
	virtual ostream& print(ostream& off) = 0;
	friend ostream& operator<<(ostream& off, Shapes& opt)
	{
		return opt.print(off);
	}
	bool operator > (Shapes& opt)
	{
		if (this->Perimeter() > opt.Perimeter())
			return true;
		return false;
	}
	bool operator < (Shapes& opt)
	{
		if (this->Perimeter() < opt.Perimeter())
			return true;
		return false;
	}
};
