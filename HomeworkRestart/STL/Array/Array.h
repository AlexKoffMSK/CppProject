#pragma once
#include <iostream>
#include <array>

namespace STLArray
{
	void at()
	{
		static const int n=10;
		std::array<double, n> ar;

		int arr[n];

		for (int i = 0; i < n; i++)
		{
			std::cout << ar[i] << ' ' << ' ' << ar.operator[](i) << ' ' << arr[i] << ' ' << *(arr+i) << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < n; i++)
		{
			std::cout << ar.at(i) << ' ';
		}

	}

	void front_back()
	{
		static const int n = 10;
		std::array<double, n> ar = {0,1,2,3,4,5,6,7,8,9};

		std::cout << ar.front() << ' ' << ar.back() << ' ';
		std::cout << std::endl;
	}

	void data()
	{
		static const int n = 10;
		std::array<double, n> ar = { 0,1,2,3,4,5,6,7,8,9 };
		
		std::cout << ar.data() << std::endl;
		*(ar.data() + 3) = 888;
		std::cout << *(ar.data()+3) << std::endl;
		std::cout << &ar[0] << std::endl;
	}

	void iterators()
	{
		static const int n = 10;
		std::array<double, n> ar = { 0,1,2,3,4,5,6,7,8,9 };

		std::cout << *ar.begin() << std::endl;
		std::cout << *(ar.end()-1) << std::endl;

		for (double& elem : ar)
		{
			std::cout << ar.data() << ' ' << elem << ' ' << &elem << std::endl;
		}

		std::array<double, n>::iterator ir = ar.begin();
		
		for (int i = 0; i < n; i++)
		{
			std::cout << *ir << ' ' << &ir << std::endl;
			ir++;
		}
	}
	
	void empty_size()
	{
		static const int n = 10;
		std::array<double, n> arr;

		std::cout << arr.empty() << ' ' << arr.size() << std::endl;
	}
	
	void fill()
	{
		static const int n = 10;
		std::array<double, n> arr;
		arr.fill(4);

		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << std::endl;
		}
		std::cout << arr.max_size() << std::endl;
	}

	
	void Run()
	{
		//at();
		front_back();
		//data();
		//iterators();
		//empty_size();
		//fill();
	}
	
	/*
	at
	[]
	front,back
	data
	iterators
	empty,size
	fill
	*/





}