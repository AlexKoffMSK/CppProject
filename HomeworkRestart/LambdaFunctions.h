#pragma once
#include<iostream>

//Лямбда-функции(выражения)

namespace LambdaFunctions
{
	int SummTwoInts(int a, int b)
	{
		return a + b;
	}

	bool CompareTwoInts(int a, int b)
	{
		return (a > b);
	}
	
	void Test1()
	{
		//Создали лямбда-функцию, которая называется SummOfTwoInts. Она принимает два инта, возвращает сумму. Важный момент - в конце стоит ";", т.к. это оператор(инструкция) внутри кода.
		auto SummOfTwoInts = [](int a, int b) -> int
		{
			return a + b;
		};
		
		std::cout << SummTwoInts(3, 5) << std::endl;
		std::cout << SummTwoInts(4, 6) << std::endl;		
		
		std::cout << SummOfTwoInts(3, 5) << std::endl;
		std::cout << SummOfTwoInts(4, 6) << std::endl;
	}

	void Test2()
	{
		std::vector<int> vec{5,3,7,5,7,9,5,3,7,8,34,6,4,7,4};
		//std::sort(vec.begin(), vec.end());
		//print_vector(vec);
		//
		//std::sort(vec.begin(), vec.end(), CompareTwoInts);
		//print_vector(vec);

		auto CompareOfTwoInts = [](int a, int b)
		{
			return a > b;
		};

		std::sort(vec.begin(), vec.end(), CompareOfTwoInts);
		print_vector(vec);

		std::sort(vec.begin(), vec.end(), [](int a, int b)
			{
				return a > b;
			}
		);
	}

	//Предикат - это функция, которая принимает объект (например int) и возвращает bool.

	template <typename TFunction>
	void PrintElemIfItMatchToPredicate(int elem1, int elem2, TFunction predicate)
	{
		if (predicate(elem1))
		{
			std::cout << elem1 << std::endl;
		}
		if (predicate(elem2))
		{
			std::cout << elem2 << std::endl;
		}
	}

	bool IsGreater5(int a)
	{
		return a > 5;
	}

	bool IsOdd(int a)
	{
		return a & 0x01;
		//a=2 = 0000 0010 = 0000 0000
		//a=3 = 0000 0011 = 0000 0001
		//a=4 = 0000 0100 = 0000 0000
		//a=5 = 0000 0101 = 0000 0001
	}

	bool IsPositive(int a)
	{
		return a > 0;
	}

	void Test3()
	{
		PrintElemIfItMatchToPredicate(3, 8, IsGreater5);
		PrintElemIfItMatchToPredicate(3, 8, IsOdd);
		PrintElemIfItMatchToPredicate(3, 8, IsPositive);
		PrintElemIfItMatchToPredicate(2, 4, ([](int a) {return a == 2;}) );
	}

	void Test4()
	{
		int p;
		std::cin >> p;
		
		auto IsGreaterP = [p](int a) {return a > p; };
		std::cout << IsGreaterP(5) << std::endl;
		std::cout << IsGreaterP(2) << std::endl;
	}
	
	void Test5()
	{
		std::string str;
		std::getline(std::cin,str);

		auto CountOfCharsInStr = [str](char ch) {return std::count(str.begin(),str.end(),ch); };

		std::cout << CountOfCharsInStr(' ') << std::endl;
		std::cout << CountOfCharsInStr('a') << std::endl;
	}

	void Test6()
	{
		int p;
		std::cin >> p;
		int q;
		std::cin >> q;

		auto IsGreaterPAndLesserQ = [p,q](int a) {return (a > p && a < q); };

		std::cout << IsGreaterPAndLesserQ(5) << std::endl;
		std::cout << IsGreaterPAndLesserQ(2) << std::endl;
	}





}