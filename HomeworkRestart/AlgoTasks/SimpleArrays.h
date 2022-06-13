#pragma once
#include <map>

/*
Простые массивы
1. Создать массив размера n. Заполнить его четверками. В третью ячейку записать 6, а в предпоследнюю 8.
2. Создать массив размера n и записать в него: на четные позиции нули, на нечетные рандомные числа.
3. Создать массив размера n и записать в него следующие числа {0, 2, 4, 6, 8, 10, ..., 2(n-1)}
4. Создать массив размера n и записать в него следующие числа { n-1, n-2, ..., 3, 2, 1, 0}
5. Вывести на экран индексы элементов, в которых записано число 5.
6. Вывести на экран индекс последней двойки. Если двойки в массиве нету, вывести -1. Пример. Исходный массив: 3 6 4 2 3 4 6 2 1. 
Вывод: 7.Пример. Исходный массив: 2 3 4 1 5 4 6 7 0. Вывод: 0.
7. Вывести на экран индексы последней двойки и первой тройки (сначала для двойки, потом для тройки). Пример. Исходный массив: 3 6 4 2 3 4 6 2 1. 
Вывод: 7 0. Пример. Исходный массив: 2 3 4 1 5 4 6 7 0. Вывод: 0 1.
8. Вывести сколько раз в массиве встречается 0.
9. Заменить все нули в массиве на число обозначающее количество нулей в массиве. 
Пример. Исходный массив: 2 3 0 1 5 0 6 7 0. Нулей в массиве 3, заменить все нули на 3. Вывод: 2 3 3 1 5 3 6 7 3
10. Вывести все локальные минимумы. Элемент является локальным минимумом, если он меньше предыдущего и следующего элемента. 
Пример. Исходный массив: 2 3 0 1 5 3 6 7 6 7. Вывод: 2 0 3 6. Пример. Исходный массив: 2 1 2 1 2 1 2 1 2 1. Вывод: 1 1 1 1 1
11. Дан массив случайных чисел размера n. Вывести сколько в массиве двоек, троек и четверок.
12. Дан массив случайных чисел размера n. 
Вывести 0, если в этом массиве число 3 встретилось раньше числа 4. 
Вывести 1, если 4 раньше 3. -1 - если в массиве нет тройки или четверки.
13. Дан массив случайных чисел размера n. Сделать так, чтоб максимальный элемент в массиве оказался в конце массива. 
Исходный порядок элементов можно не сохранять.
14. Дан массив случайных чисел размера n. Поменять местами первый минимальный и последний максимальный элементы.
15. Дан массив случайных чисел размера n. Найти среднее значение элементов массива. 
Вывести индексы элементов, который наиболее отличается от среднего. Например массив: 2 4 3 7 6 5 8. Среднее значение - (2 + 4 +3 + 7 + 6 + 5 + 8) / 7 = 5. 
Элемнты, которые наиболее отличаются от 5 это 2 и 8.
16. Дан массив случайных чисел размера n. Вывести true, если в массиве все числа уникальные, иначе false.
17. Дан массив размера n, заполненный случайными числами. Отзеркалить его относительно середины, т.е.
Пример1: 1 2 3 4 5. Результатирующий массив: 5 4 3 2 1
Пример2: 1 2 3 4 5 6. Результатирующий массив: 6 5 4 3 2 1

18. Сгенерировать такой массив размера n: В нулевой ячейке случайное число от 0 до 10. В первой от 10 до 20.
Во второй от 20 до 30. И т.д.

19. Дан массив размера n, заполненный случайными числами от 0 до 9. Вывести сколько раз встречалось минимальное число.
Например массив: 4 3 7 5 4 2 4 4 2 2 9 2. Минимальное тут 2, оно встречалось 4 раза. Значит вывести 4.

20. Дан массив размера n, заполненный случайными числами от 0 до 9. Вывести максимальное или минимальное значение, в зависимотси от того, кто больше встречался в массиве. Выводить того, кто больше. Если максимум и минимум встерчались одинаковое количество раз, то вывести обоих.
Пример1: 6 5 3 8 4 7 5 3

21. Создать 2 массива размер n. Заполнить их как в задаче 2. Вывести все числа из массивов по возрастанию (по сути слить их)
Пример: 4 15 23 37 43 56
Пример: 2 16 21 35 48 59
Вывод: 2 4 15 16 21 23 35 37 43 48 56 59
*/

namespace AlgoTasks::SimpleArrays
{
	void Task10()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		for (int i = 1; i < vec.size()-1; ++i)
		{
			if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1])
			{
				std::cout << vec[i] << std::endl;
			}
		}
	}

	//11. Дан массив случайных чисел размера n. Вывести сколько в массиве встречалось каких чисел
	void Task11()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		std::map<int, int> m;

		for (int i = 0; i < vec.size(); ++i)
		{
			m[vec[i]]++;
		}
		for (auto [key, value] : m)
		{
			std::cout << key << ' ' << value << std::endl;
		}
	}

	void Task12()
	{
		std::vector<int> vec = { 3,4,3,3,4,3,4};

		int ind3 = -1;
		int ind4 = -1;

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == 3 && ind3 == -1)
			{
				ind3 = i;
			}
			if (vec[i] == 4 && ind4 == -1)
			{
				ind4 = i;
			}
		}
			if (ind3 > ind4)
			{
				std::cout << 1 << std::endl;
				return;
			}
			if (ind3 < ind4)
			{
				std::cout << 0 << std::endl;
				return;
			}
			std::cout << -1 << std::endl;
	}

	//14. Дан массив случайных чисел размера n. Поменять местами первый минимальный и последний максимальный элементы.
	void Task14()
	{
		std::vector<int> vec = { 4,3,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,8,5 };

		int first_min = vec[0];
		int last_max = vec[0];

		int ind_first_min = 0;
		int ind_last_max = 0;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < first_min)
			{
				first_min = vec[i];
				ind_first_min = i;
			}
			if (vec[i] >= last_max)
			{
				last_max = vec[i];
				ind_last_max = i;
			}
		}
		vec[ind_first_min] = last_max;
		vec[ind_last_max] = first_min;
	}

	
	//15. Дан массив случайных чисел размера n. Найти среднее значение элементов массива. 
	//Вывести индексы элементов, которые наиболее отличаются от среднего. 
	//Например массив: 2 4 3 7 6 5 8. Среднее значение - (2 + 4 +3 + 7 + 6 + 5 + 8) / 7 = 5
	//MeanValue = MeanValue + (value - MeanValue) / CountValues
	void Task15()
	{
		std::vector<int> vec = {-2,-1,-1,0,1,1,2 };
		double MeanValue = 0;
		int counter = 0;

		int vec_min = vec[0];
		int vec_max = vec[0];

		for (int i = 0; i < vec.size(); ++i)
		{
			counter++;
			MeanValue = MeanValue + (vec[i] - MeanValue) / counter;

			if (vec[i] <= vec_min)
			{
				vec_min = vec[i];
			}
			if (vec[i] >= vec_max)
			{
				vec_max = vec[i];
			}
		}
		std::cout << MeanValue << std::endl;

		double diff_to_max = fabs(vec_max - MeanValue);
		double diff_to_min = fabs(vec_min - MeanValue);
		double max_diff = std::max(diff_to_max, diff_to_min);

		for (int i = 0; i < vec.size(); ++i)
		{
			if (fabs(vec[i] - MeanValue) >= max_diff)
			{
				std::cout << vec[i] << ' ' << i << std::endl;
			}
		}
	}

	//16. Дан массив случайных чисел размера n. Вывести true, если в массиве все числа уникальные, иначе false.
	void Task16()
	{
		std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = i + 1; j < vec.size(); ++j)
			{
				std::cout << vec[i] << ' ' << vec[j] << std::endl;

				if (vec[j] == vec[i])
				{
					std::cout << "False" << std::endl;
					return;
				}
			}
		}
		std::cout << "True" << std::endl;
	}

	//17. Дан массив размера n, заполненный случайными числами.Отзеркалить его относительно середины, т.е.
	void Task17()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };

		int j = 0;
		for (int i = 0; i < vec.size() / 2; ++i)
		{
			std::cout << vec[i] << ' ' << vec[vec.size() - 1 - i] << std::endl;
			
			std::swap(vec[i], vec[vec.size() - 1 - i]);
		}

		for (auto e : vec)
		{
			std::cout << e << std::endl;
		}

	}

	//18. Сгенерировать такой массив размера n: В нулевой ячейке случайное число от 0 до 10. В первой от 10 до 20.
	//Во второй от 20 до 30. И т.д. 0-9, 10-19
	void Task18()
	{
		std::vector<int> vec;
		int n = 10;
		
		for (int i = 0; i < n; ++i)
		{
			vec.push_back(rand() % 10 + i * 10);
		}

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	//19. Дан массив размера n, заполненный случайными числами от 0 до 9. Вывести сколько раз встречалось минимальное число.
	//Например массив : 4 3 7 5 4 2 4 4 2 2 9 2. Минимальное тут 2, оно встречалось 4 раза.Значит вывести 4.
	void Task19()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		int min = vec[0];
		int count = 1;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < min)
			{
				min = vec[i];
				count=0;
			}
			if (vec[i] == min)
			{
				count++;
			}
			std::cout << vec[i] << ' ' << min << ' ' << count << std::endl;
		}
		std::cout << count << std::endl;
	}

	//20. Дан массив размера n, заполненный случайными числами от 0 до 9. Вывести максимальное или минимальное значение, 
	//	в зависимотси от того, кто больше встречался в массиве.Выводить того, кто больше.Если максимум и минимум встерчались 
	//	одинаковое количество раз, то вывести обоих.
	//	Пример1: 6 5 3 8 4 7 5 3
	void Task20()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		int min = vec[0];
		int max = vec[0];
		int count_min = 1;
		int count_max = 1;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < min)
			{
				min = vec[i];
				count_min = 0;
			}
			if (vec[i] > max)
			{
				max = vec[i];
				count_max = 0;
			}
			if (vec[i] == min)
			{
				count_min++;
			}
			if (vec[i] == max)
			{
				count_max++;
			}
			//std::cout << "Vec[i]= " << vec[i] << ' ' << " Min= " << min << ' ' << " Count_min= " << count_min << ' ' << " Max= " << max << ' ' << " Count_max= " << count_max << std::endl;
		}
		
		if (count_max >= count_min)
		{
			std::cout << count_max;
		}
		if (count_min >= count_max)
		{
			std::cout << count_min;
		}
	}

	//Сформировать массив размерa n, где каждое следующее число больше предыдущего. Каждый следующиий элемент отличается от предыдущего не больше, чем на 10
	//разница между соседними элементами не больше 10
	std::vector<int> GenerateSortedArray(int n, int dispersion)
	{
		std::vector<int> vec;

		vec.push_back(rand() % dispersion);
		
		for (int i = 1; i < n; ++i)
		{
			vec.push_back(rand() % dispersion + vec[i-1]);
		}
		
		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
		return vec;
	}


	//21. Создать 2 массива размер n.Заполнить их как в задаче 2. Вывести все числа из массивов по возрастанию (по сути слить их)
	//	Пример: 4 15 23 37 43 56
	//	Пример : 2 16 21 35 48 59
	//	Вывод : 2 4 15 16 21 23 35 37 43 48 56 59
	void Task21_1()
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() || pos2 < vec2.size())
		{
			if (pos1 >= vec1.size())
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
				continue;
			}
			if (pos2 >= vec2.size())
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
				continue;
			}
			if (vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
	}

	void Task21_2()
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() || pos2 < vec2.size())
		{
			if (pos1 >= vec1.size())
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
				continue;
			}
			if (pos2>= vec2.size() || vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
	}

	void Task21_3() //слияние отсортированных массивов, если cout заменить на push_back
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() && pos2 < vec2.size())
		{
			if (vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
		while (pos1 < vec1.size())
		{
			std::cout << vec1[pos1] << ' ';
			pos1++;
		}
		while (pos2 < vec2.size())
		{
			std::cout << vec2[pos2] << ' ';
			pos2++;
		}
	}














}
