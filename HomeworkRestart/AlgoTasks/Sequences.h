#pragma once
#include <iostream>

/*
1. ������� ������������ ������� �����, ���� �� �� ������ �������������.
2. ������� ����� �����
3. ������� �� ����� ������������ ������ ��������� ������������������ (������ �������)
3.1 ������� �� ����� ������������ ������ ��������� ������������������ (������ ����� ��������)
4. ������� �� ����� ������������ ���������� ��������� ������������������, ������� ������� �� �������� ����� ��� �������
5. ����� ���������� ������� ������ ������������������
6. ����� ������������ ������� ������������������

8. ���������, �������� �� ������������������ ������������ (1,4,2,6,1,7)

10. ������� �� ����� ��������. ������� ����� � ���� ���� �� ������.
11. ������� ������������ ����� ����������� ������ ���������.


*/

namespace AlgoTasks::Sequences
{
	void Task0()
	{
		std::vector<int> vec{ 5,6,8,3,2,5,3,6,7,8,7,5,4,-1,7,4,45,6,4 };

		for (auto e : vec)
		{

		}
	}

	void Task3()
	{
		std::vector<int> vec{ 1,2,4,3,7,2,9 };

		int summ = 1;

		for (auto e : vec)
		{
			if (e % 2 == 0)
			{
				summ *= e;
			}
		}
		std::cout << summ << std::endl;
	}

	void Task3_1()
	{
		std::vector<int> vec{ 1,2,4,3,7,2,9 };

		int summ = 1;
		int i = 0;

		for (auto e : vec)
		{
			if (i % 2 == 0)
			{
				summ *= e;
			}
			i++;
		}
		std::cout << summ << std::endl;
	}

	void Task4()
	{
		int n = 1;

		int summ = 1;

		std::vector<int> vec{ 3,112,16,9,7,10,15,4081,100,99,70300 };

		for (auto e : vec)
		{
			if (e >= 10 && e<100 && e % n == 0)
			{
				summ *= e;
			}
		}
		std::cout << summ << std::endl;
	}

	void Task6()
	{
		std::vector<int> vec{ 5,6,8,3,2,5,3,6,7,8,7,5,4,-1,7,4,6,4 };

		int n_max;
		bool was_first_elem = false;
		for (auto e : vec)
		{
			if (!was_first_elem)
			{
				n_max = e;
				was_first_elem = true;
			}
			
			if (e > n_max)
			{
				n_max = e;
			}
		}
		std::cout << n_max << std::endl;

	}

	void Task8()
	{
		std::vector<int> vec{1,2,1,2};

		int prev = 0;
		int prevprev = 0;
		bool was_prev_elem = false;
		bool was_prevprev_elem = false;

		for (auto e : vec)
		{
			if (was_prevprev_elem == false)
			{
				prevprev = e;
				was_prevprev_elem = true;
				continue;
			}

			if (was_prev_elem == false)
			{
				prev = e;
				was_prev_elem = true;
				continue;
			}

			if (e >= prev && prev >= prevprev)
			{
				return;
			}
			else if (e <= prev && prev <= prevprev)
			{
				return;
			}
			prevprev = prev;
			prev = e;
		}
		std::cout << "Yes" << std::endl;
	}

	void Task10()
	{
		std::vector<int> vec{ 1,2,3,3,3,3,4,5,1,1,1,6,6,7,8,9 };

		int n_prev;
		bool was_first_elem = false;
		bool is_eq = false;
		
		for (auto e : vec)
		{
			if (!was_first_elem)
			{
				n_prev = e;
				was_first_elem = true;
				continue;
			}
			if (e == n_prev)
			{
				if (!is_eq)
				{
					std::cout << n_prev << ' ' << e << ' ';
					is_eq = true;
				}
				else
				{
					std::cout  << e << ' ';
				}
			}
			else
			{
				is_eq = false;
			}
			n_prev = e;
		}
		std::cout << std::endl;
	}

	void Task11()
	{
		std::vector<int> vec{ 1,2,3,3,3,3,4,5,1,1,1,1,1,1,6,6,7,8,9 };

		int n_prev;
		bool was_first_elem = false;
		int count = 1;
		int cur_max = 0;

		for (auto e : vec)
		{
			if (!was_first_elem)
			{
				n_prev = e;
				was_first_elem = true;
				continue;
			}
			
			if (e == n_prev)
			{
				count++;
			}
			else if (count != 1)
			{
				if (count > cur_max)
				{
					cur_max = count;
				}
				//std::cout << cur_max << std::endl;
				count = 1;
			}
			n_prev = e;
		}
		if (count != 1)
		{
			if (count > cur_max)
			{
				cur_max = count;
			}
			//std::cout << cur_max << std::endl;
		}
		std::cout << cur_max << std::endl;
	}

	





















}