#pragma once
#include <iostream>
#include <cassert>
#include <vector>

namespace HashTable //хэш-таблица это таблица с результатами хэширования
{
	static const int word_lenght = 9000;
	static const int n = 26 * word_lenght;

	int count_of_collisions[n] = { 0 };
	
	class  HashTableVector
	{
	private:
		
		struct KeyValue
		{
			std::string _key;
			int _value;
		};
		std::vector<KeyValue> _hash_table[n];

		//std::string _t;
		//KeyValue _kv;
		//std::string _s[n];
		//KeyValue _kv2[n];
		//std::vector<std::string> _str;
		//std::vector<std::string> _str1[n];
		//std::vector<KeyValue> _kv3;
		//std::vector<KeyValue> _kv4[n];
		
		int HashFunction0(std::string key)
		{
			return key.size();
		}

		int HashFunction1(std::string key)
		{
			char first_letter = key[0];
			if (first_letter >= 'A' && first_letter <= 'Z')
			{
				return first_letter - 'A';
			}
			else if (first_letter >= 'a' && first_letter <= 'z')
			{
				return first_letter - 'a';
			}
			else
			{
				return 0;
			}
		}

		int HashFunction(std::string key)
		{
			int counter = 0;
			for (char ch : key)
			{
				counter += ch - 'a';
			}
			return counter;
		}

		int HashFunction3(std::string key)
		{
			return 1;
		}

	public:

		void Add(std::string key, int value)
		{
			int hash = HashFunction(key);

			if (_hash_table[hash].size() != 0)
			{
				count_of_collisions[hash]++;
			}

			for (KeyValue& key_value : _hash_table[hash])
			{
				if (key_value._key == key)
				{
					key_value._value = value;
					return;
				}
			}
			_hash_table[hash].push_back(KeyValue{ key,value });
		}

		void Remove(std::string key)
		{
			int hash = HashFunction(key);
			for (int i=0; i< _hash_table[hash].size(); ++i)
			{
				if (_hash_table[hash][i]._key == key)
				{
					_hash_table[hash].erase(_hash_table[hash].begin()+i);
					return;
				}
			}
		}

		int Find(std::string key)
		{
			int hash = HashFunction(key);
			for (KeyValue& key_value : _hash_table[hash])
			{
				if (key_value._key == key)
				{
					return key_value._value;
				}
			}
			return -1;
		}
	};

	void Test()
	{
		HashTableVector hs;
		hs.Add("Vasya", 2);
		hs.Add("Petya", 3);
		hs.Add("Igor", 2);
		hs.Add("Andrey", 4);
		hs.Add("Joe", 5);
		hs.Remove("Petya");
		assert(hs.Find("Vasya") == 2);
		assert(hs.Find("Petya") == -1);
		assert(hs.Find("Igor") == 2);
		assert(hs.Find("Andrey") == 4);
		assert(hs.Find("Joe") == 5);
		assert(hs.Find("Vitya") == -1);
	}

	void Test1()
	{
		HashTableVector hs;
		hs.Add("Vasya", 2);
		hs.Add("Vasya", 3);
		assert(hs.Find("Vasya") == 3);
	}

	void Test2()
	{
		HashTableVector hs;
		
		srand(0);
		auto start = chrono::system_clock::now(); // Начинаем засекать время

		for (int i = 0; i < 10000; ++i)
		{
			static const char start_char = 'a';
			static const char end_char = 'z';
			
			int rnd = rand() % 100;

			if (rnd >= 50)
			{
				hs.Add(get_random_english_string(rand() % word_lenght + 1, start_char, end_char), rand() % 100);
			}
			if (rnd < 20)
			{
				hs.Remove(get_random_english_string(rand() % word_lenght + 1, start_char, end_char));
			}
			if (rnd >= 20 && rnd < 50)
			{
				hs.Find(get_random_english_string(rand() % word_lenght + 1, start_char, end_char));
			}
		}
		auto end = chrono::system_clock::now(); // Заканчиваем засекать вермя
		chrono::duration<double> elapsed = end - start;
		cout << setprecision(15) << elapsed.count() << "s" << endl; // Выводим сколько времени засекли
		
		//for (int count : count_of_collisions)
		//{
		//	std::cout << count << ' ';
		//}
	}
}