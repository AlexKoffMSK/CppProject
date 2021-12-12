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
		std::shared_ptr<int> a(new int);

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
		std::shared_ptr<int> a(new int);

		std::shared_ptr<int> b;

		//b = std::move(a);
		b = a;
	}

	void Test4()
	{
		std::shared_ptr<int> a(new int);
		if (true)
		{
			std::shared_ptr<int> b;

			//b = std::move(a);
			b = a;
			//a (выделенна€ пам€ть)
			//b (выделенна€ пам€ть от a)
		} 
		//a (выделенна€ пам€ть)
		//здесь b больше нету
	} // здесь будет удал€тьс€ выделенна€ пам€ть, т.к. здесь умирает последний владелец (а)

	void Test5()
	{
		std::unique_ptr<int> a(new int);
		if (true)
		{
			std::unique_ptr<int> b;

			b = std::move(a);
			//a nullptr
			//b (выделенна€ пам€ть от a)
		} // здесь будет удал€тьс€ выделенна€ пам€ть, т.к. здесь умирает единственный владелец (b)
		//a nullptr
		//здесь b больше нету
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
			:_arr(new int[kN])
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

	template<typename T>
	class SharedPointer
	{
		T* _data = nullptr;
		int* _counter_owners_ptr = nullptr;

	public:

		SharedPointer(T* data_)
		{
			_data = data_;
			_counter_owners_ptr = new int;
			*_counter_owners_ptr = 1;
			std::cout << "Constr with param " << _data << " , counter of owners " << *_counter_owners_ptr << std::endl;
		}

		~SharedPointer()
		{
			if (_data == nullptr)
			{
				std::cout << "Destr empty data" << std::endl;
				return;
			}
			
			std::cout << "Destr " << _data << " , counter of owners " << *_counter_owners_ptr << std::endl;
			(*_counter_owners_ptr)--;
			
			if (*_counter_owners_ptr == 0)
			{
				std::cout << "Delete data " << _data << std::endl;
				delete _data;
			}
		}

		void operator=(const SharedPointer& other)
		{
			if (other._counter_owners_ptr != nullptr)
			{
				std::cout << "Copy " << _data << " , counter of owners " << *_counter_owners_ptr << "Other " << other._data << "other counter of owners " << *other._counter_owners_ptr << std::endl;
			}
			
			(*_counter_owners_ptr)--;
			if (*_counter_owners_ptr == 0)
			{
				std::cout << "Delete data " << _data << std::endl;
				delete _data;
				delete _counter_owners_ptr;
			}

			_data = other._data;
			
			if (other._counter_owners_ptr != nullptr)
			{
				(*other._counter_owners_ptr)++;
			}
			_counter_owners_ptr = other._counter_owners_ptr;
		}

		void operator=(SharedPointer&& other)
		{
			std::cout << "Move " << _data << " , counter of owners " << *_counter_owners_ptr << "Other " << other._data << "other counter of owners " << *other._counter_owners_ptr << std::endl;
			(*_counter_owners_ptr)--;
			if (*_counter_owners_ptr == 0)
			{
				std::cout << "Delete data " << _data << std::endl;
				delete _data;
				delete _counter_owners_ptr;
			}

			_data = other._data;
			_counter_owners_ptr = other._counter_owners_ptr;
			other._data = nullptr;
			other._counter_owners_ptr = nullptr;
		}

		T* GetRawPointer()
		{
			return _data;
		}

		bool IsEmpty()
		{
			return _data == nullptr;
		}

	};

	void TestSharedPointer()
	{
		if (true)
		{
			SharedPointer up(new int);
		}

		SharedPointer up1(new int);
		
		if (true)
		{
			SharedPointer up2(new int);
			SharedPointer up3(new int);
			up3 = std::move(up1);
			
			assert(!up2.IsEmpty());
			assert(up1.IsEmpty());

			up2 = up1;
			//up2 = std::move(up1);
			
			assert(up1.GetRawPointer() == up2.GetRawPointer());
			
			assert(up1.IsEmpty());
			assert(up2.IsEmpty());
		}
		std::cout << "1" << std::endl;
	}






























}