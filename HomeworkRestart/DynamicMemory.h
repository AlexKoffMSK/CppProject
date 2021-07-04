#pragma once
#include<iostream>

namespace DynamicMemory
{
	void f0()
	{
		int n;
		std::cin >> n;
		
		int* arr = new int[n];
		//new int[n] - ��� �� ������ � ������������ ������� �������� ��� ������ ����� ������� n, ������ ��� ��������� �� ������ ������� �������
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 20 + 1;
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;

		delete[] arr;
		//�� ������ ����� ������������ ������� ������, ������� ��� ��� �������� ��� ������
		//������� � ����� �������, �� �� ����� ����� ������������ ���� �������, ��� ��� ����������

	}

	void f1()
	{
		int n=10;

		int* arr = new int[n];
		
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 20 + 1;
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;

		int new_n = n+1;

		int* new_arr = new int[new_n];

		for (int i = 0; i < n; i++)
		{
			new_arr[i] = arr[i];
			std::cout << arr[i] << ' ';
		}

		delete[] arr;

		new_arr[new_n - 1] = rand() % 20 + 1;
		std::cout << new_arr[new_n - 1] << ' ';
		std::cout << std::endl;
		
		delete[] new_arr;
	}

	void f2()
	{
		int n = 10;

		int* arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 20 + 1;
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;

		int new_n = n + 1;

		int* new_arr = new int[new_n];

		new_arr[0] = rand() % 20 + 1;
		
		for (int i = 0; i < n; i++)
		{
			new_arr[i+1] = arr[i]; //��������� ����� �� ��������� �� 1
		}
		delete[] arr;

		for (int i = 0; i < new_n; i++)
		{
			std::cout << new_arr[i] << ' ';
		}
		delete[] new_arr;
	}
}