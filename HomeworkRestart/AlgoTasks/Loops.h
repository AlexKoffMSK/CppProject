#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>

namespace AlgoTasks::Loops
{
	//4. ������� ������ n ������ ����� (�����������, ������ ����).
	void Task4()
	{
		int n;
		std::cin >> n;
		int count_of_results = 0;
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
		for (int i = 0; i < n; i++)
		{
			std::cout << i + n << std::endl;;
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
		for (; i <= n; i += 2)
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
			std::cout << n - i << std::endl;
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
				std::cout << n - i + n / 2 + 1 << std::endl; // i[n/2+1,n]
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
		int k, n;
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
		std::cout << std::pow(10, 3) << std::endl;
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

	//17. ������������ ������ 2 ����� n,m. ������� m m+1 m+2 ... n ��� n n+1 n+2 ... m. ����������� ���������� ���� ����.
	void Task17()
	{
		int n;
		int m;
		std::cin >> n >> m;
		int max_elem = std::max(n, m);
		int min_elem = std::min(n, m);

		for (int i = min_elem; i <= max_elem; ++i)
		{
			std::cout << i << std::endl;
		}
	}

	//18. ������� ��� �������� �����
	void Task18()
	{
		int x;
		std::cin >> x;
		for (int i = 1; i <= x / 2; ++i)
		{
			if (x % i == 0)
			{
				std::cout << i << std::endl;
			}
		}
		std::cout << x << std::endl; //��� ��� ������� �� ������ ����

	}

	//19. ����� ���������� ������������� ��������_���_������� ������������ �����
	void Task19()
	{
		int x;
		std::cin >> x;
		if (x % 2 == 0)
		{
			std::cout << x / 2 << std::endl;
		}
		else
		{
			for (int i = x / 2; i >= 2; --i)
			{
				if (x % i == 0)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}

	//20. ����� ���������� ������������� �������� ������������ ����� 
	void Task20()
	{
		int x;
		std::cin >> x;
		if (x % 2 == 0)
		{
			std::cout << 2 << std::endl;
		}
		else
		{
			for (int i = 2; i <= x / 2; ++i)
			{
				if (x % i == 0)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}

	int GetMinimalDenominator(int x)
	{
		if (x == 2)
		{
			return 1;
		}
		else if (x % 2 == 0)
		{
			return 2;
		}
		else
		{
			for (int i = 2; i <= x / 2; ++i)
			{
				if (x % i == 0)
				{
					return i;
					break;
				}
			}
		}
		return 1;
	}

	//22. �������� ������������ ���������� ����� �� ������� ����������� 27 = 3 * 9, 9 = 3 * 3, 3 * 3 * 3
	void Task22()
	{
		int n;
		std::cin >> n;
		int mult = 0;
		while (mult != 1)
		{
			mult = GetMinimalDenominator(n); //n=4, mult=2; n=2, mult=1;
			if (mult == 1)
			{
				std::cout << n << std::endl;
			}
			else
			{
				std::cout << mult << std::endl;
			}
			n = n / mult;
		}
	}
	//23. ����� ���������� ������������� �������� ���� �������� �����
	void Task23()
	{
		int n;
		int m;
		std::cin >> n >> m;
		for (int i = 2; i <= std::min(n, m) / 2; ++i)
		{
			if (n % i == 0 && m % i == 0)
			{
				std::cout << i << std::endl;
				break;
			}
		}
	}

	std::vector<int> GetDenominators(int x)
	{
		std::vector<int> vec;
		for (int i = 1; i <= x / 2; ++i)
		{
			if (x % i == 0)
			{
				vec.push_back(i);
			}
		}
		return vec;
	}

	int GetSummOfElementsOfVector(std::vector<int> vec)
	{
		return std::accumulate(vec.begin(), vec.end(), 0);
	}

	int GetSummOfDenominators(int x)
	{
		return GetSummOfElementsOfVector(GetDenominators(x));
	}

	//24.  ���������, �������� �� �������� ����������� ����� ����������� /������ ����� ���� ����� ����������� ���������
	void Task24()
	{
		int n;
		std::cin >> n;

		std::vector<int> vec;

		for (int i = 1; i <= n / 2; ++i)
		{
			if (n % i == 0)
			{
				vec.push_back(i);
				std::cout << i << std::endl;
			}
		}
		int summ = 0;

		for (int a : vec)
		{
			summ += a;
		}
		//�������� 28 = 1,2,4,7,14
		std::cout << (summ == n) << std::endl; //+1 ��� ��� ��� �������� ������ ��������� ������������
	}

	void Task24_one_row()
	{
		int n;
		std::cin >> n;
		std::cout << (GetSummOfDenominators(n) == n) << std::endl;
	}

	//25. ���������, �������� �� ��� ����������� ����� �������������� 
	void Task25()
	{
		int n, m;
		std::cin >> n >> m;
		std::cout << ((GetSummOfDenominators(n) == m) && (GetSummOfDenominators(m) == n)) << std::endl;
	}

	//25 ����� ���������� ����� �������� ���� ����������� ����� 
	void Task26(int x, int y)
	{
		/*
		1. ����� ����� x y
		2. ������� �� ��� ����� �� ������� �� ���
		3. ���� ������� ��� �������, �� ������� ����� � ���� ��� (������� ����� �� �����).
		4. ���� ���� �������, �� ������� �� x y �������� �� ������� �� �������.
		5 .��������� � ������ 1.
		*/

		//while (true)
		//{
		//	if ((std::max(x, y) % std::min(x, y)) != 0)
		//	{
		//		if (x > y)
		//		{
		//			x = (std::max(x, y) % std::min(x, y));
		//		}
		//		else
		//		{
		//			y = (std::max(x, y) % std::min(x, y));
		//		}
		//	}
		//	else
		//	{
		//		break;
		//	}
		//}

		while ((std::max(x, y) % std::min(x, y)) != 0)
		{
			if (x > y)
			{
				x = (std::max(x, y) % std::min(x, y));
			}
			else
			{
				y = (std::max(x, y) % std::min(x, y));
			}
		}
		std::cout << std::min(x, y) << std::endl;
	}

	//28. ������������ ������ �����. �������� �� ��� �������.
	bool IsSimple_Task28(int x)
	{
		for (int i = x / 2; i > 1; --i)
		{
			if (x % i == 0)
			{
				//std::cout << "Not simple" << std::endl;
				return false;
			}
		}
		//std::cout << "Simple" << std::endl;
		return true;
	}

	//29. ������������ ������ ����� n. ������� ��� ������� ����� ������� n.
	void Task29()
	{
		int x = 10;
		for (int i = x - 1; i >= 1; --i)
		{
			if (IsSimple_Task28(i))
			{
				std::cout << i << std::endl;
			}
		}
	}

	//30. ������� �� ����� ������ n ������� �����
	void Task30()
	{
		int i = 0;
		int n = 6;
		while (n >= 1)
		{
			i++;
			if (IsSimple_Task28(i))
			{
				n--;
				std::cout << i << std::endl;
			}
		}
	}

	//31. ������������ ������ ����� n (���������� ��������). ������� ������ ������� ����� ������� n.
	void Task31_0()
	{
		int i = 0;
		int n = 122;
		while (true)
		{
			i++;
			if (IsSimple_Task28(n + i))
			{
				std::cout << n + i << std::endl;
				return;
			}
		}
	}

	void Task31_1()
	{
		int n = 122;
		int i = n;
		while (true)
		{
			i++;
			if (IsSimple_Task28(i))
			{
				std::cout << i << std::endl;
				return;
			}
		}
	}

	void Task31()
	{
		int n = 122;
		while (true)
		{
			n++;
			if (IsSimple_Task28(n))
			{
				std::cout << n << std::endl;
				return;
			}
		}
	}

	//32. ������������ ������ ����� n (���������� ��������) � p. ������� ������ p ������� ����� ������� n.
	void Task32()
	{
		int n = 789;
		int p = 9;
		int count_of_simple_numbers = 0;
		while (count_of_simple_numbers != p)
		{
			n++;
			if (IsSimple_Task28(n))
			{
				std::cout << n << std::endl;
				count_of_simple_numbers++;
			}
		}
	}

	//33. ��������� ����� ���� �����
	void Task33()
	{
		int n = 1231;

		//std::string str = std::to_string(n);
		//int summ = 0;
		//for (int i = 0; i < str.size(); ++i)
		//{
		//	summ += (str[i] - '0');
		//}

		int summ = 0;
		while (n != 0)
		{
			summ += (n % 10);
			n /= 10;
		}
		std::cout << summ << std::endl;
	}

	int GetNumberOfDigits(int number)
	{
		//int count = 0;
		//while (true)
		//{
		//	if (number % 10 == 0 && number / 10 == 0)
		//	{
		//		return count;
		//	}
		//	number /= 10;
		//	count++;
		//}

		int count = 1;
		while (number >= 10)
		{
			number /= 10;
			count++;
		}
		return count;
	}

	int GetDigitFromBack(int number, int digit_pos_from_back)
	{
		//5675785865
		//     10000
		//567578
		//   %10
		// 
		//5 from end = 8

		return (number / ((int)pow(10, digit_pos_from_back - 1))) % 10;
	}

	int GetDigitFromStart(int number, int position_from_start)
	{
		//unsigned int number = 1250653456;
		//int c = 6 (digits)
		//(get 6, 3 digit) n/10 = 75658; n/10 = 7565; n/10 = 756; n%10
		//(get 5, 2 digit) n/10 = 75658; n/10 = 7565; n/10 = 756; n/10 = 75; n%10
		//(get 5, 2 digit) n/10 = 75658; n/10 = 7565; n/10 = 756; n/10 = 75; n/10 = 7; n%10
		//for (int i=0; i<pos; ++i)
		//{
		//
		//}
		//int pos_at_all = GetNumberOfDigits(n);

		int number_of_digits = 1;
		int tmp_n = number;
		while (tmp_n >= 10)
		{
			tmp_n /= 10;
			number_of_digits++;
		}

		if (position_from_start > number_of_digits)
		{
			std::cout << "Wrong position" << std::endl;
			return -1;
		}

		number = number / (int)pow(10, (number_of_digits - position_from_start));
		number = number % 10;
		//std::cout << number << std::endl;
		return number;
	}

	
	
	int GetReversedNumber(int number)
	{
		int x = 0;
		int y = 0;
		while (number != 0)
		{
			x = number % 10;
			y = y * 10 + x;
			number /= 10;
		}
		return y;
	}

	//34. ���������, �������� �� ����������� ����� ���������� ������� (����� ������ �������� ���� ����� ����� ������ ��������)
	void Task34()
	{
		int n = 17;

		//int left_h = 0;
		//int right_h = 0;
		//
		//std::string str = std::to_string(n);
		//for (int i = 0; i < str.size() / 2; ++i)
		//{
		//	left_h += (str[i] - '0');
		//}
		//for (int i = str.size() / 2; i < str.size(); ++i)
		//{
		//	right_h += (str[i] - '0');
		//}
		//
		//std::cout << (left_h == right_h) << std::endl;
		//
		////unit test - 121, 1234, 
		////12345678
		////s1 = 8
		////1234567
		////s2 = 7
		////123456
		////s2 = 7+6 = 13
		////12345
		////


	}

	//35. ���������, �������� �� ����������� ����� ����������� 
	void Task35_1()
	{
		//6 * (1 �������, 1 ���������)
		//3 * (2 �������, 1 �������, 1 �����)
		//3 * (2 �������, 1 �������, 1 �����)

		int n = 123321;
		int mid = GetNumberOfDigits(n) /2; // 6 �������� + 3 = 9
		
		for (int i = 1; i <= mid; ++i)
		{
			if (GetDigitFromStart(n, i) != GetDigitFromBack(n, i))
			{
				std::cout << "No" << std::endl;
				return;
			}
		}
		std::cout << "Yes" << std::endl;
	}

	void Task35()
	{
		//6 * (��� �������, ���� ���������, 1 �����)
		
		int n = 123456;
		int source_n = n;
		int x = 0;
		int y = 0;
		while (n != 0)
		{
			x = n % 10;
			std::cout << "x = " << x << std::endl;

			y = y * 10 + x;
			std::cout << "y = " << y << std::endl;

			n /= 10;
			std::cout << "n = " << n << std::endl;
		}

		if (y == source_n)
		{
			std::cout << "Yes" << std::endl;
			return;
		}
		std::cout << "No" << std::endl;
	}

	//36. ���������, �������� �� ����������� ����� �������� ������ 
	void Task36_1()
	{
		int n = 1;
		int x = 0;
		int power_of_2 = 0;

		while (x <= n)
		{
			x = pow(2, power_of_2);

			std::cout << x << ' ' << n << std::endl;

			if (x == n)
			{
				std::cout << "yes" << std::endl;
				return;
			}
			power_of_2++;
		}
	}

	void Task36_2()
	{
		int n = 128;
		int x = 1;
		//int power_of_2 = 0;

		while (x <= n)
		{
			std::cout << x << ' ' << n << std::endl;

			if (x == n)
			{
				std::cout << "yes" << std::endl;
				return;
			}
			x *= 2;
		}
	}

	void Task36_3()
	{
		int n = 128;
		//����� �������

		while (n != 1)
		{
			if (n % 2 != 0)
			{
				std::cout << "No" << std::endl;
				return;
			}
			n = n / 2;
		}
		std::cout << "Yes" << std::endl;
	}

	void Task36_4()
	{
		float n = 128;
		//����� �������

		while (n > 1)
		{
			n = n / 2;
			std::cout << std::setprecision(20) << n << std::endl;
		}
		if (n == 1)
		{
			std::cout << "Yes" << std::endl;
			return;
		}
		std::cout << "No" << std::endl;
	}

	void Task36_5()
	{
		int n = 127;
		//����� �������

		while (n % 2 == 0)
		{
			n = n / 2;
			std::cout << std::setprecision(20) << n << std::endl;
		}
		if (n == 1)
		{
			std::cout << "Yes" << std::endl;
			return;
		}
		std::cout << "No" << std::endl;
	}

	void Task36_6()
	{
		int n = 127;

		double x = std::log2(n);
		if (x != (int)x)
		{
			std::cout << "No" << std::endl;
		}
	}

	void Task36()
	{
		//0000 0100
		//0000 0011 = ���������� � (n-1)
		//0000 0000 - ���� �� �����, � ������� ���� ����� 1 ������� ������ 1, �� ����� ������� ������, � � ������ ������ - ��������.

		//0100 0000
		//0011 1111 = ���������� � (n-1)
		//0000 0000 - ���� �� �����, � ������� ���� ����� 1 ������� ������ 1, �� ����� ������� ������, � � ������ ������ - ��������.

		//0000 0010
		//0000 0001 = ���������� � (n-1)
		//0000 0000 - ���� �� �����, � ������� ���� ����� 1 ������� ������ 1, �� ����� ������� ������, � � ������ ������ - ��������.

		//1010 0110
		//1010 0101 = ���������� � (n-1)
		//1010 0100 - ���� �� �����, � ������� ���� ����� 1 ������� ������ 1, �� ����� ������� ������, � � ������ ������ - ��������.

		//0000 1001
		//0000 1000 = ���������� � (n-1)
		//0000 1000 - ���� �� �����, � ������� ���� ����� 1 ������� ������ 1, �� ����� ������� ������, � � ������ ������ - ��������.

		for (int n = 1; n < 128; ++n)
		{
			if ((n & (n - 1)) == 0)
			{
				std::cout << n << " Yes" << std::endl;
			}
			else
			{
				std::cout << n << " No" << std::endl;
			}
		}

	}

	//37. ������������ ��������� ������ ��������� ����� 
	void Task37()
	{
		int n = 987061; // rev = 98761
		//9
		//9*10+8 = 98
		//98*10+7 = 987
		//res = 9*10000 + 8*1000
		//67 -> 67*10+8

		int x = 0;
		int y = 0;
		while (n!=0) 
		{
			x = n % 10;
			std::cout << "x = " << x << std::endl;
			
			y = y * 10 + x;
			std::cout << "y = " << y << std::endl;

			n /= 10;
			std::cout << "n = " << n << std::endl;
		}
	}

	//38. ��������� ������������ ������������������ ���� ����� 
	void Task38_1()
	{
		//123456 - yes
		//6421 - yes
		//1537 - no
		//-3210123
		//-3 -2 -1

		int x = 10000;
		int cx = x;
		int i = 1;
		int prev = GetDigitFromBack(x, i);
		i++;
		int prevprev = GetDigitFromBack(x, i);
		int prevprevprev = 0;

		while(true)
		{
			if (cx < 100)
			{
				break;
			}

			i++;
			prevprevprev = GetDigitFromBack(x, i);
			std::cout << prev << ' ' << prevprev << ' ' << prevprevprev << std::endl;

			//�����������
			if (prev <= prevprev && prevprev <= prevprevprev)
			{
				std::cout << "Yes" << std::endl;
			}
			//��������
			else if (prev >= prevprev && prevprev >= prevprevprev)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
				break;
			}

			prev = prevprev;
			prevprev = prevprevprev;

			cx = cx / 10;
		}
	}

	void Task38_2()
	{
		int x = 123456;
		int prev = x % 10;
		x /= 10;
		int prevprev = x % 10;
		int prevprevprev = 0;

		while (true)
		{
			if (x <10)
			{
				break;
			}
			x /= 10;
			prevprevprev = x % 10;
			std::cout << prev << ' ' << prevprev << ' ' << prevprevprev << std::endl;

			//�����������
			if (prev <= prevprev && prevprev <= prevprevprev)
			{
				std::cout << "Yes" << std::endl;
			}
			//��������
			else if (prev >= prevprev && prevprev >= prevprevprev)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
				break;
			}

			prev = prevprev;
			prevprev = prevprevprev;
		}
	}

	void Task38_3()
	{
		int x = 654332111;
		int prev = x % 10;
		x /= 10;
		int prevprev = x % 10;
		x /= 10;
		int diff = prev - prevprev;
		prev = prevprev;
		while (true)
		{
			if (x == 0)
			{
				break;
			}
			
			prevprev = x % 10;

			std::cout << diff << ' ' << prev << ' ' << prevprev << std::endl;

			//�����������
			if ((prev-prevprev)*diff < 0)
			{
				std::cout << "No" << std::endl;
				return;
			}
			if ((prev - prevprev) != 0)
			{
				diff = prev - prevprev;
			}
			prev = prevprev;
			x /= 10;
		}
		std::cout << 'Y' << std::endl;
	}

	//39. ������������ ����� �� ���� �������� (���������� �����) ������������ ��������
	void Task39_1()
	{
		//237 459 - 243579

		//732 954 -> res = res * 10 + x % 10 + y % 10 -> 24
		//73 95 -> res = 24 -> res * 10 

		//3n

		int x = 2378;
		int y = 4591;
		int rx = GetReversedNumber(x);
		int ry = GetReversedNumber(y);
		int res = 0;
		
		while (rx != 0 && ry != 0)
		{
			res = res * 10 + rx % 10;
			res = res * 10 + ry % 10;

			rx /= 10;
			ry /= 10;
		}
		std::cout << res << std::endl;
	}

	void Task39_2()
	{
		int x = 2378;
		int y = 4591;
		int count_for_pow = 0;
		int res = 0;

		while (x != 0 && y != 0)
		{
			res = res + (y % 10) * (int)pow(10,count_for_pow); 
			count_for_pow++;
			
			res = res + (x % 10) * (int)pow(10, count_for_pow);
			count_for_pow++;
			
			x /= 10;
			y /= 10;
		}

		std::cout << res << std::endl;
	}

	void Task39()
	{
		int x = 2378;
		int y = 4591;
		int dec_mult = 1;
		int res = 0;

		while (x != 0)
		{
			res = res + (y % 10) * dec_mult;
			dec_mult *= 10;

			res = res + (x % 10) * dec_mult;
			dec_mult *= 10;

			x /= 10;
			y /= 10;
		}
		std::cout << res << std::endl;
	}

	//40. ������� �� ����� x, ���������� � ������� ��������� � ���������� n
	void Task40_1()
	{
		int x = 12345;
		int res = 0;
		int n = 8;
		int dec_mult = 1;

		while (x != 0)
		{
			//res *= 10;
			res = res + (x % n) * dec_mult;
			dec_mult *= 10;
			x /= n;
		}
		std::cout << res << std::endl;
	}

	void Task40()
	{
		int x = 7739;
		int res = 0;
		int n = 16;

		std::string str;

		while (x != 0)
		{
			res = (x % n);
			if (res >= 10)
			{
				str.insert(str.begin(), 'A' + res - 10);
			}
			else
			{
				str.insert(str.begin(), '0' + res);
			}
			x /= n;
		}
		std::cout << str << std::endl;
	}


	//41. ������� �� ����� n-��� ����� ��������� 
	void Task41()
	{
		//0 1 1 2 3 5 8 13 21...

		int n = 7;
		int x = 0;
		int y = 1;
		int count = 2; //��� ��� ������ ��� �������� ��������� ��� �����
		int fibb = 0;

		while (count <= n)
		{
			fibb = x + y;
			std::cout << fibb << std::endl;
			x = y;
			y = fibb;
			count++;
		}
	}

	//42. ������� �� ����� ����� ����� ��������� �� n-���� ������������ 
	void Task42()
	{
		//0 1 1 2 3 5 8 13 21...

		int n = 7;
		int x = 0;
		int y = 1;
		int count = 2; //��� ��� ������ ��� �������� ��������� ��� �����
		int fibb = 0;
		int fibb_summ = 1;

		while (count <= n)
		{
			fibb = x + y;
			fibb_summ += fibb;
			x = y;
			y = fibb;
			count++;
		}
		std::cout << fibb_summ << std::endl;
	}

	//44. ������� ��������� �������. (������� ���������� �������� ������ �������)
	void Task44_1()
	{
		//n=4
		//1000
		//0100
		//0010
		//0001

		int n = 20;
		int pos = 0;
		
		for (int i = 0; i < n*n; i++)
		{
			if (i>1 && i % n == 0)
			{
				std::cout << std::endl;
			}
			if (i == pos)
			{
				std::cout << 1;
				pos += (n+1);
			}
			else
			{
				std::cout << 0;
			}
		}
		std::cout << std::endl;
	}

	void Task44_2()
	{
		int n = 20;
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					std::cout << 1;
				}
				else
				{
					std::cout << 0;
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void Task44()
	{
		//1000 0100 0010 0001
		//1000 0100 0010 0001
		
		int n = 4;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				std::cout << 0;
			}

			std::cout << 1;
			
			for (int j = i+1; j < n; ++j)
			{
				std::cout << 0;
			}
			std::cout << std::endl;
		}
	}
}
