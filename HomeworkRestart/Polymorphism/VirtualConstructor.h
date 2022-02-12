#pragma once
#include <iostream>
#include <memory>
#include "VirtualDestructor.h"

namespace PolymorphismVirtual
{
//����������� ����������� - ��� �� ���� ����� C++, � ������� ��������������, ���������� �����//

//���� �������� ������ "�", ������� � ������ ������ ������ �, ���� "B" - �� ������ B, ����� ������� nullptr
	std::unique_ptr<Base> Create(std::string str)
	{
		if (str == "A")
		{
			return std::unique_ptr<Base>(new A);
		}
		else if (str == "B")
		{
			return std::unique_ptr<Base>(new B);
		}
		else
		{
			return nullptr;
		}
	}

	void Test4()
	{
		std::unique_ptr<Base> a = Create("A");
		a->foo();
		std::unique_ptr<Base> b = Create("B");
		b->foo();
		std::unique_ptr<Base> x = Create("C");
		if (x == nullptr)
		{
			std::cout << "NullPtr" << std::endl;
		}
		else
		{
			x->foo();
		}
	}






















}