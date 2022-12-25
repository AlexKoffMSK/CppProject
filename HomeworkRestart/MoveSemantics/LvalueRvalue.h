#pragma once
#include <iostream>

namespace MoveSemantics
{
	//Lvalue - left value, Rvalue - right value
	
	void Test1()
	{
		int a = 4;
		a = 5; 
		//a - ��� lvalue, lvalue - ������ ��� � ���� ���� ��� � � ��� ���������� ����� ���-�� ��������
		//5 ��� rvalue, � ���� ��� �����, � ��� ������ �������� ������ ��������, ������� lvalue

		int b = 3;
		a = b; //� � � b - lvalue, �.�. � ��� ����� ���-�� ��������
		std::string str = "Hello"; //str - ��� lvalue, Hello - ��� rvalue
		//3 = a; //�� ���������, �.�. � rvalue ������ ����������� ����� ��������

		3 + 4; //��� ���������, ��� rvalue
		int c = 3 + 4; //� - lvalue

		int d = 3 + c; //3 rvalue, c - lvalue, 3+c rvalue, d - lvalue
		const int e = 3; // e - lavlaue, 3 rvalue
	}

	void Test11()
	{
		int a = 10;
		int* p_a = &a;
		int& ref_a = a;

		*p_a = 15;
		ref_a = 20;

		int&& rv = 30;
		rv = 15;

		std::cout << rv;

	}

	class IntWithCopyNotyfier
	{
	public:
		int _value = 0;
		IntWithCopyNotyfier(const IntWithCopyNotyfier& x_)
		{
			_value = x_._value;
			std::cout << "C";
		}
		IntWithCopyNotyfier(int y_)
		{
			_value = y_;
		}
		friend std::ostream& operator<<(std::ostream& os, const IntWithCopyNotyfier& x)
		{
			os << x._value;
			return os;
		}
	};

	class Test2
	{
	public:
		std::vector<IntWithCopyNotyfier> _vec;

		void SetVec(const std::vector<IntWithCopyNotyfier>& vec)
		{
			//vec[0] = 2;
			print_vector(vec, "\nvec in SetVec: ");
			_vec = vec;
			//_vec = std::move(vec);
			// ����������� ����� ������� vec � ������ vec2 - ��������� ����� ������ ��� vec2 � ����������� vec � vec2;
			print_vector(vec, "\nvec in SetVec after copy: ");
			print_vector(_vec, "\n_vec in SetVec after copy: ");
		}

		void SetVec1(std::vector<IntWithCopyNotyfier>&& vec) //&& � ������ ��������� ��������� ������� - ��� "������ �� rvalue" (aka rvalue-������), ��� ����� ��������� ������ �� rvalue-��������
		{
			print_vector(vec, "\nvec in SetVec: ");
			//_vec = vec;
			_vec = std::move(vec);
			// ����������� ����� ������� vec � ������ vec2 - ��������� ����� ������ ��� vec2 � ����������� vec � vec2;
			print_vector(vec, "\nvec in SetVec after copy: ");
			print_vector(_vec, "\n_vec in SetVec after copy: ");
		}
	};

	//const std::vector<IntWithCopyNotyfier>& vec
	//Test3: 3 �����������, �.�. move ����������� � �����������
	//Test4: 6 �����������, �.�. move ����������� � �����������
	//Test5: 3 �����������, �.�. move ����������� � �����������	
	
	//std::vector<IntWithCopyNotyfier>& vec
	//Test3: 0 �����������, move ������������ ���������
	//Test4: �� ��������, �.�. �� ����� �������� �������� vec ��-�� ���������, �� ��� vec ���������� rvalue, ������� ������ �� ������ ������
	//Test5: 0 �����������, �� �������, �.�. �� ������ ����� move �������� �������� vec

	//std::vector<IntWithCopyNotyfier> vec
	//Test3: 3 �����������, ������ ��� �������� ������ �� �����
	//Test4: 3 ����������� �� ������ std::vector<IntWithCopyNotyfier>{1,2,3}, move ���������� ���������
	//Test5: 3 ����������� � �� ��������, �.�. ��������� �� �����

	void Test3()
	{
		std::vector<IntWithCopyNotyfier> vec;
		vec.reserve(3);
		vec.emplace_back(1);
		vec.emplace_back(2);
		vec.emplace_back(3);
		Test2 t2;
		t2.SetVec1(std::move(vec));
		print_vector(vec, "\nvec in main after SetVec: ");
	}

	//void TestString(std::string str)
	//{
	//
	//}

	void Test4()
	{
		//TestString("Hello");
		Test2 t2;
		t2.SetVec1(std::vector<IntWithCopyNotyfier>{1,2,3});
	}

	void Test5()
	{
		std::vector<IntWithCopyNotyfier> vec;
		vec.reserve(3);
		vec.emplace_back(1);
		vec.emplace_back(2);
		vec.emplace_back(3);
		Test2 t2;
		t2.SetVec(vec);
		print_vector(vec, "\nvec in main after SetVec: ");
		assert(vec.size() == 3);
	}

	void Test10(int&& x)
	{
		std::cout << x << std::endl;
	}

	void Test11()
	{
		int a;
		//Test10(a);
		Test10(5);
	}

	
	

















}