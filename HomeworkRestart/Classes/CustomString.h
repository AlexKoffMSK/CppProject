#pragma once
#include <iostream>
#include <cassert>
#include <set>

using namespace std;


/*обычна€ стринга, может состо€ть только из символом латинского алфавита, но у неЄ будут дополнительные плюшки
1  огда сравниваем две кастомные стринги - игнорируем регистр
2 ѕо€витс€ дополнительный метод, который возвращает количество заглавных букв в строке
3 ѕо€витс€ принт, который печатает строку только в маленьком регистре
4 Ѕудет функци€, котора€ возвращает количество гласных букв в строке
*/

bool is_char_is_latin(char a)
{
	return (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z');
}

char to_lower_char(char a)
{
	if (a >= 'A' && a <= 'Z')
	{
		int num_of_ch_aph = a - 'A';
		return 'a' + num_of_ch_aph;
	}
}

bool is_vowel(char a)
{
	//std::set<char> vowels = { 'a','e','o','u','y' };
	//if (vowels.find(a)!=vowels.end())
	switch (to_lower_char(a))
	{
	case 'a': return true;
	case 'e': return true;
	case 'o': return true;
	case 'u': return true;
	case 'y': return true;
	}
	return false;
}

class CustomString
{
	string std_str;

public:

	CustomString(string str_)
	{
		for (char a : str_)
		{
			assert(is_char_is_latin(a));
		}
		std_str = str_;
	}
	
	friend bool operator==(CustomString custom_str0, CustomString custom_str1)
	{
		if (custom_str0.std_str.size() != custom_str1.std_str.size())
		{
			return false;
		}
		for (int i = 0; i < custom_str0.std_str.size(); i++)
		{
			if (to_lower_char(custom_str0.std_str[i]) != to_lower_char(custom_str1.std_str[i]))
			{
				return false;
			}
		}
		return true;
	}

	friend bool operator!=(CustomString custom_str0, CustomString custom_str1)
	{
		return !(custom_str0 == custom_str1);
	}
	
	int get_count_of_capitals()
	{
		int count_of_capitals = 0;

		for (char a : std_str)
		{
			if (a >= 'A' && a <= 'Z')
			{
				count_of_capitals++;
			}
		}
		
		return count_of_capitals;
	}

	void print_string_in_lower_case()
	{
		for (char a : std_str)
		{
			cout << to_lower_char(a);
		}
		cout << endl;
	}

	int get_count_of_vowels()
	{
		int count_of_vow = 0;
		for (char a : std_str)
		{
			if (is_vowel(a))
			{
				count_of_vow++;
			}
		}
		return count_of_vow;
	}

	int size_of_custom_str()
	{
		return std_str.size();
	}
};

void strf1()
{
	CustomString str1("Hello");
	CustomString str2("hello");
	CustomString str3("wOrLd");
	assert(str1 == str2);
	assert(str1 != str3);
	assert(str1.get_count_of_capitals() == 1);
	assert(str2.get_count_of_capitals() == 0);
	assert(str3.get_count_of_capitals() == 2);
	assert(str1.get_count_of_vowels() == 2);
	assert(str2.get_count_of_vowels() == 2);
	assert(str3.get_count_of_vowels() == 1);
	str1.print_string_in_lower_case();
	str2.print_string_in_lower_case();
	str3.print_string_in_lower_case();
	
	cout << str1.size_of_custom_str() << endl;
	
	//CustomString str4("Hello!"); //ожидаем, что будет выкинут assert
}