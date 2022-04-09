#pragma once
#include <iostream>
#include <string>

namespace RandomTasks
{
	bool IsSpace(char ch)
	{
		return ch == '\n' || ch == '\t' || ch == ' ';
	}
	
	void Task0()
	{
		std::string str;
		//std::getline(std::cin, str);
		std::string word;
		str = "Hello world and all";
		int prev_space = -1;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' '|| i == str.size()-1)
			{
				//std::cout << prev_space << '-' << i << std::endl;
				int start_j = ((prev_space == -1) ? 0 : (prev_space+1));
				int finish_j = ((i != str.size() - 1) ? i : str.size());
				//for (int j = start_j; j < finish_j; ++j)
				//{
				//	word.push_back(str[j]);
				//}
				
				word = str.substr(start_j, finish_j - start_j);

				std::cout << '[' << word << ']' <<std::endl;
				//word.clear();
				prev_space = i;
			}
		}
	}

	void Task2()
	{
		char ch;
		std::ifstream ifs;
		ifs.open("TextFiles\\BigText.txt");
		if (!ifs.is_open())
		{
			std::cout << "File not open!" << std::endl;
		}
		std::string str;
		
		//while (ifs) 
		//while (!ifs.eof()) 
		//while (ifs>>str) 
		//{
		//	std::cout << '[' << str << ']';
		//}
		//while (std::getline(ifs,str))
		//{
		//	std::cout << '[' << str << ']';
		//}
		//while (!ifs.eof())
		//{
		//	ch = ifs.get();
		//	std::cout << '[' << ch << ']';
		//}

		std::string word;
		//str = "Hello world and all";
		
		while (!ifs.eof())
		{
			std::string line;
			std::getline(ifs, line);
			//str.push_back(ifs.get());
			str+=line+'\n';
		}

		for (int i = 0; i < str.size(); ++i)
		{
			//if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			if (!IsSpace(str[i]))
			{
				word.push_back(str[i]);
			}
			//if (str[i] == ' ' || i == str.size() - 1 || str[i] == '\n')
			if (IsSpace(str[i]) || i == str.size() - 1)
			{
				std::cout << '[' << word << ']' << std::endl;
				word.clear();
			}
		}
	}

	void Task1()
	{
		std::string str;
		str = "Hello world and all";

		std::vector<int> vec;
		vec.push_back(-1);
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ') 
			{
				vec.push_back(i);
			}
		}
		vec.push_back(str.size());

		for (int i = 0; i < vec.size()-1; ++i)
		{
			std::cout << str.substr(vec[i] + 1, (vec[i + 1] - 1) - (vec[i] + 1)+1) << std::endl;
		}
	}
}
