#pragma once
#include <iostream>


namespace StlMap
{
	void emplace()
	{
		std::map<int, int> m;
		assert(m.size() == 0);
		assert(m.empty() == true); //assert(m.empty) the same
		
		m.emplace(3, 121);
		assert(m.size() == 1);
		assert(!m.empty());

		m.emplace(5, 9);
		assert(m.size() == 2);
	}

	void emplace_and_check()
	{
		std::map<int, int> m = { {3,121},{5,9} };
		m.emplace(4, 33);
		m.emplace(1,0);

		for (auto& [key, value] : m)
		{
			std::cout << key << ' ' << value << std::endl;
		}
		for (std::pair<const int, int>& p : m)
		{
			std::cout << p.first << ' ' << p.second << std::endl;
		}
	}

	void emplace_twice()
	{
		std::map<int, int> m;
		m.emplace(4, 5);
		m.emplace(4, 6); //у мапы зафиксировано, что если добавлять в уже существующий ключ через emplace - то добавления не будет
		assert(m.size() == 1);

		for (auto& [key, value] : m)
		{
			assert(key == 4 && value == 5);
			//std::cout << key << ' ' << value << std::endl;
		}
	}

	void emplace_twice_and_check()
	{
		std::map<int, int> m;
		auto [it, is_success_emplace] = m.emplace(4, 5);
		assert(is_success_emplace);

		auto [it1, is_success_emplace1] = m.emplace(4, 6); //emplace возвращает пару: итератор на элемент и true если вставка была и false если вставки не было
		assert(!is_success_emplace1);
	}

	void emplace_string_key()
	{
		std::map<std::string, int> m;
		m.emplace("Hello", 1);
		m.emplace(" world!", 2);
	}

	void emplace_key_double_value_string()
	{
		std::map<double, std::string> m;
		m.emplace(1.4, "Hello");
		m.emplace(2.9999999, " world!");
	}

	void emplace_key_char_value_vector()
	{
		std::map<char, std::vector<int>> m;
		m.emplace('A', std::vector<int>{ 2,3,4 });
		m.emplace('B', std::vector<int>{ 5,6,7 });
	}

	struct Test
	{
		int _x;
		double _y;

		Test(int x_, double y_)
		{
			_x = x_;
			_y = y_;
		}
	};

	void emplace_key_int_value_struct()
	{
		std::map<int, Test> m;
		Test t(5,6);
		m.emplace(1, t); //аналог push_back()
		m.emplace(2, Test(7, 8));//аналог push_back()
	}

	void find()
	{
		std::map<int, double> m;
		m.emplace(1, 2.777);
		m.emplace(2, 3.777);
		m.emplace(3, 4.777);

		auto it = m.find(5);
		assert(it == m.end());

		it = m.find(2); //принимает на вход именно ключ, а не итератор или что-то еще, возвращает итератор
		assert(it != m.end());

		assert(it->first == 2 && it->second == 3.777);

		it->second = 6; //так как итератор после 112 строки смотрит на второй элемент
		assert(it->first == 2 && it->second == 6);
	}

	void clear()
	{
		std::map<int, double> m;
		m.emplace(1, 2.777);
		m.emplace(2, 3.777);
		m.emplace(3, 4.777);

		m.clear();
		assert(m.size() == 0);
		assert(m.empty());
	}

	void erase_by_key()
	{
		std::map<int, double> m;
		m.emplace(1, 2.777);
		m.emplace(2, 3.777);
		m.emplace(3, 4.777);

		m.erase(2); //удали элемент у которого ключ 2
		assert(m.size() == 2);
		assert(m.find(2) == m.end());

		int count_of_erased_elements = m.erase(3);
		assert(count_of_erased_elements == 1);

		count_of_erased_elements = m.erase(5);
		assert(count_of_erased_elements == 0);

	}

	void erase_by_iterator()
	{
		std::map<int, double> m;
		m.emplace(1, 2.777);
		m.emplace(2, 3.777);
		m.emplace(3, 4.777);

		auto it = m.find(1);
		m.erase(it);
		//с этого момента использовать it нельзя, он стал не валидным, т.к. erase удалил элемент, на который смотрел it, но erase вернет итератор на следующий элемент, который можно поймать.
		assert(m.size() == 2);
		assert(m.find(1) == m.end());
	}

	void TestEmplaceErase() //map int-int, random key, удалить из мапы все элементы, у которых ключ четный
	{
		std::map<int, int> m;
		for (int i = 0; i < 10; ++i)
		{
			m.emplace(rand() % 40 + 1, rand() % 100 + 40);
		}
		
		for (auto& [key, value] : m)
		{
			std::cout << '[' << key << ',' << value << ']';
		}
		std::cout << endl;

		bool was_erased = true;
		while (was_erased == true)
		{
			for (auto& [key, value] : m)
			{
				if (key % 2 == 0)
				{
					m.erase(key);
					was_erased = true;
					break;
				}
				else
				{
					was_erased = false;
				}
			}
		}

		for (auto& [key, value] : m)
		{
			std::cout << '[' << key << ',' << value << ']';
		}
		std::cout << endl;
	}

	void TestEmplaceErase1()
	{
		std::vector<int> vec;
		for (int i = 0; i < 20; ++i)
		{
			vec.push_back(rand() % 9 + 1);
		}

		std::map<int, int> m;
		//std::map<int, int> m_even;

		for (int i = 0; i < vec.size(); ++i)
		{
			auto it = m.find(vec[i]);
			if (it != m.end())
			{
				it->second++;
			}
			else
			{
				m.emplace(vec[i],1);
			}
		}

		for (auto& v : vec)
		{
			std::cout << '[' << v << ']';
		}
		std::cout << std::endl;

		for (auto& [key, value] : m)
		{
			std::cout << '[' << key << ',' << value << ']';
		}
		std::cout << std::endl;
	}

	void operator_squares()
	{
		std::map<int, double> m;
		m.emplace(3, 5);
		assert(m.find(3)->second == 5);

		m[3] = 6;//эта строчка почти эквивалент m.emplace(4, 6). Разница в том, что при записи через [] создается элемент или меняется значение БЕЗ проверки, которая есть у emplace
		assert(m.find(3)->second == 6);

		std::cout << m[3] << std::endl;
		std::cout << m[4] << std::endl; //будет создан новый элемент
		assert(m.size() == 2);
		assert(m[4] == 0);
		
		m[5] = 7;
		m[5] = m[5] + 3;
		assert(m[5] == 10);
	}

	void TestEmplaceErase2()
	{
		std::vector<int> vec;
		for (int i = 0; i < 20; ++i)
		{
			vec.push_back(rand() % 5 + 1);
		}

		std::map<int, int> m;
		//std::map<int, int> m_even;
		// 
		//если обращаться к элементу мапы через квадратные скобки, то если его не было - будет создан с базовым значением. Для инта 0, для строки пустая строка
		for (int i = 0; i < vec.size(); ++i)
		{
			m[vec[i]]++; // (m[vec[i]])++; сначала выполняется m[vec[i]], потом ++
		}

		for (auto& v : vec)
		{
			std::cout << '[' << v << ']';
		}
		std::cout << std::endl;

		for (auto& [key, value] : m)
		{
			std::cout << '[' << key << ',' << value << ']';
		}
		std::cout << std::endl;
	}

	void Test()
	{
		emplace();
		emplace_and_check();
		emplace_twice();
		emplace_twice_and_check();
		emplace_string_key();
		emplace_key_double_value_string();
		emplace_key_char_value_vector();
		emplace_key_int_value_struct();
		find();
		clear();
		erase_by_key();
		erase_by_iterator();
		TestEmplaceErase();
		TestEmplaceErase1();
		operator_squares();
		TestEmplaceErase2();
	}

	/*
	emplace
	find
	size
	empty
	clear
	erase
	operator []
	
	at
	iterators
	count
	emplace_hint
	insert
	insert_or_assign
	try_emplace
	less

	equal_range
	extract
	lower_bound
	merge
	upper_bound
	*/
}