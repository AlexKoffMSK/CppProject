#pragma once
#include <iostream>

namespace Inheritance
{
	struct Base
	{
		int a;
		std::string b;

		void PrintBase()
		{
			std::cout << a << ' ' << b << std::endl;
		}
	};

	struct Child:Base
	{
		int c;

		void PrintChild()
		{
			PrintBase();
			std::cout << c << std::endl;
		}
	};

	void PrintTest1(Base b)
	{
		std::cout << "PrintTest1 " << "b: " << b.b << '-' << b.a + 1 << std::endl;
	}

	void Test()
	{
		Base b;
		b.a = 4;
		b.b = "Hello";

		Child c;
		c.a = 5;
		c.b = "World";
		c.c = 1;

		b.PrintBase();
		c.PrintBase();
		c.PrintChild();

		PrintTest1(b);
		PrintTest1(c);
	}


	struct A
	{
		int _a;
	};

	struct D
	{
		int _d;
	};

	struct B : public A //наследование - является, B является А с допами, В может делать то же, что и А
	{
		int _b;
	};

	struct BB : public A, public D //наследование 
	{
		int _b;
	};

	struct C //композиция - состоит из А и допов, С не может делать то же, что и А
	{
		A _d;
		int _c;
	};

	void InA(A a)
	{
		std::cout << a._a << std::endl;
	}

	void Test111()
	{
		A a{ 1 };
		B b{ 2,5 };
		C c{ 3,6 };

		std::cout << a._a << std::endl;
		std::cout << b._a << ' ' << b._b << std::endl;
		std::cout << c._d._a << ' ' << c._c << std::endl;

		InA(a);
		InA(b);
		InA(c._d);
	}








}