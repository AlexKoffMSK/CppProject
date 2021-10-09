#pragma once
#include <iostream>

namespace Templates
{
	void PrintGreater(int x, int y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}

	void PrintGreater(double x, double y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}

	void PrintGreater(float x, float y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}

	void PrintGreater(std::string x, std::string y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}

	template <class T> 
	void PrintGreaterTemplated(T x, T y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}
	//template <class T>
	//void PrintGreaterTemplated(T x, T y, T z)
	//{
	//	if (x > y)
	//	{
	//		std::cout << x << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << y << std::endl;
	//	}
	//}

	template <class T, class Q>
	void PrintGreaterTemplated1(T x, Q y)
	{
		if (x > y)
		{
			std::cout << x << std::endl;
		}
		else
		{
			std::cout << y << std::endl;
		}
	}

	template <class T>
	void F()
	{
		T a{};
		std::cout << typeid(a).name() << std::endl;
	}

	template <class T, class Q>
	class TestClass
	{
	public:
		int _a;
		T _t;
		Q _q;
	};

	void Test1()
	{
		//int a;
		//std::cout << typeid(a).name() << std::endl;
		
		//PrintGreater(3, 4);
		//PrintGreater(3.5, 3.6);
		//PrintGreater(3.51f, 3.61f);
		//PrintGreater("Ada", "Dad");		
		//
		//PrintGreaterTemplated(3, 4);
		PrintGreaterTemplated(3.5, 3.6);
		//PrintGreaterTemplated(3.51f, 3.61f);
		//PrintGreaterTemplated("Ada", "Dad");
		//PrintGreaterTemplated1(5, 5.3);

		F<int>();
		F<double>();
		F<float>();
		F<string>();

		TestClass<char, std::string> tc;
		tc._a = 3;
		tc._t = '*';
		tc._q = "Hello";

		TestClass<double, float> tcdi;
		tcdi._a = 5;
		tcdi._t = 5.5;
		tcdi._q = 4.232;
	}

	template <class T>
	std::vector<T> BubbleSort1Iteration(std::vector<T> arr)
	{
		//принимает на вход массив, возвращает. Если левый больше чем правый.
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i - 1] > arr[i])
			{
				std::swap(arr[i - 1], arr[i]);
			}
		}
		return arr;
	}

	template <class T>
	std::vector<T> BubbleSort(std::vector<T> arr)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			arr = BubbleSort1Iteration(arr); //перезаписываем массив полностью на каждой итерации его сортировки
		}
		return arr;
	}

	void Test2()
	{
		std::vector<double> vec = { 4.4,4.5,4.6,4.2 };
		vec = BubbleSort(vec);
		for (auto elem : vec)
		{
			std::cout << elem << std::endl;
		}
	}

	template <class T, class Q> class Pair
	{
	public:
		T _t;
		Q _q;
	};
	
	template <int I> void Print(std::tuple<int, int, double, float, string, char, char, char> tpl)
	{
		std::cout << std::get<I>(tpl) << std::endl;
		Print<I-1>(tpl);
	}
	
	template <> void Print<0>(std::tuple<int, int, double, float, string, char, char, char> tpl)
	{
		std::cout << std::get<0>(tpl) << std::endl;
	}

	void Test3()
	{
		//Pair<double, std::string> p;
		//p._t = 2.456;
		//p._q = "Hello";
		//
		//std::pair<double, string> pp;
		//pp.first = 2.3434;
		//pp.second = "String";
		//

		std::tuple<int, int, double, float, string, char, char, char> tpl;
		std::get<0>(tpl) = 5;
		
		Print<7>(tpl);
	}
}