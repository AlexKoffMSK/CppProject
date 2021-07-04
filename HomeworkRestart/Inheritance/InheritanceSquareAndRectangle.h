#pragma once
#include <iostream>

namespace InheritanceRectAndSquare
{
	class Rectangle
	{
	protected:
		int _a = 0;
		int _b = 0;
	
	public:	
		Rectangle(int a_, int b_)
		{
			_a = a_;
			_b = b_;
		}

		void PrintRect()
		{
			std::cout << "Rectangle: " << "a: " << _a << ' ' << "b: " << _b << std::endl;
		}
	};

	class Square:public Rectangle
	{
	public:
		Square(int a_)
			:Rectangle(a_,a_)
		{
		}

		void PrintSquare()
		{
			std::cout << "Square: " << "a: " << _a << std::endl;
		}
	};

	void Test()
	{
		Rectangle rec(5,6);
		Square sq(5);

		rec.PrintRect();
		sq.PrintSquare();
		sq.PrintRect();
	}




}