#pragma once
#include <iostream>
#include <thread>
#include <chrono>

namespace DynamicMemoryManager
{
	struct A
	{
		int _a;
		double _b;
	};

	class MemoryManager
	{
	private:
		//делаем через запрос диапазона памяти у операционной системы
		std::byte* _memory; //указатель на начало сырой памяти, которую мы запросим у ОС

	public:

		A* AllocAndGet() //выдает не копию, а указатель на оригинал
		{

		}

		void AllocateMemory(int memory_size)
		{
			_memory = new std::byte[memory_size];
		}

	};

	void Test1()
	{
		MemoryManager mem;
		
		A* p = mem.AllocAndGet();
		
		while (true)
		{
			if (rand() % 100 < 30)
			{
				p = mem.AllocAndGet();
				p->_a = rand() % 20;
				p->_b = rand() % 20+20;
			}
			else
			{
				std::cout << p->_a << " & " << p->_b << std::endl;
			}
		}
	}

	void GrabAndFreeRAM()
	{
		while (true)
		{
			std::byte* p_arr[1024UL * 3];

			for (int i = 0; i < 1024UL * 3; ++i)
			{
				std::this_thread::sleep_for(chrono::microseconds(1));
				std::byte* p = new std::byte[1024UL * 1024];
				p_arr[i] = p;
			}
			for (int i = 0; i < 1024UL * 3; ++i)
			{
				std::this_thread::sleep_for(chrono::microseconds(1));
				delete[] p_arr[i];
			}
		}
	}















}