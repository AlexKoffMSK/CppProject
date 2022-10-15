#pragma once
#include <iostream>
#include <deque>
#include <cassert>

namespace STLDeque
{
	void operator_squares()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		assert(dq[0] == 4);
		assert(dq[1] == 3);
		assert(dq[2] == 6);
		dq[3] = 5;
		assert(dq[3] == 5);
	}

	void push_emplace_back()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		dq.emplace_back(8);
		dq.push_back(11);

		assert(dq[dq.size() - 2] == 8);
		assert(dq[dq.size()-1] == 11);

	}

	void push_emplace_front()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		dq.emplace_front(8);
		dq.push_front(11);

		assert(dq[1] == 8);
		assert(dq[0] == 11);
	}

	struct Test
	{
		int _a;
		double _b;
		
		Test() = delete; //запрещаем конструктор по умолчанию
		Test(int x, double y) :
			_a (x),
			_b (y)
		{
		}
	};

	void emplace_with_class()
	{
		std::deque<Test> dqt;
		dqt.emplace_back(4,5.5);
	}

	void push_with_class()
	{
		std::deque<Test> dqt;
		dqt.push_back(Test{ 4,5.6 });
	}

	void at()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		try
		{
			std::cout << dq.at(15);
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	void front_back()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		assert(dq.front() == 4);
		assert(dq.back() == 9);
		dq.front() = 1;
		dq.back() = 99;
		assert(dq.front() == 1);
		assert(dq.back() == 99);
	}

	void pop_front_back()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		dq.pop_front();
		dq.pop_back();
		assert(dq.front() == 3);
		assert(dq.back() == 3);
		assert(dq.size() == 5);
	}

	void operator_equal()
	{
		std::deque<int> dq1 = { 4,3,6,7,2,3,9 };
		std::deque<int> dq2 = { 5,4,6,7,8,3,2,5,7,8,9 };

		dq1 = dq2;
		assert(dq1.size() == dq2.size());
	}

	void assign()
	{
		std::deque<int> dq1 = { 4,3,6,7,2,3,9 };
		std::deque<int> dq2 = { 5,4,6,7,8,3,2,5,7,8,9 };

		dq1.assign(10, 7);

		assert(dq1.size() == 10);
		for (auto e : dq1)
		{
			assert(e == 7);
		}
	}

	void iterators()
	{
		std::deque<int> dq1 = { 4,3,6,7,2,3,9 };

		std::deque<int>::iterator it1;
		it1 = dq1.begin();

		std::deque<int>::iterator it2;
		it2 = dq1.end();

		assert(*it1 == 4);
		assert(*(it2 - 1) == 9);

		assert(*(it1 + dq1.size() - 1) == 9);

		std::deque<int>::reverse_iterator rit1;
		rit1 = dq1.rbegin();

		assert(*rit1 == 9);
		it1 += 5;
		assert(*it1 == 3);
	}

	void insert_emplace_erase()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		std::deque<int>::iterator it1 = dq.begin()+3;
		dq.emplace(it1, 66);
		assert(dq[3] == 66);
		assert(dq[4] == 7);
		assert(dq[2] == 6);

		dq = { 4,3,6,7,2,3,9 };
		it1 = dq.begin() + 3;
		dq.insert(it1, 66);
		assert(dq[3] == 66);
		assert(dq[4] == 7);
		assert(dq[2] == 6);

		dq = { 4,3,6,7,2,3,9 };
		it1 = dq.begin() + 3;
		dq.erase(it1);
		assert(dq.size() == 6);
		assert(dq[3] == 2);
	}

	void resize()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		dq.resize(10, 99);
		assert(dq[7] == 99);
		assert(dq[8] == 99);
		assert(dq[9] == 99);
		assert(dq.size() == 10);
	}

	void erase_if()
	{
		std::deque<int> dq = { 4,3,6,7,2,3,9 };
		int i = 0;
		//std::erase_if(dq, [](int x) { return x == 3; });
		//std::erase_if(dq, [](int x) { return x - 3 == 4; });
		std::erase_if(dq, [](int x) { return ((x - 3)*x-15)*2 + 9 + x == x*x*2-6*x-27+9; });
		assert(dq[0] == 4);
		assert(dq[1] == 6);
		assert(dq[2] == 7);
		assert(dq[3] == 2);
		assert(dq[4] == 9);
	}

	void TestTest()
	{
		std::deque<uint8_t> dq(60);
		std::iota(dq.begin(), dq.end(), 0);
		for (int i = 0; i < dq.size(); i++)
		{
			std::cout << (int)dq[i] << ' ' <<  (void*)(&dq[i]) << std::endl;
		}
	}


	/*
	push_back, emplace_back
	push_front,	emplace_front
	[]
	at
	front, back
	pop_front, pop_back

	operator =
	assign
	iterators
	insert, emplace, erase
	resize
	erase_if
	shrink_to_fit
	*/








}