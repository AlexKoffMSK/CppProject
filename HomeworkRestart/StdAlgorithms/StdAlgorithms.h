#pragma once
#include <iostream>
#include <vector>

namespace StdAlgorithms
{
	void Test1(int x)
	{
		std::vector<int> vec{ 4,3,6,5,7,8,9,0 };
		auto iterator = std::find(vec.begin(), vec.end(), x);
		
		if (iterator == vec.end())
		{
			std::cout << "Not found" << std::endl;
		}
		else
		{
			std::cout << "Found: " << iterator-vec.begin() << std::endl;
		}
	}

	bool IsElemGreater5(int x) //Это предикат. Предикат - это функция, которая принимает объект и возвращает bool
	{
		return x > 5;
	}

	void Test2()
	{
		//std::vector<int> vec{ 4,3,6,5,7,8,9,0 };
		std::set<int> set{ 4,3,6,5,7,8,9,0 };
		//auto iterator = std::find_if(vec.begin(), vec.end(),IsElemGreater5);
		auto iterator = std::find_if(set.begin(), set.end(), [](int x) {return x > 5; });
		
		if (iterator == set.end())
		{
			std::cout << "Not found" << std::endl;
		}
		else
		{
			//std::cout << "Found: " << iterator - set.begin() << std::endl;
			std::cout << "Found: " << std::endl;
		}
	}

	void Test3()
	{
		std::vector<int> vec{ 4,3,6,5,7,8,9,0 };
		//std::partition(vec.begin(), vec.end(), [](int x) {return x < 5; });
		//std::stable_partition(vec.begin(), vec.end(), [](int x) {return x < 5; });
		std::stable_partition(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; });
		//перегруппировывает значения контейнера так, что в первой половине - элементы удовлетворяющие предикату, во второй - неудовлетворяющие
		print_vector(vec);
	}

	void Test4()
	{
		struct Student
		{
			std::string _name;
			int _age;
		};

		std::vector<Student> studs;
		studs.push_back(Student{ "AA",4 });
		studs.push_back(Student{ "BA",5 });
		studs.push_back(Student{ "AB",3 });
		studs.push_back(Student{ "BB",7 });

		std::stable_partition(studs.begin(), studs.end(), [](Student students) {return students._name.front() == 'A'; });

		for (auto sts : studs)
		{
			std::cout << sts._age << '|' << sts._name << std::endl;
		}

		auto iterator = std::find_if(studs.begin(), studs.end(), [](Student students) {return students._age > 5; });
		if (iterator == studs.end())
		{
			std::cout << "Not Found" << std::endl;
		}
		else
		{
			std::cout << iterator->_name << std::endl;
		}
	}

	void ReverseString(std::string str)
	{
		for (int i = 0; i < str.size()/2; ++i)
		{
			std::swap(str[i], str[str.size()- 1 - i]);
		}
	}

	//Пишет индексы начала кусков pattern в строке str
	//Пример: str = "abc bc cbc cc" 
	//        pattern = "bc"
	void PrintMatchesOld(std::string str, std::string pattern)
	{
		assert(pattern.size() == 2);
		//бежим по исходной строке беря два символа и сравнивая их с паттерном
		//если совпало - то вывод на экран индекс начала куска совпадения
		//если не совпало - сдвигаемся на 1 элемент строки

		for (int i = 0; i < str.size()-1; ++i)
		{
			if (str.substr(i, 2) == pattern)
			{
				std::cout << i << std::endl;
			}
			//if (str[i] == pattern[0] && str[i + 1] == pattern[1])
			//{
			//	std::cout << i << std::endl;
			//}
		}
	}

	void PrintMatchesPattern2Chars(std::string str, std::string pattern)
	{
		assert(pattern.size() == 2);
		//бежим по строке до нахождения совпадений первого символа pattern и текущего символа в str
		//полученный индекс сохраняем в переменную, с которой дальше начинаем по-парно сравнивать предыдущим методом

		for (int i = 0; i < str.size() - 1; ++i)
		{
			if (str[i] == pattern[0])
			{
				if (str[i+1] == pattern[1])
				{
					std::cout << i << std::endl;
				}
			}
		}
	}

	void PrintMatchesWithFor(std::string str, std::string pattern)
	{
		for (int i = 0; i < str.size() - (pattern.size()-1); ++i)
		{
			//if (str.substr(i, pattern.size()) == pattern)
			//{
			//	std::cout << i << std::endl;
			//}

			int char_matches_count = 0;
			int k = i;

			for (int j = 0; j < pattern.size(); ++j)
			{
				if (pattern[j] == str[k])
				{
					char_matches_count++;
					k++;
				}
				else
				{
					char_matches_count = 0;
				}
			}

			if (char_matches_count == pattern.size())
			{
				std::cout << k - pattern.size() << std::endl;
				std::cout << i << std::endl;
				i += (pattern.size()-1);
			}
		}
	}

	void PrintMatchesWith_K(std::string str, std::string pattern)
	{
		int i = 0;
		while (i != str.size())
		{
			int k = i;
			int char_matches_count = 0;
			for (int j = 0; j < pattern.size(); ++j)
			{
				if (pattern[j] == str[k])
				{
					char_matches_count++;
					k++;
				}
				else
				{
					char_matches_count = 0;
				}
			}
			if (char_matches_count == pattern.size())
			{
				std::cout << i << std::endl;
				i += (pattern.size());
			}
			else
			{
				i++;
			}
		}
	}

	void PrintMatches(std::string str, std::string pattern)
	{
		int i = 0;
		while (i < str.size()- (pattern.size()-1))
		{
			bool is_all_matches = true;
			for (int j = 0; j < pattern.size(); ++j)
			{
				if (pattern[j] != str[i])
				{
					is_all_matches = false;
				}
				i++;
			}
			if (is_all_matches)
			{
				std::cout << i - pattern.size() << std::endl;
				//i -= (pattern.size() - 1); //тогда сравнение будет внахлест
			}
			else
			{
				i-= (pattern.size()-1);
			}
		}
	}

	// abbbba
	// bb

	void FindLenghtOfEqualSequences()
	{
		std::vector<int> vec = { 1,1,2,2,2,3,3 };
		int sequence_of_match = 0;
		int max_count_of_matches = 0;
		int count_of_matches = 0;
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] == vec[i - 1])
			{
				count_of_matches++;
				if (count_of_matches > max_count_of_matches)
				{
					max_count_of_matches = count_of_matches;
					sequence_of_match = i;
				}
			}
			else
			{
				count_of_matches = 0;
			}
		}
		std::cout << max_count_of_matches+1 << std::endl;
		std::cout << vec[sequence_of_match] << std::endl;
	}

	void RemoveNegativeFromArrayWithSort(std::vector<int>& vec)
	{
		std::sort(vec.begin(), vec.end());
		auto iterator = std::find_if(vec.begin(), vec.end(), [](int x) {return x >= 0; });
		vec.erase(vec.begin(), iterator);
	}

	void RemoveNegativeFromArrayNoSort(std::vector<int>& vec)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < 0)
			{
				vec.erase(vec.begin()+i);
				//vec.erase(std::find(vec.begin(),vec.end(),4));
				--i;
			}
		}
		//vec.erase(vec.begin(), iterator);
		//print_vector(vec);
	}


	void TestVecRemoves()
	{
		std::vector<int> vec;
		for (int i = 0; i < 1000000; ++i)
		{
			vec.push_back(std::rand() % 20 - 10);
		}

		auto begin = std::chrono::steady_clock::now();
		//RemoveNegativeFromArrayWithSort(vec);
		RemoveNegativeFromArrayNoSort(vec);
		auto end = std::chrono::steady_clock::now();

		std::cout << vec[5] << std::endl;

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "The time: " << elapsed_ms.count() << " ms\n";

	}

	void TestPrintMatches()
	{
		PrintMatches("abbbbbba", "bbb");
	}










}