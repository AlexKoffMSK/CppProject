#pragma once
#include <iostream>

namespace AlgoTasks::Loops
{
	//4. ������� ������ n ������ ����� (�����������, ������ ����).
	void Task4()
	{
		int n;
		std::cin >> n;
		int count_of_results=0;
		int result = -1;
		while (count_of_results < n)
		{
			result++;
			if (result % 2 == 0)
			{
				count_of_results++;
				std::cout << result << std::endl;
			}
		}

		for (int i = 0; i < n * 2; i += 2) //�����������, �.�. � ��� ���� ������ ����� ����� � ���� � ��� ������� % � �������
		{
			std::cout << i << std::endl;
		}

	}

	//5. ������������ ������ ����� n. ������� �������� �����, ������� n. (�����������, ������ ����).
	void Task5()
	{
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 != 0)
			{
				std::cout << i << std::endl;
			}
		}

		for (int i = 1; i < n; i += 2) //�����������, �.�. � ��� ���� ������ ����� ����� � ���� � ��� ������� % � �������
		{
			std::cout << i << std::endl;
		}
	}

	//8. ������� ������� � ����� n ��������� n �����.
	void Task8()
	{
		int n;
		std::cin >> n;
		//n=4, 4 5 6 7
		//n=3, 3 4 5
		for (int i = n; i <...; i++)
		{
			std::cout << i;
		}
	}















}