#pragma once
#include <iostream>
#include <cmath>

#include "sorts.h"

/*
void g()
{
	
	int a = std::rand() % 10;

	for (int i = 0; i < a; i++)
	{
		std::cout << "Heello";
	}
}

void g1(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		std::cout << "Heello" << b << std::endl;
	}
}

int g2(int a)
{
	std::cout << a << std::endl;
	return 1;
}

int g3(int a)
{
	std::cout << a << std::endl;
	return a * 2;
}

void g4(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void g5(int* arr)
{
	arr[1] = 3;
}

int g(int b)
{
	return b + 1;
}


int  f(int a)
{
	if (a >= 0)
	{
		return a * 2;
	}
	else
	{
		return g(a);
	}
}

int Factorial(int a)
{
	if (a == 1)
	{
		return 1;
	}
	else
	{
		return a * Factorial(a - 1);
	}
}

void f123(int a)

{
	std::cout << a << std::endl;
	if (a > 1)
	{
		f(a - 1);
	}
}

int tyu(int*, int, int )
int prime(int)
int wer(int *, int)
void (int int)
int (int int)
bool (int* int int* int)
int sign(double)
int (int)



void f()
{	
	int arr1[2] = { 0, 0 };
	int arr2[2] = { 1, 1 };
	
	g5(arr1);

	//int res = q(10);
	f123(10);

	// 0x008ffbc8  - 9436104
	// 0x008ffbb8  - 9436088
	// 16

	//arr2[1]
	//int a = 2;
	//int b = 4;
	//g1(3,1);

	//g1(4,1);
	//g1(a,a);
	//g1(b,1);
	//
	//int r = g2(3);

	//int e = g2(g2(4));
	// int e1 = g3(g3(4) + 5);
	// std::cout << e1 << std::endl;


}
*/

int compare_2_numbers_for_maximum(int a, int b)
//1. Принимает 2 числа, возвращает максимаьлное из них.
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int abs_of_number(int a)
//2. Принимает число, возвращает модуль(не использовать abs).
{
	if (a <= 0)
	{
		return (-a);
	}
	else
	{
		return a;
	}
}

int number_a_in_power_of_b(int a, int b)
//3. Принимает 2 числа a, b.Возвращает а в степени b(не использовать pow). 2 * 2 * 2 = 8
{
	int result = 1;
	for (int i = 1; i <= b; i++)
	{
		result *= a;
	}
	return result;
}

int compare_3_numbers_for_maximum(int a, int b, int c)
//4. Принимает 3 числа, возвращает максимальное.
{
	return compare_2_numbers_for_maximum(a, compare_2_numbers_for_maximum(b, c));
}

int random_bool()
//5. Ничего не принимает, вовзаращает случайно 0 или 1.
{
	int a = rand() % 2;
	return a;
}

int if_number_a_is_powered_b(int a, int b)
//6. Принимает 2 числа, возвращает true, если первое число, является результатом возведения в целочисленную степень второго числа.
{
//	int c = b;
//	for (int i = 0; i < a; i++)
//	{
//		if (pow(b, i) == a && pow(b, i) <= a)
//		{
//			return true;
//		}
//	}
//		return false;
//
//	int z = 0;
//	while (pow(b, z) != a && z<a)
//	{
//		z++;
//	}
//	//if (pow(b, z) == a)
//	//{
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}

	//return pow(b, z) == a; //вместо ифа выше

	int c = b;
	while (c < a)
	{
		c *= b;
	}
	return c == a;
}

void print_ascii_of_char(char a)
//7. Принимает char, выводит на экран его ASCII код.
{
	int b = a;
	cout << b << endl;
}

int random_come_back_of_number(int a)
//8. Принимает число, вовзращает это же число с 60 % вероятностью.В противном случае возвращает 0.
{
	int b = rand() % 100;
	if (b < 60)
	{
		return a;
	}
	else
	{
		return 0;
	}
}

void print_10_random_chars()
//9. Ничего не принимает.Печатает на экран 10 случайных символов.
{
	for (int i = 0; i < 10; i++)
	{
		char a = rand() % 256;
		cout << a << endl;
	}
}

int if_number_is_prime(int number)
//1. Написать функцию, которая принимает на вход число.Возвращает true, если число простое, иначе false;
{
	if (number <= 1)
	{
		return false;
	}
	
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
		return true;
}

void print_all_numbers_below_prime(int number)
//2. Написать функцию, которая принимает на вход число n.Вывести на экран все простые числа меньшие n.
{
	for (int i = 2;i < number; i++)
	{
		if (if_number_is_prime(i) == true)
		{
			cout << i << endl;
		}
	}
}

void print_n_prime_numbers_from_2(int n)
//3. Написать функцию, которая принимает на вход число n.Вывести на экран первых n простых чисел.
{
	int prime_counter = 0;
	int current_number = 0;
	
	while (prime_counter < n)
	{
		if (if_number_is_prime(current_number) == true)
		{
			cout << current_number << endl;
			prime_counter++;
		}
			current_number++;
	}
}

void print_prime_number_after_n(int n)
//4. Написать функцию, которая принимает на вход число n.Вывести на экран первое простое число большее n.
{
	
	//int prime_counter = 0;
	//int current_prime = n;
	//
	//while (prime_counter < 1)
	//{
	//	current_prime++;
	//	if (if_number_is_prime(current_prime) == true)
	//	{
	//		cout << current_prime << endl;
	//		prime_counter++;
	//	}
	//}


	//int prime_counter = 0;

	int current_prime = n+1;
	while (if_number_is_prime(current_prime) != true)
	{
		current_prime++;
	}
		cout << current_prime << endl;
}

void print_prime_number_after_n(int n, int p)
//5. Написать функцию, которая принимает на вход число n и p.Вывести на экран первые p простых чисел больших n.
{
	int prime_counter = 0;
	int prime_counter_limit = p;
	int current_number = n;
	
	while (prime_counter < prime_counter_limit)
	{
		current_number++;
		if (if_number_is_prime(current_number) == true)
		{
			cout << current_number << endl;
			prime_counter++;
		}
	}
}

void print_numbers_between_n_p(int n, int p)
//6. Написать функцию, которая принимает 2 целых числа и выводит все целые числа между ними.
{
	int left_limit = 0;
	int right_limit = 0;
	if (n < p)
	{
		left_limit = n;
		right_limit = p;
	}
	else
	{
		left_limit = p;
		right_limit = n;
	}
	for (int i = left_limit + 1; i < right_limit; i++)
	{
		cout << i << endl;
	}
}

void print_random_numbers_between_a_b(int a, int b) //-5-10
//7. Принимает 2 целых числа a, b и выводи случайное число из диапазона[a, b]
//[min, max]
//rand() % (max - min + 1) + min
{
	int left_limit = 0;
	int right_limit = 0;
	if (a < b)
	{
		left_limit = a;
		right_limit = b;
	}
	else
	{
		left_limit = b;
		right_limit = a;
	}
	int rnd_number = 0;
	rnd_number = rand() % (right_limit - left_limit+1) + left_limit;
	cout << rnd_number << endl;
}

bool return_random_true_false(int p) //45
//8. Принимает на вход число p из диапазона[0, 100], вовзаращет true с вероятность p%, иначе false.
{
	int prob_p = rand() % 101;
	return prob_p <= p;
}

int print_p_prob_of_a_else_b(int a, int b, int p) //5 7 45
//9. Принимает 3 числа(a, b, p).a, b любые.p из диапазона[0, 100].Возвращает a с вероятность.p%, иначе b.
{
	int prob_p = rand() % 101;
	return (prob_p <= p) ? a : b;
}

int generate_rand_1_0()
//10. Ничего не принимает.Генерирует случайное число в диапазоне[0, 1] до тех пор пока не сгенерируется 1. Возвращает количество генераций
{
	int iteration_counter = 0;
	while (rand() % 2 != 1)
	{
		iteration_counter++;
	}
	return iteration_counter;
}

int max_element_of_array(int* arr, int n)
//1. Написать функцию которая принимает массив интов и его размер.Вернуть максимальный элемент массива.
{
	int max_element = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
		}
	}
	return max_element;
}

int index_of_max_element_of_array(int* arr, int n)
//2. Написать функцию которая принимает массив интов и его размер.Вернуть индекс первого максимального элемента массива.
{
	int index_of_max_element = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[index_of_max_element])
		{
			index_of_max_element = i;
		}
	}
	cout << index_of_max_element;
	return 0;
}

int if_min_before_max_element_of_array(int* arr, int n)
//3. Написать функцию которая принимает массив интов и его размер.
//Вернуть true, если первый минимальный элемент массива встречается раньше первого максимального элемента массива, иначае false;
{
	int min_element = arr[0];
	int index_of_min_element = 0;
	int max_element = arr[0];
	int index_of_max_element = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min_element)
		{
			min_element = arr[i];
			index_of_min_element = i;
		}
		if (max_element < arr[i])
		{
			max_element = arr[i];
			index_of_max_element = i;
		}
	}
	return (index_of_min_element < index_of_max_element);
}

int summ_of_array_halfs(int* arr, int n)
//4. Написать функцию которая принимает массив интов и его размер.
//Вернуть true, если сумма первой половины равна сумме второй половине.если размер массива нечетный, то центральный элемент в сумме не участвует.
{
	int summ_0_m = 0;
	int summ_m_n = 0;

	if (n % 2 == 0)
	{
		for (int i = 0; i < n/2;i++)
		{
			summ_0_m += arr[i];
		}
		for (int i = n/2; i < n; i++)
		{
			summ_m_n += arr[i];
		}
	}
	if (n % 2 != 0)
	{
		for (int i = 0; i < n / 2;i++)
		{
			summ_0_m += arr[i];
		}
		for (int i = n/2+1; i < n; i++)
		{
			summ_m_n += arr[i];
		}
	}
	return (summ_0_m == summ_m_n);
}

int average_number_of_array(int* arr, int n)
//5. Написать функцию которая принимает массив интов и его размер.Вернуть среднее значение элементов массива.
{
	int average_number = 0;
	for (int i = 0; i < n; i++)
	{
		average_number = average_number + arr[i] / n;
	}
	return average_number;
}

void print_first_p_below_zero_elements_of_array(int* arr, int n, int p)
//6. Написать функцию которая принимает массив интов и его размер и число p.Непечатать первые p элементов массива, которые меньше нуля.
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0 && counter<p)
		{
			cout << arr[i];
			counter++;
		}
	}
}

int true_if_only_2_unic_numbers_in_arr(int* arr, int n)
//7. Написать функцию которая принимает массив интов и его размер.Вернуть если в массиве не более 2х уникальных чисел.
//Например: 1 1 1 1 - true. 1 2 2 1 2 1 1 2 - true. 1 1 2 2 1 3 1 2 - false.
{
	//int uniq_1 = arr[0];
	//int uniq_2 = 0;
	//int i = 0;
	//
	//for (; i < n; i++)
	//{
	//	if (arr[i] != uniq_1)
	//	{
	//		uniq_2 = arr[i];
	//		break;
	//	}
	//}
	//
	//for (; i < n; i++)
	//{
	//	if (arr[i] != uniq_1 && arr[i] != uniq_2)
	//	{
	//		return false;
	//	}
	//}
	//return true;
	
	int i = 0;
	while (i < n && arr[i] == arr[0])
	{
		i++;
	}
	for (int j = i; j < n; j++)
	{
		if (arr[j] != arr[0] && arr[j] != arr[i])
		{
			return false;
		}
	}
	return true;
}

int true_if_arr_mirror(int* arr, int n)
//8. Написать функцию которая принимает массив интов и его размер.Вернуть true если массив зеркальный. (палиндром)
{
	//int check_rounds = 0;

	// 0 1 2 3 4 5    n = 6.  n/2 = 3   0 1 2
	// 0 1 2 3 4      n = 5.  n/2 = 2   0 1

	for (int i = 0; i < n/2; i++)
	{
		//cout << arr[i] << ' ' << arr[n-i-1] << endl; // подобрал... но не понимаю - почему понадобилось добавлять -1...

		if (arr[i] != arr[n - i - 1])
		{
			return false;
			//check_rounds++;
		}
	}
	return true;

//Но идеи были вообще следующие: первая - дербаним массив пополам, пересортировываем его в обратном порядке и вычитаем один массив из другого
//ещё идея была - вместо i++ шагаем по сужающимся краям, типа 0-9,8-2,3-7,6-4,5

/*
0   9 : +9   9    9 7 5 3
9   8 : -1   1
8   1 : -7   7
1   2 : +1   1
2   7 : +5   5
7   6 : -1   1
6   3 : -3   3
3   4 : +1   1
5
*/

/*
1. Скопировть исходный массив в другой.
2. Развернуть другой
3. И из одного вычесть (сравнить что массивыы равны)
*/


// 1 2 3 4 5  4 3 2 1
// 4 3 2 1

//bubble_sort(arr, n);
//for (int i = 0; i < n; i++)
//{
//	cout << arr[i] << endl;
//}
//return 0;



//if (n % 2 == 0)
//{
//	for (int i = 0; i < n / 2;i++)
//	{
//
//	}
//	for (int i = n / 2; i < n; i++)
//	{
//
//	}
//}
//if (n % 2 != 0)
//{
//	for (int i = 0; i < n / 2;i++)
//	{
//
//	}
//	for (int i = n / 2 + 1; i < n; i++)
//	{
//
//	}
//}
//return ();
}

/*

3.  Неправильно. Интересно что решил заюзать сортировку, этот вариант оставь. Сдлеай 2 ваиранта:
	  3.1. Поправь этот с сортировкой, чтоб он правильно работал. Проблема в том что не каждый предпоследний элемент в отсортированном массиве является предмаксимальным (пример приводить не буду, сам подумай). Дам еще подсказку, что бывают массивы где вообще нет предмаксимального элемента.
	  3.2. Сделай реализацию, которая не меняет исходный массив. Т.е. нельзя его сортировать.
4. Правильно. Ради тренировки сделай тоже самое через вайл.
*/


bool true_if_arr_rising(int* arr, int n)
//9. Написать функцию которая принимает массив интов и его размер.Вернуть true, если массив возрастает.
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool true_if_1_elem_of_array_is_different_from_whole_array(int* arr, int n)
//10. Написать функцию которая принимает массив интов и его размер.Вернуть true если в массиве можно убрать один элемент,
//так что оставшиеся станут одинаковыми.Иначе false.
//Пример : 1 1 1 1 1 3 1 1 - true.  1 2 2 1 1 1 1 - false.  1 1 3 1 1 2 4 5 - false.
// 1 1 1 3 4 3 1 1
// 1 1 1 1 3 1 1 1
// 1 1 1 1 1 1 1 1
// 3 3 3 3 0 3 3 3
// 3 3 0 3 3 3 0 3

// 3 1 1 1 1 1 1 1
// 1 3 2 1 1 1 1 1
// 1 1 1 1 1 1 1 3
{
	// 1 1 1 3 4 3 1 1 
	// 1 2 2 2 2 2 2 2
	// n, n-1, n, n-1
	int counter_0 = 0;
	int counter_1 = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[0] == arr[i])
		{
			counter_0++;
		}
		if (arr[1] == arr[i])
		{
			counter_1++;
		}

		if (counter_0 + counter_1 < i)
		{
			return false;
		}
	}
	return (counter_0 == n || counter_0 == n - 1 || counter_1 == n - 1);
}

bool true_if_amount_of_negatives_less_then_positives(int* arr, int n)
//2. Написать функцию, которая принимает массив и его размер.Вернуть true, если отрицательных чисел в массиве меньше положительных.
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			counter++;
		}
		else
		{
			counter--;
		}
	}
	//cout << counter << endl;
	return (counter >= 0);
}

int print_premax_number_of_arr(int* arr, int n)
//3. Написать функцию, которая принимает массив и его размер.Вернуть предмаксимальный элемент массива.
//Пример : 2 3 4 8 2 4 6 3 4 5. Вывод : 6.
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		exchange_2_unordered_elems(arr, n);
	}

	cout << arr[n - 2] << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	return arr[n - 2];
}

void print_summ_of_elems_of_arr_while_less_p(int* arr, int n, int p)
//4. Написать функцию, которая принимает массив и его размер и число p.Выводить на экран элементы массива, пока сумма элементов не станет больше p.
{
	int summ = 0;

	for (int i = 0; i < n; i++)
	{
		summ += arr[i];

		if (summ <= p)
		{
			cout << summ << endl;
		}
	}
}

void move_elems_of_arr_right_by_1(int* arr, int n)
//5. Написать функцию, которая принимает массив и его размер.Циклически сдвинуть все элементы массива на один вправо.
//Пример : 0 1 2 3 4 5 6. Вывод : 6 0 1 2 3 4 5.
//         0 1 2 3 4 5 6. Вывод : 1 2 3 4 5 6 0

// 0 0 2 3 4 5 6.  1
// 0 0 1 3 4 5 6.  2

// 0 1 2 3 4 5 6.   0
// 0 1 2 3 4 5 0.
// 0 0 1 2 3 4 0.
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	int temp = 0;
	//int temp2 = 0;

	temp = arr[n-1];

	for (int i = n-2; i >= 1; i--)
	{
		//temp2 = arr[i];
		//arr[i] = temp;
		//temp = temp2;
		arr[i] = arr[i-1];
	}

	arr[0] = temp;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


void arr_sort_add(int* arr, int n, int a)
// функция принимает на вход отсортированный массив, и количество элементов в массиве, с которыми надо работать и число, которое надо вставить, 
// чтобы он остался отсортированным.
{
	// 1 3 4 4 6 7 7 8 9     10
	// 1 3 4 4 6 7 7 8 9 10

	if (n == 0 || a > arr[n - 1])
	{
		arr[n] = a;
		return;
	}

	// Мы должны закончить цикл, если встретили в массие элемент, который больше 5

	int index_for_add = 0; //3

	//for (int i = 0; i < n; i++)
	//{
	//	if (a > arr[i])
	//	{
	//		index_for_add = i;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}

	while (a > arr[index_for_add])
	{
		index_for_add++; //на 1 шаг и итерацию больше, чем нужный индекс для подстановки нового элемента, нужно будет сделать -1!
	}

	// 1 3 4 4 6 7 7 8 9     5, позиция 4(там где число 6)
	// 1 3 4 4 5 6 7 7 8 9 

	for (int i = n-1; i >= index_for_add; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index_for_add] = a;
}