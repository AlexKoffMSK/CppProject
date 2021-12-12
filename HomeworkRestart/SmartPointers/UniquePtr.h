#pragma once
#include <iostream>
#include <memory>

namespace SmartPointers
{
	void Test1()
	{
		//int* a = new int[1];
		int* a = new int;

		int b = rand() % 10;
		if (b > 5)
		{
			std::cout << '2' << std::endl;
			delete a;
			return;
		}
		
		int c = rand() % 10;
		if (c < 5)
		{
			std::cout << '3' << std::endl;
			delete a;
			return;
		}
		std::cout << '1' << std::endl;
		delete a;
	}

	void Test2()
	{
		std::unique_ptr<int> a(new int);

		int b = rand() % 10;
		if (b > 5)
		{
			std::cout << '2' << std::endl;
			return;
		}

		int c = rand() % 10;
		if (c < 5)
		{
			std::cout << '3' << std::endl;
			return;
		}
		std::cout << '1' << std::endl;
	}

	void Test3()
	{
		std::unique_ptr<int> a(new int);

		std::unique_ptr<int> b;

		b = std::move(a);
	}

	void Test4()
	{
		std::unique_ptr<int[]> a(new int[10]);
		//a = new int[10];
		std::unique_ptr<int[]> b;

		b = std::move(a);
	}

	const int kN = 10;

	class MoveSemanticsClass
	{
	public:
		std::unique_ptr<int[]> _arr;

		MoveSemanticsClass()
			:_arr(new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = i;
			}
		}

		~MoveSemanticsClass()
		{
		}

		MoveSemanticsClass(const MoveSemanticsClass& parametr)
			:_arr(new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
		}

		MoveSemanticsClass(MoveSemanticsClass&& parametr)
		{
			_arr = std::move(parametr._arr);
		}

		MoveSemanticsClass(int num)
			:_arr (new int[kN])
		{
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = num;
			}
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
			_arr.reset(new int[kN]);
			for (int i = 0; i < kN; ++i)
			{
				_arr[i] = parametr._arr[i];
			}
		}
		void operator=(MoveSemanticsClass&& parametr)
		{
			_arr = std::move(parametr._arr);
		}
	};
	
	/*=============================================================================*/

	template <typename T>
	class UniquePointer
	{
		T* _data = nullptr;

	public:

		UniquePointer() = default;

		UniquePointer(T* data_)
		{
			_data = data_;
			std::cout << "Constr with param " << _data << std::endl;
		}

		~UniquePointer()
		{
			std::cout << "Destr " << _data << std::endl;
			if (_data != nullptr)
			{
				delete _data;
			}
		}

		void operator=(const UniquePointer& other) = delete;

		void operator=(UniquePointer&& other)
		{
			std::cout << "Move  " << other._data << " To " << _data << std::endl;
			if (!IsEmpty())
			{
				std::cout << "Delete " << _data << std::endl;
				delete _data; //delete отдает операционной системе память, куда указывает указатель _data. Сам указатель _data продолжает на нее смотреть.
			}
			_data = other._data;
			other._data = nullptr;
		}
		
		bool IsEmpty()
		{
			return _data == nullptr;
		}
	};

	void TestUniquePointer()
	{
		if (true)
		{
			UniquePointer up(new int);
		}
		UniquePointer up1(new int);
		UniquePointer up2(new int);
		UniquePointer<double> up3;
		//up2 = up1;
		assert(!up2.IsEmpty());
		assert(!up1.IsEmpty());
		up2 = std::move(up1);
		assert(up1.IsEmpty());
		assert(!up2.IsEmpty());
	}






























}