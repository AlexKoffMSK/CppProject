#pragma once
#include<iostream>
#include<functional>

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

#define Endl std::endl;
#define Print(a) std::cout << a << ' ' << __FILE__ << ' ' << __LINE__ << Endl;
#define PrintVariableName(a) std::cout << #a << Endl;

//#define PRINT_LOGS

	bool IsGreater5(int a)
	{
#ifdef PRINT_LOGS
		std::cout << '!' << a << Endl;
#endif
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

	void Test3(int z)
	{
		PrintElemIfItMatchToPredicate(3, 8, IsGreater5);
		PrintElemIfItMatchToPredicate(3, 8, IsOdd);
		PrintElemIfItMatchToPredicate(3, 8, IsPositive);
		PrintElemIfItMatchToPredicate(2, 4, ([z](int a) {return a == 2 && a > z;}) );
	}

	void Test4()
	{
		int p;
		std::cin >> p;
		
		auto IsGreaterP = [p](int a) {return a > p; };
		std::cout << IsGreaterP(5) << std::endl;
		std::cout << IsGreaterP(2) << Endl;
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
		int p=3;
		std::cin >> p;
		int q;
		std::cin >> q;

		auto IsGreaterPAndLesserQ = [p,q](int a) {return (a > p && a < q); };

		std::cout << IsGreaterPAndLesserQ(5) << std::endl;
		std::cout << IsGreaterPAndLesserQ(2) << std::endl;

		Print(p);
		PrintVariableName(p);
	}

	void Test7()
	{
		auto IsSizeGreater5 = [](std::string str) {return str.size() > 5;	};
		auto IsFirstLetterIsA = [](std::string str) {return str[0] == 'A' || str[0] == 'a'; };
		auto IsLastLetterIsA = [](std::string str) {return str.back() == 'A' || str.back() == 'a'; };

		std::cout << IsSizeGreater5("Hello") << std::endl;
		std::cout << IsSizeGreater5("Hello1") << std::endl;
		std::cout << IsFirstLetterIsA("Hello") << std::endl;
		std::cout << IsFirstLetterIsA("Aello") << std::endl;

		auto IsSizeGreater5AndFirstLetterIsA = [IsSizeGreater5, IsFirstLetterIsA](std::string str) {return IsSizeGreater5(str) && IsFirstLetterIsA(str); };

		std::cout << IsSizeGreater5AndFirstLetterIsA("Hello") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA("Hello1") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA("Aello") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA("Aello1") << std::endl;

		auto IsMatchBothPredicates = [](auto AnyLambdaPredicate0, auto AnyLambdaPredicate1)
		{
			return [AnyLambdaPredicate0, AnyLambdaPredicate1](std::string str)
			{
				return AnyLambdaPredicate0(str) && AnyLambdaPredicate1(str); //вернуть тру если применение к этим предикатам данной строки оба вернули тру 
			};
		};

		auto IsSizeGreater5AndFirstLetterIsA_1 = IsMatchBothPredicates(IsSizeGreater5, IsFirstLetterIsA);
		auto IsSizeGreater5AndLastLetterIsA_1 = IsMatchBothPredicates(IsSizeGreater5, IsLastLetterIsA);
		auto IsSizeGreater5AndFirstLetterIsAAndLastLetterIsA_1 = IsMatchBothPredicates(IsSizeGreater5AndLastLetterIsA_1, IsFirstLetterIsA);

		std::cout << IsSizeGreater5AndFirstLetterIsA_1("Hello") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA_1("Hello1") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA_1("Aello") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsA_1("Aello1") << std::endl;

		std::cout << IsSizeGreater5AndFirstLetterIsAAndLastLetterIsA_1("Aello1") << std::endl;
		std::cout << IsSizeGreater5AndFirstLetterIsAAndLastLetterIsA_1("Aelloa") << std::endl;


	}

	void Test8()
	{
		//auto CallTwice = [](auto AnyLambda) {AnyLambda(); AnyLambda(); }; //принимает лямбду и вызывает ее два раза
		
		auto CallTwice = [](auto AnyLambda) //принимает лямбду и вызывает ее два раза
		{
			AnyLambda(); 
			AnyLambda(); 
		}; 

		auto PrintHello = []() {std::cout << "Hello" << std::endl; };
		auto PrintWorld = []() {std::cout << "World" << std::endl; };
		
		CallTwice(PrintHello);
		CallTwice(PrintWorld);

	}

	void Test9()
	{
		//принимает на вход число а и возвращает лямбду которая представляет предикат, принимающий на вход инт и возвращающий тру если инт больше чем а

		auto GetPredicate = [](int a) 
		{
			return [a](int b) {return a < b; };
		};

		std::cout << GetPredicate(5)(9) << std::endl;

		bool is_true_if_predicate_greater_5 = GetPredicate(5)(9);

		auto IsGreater5Lambda = GetPredicate(5);
		auto IsGreater6Lambda = GetPredicate(6);

		bool good = IsGreater5Lambda(4);
		bool good1 = IsGreater5Lambda(8);

		bool good2 = IsGreater6Lambda(5);
		bool good3 = IsGreater6Lambda(7);

	}

	template<typename TFunction>
	void CallThreeTimes(TFunction function)
	{
		function(3);
		function(4);
		function(5);
	}

	void CallThreeTimes1(std::function<void(int)> function)
	{
		function(3);
		function(4);
		function(5);
	}

	void Foo(int x)
	{
		std::cout << x << std::endl;
	}

	void Test10()
	{
		std::function<void(int)> function = Test3;
		function(42);
		function = Foo;
		function(42);
	}
}