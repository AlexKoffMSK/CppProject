#pragma once
#include<iostream>

namespace Pointers
{
	void f()
	{
		int a=3;
		int b=4;
		//char c;

		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		//std::cout << &b << '-' << std::ios::dec<<&b << std::endl;
		//std::cout << &c << '-' << std::ios::dec<<&c << std::endl;

		int* pointer_to_a = &a; //создаем переменную для хранения адреса переменной int a. 
		//int* - это указатель на int, который хранит адрес интовых переменных
		//указатель int* смотрит на ячейку памяти, где записан int

		//std::cout << &adr_a << std::endl;
		std::cout << pointer_to_a << std::endl;

		pointer_to_a = &b;

		//std::cout << &adr_a << std::endl;
		std::cout << pointer_to_a << std::endl; //выводим значение, т.е. адрес
		std::cout << *pointer_to_a << std::endl; //выводим уже не сам адрес, а то - что под ним живёт, называется - разыменовывание
		
		*pointer_to_a = 5; //стучимся внутрь (в контексте в коде, а не при объявлении)
		
		std::cout << b << std::endl;
	}

	void f05()
	{
		int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
		int* pointer_to_3 = &arr[3];
		int* pointer_to_4 = &arr[4];
		std::cout << pointer_to_3 - pointer_to_4 << std::endl;
		//общая формула: (p1 - p0) / sizeof (int) = (4 - 3) / 4 - это в случае с int = сколько интов между этими адресами, не включая правый
		std::cout << pointer_to_4 - pointer_to_3 << std::endl;

		int* pointer_to_last_element_of_arr = &arr[std::size(arr) - 1]; //адрес последней ячейки в массиве
		int* pointer_to_zero_element_of_arr = &arr[0];
		std::cout << pointer_to_last_element_of_arr - pointer_to_zero_element_of_arr + 1 << std::endl;// расстояние между двумя указателями в int-ах
	}

	void f1()
	{
		int a = 5;
		int b = 10;

		int* pointer_to_a = &a; //в указатель pointer_to_a записали адрес a
		int* pointer_to_b = &b;

		std::cout << pointer_to_a << std::endl;
		std::cout << pointer_to_b << std::endl;

		std::cout << pointer_to_a - pointer_to_b << std::endl;
		std::cout << pointer_to_b - pointer_to_a << std::endl;
	}

	void f15()
	{
		int arr[10] = {1,2,3,4,5,6,7,8,9,10};
		//int* pointer = &arr[0];
		//pointer = (int*)((char*)pointer + 1); 
		//(char*)pointer - воспринимай pointer как указатель на char, char - это 1 байт
		//(char*)pointer+1 - сместить pointer на 1 char (на 1 байт)
		//(int*)((char*)pointer + 1) - результат ((char*)pointer + 1) воспринимай как указатель на int 

		//std::cout << *pointer << std::endl;

		//вывести на экран все байты, которые входят в массив. байты выводить в виде числа
		
		//for (int z = 0; z < 65535; z++)
		//{
		//	std::cout << z << " - ";
		//	std::cout << (int)(*((unsigned char*)&z + 0)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 1)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 2)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 3)) << endl;
		//}
		//for (int i = 0; i < std::size(arr); i++) //можно тоже использовать for-auto цикл
		//{
		//	std::cout << (int)(*((unsigned char*)&arr[i]+0)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&arr[i]+1)) << ' '; 
		//	std::cout << (int)(*((unsigned char*)&arr[i]+2)) << ' '; 
		//	std::cout << (int)(*((unsigned char*)&arr[i] + 3)) << endl;
		//	//справа-налево:
			//&arr[i] - берем адрес i-ой ячейки массива (это указатель на int)
			//(char*)&arr[i] - воспринимаем его как указатель на char (это указатель на char)
			//*(char*)&arr[i] - разыменовываем указатель на char (это char)
			//(int)(*(char*)&arr[i]) - воспринимай это всё как int (это int)
		//
		//}
		std::cout << *(int*)((char*)&arr[0] - 1) << std::endl;
	}

	void f2()
	{
		int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
		//int* pointer = &arr[0];
		//std::cout << *pointer << std::endl;
		//pointer++; //сдвиг на следующий int, двигаемся по интам
		//std::cout << *pointer << std::endl;
		//(*pointer)++; //ЧЕРЕЗ указатель увеличили значение в 1-й ячейке массива
		//std::cout << arr[1] << std::endl;

		//int* pointer = &arr[0];
		//int* pointer_of_end = &arr[size(arr)-1];
		
		//while (pointer <= pointer_of_end)
		//{
		//	cout << pointer << ' ';
		//	cout << *pointer << endl;
		//	pointer++;
		//}

		//for (int* pointer = &arr[0]; pointer <= &arr[size(arr) - 1]; pointer++)
		for (int* pointer = &arr[0]; pointer < arr + std::size(arr); pointer++)
		{
			std::cout << pointer << ' ';
			std::cout << *pointer << std::endl;
		}
	}

	/*
	Создать массив {10,11,12,13,14,15,16,17,18,19};
	
	1. Вывести на экран адрес 3, 6 и 7 ячеек.
	
	2. Создать указатель p, который будет смотреть на  2 ячейку массива.
		Передвинуть его так, чтоб он смотрел на 6 ячейку массива.
		Выести на экран значение, на которое указывает p.
	
	3. Создать 2 указателя. p - смотрит на 3ю ячейку, q - на препоследнюю.
		Вывести количество ячеек между ними (не включая их самих). В данном приме это 4 (14,15,16,17).
	
	4. Создать 2 указателя. p - смотрит на 3ю ячейку, q - на препоследнюю.
		Вывести содержимое всех ячеек, ключая их самих. (Т.е. 13, 14,15,16,17, 18).
	
	4.1. Тоже самое, но в обратном порядке (18, 17, 16, 15,14,13).
	
	5. Записать в указатель p адрес случайной ячейки массива.
		Вывести true, если эта ячейка находится в левой части массива, false иначе.

	*/
	
	void task1()
	{
		int arr[10] = { 10,11,12,13,14,15,16,17,18,19 };
		//int* pointer_3 = &arr[3]; //создан указатель на элемент массива
		//int* pointer_6 = &arr[6];
		//int* pointer_7 = &arr[7];
		//std::cout << pointer_3 << std::endl; //выводится на экран адрес элемента массива в памяти
		//std::cout << pointer_6 << std::endl;
		//std::cout << pointer_7 << std::endl;
		
		//int* pointer_a = &arr[2]; //создан указатель на элемент массива
		//std::cout << pointer_a << std::endl; //выводится на экран адрес элемента массива в памяти
		//pointer_a = pointer_a + 4; //указатель сдвинут на +4 относительно стартового элемента массива
		//std::cout << pointer_a << std::endl; //вывод на экран адреса переменной в памяти, на которую указывает указатель
		//std::cout << *pointer_a << std::endl; //разыменовывается указатель - выводится на экран значение переменной, на которую указывает указатель

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr)-1-1];// первый "-1" - переход от размера массива к последнему элементу, второй "-1" - к предпоследнему
		//std::cout << pointer_q - (pointer_p+1) << std::endl;

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr) - 1 - 1];// первый "-1" - переход от размера массива к последнему элементу, второй "-1" - к предпоследнему
		////for (int* pointer = &arr[0]; pointer < arr + size(arr); pointer++)
		//for (int* pointer = pointer_p; pointer <= pointer_q; pointer++)
		//{
		//	std::cout << *pointer << std::endl;
		//}

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr) - 1 - 1];// первый "-1" - переход от размера массива к последнему элементу, второй "-1" - к предпоследнему
		////for (int* pointer = &arr[0]; pointer < arr + size(arr); pointer++)
		//for (int* pointer = pointer_q; pointer >= pointer_p; pointer--)
		//{
		//	std::cout << *pointer << std::endl;
		//}

		int* pointer_p = &arr[rand()%std::size(arr)]; //создан указатель на случайный элемент массива
		if (pointer_p < &arr[std::size(arr) / 2])
		{
			std::cout << "True" << std::endl;
			std::cout << pointer_p << std::endl; //debug-вывод
			std::cout << &arr[std::size(arr) / 2] << std::endl; //debug-вывод
		}
		else
		{
			std::cout << "False" << std::endl;
			std::cout << pointer_p << std::endl; //debug-вывод
			std::cout << &arr[std::size(arr) / 2] << std::endl; //debug-вывод
		}
	}

	/*
	  8 
	  9
	1 0
	1 1
	1 2

	8 0
	9 0
	0 1
	1 1
	2 1

	8
	9
	A
	B
	C
	D
	E
	F
	1 0
	1 1
	1 2
	...
	1 9
	1 A
	1 B
	1 C
	1 D
	1 E
	1 F
	2 0
	...
	F F
	1 0 0
	1 0 1
	1 0 2
	...
	1 0 F
	1 1 0
	...
	1 2 A
	1 2 B
	...
	1 F A
	1 F B
	...
	F F F
	1 0 0 0
	... это всё в шеснадцатеричной системе


	переходим к системе счисления по основанию 255 (255 цифр! - элементов записи числа)

	0
	1
	2
	...
	254
	255
	1 0
	1 1
	1 2
	...
	1 255
	2 0
	2 1
	2 2
	...
	255 254
	255 255
	1 0 0


	*/

	int* find_max_elem_in_segment_and_return_pointer(int* pointer_left_bound, int* pointer_right_bound) //указатель на левую и правую границу массива,
		//возвращает указатель на максимальный элемент диапазона
	{
		int* pointer_of_max_elem = pointer_left_bound;
		for (int* pointer = pointer_left_bound; pointer <= pointer_right_bound; pointer++)
		{
			if (*pointer >= *pointer_of_max_elem)
			{
				pointer_of_max_elem = pointer;
			}
		}
		return pointer_of_max_elem;
	}

	int* find_min_elem_in_segment_and_return_pointer(int* pointer_left_bound, int* pointer_right_bound) 
		//указатель на левую и правую границу массива,
		//возвращает указатель на миним альный элемент диапазона
	{
		int* pointer_of_min_elem = pointer_left_bound;
		for (int* pointer = pointer_left_bound; pointer <= pointer_right_bound; pointer++)
		{
			if (*pointer <= *pointer_of_min_elem)
			{
				pointer_of_min_elem = pointer;
			}
		}
		return pointer_of_min_elem;
	}

	//пример передачи в функцию указателя и ссылки
	void Test666(std::vector<int>& vec, std::vector<int>* vec1)
	{
		int a = 5;
		int* b = &a;
		int arr[10];
		int* c = arr;
		//c[4] = 8;
		//arr[11] = 8;
		c[21] = 8;
		int* d = &arr[0];
		b[5] = 3;

		vec[1];
		*(vec1 + 1);
	}

	//=============================

	void ForTest777(int* x)
	{
		(*x)++;
	}
	
	void Test777()
	{
		int a=5;
		int* pt_a = &a;
		std::cout << pt_a << std::endl;
		std::cout << *pt_a << std::endl;

		ForTest777(&a);
		
		std::cout << a << std::endl;
		std::cout << &a << std::endl;

		int arr[6]={ 1,2,3,4,5,6 };// массив на стеке
		//int* arr1 = new int[6]; //массив в куче
		int c;
		int* pt_arr = &arr[3];

		std::cout << *pt_arr << std::endl;
		*pt_arr = 0;
		std::cout << arr[3] << std::endl;

		pt_arr = &arr[4];
		//pt_arr++;
		std::cout << *pt_arr << std::endl;
		//pt_arr-=3;
		int* pt_arr0 = &arr[rand()%std::size(arr)];
		
		std::cout << &arr[4] << std::endl;
		std::cout << pt_arr << std::endl;
		//std::cout << &pt_arr0 << std::endl;

	
	}






















}