#pragma once
#include <iostream>
#include <cassert>

namespace StlString
{
	void OperatorSquare()
	{
		std::string str = "Hello"; //у стринги всегда в конце есть завершающий 0 - \0, но он невидим для size()
		assert(str.size() == 5);
		assert(str[0] == 'H');
		str[0] = 'G';
		assert(str[0] == 'G');
	}
	void at()
	{
		std::string str = "Hello"; //у стринги всегда в конце есть завершающий 0 - \0, но он невидим для size()
		assert(str.at(0) == 'H');
		str.at(0) = 'G';
		assert(str.at(0) == 'G');
		
		try
		{
			str.at(8) = 'i'; //при указании на ячейку памяти за границей массива at кидает исключение, которое можно поймать и вывести на экран
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
		str.push_back('1'); //добавляет только один элемент строки, т.е. 1 символ. в отличие от append-а, который может добавить целую строку
		assert(str == "Aa1");
		str.pop_back(); //убирает последний символ. только один.
		assert(str == "Aa");
		str.pop_back(); //убирает последний символ. только один.
		assert(str == "A");
		str.pop_back(); //убирает последний символ. только один.
		assert(str == "");//компилятор будет генерировать две строки для сравнения, хоть вторая и пустая, но компилятор будет генерить вторую строку
		assert(str.size() == 0);//компилятор будет генерировать 0 для сравнения со строкой, т.е. будет сравнение строки с числом
		assert(str.empty()); //для проверки на пустоту использовать только этот. Так как ничего лишнего не генерится.
	}

	void front_and_back()
	{
		std::string str = "Hello";
		assert(str.front() == 'H');
		assert(str.back() == 'o');
		//если вызвать front и back для пустой строки - будет UB!!
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
		//max_size возвращает вообще максимальный размер строки в байтах, который может позволить система, железо. Это не метод конкретного объекта.
		std::cout << str.max_size() << std::endl; 
		str.clear();
		assert(str.empty());
	}

	void insert()
	{
		std::string str = "Hello";
		str.insert(2, 1, '!'); //в какую позицию, сколько раз вставить, что вставить
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
		assert(std::stoi("334R") == 334); //sto считывает числа до символов. Увидит символ - прекратит считывание, но до символа считает
		
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
		//строка хелло
		//цикл. 100 раз сгенерить инт и если число четное, то всунуть его в конец стартовой строки, иначе в начало. При этом, разделив каждое число "_".
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
		//хелло
		//цикл 20 раз - на каждой итерации генерится число от 0 до 1, если 0 - то мы должны запушшить случайный символ в случайное место в строке, иначе удалить случайный символ
		std::string str = "Hello";

		for (int i = 0; i < 40; ++i)
		{
			int x = (rand() % 2);
			if (x == 0)
			{
				//str.insert(2, 1, '!'); //в какую позицию, сколько раз вставить, что вставить
				//str.insert(rand() % str.size(), 1, (char)(rand()% 255+1));
				str.insert(rand() % str.size(), 1, rand() % ('z' - 'a' + 1) + 'a');
				std::cout << str << std::endl;
			}
			else
			{
				str.erase(rand() % str.size(), 1);
				std::cout << str << std::endl;
			}
		}
	}

	void find()
	{
		std::string str = "Hello_world_all_strings";
		int i = str.find('_'); //возвращает индекс позиции, где найден символ. остановится на первом найденном
		assert(i == 5);
		
		i = str.find('?'); //если не нашел - вернет спец. константу npos
		assert(i == str.npos);

		assert(str.find_last_of('_') == 15); //ищет с конца, возвращает позицию найденного символа от начала строки 
		assert(str.find_last_of('?') == str.npos);
		assert(str.find_first_not_of('H') == 1); //ищет первое НЕСОВПАДЕНИЕ
		assert(str.find_last_not_of('s') == str.size()-2); //ищет первое НЕСОВПАДЕНИЕ
		
		
		assert(str.find("world") == 6);
		
		assert(str.find_first_of("ll") == 2);
		
		assert(str.find_last_of("ll") == 14);
		
		assert(str.rfind("ll") == 13);

		assert(str.find('l', 6) == 9);
	}

	void substr()
	{
		std::string str = "Hello_world_all_strings";
		std::string str2 = str.substr(6, 5); //начиная с 6 символа следующие 5 символов. Если не указать второй параметр - возьмет все до конца
		assert(str2 == "world");
		assert(str.substr(6) == "world_all_strings");
	}

	void Test3()
	{
		//тестовое задание
		//строка хелловорлд..стрингс
		//надо найти первую букву l последнюю букву l и вырезать (сделать подстроку) между ними, включая первую и последнюю l.
		//"Hello_world_all_strings" - "llo_world_all" . Не использовать константные указатели на позиции l.
		std::string str = "Hello_world_all_strings";
		std::cout << str.substr(str.find_first_of('l'), str.rfind('l') - str.find_first_of('l') + 1) << std::endl;
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
		Test3();
	}
	/*
	[]
	at
	Оператор =
	assign
	оператор+ 
	append, +=
	push_back, pop_back
	front, back
	size_lenght
	maxsize
	clear
	insert
	erase
	операторы сравнения
	sto
	to_string
	
	find
	substr
	starts with (20)
	ends with (20)
	contains (23)
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