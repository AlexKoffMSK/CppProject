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
			//Если mutex до этого был зелёный, то функция проходит через эту строку и закрывает за собой (делает красным). 
			//Если до этой строки mutex красный, то ждём (тред спит) пока станет зеленым и продолжаем выполнение функции, проходя через mutex делая его красным.
			//if (is_allow_to_go == false)
			//{
			//	continue;
			//}
			//is_allow_to_go = false;
			std::cout << 'A';
			std::cout << ch;
			std::cout << std::endl;
			//is_allow_to_go_a = false;
			mutex_for_print.unlock(); //здесь открывает, делаем зеленым
			//mutex_for_print1.unlock(); //здесь открывает, делаем зеленым
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

		SetThreadAffinityMask(thread_print_a.native_handle(), 1 << 0); //выполнение функции аллокировано на 0 ядро процессора
		//SetThreadAffinityMask(thread_print_aa.native_handle(), 1 << 2); //выполнение функции аллокировано на 0 ядро процессора
		SetThreadAffinityMask(thread_print_b.native_handle(), 1 << 3); //выполнение функции аллокировано на 3 ядро процессора

		thread_print_a.join(); //эта строчка остановит выполнение программы и будет ждать окончание выполнения потока а - по смыслу должно было бы быть wait, а не join
		//thread_print_b.join(); //эта строчка остановит выполнение программы и будет ждать окончание выполнения потока b - по смыслу должно было бы быть wait, а не join
	}










}