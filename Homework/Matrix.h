#pragma once
#include <iostream>
#include <cmath>


void summ_of_up_right_and_down_left_elems_of_matrix()
//1. Создать двумерную матрицу размера n на m и заполнить случайными числами.
//Вывести сумму элементов правой верхней полловины матрицы и сумму левой нижней.
{
	const int n = 4;
	const int m = 6;
	int arr[n][m]; //n - количество сток, m - количество столбцов
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1; // n - ( n / m ) * m = n % m
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	int summ_up_right = 0;

	for (int i = 0; i < n/2; i++) //от нулевой строки до середины строк
	{
		for (int j = m/2; j < m ; j++) //от середины столбцов до конца столбцов
		{
			summ_up_right += arr[i][j];
		}
	}

	cout << summ_up_right << endl;


	int summ_down_left = 0;

	for (int i = n/2; i < n; i++) //от середины строк до конца строк
	{
		for (int j = 0; j < m/2; j++) //от начала столбцов до середины столбцов
		{
			summ_down_left += arr[i][j];
		}
	}

	cout << summ_down_left << endl;
}

void transpose_of_matrix()
//2. Создать квадратную двумерную матрицу размера n на m и заполнить случайными числами.Транспонировать матрицу.
//ДОДЕЛАТЬ!!!
{
	const int n = 4;
	const int m = 4;
	int arr[n][m]; //n - количество сток, m - количество столбцов
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void matrix_generation_z()
//3. Создать двумерную матрицу размера n на m.Заполнить ее таким образом :
//0  1  2  3  4
//5  6  7  8  9
//10 11 12 13 14
//...
{
	const int n = 10;
	const int m = 5;
	int cur_number = 0;
	int max_number = n*m;
	int arr[n][m];

	//for (int i = 0; i <n; i++) 
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		arr[i][j] = j+i*m; //конвертация координат в число
	//	}
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		arr[i][j] = cur_number; //конвертация из числа в координаты
	//		cur_number++;
	//	}
	//}

	for (int k = 0; k < max_number; k++)
	{
		cout << "k = " << k << "   " << "i = " << k / m << "   j = " << k % m << endl;
		arr[k / m][k % m] = k; //остаток от деления меньшего на большее значит что - никому ничего не досталось, в остатке то что делили! Т.е. числитель.
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

}

void matrix_generation()
{
	const int n = 10;
	const int m = 5;
	for (int k = 0; k < 100; k++)
	{
		int i = k / m;
		int j = k % m;
		int new_k = j + i * m;
		cout << "k = " << k << "   " << "i = " << i << "   j = " << j << "   new_k = " << new_k << endl;
	}
}