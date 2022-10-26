#pragma once
#include <iostream>
#include <unordered_map>
#include <functional>

//ассоциативный массив, под капотом хэш-таблица, использует метод работы с коллизиями - метод цепочек
//метод цепочек - это когда значением в хэш-таблице является список. 
//еще бывает метод открытой адресации, это когда значение с одинаковым ключем располагается в следующей доступной ячейке хэш-таблицы

namespace STLUnorderedMap
{
	void test()
	{
		std::unordered_map<int, double> um;
		um.emplace(5, 5.1); //принимает ключ и значение (объект)
		um.emplace(1, 1.1);
		um.emplace(2, 2.1);
		um.emplace(3, 3.1);
		um.emplace(4, 3.1);
		um.emplace(7, 3.1);
		um.emplace(8, 3.1);
		um.emplace(10, 3.1);

		assert(um.find(6) == um.end());
		assert(um.find(5)->second == 5.1);

		um.erase(1);
		
		um.erase(um.find(3));

		assert(um.size() == 6);

		assert(um.count(1) == 0);
		assert(um.count(3) == 0);
		
		um.insert(std::pair<int,double>{11,11.1}); //принимает пару, можно не писать <int,double>
		um.insert(std::pair{ 11,11.2 });

		assert(um.find(11)->second == 11.1);
		assert(um.find(11)->second != 11.2);
		
		um.insert_or_assign(11,11.3); //принимает ключ и значение (объект). Либо создает новый, либо меняет значение у ключа, если такой ключ уже есть

		assert(um.find(11)->second == 11.3);
	}

	class MyHash
	{
	public:
		int operator()(int x) const
		{
			//std::cout << "H " << x << ' ' << x % 5 << std::endl;
			return x % 5;
		}
	};

	void test2()
	{
		MyHash mh_1;

		//std::cout << mh_1.operator()(13) << std::endl;
		//std::cout << mh_1(13) << std::endl;
		
		std::unordered_map<int, double, MyHash> um; //MyHash выступает в роли функтора

		um.emplace(5, 5.1); //принимает ключ и значение (объект)
		um.emplace(1, 1.1);
		um.emplace(2, 2.1);
		um.emplace(3, 3.1);
		um.emplace(4, 4.1);
		um.emplace(7, 7.1);
		um.emplace(8, 8.1);
		um.emplace(10, 10.1);
		um.emplace(11, 11.1);
		um.emplace(15, 15.1);

		std::cout << um.bucket_count() << std::endl; //возвращает суммарное количество bucket-ов
		std::cout << um.bucket(5) << std::endl; //возвращает номер bucket-а, куда попадает ключ 5
		std::cout << um.bucket(2) << std::endl;
		std::cout << um.bucket(3) << std::endl;
		std::cout << um.bucket(15) << std::endl;

		std::cout << um.bucket_size(0) << std::endl; //возвращает количество элементов в bucket-е (в данном случае в нулевом)
		std::cout << um.max_bucket_count() << std::endl; //возвращает максимальное число возможных bucket-ов

		for (auto it = um.begin(); it != um.end(); it++)
		{
			std::cout << it->first << ' ' << it->second << std::endl; //вывод будет отсортирован по результату хэш-фукнции
		}

	}

	//какие бывают ключи и какие под них придумать хэш-фукнции чтобы минимизировать коллизии?
	//так как результат - число, то это может быть числовая функция, типа сложения, умножения, целочисленного деления на что-то.
	//string - Ф И О, город проживания.
	//string - Предложение со знаками препинания, пробелами и точкой в конце.
	//string - абзац - набор предложений, котоорые заканчиваются пустой строкой
	//string - Текст - набор абзацев
	//string - Арифметическое выражение
	//СуммаДенег кратна 1000, диапазон - от 100000 до 10^6
	//Структура Студент - ФИО, возраст, успеваемость
	//Точка на плоскости (x,y)
	//прямоугольник (1 точка и два числа - ширина, высота)
	//прямоугольник (1 точка и два числа - ширина, высота)
	//Ордер на бирже - id цена объем сторона

	//хэш-функция, которую мы передаем в виде функции
	int HashFunctionFIOSummChars(std::string& str)
	{
		//сложность O(n)
		
		int summ = 0;
		for (char ch : str)
		{
			if (ch == ' ')
			{
				continue;
			}
			summ += (int)ch;
		}
		return summ;
	}

	int HashFunctionFIOSummPosChars(std::string& str)
	{
		//сложность O(n)
		
		int summ = 0;
		for (char ch : str)
		{
			if (ch == ' ')
			{
				continue;
			}
			summ += (ch-'a')*2;
		}
		return summ;
	}

	//хэш-функция, которую мы передаем в виде функтора
	class StringLenghtHashFunction
	{
	public:
		int operator()(std::string& str) const
		{
			return str.size();
		}

		//сложность O(1)
	};

	//void TestFIO(std::function<uint64_t(std::string)> hash_func) 
	template<class T>
	void TestFIO(T hash_func)
	{
		srand(0);
		
		const int n = 10000;
		const int max_f = 15;
		const int max_i = 10;
		const int max_o = 13;
		const int min_word_lenght = 1000;
		const int letters = 30;

		uint64_t total_hash_time = 0;

		std::set<uint64_t> uniq_hashes;
		
		for (int i = 0; i < n; i++)
		{
			std::string fio;
			int x = rand() % max_f + min_word_lenght;
			for (int j = 0; j < x; j++)
			{
				fio.push_back(rand() % letters + 'a');
			}

			fio.push_back(' ');

			int y = rand() % max_i + min_word_lenght;
			for (int j = 0; j < y; j++)
			{
				fio.push_back(rand() % letters + 'a');
			}

			fio.push_back(' ');

			int z = rand() % max_o + min_word_lenght;
			for (int j = 0; j < z; j++)
			{
				fio.push_back(rand() % letters + 'a');
			}

			auto t1 = std::chrono::high_resolution_clock::now();

			uint64_t hash_res = hash_func(fio);

			auto t2 = std::chrono::high_resolution_clock::now();

			total_hash_time += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

			uniq_hashes.emplace(hash_res);
		}
		std::cout << "set_size: " << std::setw(5) << uniq_hashes.size() << " | ";
		std::cout << "bounds: " << std::setw(9) << *uniq_hashes.begin() << ' ' << std::setw(9) << *uniq_hashes.rbegin() << ' ' << std::setw(9) << *uniq_hashes.rbegin() - *uniq_hashes.begin() + 1 << " | ";
		std::cout << std::setw(6) << 1 - ((double)(uniq_hashes.size()-1) / n) << " | " << std::setprecision(3) << (double)total_hash_time / (1000000000) << std::endl;
	}

	void Run()
	{
		TestFIO(HashFunctionFIOSummChars);
		TestFIO(HashFunctionFIOSummPosChars);
		TestFIO(StringLenghtHashFunction{});
		TestFIO([](std::string& str) {return 1; }); //сложность O(1)
		//TestFIO([](std::string str) {return str.size(); });

		TestFIO([](std::string& str)
			{
				//сложность O(n)
				uint64_t count = 0;
		
				for (char ch : str)
				{
					if (ch == ' ')
					{
						count *= 10000;
					}
					else
					{
						count += ch;
					}
				}
				return count % 10000;
			}
		);

		TestFIO([](std::string& str)
			{
				//сложность O(n)
				
				uint64_t count_odd = 0;
				uint64_t count_even = 0;
		
				for (char ch : str)
				{
					if (ch % 2 == 0)
					{
						count_even += (int)ch;
					}
					else
					{
						count_odd += (int)ch;
					}
				}
				
				return (count_even * 10000 + count_odd) % 100000;
			}
		);

		TestFIO([](std::string& str)
			{
				//сложность O(n)
				
				uint64_t count = 0;
				int max_mult = 6;
				
				//1 10 100 1000
				//Happy Happy!
				
				for (int i=0; i < str.size(); i++)
				{
					if (str[i] == ' ')
					{
						continue;
					}
					count += (int)str[i] * std::pow(10, i % max_mult);

				}
				return count % 10000;
			}
		);

		TestFIO([](std::string& str)
			{
				uint64_t summ = 0;
				uint64_t* p_max = (uint64_t*)(str.data() + str.size());
				
				uint64_t* p = (uint64_t*)str.data();

				while (p < p_max)
				{
					summ += *p;
					p++;
				}
				return summ % 10000;

				//set_size:  6273 | bounds:         0      9999     10000 |  0.373 | 0.0963
			}
		);

	}
}

//создать unmap и помимо расчета хэшфункции - загнать в мапу и замерять время. через функтор и функцию, лямбда не выйдет

/*
emplace
count
find
insert
insert_or_assign

bucket_count
buckets_size
bucket
max_bucket_count

bucket_iterator



emplace_hint
try_emplace
erase
extract
merge
at
operator[]
equal_range
iterators
load_factor
max_load_factor
rehash
reserve
hash_function
key_eq
*/