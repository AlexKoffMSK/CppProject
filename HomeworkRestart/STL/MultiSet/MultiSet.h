#pragma once
#include <iostream>
#include <set>

namespace STLMultiSet
{
	void Test()
	{
		std::multiset<int> ms;

		ms.emplace(5);
		ms.emplace(5);
		ms.emplace(6);
		ms.emplace(10);
		ms.emplace(8);
		ms.emplace(4);
		ms.emplace(3);
		ms.emplace(2);

		assert(ms.find(99) == ms.end());
		assert(ms.find(5) != ms.end());

		std::vector<int> vec;

		int i = 0;

		for (auto key : ms)
		{
			i++;
			if (i > ms.size() / 4 && i <= ms.size() / 4 * 3)
			{
				vec.push_back(key);
			}
		}

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}

		assert(ms.count(5) == 2);
		assert(ms.count(10) == 1);
		assert(ms.count(0) == 0);


		assert(*ms.lower_bound(6) == 6);
		assert(*ms.lower_bound(7) == 8);
		assert(*ms.upper_bound(6) == 8);
		assert(*ms.upper_bound(7) == 8);
		assert(ms.upper_bound(10) == ms.end());

	}

	void Run()
	{
		Test();
	}
}

/*
emplace
insert
size
count
find
equal_range
erase
lower_bound - возвращает итератор на элемент, ключ которого больше или равен искомого
upper_bound - возвращает итератор на элемент, ключ которого строго больше искомого
extract merge
*/