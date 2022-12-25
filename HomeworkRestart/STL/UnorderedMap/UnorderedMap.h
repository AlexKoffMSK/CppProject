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
		int operator()(const std::string& str) const
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

		TestFIO([](std::string& str)
			{
				uint64_t summ = 0;
				char* p_max = (str.data() + str.size());
				char* p = str.data();

				while (p < p_max)
				{
					summ += *(uint64_t*)p;
					p++;
				}
				return summ % 10000;

			}
		);

	}

	class CustomHashFunction
	{
	public:
		int operator()(int x) const
		{
			return x%5;
		}
	};

	class CustomHashFunction1
	{
	public:
		int operator()(const std::string& str) const
		{
			return *(int*)str.data();
		}
	};

	class CustomHashOurFastest
	{
	public:
		int operator()(const std::string& str) const
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
		}
		//set_size:  6273 | bounds:         0      9999     10000 |  0.373 | 0.0963
	};

	void UnorderedMapCustomHash()
	{
		std::unordered_map<int, int> um;
		std::unordered_map<int, int, CustomHashFunction> um1;

	}

	template<class TMap>
	void TestFioInUnMap()
	{
		TMap tm;
		srand(0);

		const int n = 10000;
		const int max_f = 15;
		const int max_i = 10;
		const int max_o = 13;
		const int min_word_lenght = 1;
		const int letters = 30;

		uint64_t total_hash_time = 0;

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

			//*(int*)fio.data() = i;

			auto t1 = std::chrono::high_resolution_clock::now();

			tm.emplace(fio,1);

			auto t2 = std::chrono::high_resolution_clock::now();

			total_hash_time += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		}

		std::map<int, int> m;

		for (int i = 0; i < tm.bucket_count(); i++)
		{
			m[tm.bucket_size(i)]++;
		}

		for (auto [key,value] : m)
		{
			std::cout << key << ": " << value << std::endl;
		}

		std::cout << std::setw(5) << tm.bucket_count() << " | " << tm.size() << " | " << std::setprecision(3) << (double)total_hash_time / (1000000000) << std::endl;

		for (auto it = tm.begin(1); it != tm.end(1); it++)
		{
			std::cout << " [" << it->first << ' ' << it->second << "] " << std::endl;
		}
	}

	void TestMaps()
	{
		TestFioInUnMap<std::unordered_map<std::string,int>>();
		//TestFioInUnMap<std::unordered_map<std::string,int, StringLenghtHashFunction>>();
		TestFioInUnMap<std::unordered_map<std::string,int, CustomHashOurFastest>>();
		TestFioInUnMap<std::unordered_map<std::string,int, CustomHashFunction1>>();
	}

	void Run1()
	{
		TestMaps();
	}

	class ObjectsForMap
	{
	public:
		int _a;
		double _b;

		ObjectsForMap(int x_, double y_)
			: _a(x_)
			, _b(y_)
		{
		}
	};

	class BigObject
	{
	public:
		int* _a;
		int _n = 0;

		BigObject(int n)
			: _a(new int[n])
			, _n(n)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Constructor " << (void*)this << std::endl;
		}

		BigObject(const BigObject& bo)
			: _a(new int[bo._n])
			, _n(bo._n)
		{
			std::cout << "Copy Constructor " << (void*)&bo << " to " << (void*)this << std::endl;
		}

		BigObject(STLUnorderedMap::BigObject&& bo)
			: _a(bo._a)
			, _n(bo._n)
		{
			bo._a = nullptr;
			bo._n = 0;
			std::cout << "Move Constructor " << (void*)&bo << " to " << (void*)this << std::endl;
		}

		~BigObject()
		{
			if (_n != 0)
			{
				delete[] _a; //delete просто возвращает операционной системе память, но не убиавет никакой объект или поле и т.д.
				std::cout << "Destructor with delete " << (void*)this << std::endl;
			}
			else
			{
				std::cout << "Destructor without delete " << (void*)this << std::endl;
			}
		}

		bool operator==(const BigObject& obj) const
		{
			return _a == obj._a;
		}
	};

	void TryEmplace()
	{
		std::unordered_map<int, ObjectsForMap> um;
		
		um.insert(std::pair{ 1,ObjectsForMap(2,3.1) });
		//um.insert(std::pair{ 1,ObjectsForMap{2,3.1} });
		
		um.emplace(2, ObjectsForMap(3, 4.1));
		//um.emplace(1, ObjectsForMap{ 2,3.1 }));
		
		um.try_emplace(3,4,5.1);
		
		std::unordered_map<int, BigObject> umb;
		std::cout << "1" << std::endl;
		umb.emplace(1, BigObject(1000));

		std::cout << "2" << std::endl;
		umb.emplace(2, BigObject(1000));

		std::cout << "3" << std::endl;
		//1 Constr1 Copy1_to_2 Destr1; 2 Constr3 Copy3_to_4 Destr3; 3 Destr2 Destr4
	}

	void TryEmplace1()
	{
		std::unordered_map<int, BigObject> umb;
		
		std::cout << "1" << std::endl;
		
		BigObject bo1(1000);
		umb.emplace(1, bo1);
		//в мапу umb создаваемый объект приезжает по ссылке, а не по копии и копируется он только если объект действительно будет вставлен
		
		std::cout << "2" << std::endl;
		BigObject bo2(1000);
		umb.emplace(2, bo2);

		std::cout << "3" << std::endl;
		//1 Constr1 Copy1_to_2; 2 Constr3 Copy3_to_4; 3 Destr3 Destr1 Destr 2 Destr 4
	}

	void TryEmplace2()
	{
		std::unordered_map<int, BigObject> umb;
		std::cout << "1" << std::endl;
		umb.emplace(1, BigObject(1000));

		std::cout << "2" << std::endl;
		umb.emplace(1, BigObject(1000));

		std::cout << "3" << std::endl;
		//1 Constr1 FindPlaceInUmb=true Copy1_to_2 Destr1; 2 Constr3 FindPlaceInUmb=false Destr3; 3 Destr2
	}

	void TryEmplaceBestForProd()
	{
		std::unordered_map<int, BigObject> umb;
		std::cout << "1" << std::endl;
		umb.try_emplace(1, 1000);

		std::cout << "2" << std::endl;
		umb.try_emplace(1, 1000);

		std::cout << "3" << std::endl;
		//1, FindPlaceInUmb=true Constr1_in_UMB; 2 FindPlaceInUmb=false; 3 Destr1
	}

	int size = 1000000;
	int iterations_count = 20;
	int max_rand = 5;
	double tt1 = 0;
	double tt2 = 0;

	void TestEmplaces1()
	{
		srand(0);
		
		std::unordered_map<int, BigObject> umb;
		
		auto t1 = std::chrono::high_resolution_clock::now();
		
		for (int i = 0; i < iterations_count; i++)
		{
			umb.emplace(std::rand() % max_rand, BigObject(size));
		}
		
		auto t2 = std::chrono::high_resolution_clock::now();
		
		tt1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	}

	void TestEmplaces2()
	{
		srand(0);
		
		std::unordered_map<int, BigObject> umb;

		auto t1 = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < iterations_count; i++)
		{
			umb.try_emplace(std::rand() % max_rand, size);
		}

		auto t2 = std::chrono::high_resolution_clock::now();

		tt2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	}

	void Run2()
	{
		TestEmplaces1();
		std::cout << '2' << std::endl;
		TestEmplaces2();
		std::cout << tt1 / 1000000 << ' ' << tt2 / 1000000 << ' ' << tt1 / tt2 << std::endl;
		_getch();
		//TryEmplaceBestForProd();
	}

	void Extract()
	{
		std::unordered_map<int, BigObject> umb1;
		std::unordered_map<int, BigObject> umb2;

		std::cout << '1' << std::endl;
		umb1.try_emplace(1,1000);
		std::cout << '2' << std::endl;
		umb1.try_emplace(2,1000);
		std::cout << '3' << std::endl;

		umb2.insert(umb1.extract(2));
		
		std::cout << '4' << std::endl;
		umb1.erase(1);
		std::cout << '5' << std::endl;
		umb2.erase(2);
		std::cout << '6' << std::endl;
		//Constr1, Constr2, ReLink2_to_map2,Destr1,Destr2
	}

	void NoExtract()
	{
		std::unordered_map<int, BigObject> umb1;
		std::unordered_map<int, BigObject> umb2;

		std::cout << '1' << std::endl;
		umb1.try_emplace(1, 1000);
		umb1.try_emplace(1, 1000);
		std::cout << '2' << std::endl;
		umb1.try_emplace(2, 1000);
		std::cout << '3' << std::endl;

		auto it = umb1.find(2);
		umb2.emplace(2, it->second);
		umb1.erase(it);

		std::cout << '4' << std::endl;
		umb1.erase(1);
		std::cout << '5' << std::endl;
		umb2.erase(2);
		std::cout << '6' << std::endl;

		//Constr1, Constr2, CopyConstr2_to_3, Destr2, Destr1, Destr3
	}

	void Merge()
	{
		std::unordered_map<int, BigObject> umb1;
		std::unordered_map<int, BigObject> umb2;


	}

	void Run3()
	{
		//int a;
		//int b;
		////((std::cout << "1"), a) = ((std::cout << "2"), 2);
		//(std::cout << " 1 "), (std::cout << " 2 "), (std::cout << " 3 ");
		//((std::cout << " 1 "), (std::cout << " 2 ")), (std::cout << " 3 ");
		//(std::cout << " 1 "), ((std::cout << " 2 "), (std::cout << " 3 "));
		//
		//
		//
		////оператор запятая "," - пишется так:
		////{arg1},{arg2}
		////работает так:
		////сначала выполняется arg1, потом выполняется arg2, а потом все выражение превращается в результат arg2
		//(a = 3 + 4, (a > 4 ? a : b)) = 6;

		Extract();
		//Merge();

	}
}

namespace std
{
	template<>
	struct hash<STLUnorderedMap::BigObject>
	{
		std::size_t operator()(const STLUnorderedMap::BigObject& obj) const { return 0; }
	};

}

void TestTest()
{
	std::unordered_map<STLUnorderedMap::BigObject, int> umb1;
	umb1.emplace(1, 2);
	
	//STLUnorderedMap::BigObject b(1);
	//umb1.emplace(b, 2);
}

void TestTestTest(STLUnorderedMap::BigObject& bo)
{
	bo._a[0] = 4;
}

void TestTestTestTest(STLUnorderedMap::BigObject bo)
{
	bo._a[0] = 4;
}

void TestTestTest1(STLUnorderedMap::BigObject* bo)
{
	bo->_a[0] = 4;
}

void TestTestTest2(STLUnorderedMap::BigObject&& bo)
{
	STLUnorderedMap::BigObject bo1(bo);
	bo1._a[0] = 4;
}

STLUnorderedMap::BigObject TestReturnRv()
{
	STLUnorderedMap::BigObject bo(3);
	return bo;
}

STLUnorderedMap::BigObject TestReturnRvWithLvIn(STLUnorderedMap::BigObject& bo)
{
	return bo;
}

void TestTestTest3()
{
	STLUnorderedMap::BigObject bo1(5);
	STLUnorderedMap::BigObject bo(std::move(bo1));
	std::cout << bo1._n << std::endl;
}

void Test22()
{
	STLUnorderedMap::BigObject bo(3);
	std::cout << bo._a[0] << std::endl;


	std::cout << bo._a[0] << std::endl;
}

void Test11()
{
	int a = 10;
	int* p_a = &a;
	int& ref_a = a;

	*p_a = 15;
	ref_a = 20;

	int&& rv = 30;
	rv = 15;

	std::cout << rv;
}

//создать unmap и помимо расчета хэшфункции - загнать в мапу и замерять время. через функтор и функцию, лямбда не выйдет

/*
Сравнение бинарного поиска и хэш-таблицы по скорости поиска. Бинарный поиск работает за логарифм от количества элементов.
Например, в контейнере 1000 элементов, значит бин.поиск будет выполняться за логарифм от 1000 - 10 шагов - всегда!
Хэш-таблица - скорость поиска зависит от распределенности элементов, т.е. от того как хэш-функция равномерно выдает распределение,
т.е. коллизиогенность хэш-функции. Чем меньше коллизий - тем быстрее
Допустим, хэшфун на 1000 элементов выдает 100 бакетов, при этом в каждом в среднем по 10 элементов.
В этом случае - скорость тоже будет равна 10 шагам + скорость работы хэш-функции.
Если хэшфунк распределила на 500 бакетов, в которых в каждом по 2 элемента, тоже равномерно.
В этом случае - скорость будет равна 2 шагам + скорость работы хэш-функции.
Если хэшфунк распределила на 2 бакета, в которых в каждом по 500 элементов.
В этом случае - скорость будет равна 500 шагов + скорость работы хэш-функции.
*/

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
emplace_hint
*/