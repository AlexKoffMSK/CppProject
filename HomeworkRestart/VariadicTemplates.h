#pragma once
#include <iostream>

namespace VariadicTemplate
{
	//template<class T>
	//void F(T x)
	//{
	//	std::cout << x << std::endl;
	//}

	template<class... Args>
	void F(Args... args)
	{
		//(E op ...) becomes (E1 op (... op (EN-1 op EN)))
		//(args << ...) becomes (args1 << (args2 << args3))
		//std::cout << (args << ...) becomes std::cout << (args1 << (args2 << args3))
		//std::cout << (args << ...) << std::endl;

		//(... op E) becomes (((E1 op E2) op ...) op EN)
		//std::cout << (... << args) becomes std::cout << (((args1 << args2) << args3)

		//(I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)
		//I это какая-то операция, может быть даже std::cout, любое выражение, которое может сюда подойти
		//op - это в нашем случае стрелочки, 
		// E в нашем случае это args, 
		// многоточие - это ключевое слово
		//(std::cout << ... << args) becomes (((std::cout << args1) << args2) << args3)
		
		//(std::cout << ... << args) << std::endl;
		((std::cout << args << ' '), ...) << std::endl;
		//E = (std::cout << ' '  << args)
		//E1 = (std::cout << ' '  << args1)
		//E2 = (std::cout << ' '  << args2)
		//(E op ...) becomes (E1 op (... op (EN-1 op EN))) 
		// op - это запятая в нашем случае 
		//((std::cout << ' ' << args), ...) becomes ((std::cout << ' ' << args1), (std::cout << ' '  << args2), (std::cout << ' '  << args3)
		//((std::cout << args), ...) becomes ((std::cout << args1), (std::cout << args2), (std::cout << args3)
	}

	double GetSumm1(double args1, float args2, int args3)
	{
		return args1 + args2 + args3;
		
	}

	template<class... Args>
	void PrintSumm(Args... args)
	{
		double summ = 0;
		summ = (args + ...);
		//summ = (args1 + (args2 + (args3)));
		std::cout << summ << std::endl;
	}

	template<typename... Args>
	auto GetSumm(Args... args)
	{
		return (args + ...);
	}

	template<typename... Args>
	void VecPushBackArgs(std::vector<int>& vec, Args... args)
	{
		(vec.push_back(args),...);
		
		//vec.push_back(args1,args2,args3)
	}

	int Mult2(int x)
	{
		return x * 2;
	}

	int Add3(int x)
	{
		return x + 3;
	}

	template<typename... Args>
	void Test2(Args... args)
	{
		((std::cout << args << ' '), ...) << std::endl;
		((std::cout << Mult2(args) << ' '), ...) << std::endl;
		((std::cout << Add3(Mult2(args)) << ' '), ...) << std::endl;
	}

	void Test1()
	{
		F(4);
		F("Str");
		F(4, "Str");
		F(4., 5, "Str");
		F(4, 5, "Str", "Tdr");
		F('C', true, 4., 7.f, "Str", "Tdr");
		PrintSumm(3.14, 5.f, 8);
		std::cout << GetSumm(3.14, 5.f, 8) << std::endl;
		std::cout << GetSumm(std::string("Str"), std::string("Tdr")) << std::endl;
		std::vector<int> vec;
		VecPushBackArgs(vec, 2, 3, 4);
		print_vector(vec);
		VecPushBackArgs(vec, 1);
		print_vector(vec);
		VecPushBackArgs(vec, 1,99);
		print_vector(vec);
		Test2(2, 3, 4);
	}




























}