#pragma once
#include <iostream>
#include <set>

// ��������� - ��� ����� ��������� ��� ����������
// 3 15 -1 - ��� ��������� ���������
// 3 3 -1 - ��� �� ���������, �.�. ����������� 3. ���������� ����� 3 � -1

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

		if (s.find(4) != s.end()) //���� �� ����� �� ����� -> ������ ����� 4
		{
			cout << "4" << endl;
		}
		if (s.find(3) != s.end()) //���� �� ����� �� ����� -> ������ ����� 4
		{
			cout << "3" << endl;
		}
	}
}