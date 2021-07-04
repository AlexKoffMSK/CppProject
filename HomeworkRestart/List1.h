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
	�������� �� ����������, � ������� ���� ��������� � ������ � �����.
	1. ������� 4 ������� (�� ������������) �������� e1,e2,e3,e4. ��������� �� ���: e1 <-> e3 <-> e2 <-> e4
	������� �� �����.
	2. ������� 2 ������� � 2 ������������, ��������� �� ������ ������ e1 -> e2 -> e3 -> e4. 
	������ ����� ������� nullptr;
	�������.
	3. ������� 30 ������������ ���������. ������� �� ��� ����������� ������ e1 <-> e2 <-> ... <-> e29 <-> e30.
	value � ������� ������� ���������.
	3.1. ������� �� �����
	3.2. ����� ����� ������� value.
	3.3. ��������� ����� ������ ������ ��������� ������.
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
		e2.pointer_to_next_elem = e3; //�� ����� ������ ������ ��� �3 ������������? ������ ��� �3 ���������.
		e2.pointer_to_prev_elem = nullptr;
		e3->pointer_to_next_elem = e4;
		e3->pointer_to_prev_elem = nullptr;
		e4->pointer_to_next_elem = nullptr;
		e4->pointer_to_prev_elem = nullptr;
	}

	void Test5()
	{
		Elem* ptr_to_first_elem_of_list = new Elem; 
		//Elem* pointer_to_first_elem_of_list = first_elem_of_list; //pointer_to_e - ��� �� ��������� �� e1, pointer_to_e ��������� ���� ��, ���� ��������� e1

		ptr_to_first_elem_of_list->pointer_to_prev_elem = nullptr;
		ptr_to_first_elem_of_list->value = 0;
		
		Elem* ptr_to_cur_elem_of_list = ptr_to_first_elem_of_list;

		int rnd_n = rand() % 10 + 10;
		for (int i = 1; i < rnd_n; i++)
		{
			ptr_to_cur_elem_of_list->pointer_to_next_elem = new Elem; //� �������� �������� ��������� - �����
			ptr_to_cur_elem_of_list->pointer_to_next_elem->value = rand()%200+201;
			ptr_to_cur_elem_of_list->pointer_to_next_elem->pointer_to_prev_elem = ptr_to_cur_elem_of_list;
			ptr_to_cur_elem_of_list = ptr_to_cur_elem_of_list->pointer_to_next_elem; //������ ������� - ��� �����
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