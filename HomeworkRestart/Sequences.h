#pragma once
#include <string>
#include <iostream>
#include "DataStructures/Queue.h"

namespace Sequences
{
	void Summ()
	{
		int n;
		int a;
		int b = 0;
		std::cin >> n;

		for (int i = 0; i < n; i++)
		{
			std::cin >> a;
			b += a;
		}
	}

	void CheckIsIncrease()
	{
		// -1 2 3
		int n;
		int a = 0;
		std::cin >> n;
		std::cin >> a;
		int b = a;

		bool is_increase = true;
		for (int i = 0; i < n - 1; i++)
		{
			std::cin >> a;
			if (a < b)
			{
				is_increase = false;
			}
			std::cout << a << ' ' << b << std::endl;

			b = a;
		}
		std::cout << is_increase << std::endl;
	}

	void PrintMinimum()
	{
		int n;
		int a = 0;
		std::cin >> n;
		std::cin >> a;
		int min = a;

		for (int i = 0; i < n - 1; i++)
		{
			std::cin >> a;
			if (a < min)
			{
				min = a;
			}
		}
		std::cout << min << std::endl;
	}

	void LocalMinimum()
	{
		//вывести все локальные минимумы последовательности
		//локальный минимум - элемент последовательности, который меньше своих соседей
		//соседи:
		//	- для самого первого элемента - это второй элемент, 
		//	- для последнего - это предпоследний
		//	- для всех остальных это предыдущий и следующий

		// 4 3 7 8 10 3 4 2 1 5
		//   3        3     1

		int n;
		int a = 0;
		std::cin >> n;
		int prev;
		int prevprev;
		std::cin >> a;
		prevprev = a;
		std::cin >> a;
		prev = a;
		if (prevprev < prev)
		{
			std::cout << prevprev << std::endl;
		}
		for (int i = 0; i < n - 2; i++)
		{
			std::cin >> a;
			//std::cout << prevprev << ' ' << prev << ' ' << a << std::endl;
			if (prev < prevprev && prev < a)
			{
				std::cout << prev << std::endl;
			}
			prevprev = prev;
			prev = a;
		}
		if (prev < prevprev)
		{
			std::cout << prev << std::endl;
		}
	}

	void LocalMinimumAdv()
	{
		//5 4 3 3 3 6 4 4 5
		//    3 3 3   4 4

		int n;
		int a = 0;
		std::cin >> n;
		int prev;
		int prevprev;
		std::cin >> a;
		prevprev = a;
		std::cin >> a;
		prev = a;
		if (prevprev < prev)
		{
			std::cout << prevprev << std::endl;
		}
		for (int i = 0; i < n - 2; i++)
		{
			std::cin >> a;
			//std::cout << prevprev << ' ' << prev << ' ' << a << std::endl;
			if (a != prev)
			{
				if (prev < prevprev && prev < a)
				{
					std::cout << prev << std::endl;
				}
				prevprev = prev;
				prev = a;
			}
		}
		if (prev < prevprev)
		{
			std::cout << prev << std::endl;
		}
	}

	void CheckIsEven()
	{
		int n;
		std::cin >> n;
		int a;

		bool is_even = true;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a;
			if (a%2 !=0)
			{
				is_even = false;
			}
		}
		std::cout << is_even << std::endl;
	}

	void AmountOfNegatives()
	{
		int n;
		int a;
		std::cin >> n;
		int counter_of_negatives=0;

		for (int i = 0; i < n; i++)
		{
			std::cin >> a;
			if (a < 0)
			{
				counter_of_negatives++;
			}
		}
		std::cout << counter_of_negatives << std::endl;
	}

	void CheckIfFirstElemBiggerLast()
	{
		int n;
		int a;
		std::cin >> n;
		int first_elem = 0;
		std::cin >> a;
		first_elem = a;

		for (int i = 0; i < n-1; i++)
		{
			std::cin >> a;
		}
		if (a < first_elem)
		{
			std::cout << "FirstIsBigger" << std::endl;
		}
		else
		{
			std::cout << "LastIsBigger" << std::endl;
		}
	}

	void CheckSummFirst2BiggerSummLast2()
	{
		int n;
		std::cin >> n;
		int a;
		int summ_of_first_two;
		int summ_of_last_two;

		for (int i = 0; i < n - 1; i++)
		{

		}
	}

	void PrintCentralElem()
	{
		int n;
		std::cin >> n;
		int a;

		int counter = 0;

		for (int i = 0; i < n ; i++)
		{
			std::cin >> a;
			counter++;
			if (counter == n / 2+1)
			{
				std::cout << a << std::endl;
			}
		}
	}

	void SummWithoutN()
	{
		int a = 0;
		int summ = 0;
		//do 
		//{
		//	std::cin >> a;
		//	if (a == 0)
		//	{
		//		break;
		//	}
		//	summ += a;
		//} while (a != 0);

		while (true)
		{
			std::cin >> a;
			if (a == 0)
			{
				break;
			}
			summ += a;
		}

		//std::cin >> a;
		//while (a != 0)
		//{
		//	summ += a;
		//	std::cin >> a;
		//}

		std::cout << summ << std::endl;
	}

	void AverageOfWithoutN()
	{
		int a = 0;
		int counter = 0;
		int summ = 0;

		while (true)
		{
			std::cin >> a;
			if (a == 0)
			{
				break;
			}
			summ += a;
			counter++;
		}
		std::cout << summ / counter << std::endl;
	}

	void PrintCentralElemWithoutN()
	{
		//человек вводит всегда больше или равно 3 элемента, вводит всегда нечетное количество элементов
		int a = 0;
		int b = 0;
		DataStructures::Queue q;
		
		std::cin >> a;
		q.PushToBack(a);

		while (true)
		{
			std::cin >> a;
			if (a == 0)
			{
				break;
			}
			std::cin >> b;
			q.PushToBack(a);
			q.PushToBack(b);
			q.PopFrontElem();
		}
		std::cout << q.GetFrontElem() << std::endl;
	}

	void CheckSummFirst2BiggerSummLast2WithoutN()
	{
		int summ1 = 0;
		int summ2 = 0;
		int last_a = 0;
		int prevlast_a = 0;
		int a = 0;
		
		std::cin >> a;
		summ1 += a;
		
		std::cin >> a;
		summ1 += a;

		while (true)
		{
			prevlast_a = last_a;
			last_a = a;

			std::cin >> a;
			/*в этом месте пишем состояние*/
			if (a == 0)
			{
				break;
			}
		}
		//std::cout << (summ1 > last_a) << std::endl;
		std::cout << last_a << ' ' << prevlast_a << std::endl;
	}

	void CheckIfNum4InSequence()
	{
		int a;
		bool is_4_exist = false;

		do
		{
			cin >> a;
			if (a == 4)
			{
				is_4_exist = true;
			}

		} while (a != 0);
		
		if (is_4_exist)
		{
			cout << "True" << endl;
		}
	}

	void ProductOfSequence()
	{
		int a;
		int product=1;
		do
		{
			cin >> a;
			if (a != 0)
			{
				product *= a;
			}
		} while (a != 0);
		cout << product << endl;
	}

	void PrintIncreaseCount()
	{
		int a;
		int b;
		int count_incr = 0;
		cin >> a;
		do
		{
			b = a;
			cin >> a;
			if (a > b)
			{
				count_incr++;
			}
		} while (a != 0);
		cout << count_incr << endl;
	}

	void PrintLastTwoElems()
	{
		int a;
		int b;
		int c;
		cin >> a;
		cin >> b;
		do
		{
			c = b;
			b = a;
			cin >> a;
		} while (a != 0);
		cout << c << ' ' << b << endl;
	}

	void PrintLastThreeElems()
	{
		int a;
		int b;
		int c;
		int d;
		cin >> a;
		cin >> b;
		cin >> c;
		do
		{
			d = c;
			c = b;
			b = a;
			cin >> a;

		} while (a != 0);
		cout << d << ' ' << c << ' ' << b << endl;
	}

	void PrintLastnElems()
	{
		//4 - число чисел на вывод
		//1 2 3 4 5 6 7 8 9 0 - ввод чисел
		//6 7 8 9 - вывод чисел
		DataStructures::Queue q;
		
		int n;
		cout << "Elems in queue: ";
		cin >> n;
		int a;

		for (int i = 0; i < n; i++)
		{
			cin >> a;
			q.PushToBack(a);
		}

		while (true)
		{
			cin >> a;
			if (a == 0)
			{
				break;
			}
			q.PushToBack(a);
			q.PopFrontElem();
		}

		q.Print();
	}

	void PrintMostFrequent()
	{
		//вывести наиболее часто встречающееся число. ввод чисел от 1 до 9 включительно.
		
		int a = 0;
		int arr[10] = { 0 };

		while (true)
		{
			cin >> a;
			if (a == 0)
			{
				break;
			}
			arr[a]++;
		}

		int ind_of_cur_max = 0;
		for (int i = 0; i < std::size(arr); i++)
		{
			if (arr[i] > arr[ind_of_cur_max])
			{
				ind_of_cur_max = i;
			}
		}
		cout << ind_of_cur_max << endl;
	}
}