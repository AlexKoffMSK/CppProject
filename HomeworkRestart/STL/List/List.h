#pragma once
#include <iostream>
#include <list>
#include <cassert>
#include <csignal>

namespace STLList
{
	void front_back()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };
		assert(ls.front() == 5);
		assert(ls.back() == 2);
	}

	struct Test
	{
		int _x = 0;
		int _y = 0;
		
		Test(int a_, int b_) :
		_x (a_),
		_y (b_)
		{
		};
	};

	struct Test1
	{
		const int _x = 0;

		Test1(int a_)
		{
			//_x = a_; //так нельз€
		};
	};

	struct Test2
	{
	private:
		const int _x = 0;
	
	public:
		Test2(int a_) :
			_x (a_)
		{
		};
	};

	struct Test3
	{
		int& _x;

		Test3(int& a_) :
			_x(a_)
		{
		};
	};

	void f()
	{
		int v;
		Test3 t3(v);

	}

	struct Test4 : public Test2 
	{
		int _b = 0;
		Test4(int tx_, int tb_) :
			Test2(tx_),
			_b(tb_)
		{
			
		}
	};

	void push_back_emplace_back()
	{
		std::list<Test> ls = {Test{7,8}}; //на лету сгенерирован объект и передан
		
		Test ts_1 ( 77,66 );				  //варианты создани€ объекта класса и его инициализации
		Test ts_2 = { 77,66 };				  //варианты создани€ объекта класса и его инициализации
		Test ts_3 { 77,66 };				  //варианты создани€ объекта класса и его инициализации
		
		ls.push_back(ts_1);
		ls.push_back(Test{ 66,88 });

		ls.emplace_back(88,55);

		assert(ls.back()._x == 88 && ls.back()._y == 55);
	}


	void pop_back_push_front_pop_front_emplace_front()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };

		ls.pop_back();
		ls.push_front(0);

		assert(ls.back() == 4);
		assert(ls.front() == 0);
	}

	void iterators()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };
		std::list<int>::iterator it;

		it = ls.begin();

		std::cout << *it << ' ' << &it << ' ' << &(*it) << std::endl;

		it++;
		std::advance(it, 2); //перейдет к 8. Advance сдвигает итератор на заданное количество €чеек, итератор теперь смотрит на 8
		*it = 10; //помен€л 8 на 10

		std::advance(it, -2); //перейдет к 6.

		std::cout << *it << ' ' << &it << ' ' << &(*it) << std::endl;
	}

	void insert_emplace_erase()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };
		std::list<int>::iterator it = ls.begin();
		std::advance(it, ls.size()/2);

		ls.insert(it, 88);

		std::cout << *it << std::endl;
		
		std::list<int>::iterator it_check=ls.begin();

		for (int i = 0; i < ls.size(); i++)
		{
			std::cout << *it_check << ' ';
			it_check++;
		}

		it_check = ls.begin();

		ls.emplace(it, 99);

		for (int i = 0; i < ls.size(); i++)
		{
			std::cout << *it_check << ' ';
			it_check++;
		}

		std::cout << *it << std::endl;

		ls.erase(it);

		std::cout << *it << std::endl;
	}

	void operator_equal()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };
		std::list<int> ls_1 = { 4,3,6,7,8,2 };
		
		std::list<int> ls_tmp;

		ls_tmp = ls;
		ls = ls_1;
		ls_1 = ls_tmp;
		
		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		ls.swap(ls_1);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	void assign_clear()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };
		std::list<int> ls_1 = { 4,3,6,7,8,2 };

		ls.assign(5,4);
		
		std::list<int>::iterator it = ls_1.begin();
		std::list<int>::iterator it1 = ls_1.begin();

		std::advance(it, 1);
		std::advance(it1, 4);

		ls.assign(it, it1);

		ls.assign({ 1,1,1 });

		ls = { 6,7 };

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		ls.clear();

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	void resize()
	{
		std::list<int> ls = { 5,6,7,8,9,3,4,2 };

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		ls.resize(10);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		ls.resize(12,5);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	void merge()
	{
		std::list<int> ls = { 1,2,3,4,5,6,7,8 };

		std::list<int> ls_1 = { 6,7,8,9,9,9,9 };

		ls.merge({ 6,7,8,8,8 });

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		ls.merge(ls_1);

		ls = { 5,4,2 };
		
		ls.merge({ 9,8,7,6,5,4 }, [](int a, int b) {return a > b; });

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	void SetToBoth(std::list<int>& l1, std::list<int>& l2, std::list<int>&& l3)
	{
		std::list<int>::iterator it = l3.begin();
		std::advance(it, l3.size() / 2);

		l1.splice(l1.end(), l3, l3.begin(), it);

		l2.splice(l2.end(), l3, it, l3.end());

		for (int e : l1)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		for (int e : l2)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

		for (int e : l3)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}


	void splice()
	{
		std::list<int> ls = { 1,2,3,4,5,6,7,8 };
		std::list<int>::iterator it = ls.begin();
		std::advance(it, 3);
		std::list<int> ls_1 = { 6,7,8,9,9,9,9 };
		std::list<int> ls_2 = { 77,88,99,44,33,55,677 };
		std::list<int>::iterator it1 = ls_1.begin();
		std::advance(it1, 3);
		
		//ls.splice()
		

		//ls.splice(it, ls_1);
		//ls.splice(it, ls_1, it1);
		//ls.splice(it, ls_1, it1,ls_1.end());

		//std::list<int>&& ls_2 = { 1,2,3,4,5,6,7,8 };

		SetToBoth(ls, ls_1, {555,666,777,888,999});

	}

	void remove()
	{
		std::list<int> ls = { 1,1,2,3,1,4,5,1,6,7,8 };

		ls.remove(1);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;

	}

	bool IsEven(int x)
	{
		return (x % 2 == 0);
	}

	void remove_if()
	{
		std::list<int> ls = { 1,1,2,3,1,4,5,1,6,7,8 };
		
		//ls.remove_if(IsEven);

		ls.remove_if([](int x) {return x % 2 == 0; });

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	bool IsEBothArgsAreEven(int x, int y)
	{
		return ((x % 2 == 0) && (y % 2 == 0));
	}

	void unique()
	{
		std::list<int> ls = { 1,1,2,3,3,1,4,5,5,1,6,10,12,14,7,8,6,4,2 };

		//ls.unique();
		ls.unique(IsEBothArgsAreEven);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	bool CompareTwoIntsByLexigraphic(int a, int b)
	{
		
		return std::to_string(a) < std::to_string(b);
	}

	void sort()
	{
		std::list<int> ls = { 1,1,2,3,3,1,4,5,5,1,6,10,12,14,7,8,6,4,2,25,100 };
		//ls.sort();

		ls.sort(CompareTwoIntsByLexigraphic);

		for (int e : ls)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	/*void f(int x)
	{

	}

	void f1(int& x)
	{
		x = 6;
	}

	void f2(const int& x)
	{
		
	}

	void f3(int* x)
	{
		*x = 6;
	}

	void f4(const int* x)
	{
		int v;
		x = &v;
	}

	void f5(int* const x)
	{
		*x = 6;
	}

	void f6(const int* const x)
	{

	}*/

	void Run()
	{
		//int c = 4;
		//int& b = c;
		//int a = 888;
		//b = a;
		//
		//int* b_pc = &c;
		//*b_pc = a;
		//
		//f(5);
		//f(c);
		//
		//f1(a);
		////f1(5);
		//
		//f2(a);
		//f2(5);
		//
		//f3(&a);
		//f3(5);

		sort();
	}
}