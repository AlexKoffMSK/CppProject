#pragma once
#include <iostream>

namespace ContainerList1
{
	struct Elem
	{
		int value;
		Elem* pointer_to_next_elem;
		Elem* pointer_to_prev_elem;
	};

	void Test1()
	{
		Elem* e1 = new Elem;
		Elem* e2 = new Elem;
		Elem* e3 = new Elem;

		e1->value = 1;
		e2->value = 2;
		e3->value = 3;

		e1->pointer_to_next_elem = e2;
		e1->pointer_to_prev_elem = nullptr;
		e2->pointer_to_next_elem = e3;
		e2->pointer_to_prev_elem = e1;
		e3->pointer_to_next_elem = nullptr;
		e3->pointer_to_prev_elem = e2;
	}

	void Test2()
	{
		Elem* e1 = new Elem;
		Elem* q = e1;

		e1->pointer_to_prev_elem = nullptr;

		for (int i = 0; i < 10; i++)
		{
			Elem* q1 = new Elem;
			
			q->pointer_to_next_elem = q1;
			q1->pointer_to_prev_elem = q;
			q = q->pointer_to_next_elem;
		}
		q->pointer_to_next_elem = nullptr;
	}

	/*
	Работаем со структурой, у которой есть указатель и вперед и назад.
	1. Создать 4 обычных (не динамических) элемента e1,e2,e3,e4. Соединить их так: e1 <-> e3 <-> e2 <-> e4
	Вывести на экран.
	2. Создать 2 обычных и 2 динамических, соединить их только вперед e1 -> e2 -> e3 -> e4. 
	Ссылки назад сделать nullptr;
	Вывести.
	3. Создать 30 динамических элементов. Сделать из них полноценный список e1 <-> e2 <-> ... <-> e29 <-> e30.
	value у каждого сделать рандомным.
	3.1. Вывести на экран
	3.2. Найти самый большой value.
	3.3. Посчитать сумму только четных элементов списка.
	*/

	void Test3()
	{
		Elem e1;
		Elem e2;
		Elem e3;
		Elem e4;

		e1.pointer_to_prev_elem = nullptr;
		e1.pointer_to_next_elem = &e3;
		e3.pointer_to_prev_elem = &e1;
		e3.pointer_to_next_elem = &e2;
		e2.pointer_to_prev_elem = &e3;
		e2.pointer_to_next_elem = &e4;
		e4.pointer_to_prev_elem = &e2;
		e4.pointer_to_next_elem = nullptr;
	}

	void Test4()
	{
		Elem e1;
		Elem e2;
		Elem* e3 = new Elem;
		Elem* e4 = new Elem;
		int* p;
		e1.pointer_to_prev_elem = nullptr;
		e1.pointer_to_next_elem = &e2;
		e2.pointer_to_next_elem = e3; //не выдаёт ошибку потому что е3 динамический? Потому что е3 указатель.
		e2.pointer_to_prev_elem = nullptr;
		e3->pointer_to_next_elem = e4;
		e3->pointer_to_prev_elem = nullptr;
		e4->pointer_to_next_elem = nullptr;
		e4->pointer_to_prev_elem = nullptr;
	}

	void Test5()
	{
		Elem* ptr_to_first_elem_of_list = new Elem; 
		//Elem* pointer_to_first_elem_of_list = first_elem_of_list; //pointer_to_e - это не указатель на e1, pointer_to_e указывает туда же, куда указывает e1

		ptr_to_first_elem_of_list->pointer_to_prev_elem = nullptr;
		ptr_to_first_elem_of_list->value = 0;
		
		Elem* ptr_to_cur_elem_of_list = ptr_to_first_elem_of_list;

		int rnd_n = rand() % 10 + 10;
		for (int i = 1; i < rnd_n; i++)
		{
			ptr_to_cur_elem_of_list->pointer_to_next_elem = new Elem; //у текущего элемента следующий - новый
			ptr_to_cur_elem_of_list->pointer_to_next_elem->value = rand()%200+201;
			ptr_to_cur_elem_of_list->pointer_to_next_elem->pointer_to_prev_elem = ptr_to_cur_elem_of_list;
			ptr_to_cur_elem_of_list = ptr_to_cur_elem_of_list->pointer_to_next_elem; //теперь текущий - это новый
		}
		ptr_to_cur_elem_of_list->pointer_to_next_elem = nullptr;

		ptr_to_cur_elem_of_list = ptr_to_first_elem_of_list;

		while (ptr_to_cur_elem_of_list != nullptr)
		{
			cout << ptr_to_cur_elem_of_list->value << ' ';
			ptr_to_cur_elem_of_list = ptr_to_cur_elem_of_list->pointer_to_next_elem;
		}

		int cur_max = ptr_to_first_elem_of_list->value;
		
		ptr_to_cur_elem_of_list = ptr_to_first_elem_of_list;

		while (ptr_to_cur_elem_of_list != nullptr)
		{
			if (ptr_to_cur_elem_of_list->value > cur_max)
			{
				cur_max = ptr_to_cur_elem_of_list->value;
			}
			ptr_to_cur_elem_of_list = ptr_to_cur_elem_of_list->pointer_to_next_elem;
		}
		cout << endl;
		cout << cur_max << endl;

		cout << endl;

		ptr_to_cur_elem_of_list = ptr_to_first_elem_of_list;

		int i = 1;
		int summ = 0;

		while (ptr_to_cur_elem_of_list != nullptr)
		{
			if (i % 2 == 0)
			{
				summ += ptr_to_cur_elem_of_list->value;
				std::cout << summ << ' ';
			}
			i++;
			ptr_to_cur_elem_of_list = ptr_to_cur_elem_of_list->pointer_to_next_elem;
		}
	}




















}