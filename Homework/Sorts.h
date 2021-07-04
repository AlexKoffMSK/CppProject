#pragma once
#include <iostream>

bool exchange_2_unordered_elems(int* arr, int n)
//������� ��������� �� ������� � ������ 2 �������� �������� �������, ������� �� ����������� �� �����������
{
	bool is_already_sorted = true;
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i+1]) // ���� > - ����� ������� ��������� �����, < - ����� ��������� ��������� �����
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			is_already_sorted = false;
		}
	}
	return is_already_sorted;
}

int find_index_of_min_elem(int* arr, int n, int start_index)
{
	int current_min = arr[start_index];
	int index_of_current_min = start_index;
	for (int i = start_index; i < n; i++)
	{
		if (current_min > arr[i])
		{
			current_min = arr[i];
			index_of_current_min = i;
		}
	}
	return index_of_current_min;
}


void selection_sort(int* arr, int n)
	// 1. ������ ��������� ������� ������ ������� �������
	// 2. ������� � ����������� ����� ������ ������ ������������ ��������
	// 3. ������ ��� � ������� ������ ���������
	// 4. ���� ������ ������� ����� �� �����, �����������. ����� ������� ������ ������� � ���� �� ����� 2
{
	int index_of_current_min = 0;

	for (int i = 0; i < n; i++)
	{
		index_of_current_min = find_index_of_min_elem(arr, n, i);
		
		// ������� ������� �������� ������� ��� ��������� i � index_of_current_min
		int temp = arr[i];
		arr[i] = arr[index_of_current_min];
		arr[index_of_current_min] = temp;

		std::cout << i << ", " << index_of_current_min << ": ";
		
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}
}


void bubble_sort(int* arr, int n)
//����������� ����������, ��������� ������ �� ���� � �������� ������� ������������� ������� �� ��� ���, ���� ������ �� ������ ���������������, 
//��� ���������� ��� ����������� ��������� ���������� bool is_already_sorted
{
	//while (exchange_2_unordered_elems(arr, n) == false)
	//{
	//}

	bool is_sorted = false;

	do
	{
		is_sorted = exchange_2_unordered_elems(arr, n);
		std::cout << endl;

		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << ' ';
		}
	} while (is_sorted == false);
}


void array_generation()
{
	const int n = 10;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
		//a[i] = n-i-1;
		std::cout << a[i] << ' ';
	}
	
	std::cout << std::endl;
	
	bubble_sort(a, n);
	//selection_sort(a, n);

	std::cout << endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << ' ';
	}
}