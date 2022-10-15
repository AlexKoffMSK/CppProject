#include <iostream>
#include <vector>

namespace STLSet
{
	void emplace()
	{
		std::set<int> s;
		s.emplace(4);
		s.emplace(6);
		s.emplace(4);
		s.emplace(8);
		assert(s.size() == 3);
	}

	void insert()
	{
		std::set<int> s;
		s.insert(4);
		s.insert(6);
		s.insert(4);
		s.insert(8);
		assert(s.size() == 3);
	}

	struct Test
	{
		int _age=0;
		int _height =0;
		Test(int age_, int height_)
		{
			_age = age_;
			_height = height_;
		}
		//3,4 < 4,3
		//3,3 > 2,4
		//3,3 < 3,4
		friend bool operator<(Test a, Test b)
		{
			if (a._age == b._age)
			{
				return a._height < b._height;
			}
			return a._age < b._age;
		}
	};

	void insert_emplace_struct()
	{
		std::set<Test> st;

		st.insert(Test{ 4,5 });
		st.emplace(5, 6);
		st.emplace(4, 6);
		assert(st.size() == 3);
	}

	void contains()
	{
		std::set<int> s;
		s.emplace(5);
		s.emplace(4);
		s.emplace(7);
		s.emplace(3);
		s.emplace(9);

		assert(s.contains(5) == true);
		assert(s.contains(10) == false);
	}

	void Test1()
	{
		std::set<int> already_was;

		for (int i = 0; i < 40; ++i)
		{
			int a;
			
			a = rand() % 10;
			
			if (!already_was.contains(a))
			{
				std::cout << a << std::endl;
			}
			else
			{
				std::cout << '[' << a << ']' << std::endl;
			}
			already_was.emplace(a);
		}
	}

	void find()
	{
		std::set<int> s;
		s.emplace(4);
		s.emplace(6);
		s.emplace(9);
		
		std::set<int>::iterator it = s.find(4);
		
		assert(it != s.end());
		assert(*it == 4);
		
		it = s.find(10);
		assert(it == s.end());
	}

	void erase()
	{
		std::set<int> s;
		s.emplace(4);
		s.emplace(6);
		s.emplace(9);

		s.erase(6);

		std::set<int>::iterator it = s.find(9);

		s.erase(it);
		assert(s.size() == 1);
	}

	void Test2()
	{
		std::set<int> exists;
		//1 2 2 2 3 4 4 5 4 2 6 2 6
		//1 2   2 3 4   5 4   6 2 6

		for (int i = 0; i < 30; ++i)
		{
			int a;

			a = rand() % 10;

			if (!exists.contains(a))
			{
				std::cout << a << ' ';
				exists.emplace(a);
			}
			else
			{
				std::cout << '[' << a << ']' << ' ';
				exists.erase(a);
			}
		}
	}

	void count()
	{
		std::set<int> s;
		s.emplace(4);
		s.emplace(6);
		s.emplace(9);
		s.emplace(9);
		assert(s.count(4) == 1);
		assert(s.count(19) == 0);
		assert(s.count(9) == 1); //тут 1 а не 2 так как в сете, как и в мапе, нет повторов
	}

	void iterators()
	{
		std::set<int> s;
		s.emplace(88);
		s.emplace(6);
		s.emplace(2);
		s.emplace(19);

		//begin, end, ++, --

		for (auto it = s.begin(); it != s.end(); ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;

		for (auto ss : s)
		{
			std::cout << ss << ' ';
		}
		std::cout << std::endl;
	}

	void emplace_hint(int amount_of_emplaces)
	{
		std::set<int> s;
		auto it = s.begin();
		for (int i = 0; i < amount_of_emplaces; ++i)
		{
			s.emplace_hint(it, i);
			it = s.end();
		}
	}

	void emplace_hint_wrong(int amount_of_emplaces)
	{
		std::set<int> s;
		auto it = s.begin();
		for (int i = amount_of_emplaces; i > 0; --i)
		{
			s.emplace_hint(it, i);
			it = s.end();
		}
	}

	void swap()
	{
		std::set<int> s1;
		s1.emplace(88);
		s1.emplace(6);
		s1.emplace(2);
		s1.emplace(19);

		std::set<int> s2;
		s2.emplace(34);
		s2.emplace(2);

		s1.swap(s2);

		assert(s2.size() == 4);
		assert(s1.size() == 2);
	}

	void lower_bound()
	{
		std::set<int> s1;
		s1.emplace(1);
		s1.emplace(3);
		s1.emplace(5);
		s1.emplace(7);

		auto it = s1.lower_bound(3); //возвращает итератор на первый (ближайший) элемент, который больше или равен числу, которое пригнано на вход
		assert(*it == 3);

		it = s1.lower_bound(4);
		assert(*it == 5);

		it = s1.lower_bound(8);
		assert(it == s1.end());
	}

	void upper_bound()
	{
		std::set<int> s1;
		s1.emplace(1);
		s1.emplace(3);
		s1.emplace(5);
		s1.emplace(7);

		auto it = s1.upper_bound(3); //возвращает итератор на первый (ближайший) элемент, который больше числа, которое пригнано на вход
		assert(*it == 5);

		it = s1.upper_bound(4);
		assert(*it == 5);

		it = s1.upper_bound(8);
		assert(it == s1.end());
	}

	void equal_range()
	{
		std::set<int> s1;
		s1.emplace(1);
		s1.emplace(3);
		s1.emplace(5);
		s1.emplace(7);

		/* 
		принимает на вход число и возвращает на пару итераторов, 
		где первый итератор - это аналог lower_bound, а второй upper_bound
		*/
		
		auto [it1,it2] = s1.equal_range(3);
		assert(*it1 == 3 && *it2 == 5);
		
		auto [it11, it22] = s1.equal_range(6);
		assert(*it11 == 7 && *it22 == 7);

		auto [it111, it222] = s1.equal_range(7);
		assert(*it111 == 7 && it222 == s1.end());
		
		auto [it1111, it2222] = s1.equal_range(8);
		assert(it1111 == s1.end() && it2222 == s1.end());
	}

	void Test3()
	{
		std::set<int> s;
		for (int i = 0; i < 4; ++i)
		{
			int a = (rand() % 10) * 4;
			s.emplace(a);
			std::cout << a << ' ';
		}

		std::cout << std::endl;

		for (int i = 0; i < 20; ++i)
		{
			int a = rand() % 40;

			auto it = s.lower_bound(a);
			
			if (it != s.end())
			{
				std::cout << a << '-' << *it << std::endl;
			}
			else
			{
				std::cout << a << '-' << '!' << std::endl;
			}
		}
	}

	void Test4()
	{
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; ++i)
		{
			v1.push_back(rand() % 20);
			v2.push_back(rand() % 20);
		}

		for (auto elem : v1)
		{
			std::cout << std::setw(2) << elem << ' ';
		}
		std::cout << std::endl;

		for (auto elem : v2)
		{
			std::cout << std::setw(2) << elem << ' ';
		}
		std::cout << std::endl;

		std::set<int> s1;
		std::set<int> s2;

		for (auto e1 : v1)
		{
			s1.emplace(e1);
		}
		for (auto e2 : v2)
		{
			s2.emplace(e2);
		}

		//for (auto v1e : v1)
		//{
		//	for (auto v2e : v2)
		//	{
		//		if (v2e == v1e)
		//		{
		//			std::cout << v2e << ' ';
		//		}
		//	}
		//}

		//for (auto v1e : v1)
		//{
		//	auto it = std::find(v2.begin(), v2.end(), v1e);
		//	if (it != v2.end())
		//	{
		//		std::cout << *it << ' ';
		//	}
		//}

		for (int e : s1)
		{
			if (s2.contains(e))
			{
				std::cout << e << ' ';
			}
		}
	}

	void TestAll()
	{
		//emplace();
		//insert();
		//insert_emplace_struct();
		//contains();
		//Test1();
		//find();
		//erase();
		//Test2();
		//iterators();
		//emplace_hint(10);
		//emplace_hint_wrong(10);
		//swap();
		//lower_bound();
		//upper_bound();
		//equal_range();
		//Test3();
		Test4();
	}


	/*
	Set - это контейнер множества, в него можно положить, из него можно забрать и спросить - есть ли внутри. 
	Так как это множество - там нет повторяющихся элементов.  Set - эт также как и map - красно-черное дерево, но у Set есть только ключ, нет значения.

	Emplace
	Insert
	contains(c++20)
	find
	count
	erase
	clear - просто очищает весь контейнер
	
	Iterators
	Emplcace_hint
	swap
	lower_bound
	upper_bound
	equal_range
	
	extract
	merge
	*/
}