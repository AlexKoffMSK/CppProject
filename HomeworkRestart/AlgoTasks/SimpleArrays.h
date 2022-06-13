#pragma once
#include <map>

/*
������� �������
1. ������� ������ ������� n. ��������� ��� ����������. � ������ ������ �������� 6, � � ������������� 8.
2. ������� ������ ������� n � �������� � ����: �� ������ ������� ����, �� �������� ��������� �����.
3. ������� ������ ������� n � �������� � ���� ��������� ����� {0, 2, 4, 6, 8, 10, ..., 2(n-1)}
4. ������� ������ ������� n � �������� � ���� ��������� ����� { n-1, n-2, ..., 3, 2, 1, 0}
5. ������� �� ����� ������� ���������, � ������� �������� ����� 5.
6. ������� �� ����� ������ ��������� ������. ���� ������ � ������� ����, ������� -1. ������. �������� ������: 3 6 4 2 3 4 6 2 1. 
�����: 7.������. �������� ������: 2 3 4 1 5 4 6 7 0. �����: 0.
7. ������� �� ����� ������� ��������� ������ � ������ ������ (������� ��� ������, ����� ��� ������). ������. �������� ������: 3 6 4 2 3 4 6 2 1. 
�����: 7 0. ������. �������� ������: 2 3 4 1 5 4 6 7 0. �����: 0 1.
8. ������� ������� ��� � ������� ����������� 0.
9. �������� ��� ���� � ������� �� ����� ������������ ���������� ����� � �������. 
������. �������� ������: 2 3 0 1 5 0 6 7 0. ����� � ������� 3, �������� ��� ���� �� 3. �����: 2 3 3 1 5 3 6 7 3
10. ������� ��� ��������� ��������. ������� �������� ��������� ���������, ���� �� ������ ����������� � ���������� ��������. 
������. �������� ������: 2 3 0 1 5 3 6 7 6 7. �����: 2 0 3 6. ������. �������� ������: 2 1 2 1 2 1 2 1 2 1. �����: 1 1 1 1 1
11. ��� ������ ��������� ����� ������� n. ������� ������� � ������� �����, ����� � ��������.
12. ��� ������ ��������� ����� ������� n. 
������� 0, ���� � ���� ������� ����� 3 ����������� ������ ����� 4. 
������� 1, ���� 4 ������ 3. -1 - ���� � ������� ��� ������ ��� ��������.
13. ��� ������ ��������� ����� ������� n. ������� ���, ���� ������������ ������� � ������� �������� � ����� �������. 
�������� ������� ��������� ����� �� ���������.
14. ��� ������ ��������� ����� ������� n. �������� ������� ������ ����������� � ��������� ������������ ��������.
15. ��� ������ ��������� ����� ������� n. ����� ������� �������� ��������� �������. 
������� ������� ���������, ������� �������� ���������� �� ��������. �������� ������: 2 4 3 7 6 5 8. ������� �������� - (2 + 4 +3 + 7 + 6 + 5 + 8) / 7 = 5. 
�������, ������� �������� ���������� �� 5 ��� 2 � 8.
16. ��� ������ ��������� ����� ������� n. ������� true, ���� � ������� ��� ����� ����������, ����� false.
17. ��� ������ ������� n, ����������� ���������� �������. ����������� ��� ������������ ��������, �.�.
������1: 1 2 3 4 5. ���������������� ������: 5 4 3 2 1
������2: 1 2 3 4 5 6. ���������������� ������: 6 5 4 3 2 1

18. ������������� ����� ������ ������� n: � ������� ������ ��������� ����� �� 0 �� 10. � ������ �� 10 �� 20.
�� ������ �� 20 �� 30. � �.�.

19. ��� ������ ������� n, ����������� ���������� ������� �� 0 �� 9. ������� ������� ��� ����������� ����������� �����.
�������� ������: 4 3 7 5 4 2 4 4 2 2 9 2. ����������� ��� 2, ��� ����������� 4 ����. ������ ������� 4.

20. ��� ������ ������� n, ����������� ���������� ������� �� 0 �� 9. ������� ������������ ��� ����������� ��������, � ����������� �� ����, ��� ������ ���������� � �������. �������� ����, ��� ������. ���� �������� � ������� ����������� ���������� ���������� ���, �� ������� �����.
������1: 6 5 3 8 4 7 5 3

21. ������� 2 ������� ������ n. ��������� �� ��� � ������ 2. ������� ��� ����� �� �������� �� ����������� (�� ���� ����� ��)
������: 4 15 23 37 43 56
������: 2 16 21 35 48 59
�����: 2 4 15 16 21 23 35 37 43 48 56 59
*/

namespace AlgoTasks::SimpleArrays
{
	void Task10()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		for (int i = 1; i < vec.size()-1; ++i)
		{
			if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1])
			{
				std::cout << vec[i] << std::endl;
			}
		}
	}

	//11. ��� ������ ��������� ����� ������� n. ������� ������� � ������� ����������� ����� �����
	void Task11()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		std::map<int, int> m;

		for (int i = 0; i < vec.size(); ++i)
		{
			m[vec[i]]++;
		}
		for (auto [key, value] : m)
		{
			std::cout << key << ' ' << value << std::endl;
		}
	}

	void Task12()
	{
		std::vector<int> vec = { 3,4,3,3,4,3,4};

		int ind3 = -1;
		int ind4 = -1;

		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == 3 && ind3 == -1)
			{
				ind3 = i;
			}
			if (vec[i] == 4 && ind4 == -1)
			{
				ind4 = i;
			}
		}
			if (ind3 > ind4)
			{
				std::cout << 1 << std::endl;
				return;
			}
			if (ind3 < ind4)
			{
				std::cout << 0 << std::endl;
				return;
			}
			std::cout << -1 << std::endl;
	}

	//14. ��� ������ ��������� ����� ������� n. �������� ������� ������ ����������� � ��������� ������������ ��������.
	void Task14()
	{
		std::vector<int> vec = { 4,3,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,8,5 };

		int first_min = vec[0];
		int last_max = vec[0];

		int ind_first_min = 0;
		int ind_last_max = 0;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < first_min)
			{
				first_min = vec[i];
				ind_first_min = i;
			}
			if (vec[i] >= last_max)
			{
				last_max = vec[i];
				ind_last_max = i;
			}
		}
		vec[ind_first_min] = last_max;
		vec[ind_last_max] = first_min;
	}

	
	//15. ��� ������ ��������� ����� ������� n. ����� ������� �������� ��������� �������. 
	//������� ������� ���������, ������� �������� ���������� �� ��������. 
	//�������� ������: 2 4 3 7 6 5 8. ������� �������� - (2 + 4 +3 + 7 + 6 + 5 + 8) / 7 = 5
	//MeanValue = MeanValue + (value - MeanValue) / CountValues
	void Task15()
	{
		std::vector<int> vec = {-2,-1,-1,0,1,1,2 };
		double MeanValue = 0;
		int counter = 0;

		int vec_min = vec[0];
		int vec_max = vec[0];

		for (int i = 0; i < vec.size(); ++i)
		{
			counter++;
			MeanValue = MeanValue + (vec[i] - MeanValue) / counter;

			if (vec[i] <= vec_min)
			{
				vec_min = vec[i];
			}
			if (vec[i] >= vec_max)
			{
				vec_max = vec[i];
			}
		}
		std::cout << MeanValue << std::endl;

		double diff_to_max = fabs(vec_max - MeanValue);
		double diff_to_min = fabs(vec_min - MeanValue);
		double max_diff = std::max(diff_to_max, diff_to_min);

		for (int i = 0; i < vec.size(); ++i)
		{
			if (fabs(vec[i] - MeanValue) >= max_diff)
			{
				std::cout << vec[i] << ' ' << i << std::endl;
			}
		}
	}

	//16. ��� ������ ��������� ����� ������� n. ������� true, ���� � ������� ��� ����� ����������, ����� false.
	void Task16()
	{
		std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = i + 1; j < vec.size(); ++j)
			{
				std::cout << vec[i] << ' ' << vec[j] << std::endl;

				if (vec[j] == vec[i])
				{
					std::cout << "False" << std::endl;
					return;
				}
			}
		}
		std::cout << "True" << std::endl;
	}

	//17. ��� ������ ������� n, ����������� ���������� �������.����������� ��� ������������ ��������, �.�.
	void Task17()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };

		int j = 0;
		for (int i = 0; i < vec.size() / 2; ++i)
		{
			std::cout << vec[i] << ' ' << vec[vec.size() - 1 - i] << std::endl;
			
			std::swap(vec[i], vec[vec.size() - 1 - i]);
		}

		for (auto e : vec)
		{
			std::cout << e << std::endl;
		}

	}

	//18. ������������� ����� ������ ������� n: � ������� ������ ��������� ����� �� 0 �� 10. � ������ �� 10 �� 20.
	//�� ������ �� 20 �� 30. � �.�. 0-9, 10-19
	void Task18()
	{
		std::vector<int> vec;
		int n = 10;
		
		for (int i = 0; i < n; ++i)
		{
			vec.push_back(rand() % 10 + i * 10);
		}

		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
	}

	//19. ��� ������ ������� n, ����������� ���������� ������� �� 0 �� 9. ������� ������� ��� ����������� ����������� �����.
	//�������� ������ : 4 3 7 5 4 2 4 4 2 2 9 2. ����������� ��� 2, ��� ����������� 4 ����.������ ������� 4.
	void Task19()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		int min = vec[0];
		int count = 1;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < min)
			{
				min = vec[i];
				count=0;
			}
			if (vec[i] == min)
			{
				count++;
			}
			std::cout << vec[i] << ' ' << min << ' ' << count << std::endl;
		}
		std::cout << count << std::endl;
	}

	//20. ��� ������ ������� n, ����������� ���������� ������� �� 0 �� 9. ������� ������������ ��� ����������� ��������, 
	//	� ����������� �� ����, ��� ������ ���������� � �������.�������� ����, ��� ������.���� �������� � ������� ����������� 
	//	���������� ���������� ���, �� ������� �����.
	//	������1: 6 5 3 8 4 7 5 3
	void Task20()
	{
		std::vector<int> vec = { 4,3,5,6,2,3,4,2,6,3,2,6,2,7,8,5,5,8 };

		int min = vec[0];
		int max = vec[0];
		int count_min = 1;
		int count_max = 1;

		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < min)
			{
				min = vec[i];
				count_min = 0;
			}
			if (vec[i] > max)
			{
				max = vec[i];
				count_max = 0;
			}
			if (vec[i] == min)
			{
				count_min++;
			}
			if (vec[i] == max)
			{
				count_max++;
			}
			//std::cout << "Vec[i]= " << vec[i] << ' ' << " Min= " << min << ' ' << " Count_min= " << count_min << ' ' << " Max= " << max << ' ' << " Count_max= " << count_max << std::endl;
		}
		
		if (count_max >= count_min)
		{
			std::cout << count_max;
		}
		if (count_min >= count_max)
		{
			std::cout << count_min;
		}
	}

	//������������ ������ ������a n, ��� ������ ��������� ����� ������ �����������. ������ ���������� ������� ���������� �� ����������� �� ������, ��� �� 10
	//������� ����� ��������� ���������� �� ������ 10
	std::vector<int> GenerateSortedArray(int n, int dispersion)
	{
		std::vector<int> vec;

		vec.push_back(rand() % dispersion);
		
		for (int i = 1; i < n; ++i)
		{
			vec.push_back(rand() % dispersion + vec[i-1]);
		}
		
		for (auto e : vec)
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
		return vec;
	}


	//21. ������� 2 ������� ������ n.��������� �� ��� � ������ 2. ������� ��� ����� �� �������� �� ����������� (�� ���� ����� ��)
	//	������: 4 15 23 37 43 56
	//	������ : 2 16 21 35 48 59
	//	����� : 2 4 15 16 21 23 35 37 43 48 56 59
	void Task21_1()
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() || pos2 < vec2.size())
		{
			if (pos1 >= vec1.size())
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
				continue;
			}
			if (pos2 >= vec2.size())
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
				continue;
			}
			if (vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
	}

	void Task21_2()
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() || pos2 < vec2.size())
		{
			if (pos1 >= vec1.size())
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
				continue;
			}
			if (pos2>= vec2.size() || vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
	}

	void Task21_3() //������� ��������������� ��������, ���� cout �������� �� push_back
	{
		std::vector<int> vec1 = GenerateSortedArray(10, 10);
		std::vector<int> vec2 = GenerateSortedArray(10, 10);

		int pos1 = 0;
		int pos2 = 0;

		while (pos1 < vec1.size() && pos2 < vec2.size())
		{
			if (vec1[pos1] < vec2[pos2])
			{
				std::cout << vec1[pos1] << ' ';
				pos1++;
			}
			else
			{
				std::cout << vec2[pos2] << ' ';
				pos2++;
			}
		}
		while (pos1 < vec1.size())
		{
			std::cout << vec1[pos1] << ' ';
			pos1++;
		}
		while (pos2 < vec2.size())
		{
			std::cout << vec2[pos2] << ' ';
			pos2++;
		}
	}














}
