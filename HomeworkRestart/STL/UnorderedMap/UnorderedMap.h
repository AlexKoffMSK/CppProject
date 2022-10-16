#pragma once
#include <iostream>
#include <unordered_map>

//ассоциативный массив, под капотом хэш-таблица, использует метод работы с коллизи€ми - метод цепочек
//метод цепочек - это когда значением в хэш-таблице €вл€етс€ список. 
//еще бывает метод открытой адресации, это когда значение с одинаковым ключем располагаетс€ в следующей доступной €чейке хэш-таблицы

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
		
		um.insert_or_assign(11,11.3); //принимает ключ и значение (объект). Ћибо создает новый, либо мен€ет значение у ключа, если такой ключ уже есть

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

	void Run()
	{
		test2();

	}
}

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