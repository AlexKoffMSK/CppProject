#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include "RingBuffer.h"

namespace RingBufferTest
{
	//std::queue<int> q;
	RingBufferContainer q;
	
	bool is_need_work_func2 = true;

	void Func1()
	{
		int summ1 = 0;

		for (int i = 0; i < 1000; i++)
		{
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
			//int a = rand() % 10;
			int a = i;
			summ1 += a;
			q.push(a);
			//std::cout << "Func1: " << a << " q.size(): " << q.size() << std::endl;
		}
		std::cout << "Summ1 : " << summ1 << std::endl;
		is_need_work_func2 = false;
	}

	void Func2()
	{
		int summ2 = 0;

		while (is_need_work_func2)
		{
			if (q.size() != 0)
			{
				summ2 += q.front();

				//std::cout << "Func2: " << q.front() << " q.size(): " << q.size() << std::endl;
				q.pop();
			}
		}
		
		while (q.size() != 0) //добиваем в сумм2 то, что осталось во 2й очереди
		{
			//std::cout << q.front() << std::endl;
			summ2 += q.front();
			q.pop();
		}
		
		std::cout << "Summ2: " << summ2 << std::endl;
	}

	void Test_Queue()
	{
		std::thread thread1(Func1);
		std::thread thread2(Func2);
		thread1.join();
		thread2.join();
	}

	void Test_RingBufferContainer()
	{
		RingBufferContainer a;								 a.PrintDebug();
		a.push(1);											 a.PrintDebug();
		a.push(2);											 a.PrintDebug();
		a.push(3);											 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		a.push(4);											 a.PrintDebug();
		a.push(5);											 a.PrintDebug();
		a.push(6);											 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		a.push(7);											 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		std::cout << a.front() << std::endl; a.pop();		 a.PrintDebug();
		a.push(8);											 a.PrintDebug();
		a.push(9);											 a.PrintDebug();
		std::cout << "Size: " << a.size() << std::endl;
	}
	void Test1_RingBufferContainer()
	{
		RingBufferContainer a;								 a.PrintDebug();
		for (int i = 0; i < 1000; i++)
		{
			int r = rand() % 100;
			if (r < 50)
			{
				a.push(rand() % 90 + 10);
				a.PrintDebug();
			}
			else
			{
				if (a.size() != 0)
				{
					std::cout << "Front: " << a.front() << " and POP" << std::endl;
					a.pop();
					a.PrintDebug();
				}
				else
				{
					std::cout << "Try POP but ring is empty!" << std::endl;
				}
			}
		}
	}
}
