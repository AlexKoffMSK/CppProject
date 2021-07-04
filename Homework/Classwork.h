#pragma once
#include <iostream>;
using namespace std;

// 1. Функция, которая ничего не принимает. Печатает на экран числа от 10 11 12 .. до 50.
void task_1()
{
	for (int i = 10; i <= 50; i++)
	{
		cout << i << " ";
	}
}

// 2. Функция. Принимает число a, печатает на экран числа a, 2a, 3a, 4a, ..., 30a.
void task_2(int a)
{
	for (int i = 1; i <= 30; i++)
	{
		cout << i * a << ' ';
	}
}

// 3. Функция. Принимает число a, печатает на экран a раз число а.
void task_3(int a)
{
	for (int i = 0;i < a;i++)
	{
		cout << a << ' ';
	}
}


// 4. Функция. Выводит следующее: 1 1 1 1 1  2 2 2 2 2  3 3 3 3 3 ... 8 8 8 8 8 9 9 9 9 9.
void task_4()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0;j < 5; j++)
		{
			cout << i << ' ';
		}
		cout << ' ';
	}
}


// 5. Функция, принимает 2 числа a,b. Вывести все числа между ними от меньшего к большему.
void task_5(int a, int b)
{
	int min = (a>b) ? b : a;
	int max = (a>b) ? a : b;

	//int min = 0;
	//int max = 0;
	//if (a > b)
	//{
	//	max = a;
	//	min = b;
	//}
	//else
	//{
	//	max = b;
	//	min = a;
	//}

	for (int i = min;i <= max;i++)
	{
		cout << i << ' ';
	}
}

// 6. Функция принимает массив и его размер. Вывести сумму элементов массива с четными индексами, произведение элементов массива с нечсетными индексами
void task_6(int* arr, int n)
{
	//int summ = 0;
	//for (int i = 0; i < n; i+=2)
	//{
	//	summ += arr[i];
	//}

	// 0 1 2 3 4
	// 0 1 2 3 4 5

	//int summ = 0;
	//int prod = 1;
	//for (int i = 0; i < n; i+=2)
	//{
	//	summ += arr[i];
	//
	//	if (i < n - 1)
	//	{
	//		prod *= arr[i+1];
	//	}
	//}

	//int summ = 0;
	//int prod = 1;
	//for (int i = 0; i < n; i++)
	//{
	//	if (i % 2 == 0)
	//	{
	//		summ += arr[i];
	//	}
	//	else
	//	{
	//		prod *= arr[i + 1];
	//	}
	//}

	int summ = 0;
	int prod = 1;
	for (int i = 0; i < n+1; i += 2)
	{
		summ += arr[i];
	}
	for (int i = 1; i < n; i += 2)
	{
		prod *= arr[i + 1];
	}

	cout << summ << ' ' << prod;
}

// 7. Написать функцию, которая принимает массив и его размер. Найти максимум и записать его вмето нулей в массиве.
// Пример: 2 4 3 5 0 6 5 0 4 3 5. Итог : 2 4 3 5 6 6 5 6 4 3 5

void task_7(int* arr, int n)
{
	int max = arr[0];
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = max;
		}
		cout << arr[i] << ' ';
	}
}

// 8. Создать двумерный массив n*m и заполнить его случайными числами от 1 до 9 включительно
// 10 раз в случаное место в матрице записать 0. Вывести координаты всех нулей
void task_8()
{
	const int n = 10;
	const int m = 20;
	int arr[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	for (int k = 0; k < 10; k++)
	{
		arr[rand() % n][rand() % m] = 0;
	}
	
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << i << ' ' << j;
				cout << endl;
			}
		}
	}
}

// 9. Создать двумерный массив n*m и заполнить его случайными числами от 1 до 9 включительно
// В случаное место в матрице записать 0.
// Занулить строку и столбец, на пересечении которых стоит 0
void task_9()
{
	const int n = 10;
	const int m = 10;
	int arr[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	arr[rand() % n][rand() % m] = 0;

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	int zero_i = 0;
	int zero_j = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				zero_i = i;
				zero_j = j;
			}
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		arr[zero_i][j] = 0;
	//		arr[i][zero_j] = 0;
	//	}
	//}

	/*
	arr[zero_i][0]   = 0;
	arr[zero_i][1]   = 0;
	...
	arr[zero_i][m-1] = 0;
	arr[zero_i][j]   = 0
	*/

	for (int i = 0; i < n; i++)
	{
		arr[i][zero_j] = 0;
	}

	for (int j = 0; j < m; j++)
	{
		arr[zero_i][j] = 0;
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "Ready" << endl;
}




void ClassworkTask()
{
	//task_1();
	//task_2(2);
	//task_3(10);
	//task_4();
	//task_5(15,5);
	//int arr[] = { 1,6,0,6,7,0,3,6,7 };
	//task_6(arr, size(arr));
	//task_7(arr, size(arr));
	//task_8();
	task_9();
}