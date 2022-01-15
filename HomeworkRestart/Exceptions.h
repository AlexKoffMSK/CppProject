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

	template <typename TFunction> //статический полиморфизм, а есть еще std::function - это динамический полиморфизм
	void CallFunctionNTimes(TFunction function, int n)
	{
		std::vector<int> vec_for_exc;

		for (int i = 0; i < n; ++i)
		{
			try
			{
				function(i);
			}
			catch (int exception)
			{
				vec_for_exc.push_back(exception);
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
			//throw 3.14;
			throw a; //если код попадает сюда, то выполнение данной функции останавливаетс€ и бросаетс€ исключение с типом инт и значением а.
		}
		if (str == "Hello")
		{
			throw str;
		}
		std::cout << "Work with: " << a << " and " << str << std::endl;
	}

	void Test6()
	{
		try
		{
			WorkWithValue1(1, "sdf");
			WorkWithValue1(2, "asd");
			WorkWithValue1(4, "Olleh");
			WorkWithValue1(3, "Hello");
			WorkWithValue1(5, "pop");
		}
		//catch (...)
		//{
		//	std::cout << "Exception has been caught!" << std::endl;
		//}
		catch (int exception)
		{
			std::cout << "Exception with int = " << exception << std::endl;
		}
		catch (std::string exception)
		{
			std::cout << "Exception with string = " << exception << std::endl;
		}
		catch (...)
		{
			std::cout << "Some exception, don't know - which one! All I know - it isn't int or str!" << std::endl;
		}
	}

	void WorkWithValue2(int x)
	{
		if (x == 0)
		{
			throw x;
		}
		std::cout << x << std::endl;
	}

	void WorkWithValue3(int x, std::string str)
	{
		if (str == "Hello")
		{
			throw str;
		}
		WorkWithValue2(x - 1);
		WorkWithValue2(x + 1);
	}

	void Test7()
	{
		try
		{
			WorkWithValue3(1, "World");
		}
		catch (int exception)
		{
			std::cout << exception << std::endl;
		}
		catch (std::string exception)
		{
			std::cout << exception << std::endl;
		}
	}

	void Test8()
	{
		std::vector<int> vec = {1,2,3,4,5};
		//std::cout << vec[7] << std::endl;
		try
		{
			std::cout << vec.at(7) << std::endl;
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}


}