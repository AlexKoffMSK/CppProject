#pragma once
#include <iostream>
#include <cassert>
#include <vector>

namespace StlString
{
	void OperatorSquare()
	{
		std::string str = "Hello"; //� ������� ������ � ����� ���� ����������� 0 - \0, �� �� ������� ��� size()
		assert(str.size() == 5);
		assert(str[0] == 'H');
		str[0] = 'G';
		assert(str[0] == 'G');
	}
	void at()
	{
		std::string str = "Hello"; //� ������� ������ � ����� ���� ����������� 0 - \0, �� �� ������� ��� size()
		assert(str.at(0) == 'H');
		str.at(0) = 'G';
		assert(str.at(0) == 'G');
		
		try
		{
			str.at(8) = 'i'; //��� �������� �� ������ ������ �� �������� ������� at ������ ����������, ������� ����� ������� � ������� �� �����
		}
		catch(std::exception exc)
		{
			std::cout << exc.what() << std::endl;
		}

	}

	void assign()
	{
		std::string str;
		str.assign("Hello");
		assert(str == "Hello");
		str = "World";
		assert(str == "World");
	}

	void OperatorPlus()
	{
		std::string str0 = "Hello";
		std::string str1 = "World";
		std::string str2 = "Again";
		std::string str = str0 + str1 + str2;
		assert(str == "HelloWorldAgain");

		std::string str3 = str0 + "__!__" + str1 + "***@@@" + str2 + "^^^";
		assert(str3 == "Hello__!__World***@@@Again^^^");
	}

	void append()
	{
		std::string str = "Hola";
		str.append("Bonita");
		assert(str == "HolaBonita");

		str += "Mucho";
		assert(str == "HolaBonitaMucho");
	}

	void push_back_and_pop_back()
	{
		std::string str = "Aa";
		str.push_back('1'); //��������� ������ ���� ������� ������, �.�. 1 ������. � ������� �� append-�, ������� ����� �������� ����� ������
		assert(str == "Aa1");
		str.pop_back(); //������� ��������� ������. ������ ����.
		assert(str == "Aa");
		str.pop_back(); //������� ��������� ������. ������ ����.
		assert(str == "A");
		str.pop_back(); //������� ��������� ������. ������ ����.
		assert(str == "");//���������� ����� ������������ ��� ������ ��� ���������, ���� ������ � ������, �� ���������� ����� �������� ������ ������
		assert(str.size() == 0);//���������� ����� ������������ 0 ��� ��������� �� �������, �.�. ����� ��������� ������ � ������
		assert(str.empty()); //��� �������� �� ������� ������������ ������ ����. ��� ��� ������ ������� �� ���������.
	}

	void front_and_back()
	{
		std::string str = "Hello";
		assert(str.front() == 'H');
		assert(str.back() == 'o');
		//���� ������� front � back ��� ������ ������ - ����� UB!!
		str.front() = 'K';
		str.back() = 'y';
		assert(str == "Kelly");
	}

	void size_and_lenght()
	{
		std::string str = "Hello";
		assert(str.size() == 5);
		assert(str.length() == 5);
	}

	void max_size_and_clear()
	{
		std::string str = "Hello";
		//max_size ���������� ������ ������������ ������ ������ � ������, ������� ����� ��������� �������, ������. ��� �� ����� ����������� �������.
		std::cout << str.max_size() << std::endl; 
		str.clear();
		assert(str.empty());
	}

	void insert()
	{
		std::string str = "Hello";
		str.insert(2, 1, '!'); //� ����� �������, ������� ��� ��������, ��� ��������
		assert(str == "He!llo");
		
		str.insert(5, 2, '?');
		assert(str == "He!ll??o");
		
		str.insert(0, "World");
		assert(str == "WorldHe!ll??o");
	}
	void erase()
	{
		std::string str = "WorldHe!ll??o";
		
		str.erase(7,1);
		assert(str == "WorldHell??o");
		
		str.erase(9, 2);
		assert(str == "WorldHello");
		
		str.erase(0, 5);
		assert(str == "Hello");

		str.erase(2);
		assert(str == "He");
	}

	void compare_operators()
	{
		std::vector<std::string> vec_s =
		{
			"aaa", //!
			"aab", //!
			"aba", //!
			"baa", //!
			"bab", //!
			"abc", //!
			"cab", //!
			"bbb", //!
			"abb", //!
			"aaaa", //!
			"bb" //!
		};

		std::sort(vec_s.begin(), vec_s.end());

		assert(vec_s[0] == "aaa");
		assert(vec_s[1] == "aaaa"); 
		assert(vec_s[2] == "aab"); 
		assert(vec_s[3] == "aba"); 
		assert(vec_s[4] == "abb"); 
		assert(vec_s[5] == "abc"); 
		assert(vec_s[6] == "baa"); 
		assert(vec_s[7] == "bab"); 
		assert(vec_s[8] == "bb"); 
		assert(vec_s[9] == "bbb"); 
		assert(vec_s[10] == "cab"); 

	}

	void sto()
	{
		std::string str = "123";
		assert(std::stoi(str) == 123);
		assert(std::stoll("23223049820938980") == 23223049820938980LL);
		assert(std::stod("234432.432") == 234432.432);
		assert(std::stoi("-42234") == -42234);
		assert(std::stoi("334R") == 334); //sto ��������� ����� �� ��������. ������ ������ - ��������� ����������, �� �� ������� �������
		
		try
		{
			int i = std::stoi("R334");
		}
		catch (std::exception exc)
		{
			std::cout << exc.what() << std::endl;
		}
		
		size_t pos = 0;

		assert(std::stoi("101rty", &pos, 2) == 5);
		assert(pos == 3);

		assert(std::stoll("123ACE12Fuououo",&pos, 16) == 4893499695LL);
		assert(pos == 9);
	}
	 
	void to_string()
	{
		assert(std::to_string(123) == "123");
		assert(std::to_string(23223049820938980LL) == "23223049820938980");
		assert(std::to_string(234432.432) == "234432.432000");
		assert(std::to_string(-42234) == "-42234");
	}

	void Test1()
	{
		//������ �����
		//����. 100 ��� ��������� ��� � ���� ����� ������, �� ������� ��� � ����� ��������� ������, ����� � ������. ��� ����, �������� ������ ����� "_".
		//3_5_1_Hello_6_2_4

		std::string str = "Hello";

		for (int i = 0; i < 10; ++i)
		{
			int x = (rand() % 10);
			if (x % 2 == 0)
			{
				//str.append("_");
				//str.append(std::to_string(x));
				
				str += '_' + std::to_string(x);
				
				std::cout << str << std::endl;
			}
			else
			{
				//str.insert(0, 1, '_');
				//str.insert(0, std::to_string(x));
				
				str.insert(0, (std::to_string(x) + '_'));

				std::cout << str << std::endl;
			}
		}
		std::cout << str << std::endl;
	}

	void Test2()
	{
		//�����
		//���� 20 ��� - �� ������ �������� ��������� ����� �� 0 �� 1, ���� 0 - �� �� ������ �������� ��������� ������ � ��������� ����� � ������, ����� ������� ��������� ������
		std::string str = "Hello";

		for (int i = 0; i < 40; ++i)
		{
			int x = (rand() % 2);
			if (x == 0)
			{
				if (str.empty())
				{
					str.insert(0,1,rand() % ('z' - 'a' + 1) + 'a');
				}
				else
				{
					//str.insert(2, 1, '!'); //� ����� �������, ������� ��� ��������, ��� ��������
					//str.insert(rand() % str.size(), 1, (char)(rand()% 255+1));
					str.insert(rand() % str.size(), 1, rand() % ('z' - 'a' + 1) + 'a');
					std::cout << str << std::endl;
				}
			}
			else
			{
				if (!str.empty())
				{
					str.erase(rand() % str.size(), 1);
					std::cout << str << std::endl;
				}
			}
		}
	}

	void find()
	{
		std::string str = "Hello_world_all_strings";
		int i = str.find('_'); //���������� ������ �������, ��� ������ ������. ����������� �� ������ ���������
		assert(i == 5);
		
		i = str.find('?'); //���� �� ����� - ������ ����. ��������� npos
		assert(i == str.npos);

		assert(str.find_last_of('_') == 15); //���� � �����, ���������� ������� ���������� ������� �� ������ ������ 
		assert(str.find_last_of('?') == str.npos);
		assert(str.find_first_not_of('H') == 1); //���� ������ ������������
		assert(str.find_last_not_of('s') == str.size()-2); //���� ������ ������������
		
		
		assert(str.find("world") == 6);
		
		assert(str.find_first_of("ll") == 2);
		
		assert(str.find_last_of("ll") == 14);
		
		assert(str.rfind("ll") == 13);

		assert(str.find('l', 6) == 9);
	}

	void substr()
	{
		std::string str = "Hello_world_all_strings";
		std::string str2 = str.substr(6, 5); //������� � 6 ������� ��������� 5 ��������. ���� �� ������� ������ �������� - ������� ��� �� �����
		assert(str2 == "world");
		assert(str.substr(6) == "world_all_strings");
	}

	void Test3()
	{
		//�������� �������
		//������ ����������..�������
		//���� ����� ������ ����� l ��������� ����� l � �������� (������� ���������) ����� ����, ������� ������ � ��������� l.
		//"Hello_world_all_strings" - "llo_world_all" . �� ������������ ����������� ��������� �� ������� l.
		std::string str = "Hello_world_all_strings";
		std::cout << str.substr(str.find_first_of('l'), str.rfind('l') - str.find_first_of('l') + 1) << std::endl;
	}
	
	void starts_with()
	{
		//starts_with() ���������� bool, ���������� ������ �����
		std::string str = "Hello_world_all_strings";
		assert(str.starts_with("Hello"));
		assert(!str.starts_with("Hello1"));
	}

	void ends_with()
	{
		std::string str = "Hello_world_all_strings";
		assert(str.ends_with("strings"));
		assert(!str.ends_with("atrings"));
	}

	void replace_by_characters()
	{
		std::string str = "Hello_world_all_strings";
		str.replace(6, 5, 2, '?'); 
		//������ ��� - �������� � �������� ������ ������ ������ ������, ������ - ������� �������� ��������, ��������� ��� - ��� = �� ��� �������� - 
		//� ������� ������ - �������� ����� world �� 2 ����� �������. ������� ������ �������� ������.
		//std::cout << str << std::endl;
		assert(str == "Hello_??_all_strings");

		str = "Hello_world_all_strings";
		str.replace(12, 3, 3, '?');
		assert(str == "Hello_world_???_strings");

		str = "Hello_world_all_strings";
		str.replace(12, 3, 5, '?');
		assert(str == "Hello_world_?????_strings");
	}

	void replace_by_string()
	{
		std::string str = "Hello_world_all_strings";
		str.replace(6, 5, "strin");
		assert(str == "Hello_strin_all_strings");
		
		str = "Hello_world_all_strings";
		str.replace(6, 5, "string");
		assert(str == "Hello_string_all_strings");

		str = "Hello_world_all_strings";
		str.replace(6, 5, "str");
		assert(str == "Hello_str_all_strings");

		str = "Hello_world_all_strings";
		str.replace(6, 5, "string",3); //������� ������� �� ������� ������� ������ 3 �������
		assert(str == "Hello_str_all_strings");

		std::string pattern = "strings";

		str = "Hello_world_all_strings";
		str.replace(6, 5, pattern,2,3);
		assert(str == "Hello_rin_all_strings");

		str = "Hello_world_all_strings";
		str.replace(6, 5, pattern);
		assert(str == "Hello_strings_all_strings");
	}

	void iteratorsIterate()
	{
		std::string str = "Hello_world_all_strings";

		for (auto it = str.begin(); it != str.end(); ++it)
		{
			std::cout << *it;
		}

		std::cout << std::endl;

		for (int i = 0; i < str.size(); ++i)
		{
			std::cout << str[i];
		}

		std::cout << std::endl;

		for (auto ch : str)
		{
			std::cout << ch;
		}

		std::cout << std::endl;
	}

	void IteratorsTest()
	{
		std::string str = "Hello_world_all_strings";
		auto it = str.begin();
		it += 3;
		assert(*it == 'l');
		it -= 2;
		assert(*it == 'e');
	}

	bool IsCharEquals_l(char ch)
	{
		std::cout << '!' << ch << std::endl;
		return ch == 'l';
	}

	void erase_if()
	{
		std::string str = "Hello_world_all_strings";
		std::cout << "Start" << std::endl;
		std::erase_if(str, IsCharEquals_l);
		std::cout << "End" << std::endl;
		assert(str == "Heo_word_a_strings");
	}

	void Test4()
	{
		std::string str = "Hello_world_all_strings";
		//������� �� ��� ������, ������� ����������� ������ ���� ���������
		std::string str_sorted = str;
		
		//���������� - ����� ������������ ����� ���������� ������������������ � ���������������� �������.
		std::sort(str_sorted.begin(), str_sorted.end());
		//H___adegilllllnoorrsstw
		int amount = 1;										   
		int cur_max=1;										   
		char ch = str_sorted[0];							   
															   
		for (int i = 1; i < str_sorted.size(); ++i)			   
		{													   
			if (str_sorted[i] == str_sorted[i - 1])			   
			{												   
				amount++;									   
				if (amount > cur_max)						   
				{											   
					cur_max = amount;						   
					ch = str_sorted[i];						   
				}											   
			}												   
			else											   
			{												   
				amount = 1;									   
			}												   
		}
		std::erase_if(str, [ch](char cha) {return cha == ch; });
		std::cout << str << std::endl;
	}

	void Test4Short()
	{
		std::string str = "Hello_world_all_strings";
		std::map<char, int> mch;
		int max_amount=1;
		char max_char;
		for (auto ch : str)
		{
			mch[ch]++;
			if (mch[ch] > max_amount)
			{
				max_amount = mch[ch];
				max_char = ch;
			}
		}
		std::cout << max_char << '-' << max_amount << std::endl;
		std::erase_if(str, [max_char](char cha) {return cha == max_char; });
		std::cout << str << std::endl;
	}

	void compare()
	{
		std::string str = "Hello_world_all_strings";
		std::cout << str.compare(6, 5, "wprld") << std::endl;
		assert(str.compare(6, 5, "wprld") < 0);//������ ������ - str - ������ ������ "wprld", ������� ������������� �����
		assert(str.compare(6, 5, "world") == 0);//������ ������ - str - ����� ������ "world", ������� 0
		assert(str.compare(6, 5, "warld") > 0); //������ ������ - str - ������ ������ "warld", ������� ������������� �����

		assert(str.compare(6, 3, "wor!!", 3) == 0);

		assert(str.compare("Hello_world_all_strings") == 0);
		assert(str.compare("Hella_world_all_strings") > 0);
		assert(str.compare("Hyllo_world_all_strings") < 0);
	}

	void copy()
	{
		std::string str = "Hello_world_all_strings";
		
		char arr[10];
		
		str.copy(arr, 5, 6);
		
		std::cout << arr << std::endl;
	}

	void resize()
	{
		std::string str = "Hello";
		assert(str.size() == 5);

		str.resize(2);
		assert(str == "He");

		str.resize(7,'t');
		assert(str.size() == 7);
		assert(str == "Hettttt");
	}

	void TestAll()
	{
		//OperatorSquare();
		//at();
		//assign();
		//OperatorPlus();
		//append();
		//push_back_and_pop_back();
		//front_and_back();
		//size_and_lenght();
		//max_size_and_clear();
		//insert();
		//erase();
		//compare_operators();
		//sto();
		//to_string();
		//Test2();
		//find();
		//substr();
		//Test3();
		//starts_with();
		//ends_with();
		//replace_by_characters();
		//replace_by_string();
		//iteratorsIterate();
		//IteratorsTest();
		//erase_if();
		//Test4();
		//Test4Short();
		//compare();
		//copy();
		resize();
	}
	/*
	[]
	at
	�������� =
	assign
	��������+ 
	append, +=
	push_back, pop_back
	front, back
	size_lenght
	maxsize
	clear
	insert
	erase
	��������� ���������
	sto
	to_string
	
	find
	substr
	starts with (20)
	ends with (20)
	contains (23) - ��� � ������
	replace
	iterators
	erase_if (20)
	compare
	copy
	resize
	
	data
	c_str
	reserve
	capacity
	shrink to fit
	literal
	*/

}