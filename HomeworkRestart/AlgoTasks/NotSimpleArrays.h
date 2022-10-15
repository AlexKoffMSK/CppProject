#pragma once

/*
Массивы
1. Симметричны ли значения элементов массива?
2. Переставить элементы массива в обратном порядке.
3. Циклически сдвинуть элементы массива на одну позицию вправо.
4. Сравнить два неупорядоченных целочисленных массива A и B как числовые множества: A = B и A принадлежит B.
5. Удалить из массива все отрицательные значения, а оставшиеся уплотнить (сдвинуть) с сохранение исходного порядка к началу массива.
6. Циклически сдвинуть элементы массива на K позиций вправо с затратой O(N)действий (N-длина массива)
7. Каждый элемент массива заменить на полусумму соседей (кроме первого и последнего)
8. Назовем x-отрезком группу подряд идущих элементов массива, каждый из которых равен x. 
Для заданного числа x заменить элементы каждого x-отрезка на полусумму элементов, прилегающих к этому отрезку справа и слева. 
Если x-отрезок расположен в начале или конце массива, считать недостающий крайний элемент равным нулю.
9. Сгруппировать положительные элементы массива в его начале, а отрицательные - в конце с сохранением их порядка.
10. Получить массив биномиальных коэффициентов для степени N, последовательно вычисляя строки треугольника Паскаля (можно использовать только один массив).
11. Элементы массива не убывают. Двоичным поиском определить позицию, где в этот массив можно вставить данное число x.
12. Даны два неубывающих массива. Построить третий неубывающий массив, который является объединением первых двух.
13. Пусть в массиве последовательно записаны цифры некоторого длинного десятичного числа. 
Реализовать функции "прибавляющие единицу"и "вычитающие единицу"из такого числа.
14. Удалить все элементы массива с четными значениями, уплотнив массив к его началу.Функция должна возвращать количество элементов в получившемся массиве.
15. Заменить все локальные минимумы в массиве одним элементом, значение которого равно элементу массива с минимальным значением. 
Функция должна возвращать количество элементов в получившемся массиве.
16. Заменить каждый элемент массива количеством элементов массива с меньшими индексами, имеющими значение, меньше данного элемента, 
т.е. каждый элемент массива ai заменить количеством элеметвом массива aj , таких что j < i и aj < ai.
17. Отнормировать все элементы массива {ai}i=1,...,N на интервал [min(a1, aN), max(a1, aN)], т.е. в случае, когда все элементы массива совпадают, 
изменять массив не следует, иначе заменить каждый элемент массива на значение min(a1, aN) + [(ai − min(a1, aN))/|a1 − aN|].
18. Заменить все минимальные элементы массива на значение элемента массива, большего минимального, но не большего всех остальных элементов массива.
19. Удалить из массива наиболее часто встречающееся значение. Если таких значений несколько, то выбрать любое из них. 
Функция должна возвращать количество элементов в получившемся массиве.
20. Удалить из массива наименее часто встречающееся значение. Если таких значений несколько, то удалить все эти значения. 
Функция должна возвращать количество элементов в получившемся массиве.
21. В каждом интервале строгого возрастания в массиве заменить все значения в данном интервале на среднее значение в 
интервале (рассматриваются интервалы возрастания в массиве, которые нельзя удлинить).
22. Поменять местами в массиве локальные минимумы с соседними порядковыми номерами, т.е. поменять местами в массиве локальные минимумы с 
номерами 2i и 2i + 1 для всех возможных i.
23. Удалить из массива элементы, содержащиеся во всех интервалах строгого возрастания с длиной не более 3. 
Функция должна возвращать количество элементов в получившемся массиве.
24.
*/

namespace AlgoTasks::NotSimpleArrays
{
	void Task3()
	{
		std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

		int back_up = vec.back();

		for (int i=vec.size()-1; i>0; --i)
		{
			vec[i] = vec[i - 1];
		}
		vec[0] = back_up;

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	std::vector<int> GetUniqueElems(std::vector<int> arr)
	{
		std::sort(arr.begin(), arr.end());
		
		std::vector<int> res_vec;
		
		res_vec.push_back(arr[0]);

		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] != res_vec.back())
			{
				res_vec.push_back(arr[i]);
			}
		}
		return res_vec;
	}
	
	bool IsArray1ContainsInArray2(std::vector<int> arr1, std::vector<int> arr2)
	{
		if (arr1.size() > arr2.size())
		{
			return false;
		}

		for (int i = 0; i < arr1.size(); ++i)
		{
			if (std::find(arr2.begin(), arr2.end(), arr1[i]) == arr2.end())
			{
				return false;
			}
		}
		return true;

	}

	std::vector<int> GetArrayWithoutElem(std::vector<int> vec, int x)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == x)
			{
				for (int j = i; j < vec.size()-1; ++j)
				{
					vec[j] = vec[j + 1];
				}
				vec.erase(vec.begin() + vec.size()-1);
			}
		}
		return vec;
	}
	
	template <typename T> 
	void PrintVec(std::vector<T> vec)
	{
		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	//4. Сравнить два неупорядоченных целочисленных массива A и B как числовые множества: A = B и A принадлежит B.
	void Task4()
	{
		//1 2 3 1 1 2 3 3 - A
		//1 2 3 - B
		//A = B

		//1 2 3 1 1 2 3 3 - A
		//2 3 4 - B
		//A != B

		//1 2 3 1 1 2 3 3 - A
		//1 2 3 4 - B
		//A принадлежит B (A c B)

		//1 2 3 1 1 2 3 3 - A
		//2 1 3 - A`
		//3 2 1 - B
		//A = B

		std::vector<int> or_vec = { 2,3,1,0,3,4,5 };
		std::vector<int> or_vec1 = { 0,0,1,6,3,4,5 };
		
		std::vector<int> vec = GetUniqueElems(or_vec);
		std::vector<int> vec1 = GetUniqueElems(or_vec1);

		if (vec.size() == vec1.size())
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				if (vec[i] != vec1[i])
				{
					std::cout << "Not Equal" << std::endl;
					return;
				}
			}
			std::cout << "Equal" << std::endl;
		}
		else
		{
			if (IsArray1ContainsInArray2(vec, vec1))
			{
				std::cout << "Not Equal & Arr 1 contains in Arr2" << std::endl;
			}
			else
			{
				std::cout << "Not Equal & Arr 1 do not contains in Arr2" << std::endl;
			}
		}
	}

	//5. Удалить из массива все отрицательные значения, а оставшиеся уплотнить (сдвинуть) с сохранение исходного порядка к началу массива.
	void Task5_1()
	{
		std::vector<int> vec = { -1,2,-3,4,4,-5,6,-7,8,-9 };

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < 0)
			{
				vec = GetArrayWithoutElem(vec, vec[i]);
			}
		}
		
		for (auto e : vec)
		{
			std::cout << e << ' ';
		}

	}

	void Task5_2()
	{
		std::vector<int> vec = { -1,2,-3,4,4,-5,6,-7,8,-9 };

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < 0)
			{
				vec.erase(vec.begin() + i);
			}
		}
		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	void Task5()
	{
		std::vector<int> vec = { -2,-2,-3,-1,-2,-3,4,-4,-5,-6,-7,-8,-9 };

		//int place_to_overwrite = -1; //так как 0 может оказаться валидным числом
		//for (int i = 0; i < vec.size(); ++i)
		//{
		//	if (vec[i] < 0)
		//	{
		//		place_to_overwtire = i;
		//		break;
		//	}
		//}

		int place_to_overwrite = 0;

		while (place_to_overwrite < vec.size() && vec[place_to_overwrite] > 0)
		{
			place_to_overwrite++;
		}

		//if (place_to_overwrite < 0)
		//{
		//	for (auto e : vec)
		//	{
		//		std::cout << e << ' ';
		//	}
		//	return;
		//}
		
		for (int i = place_to_overwrite; i < vec.size(); ++i)
		{
			if (vec[i] > 0)
			{
				vec[place_to_overwrite] = vec[i];
				place_to_overwrite++;
			}
		}
		
		vec.resize(place_to_overwrite);

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	//Есть двумерный квадратный массив размера n. Надо заполнить его змейкой
	//n = 5;
	//0:  1  2  3  4  5
	//1: 10  9  8  7  6 
	//2: 11 12 13 14 15
	//3: 20 19 18 17 16
	//4: 21 22 23 24 25
	//индексы элементов
	// 0  1  2  3  4
	// 5  6  7  8  9
	//10 11 12 13 14
	//15 16 17 18 19
	//20 21 22 23 24
	void TaskMatrixSnake_1()
	{
		const int n = 5;
		int arr[n][n];

		int num = 1;

		int* arr_plain = (int*)arr;
		for (int i = 0; i < n * n; ++i)
		{
			if (i != 0)
			{
				if (i % n == 0)
				{
					if ((i / n) % 2 != 0)
					{
						num += n - 1;
					}
					else
					{
						num += n + 1;
					}
				}
			}

			arr_plain[i] = num;

			if ((i / n) % 2 == 0) //проверяем на четность строки. i/n это способ определить номер строки используя линеаризованный индекс.
			{
				num++;
			}
			else
			{
				num--;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake_2()
	{
		const int n = 10;
		int arr[n][n];

		//i=0; j=2, num = 3
		//i=0; j=4, num = 5 (num = (n*i)+(j+1))
		//i=2; j=2, num = 13 (num = (n*i)+(j+1))
		//i=2; j=4, num = 15 (num = (n*i)+(j+1))

		//i=1; j=2; num=8 (num = (n * (i+1) - j))
		//i=1; j=3; num=7 (num = (n * (i+1) - j))
		//i=1; j=0; num=7 (num = (n * (i+1) - j))

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i%2 == 0) //для четных строк
				{
					arr[i][j] = (n * i) + (j + 1);
					
				}
				else //для нечетных строк
				{
					arr[i][j] = (n * (i + 1) - j);
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake_3()
	{
		const int n = 10;
		int arr[n][n];
		bool is_even = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (is_even) //для четных строк
				{
					arr[i][j] = (n * i) + (j + 1);

				}
				else //для нечетных строк
				{
					arr[i][j] = (n * (i + 1) - j);
				}
			}
			is_even = !is_even;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake_4()
	{
		const int n = 10;
		int arr[n][n];
		for (int i = 0; i < n; i+=2)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = (n * i) + (j + 1);
			}
		}

		for (int i = 1; i < n; i+=2)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = (n * (i + 1) - j);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake_5()
	{
		const int n = 10;
		int arr[n][n];

		int num = 1;

		for (int i = 0; i < n; i += 2)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = num+j;
			}
			num += n + n;
		}
		
		num = n + n;

		for (int i = 1; i < n; i += 2)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = num - j;
			}
			num += n + n;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake_6()
	{
		const int n = 10;
		int arr[n][n];

		int num = 1;

		for (int i = 0; i < n; ++i)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < n; ++j)
				{
					arr[i][j] = num;
					num++;
				}
			}
			else
			{
				for (int j = n-1; j >= 0; --j)
				{
					arr[i][j] = num;
					num++;
				}
			}
			
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void TaskMatrixSnake()
	{
		const int n = 5;
		int arr[n][n];

		int num = 1;

		for (int i = 0; i < n-1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = num;
				num++;
			}

			i++;

			for (int j = n - 1; j >= 0; --j)
			{
				arr[i][j] = num;
				num++;
			}
		}

		if (n % 2 != 0) //если количество строк нечетное, то надо дополнительно заполнить последнюю строку
		{
			for (int j = n - 1; j >= 0; --j)
			{
				arr[n-1][j] = num;
				num++;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::setw(3) << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	//6. Циклически сдвинуть элементы массива на K позиций вправо с затратой O(N)действий (N-длина массива)
	void Task6_1()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
		int k=4;

		int temp = 0;

		for (int i = 0; i < k; ++i)
		{
			temp = vec.back();
			vec.pop_back(); //1 действие
			vec.insert(vec.begin(), temp); //N-действий
		}
		//решение k*N действий

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	void Task6_2()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
		int k = 4;

		std::vector<int> tmp_vec;

		//k - действий
		for (int i = vec.size()-k; i < vec.size(); ++i)
		{
			tmp_vec.push_back(vec[i]);
		}

		//1 действие
		vec.resize(vec.size() - k);

		//k*N действий
		for (int i = k-1; i >= 0; i--)
		{
			vec.insert(vec.begin(), tmp_vec[i]); //N-действий
		}

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	void Task6_3()
	{
		std::vector<int> vec =   { 0,1,2,3,4,5,6,7,8,9 };
		//std::vector<int> vec = { 6,7,8,9,0,1,2,3,4,5 };
		
		int k = 4;

		std::vector<int> tmp_vec;

		//k-действий
		for (int i = vec.size() - k; i < vec.size(); ++i)
		{
			tmp_vec.push_back(vec[i]);
		}

		//N-k действий
		for (int i=vec.size()-k-1; i>=0; i--)
		{
			vec[i+k] = vec[i];
		}
		
		//k-действий
		for (int i = 0; i < k; ++i)
		{
			vec[i] = tmp_vec[i];
		}

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}

		//swap i & i+k
		//swap i & i+2k
		//swap i & i+3k
		//if size-i и если он больше чем k - то это хвост
	}

	void Task6()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9,10 };
		//std::vector<int> vec = { 6,7,8,9,0,1,2,3,4,5 };

		int k = 4;
		
		//n=10; k=3 - 1 налево k-((n-k)%k)
		//n=10; k=4 - 2 налево, 2 направо
		//n=10; k=5 - 0 налево
		//n=10; k=6 - 4 налево, 2 направо
		//n=10; k=7 - 3 налево, 4 направо

		int group_swaps_count = vec.size() / k-1;

		//(n / (k-1)) * k = (n*k)/(k-1)
		for (int j = 0; j < group_swaps_count; ++j) 
		{
			for (int i = 0; i < k; ++i)
			{
				std::swap(vec[i], vec[i + k*(j+1)]);
			}
		}

		//int tail_size = vec.size() - group_swaps_count * (k+1);
		int tail_size = vec.size() % k;

		//n % k
		for (int i = 0; i < tail_size; ++i)
		{
			std::swap(vec[i], vec[vec.size() - tail_size + i]);
		}

		int count_of_swaps_for_tail = ((vec.size() - k) % k);
		
		//((n-k) % k) * (k-1)
		for (int i = 0; i < count_of_swaps_for_tail; ++i)
		{
			int tmp = vec.front();
			for (int j = 0; j < k-1; ++j)
			{
				vec[j] = vec[j + 1];
			}
			vec[k - 1] = tmp;
		}


		for (auto e : vec)
		{
			std::cout << e << ' ';
		}

		//swap i & i+k
		//swap i & i+2k
		//swap i & i+3k
		//if size-i и если он больше чем k - то это хвост
	}

	//7. Каждый элемент массива заменить на полусумму соседей (из оригинального массива)(кроме первого и последнего)
	void Task7()
	{
		std::vector<double> vec = { 1,2,3,4,5,6,7};
		
		double prev_orig_elem = vec[0];

		for (int i = 1; i < vec.size() - 1; ++i)
		{
			int tmp = vec[i];
			vec[i] = (prev_orig_elem / 2 + vec[i + 1] / 2);
			prev_orig_elem = tmp;
		}
		PrintVec(vec);
	}

	//8. Назовем x-отрезком группу подряд идущих одинаковых элементов массива, каждый из которых равен x.
	//Для заданного числа x заменить элементы каждого x-отрезка на полусумму элементов, прилегающих к этому отрезку справа и слева. 
	//Если x - отрезок расположен в начале или конце массива, считать недостающий крайний элемент равным нулю.
	void Task8()
	{
		std::vector<double> vec = { 2,2,6,6};
		//std::vector<double> vec = { 1,2,3,3,3,3,8,6,4,4,4};
		//                        { 1,2,5,5,5,5,8,6,3,3,3 }
		//1 Найти группу - начало и конец
		
		int counter = 1;
		double prev_orig_elem = vec[0];
		int prev_segment_right_bound = 0;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] == vec[i - 1])
			{
				counter++;
			}
			else if (counter > 1)
			{
				int left_bound_i = i - counter;
				
				double left_neighbour = 0;
				if (left_bound_i - 1 == prev_segment_right_bound)
				{
					left_neighbour = prev_orig_elem;
				}
				else if (left_bound_i > 0)
				{
					left_neighbour = vec[left_bound_i-1];
				}
				
				int right_bound_i = i-1;

				prev_segment_right_bound = right_bound_i;

				double half_summ = left_neighbour /2 + vec[right_bound_i+1]/2;
				
				prev_orig_elem = vec[right_bound_i];

				for (int j = left_bound_i; j <= right_bound_i; ++j)
				{
					vec[j] = half_summ;
				}
				counter = 1;
			}
		}

		if (counter > 1)
		{
			int left_bound_i = vec.size() - counter;

			double left_neighbour = 0;
			if (left_bound_i - 1 == prev_segment_right_bound)
			{
				left_neighbour = prev_orig_elem;
			}
			else if (left_bound_i > 0)
			{
				left_neighbour = vec[left_bound_i - 1];
			}

			double half_summ = left_neighbour / 2;
			for (int i = left_bound_i; i < vec.size(); ++i)
			{
				vec[i] = half_summ;
			}
		}

		PrintVec(vec);
	}

	//9. Сгруппировать положительные элементы массива в его начале, а отрицательные - в конце с сохранением их порядка.
	void Task9_1()
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };

		std::vector<int> vec1;

		for (int i = 0; i<vec.size(); ++i)
		{
			if (vec[i] > 0)
			{
				vec1.push_back(vec[i]);

			}
		}

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < 0)
			{
				vec1.push_back(vec[i]);

			}
		}
		PrintVec(vec1);
	}

	//9. Сгруппировать положительные элементы массива в его начале, а отрицательные - в конце (порядок можно менять).
	//Нельзя использовать дополнительный массив
	void Task9_2()
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };
		
		//{ -5,6,-2,-8,5,5,5,-9,7,-4 };
		//{ 5,-6,-2,-8,5,5,5,-9,7,-4 };
		
		//{ 6,-5,-2,-8,5,5,5,-9,7,-4 };
		//     |       i
		//{ 6,5,-2,-8,-5,5,5,-9,7,-4 };
		//       |       i
		//{ 6,5, 5,-8,-5,-2,5,-9,7,-4 };
		// 
		//{ 6,5, 5,-8,-5,-2,5,-9,7,-4 };
		//          |       i
		//{ 6,5, 5,5,-5,-2,-8,-9,7,-4 };

		//{ 6,5, 5,5,-5,-2,-8,-9,7,-4 };
		//            |          i
		//{ 6,5, 5,5,7,-2,-8,-9,-5,-4 };

		//{ 6,5, 5,5,7,-2,-8,-9,-5,-4 };
		//              |           i

		int place_to_set = 0;
		
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] > 0)
			{
				std::swap(vec[i], vec[place_to_set]);
				place_to_set++;
			}
		}
		PrintVec(vec);
	}

	void Task9_3()
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };

		//{ -5,6,-2,-8,5,5,5,-9,7,-4 }
		//   i                     j
		
		//{ -5,6,-2,-8,5,5,5,-9,7,-4 }
		//   i                  j  

		//{ 7,6,-2,-8,5,5,5,-9,-5,-4 }
		//    i              j  

		//{ 7,6,-2,-8,5,5,5,-9,-5,-4 }
		//       i           j  

		//{ 7,6,-2,-8,5,5,5,-9,-5,-4 }
		//       i        j  

		//{ 7,6, 5,-8,5,5,-2,-9,-5,-4 }
		//       i         j  

		//{ 7,6, 5,-8,5,5,-2,-9,-5,-4 }
		//          i   j  

		//{ 7,6, 5, 5,5,-8,-2,-9,-5,-4 }
		//          i    j  

		//{ 7,6, 5, 5,5,-8,-2,-9,-5,-4 }
		//            ij 

		int i = 0;
		int j = vec.size() - 1;

		while (i<j)
		{
			if (vec[i] < 0) //i НЕ на своем месте
			{
				if (vec[j] < 0) //j на своем месте
				{
					j--; //двигаем j
				}
				else
				{
					//попали сюда, если j НЕ на своем месте
					std::swap(vec[i], vec[j]);
					i++;
					j--;
				}
			}
			else if (vec[j] < 0)
			{
				//все на своих местах
				i++;
				j--;
			}
			else
			{
				//i на своем месте, j НЕ на своем месте - i>0,j>0
				i++;
			}
		}

		PrintVec(vec);
	}

	void Task9_4()
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };

		int i = 0;
		int j = vec.size() - 1;

		while (i < j)
		{
			if (vec[i] < 0) //i НЕ на своем месте
			{
				if (vec[j] >= 0) //j на своем месте
				{
					//попали сюда, если j НЕ на своем месте
					std::swap(vec[i], vec[j]);
					i++;
				}
				j--; //двигаем j
			}
			else 
			{
				//i на своем месте

				if (vec[j] < 0)
				{
					//j на своем месте
					j--;
				}
				i++; 
			}
		}

		PrintVec(vec);
	}

	void Task9_5()
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };

		int i = 0;
		int j = vec.size() - 1;

		while (i < j)
		{
			if (vec[i] > 0)
			{
				i++;
				continue;
			}
			if (vec[j] < 0)
			{
				j--;
				continue;
			}
			// i и j не на своих местах
			std::swap(vec[i], vec[j]);
			i++;
			j--;
		}
		PrintVec(vec);
	}

	void Task9() //с сохранением исходного порядка
	{
		std::vector<int> vec{ -5,6,-2,-8,5,5,5,-9,7,-4 };

		//-5, 6,-2,-8, 5, 5, 5,-9, 7,-4
		//    i
		// 6,-5,-2,-8, 5, 5, 5,-9, 7,-4
		//             i
		// 6, 5, 5, 5, 7,-5,-2,-8,-9-4
		//                         i
		// 
		// 6,-5,-2,-8, 5, 5, 5,-9, 7,-4
		// 6, 5,-5,-2,-8, 5, 5,-9, 7,-4

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < 0)
			{
				continue;
			}
			for (int j = i; j > 0; j--)
			{
				if (vec[j - 1] < 0) 
				{
					std::swap(vec[j], vec[j - 1]);
				}
			}
		}
		PrintVec(vec);
	}

	//10. Получить массив биномиальных коэффициентов для степени N, последовательно вычисляя строки треугольника Паскаля 
	//(можно использовать только один массив).
	void Task10()
	{

	}

	//11. Элементы массива не убывают. Двоичным поиском определить позицию, где в этот массив можно вставить данное число x.
	void Task11_1()
	{
		//1,4,6,7,7,8,8,9
		//      |
		//1,4,6
		//  |
		//  4,6
		//    |  
		//  4
		//  |
		
		//1,4,6,7,7,8,8,9
		//[     |       ]  
		
		//1,4,6,7,7,8,8,9
		//[ | ] 
		
		//1,4,6 ,7,7,8,8,9
		//    [] 

		//2,4,6
		//x=5

		std::vector<int> vec{ 1,6,6,7,8,8,8,9 };
		int x = 5;
		
		int left_bound=0;
		int right_bound=vec.size()-1;

		while (true)
		{
			if (left_bound >= right_bound)
			{
				int pos_to_insert = left_bound;
				if (x > vec[left_bound]) 
				{
					pos_to_insert++;
				}
				vec.insert(vec.begin() + pos_to_insert, x);
				PrintVec(vec);
				std::cout << pos_to_insert << std::endl;
				return;
			}
			
			int middle_i = (left_bound + right_bound) / 2;
			if (x < vec[middle_i])
			{
				right_bound = middle_i - 1;
			}
			else 
			{
				if (x > vec[middle_i])
				{
					left_bound = middle_i + 1;
				}
				else
				{
					vec.insert(vec.begin() + middle_i, x);
					PrintVec(vec);
					std::cout << middle_i << std::endl;
					return;
				}
			}
		}
	}

	void Task11()
	{
		std::vector<int> vec{ 1,6,6,7,8,8,8,9 };
		int x = 10;

		int left_bound = 0;
		int right_bound = vec.size() - 1;
		int middle_i = (left_bound + right_bound) / 2;

		while (vec[middle_i] != x && left_bound < right_bound)
		{
			if (x < vec[middle_i])
			{
				right_bound = middle_i - 1;
			}
			else
			{
				left_bound = middle_i + 1;
			}
			
			middle_i = (left_bound + right_bound) / 2;
		}
		if (x > vec[middle_i])
		{
			middle_i++;
		}
		//vec.insert(vec.begin() + middle_i, x);
		//PrintVec(vec);
		std::cout << middle_i << std::endl;
	}

	//13. Пусть в массиве последовательно записаны цифры некоторого длинного десятичного числа. 
	//Реализовать функции "прибавляющие единицу"и "вычитающие единицу"из такого числа.
	void Task13_plus()
	{
		std::vector<int> vec{9,9,9,9};
		//std::vector<int> vec{0,0,0}; -1

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			if ((vec[i] + 1) != 10)
			{
				vec[i]++;
				PrintVec(vec);
				return;
			}
			vec[i] = 0;
		}
		
		vec.push_back(0);
		
		vec[0] = 1;

		PrintVec(vec);
	}

	void Task13_minus()
	{
		std::vector<int> vec{1,0,3,2,1};

		if (vec == std::vector<int>{0})
		{
			vec[0] = -1;
			PrintVec(vec);
			return;
		}

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			if ((vec[i] - 1) >= 0)
			{
				vec[i]--;
				if (i == 0 && vec[0] == 0)
				{
					vec.erase(vec.begin());
				}
				PrintVec(vec);
				return;
			}
			vec[i] = 9;
		}
		PrintVec(vec);
	}

	//15. Заменить все локальные минимумы в массиве одним элементом, значение которого равно элементу массива с минимальным значением. 
	//Функция должна возвращать количество элементов в получившемся массиве.
	void Task15()
	{
		std::vector<int> vec{ 1,2,3,2,4,0,5,5,3,3,3,6,7,5,9 };
		//1,2,3,0,4,0,5,5,0,6,7,0,9
		//1 2 3 2
		//1 2 3 2 4 - закрылся локальный минимум, его начало третий индекс массива, а текущий индекс (4) значит локальный минимум длины 1
		//1 2 3 2 1 - локальный минимум не удался, и появился новый кандидат на локальный минимум
		//1 2 3 2 2 - есть кандидат, повторяется. читаем дальше пока не увидим другое число

		int total_min = vec[0];
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < total_min)
			{
				total_min = vec[i];
			}
		}

		int ind_loc_min_cand = 0;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (ind_loc_min_cand == 0)
			{
				if (vec[i - 1] > vec[i])
				{
					ind_loc_min_cand = i;
				}
				else
				{
					continue;
				}
			}
			else
			{
				if (vec[i] > vec[i - 1])
				{
					if (i - ind_loc_min_cand > 1)
					{
						vec.erase(vec.begin() + ind_loc_min_cand, vec.begin() + i - 1);

						i = ind_loc_min_cand + 1;
					}

					vec[ind_loc_min_cand] = total_min;
					
					ind_loc_min_cand = 0;

				}
				else if (vec[i - 1] > vec[i])
				{
					ind_loc_min_cand = i;
				}
				else
				{
					continue;
				}
			}
		}
		PrintVec(vec);
	}

	//16. Заменить каждый элемент массива количеством элементов массива с меньшими индексами, имеющими значение, меньше данного элемента, 
	//т.е.каждый элемент массива ai заменить количеством элеметвом массива aj, таких что j < i и aj < ai.
	//4 3 6 3 5 6 6 3 2 4 3 2 2
	//          4
	void Task16_1()
	{
		std::vector<int> vec = { 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 };
		// 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 
		// 0, 0, 2, 0, 3, 4, 4, 0, 0, 4, 1, 0, 0

		std::vector<int> vec1;
		vec1.push_back(0);

		for (int i = 1; i < vec.size(); i++)
		{
			int count_of_lefts = 0;
			for (int j = 0; j < i; j++)
			{
				if (vec[j] < vec[i])
				{
					count_of_lefts++;
				}
			}
			vec1.push_back(count_of_lefts);
		}
		PrintVec(vec1);
	}

	void Task16()
	{
		std::vector<int> vec = { 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 };
		// 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 
		// 0, 0, 2, 0, 3, 4, 4, 0, 0, 4, 1, 0, 0

		for (int i = vec.size()-1; i >= 0; i--)
		{
			int count_of_lefts = 0;
			for (int j = 0; j < i; j++)
			{
				if (vec[j] < vec[i])
				{
					count_of_lefts++;
				}
			}
			vec[i] = count_of_lefts;
		}
		PrintVec(vec);
	}

	//18. Заменить все минимальные элементы массива на значение элемента массива, большего минимального, но не большего всех остальных элементов массива.
	void Task18_2()
	{
		std::vector<int> vec = { 2, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 };
		//{ 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 }
		//{ 4, 3, 6, 3, 5, 6, 6, 3, 2, 4, 3, 2, 2 }
		int min = vec[0];
		
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] < min)
			{
				min = vec[i];
			}
		}
		
		int min_delta;
		int i = 0; 

		for ( ; i < vec.size(); i++)
		{
			if (vec[i] != min)
			{
				min_delta = vec[i] - min;
				break;
			}
		}

		for (; i < vec.size(); i++)
		{
			if (vec[i] - min < min_delta && vec[i] != min)
			{
				min_delta = vec[i] - min;
			}
		}
		int next_min = min + min_delta;
		std::cout << min << ' ' << min_delta << ' ' << next_min << std::endl;
	}

	void Task18_1()
	{
		std::vector<int> vec = { 5,5,7,2,7,5,5,2,1 };
		
		int min=vec[0];
		int i = 0;

		for ( ; i < vec.size(); i++)
		{
			if (vec[i] % 2 == 0)
			{
				min = vec[i];
				break;
			}
		}

		for ( ; i < vec.size(); i++)
		{
			if (vec[i]%2 == 0 && vec[i] < min)
			{
				min = vec[i];
			}
		}






		std::cout << min << std::endl;
	}

	void Task18()
	{
		std::vector<int> vec = { 2,3,2,2,3,3,3,6,5,8,9,2 };
		
		int min = vec[0];
		int next_min = vec[0];

		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] < min)
			{
				next_min = min;
				min = vec[i];
			}
			else if (vec[i] < next_min && vec[i] > min || next_min == min)
			{
				next_min = vec[i];
			}
		}

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == min)
			{
				vec[i] = next_min;
			}
		}

		std::cout << min << ' ' << ' ' << next_min << std::endl;

		PrintVec(vec);
	}

	//19. Удалить из массива наиболее часто встречающееся значение. Если таких значений несколько, то выбрать любое из них. 
	//Функция должна возвращать количество элементов в получившемся массиве.
	void Task19()
	{
		std::vector<int> vec = { 2,3,2,2,3,3,3,6,5,8,9,2 };





	}












}