#pragma once
#include <iostream>

namespace ContainerList2
{
	struct Elem
	{
		int value;
		Elem* ptr1;
		Elem* ptr2;
		Elem* ptr3;
	};

	void Test1()
	{
		Elem* ptr_to_first_elem = new Elem;

		ptr_to_first_elem->value = 1;
		ptr_to_first_elem->ptr1 = new Elem;
		ptr_to_first_elem->ptr2 = new Elem;
		ptr_to_first_elem->ptr3 = nullptr;

		ptr_to_first_elem->ptr1->value = 2;
		ptr_to_first_elem->ptr1->ptr1 = new Elem;
		ptr_to_first_elem->ptr1->ptr2 = ptr_to_first_elem;
		ptr_to_first_elem->ptr1->ptr3 = nullptr;

		ptr_to_first_elem->ptr2->value = 3;
		ptr_to_first_elem->ptr2->ptr1 = ptr_to_first_elem;
		ptr_to_first_elem->ptr2->ptr2 = nullptr;
		ptr_to_first_elem->ptr2->ptr3 = ptr_to_first_elem->ptr1->ptr1;
		
		ptr_to_first_elem->ptr1->ptr1->value = 4;
		ptr_to_first_elem->ptr1->ptr1->ptr1 = nullptr;
		ptr_to_first_elem->ptr1->ptr1->ptr2 = ptr_to_first_elem;
		ptr_to_first_elem->ptr1->ptr1->ptr3 = nullptr;
	}

	struct ElemCircle
	{
		int value;
		ElemCircle* ptr_to_c;
	};

	struct ElemSquare
	{
		int value;
		ElemSquare* ptr_to_s;
		ElemCircle* ptr_to_c;
	};

	void Test2()
	{
		ElemCircle* ptr_to_first_elem_c = new ElemCircle;
		ptr_to_first_elem_c->value = 1;
		ptr_to_first_elem_c->ptr_to_c = new ElemCircle;
		ptr_to_first_elem_c->ptr_to_c->value = 2;
		ptr_to_first_elem_c->ptr_to_c->ptr_to_c = new ElemCircle;
		ptr_to_first_elem_c->ptr_to_c->ptr_to_c->value = 3;

		ElemSquare* ptr_to_first_elem_s = new ElemSquare;
		ptr_to_first_elem_s->value = 11;
		ptr_to_first_elem_s->ptr_to_c = ptr_to_first_elem_c;

		ptr_to_first_elem_s->ptr_to_s = new ElemSquare;
		ptr_to_first_elem_s->ptr_to_s->value = 12;
		ptr_to_first_elem_s->ptr_to_s->ptr_to_c= ptr_to_first_elem_c->ptr_to_c;

		ptr_to_first_elem_s->ptr_to_s->ptr_to_s = new ElemSquare;
		ptr_to_first_elem_s->ptr_to_s->ptr_to_s->value = 13;

		ptr_to_first_elem_s->ptr_to_s->ptr_to_s->ptr_to_c = new ElemCircle;
		ptr_to_first_elem_s->ptr_to_s->ptr_to_s->ptr_to_c->value = 4;

		ptr_to_first_elem_c->ptr_to_c->ptr_to_c->ptr_to_c = ptr_to_first_elem_s->ptr_to_s->ptr_to_s->ptr_to_c;
	}



















}