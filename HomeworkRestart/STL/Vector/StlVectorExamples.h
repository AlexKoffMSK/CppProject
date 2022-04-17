#pragma once
#include <iostream>
#include <vector>
#include <cassert>

namespace StlVector
{
	void push_back()
	{
		std::vector<int> vec;
		vec.push_back(5);
		std::cout << vec[0] << std::endl;

		vec.push_back(3);
		std::cout << vec[0] << ' ' << vec[1] << std::endl;
		assert(vec[0] == 5);
		assert(vec[1] == 3);

		vec.push_back(6);
		assert(vec[0] == 5);
		assert(vec[1] == 3);
		assert(vec[2] == 6);

		assert(vec.front() == 5);
		assert(vec.back() == 6);
	}

	void front_back()
	{
		std::vector<int> vec = { 5,2,3,1,9 };

		assert(vec.front() == 5);
		vec.front() = 10;
		assert(vec.front() == 10);

		assert(vec.back() == 9);
		vec.back() = 18;
		assert(vec.back() == 18);
	}

	void VectorOfStrings()
	{
		std::vector<std::string> vec;
		vec.push_back("asd");
		vec.push_back("sda");
		vec.push_back("das");

		assert(vec.front() == "asd");
		assert(vec[1] == "sda");
		assert(vec.back() == "das");

		vec.back()[1] = '!';

		std::string str = "ddd";
		str[0] = 'f';

		std::string& str1 = vec.back();
		str1[2] = '?';
		
		assert(vec.back() == "d!?");
		5; //это тип int. Если написать auto a = 5, то a будет иметь тип int
		5u;//unsigned int
		5l;//long
		5.; //double
		5.f;//float
		'5';//char
		"abs";//const char* - массив, символов, который нельзя изменять
		"abs"s;//string
	}

	void IterateOfAllElementsForAutoLoop()
	{
		std::vector<int> vec = { 5,3,7,3,4,7,3 };

		int i = 0;
		for (int a : vec)
		{
			assert(vec[i] == a);
			std::cout << a << std::endl;
			i++;
		}

		for (int& a : vec)
		{
			a++;
		}

		std::vector<int> vector_for_test = { 6,4,8,4,5,8,4 };

		for (int j =0; j<vec.size(); j++)
		{
			assert(vec[j] == vector_for_test[j]);
		}

	}

	//clear
	//emplace_back
	//pop_back
	//resize
	//reserve (*)
	//capacity (*)
	//итерирование через итераторы
	//insert & emplace
	//erase
	
	void clear()
	{
		std::vector<int> vec = { 5,3,7,3,4,7,3 };
		assert(vec.size() == 7);
		assert(!vec.empty());
		vec.clear();
		assert(vec.size() == 0);
		assert(vec.empty());
	}

	struct TestStruct
	{
		int _a;
		double _b;
		float f;

		TestStruct(int x_, double y_)
		{
			_a = x_;
			_b = y_;
		}
	};

	void emplace_back()
	{
		std::vector<TestStruct> vec;

		TestStruct ts(4, 6.8);
		vec.push_back(ts);

		vec.push_back(TestStruct{ 7,9.2 });// фигурные скобки позволяют выполнить агрегатную инициализацию полей объекта класса при условии, что поля открыты и независимо от наличия конструктора
		vec.push_back(TestStruct( 7,9.2 ));// круглые скобки делают то же самое но только при условии наличия конструктора

		vec.emplace_back(ts);
		vec.emplace_back(5, 8.2); //не будет работать если нет конструктора
		vec.emplace_back(TestStruct{ 3,1.29 }); //будет работать если нет конструктора
		vec.emplace_back(TestStruct( 2,44.2)); //круглые скобки более безопасные, т.к. проверяют наличие конструктора
	}

	void pop_back()
	{
		std::vector<int> vec = { 4,5,6 };
		assert(vec.size() == 3);
		assert(vec.back() == 6);
		
		vec.pop_back();
		assert(vec.size() == 2);
		assert(vec.back() == 5);
		
		vec.pop_back();
		assert(vec.size() == 1);
		assert(vec.back() == 4);
		
		vec.pop_back();
		assert(vec.empty());

		//vec.pop_back();
	}

	void resize()
	{
		std::vector<int> vec;
		assert(vec.size() == 0);

		vec.resize(10);
		assert(vec.size() == 10);
		for (int a : vec)
		{
			assert(a == 0);
			//std::cout << a << std::endl;
		}

		vec.clear();

		vec.resize(20, 5);
		for (int a : vec)
		{
			assert(a == 5);
			//std::cout << a << std::endl;
		}

		assert(vec.size() == 20);

		vec.resize(10); //удалятся последние 10 элементов
		assert(vec.size() == 10);

		vec.resize(20);
		assert(vec.size() == 20);

		for (int i = 0; i < 10; ++i)
		{
			assert(vec[i] == 5);
			assert(vec[i+10] == 0);
		}

		vec.resize(30, 7);
		for (int i = 0; i < 10; ++i)
		{
			assert(vec[i] == 5);
			assert(vec[i + 10] == 0);
			assert(vec[i + 20] == 7);
		}
	}

	void IteratorsIterate()
	{
		std::vector<int> vec = { 5,7,5,3,7,4,3 };

		//for (           int i =0;  i < vec.size(); ++i)
		int i = 0;
		for (auto it = vec.begin(); it != vec.end(); ++it) //vec.end() - это итератор, который не смотрит ни на один элемент контейнера
		{
			assert(*it == vec[i]);
			std::cout << *it << std::endl;
			i++;
		}
		i--;
		for (auto reverse_it = vec.rbegin(); reverse_it != vec.rend(); ++reverse_it)
		{
			assert(*reverse_it == vec[i]);
			std::cout << *reverse_it << std::endl;
			i--;
		}
	}

	void IteratorsExample1()
	{
		std::vector<int> vec = { 5,7,89,3,4,5};
		std::vector<int>::iterator it = vec.begin(); //begin() возвращает итератор! и end() тоже.
		assert(*it == 5);

		it++;
		assert(*it == 7);

		it--;
		assert(*it == 5);

		it+=3;
		assert(*it == 3);

		it++;
		assert(*it == 4);

		it++;
		assert(*it == 5);

		it++;
		assert(it == vec.end());
	}









	void CheckAll()
	{
		push_back();
		front_back();
		VectorOfStrings();
		IterateOfAllElementsForAutoLoop();
		emplace_back();
		pop_back();
		resize();
		IteratorsIterate();
		IteratorsExample1();











	}

}