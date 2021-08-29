#pragma once
#include <iostream>
#include <chrono>

namespace ChronoTime
{
	std::ostream& operator<<(std::ostream& os, std::chrono::seconds sec)
	{
		os << sec.count() << "_s";
		return os;
	}
	std::ostream& operator<<(std::ostream& os, std::chrono::nanoseconds nanosec)
	{
		os << nanosec.count() << "_ns";
		return os;
	}
	
	void Test1()
	{
		std::cout << std::chrono::high_resolution_clock::now().time_since_epoch() << std::endl;
		std::cout << std::chrono::system_clock::now().time_since_epoch() << std::endl;
	}

	void Test2()
	{
		auto time1 = chrono::high_resolution_clock::now().time_since_epoch();
		auto time_delta = chrono::seconds(2);
		auto time2 = time1 + time_delta;

		while (chrono::high_resolution_clock::now().time_since_epoch() < time2)
		{
			
		}
		std::cout << "now" << std::endl;
	}


























}