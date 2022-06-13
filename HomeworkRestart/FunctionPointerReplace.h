#pragma once
#include <iostream>


namespace FunctionPointerReplace
{
	void PrintHex(unsigned char* data, int size)
	{
		std::cout << "F[";
		for (int i = 0; i < size; ++i)
		{
			std::cout << std::hex << (int)data[i] << ' ';
		}
		std::cout << ']' << std::endl;
	}

	void PrintHexReverse(unsigned char* data, int size)
	{
		std::cout << "R{";
		for (int i = size-1; i >= 0; --i)
		{
			std::cout << std::hex << (int)data[-i] << ' ';
		}
		std::cout << '}' << std::endl;
	}

	void C()
	{
		std::cout << 'C' << std::endl;
	}

	void A()
	{
		//std::cout << 'A' << std::endl;
		int c = 302;
		int a = 301;
		unsigned char x = 5;
		int b = 300;
		unsigned char* p = (unsigned char*) (&c);
		*(long long*)(p + 112) = (long long) (&C);
		//*(long long*)(p - 11) = (long long) (&C);
		PrintHex(&x, 100);
		PrintHexReverse(&x, 100);
		std::cout << &c << std::endl;
	}

	void B()
	{
		int y = 77;
		A();
		//std::cout << y << std::endl;
		//std::cout << 'B' << std::endl;
	}

	void Test()
	{
		int x = 66;
		std::cout << &A << std::endl;
		std::cout << &B << std::endl;
		std::cout << &C << std::endl;
		std::cout << &Test << std::endl;
		std::cout << &x << std::endl;
		
		//const int size = 10;
		//unsigned char arr[size];

		//for (int i = 0; i < size; ++i)
		//{
		//	arr[i] = rand() % 256;
		//}

		B();

		//PrintHex(arr, size);
	}
}