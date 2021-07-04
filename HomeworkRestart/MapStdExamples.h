#pragma once
#include <iostream>
#include <map>
#include <set>
#include "Functions.h"

namespace MapStdExamples
{
	void Example1()
	{
		std::map<int, int> m;
		m[3] = 15;
		m[4] = -1;
		m[15] = 129;

		cout << m[3] << ' ' << m[4] << ' ' << m[15] << endl;
	}

	void Example2()
	{
		std::map<int, int> m;
		m[3] = 15;
		m[3] = 20;
		m[3]++;
		m[3]++;

		cout << m[3] << endl;
	}

	void Example3()
	{
		std::map<int, int> m;
		m[3] = 15;
		m[4] = -1;
		m[15] = 129;

		m.erase(4);

		cout << m[3] << ' ' << m[4] << ' ' << m[15] << endl;
	}

	void Example4()
	{
		std::map<int, int> m;
		m[3] = 15;
		m[4] = -1;
		m[15] = 129;

		for (auto [key, value] : m)
		{
			cout << key << ' ' << value << ' ' << endl;
		}
	}

	void Example5()
	{
		const int n = 20;
		int arr[n];
		std::map<int, int> m;

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
			cout << arr[i] << ' ';
			m[arr[i]]++;
		}
		
		std::cout << endl;

		int cur_max_key = m.begin()->first;
		int cur_max_value = m.begin()->second;
		for (auto [key, value] : m)
		{
			if (value > cur_max_value)
			{
				cur_max_value = value;
				cur_max_key = key;
			}
		}
			cout << cur_max_key << ' ' << cur_max_value << ' ' << endl;
	}

	void Example6()
	{
		std::map<int, int> m;
		int n=10;
		for (int i = 1; i <= n; i++)
		{
			m[i] = i + 1;
			cout << m[i] << endl;
		}
	}

	void Example7()
	{
		std::map<int, int> m;
		int n = 10;
		int rnd_num_a = 0;
		
		for (int i = 0; i < n; i++)
		{
			rnd_num_a = rand() % 2;
			
			cout << rnd_num_a << endl;
			
			m[i] = rnd_num_a;
			
			cout << i << ' ' << rnd_num_a << endl;
			
			for (int j = 0; j < i; j++) //m.size()?
			{
				if (m[j] == rnd_num_a)
				{
					cout << "Dumplicate {a}" << endl;
				}
			}
		}
	}

	void Example7_1()
	{
		std::map<int, int> m;
		int n = 10;
		int rnd_num_a = 0;

		for (int i = 0; i < n; i++)
		{
			rnd_num_a = rand() % 10;
			cout << rnd_num_a << ' ' << m.size() << endl;
			if (m[rnd_num_a] != 0)
			{
				cout << "Dumplicate {a}" << endl;
			}
			m[rnd_num_a] = 1;
			cout << m.size() << endl;
		}
	}

	void Example7_2()
	{
		std::map<int, int> m;
		vector<int> vec;

		vec.push_back(10);
		vec.push_back(200);
		vec.push_back(200);
		vec.push_back(10);
		vec.push_back(200);

		m[10] = 1;
		m[200] = 2;
		m[200] = 0;
		m[10] = 4;
		m[200] = 5;

		cout << vec.size() << ' ' << m.size() <<endl;

	}

	void Example7_3()
	{
		std::set<int> s;
		int n = 10;
		int rnd_num_a = 0;

		for (int i = 0; i < n; i++)
		{
			rnd_num_a = rand() % 10;
			
			if (s.find(rnd_num_a) != s.end())
			{
				cout << "Dumplicate {a}" << endl;
			}
			s.insert(rnd_num_a);
		}
	}

	void Example8()
	{
		//3. Создать мапу <int, int>.Вводить числа, пока не введем 0.
		//	Вывести количество уникальных чисел, которые были введены.
		//	(Подсказка: у мапы есть метод size()).
		//	Например, ввели: 5 3 7 4 4 3 3 5 5 0.
		//	Ответ : 4, т.к.уникальных чисел тут 4(3 4 5 7)
		std::set<int> s;
		int a;

		while (true)
		{
			cin >> a;
			if (a == 0)
			{
				break;
			}
			s.insert(a);

			cout << s.size() << endl;
		}
	}

	void CountOfAppereanceElemsInVector()
	{
		std::vector<int> vec;
		int n = 10;
		std::map<int, int> m;

		for (int i = 0; i < n; i++)
		{
			vec.push_back(rand() % 10);
			cout << vec.back() << endl;
			m[vec.back()]++;
			PrintMap(m);
		}
	}

	void CountOfAppereanceCharsInString()
	{
		std::string s;
		s = "Hello world";
		std::map<char, int> m;
		for (char ch : s)
		{
			m[ch]++;
			PrintMap(m);
		}
	}

	void ReplaceChars()
	{
		std::string s;
		s = "Hello world!";
		//вывести на экран строку, но l заменить на нижнее подчеркивание
		//l - _
		//  - !
		//H - h
		std::map<char, char> m;
		m['l'] = '_';
		m[' '] = '!';
		m['H'] = 'h';
		for (char ch : s)
		{
			if (m.find(ch) != m.end())
			{
				cout << m[ch];
			}
			else
			{
				cout << ch;
			}
		}
	}

	void ReplaceCharsAdv()
	{
		std::string s;
		s = "Hello world!";
		//вывести на экран строку, но l заменить на нижнее подчеркивание
		//l - _
		//  - !
		//H - h
		std::map<char, char> m;
		for (int i = 0; i < 256; i++)
		{
			m[i] = i;
		}

		m['l'] = '_';
		m[' '] = '!';
		m['H'] = 'h';
		
		PrintMap(m);
		
		for (char ch : s)
		{
			cout << m[ch];
		}
	}

	void CountOfWords()
	{
		//человек вводит слова через пробел, завершает строку словом "!".
		//вывести на экран сколько раз встречалось каждое слово
		//Hello world hello a a world !

		std::string s;
		std::map<string, int> m;
		while (true)
		{
			cin >> s;
			if (s == "!")
			{
				break;
			}
			m[s]++;
			PrintMap(m);
		}
	}
}
