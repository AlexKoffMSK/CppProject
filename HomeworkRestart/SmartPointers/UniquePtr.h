#pragma once
#include <iostream>
#include <memory>

namespace SmartPointers
{
	void Test1()
	{
		//int* a = new int[1];
		int* a = new int;

		int b = rand() % 10;
		if (b > 5)
		{
			std::cout << '2' << std::endl;
			delete a;
			return;
		}
		
		int c = rand() % 10;
		if (c < 5)
		{
			std::cout << '3' << std::endl;
			delete a;
			return;
		}
		std::cout << '1' << std::endl;
		delete a;
	}

	void Test2()
	{
		std::unique_ptr<int> a(new int);

		int b = rand() % 10;
		if (b > 5)
		{
			std::cout << '2' << std::endl;
			return;
		}

		int c = rand() % 10;
		if (c < 5)
		{
			std::cout << '3' << std::endl;
			return;
		}
		std::cout << '1' << std::endl;
	}

	void Test3()
	{
		std::unique_ptr<int> a(new int);

		std::unique_ptr<int> b;

		b = std::move(a);
	}

	void Test4()
	{
		std::unique_ptr<int[]> a(new int[10]);
		//a = new int[10];
		std::unique_ptr<int[]> b;

		b = std::move(a);
	}

	const int kN = 10;

	class MoveSemanticsClass
	{
	public:
		std::unique_ptr<int[]> _arr;

		MoveSemanticsClass()
			:_arr(new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = i;
			}
		}

		~MoveSemanticsClass()
		{
		}

		MoveSemanticsClass(const MoveSemanticsClass& parametr)
			:_arr(new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
		}

		MoveSemanticsClass(MoveSemanticsClass&& parametr)
		{
			_arr = std::move(parametr._arr);
		}

		MoveSemanticsClass(int num)
			:_arr (new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = num;
			}
		}

		void Print()
		{
			for (int i = 0; i < kN; ++i)
			{
				std::cout << _arr[i] << ' ';
			}
			std::cout << std::endl;
		}

		void operator=(const MoveSemanticsClass& parametr)
		{
			_arr.reset(new int[kN]);
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
		}
		void operator=(MoveSemanticsClass&& parametr)
		{
			_arr = std::move(parametr._arr);
		}
	};


































}