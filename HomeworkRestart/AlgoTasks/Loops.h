#pragma once
#include <iostream>
#include <algorithm>

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
		for (int i = 0; i <n; i++)
		{
			std::cout << i+n << std::endl;;
		}
	}

	//������� ������� ������ ����� � ���������� �� 1 �� n (������������), ����� �������� ����� �� n (�� �������) �� 2n (������������).
	void Task9()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n * 2; ++i)
		{
			if (i <= n && i % 2 == 0)
			{
				std::cout << i << std::endl;
			}
			if (i >= n && i % 2 != 0)
			{
				std::cout << i << std::endl;
			}
		}
	}

	void Task9_1()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n * 2; ++i)
		{
			if (i <= n)
			{
				if (i % 2 == 0)
				{
					std::cout << i << std::endl;
				}
			}
			else
			{
				if (i % 2 != 0)
				{
					std::cout << i << std::endl;
				}
			}
		}
	}

	void Task9_2()
	{
		int n;
		std::cin >> n;
		int i = 0;
		for (; i <= n; i+=2)
		{
			std::cout << i << std::endl;
		}
		//��� n = 10 i ���������� ������ 12
		//��� n = 11 i ���������� ������ 12 ��� ��� i ������ �� 2
		i--; //��������� ����� �� 1, �.�. �� ����������� ����� i ������ ������
		for (; i <= n * 2; i += 2)
		{
			std::cout << i << std::endl;
		}
	}

	//10. ������������ ������ ����� n. ������� n n-1 n-2 ... 1
	void Task10()
	{
		int n;
		std::cin >> n;

		for (int i = n; i > 0; --i)
		{
			std::cout << i << std::endl;
		}
	}

	//11. ���� ����� ������ ��� ����� ����.
	void Task11()
	{
		int n;
		std::cin >> n;

		for (int i = 0; i < n; ++i)
		{
			std::cout << n-i << std::endl;
		}
	}

	//12. ������������ ������ ����� n. ������� ������ �������� �� �����������. � ������ �� ��������. (1 2 3 ... n/2) (n n-1 n-2 ... n/2+1)
	//13. ������� ���� �����, �� ������������ ������ ���� for.
	void Task12()
	{
		int n;
		std::cin >> n;
		
		for (int i = 0; i <= n; ++i)
		{
			if (i <= n / 2)
			{
				std::cout << i << std::endl;
			}
			else
			{
				std::cout << n - i + n/2 + 1 << std::endl; // i[n/2+1,n]
			}
		}
	}

	//15. ��������� n! = 1  2  3  4  5  �  (n - 1) * n. - ��������
	//n! = n*(n-1)!
	int Task15_factorial(int x)
	{
		return (x > 0) ? (x * Task15_factorial(x - 1)) : 1;
	}
	
	void Task15()
	{
		int n;
		std::cin >> n;
		std::cout << Task15_factorial(n) << std::endl;
	}

	//16. ��������� ����� ��������� �� n �� k !������� ���� �� ������ ����!��� ����� ����������!
	//c_n_k = (n!) / (k! * (n-k)!)
	int Task16()
	{
		int k,n;
		std::cin >> k >> n;

		return Task15_factorial(n) / (Task15_factorial(k) * Task15_factorial(n - k));
	}

	//������� ��� ��������� ���������� ����� - ��� ����� �� 10 ���������
	//012
	//013
	//014
	//...
	//019
	//023
	//...
	//029
	//034
	//...
	//089
	
	//123
	//124
	//..
	//129
	//134
	//...
	//189
	
	//234
	//..
	//239
	//345
	//..
	//349
	//456
	//...
	//679
	//789
	void Task16_1()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = i + 1; j < 10; ++j)
			{
				for (int k = j + 1; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - ���������� ���������� ���������" << std::endl;
		std::cout << Task15_factorial(10) / (Task15_factorial(3) * Task15_factorial(10 - 3)) << std::endl;
	}

	//�� ��, ��� � 16_1, �� � ������������ �����
	//(k + n-1)! / ((n-1)! * k!)
	//000
	//001
	//002
	//009
	//011
	//012
	//019
	//022
	//...
	//999
	void Task16_2()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = i; j < 10; ++j)
			{
				for (int k = j; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - ���������� ��������� � ������ ���������� ����" << std::endl;
		std::cout << Task15_factorial(12) / (Task15_factorial(9) * Task15_factorial(3)) << std::endl;
	}

	//�� �� ��� � 16_2, �� ����� ������� �����
	//�������10^3
	//123
	//321
	void Task16_3()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				for (int k = 0; k < 10; ++k)
				{
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - ���������� ���������� 10 ���� � 3 �������" << std::endl;
		std::cout << std::pow(10,3) << std::endl;
	}

	//����, ��� � 16_3, �� ����� �� ����� �����������
	// n! / (n-k)!
	//123
	//321
	void Task16_4()
	{
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (j == i)
				{
					continue;
				}
				for (int k = 0; k < 10; ++k)
				{
					if (k == j || k == i) 
					{ 
						continue; 
					}
					std::cout << i << j << k << std::endl;
					count++;
				}
			}
		}
		std::cout << count << " - ���������� ���������� 10 ���� � 3 ������� ��� ���������� ����" << std::endl;
		std::cout << Task15_factorial(10) / Task15_factorial(7) << std::endl;
	}

	//��� ������, ������� ��� ��������� ������������ ��������� ����� �������
	//01234
	//...
	//04321

	std::vector<int> RemoveElementFromVector(std::vector<int> vector, int index_to_remove)
	{
		vector.erase(vector.begin() + index_to_remove);
		return vector;
	}

	//����� ���������� �������
	int count = 0;

	void PrintPermutation(std::string prefix, std::vector<int> vec)
	{
		if (vec.size() == 0)
		{
			return;
		}
		
		if (vec.size() == 1)
		{
			std::cout << prefix << vec[0] << std::endl;
			count++;
			return;
		}
		for (int i = 0; i < vec.size(); ++i) 
		{
			PrintPermutation(prefix + std::to_string(vec[i]), RemoveElementFromVector(vec, i));
		}
		return;
	}

	void TaskTest()
	{
		std::string s = "12345";
		do {
			std::cout << s << '\n';
		} while (std::next_permutation(s.begin(), s.end()));
	}
}