#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>

namespace AlgoTasks::Loops
{
	//4. Вывести первые n четных чисел (натуральных, больше нуля).
	void Task4()
	{
		int n;
		std::cin >> n;
		int count_of_results=0;
		int result = -1;
		while (count_of_results < n)
		{
			result++;
			if (result % 2 == 0)
			{
				count_of_results++;
				std::cout << result << std::endl;
			}
		}

		for (int i = 0; i < n * 2; i += 2) //оптимальнее, т.к. в два раза меньше будет заход в цикл и нет долгого % и условия
		{
			std::cout << i << std::endl;
		}

	}

	//5. Пользователь вводит число n. Вывести нечетные числа, меньшие n. (натуральных, больше нуля).
	void Task5()
	{
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 != 0)
			{
				std::cout << i << std::endl;
			}
		}

		for (int i = 1; i < n; i += 2) //оптимальнее, т.к. в два раза меньше будет заход в цикл и нет долгого % и условия
		{
			std::cout << i << std::endl;
		}
	}

	//8. Вывести начиная с числа n следующие n чисел.
	void Task8()
	{
		int n;
		std::cin >> n;
		//n=4, 4 5 6 7
		//n=3, 3 4 5
		for (int i = 0; i <n; i++)
		{
			std::cout << i+n << std::endl;;
		}
	}

	//Вывести сначала четные числа в промежутке от 1 до n (включительно), затем нечетные числа от n (не включая) до 2n (включительно).
	void Task9()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n * 2; ++i)
		{
			if (i <= n && i % 2 == 0)
			{
				std::cout << i << std::endl;
			}
			if (i >= n && i % 2 != 0)
			{
				std::cout << i << std::endl;
			}
		}
	}

	void Task9_1()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n * 2; ++i)
		{
			if (i <= n)
			{
				if (i % 2 == 0)
				{
					std::cout << i << std::endl;
				}
			}
			else
			{
				if (i % 2 != 0)
				{
					std::cout << i << std::endl;
				}
			}
		}
	}

	void Task9_2()
	{
		int n;
		std::cin >> n;
		int i = 0;
		for (; i <= n; i+=2)
		{
			std::cout << i << std::endl;
		}
		//при n = 10 i становится равным 12
		//при n = 11 i становится равным 12 так как i шагает по 2
		i--; //отступаем назад на 1, т.к. из предыдущего цикла i всегда четный
		for (; i <= n * 2; i += 2)
		{
			std::cout << i << std::endl;
		}
	}

	//10. Пользователь вводит число n. Вывести n n-1 n-2 ... 1
	void Task10()
	{
		int n;
		std::cin >> n;

		for (int i = n; i > 0; --i)
		{
			std::cout << i << std::endl;
		}
	}

	//11. Тоже самое только фор вверх идет.
	void Task11()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n; ++i)
		{
			std::cout << n-i << std::endl;
		}
	}

	//12. Пользователь вводит число n. Вывести первую половину по возрастанию. А вторую по убыванию. (1 2 3 ... n/2) (n n-1 n-2 ... n/2+1)
	//13. Сделать тоже самое, но использовать только один for.
	void Task12()
	{
		int n;
		std::cin >> n;
		
		for (int i = 0; i <= n; ++i)
		{
			if (i <= n / 2)
			{
				std::cout << i << std::endl;
			}
			else
			{
				std::cout << n - i + n/2 + 1 << std::endl; // i[n/2+1,n]
			}
		}
	}

	//15. Посчитать n! = 1  2  3  4  5  …  (n - 1) * n. - рекурсия
	//n! = n*(n-1)!
	int Task15_factorial(int x)
	{
		return (x > 0) ? (x * Task15_factorial(x - 1)) : 1;
	}
	
	void Task15()
	{
		int n;
		std::cin >> n;
		std::cout << Task15_factorial(n) << std::endl;
	}

	//16. Вычислить число сочетаний из n по k !Порядок цифр не играет роли!Без учета повторений!
	//c_n_k = (n!) / (k! * (n-k)!)
	int Task16()
	{
		int k,n;
		std::cin >> k >> n;

		return Task15_factorial(n) / (Task15_factorial(k) * Task15_factorial(n - k));
	}

	//вывести все возможные комбинации замка - три цифры из 10 возможных
	//012
	//013
	//014
	//...
	//019
	//023
	//...
	//029
	//034
	//...
	//089
	
	//123
	//124
	//..
	//129
	//134
	//...
	//189
	
	//234
	//..
	//239
	//345
	//..
	//349
	//456
	//...
	//679
	//789
	void Task16_1()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = i + 1; j < 10; ++j)
			{
				for (int k = j + 1; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - Количество уникальных сочетаний" << std::endl;
		std::cout << Task15_factorial(10) / (Task15_factorial(3) * Task15_factorial(10 - 3)) << std::endl;
	}

	//то же, что и 16_1, но с повторениями чисел
	//(k + n-1)! / ((n-1)! * k!)
	//000
	//001
	//002
	//009
	//011
	//012
	//019
	//022
	//...
	//999
	void Task16_2()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = i; j < 10; ++j)
			{
				for (int k = j; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - Количество сочетаний с учетом повторений цифр" << std::endl;
		std::cout << Task15_factorial(12) / (Task15_factorial(9) * Task15_factorial(3)) << std::endl;
	}

	//то же что и 16_2, но важна позиция чисел
	//формула10^3
	//123
	//321
	void Task16_3()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				for (int k = 0; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - Количество размещений 10 цифр в 3 ячейках" << std::endl;
		std::cout << std::pow(10,3) << std::endl;
	}

	//тоже, что и 16_3, но цифры не могут повторяться
	// n! / (n-k)!
	//123
	//321
	void Task16_4()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (j == i)
				{
					continue;
				}
				for (int k = 0; k < 10; ++k)
				{
					if (k == j || k == i) 
					{ 
						continue; 
					}
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - Количество размещений 10 цифр в 3 ячейках без повторений цифр" << std::endl;
		std::cout << Task15_factorial(10) / Task15_factorial(7) << std::endl;
	}

	//дан массив, вывести все возможные перестановки элементов этого массива
	//01234
	//...
	//04321

	std::vector<int> RemoveElementFromVector(std::vector<int> vector, int index_to_remove)
	{
		vector.erase(vector.begin() + index_to_remove);

		return vector;
	}

	//нужен глобальный счетчик
	int count = 0;

	void PrintPermutation(std::string prefix, std::vector<int> vec)
	{
		if (vec.size() == 0)
		{
			return;
		}
		
		if (vec.size() == 1)
		{
			std::cout << prefix << vec[0] << std::endl;
			count++;
			return;
		}
		for (int i = 0; i < vec.size(); ++i) 
		{
			PrintPermutation(prefix + std::to_string(vec[i]), RemoveElementFromVector(vec, i));
		}
		return;
	}

	void TaskTest()
	{
		std::string s = "12345";
		do {
			std::cout << s << '\n';
		} while (std::next_permutation(s.begin(), s.end()));
	}

	//17. Пользователь вводит 2 числа n,m. Вывести m m+1 m+2 ... n или n n+1 n+2 ... m. Используйте пожалуйста один цикл.
	void Task17()
	{
		int n;
		int m;
		std::cin >> n >> m;
		int max_elem = max(n, m);
		int min_elem = min(n, m);

		for (int i = min_elem; i <= max_elem; ++i)
		{
			std::cout << i << std::endl;
		}
	}


	//18. Вывести все делители числа
	void Task18()
	{
		int x;
		std::cin >> x;
		for (int i = 1; i <= x/2; ++i)
		{
			if (x % i == 0)
			{
				std::cout << i << std::endl;
			}
		}
		std::cout << x << std::endl; //так как делится на самого себя

	}

	//19. Найти наибольший нетривиальный делитель_без_остатка натурального числа
	void Task19()
	{
		int x;
		std::cin >> x;
		if (x % 2 == 0)
		{
			std::cout << x / 2 << std::endl;
		}
		else
		{
			for (int i = x/2; i >= 2; --i)
			{
				if (x % i == 0)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}

	//20. Найти наименьший нетривиальный делитель натурального числа 
	void Task20()
	{
		int x;
		std::cin >> x;
		if (x % 2 == 0)
		{
			std::cout << 2 << std::endl;
		}
		else
		{
			for (int i = 2; i <= x / 2; ++i)
			{
				if (x % i == 0)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}

	int GetMinimalDenominator(int x)
	{
		if (x == 2)
		{
			return 1;
		}
		else if (x % 2 == 0)
		{
			return 2;
		}
		else
		{
			for (int i = 2; i <= x / 2; ++i)
			{
				if (x % i == 0)
				{
					return i;
					break;
				}
			}
		}
		return 1;
	}

	//22. Получить каноническое разложение числа на простые сомножители 27 = 3 * 9, 9 = 3 * 3, 3 * 3 * 3
	void Task22()
	{
		int n;
		std::cin >> n;
		int mult = 0;
		while (mult!=1)
		{
			mult = GetMinimalDenominator(n); //n=4, mult=2; n=2, mult=1;
			if (mult == 1)
			{
				std::cout << n << std::endl;
			}
			else
			{
				std::cout << mult << std::endl;
			}
			n = n / mult;
		}
	}
	//23. Найти наименьший нетривиальный делитель двух заданных чисел
	void Task23()
	{
		int n;
		int m;
		std::cin >> n >> m;
		for (int i = 2; i <= min(n, m) / 2; ++i)
		{
			if (n % i == 0 && m % i == 0)
			{
				std::cout << i << std::endl;
				break;
			}
		}
	}

	std::vector<int> GetDenominators(int x)
	{
		std::vector<int> vec;
		for (int i = 1; i <= x / 2; ++i)
		{
			if (x % i == 0)
			{
				vec.push_back(i);
			}
		}
		return vec;
	}

	int GetSummOfElementsOfVector(std::vector<int> vec)
	{
		return std::accumulate(vec.begin(), vec.end(), 0);
	}

	int GetSummOfDenominators(int x)
	{
		return GetSummOfElementsOfVector(GetDenominators(x));
	}

	//24.  Проверить, является ли заданное натуральное число совершенным /равное сумме всех своих собственных делителей
	void Task24()
	{
		int n;
		std::cin >> n; 
		
		std::vector<int> vec;

		for (int i = 1; i <= n / 2; ++i)
		{
			if (n % i == 0)
			{
				vec.push_back(i);
				std::cout << i << std::endl;
			}
		}
		int summ = 0;
		
		for (int a : vec)
		{
			summ += a;
		}
		//делители 28 = 1,2,4,7,14
		std::cout << (summ == n) << std::endl; //+1 так как она является первым элементом перемножения
	}

	void Task24_one_row()
	{
		int n;
		std::cin >> n;
		std::cout << (GetSummOfDenominators(n) == n) << std::endl;
	}

	//25. Проверить, являются ли два натуральных числа дружественными 
	void Task25()
	{
		int n,m;
		std::cin >> n >> m;
		std::cout << ((GetSummOfDenominators(n) == m) && (GetSummOfDenominators(m) == n)) << std::endl;
	}
}
