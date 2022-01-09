#pragma once
#include <iostream>

namespace Exceptions
{
	int GetValue(int a)
	{
		if (a == 0)
		{
			throw std::exception("Division by zero!"); //если код попадает сюда, то выполнение данной функции останавливаетс€ и бросаетс€ исключение с текстом Division by zero!.
		}
		return (a + 3) / a;
	}

	void Test0()
	{
		try //мы объ€вл€ем область, в которой мы будем ловить исключени€
		{ 
			std::cout << GetValue(3) << std::endl;
			std::cout << GetValue(-1) << std::endl;
			std::cout << GetValue(0) << std::endl;
			std::cout << GetValue(4) << std::endl;
		}
		catch (std::exception ex) //мы попадем сюда если в блоке, который находитс€ выше этой строки будет кинуто исключение std::exception
		{
			std::cout << ex.what() << std::endl;
		}
	}

	void Test1()
	{
		for (int i=0; i<1000000; ++i)
		{
			try //мы объ€вл€ем область, в которой мы будем ловить исключени€
			{
				std::cout << GetValue(rand() % 5 - 2) << std::endl;
			}
			catch (std::exception ex) //мы попадем сюда если в блоке, который находитс€ выше этой строки будет кинуто исключение std::exception
			{
				std::cout << ex.what() << std::endl;
			}
		}
	}

	void WorkWithValue(int a)
	{
		if (a % 2 == 0)
		{
			throw a; //если код попадает сюда, то выполнение данной функции останавливаетс€ и бросаетс€ исключение с типом инт и значением а.
		}
		std::cout << "Work with a: " << a << std::endl;
	}

	void Test2()
	{
		try
		{
			WorkWithValue(3);
			WorkWithValue(5);
			WorkWithValue(2);
			WorkWithValue(9);
		}
		catch (int ex)
		{
			std::cout << "Caught int exception with value: " << ex << std::endl;
		}
	}

	void Test3()
	{
		std::vector<int> vec_for_exc;
		for (int i = 0; i < 100; ++i)
		{
			try
			{
				WorkWithValue(rand() % 5 - 4);
			}
			catch (int a)
			{
				vec_for_exc.push_back(a);
			}
		}
		print_vector(vec_for_exc);
	}

	template <typename TFunction>
	void CallFunctionNTimes(TFunction function, int n)
	{
		std::vector<int> vec_for_exc;
		
		for (int i = 0; i < n; ++i)
		{
			try
			{
				function(i);
			}
			catch (int a)
			{
				vec_for_exc.push_back(a);
			}
		}
		print_vector(vec_for_exc);
	}

	void Test5()
	{
		CallFunctionNTimes(WorkWithValue, 10);

		CallFunctionNTimes([](int a) {std::cout << '!' << a << std::endl; }, 10);

		auto PrintAllExcept3 = [](int a) 
		{
			if (a == 3 || a == 5)
			{
				throw a;
			}
			std::cout << "!!" << a << std::endl;
		};

		CallFunctionNTimes(PrintAllExcept3, 7);
	}

	void WorkWithValue1(int a, std::string str)
	{
		if (a == 4)
		{
			throw a; //если код попадает сюда, то выполнение данной функции останавливаетс€ и бросаетс€ исключение с типом инт и значением а.
		}
		if (str == "Hello")
		{
			throw str;
		}
		std::cout << "Work with: " << a << " and " << str << std::endl;
	}

	void Test5()
	{
		
	}










}