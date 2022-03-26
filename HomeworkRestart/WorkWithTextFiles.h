#pragma once
#include <iostream>
#include <fstream>
#include "GlobalStructures.h"
#include <map>
#include <string>
#include <vector>

namespace WorkWithTextFiles
{
	//void ExampleRead1()
	//{
	//	std::ifstream ifs("TextFiles/File1.txt");
	//	if (!ifs.is_open())
	//	{
	//		std::cout << "File not found!" << std::endl;
	//		return;
	//	}

	//	std::string s;
	//	ifs >> s; 
	//	//из файла первое слово (до пробела) в переменную s. —читали первое слово, подвинули курсор. 
	//	//—читывает до пробельного символа (пробел, табул€ци€, переход на новую строку)
	//	cout << s << endl;
	//	ifs >> s; //из файла второе слово (до пробела) в переменную s
	//	cout << s << endl;
	//}

	void ExampleRead11()
	{
		std::string str;
		
		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		int counter = 0;
		for (int i = 0; i < 30; ++i)
		{
			char ch;
			ch = ifs.get();
			if (ch == ' ')
			{
				counter++;
			}
		}
	}

	void StringToWordsByBUKVYWithMap()
	{
		std::map<int, std::string> decomposed_str;
		std::string str;

		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		std::getline(ifs,str);
		std::cout << str;

		int word_start_pos=0;

		for (int i = 0; i < str.size(); ++i)
		{
			if (i == 0 && str[i] != ' ')
			{
				word_start_pos = i;
			}
			if (i>0 && str[i - 1] == ' ' && str[i] != ' ')
			{
				word_start_pos = i;
			}
			if (str[i] != ' ')
			{
			decomposed_str[word_start_pos] += str[i];
			}
		}

		for (auto [key, value] : decomposed_str)
		{
			std::cout << key << '-' << '[' << value << ']' << std::endl;
		}
	}

	void StringToWordsByBUKVYWithVector()
	{
		std::vector<std::string> vec;
		std::string str;

		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		std::getline(ifs, str);
		std::cout << str;

		for (int i = 0; i < str.size(); ++i)
		{
			if (i == 0 && str[i] != ' ')
			{
				vec.emplace_back();
				//vec.back() += str[i];
			}
			if (i > 0 && str[i - 1] == ' ' && str[i] != ' ')
			{
				vec.emplace_back();
				//vec.back() += str[i];
			}
			if (str[i] != ' ')
			{
				vec.back() += str[i];
			}
		}

		for (auto value : vec)
		{
			std::cout << '[' << value << ']' << std::endl;
		}
	}

	void StringToWordsByBUKVYWithVector1()
	{
		std::vector<std::string> vec;
		std::string str;

		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		std::getline(ifs, str);
		std::cout << str << std::endl;

		vec.emplace_back();

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				if (!vec.back().empty())
				{
					vec.emplace_back();
				}
			}
			else
			{
				vec.back() += str[i];
			}
		}
		if (vec.back().empty())
		{
			vec.pop_back();
		}

		for (auto value : vec)
		{
			std::cout << '[' << value << ']' << std::endl;
		}
	}
	
	void StringToWordsByBUKVYWithMap1()
	{
		std::map<int, std::string> decomposed_str;
		std::string str;

		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		std::getline(ifs, str);
		std::cout << str;

		int word_start_pos = 0;

		if (str[0] != ' ')
		{
			decomposed_str[word_start_pos] += str[0];
		}
		
		for (int i = 1; i < str.size(); ++i)
		{
			if (str[i - 1] == ' ' && str[i] != ' ')
			{
				word_start_pos = i;
			}
			if (str[i] != ' ')
			{
				decomposed_str[word_start_pos] += str[i];
			}
		}

		for (auto [key, value] : decomposed_str)
		{
			std::cout << key << '-' << '[' << value << ']' << std::endl;
		}
	}

	//апдейт - исключить символы (например восклицательный знак), сделать счетчик количества раз использовани€ слов, сохран€ть только уникальные слова, исключить падежи, окончани€

	/*void ExampleRead2()
	{
		std::ifstream ifs("TextFiles/File1.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		std::string s;
		while (ifs >> s)
		{
			cout << s;
		}
	}

	void ExampleRead3()
	{
		std::ifstream ifs("TextFiles/File1.txt");
		//std::ifstream ifs("Source.cpp");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		std::map<string, int> m;
		std::string s;
		while (ifs >> s)
		{
			m[s]++;
		}
			PrintMap(m);
	}

	void ExampleRead4()
	{
		std::ifstream ifs("TextFiles/File2.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}
		int a;
		while (ifs >> a) //пока есть что считывать. считываение определ€етс€ ">>"
		{
			cout << a << endl;
		}
	}

	void ExampleWrite1()
	{
		std::ofstream ofs("TextFiles/File3.txt");
		if (!ofs.is_open()) //(!(ofs.is_open())) 
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		ofs << 3 << endl;
	}

	void ExampleAppend()
	{
		std::ofstream ofs("TextFiles/File3.txt",std::ios::app);
		if (!ofs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		ofs << 3 << endl;
	}

	//сериализаци€ данных - запись программной структуры данных на диск, преобразование структуры данных в файл
	//десериализаци€ данных - наоборот. чтение структуры данных из файла.

	vector<vector<string>> ReadTSV(string filename)
	{
		std::ifstream ifs(filename);
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return {};
		}
		//vector<vector<int>> vecvec;
		////1 2 3
		////5 6 7
		//vector<int> vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec.push_back(3);
		//vecvec.push_back(vec);
		//vec.clear();
		//vec.push_back(5);
		//vec.push_back(6);
		//vec.push_back(7);
		//vecvec.push_back(vec);
		//cout << vecvec[1][1];
		//print_vector(vecvec[0]);
		
		std::string s;

		vector<vector<string>> result;

		vector<string> row;
		
		while (ifs >> s)
		{
			if (s != ";")
			{
				row.push_back(s);
			}
			else
			{
				result.push_back(row);
				row.clear();
			}
		}
		return result;
	}

	void ExampleReadTSV()
	{
		vector<vector<string>> temp_vec = ReadTSV("TextFiles/File1.tsv");
		for (int i = 0; i < temp_vec.size(); i++)
		{
			print_vector(temp_vec[i]);
		}
	}

	void SaveVectorToFile(vector<int> vec, string filepath)
	{
		std::ofstream ofs(filepath);
		if (!ofs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		for (int a : vec)
		{
			ofs << a << ' ';
		}
		ofs << endl;
	}

	void TestSaveVectorToFile()
	{
		std::vector<int> vec = get_random_vector_max_range_size(10, 10);
		SaveVectorToFile(vec, "TextFiles/FileVec.txt");
	}

	vector<int> LoadVectorFromFile(string filepath)
	{
		std::ifstream ifs(filepath);

		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return{};
		}

		vector<int> vecfromfile;
		int temp;

		while (ifs >> temp) //считываем в переменную а до тех пор пока есть что считывать
		{
			vecfromfile.push_back(temp);
		}
		return vecfromfile;
	}

	void TestPrintVectorFromFile()
	{
		print_vector(LoadVectorFromFile("TextFiles/FileVec.txt"));
	}

	//сделать такое же с мапкой в текстовый файл (SaveToFile, LoadFromFile)
	//сделать такое же со структурой Human в текстовый файл (SaveToFile, LoadFromFile)

	void SaveMapToTextFile(std::map<int,int> m, string filepath)
	{
		std::ofstream ofs(filepath);
		if (!ofs.is_open()) //(!(ofs.is_open()))
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		for (auto [key, value] : m)
		{
			ofs << "Map.Key: " << key << " - " << "Map.Value: " << value << endl;
		}
		cout << endl;
	}

	void TestSaveMapToTextFile()
	{
		std::map<int, int> m;
		for (int i = 0; i < 10; i++)
		{
			m[rand() % 10 + 1] = rand() % 1000 + 1;
		}
		SaveMapToTextFile(m, "TextFiles/File2.txt");
	}

	void ReadMapFromTextFile()
	{
		std::ifstream ifs("TextFiles/File2.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		std::map<int, int> m;
		
		std::string string1;
		std::string string2;
		std::string string3;

		int int_key;
		int int_value;

		while (ifs >> string1 >> int_key >> string2 >> string3 >> int_value)
		{
			//ifs >> string1;
			//ifs >> int_key;
			//ifs >> string2;
			//ifs >> string3;
			//ifs >> int_value;

			m[int_key] = int_value;
		}
		
		PrintMap(m);
	}

	void SaveStructToFile()
	{
		Human h;
		h.city_of_living = "Moscow";
		h.date_of_birth.year = 2010;
		h.date_of_birth.month = 10;
		h.date_of_birth.day = 20;
		h.gender = 'm';
		h.str_name = "Ivan";
		
		std::ofstream ofs("TextFiles/File2.txt");
		if (!ofs.is_open()) //(!(ofs.is_open()))
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		ofs << h.city_of_living << ' ';
		ofs << h.date_of_birth.year << ' ';
		ofs << h.date_of_birth.month << ' ';
		ofs << h.date_of_birth.day << ' ';
		ofs << h.gender << ' ';
		ofs << h.str_name << ' ';
		std::cout << std::endl;
	}

	void ReadStructFromFile()
	{
		std::ifstream ifs("TextFiles/File2.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		Human h;

		ifs >> h.city_of_living;
		ifs >> h.date_of_birth.year;
		ifs >> h.date_of_birth.month;
		ifs >> h.date_of_birth.day;
		ifs >> h.gender;
		ifs >> h.str_name;
	}
	*/
}