#pragma once
#include <iostream>
#include <map>
#include <list>


namespace Iterators
{
	void Test1()
	{
		std::map<int, int> m;
		for (int i = 0; i < 100; ++i)
		{
			int a = rand() % 1000;
			m[a]++;
		}

		//std::map<int, int>::iterator iter = m.begin();

		//for (int i=0; i<m.size(); ++i)
		//{
		//	std::cout << << ": " << m[i] << std::endl;
		//}

		for (auto it = m.begin(); it!= m.end(); ++it)
		{
			std::cout << it->first << ": " << it->second << std::endl;
		}

		for (auto elem : m)
		{
			std::cout << elem.first << ": " << elem.second << std::endl;
		}

		//auto it = m.find(30);
		//if (it != m.end())
		//{
		//	std::cout << it->second << std::endl;
		//}
		//else


	}


















}