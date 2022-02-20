#pragma once
#include <iostream>

namespace VirtualInheritance
{
	struct A
	{
		int _a;
	};

	struct B_Composition //когда внутри класса интегрируется другой класс - это композиция
	{
		A _a;
		int _b;
	};

	struct B :virtual public A
	{
		int _b;
	};

	struct C :virtual public A
	{
		int _c;
	};

	struct D :public B, public C
	{
		int _d;
	};

	void TestVirtInher()
	{
		B b;
		D d;
		d._a = 3;
		d.C::_a = 2;
		d._b = 4;
	}

	struct AA
	{
		int _a;
	};

	struct BB :public AA
	{
		int _a;
	};

	void Test2()
	{
		BB b;
		b._a = 3;
		b.AA::_a = 5;
		int a = 0;

		B_Composition bc;
		B u;
		bc._a._a = 88;
		b._a = 99;
	}

	struct AAA
	{
		int _a;
		int _b;
		int _c;
	};

	struct BBB: private AAA
	{
		void T()
		{
			_a = 3;
		}

		int GetB()
		{
			return _b;
		}
		int GetC()
		{
			return _c;
		}
		void SetB(int x)
		{
			_b = x;
		}
	};

	void Test3()
	{
		BBB b;

		std::deque<int> deq;
		std::queue<int> qu;
		qu.push(4);
	}



















}