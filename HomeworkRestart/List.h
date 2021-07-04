#pragma once
#include <iostream>

namespace ContainerList
{
	struct Elem
	{
		int value;
		Elem* p;
	};

	void test0()
	{
		int b = 3;
		int* p_b = &b;
		
		*p_b = 4; //через разыменование указател€ помен€ли в нЄм значение

		Elem a;
		Elem* p_a = &a;

		(*p_a).value = 4;//через разыменование указател€ помен€ли в нЄм значение
		p_a->value = 4;
	}

	void Test1()
	{
		Elem e;
		e.value = 3;

		Elem e1;
		e1.value = 4;
		
		e.p = &e1; //в поле "p" записан адрес переменной e1

		e1.p = &e;

		std::cout << e.value << std::endl;
		std::cout << e1.p->value << std::endl;
		std::cout << e1.p->p->p->value<< std::endl;
	}

	void Test2()
	{
		Elem e1;
		Elem e2;
		Elem e3;

		e1.value = 1;
		e2.value = 2;
		e3.value = 3;

		e1.p = &e2;
		e2.p = &e3;
		e3.p = &e1;

		Elem* q = &e1;

		cout << q->value << endl;
		
		cout << q->p->value << endl;
		
		cout << q->p->p->value << endl;
		
		cout << q->p->p->p->value << endl;
	}

	void Test3()
	{
		Elem e1;
		e1.value = 1;

		e1.p = &e1;
	}

	void Test4()
	{
		Elem e1;
		e1.value = 1;

		Elem* e2 = new Elem;
		e2->value = 2;

		e1.p = e2;
		e2->p = &e1;
	}

	void Test5()
	{
		Elem* e1 = new Elem;

		e1->p = new Elem;

		e1->p->value = 2;

		e1->p->p = new Elem;

		e1->p->p->value = 3;

		e1->p->p->p = e1;
	}

	void Test6()
	{
		Elem* e1 = new Elem;
		e1->p = new Elem;
		e1->value = 1;
		e1->p->value = 2;
		e1->p->p = new Elem;
		e1->p->p->value = 3;
		e1->p->p->p = e1;

		Elem* q = e1;
		cout << q->value << endl;

		q = q->p;
		cout << q->value << endl;

		q = q->p;
		cout << q->value << endl;
	}

	void Test7()
	{
		Elem* e1 = new Elem;
		e1->value = 0;
		Elem* q = e1;

		for (int i = 1; i <= 10; i++)
		{
			q->p = new Elem;
			q = q->p;
			q->value = i;
			//cout << q->value << endl;
		}

		Elem* q1 = e1;
		cout << q1->value << endl;
		for (int i = 0; i < 10; i++)
		{
			q1=q1->p;
			cout << q1->value << endl;
		}
	}

	void Test8()
	{
		Elem* e1 = new Elem;
		e1->value = 0;
		Elem* q = e1;

		for (int i = 1; i <= 10; i++)
		{
			q->p = new Elem;
			q = q->p;
			q->value = i;
			//cout << q->value << endl;
		}

		q->p = nullptr;

		Elem* q1 = e1;
		cout << q1->value << endl;

		while (q1->p != nullptr)
		{
			q1 = q1->p;
			cout << q1->value << endl;
		}
	}

	void Summ()
	{
		Elem* e1 = new Elem;
		e1->value = 0;
		Elem* q = e1;

		for (int i = 1; i <= 10; i++)
		{
			q->p = new Elem;
			q = q->p;
			q->value = i;
			//cout << q->value << endl;
		}
		q->p = nullptr;
		
		q = e1;
		int summ=0;

		while (q != nullptr)
		{
			summ += q->value;
			cout << q->value << ' ' << summ << endl;
			q = q->p;
		}
	}

	void Is_Sorted()
	{
		Elem* e1 = new Elem;
		e1->value = 0;
		Elem* q = e1;

		for (int i = 1; i <= 10; i++)
		{
			q->p = new Elem;
			q = q->p;
			q->value = i;
		}
		q->p = nullptr;

		q = e1;
		//cout << q->value << ' ' << q->p->value << endl;
		
		bool is_sorted = true;
		
		while (q->p != nullptr)
		{
			if (q->value > q->p->value)
			{
				is_sorted = false;
				break;
			}
			q = q->p;
		}
		cout << is_sorted << endl;
	}

	void FindMiddle()
	{
		Elem* e1 = new Elem;
		e1->value = 0;
		Elem* q = e1;
		for (int i = 1; i <= 11; i++)
		{
			q->p = new Elem;
			q = q->p;
			q->value = i;
		}
		q->p = nullptr;
		
		q = e1;
		Elem* q1 = e1;

		//вывести на экран средний элемент списка не использу€ 10

		while (q1 != nullptr)
		{
			q = q->p;
			q1 = q1->p->p;
		}
		cout << q->value << endl;
	}
}