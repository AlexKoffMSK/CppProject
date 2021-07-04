#pragma once
#include <iostream>
#include <cmath>


void summ_of_up_right_and_down_left_elems_of_matrix()
//1. ������� ��������� ������� ������� n �� m � ��������� ���������� �������.
//������� ����� ��������� ������ ������� ��������� ������� � ����� ����� ������.
{
	const int n = 4;
	const int m = 6;
	int arr[n][m]; //n - ���������� ����, m - ���������� ��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1; // n - ( n / m ) * m = n % m
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	int summ_up_right = 0;

	for (int i = 0; i < n/2; i++) //�� ������� ������ �� �������� �����
	{
		for (int j = m/2; j < m ; j++) //�� �������� �������� �� ����� ��������
		{
			summ_up_right += arr[i][j];
		}
	}

	cout << summ_up_right << endl;


	int summ_down_left = 0;

	for (int i = n/2; i < n; i++) //�� �������� ����� �� ����� �����
	{
		for (int j = 0; j < m/2; j++) //�� ������ �������� �� �������� ��������
		{
			summ_down_left += arr[i][j];
		}
	}

	cout << summ_down_left << endl;
}

void transpose_of_matrix()
//2. ������� ���������� ��������� ������� ������� n �� m � ��������� ���������� �������.��������������� �������.
//��������!!!
{
	const int n = 4;
	const int m = 4;
	int arr[n][m]; //n - ���������� ����, m - ���������� ��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 9 + 1;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void matrix_generation_z()
//3. ������� ��������� ������� ������� n �� m.��������� �� ����� ������� :
//0  1  2  3  4
//5  6  7  8  9
//10 11 12 13 14
//...
{
	const int n = 10;
	const int m = 5;
	int cur_number = 0;
	int max_number = n*m;
	int arr[n][m];

	//for (int i = 0; i <n; i++) 
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		arr[i][j] = j+i*m; //����������� ��������� � �����
	//	}
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		arr[i][j] = cur_number; //����������� �� ����� � ����������
	//		cur_number++;
	//	}
	//}

	for (int k = 0; k < max_number; k++)
	{
		cout << "k = " << k << "   " << "i = " << k / m << "   j = " << k % m << endl;
		arr[k / m][k % m] = k; //������� �� ������� �������� �� ������� ������ ��� - ������ ������ �� ���������, � ������� �� ��� ������! �.�. ���������.
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

}

void matrix_generation()
{
	const int n = 10;
	const int m = 5;
	for (int k = 0; k < 100; k++)
	{
		int i = k / m;
		int j = k % m;
		int new_k = j + i * m;
		cout << "k = " << k << "   " << "i = " << i << "   j = " << j << "   new_k = " << new_k << endl;
	}
}