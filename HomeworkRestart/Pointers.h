#pragma once
#include<iostream>

namespace Pointers
{
	void f()
	{
		int a=3;
		int b=4;
		//char c;

		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		//std::cout << &b << '-' << std::ios::dec<<&b << std::endl;
		//std::cout << &c << '-' << std::ios::dec<<&c << std::endl;

		int* pointer_to_a = &a; //������� ���������� ��� �������� ������ ���������� int a. 
		//int* - ��� ��������� �� int, ������� ������ ����� ������� ����������
		//��������� int* ������� �� ������ ������, ��� ������� int

		//std::cout << &adr_a << std::endl;
		std::cout << pointer_to_a << std::endl;

		pointer_to_a = &b;

		//std::cout << &adr_a << std::endl;
		std::cout << pointer_to_a << std::endl; //������� ��������, �.�. �����
		std::cout << *pointer_to_a << std::endl; //������� ��� �� ��� �����, � �� - ��� ��� ��� ����, ���������� - ���������������
		
		*pointer_to_a = 5; //�������� ������ (� ��������� � ����, � �� ��� ����������)
		
		std::cout << b << std::endl;
	}

	void f05()
	{
		int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
		int* pointer_to_3 = &arr[3];
		int* pointer_to_4 = &arr[4];
		std::cout << pointer_to_3 - pointer_to_4 << std::endl;
		//����� �������: (p1 - p0) / sizeof (int) = (4 - 3) / 4 - ��� � ������ � int = ������� ����� ����� ����� ��������, �� ������� ������
		std::cout << pointer_to_4 - pointer_to_3 << std::endl;

		int* pointer_to_last_element_of_arr = &arr[std::size(arr) - 1]; //����� ��������� ������ � �������
		int* pointer_to_zero_element_of_arr = &arr[0];
		std::cout << pointer_to_last_element_of_arr - pointer_to_zero_element_of_arr + 1 << std::endl;// ���������� ����� ����� ����������� � int-��
	}

	void f1()
	{
		int a = 5;
		int b = 10;

		int* pointer_to_a = &a; //� ��������� pointer_to_a �������� ����� a
		int* pointer_to_b = &b;

		std::cout << pointer_to_a << std::endl;
		std::cout << pointer_to_b << std::endl;

		std::cout << pointer_to_a - pointer_to_b << std::endl;
		std::cout << pointer_to_b - pointer_to_a << std::endl;
	}

	void f15()
	{
		int arr[10] = {1,2,3,4,5,6,7,8,9,10};
		//int* pointer = &arr[0];
		//pointer = (int*)((char*)pointer + 1); 
		//(char*)pointer - ����������� pointer ��� ��������� �� char, char - ��� 1 ����
		//(char*)pointer+1 - �������� pointer �� 1 char (�� 1 ����)
		//(int*)((char*)pointer + 1) - ��������� ((char*)pointer + 1) ����������� ��� ��������� �� int 

		//std::cout << *pointer << std::endl;

		//������� �� ����� ��� �����, ������� ������ � ������. ����� �������� � ���� �����
		
		//for (int z = 0; z < 65535; z++)
		//{
		//	std::cout << z << " - ";
		//	std::cout << (int)(*((unsigned char*)&z + 0)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 1)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 2)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&z + 3)) << endl;
		//}
		//for (int i = 0; i < std::size(arr); i++) //����� ���� ������������ for-auto ����
		//{
		//	std::cout << (int)(*((unsigned char*)&arr[i]+0)) << ' ';
		//	std::cout << (int)(*((unsigned char*)&arr[i]+1)) << ' '; 
		//	std::cout << (int)(*((unsigned char*)&arr[i]+2)) << ' '; 
		//	std::cout << (int)(*((unsigned char*)&arr[i] + 3)) << endl;
		//	//������-������:
			//&arr[i] - ����� ����� i-�� ������ ������� (��� ��������� �� int)
			//(char*)&arr[i] - ������������ ��� ��� ��������� �� char (��� ��������� �� char)
			//*(char*)&arr[i] - �������������� ��������� �� char (��� char)
			//(int)(*(char*)&arr[i]) - ����������� ��� �� ��� int (��� int)
		//
		//}
		std::cout << *(int*)((char*)&arr[0] - 1) << endl;
	}

	void f2()
	{
		int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
		//int* pointer = &arr[0];
		//std::cout << *pointer << std::endl;
		//pointer++; //����� �� ��������� int, ��������� �� �����
		//std::cout << *pointer << std::endl;
		//(*pointer)++; //����� ��������� ��������� �������� � 1-� ������ �������
		//std::cout << arr[1] << std::endl;

		//int* pointer = &arr[0];
		//int* pointer_of_end = &arr[size(arr)-1];
		
		//while (pointer <= pointer_of_end)
		//{
		//	cout << pointer << ' ';
		//	cout << *pointer << endl;
		//	pointer++;
		//}

		//for (int* pointer = &arr[0]; pointer <= &arr[size(arr) - 1]; pointer++)
		for (int* pointer = &arr[0]; pointer < arr + size(arr); pointer++)
		{
			cout << pointer << ' ';
			cout << *pointer << endl;
		}
	}

	/*
	������� ������ {10,11,12,13,14,15,16,17,18,19};
	
	1. ������� �� ����� ����� 3, 6 � 7 �����.
	
	2. ������� ��������� p, ������� ����� �������� ��  2 ������ �������.
		����������� ��� ���, ���� �� ������� �� 6 ������ �������.
		������ �� ����� ��������, �� ������� ��������� p.
	
	3. ������� 2 ���������. p - ������� �� 3� ������, q - �� ������������.
		������� ���������� ����� ����� ���� (�� ������� �� �����). � ������ ����� ��� 4 (14,15,16,17).
	
	4. ������� 2 ���������. p - ������� �� 3� ������, q - �� ������������.
		������� ���������� ���� �����, ������ �� �����. (�.�. 13, 14,15,16,17, 18).
	
	4.1. ���� �����, �� � �������� ������� (18, 17, 16, 15,14,13).
	
	5. �������� � ��������� p ����� ��������� ������ �������.
		������� true, ���� ��� ������ ��������� � ����� ����� �������, false �����.

	*/
	
	void task1()
	{
		int arr[10] = { 10,11,12,13,14,15,16,17,18,19 };
		//int* pointer_3 = &arr[3]; //������ ��������� �� ������� �������
		//int* pointer_6 = &arr[6];
		//int* pointer_7 = &arr[7];
		//std::cout << pointer_3 << std::endl; //��������� �� ����� ����� �������� ������� � ������
		//std::cout << pointer_6 << std::endl;
		//std::cout << pointer_7 << std::endl;
		
		//int* pointer_a = &arr[2]; //������ ��������� �� ������� �������
		//std::cout << pointer_a << std::endl; //��������� �� ����� ����� �������� ������� � ������
		//pointer_a = pointer_a + 4; //��������� ������� �� +4 ������������ ���������� �������� �������
		//std::cout << pointer_a << std::endl; //����� �� ����� ������ ���������� � ������, �� ������� ��������� ���������
		//std::cout << *pointer_a << std::endl; //���������������� ��������� - ��������� �� ����� �������� ����������, �� ������� ��������� ���������

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr)-1-1];// ������ "-1" - ������� �� ������� ������� � ���������� ��������, ������ "-1" - � ��������������
		//std::cout << pointer_q - (pointer_p+1) << std::endl;

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr) - 1 - 1];// ������ "-1" - ������� �� ������� ������� � ���������� ��������, ������ "-1" - � ��������������
		////for (int* pointer = &arr[0]; pointer < arr + size(arr); pointer++)
		//for (int* pointer = pointer_p; pointer <= pointer_q; pointer++)
		//{
		//	std::cout << *pointer << std::endl;
		//}

		//int* pointer_p = &arr[3];
		//int* pointer_q = &arr[size(arr) - 1 - 1];// ������ "-1" - ������� �� ������� ������� � ���������� ��������, ������ "-1" - � ��������������
		////for (int* pointer = &arr[0]; pointer < arr + size(arr); pointer++)
		//for (int* pointer = pointer_q; pointer >= pointer_p; pointer--)
		//{
		//	std::cout << *pointer << std::endl;
		//}

		int* pointer_p = &arr[rand()%size(arr)]; //������ ��������� �� ��������� ������� �������
		if (pointer_p < &arr[size(arr) / 2])
		{
			std::cout << "True" << endl;
			std::cout << pointer_p << std::endl; //debug-�����
			std::cout << &arr[size(arr) / 2] << std::endl; //debug-�����
		}
		else
		{
			std::cout << "False" << endl;
			std::cout << pointer_p << std::endl; //debug-�����
			std::cout << &arr[size(arr) / 2] << std::endl; //debug-�����
		}
	}

	/*
	  8 
	  9
	1 0
	1 1
	1 2

	8 0
	9 0
	0 1
	1 1
	2 1

	8
	9
	A
	B
	C
	D
	E
	F
	1 0
	1 1
	1 2
	...
	1 9
	1 A
	1 B
	1 C
	1 D
	1 E
	1 F
	2 0
	...
	F F
	1 0 0
	1 0 1
	1 0 2
	...
	1 0 F
	1 1 0
	...
	1 2 A
	1 2 B
	...
	1 F A
	1 F B
	...
	F F F
	1 0 0 0
	... ��� �� � ���������������� �������


	��������� � ������� ��������� �� ��������� 255 (255 ����! - ��������� ������ �����)

	0
	1
	2
	...
	254
	255
	1 0
	1 1
	1 2
	...
	1 255
	2 0
	2 1
	2 2
	...
	255 254
	255 255
	1 0 0


	*/

	int* find_max_elem_in_segment_and_return_pointer(int* pointer_left_bound, int* pointer_right_bound) //��������� �� ����� � ������ ������� �������,
		//���������� ��������� �� ������������ ������� ���������
	{
		int* pointer_of_max_elem = pointer_left_bound;
		for (int* pointer = pointer_left_bound; pointer <= pointer_right_bound; pointer++)
		{
			if (*pointer >= *pointer_of_max_elem)
			{
				pointer_of_max_elem = pointer;
			}
		}
		return pointer_of_max_elem;
	}

	int* find_min_elem_in_segment_and_return_pointer(int* pointer_left_bound, int* pointer_right_bound) 
		//��������� �� ����� � ������ ������� �������,
		//���������� ��������� �� ����� ������ ������� ���������
	{
		int* pointer_of_min_elem = pointer_left_bound;
		for (int* pointer = pointer_left_bound; pointer <= pointer_right_bound; pointer++)
		{
			if (*pointer <= *pointer_of_min_elem)
			{
				pointer_of_min_elem = pointer;
			}
		}
		return pointer_of_min_elem;
	}

	//������ �������� � ������� ��������� � ������
	void Test666(std::vector<int>& vec, std::vector<int>* vec1)
	{
		int a = 5;
		int* b = &a;
		int arr[10];
		int* c = arr;
		//c[4] = 8;
		//arr[11] = 8;
		c[21] = 8;
		int* d = &arr[0];
		b[5] = 3;

		vec[1];
		*(vec1 + 1);
	}
}