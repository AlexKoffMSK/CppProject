#pragma once
#include <iostream>
#include <queue>

namespace RingBufferTest
{
	class RingBufferContainer
	{
	private:

		static const int kBufferMaxSize = 3000;
		int _arr[kBufferMaxSize] = {};
		int _head = 0;
		int _after_tail = 0;

	public:

		void push(int a)
		{
			//std::cout << "Try push: " << a << std::endl;

			if (size() >= kBufferMaxSize - 1)
			{
				std::cout << "Queue is full!" << std::endl;
				return;
			}
			_arr[_after_tail % std::size(_arr)] = a;
			_after_tail++;
		}
		
		void pop()
		{
			_arr[_head % std::size(_arr)] = -1;
			_head++;
		}
		
		int front()
		{
			return _arr[_head % std::size(_arr)];
		}
		
		int size()
		{
			return _after_tail - _head;
		}
		
		bool IsEmpty()
		{
			return size() == 0;
		}

		void PrintDebug()
		{
			std::cout << "Head: " << std::setw(3) << _head << ' ' << "AfterTail: " << std::setw(3) << _after_tail << ' ' << "Arr: ";
			for (int a : _arr)
			{
				std::cout << a << ' ';
			}
			std::cout << std::endl;
		}
	};





















}