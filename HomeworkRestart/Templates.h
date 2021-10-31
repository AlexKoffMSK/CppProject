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
	T GetGreater(T x, T y)
	{
		if (x > y)
		{
			return x;
		}
		else
		{
			return y;
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

	template <class T> void F()
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
	
	template <int I> void PrintTuple(std::tuple<int, int, double, float, string, char, char, char> tpl)
	{
		std::cout << std::get<I>(tpl) << std::endl;
		PrintTuple<I-1>(tpl);
	}
	
	template <> void PrintTuple<0>(std::tuple<int, int, double, float, string, char, char, char> tpl)
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
		
		PrintTuple<7>(tpl);
	}

	template <class T> void PrintTemplateTypeName()
	{
		std::cout << typeid(T).name() << std::endl;
	}

	void Test4()
	{
		PrintTemplateTypeName<int>();
		PrintTemplateTypeName<double>();
		PrintTemplateTypeName<std::string>();
	}

	template <class T>
	void PrintGreaterTemplated2(T x, T y)
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

	template <class TFunction>
	void CallTwice(TFunction function)
	{
		function(5);
		function(5);
	}

	void PrintHello(int x)
	{
		std::cout << "Hello" << ' ' << x << std::endl;
	}

	void PrintWorld(int x)
	{
		std::cout << "World" << ' ' << x << std::endl;
	}

	void Test6()
	{
		CallTwice(PrintHello);
		CallTwice(PrintWorld);
	}

	template <class T> 
	void PrintTwice(T x)
	{
		std::cout << x << std::endl;
		std::cout << x << std::endl;
	}

	template <class T>
	bool IsXGreaterY(const T& x, const T& y)
	{
		return x>y;
	}

	template <class T>
	bool IsXLesserY(const T& x, const T& y)
	{
		return x < y;
	}

	void Test5()
	{
		std::vector<int> vec = { 5,6,7,8,3,5,8,3,6,2,8 };
		
		std::sort(vec.begin(), vec.end(), IsXGreaterY<int>);
		print_vector(vec);
		
		std::sort(vec.begin(), vec.end(), IsXLesserY<int>);
		print_vector(vec);

		std::vector<std::string> vecstr = { "asd","def","gasdfa","ihiosdjfkl" };

		std::sort(vecstr.begin(), vecstr.end(), IsXGreaterY<std::string>);
		print_vector(vecstr);

		std::sort(vecstr.begin(), vecstr.end(), IsXLesserY<std::string>);
		print_vector(vecstr);
	}

	template <class TFunction>
	void IncrementAndPrintEveryNStep(TFunction function, int n)
	{
		for (int i = 0; i < 50; ++i)
		{
			Print(i);
			if (i % n == 0)
			{
				function(i);
			}
		}
	}

	void Test7()
	{
		IncrementAndPrintEveryNStep(PrintHello,10);
		IncrementAndPrintEveryNStep(PrintWorld,5);
	}
	
}