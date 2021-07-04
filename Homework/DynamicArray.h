#pragma once
#include <chrono>
#include <iostream>
#include <limits>

using namespace std;


void DynamicArray()
{
	// Пользователь вводит число, создать массив такого размера

	int n;
	cin >> n;

	// const int n=5;
	// int arr[n];  - статический массив, размер должен быть известен на этапе компиляции
	
	int* arr = new int[n]; // динамический массив. Динамичность массива - это свойство его, которое говорит о том, что его размер становится известен только в момент работы программы, а не на этапе компиляции.

	
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << ' ';
	}

	cout << endl;
	
	// можно потерять связь с зарезервированой паматью!

	delete[] arr; // массив мне больше не нужен. Память занимаемая им отдается назад ОС
}

void DynamicArrayLeak()
{
	{
		// char - занимает 1 байт
		char* arr = new char[1024 * 1024 * 512]; // ПОпросили у ОС - 1мб
		
		system("pause");
	}
}

void dynamic_array_shift_1(int* arr, int n)
//принимает массив и его размер. создать второй массив и засунуть в него элементы первого массива, свдинув их на 1 позицию вправо (циклически)
//Пример : 0 1 2 3 4 5 6. Вывод : 6 0 1 2 3 4 5.
{
	int* new_arr = new int[n]; //создаем второй массив

	for (int i = 1; i < n; i++) 
	{
		new_arr[i] = arr[i - 1];
	}
	new_arr[0] = arr[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new_arr[i];
	}

	delete[] new_arr;
}

void dynamic_array_shift_3(int* arr, int n, int p)
//принимает массив и его размер. создать второй массив и засунуть в него элементы первого массива, свдинув их на 3 позиции вправо (циклически)
//Пример : 0 1 2 3 4 5 6. Вывод : 4 5 6 0 1 2 3.
{
	int* new_arr = new int[n]; //создаем второй массив

	for (int i = 0; i < n-p; i++)
	{
		new_arr[i + p] = arr[i];
	}

	for (int i = n-p; i < n; i++)
	{
		new_arr[i - (n - p)] = arr[i];
	}

	//for (int i = 0; i < 3; i++)
	//{
	//	new_arr[i] = arr[i+(n-3)];
	//}

	// i
	// n-3  - (n-3) = 0
	// n-2  - (n-3) = 1
	// n-1  - (n-3) = 2

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << new_arr[i] << ' ';
	}
	cout << endl;
	cout << endl;

	delete[] new_arr;
}

void dynamic_array_shift_3_adv(int* arr, int n, int p)
//принимает массив и его размер. создать второй массив и засунуть в него элементы первого массива, свдинув их на 3 позиции вправо (циклически)
//Пример : 0 1 2 3 4 5 6. Вывод : 4 5 6 0 1 2 3.
{
	int* new_arr = new int[n]; //создаем второй массив

	for (int i = 0; i < n; i++)
	{
		new_arr[(i + p) % n] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << new_arr[i] << ' ';
	}
	cout << endl;
	cout << endl;

	delete[] new_arr;
}


void dynamic_array_sort_from_arr(int* arr, int n)
//принимает массив и его размер. создать новый СРАЗУ отсортированный массив из элементов первого массива
{
	cout << "Start work v1 algorithm with size (" << n << "): ";
	int* new_arr = new int[n]; //создаем второй массив длины, равной первому массиву

	int current_min_bound = -1; //создаем движимую границу минимального значения для дальнейшей сортировки

	int new_arr_index_for_insert = 0; //создаем переменную, указывающую на то - куда заполнять следующий отсортированный элемент

	auto start = chrono::system_clock::now(); // Начинаем засекать время

	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;

	while (new_arr_index_for_insert < n) //запускаем цикл с ограничением - количества элементов для заполнения
	{
		int min = INT_MAX; // Возвращает самое максимальное число, которое можно засунуть в int
		int counter_min = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= current_min_bound)
			{
				continue; // Идти на новую итерацию
			}

			if (arr[i] < min)
			{
				counter_min = 0;
				min = arr[i];
			}

			if (arr[i] == min)
			{
				counter_min++;
			}
		}

		current_min_bound = min;

		for (int i = 0; i < counter_min; i++)
		{
			new_arr[new_arr_index_for_insert + i] = min;
		}

		new_arr_index_for_insert += counter_min;

		//for (int i = 0; i < n; i++)
		//{
		//	cout << new_arr[i] << ' ';
		//}
		//cout << endl;
	}

	auto end = chrono::system_clock::now(); // Заканчиваем засекать вермя
	chrono::duration<double> elapsed = end - start;
	cout << setprecision(15) << elapsed.count() << "s" << endl; // Выводим сколько времени засекли

	delete[] new_arr;

	//cout << endl;
}


void dynamic_array_sort_from_arr_v2(int* arr, int n)
//принимает массив и его размер. создать новый СРАЗУ отсортированный массив из элементов первого массива
// 7 4 2 3 5 9 7 8 9 3 4 5 2 3 2
{
	cout << "Start work v2 algorithm with size (" << n << "): ";
	int* new_arr = new int[n]; //создаем второй массив длины, равной первому массиву

	// 7 4 2 3 5 9 7 8 9 3 4 5 2 3 2
	// Берем очередной эоемент: 7
	// Ищем куда его вставить в новом массиве. Новый массив пустой, так что вставляем в самое начало: "7"
	// Берем очередной эоемент: 4
	// Ищем куда его вставить в новом массиве. Массив уже не пустой "7", то надо понять куда вставить, в данном случае надо вставить перед 7 и сдвинуть 7 вперед
	// "4 7"
	// Берем очередной эоемент: 2
	// Ищем куда его вставить в новом массиве. Массив уже не пустой "4 7", "2 4 7"
	// Берем очередной эоемент: 3
	// Ищем куда его вставить в новом массиве. Массив уже не пустой "2 4 7", "2 3 4 7"

	auto start = chrono::system_clock::now(); // Начинаем засекать время

	for (int i = 0; i < n; i++)
	{
		arr_sort_add(new_arr, i, arr[i]); //или n-1 вместо i, т.к. мы передаём не размер массива, а размер поля для сортировки.
	}
	
	auto end = chrono::system_clock::now(); // Заканчиваем засекать вермя
	chrono::duration<double> elapsed = end - start;
	cout << setprecision(15) << elapsed.count() << "s" << endl; // Выводим сколько времени засекли


	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;
	//
	//for (int i = 0; i < n; i++)
	//{
	//	cout << new_arr[i] << ' ';
	//}
	//cout << endl;

	delete[] new_arr;
}





void DynamicArrayLobby()
{
	//DynamicArray();
	//DynamicArrayLeak();
	
	const int n = 10000000;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand() % 10;
		//arr[i] = i;
		arr[i] = n - i;
	}
	//for (int p = 0; p < n; p++)
	//{
		//dynamic_array_shift_3(arr, n, p);
		//dynamic_array_shift_3_adv(arr, n);
	//}
	//dynamic_array_sort_from_arr(arr, n);
	//dynamic_array_sort_from_arr_v2(arr, n);


	// 1 2 3 2 2 2 2 3 3 3 1 1 1 1 2 2 3 3 2 1
	// ((1 + n)n)/2 = 0.5 (n^2 + n)
	// 3n

	for (int size = 1000; size <= 25000; size *= 5)
	//for (int size = 2; size <= n; size *= size)
	{
		dynamic_array_sort_from_arr(arr, size);
		dynamic_array_sort_from_arr_v2(arr, size);
	}

	delete[] arr;
}