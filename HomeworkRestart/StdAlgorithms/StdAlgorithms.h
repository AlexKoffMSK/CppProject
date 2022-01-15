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

	bool IsElemGreater5(int x)
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

	//ѕишет индексы начала кусков pattern в строке str
	//ѕример: str = "abc bc cbc cc" 
	//        pattern = "bc"
	void PrintMatchesOld(std::string str, std::string pattern)
	{
		assert(pattern.size() == 2);
		//бежим по исходной строке бер€ два символа и сравнива€ их с паттерном
		//если совпало - то вывод на экран индекс начала куска совпадени€
		//если не совпало - сдвигаемс€ на 1 элемент строки

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

	void PrintMatches(std::string str, std::string pattern)
	{
		assert(pattern.size() == 2);
		//бежим по строке до нахождени€ совпадений первого символа pattern и текущего символа в str
		//полученный индекс сохран€ем в переменную, с которой дальше начинаем по-парно сравнивать предыдущим методом

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

	void TestPrintMatches()
	{
		PrintMatches("ssssss aadsaa asar a abc safhaljhlskjhdf lasdlajh l lkahsl al jkh l bc cbc cc", "bc");
	}

}