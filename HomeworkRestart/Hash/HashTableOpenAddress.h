#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Functions.h"

namespace HashTable //хэш-таблица это таблица с результатами хэширования. Метод открытой адресации.
{
	//1.Длина строки (1 действие)
	int HashFunctionSize(std::string str) {return str.size();}
	int HashFunction0(std::string str) { return 0; }
	
	//2.Сумма аски кодов символом (N действий * сложность суммирования)
	//int HashFunction(std::string str)
	//{
	//	int char_summ = 0;
	//	for (int i = 0; i < str.size(); ++i)
	//	{
	//
	//	}
	//}

	//3.Количество гласных букв (N * сложность понимания гласная ли буква)
	
	//4.Количество цифр (N * сложность определения цифра ли)
	
	//5.SHA256 (хз)
	
	//6.Аски код первого символа (1 действие)
	int HashFunctionASCIIFirstLetter(std::string str)
	{
		return str.front();
		//return *str.begin(); аналогично
		//return str[0]; аналогично
	}
	
	template <class THashFunction>
	class HashTableOpenAddress
	{
	private:

		std::vector<std::string> _hash_table = std::vector<std::string>(300);
		THashFunction _hash_function;

	public:
		int _array_finds_count = 0;

		HashTableOpenAddress(THashFunction hash_function_)
		{
			_hash_function = hash_function_;
		}

		void Add(std::string key)
		{
			int hash = _hash_function(key);
			
			for (int i = hash; i < _hash_table.size(); ++i)
			{
				if (_hash_table[i].empty())
				{
					_hash_table[i] = key;
					return;
				}
			}
			assert(false);
		}

		bool Find(std::string key)
		{
			int hash = _hash_function(key);
			
			for (int i = hash; i < _hash_table.size(); ++i)
			{
				_array_finds_count++;
				if (_hash_table[i].empty())
				{
					return false;
				}
				if (_hash_table[i] == key)
				{
					return true;
				}
			}
			return false;
		}

		void Print()
		{
			for (int i = 0; i < _hash_table.size(); ++i)
			{
				std::cout << "Index: " << std::setw(3) << i << ". Value: " << _hash_table[i] << std::endl;
			}
		}

	};

	void TestOA()
	{
		HashTableOpenAddress hsoa(HashFunctionSize);
		hsoa.Add("Vasya");
		hsoa.Add("Petya");
		hsoa.Add("Sergey");
		hsoa.Add("Tom");
		hsoa.Add("Yam");
		hsoa.Add("Bob");
		hsoa.Add("Konstantin");
		hsoa.Add("Matvey");
		
		//hsoa.Print();

		std::cout << "Vasya: " << hsoa.Find("Vasya") << std::endl;
		std::cout << "Kolya: " << hsoa.Find("Kolya") << std::endl;
		std::cout << "Jon: " << hsoa.Find("Jon") << std::endl;
		std::cout << "Yam: " << hsoa.Find("Yam") << std::endl;
		std::cout << "Bob: " << hsoa.Find("Bob") << std::endl;
		std::cout << "Sergey: " << hsoa.Find("Sergey") << std::endl;
		std::cout << "Konstantin: " << hsoa.Find("Konstantin") << std::endl;
		std::cout << "Matvey: " << hsoa.Find("Matvey") << std::endl;
		std::cout << "Andrey: " << hsoa.Find("Andrey") << std::endl;

	}

	template <class TFunction>
	void Test2OA(int uniq_elems_count, int adds_count, int finds_count, int max_str_lenght, TFunction function)
	{
		std::vector<std::string> uniq_elems;
		
		for (int i = 0; i < adds_count; ++i)
		{
			uniq_elems.push_back(get_random_english_string(rand() % max_str_lenght + 1));
		}
		
		auto t0 = chrono::system_clock::now(); // Начинаем засекать время
		
		HashTableOpenAddress htoa(function);

		for (int i = 0; i < adds_count; ++i)
		{
			int rand_elem_index_to_add = rand() % uniq_elems.size();
			htoa.Add(uniq_elems[rand_elem_index_to_add]);
		}
		
		auto t1 = chrono::system_clock::now(); // Начинаем засекать время

		int counter_of_find = 0;
		for (int i = 0; i<finds_count; ++i)
		{
			int rand_elem_index_to_find = rand() % uniq_elems.size();
			counter_of_find += htoa.Find(uniq_elems[rand_elem_index_to_find]);
		}

		auto t2 = chrono::system_clock::now(); // Заканчиваем засекать вермя

		chrono::duration<double> elapsed_add = t1 - t0;
		chrono::duration<double> elapsed_find = t2 - t1;

		ofstream ofs("Hash/OAresults.txt",std::ios_base::app);
		
		ofs << "u_e_c: " << setw(4) <<uniq_elems_count << ", a_c: " << setw(4) <<adds_count << ", f_c: " << setw(7) << finds_count << ", m_s_l: " << setw(4) <<max_str_lenght << "|   ";

		ofs << setprecision(5) << setw(9) << elapsed_add.count() << ",     "; // Выводим сколько времени засекли
		ofs << setprecision(5) << setw(9) << elapsed_find.count() << ",     "; // Выводим сколько времени засекли
		ofs << setprecision(5) << setw(9) << (elapsed_find + elapsed_add).count() << ",     "; // Выводим сколько времени засекли
		ofs << setw(9) << htoa._array_finds_count << std::endl;
		std::cout << counter_of_find << std::endl;
	}

	template <class TFunction>
	void Test3OA(TFunction function, std::string message)
	{
		ofstream ofs("Hash/OAresults.txt", std::ios_base::app);
		ofs << endl;
		ofs << message << endl;
		ofs.close();
		Test2OA(100, 50, 100, 10, function);
		Test2OA(100, 50, 1000, 10, function);
		Test2OA(100, 50, 10000, 10, function);
		Test2OA(100, 50, 100000, 10, function);
		Test2OA(100, 50, 1000000, 10, function);
		std::cout << "Ready" << std::endl;
	}

	void Test4OA()
	{
		Test3OA(HashFunctionSize, "HashFunctionSize: ");
		Test3OA(HashFunction0, "HashFunction0: ");
		Test3OA(HashFunctionASCIIFirstLetter, "HashFunctionASCIIFirstLetter: ");
	}
}