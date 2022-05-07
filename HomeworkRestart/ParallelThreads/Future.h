#pragma once
#include <iostream>
#include <thread>
#include <future>

namespace ParallelThreads
{
	int Test()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "!!!" << std::endl;
		return rand() % 100;
	}

	void Go()
	{
		//std::thread thr(Test);
		std::future fut = std::async(Test);

		std::cout << "!" << std::endl;
		fut.wait();
		int result = fut.get();
		std::cout << result << std::endl;
	}





















}