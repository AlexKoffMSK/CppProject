#pragma once
#include <iostream>

namespace MoveSemantics
{
	const int kN = 10;
	
	int objects_count = 0;

	class MoveSemanticsClass
	{
	public:
		int* _arr;

		MoveSemanticsClass()
		{
			std::cout << "Use constr default SLOW SLOW. This = " << this << std::endl;
			_arr = new int[kN];
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = i;
			}
			objects_count++;
		}

		~MoveSemanticsClass()
		{
			objects_count--;
			if (_arr != nullptr)
			{
				std::cout << "Use destr SLOW. This = " << this << std::endl;
				delete[] _arr; 
			}
			else
			{
				std::cout << "Use destr. This = " << this << std::endl;
			}
		}

		MoveSemanticsClass(const MoveSemanticsClass& parametr)
		{
			std::cout << "Use constr Copy SLOW SLOW. Parametr = " << &parametr << " This = " << this << std::endl;
			_arr = new int[kN];
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
			objects_count++;
		}

		MoveSemanticsClass(MoveSemanticsClass&& parametr)
		{
			std::cout << "Use constr MOVE fast. Parametr = " << &parametr << " This = " << this << std::endl;
			_arr = parametr._arr; 
			//в отличие от конструктора копировани€, здесь мы можем скопировать указатель, потому что мы знаем, что parametr - это rvalue-объект, который умрет. 
			//Ќет смысла копировать объект, который сейчас умрет, можно просто его данные забрать себе.
			parametr._arr = nullptr;
		}

		MoveSemanticsClass(int num)
		{
			std::cout << "Use constr with INT SLOW SLOW. Num = " << num << " This = " << this << std::endl;
			_arr = new int[kN];
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = num;
			}
			objects_count++;
		}

		void Print()
		{
			for (int i = 0; i < kN; ++i)
			{
				std::cout << _arr[i] << ' ';
			}
			std::cout << std::endl;
		}

		void operator=(const MoveSemanticsClass& parametr)
		{
			if (_arr != nullptr)
			{
				std::cout << "Use assigment operator SLOW SLOW SLOW. Parametr = " << &parametr << " This = " << this << std::endl;
				delete[] _arr;
			}
			else
			{
				std::cout << "Use assigment operator SLOW SLOW. Parametr = " << &parametr << " This = " << this << std::endl;

			}
			_arr = new int[kN];
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
		}
		void operator=(MoveSemanticsClass&& parametr)
		{
			if (_arr != nullptr)
			{
				std::cout << "Use MOVE assigment operator SLOW. Parametr = " << &parametr << " This = " << this << std::endl;
				delete[] _arr;
			}
			else
			{
				std::cout << "Use MOVE assigment operator. Parametr = " << &parametr << " This = " << this << std::endl;

			}
			_arr = parametr._arr;
			parametr._arr = nullptr;
		}
	};

	MoveSemanticsClass global_m;

	void Test99(MoveSemanticsClass&& m)
	{
		std::cout << "Enter to func Test99" << ". m =" << &m << std::endl;
		global_m = std::move(m);
		//m.Print();
		std::cout << "End func Test99" << std::endl;
	}

	void Test99(const MoveSemanticsClass& m)
	{
		std::cout << "Enter to func Test99" << ". m =" << &m << std::endl;
		global_m = m;
		//m.Print();
		std::cout << "End func Test99" << std::endl;
	}

	void Test100()
	{
		//MoveSemanticsClass m1;
		//MoveSemanticsClass m2 = m1;
		//m1._arr[3] = 5;
		//m2._arr[3] = 5;
		//m1._arr[3] = 6;
		//std::cout << m1._arr[3] << ' ' << m2._arr[3] << std::endl;
		//MoveSemanticsClass m3(7);
		//m3.Print();
		std::cout << '1' << std::endl;
		MoveSemanticsClass m4(8);
		std::cout << '2' << ". m4 =" << &m4 << std::endl;
		//Test99(m4);
		Test99(std::move(m4));
		std::cout << '3' << std::endl;
		Test99(MoveSemanticsClass(9));
		std::cout << '4' << std::endl;

	}

	MoveSemanticsClass Test98()
	{
		MoveSemanticsClass m;
		m._arr[3] = 0;
		m._arr[8] = 0;
		return m;
	}

	void Test101()
	{
		MoveSemanticsClass m1 = Test98();

	}

	void Test102()
	{
		MoveSemanticsClass m1; 
		m1._arr[3] = 0;
		m1 = Test98();
		//по умолчанию конструктор m1
		//по умолчанию конструктор m
		//оператор присваивани€ m1 = m
		//деструктор m
		//деструктор m1
	}




















}