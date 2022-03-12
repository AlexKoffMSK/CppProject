#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <WinBase.h>

namespace Mutexes
{
	std::mutex mutex_for_print;
	
	//bool is_allow_to_go_a = true;

	void PrintA(char ch)
	{
		int summ = 0;
		while (true) 
		{ 
			//if (!is_allow_to_go_a)
			//{
			//	continue;
			//}
			mutex_for_print.lock(); 
			//���� mutex �� ����� ��� ������, �� ������� �������� ����� ��� ������ � ��������� �� ����� (������ �������). 
			//���� �� ���� ������ mutex �������, �� ��� (���� ����) ���� ������ ������� � ���������� ���������� �������, ������� ����� mutex ����� ��� �������.
			//if (is_allow_to_go == false)
			//{
			//	continue;
			//}
			//is_allow_to_go = false;
			std::cout << 'A';
			std::cout << ch;
			std::cout << std::endl;
			//is_allow_to_go_a = false;
			mutex_for_print.unlock(); //����� ���������, ������ �������
			//mutex_for_print1.unlock(); //����� ���������, ������ �������
			summ++;
			//if (summ % 1000000000 == 0)
			//{
			//	std::this_thread::sleep_for(std::chrono::seconds(1));
			//}
		}
		std::cout << summ << std::endl;
	}

	void PrintB(char ch)
	{
		int summ = 0;
		while (true) 
		{ 
			//if (is_allow_to_go_a)
			//{
			//	continue;
			//}
			mutex_for_print.lock();
			//if (is_allow_to_go == false)
			//{
			//	continue;
			//}
			//is_allow_to_go = false;
			std::cout << 'B';
			std::cout << ch;
			std::cout << std::endl;
			//is_allow_to_go_a = true;
			mutex_for_print.unlock();
			summ++;
		}
		std::cout << summ << std::endl;
	}

	void Test()
	{
		std::thread thread_print_a(PrintA,'a');
		//std::thread thread_print_aa(PrintA,'b');
		std::thread thread_print_b(PrintB,'b');

		SetThreadAffinityMask(thread_print_a.native_handle(), 1 << 0); //���������� ������� ������������ �� 0 ���� ����������
		//SetThreadAffinityMask(thread_print_aa.native_handle(), 1 << 2); //���������� ������� ������������ �� 0 ���� ����������
		SetThreadAffinityMask(thread_print_b.native_handle(), 1 << 3); //���������� ������� ������������ �� 3 ���� ����������

		thread_print_a.join(); //��� ������� ��������� ���������� ��������� � ����� ����� ��������� ���������� ������ � - �� ������ ������ ���� �� ���� wait, � �� join
		//thread_print_b.join(); //��� ������� ��������� ���������� ��������� � ����� ����� ��������� ���������� ������ b - �� ������ ������ ���� �� ���� wait, � �� join
	}










}