#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <map>

namespace STLMultiMap
{
	void emplace()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 30);
		mmap.emplace(1, 40);
		mmap.emplace(2, 50);
		assert(mmap.size() == 5);

		for (auto [key,value] : mmap)
		{
			std::cout << key << ' ' << value << std::endl;
		}
	}

	void count()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 30);
		mmap.emplace(1, 40);
		mmap.emplace(2, 50);

		assert(mmap.count(1) == 2);
		assert(mmap.count(2) == 2);
		assert(mmap.count(3) == 1);
		assert(mmap.count(4) == 0);
	}

	void find()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 30);
		mmap.emplace(1, 40);
		mmap.emplace(2, 50);

		assert(mmap.find(4) == mmap.end());
		assert(mmap.find(1)->first == 1);
		assert(mmap.find(1)->second == 10 || mmap.find(1)->second == 40);
	}

	void equal_range()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 30);
		mmap.emplace(1, 40);
		mmap.emplace(1, 70);
		mmap.emplace(2, 50);

		auto data = mmap.equal_range(1);

		for (std::multimap<int, int>::iterator it = data.first; it != data.second; it++)
		{
			std::cout << it->first << ' ' << it->second << std::endl;
		}

		//std::multimap<int,int>::iterator

	}

	void erase()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 30);
		mmap.emplace(1, 40);
		mmap.emplace(1, 70);
		mmap.emplace(2, 50);
		mmap.emplace(2, 67);
		mmap.emplace(2, 34);

		assert(mmap.erase(1) == 3);

		auto data = mmap.equal_range(2);

		for (std::multimap<int, int>::iterator it = data.first; it != data.second; it++)
		{
			if (it->second == 67)
			{
				mmap.erase(it);
			}
		}

		
	}

	void lower_upper_bound()
	{
		std::multimap<int, int> mmap;
		mmap.emplace(1, 10);
		mmap.emplace(2, 20);
		mmap.emplace(3, 45);
		mmap.emplace(4, 34);
		mmap.emplace(5, 21);
		mmap.emplace(1, 40);
		mmap.emplace(1, 70);
		mmap.emplace(2, 50);
		mmap.emplace(2, 67);
		mmap.emplace(2, 34);

		assert(mmap.lower_bound(4)->second == 34);
		assert(mmap.upper_bound(4)->second == 21);
	}

	void Extract()
	{
		std::multimap<int, int> mmap1;
		std::multimap<int, int> mmap2;

		mmap1.emplace(1, 10);
		mmap1.emplace(2, 20);
		mmap1.emplace(3, 45);
		mmap2.emplace(4, 34);
		mmap2.emplace(5, 21);
		mmap2.emplace(8, 40);

		//mmap1.emplace(4,mmap1.find(4)->second);
		//mmap2.erase(4);

		auto node = mmap1.extract(4);
		mmap2.insert(std::move(node));

		assert(mmap2.find(4) != mmap2.end());
		assert(mmap2.find(4)->second == 34);
		assert(mmap1.find(4) == mmap1.end());

	}

	void Merge()
	{
		std::multimap<int, int> mmap1;
		std::multimap<int, int> mmap2;
		std::multimap<int, int> mmap3;

		mmap1.emplace(1, 10);
		mmap1.emplace(2, 20);
		mmap1.emplace(3, 45);
		mmap2.emplace(4, 34);
		mmap2.emplace(5, 21);
		mmap2.emplace(8, 40);

		mmap3.merge(mmap1);
		mmap3.merge(mmap2);

		assert(mmap1.empty());
		assert(mmap2.empty());
		assert(mmap3.size() == 6);

	}

	void Run()
	{
		Merge();
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
lower_bound, upper_bound
extract merge
*/