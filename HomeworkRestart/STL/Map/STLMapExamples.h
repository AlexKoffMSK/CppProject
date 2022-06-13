#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <map>

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

		Test() = default;
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
		std::cout << std::endl;

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
		std::cout << std::endl;
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
		//создать вектор рандомных чисел, а дальше вывести - сколько встречалось каждое число
		std::vector<int> vec;
		for (int i = 0; i < 20; ++i)
		{
			vec.push_back(rand() % 5 + 1);
		}

		std::map<int, int> m;
		//std::map<int, int> m_even;
		// 
		//если обращаться к элементу мапы через квадратные скобки, то, если его не было - будет создан с базовым значением. Для инта 0, для строки пустая строка
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

	//задача сделать цикл условно 100 итераций. на каждой итерации генерится
	//Два числа - цена, второе объем. задача для каждой цены сказать наибольший объем. Найти максимум по каждой цене.
	//вариант с вектором: память - N, действие - N+Nlogn+N
	//вариант с мапой первый: память - М(сколько уникальных цен), действие - 2*Nlogn
	//вариант с мапой второй: память - М(сколько уникальных цен), действие - Nlogn
	//вариант с мапой третий: память - М(сколько уникальных цен), действие - Nlogn
	void TestOnlineMap()
	{
		std::map<int, int> m;
		for (int i = 0; i < 10; ++i)
		{
			int price = rand() % 5 + 1;
			int value = rand() % 10 + 1;
			std::cout << '[' << price << ',' << value << ']' << std::endl;
			
			//int& curmax_value = m[price];
			//if (curmax_value < value)
			//{
			//	curmax_value = value;
			//}

			//auto it = m.find(price);
			//
			//if (it == m.end())
			//{
			//	m.emplace(price, value);
			//}
			//else
			//{
			//	if (it->second < value)
			//	{
			//		it->second = value;
			//	}
			//}

			auto [it, is_success_emplace] = m.emplace(price, value);
			if (it->second < value)
			{
				it->second = value;
			}

		}

		std::cout << std::endl;

		for (auto [key,value] : m)
		{
			std::cout << '[' << key << ',' << value << ']' << std::endl;
		}
	}
	
	//задача 
	//первая пара 3,5 - 5 это зависимый ордер 3. У 3 есть ребенок 5
	//первая пара 4,5
	//первая пара 5,6
	//первая пара 2,4
	//первая пара 6,7
	//первая пара 3,7 - это мы должны проигнорировать, потому что у 3 уже было соответствие
	//для каждого ордера вывести цепочку его зависимых ордеров:
	//2-4-5-6-7
	//3-5-6-7
	//4-5-6-7
	//5-6-7
	//6-7
	//7
	//у одного родителя может быть не более одного ребенка, у одного ребенка может быть много родителей и может не быть родителей
	void TestSequence()
	{
		std::map<int, int> m;
		for (int i = 0; i < 10; ++i)
		{
			int id_parent_order = rand() % 5 + 1;
			int id_child_order = rand() % 5 + 1;
			std::cout << '[' << id_parent_order << ',' << id_child_order << ']' << std::endl;
			auto [it, is_success_emplace] = m.emplace(id_parent_order, id_child_order);
			//провверять на то, что такое уже было не нужно, это сделал emplace
		}
		std::cout << std::endl;
		for (auto [key, value] : m)
		{
			std::cout << '[' << key << ',' << value << ']' << std::endl;
		}

		std::cout << std::endl;

		int see_for_value;

		std::map<int, int> m1; //создаем вторую мапу для хранения ячеек которые мы уже посещали
		
		for (auto [key, value] : m) 
		{
			auto it = m.find(key);
			while (true)
			{
				if (it == m.end())
				{
					break;
				}

				see_for_value = it->second;

				std::cout << '[' << it->first << ',' << it->second << ']';
				
				m1.emplace(it->first, it->second);
				
				it = m.find(see_for_value);
				
				if (it != m.end() && m1.find(it->first) != m1.end())
				{
					break;
				}
			}
			std::cout << std::endl;
			m1.clear();
		}

		std::cout << std::endl;
	}

	void at()
	{
		std::map<int, double> m;
		m.emplace(4, 5.2);
		m.emplace(7, 8.6);
		assert(m.at(4) == 5.2); //кинет исключение если 4 не было
		assert(m[4] == 5.2);//создаст 4 если ее не было
		
		try
		{
			std::cout << m.at(5) << std::endl;
		}
		catch (std::exception exc) 
		{
			std::cout << "Caught exception: " << exc.what() << std::endl;
		}
		
		m.at(4) = 3.85;
		m[4] = 8.999;
	}

	void iterators()
	{
		std::map<int, double> m;
		m.emplace(2, 5.);
		m.emplace(1, 4.);
		m.emplace(3, 6.);

		auto it = m.begin();
		
		assert(it->first == 1 && it->second == 4.);

		//std::cout << it->first << ' ' << it->second << std::endl;
		++it;
		assert(it->first == 2 && it->second == 5.);

		++it;
		assert(it->first == 3 && it->second == 6.);

		++it;
		assert(it == m.end());
	}

	void reverse_iterators()
	{
		std::map<int, double> m;
		m.emplace(2, 5.);
		m.emplace(1, 4.);
		m.emplace(3, 6.);

		auto it = m.rbegin();

		assert(it->first == 3 && it->second == 6.);

		//std::cout << it->first << ' ' << it->second << std::endl;
		++it;
		assert(it->first == 2 && it->second == 5.);

		++it;
		assert(it->first == 1 && it->second == 4.);

		++it;
		assert(it == m.rend());

		for (auto it = m.begin(); it != m.end(); ++it)
		{
			std::cout << it->first << ' ' << it->second << std::endl;
		}
	}

	void count()
	{
		std::map<int, double> m;
		m.emplace(2, 5.);
		m.emplace(1, 4.);
		m.emplace(1, 6.);

		assert(m.count(1) == 1);
		assert(m.count(6) == 0);
	}

	int map_emplace(int nof_operations)
	{
		std::map<int, char> map;
		for (int i = 0; i < nof_operations; ++i) 
		{
			map.emplace(i, 'a');
		}
		return map.size();
	}

	void map_emplace_hint(int nof_operations)
	{
		std::map<int, char> map;
		auto it = map.begin();
		for (int i = 0; i < nof_operations; ++i) 
		{
			map.emplace_hint(it, i, 'b');
			it = map.end();
		}
	}

	void map_emplace_hint_wrong(int nof_operations)
	{
		std::map<int, char> map;
		auto it = map.begin();
		for (int i = nof_operations; i > 0; --i) 
		{
			map.emplace_hint(it, i, 'c');
			it = map.end();
		}
	}

	void insert()
	{
		std::map<int, double> m;
		m.emplace(2, 5.);
		m.emplace(1, 4.);
		m.emplace(1, 6.);

		m.insert(std::pair(3, 5.));
		m.insert(std::pair{ 4, 6. });
		m.insert({ 5, 7. });
	}

	void insert_or_assign()
	{
		std::map<int, int> m;
		m.emplace(2, 5);
		m.emplace(1, 4);
		m.emplace(1, 6);

		m.insert_or_assign(3, 5); 
		m.insert_or_assign(2, 6); //в отличиие от emplace - заменит существующую пару
	}

	void insert_or_assign_struct()
	{
		std::map<int, Test> m;
		m.emplace(2, Test(7, 8));
		m.insert({ 3,Test(6,9) });
		m.insert_or_assign(3, Test(8, 4));
		m[4] = (Test(1, 0));
		//std::cout << m[9]._x << std::endl;
	}

	void try_emplace()
	{
		std::map<int, Test> m;
		m.emplace(5, Test(4,5));
		m.emplace(5, Test(8,9));
		m.try_emplace(5, 6, 8);
	}

	void greater()
	{
		std::map<int, double> m;
		std::map<int, double,std::greater<>> m1;
		m.emplace(5, 6);
		m1.emplace(5, 6);

		m.emplace(6, 8);
		m1.emplace(6, 8);
		
		m.emplace(4, 8);
		m1.emplace(4, 8);

		for (auto [key, value] : m)
		{
			std::cout << key << ' ' << value << std::endl;
		}

		std::cout << std::endl;
		
		for (auto [key, value] : m1)
		{
			std::cout << key << ' ' << value << std::endl;
		}
	}

	void TestAll()
	{
		//emplace();
		//emplace_and_check();
		//emplace_twice();
		//emplace_twice_and_check();
		//emplace_string_key();
		//emplace_key_double_value_string();
		//emplace_key_char_value_vector();
		//emplace_key_int_value_struct();
		//find();
		//clear();
		//erase_by_key();
		//erase_by_iterator();
		//TestEmplaceErase();
		//TestEmplaceErase1();
		//operator_squares();
		//TestEmplaceErase2();
		//TestOnlineMap();
		//TestSequence();
		//at();
		//iterators();
		//reverse_iterators();
		//count();
		//auto t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//map_emplace_hint(100000);
		//auto t2 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//map_emplace_hint_wrong(100000);
		//auto t3 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//map_emplace(100000);
		//auto t4 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//std::cout << t2 - t1 << std::endl;
		//std::cout << t3 - t2 << std::endl;
		//std::cout << t4 - t3 << std::endl;
		//insert();
		//insert_or_assign();
		//insert_or_assign_struct();
		//try_emplace();
		greater();
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
	greater

	equal_range
	extract
	lower_bound
	merge
	upper_bound
	*/
}