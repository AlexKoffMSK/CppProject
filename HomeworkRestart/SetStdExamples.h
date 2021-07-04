#pragma once
#include <iostream>
#include <set>

// множество - это набор элементов без повторений
// 3 15 -1 - это множество элементов
// 3 3 -1 - это не множество, т.к. повторяется 3. Множеством будет 3 и -1

namespace Set
{
	void Example1()
	{
		std::set<int> s;
		s.insert(3);
		s.insert(3);
		s.insert(15);
		s.insert(-1);

		for (int a : s)
		{
			std::cout << a << std::endl;
		}

		if (s.find(4) != s.end()) //если не дошел до конца -> значит нашел 4
		{
			cout << "4" << endl;
		}
		if (s.find(3) != s.end()) //если не дошел до конца -> значит нашел 4
		{
			cout << "3" << endl;
		}
	}
}