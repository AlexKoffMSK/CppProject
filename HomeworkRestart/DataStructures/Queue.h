#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Functions.h"

namespace DataStructures
{
	class Queue
	{

		std::vector<int> std_vector;

	public:

		void PushToBack(int elem)
		{
			std_vector.push_back(elem);
		}

		void PopFrontElem()
		{
			std_vector.erase(std_vector.begin() + 0);
		}

		int GetFrontElem()
		{
			return std_vector[0];
		}

		void Print()
		{
			print_vector(std_vector);
		}
	};	
	
	void QueueTesting()
	{
		Queue q;
		q.PushToBack(1);
		q.PushToBack(2);
		q.PushToBack(3);
		q.Print();
		std::cout << q.GetFrontElem() << std::endl;
		q.PopFrontElem();
		q.Print();
		std::cout << q.GetFrontElem() << std::endl;
		q.PushToBack(4);
		q.PushToBack(5);
		q.Print();
		std::cout << q.GetFrontElem() << std::endl;
	}

	void QueueTesting1()
	{
		Queue q;
		for (int i = 1; i <= 10; i++)
		{
			q.PushToBack(i);
		}
		q.Print();
		for (int i = 11; i <= 20; i++)
		{
			q.PopFrontElem();
			q.PushToBack(i);
			q.Print();
		}
	}

	void QueueTesting2()
	{
		Queue q;
		
		q.PushToBack(1);

		for (int i = 2; i <= 9; i+=2)
		{
			q.Print();
			q.PushToBack(i);
			q.PushToBack(i + 1);
			q.PopFrontElem();
			q.Print();
			std::cout << std::endl;
		}
	}

	void QueueTesting3()
	{
		Queue q;
		q.PushToBack(1);
		q.PushToBack(2);
		q.PushToBack(3);
		cout << q.GetFrontElem() << endl; //1
		q.PushToBack(4);
		cout << q.GetFrontElem() << endl; //1
		q.PopFrontElem();
		q.PopFrontElem();
		cout << q.GetFrontElem() << endl; //3
	}

	void QueueTesting4()
	{
		Queue q;
		for (int i = 0; i < 10; i++)
		{
			q.PushToBack(i);
		}
		for (int i = 10; i < 30; i++)
		{
			q.PushToBack(i);
			q.PopFrontElem();
			q.Print();
		}
		
	}
}

