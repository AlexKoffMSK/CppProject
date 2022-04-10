#pragma once
#include <iostream>

namespace AlgoTasks::Conditions
{
	//Пользователь вводит 2 числа, если эти числа одинакового знака, то вывести “yes”, если разного, то запросить у пользователя еще число и вывести на экран 2 числа одинакового знака(третье число там точно будет)
	void Task7()
	{
		int a;
		int b;

		std::cin >> a >> b;
		if (a > 0 && b > 0 || a < 0 && b < 0)
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			//a < 0 , b > 0
			//a > 0 , b < 0
			int c;
			std::cin >> c;
			
			if (a > 0)
			{
				//a > 0, b < 0
				if (c > 0)
				{
					//a > 0, b < 0, c > 0
					std::cout << a << c << std::endl;
				}
				else
				{
					//a > 0, b < 0, c < 0
					std::cout << b << c << std::endl;
				}
			}
			else
			{
				//a < 0, b > 0
				if (c > 0)
				{
					std::cout << b << c << std::endl;
				}
				else
				{
					//a < 0, b > 0, c < 0
					std::cout << a << c << std::endl;
				}
			}
		}
	}

	void Task7_1()
	{
		int a;
		int b;

		std::cin >> a >> b;
		if ((a * b) > 0)
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			int c;
			std::cin >> c;
			if ((a * c) > 0)
			{
				std::cout << a << c << std::endl;
			}
			else
			{
				std::cout << b << c << std::endl;
			}
		}
	}

	//Пользователь вводит 3 числа. Вывести максимальное из них.
	void Task9()
	{
		int a, b, c;
		std::cin >> a>> b>> c;
		if (a > b)
		{
			if (b > c)
			{
				std::cout << a << std::endl;
			}
			else
			{
				//a>=b, c>=b
				if (a < c)
				{
					std::cout << c << std::endl;
				}
				else
				{
					//a>=c,c>=b
					std::cout << a << std::endl;
				}
			}
		}
		else
		{
			//b>=a
			if (a > c)
			{
				std::cout << b << std::endl;
			}
			else
			{
				//a<=c, a<=b
				if (b > c)
				{
					std::cout << b << std::endl;
				}
				else
				{
					//b<=c,a<=c
					std::cout << c << std::endl;
				}
			}
		}
	}

	void Task9_1()
	{
		int a, b, c, t;
		std::cin >> a>> b>> c;
		if (a > b)
		{
			t = a;
		}
		else
		{
			t = b;
		}
		if (t > c)
		{
			std::cout << t << std::endl;
		}
		else
		{
			std::cout << c << std::endl;
		}
	}

	//Пользователь вводит 3 числа. Вывести эти 3 числа в порядке возрастания.
	void Task10()
	{
		int a, b, c, tmax;
		std::cin >> a >> b >> c;

		if (a > b)
		{
			std::swap(a, b);
		}
		if (b > c)
		{
			std::swap(b, c);
		}
		//5 6 1
		//5 1 6
		if (a > b)
		{
			std::swap(a, b);
		}

		std::cout << b << a << c << std::endl;
	}

	void Task15()
	{
		int a,b,c,h;
		std::cin >> a >> b >> c >> h;
		int dist_ac = abs(c - a);
		int dist_ab = abs(b - a) + h;
		int dist_bc = abs(b - c) + h;
		if ((dist_ab + dist_bc) > (dist_ac + dist_bc))
		{
			std::cout << "acb" << std::endl;
		}
		else
		{ 
			std::cout << "abc" << std::endl;
		}
	}

















}