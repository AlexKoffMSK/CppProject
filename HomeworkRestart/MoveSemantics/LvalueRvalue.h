#pragma once
#include <iostream>

namespace MoveSemantics
{
	//Lvalue - left value, Rvalue - right value
	
	void Test1()
	{
		int a = 4;
		a = 5; 
		//a - это lvalue, lvalue - потому что у него есть имя и в эту переменную можно что-то записать
		//5 это rvalue, у него нет имени, в нее нельзя засунуть другое значение, антипод lvalue

		int b = 3;
		a = b; //и а и b - lvalue, т.к. в них можно что-то записать
		std::string str = "Hello"; //str - это lvalue, Hello - это rvalue
		//3 = a; //не сбилдится, т.к. в rvalue нельзя присваивать новые значения

		3 + 4; //это выражение, оно rvalue
		int c = 3 + 4; //с - lvalue

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
			// копирование всего вектора vec в вектор vec2 - выделение новой памяти под vec2 и копирование vec в vec2;
			print_vector(vec, "\nvec in SetVec after copy: ");
			print_vector(_vec, "\n_vec in SetVec after copy: ");
		}

		void SetVec1(std::vector<IntWithCopyNotyfier>&& vec) //&& в данном контексте аргумента функции - это "ссылка на rvalue" (aka rvalue-ссылка), она может ссылаться ТОЛЬКО на rvalue-значение
		{
			print_vector(vec, "\nvec in SetVec: ");
			//_vec = vec;
			_vec = std::move(vec);
			// копирование всего вектора vec в вектор vec2 - выделение новой памяти под vec2 и копирование vec в vec2;
			print_vector(vec, "\nvec in SetVec after copy: ");
			print_vector(_vec, "\n_vec in SetVec after copy: ");
		}
	};

	//const std::vector<IntWithCopyNotyfier>& vec
	//Test3: 3 копирования, т.к. move превратился в копирование
	//Test4: 6 копирований, т.к. move превратился в копирование
	//Test5: 3 копирования, т.к. move превратился в копирование	
	
	//std::vector<IntWithCopyNotyfier>& vec
	//Test3: 0 копирования, move отрабатывает нормально
	//Test4: не билдится, т.к. мы можем изменить значение vec из-за указателя, но под vec скрывается rvalue, которое менять по ссылке нельзя
	//Test5: 0 копирований, но валится, т.к. по ссылке через move зануляем исходный vec

	//std::vector<IntWithCopyNotyfier> vec
	//Test3: 3 копирования, потому что передаем вектор по копии
	//Test4: 3 копирования на стадии std::vector<IntWithCopyNotyfier>{1,2,3}, move отработает нормально
	//Test5: 3 копирования и не свалится, т.к. принимаем по копии

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