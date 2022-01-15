#pragma once
#include <iostream>

namespace Initialization
{
	class A
	{
		int _x;	//это не создание пол€, а объ€вление будущей конструкции, здесь не происходит создание значений
		int _y;

	public:
		A(int x_, int y_)
		{
			_x = x_;
			_y = y_;
		}
	};

	class B
	{
		int _c;
		A _a;

	public:
		B(int ax_, int ay_, int c_)
			: _a(ax_,ay_)
		{
			_c = c_;
		}
	};

	void Test()
	{
		//A a;
		A a(4, 5);
		B b(3,4,5);
	}

	class C
	{
		int& _ref;

	public:
		C(int& ref_)
			: _ref(ref_)
		{
		}
	};











}