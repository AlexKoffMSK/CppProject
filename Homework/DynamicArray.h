#pragma once
#include <chrono>
#include <iostream>
#include <limits>

using namespace std;


void DynamicArray()
{
	// ������������ ������ �����, ������� ������ ������ �������

	int n;
	cin >> n;

	// const int n=5;
	// int arr[n];  - ����������� ������, ������ ������ ���� �������� �� ����� ����������
	
	int* arr = new int[n]; // ������������ ������. ������������ ������� - ��� �������� ���, ������� ������� � ���, ��� ��� ������ ���������� �������� ������ � ������ ������ ���������, � �� �� ����� ����������.

	
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << ' ';
	}

	cout << endl;
	
	// ����� �������� ����� � ���������������� �������!

	delete[] arr; // ������ ��� ������ �� �����. ������ ���������� �� �������� ����� ��
}

void DynamicArrayLeak()
{
	{
		// char - �������� 1 ����
		char* arr = new char[1024 * 1024 * 512]; // ��������� � �� - 1��
		
		system("pause");
	}
}

void dynamic_array_shift_1(int* arr, int n)
//��������� ������ � ��� ������. ������� ������ ������ � �������� � ���� �������� ������� �������, ������� �� �� 1 ������� ������ (����������)
//������ : 0 1 2 3 4 5 6. ����� : 6 0 1 2 3 4 5.
{
	int* new_arr = new int[n]; //������� ������ ������

	for (int i = 1; i < n; i++) 
	{
		new_arr[i] = arr[i - 1];
	}
	new_arr[0] = arr[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new_arr[i];
	}

	delete[] new_arr;
}

void dynamic_array_shift_3(int* arr, int n, int p)
//��������� ������ � ��� ������. ������� ������ ������ � �������� � ���� �������� ������� �������, ������� �� �� 3 ������� ������ (����������)
//������ : 0 1 2 3 4 5 6. ����� : 4 5 6 0 1 2 3.
{
	int* new_arr = new int[n]; //������� ������ ������

	for (int i = 0; i < n-p; i++)
	{
		new_arr[i + p] = arr[i];
	}

	for (int i = n-p; i < n; i++)
	{
		new_arr[i - (n - p)] = arr[i];
	}

	//for (int i = 0; i < 3; i++)
	//{
	//	new_arr[i] = arr[i+(n-3)];
	//}

	// i
	// n-3  - (n-3) = 0
	// n-2  - (n-3) = 1
	// n-1  - (n-3) = 2

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << new_arr[i] << ' ';
	}
	cout << endl;
	cout << endl;

	delete[] new_arr;
}

void dynamic_array_shift_3_adv(int* arr, int n, int p)
//��������� ������ � ��� ������. ������� ������ ������ � �������� � ���� �������� ������� �������, ������� �� �� 3 ������� ������ (����������)
//������ : 0 1 2 3 4 5 6. ����� : 4 5 6 0 1 2 3.
{
	int* new_arr = new int[n]; //������� ������ ������

	for (int i = 0; i < n; i++)
	{
		new_arr[(i + p) % n] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << new_arr[i] << ' ';
	}
	cout << endl;
	cout << endl;

	delete[] new_arr;
}


void dynamic_array_sort_from_arr(int* arr, int n)
//��������� ������ � ��� ������. ������� ����� ����� ��������������� ������ �� ��������� ������� �������
{
	cout << "Start work v1 algorithm with size (" << n << "): ";
	int* new_arr = new int[n]; //������� ������ ������ �����, ������ ������� �������

	int current_min_bound = -1; //������� �������� ������� ������������ �������� ��� ���������� ����������

	int new_arr_index_for_insert = 0; //������� ����������, ����������� �� �� - ���� ��������� ��������� ��������������� �������

	auto start = chrono::system_clock::now(); // �������� �������� �����

	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;

	while (new_arr_index_for_insert < n) //��������� ���� � ������������ - ���������� ��������� ��� ����������
	{
		int min = INT_MAX; // ���������� ����� ������������ �����, ������� ����� �������� � int
		int counter_min = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= current_min_bound)
			{
				continue; // ���� �� ����� ��������
			}

			if (arr[i] < min)
			{
				counter_min = 0;
				min = arr[i];
			}

			if (arr[i] == min)
			{
				counter_min++;
			}
		}

		current_min_bound = min;

		for (int i = 0; i < counter_min; i++)
		{
			new_arr[new_arr_index_for_insert + i] = min;
		}

		new_arr_index_for_insert += counter_min;

		//for (int i = 0; i < n; i++)
		//{
		//	cout << new_arr[i] << ' ';
		//}
		//cout << endl;
	}

	auto end = chrono::system_clock::now(); // ����������� �������� �����
	chrono::duration<double> elapsed = end - start;
	cout << setprecision(15) << elapsed.count() << "s" << endl; // ������� ������� ������� �������

	delete[] new_arr;

	//cout << endl;
}


void dynamic_array_sort_from_arr_v2(int* arr, int n)
//��������� ������ � ��� ������. ������� ����� ����� ��������������� ������ �� ��������� ������� �������
// 7 4 2 3 5 9 7 8 9 3 4 5 2 3 2
{
	cout << "Start work v2 algorithm with size (" << n << "): ";
	int* new_arr = new int[n]; //������� ������ ������ �����, ������ ������� �������

	// 7 4 2 3 5 9 7 8 9 3 4 5 2 3 2
	// ����� ��������� �������: 7
	// ���� ���� ��� �������� � ����� �������. ����� ������ ������, ��� ��� ��������� � ����� ������: "7"
	// ����� ��������� �������: 4
	// ���� ���� ��� �������� � ����� �������. ������ ��� �� ������ "7", �� ���� ������ ���� ��������, � ������ ������ ���� �������� ����� 7 � �������� 7 ������
	// "4 7"
	// ����� ��������� �������: 2
	// ���� ���� ��� �������� � ����� �������. ������ ��� �� ������ "4 7", "2 4 7"
	// ����� ��������� �������: 3
	// ���� ���� ��� �������� � ����� �������. ������ ��� �� ������ "2 4 7", "2 3 4 7"

	auto start = chrono::system_clock::now(); // �������� �������� �����

	for (int i = 0; i < n; i++)
	{
		arr_sort_add(new_arr, i, arr[i]); //��� n-1 ������ i, �.�. �� ������� �� ������ �������, � ������ ���� ��� ����������.
	}
	
	auto end = chrono::system_clock::now(); // ����������� �������� �����
	chrono::duration<double> elapsed = end - start;
	cout << setprecision(15) << elapsed.count() << "s" << endl; // ������� ������� ������� �������


	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;
	//
	//for (int i = 0; i < n; i++)
	//{
	//	cout << new_arr[i] << ' ';
	//}
	//cout << endl;

	delete[] new_arr;
}





void DynamicArrayLobby()
{
	//DynamicArray();
	//DynamicArrayLeak();
	
	const int n = 10000000;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand() % 10;
		//arr[i] = i;
		arr[i] = n - i;
	}
	//for (int p = 0; p < n; p++)
	//{
		//dynamic_array_shift_3(arr, n, p);
		//dynamic_array_shift_3_adv(arr, n);
	//}
	//dynamic_array_sort_from_arr(arr, n);
	//dynamic_array_sort_from_arr_v2(arr, n);


	// 1 2 3 2 2 2 2 3 3 3 1 1 1 1 2 2 3 3 2 1
	// ((1 + n)n)/2 = 0.5 (n^2 + n)
	// 3n

	for (int size = 1000; size <= 25000; size *= 5)
	//for (int size = 2; size <= n; size *= size)
	{
		dynamic_array_sort_from_arr(arr, size);
		dynamic_array_sort_from_arr_v2(arr, size);
	}

	delete[] arr;
}