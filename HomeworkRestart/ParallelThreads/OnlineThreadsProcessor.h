#pragma once
#include <iostream>
#include <future>
#include <thread>
#include <queue>

namespace ParallelThreads
{
	std::vector<int> data_from_1;
	std::vector<int> data_from_2;
	
	void Generator1()
	{
		srand(time(0));
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 2 + 1));
			int x = rand() % 3;
			std::cout << "Gen1: " << x << std::endl;
			data_from_1.push_back(x);
		}
	}

	void Generator2()
	{
		srand(time(0)+3);
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 2 + 1));
			int x = rand() % 3;
			std::cout << "Gen2: " << x << std::endl;
			data_from_2.push_back(x);
		}
	}

	void Processor()
	{
		int ind1=0;
		int ind2=0;

		std::queue<int> q1;
		std::queue<int> q2;


		while (true)
		{
			if (ind1 < data_from_1.size())
			{
				q1.push(data_from_1[ind1]);
				std::cout << "Processor for 1:" << data_from_1[ind1] << std::endl;
				ind1++;
			}
			if (ind2 < data_from_2.size())
			{
				q2.push(data_from_2[ind2]);
				std::cout << "Processor for 2:" << data_from_2[ind2] << std::endl;
				ind2++;
			}
			if (!q1.empty() && !q2.empty())
			{
				if (q1.front() == q2.front())
				{
					std::cout << "Equal" << std::endl;
				}
				else
				{
					std::cout << "Not Equal" << std::endl;
				}
				q1.pop();
				q2.pop();
			}
		}
	}

	void Go1()
	{
		std::thread thr1(Generator1);
		std::thread thr2(Generator2);
		std::thread thr3(Processor);

		thr1.join();
		thr2.join();
		thr3.join();
	}



















}