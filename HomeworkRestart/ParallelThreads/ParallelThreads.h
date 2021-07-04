#pragma once
#include <iostream>
#include <thread>
#include <mutex>

namespace ParallelThreads
{
	std::mutex m1;
	bool is_now_print_A = false;
	
	void Test2(char ch) //вызываемая функция из инициирующего потока
	{
		for (int i = 0; i < 1000000; i++)
		{
			for (int j =0; j<1000000; j++ )
			{
				if (!is_now_print_A) //если сейчас не время печатания А
				{
					//m1.lock(); //если mutex сейчас красный, то ждем пока он станет зеленым, никуда не идем
					//как только mutex стал зеленым, идем дальше и сразу же делаем mutex красным, закрываем за собой ворота перед вторым
					std::cout << ch << std::endl;
					//m1.unlock(); //безусловно делаем mutex зеленым, т.е. открываем ворота
					is_now_print_A = true;
				}
			}
		}
	}
	
	void Test1() //инициирующий поток, главный, основной поток - не связано никак с его приоритетом
		//но при этом, тест1 ждет второго на строке thread1.join();
	{
		//Test2();
		
		std::thread thread1(Test2,'B');

		for (int i = 0; i < 1000000; i++)
		{
			for (int j = 0; j < 1000000; j++)
			{
				if (is_now_print_A) //если сейчас время печатания А
				{
					//m1.lock();
					std::cout << 'A' << std::endl;
					//m1.unlock();
					is_now_print_A = false;
				}
			}
		}

		thread1.join(); //ожидаем, пока тред 1 закончит свое выполнение. 
		//Эта команда останаливает процесс, в котором она вызвана пока не будет закончено выполнение thread1 (Test2)
	}

	int CalculateSumm(vector<int>& vec, int index_start, int index_end)
	{
		int summ = 0;
		//while (index_start != index_end) //запись тождественна записи через for ниже
		for (int i= index_start; i < index_end; i++)
		{
			//summ += vec[index_start];
			summ += vec[i];
			//index_start++;
		}
		std::cout << summ << std::endl;
		return summ;
	}

	void Test3()
	{
		vector<int> vec;
		for (int i = 0; i < 10000000; i++)
		{
			vec.push_back(1);
		}
		
		auto t1 = std::chrono::high_resolution_clock::now();
		
		CalculateSumm(vec, 0, vec.size());
		
		
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "Time: " << duration << std::endl;
	}

	void Test4()
	{
		vector<int> vec;
		for (int i = 0; i < 10000000; i++)
		{
			vec.push_back(1);
		}

		auto t1 = std::chrono::high_resolution_clock::now();

		CalculateSumm(vec, 0, vec.size()/2);
		CalculateSumm(vec, vec.size() / 2, vec.size());

		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "Time: " << duration << std::endl;
	}

	void Test5(int threads_count)
	{
		vector<int> vec;
		for (int i = 0; i < 10000000; i++)
		{
			vec.push_back(1);
		}

		auto t1 = std::chrono::high_resolution_clock::now();

		//std::thread th1([&vec]()
		//	{
		//		std::cout << CalculateSumm(vec, vec.size() / 2, vec.size()) << std::endl;
		//	});

		std::vector<std::thread> threads;

		int elems_per_thread = vec.size() / threads_count;

		for (int i = 0; i < threads_count; i++)
		{
			threads.push_back(std::thread(CalculateSumm, std::ref(vec), i*elems_per_thread, (i+1)*elems_per_thread));
		}

		for (int i = 0; i < threads_count; i++)
		{
			threads[i].join();
		}

		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "Time: " << duration << std::endl;
	}

	void Test6()
	{
		struct A
		{
			int _b = 4;
			int _c = 7;
		};

		class B
		{
		private:
			int _b = 4;
			int _c = 7;
		};
		
		class C
		{
		private:
			int _b = 4;
			int _c = 7;
		public:
			C(int b, int c)
			{
				_b = b;
				_c = c;
			}
		};

		struct D
		{
			int _b = 4;
			int _c = 7;
		
			D()
			{
			}
			
			D(int b, int c)
			{
				_b = b;
				_c = c;
			}
		};

		A a1;
		A a2{ 5,8 }; //это работает, потому что все поля у А - открытые
		//A a3( 5,8 );
		
		B b1;
		//B b2{ 5,8 };
		//B b3( 5,8 );
		
		//C c1;
		C c2{5,8};
		C c3(5,8);

		D d1;
		D d2{ 5,8 };
		D d3(5, 8);
	}

	
	int x = 10;
	int y = 10;
	int dx = 1;
	int dy = 0;
	int ex = 20;
	int ey = 20;
	void Test8()
	{
		while (true)
		{
			Console.Print(x, y, ' ');
			if ((x+dx) > 0 && (x+dx) < 140)
			{
				x += dx;
			}
			if ((y+dy) > 0 && (y+dy) < 140)
			{
				y += dy;
			}
			Console.Print(x, y, '*');

			Console.Print(ex, ey, ' ');

			int edx = std::rand() % 3 - 1;
			int edy = std::rand() % 3 - 1;

			if ((ex + edx) > 0 && (ex + edx) < 140)
			{
				ex += edx;
			}
			if ((ey + edy) > 0 && (ey + edy) < 140)
			{
				ey += edy;
			}
			Console.Print(ex, ey, '@');

			std::this_thread::sleep_for(std::chrono::milliseconds(60));
		}
	}
	void Test7()
	{
		std::thread th1(Test8);

		while (true)
		{
			char ch = _getch();
			switch (ch)
			{
			case 'w': dx = 0; dy = -1; break;
			case 'a': dx = -1;dy = 0; break;
			case 'd': dx = 1; dy = 0; break;
			case 's': dx = 0; dy = 1; break;
			}
		}
	}

	std::mutex dead_lock_mutex1;
	std::mutex dead_lock_mutex2;

	void DeadLockFunc1()
	{
		//...some actions..0 //
		
		dead_lock_mutex1.lock();

		//...some actions..1 //

		dead_lock_mutex2.lock();

		//...some actions..2 //

		dead_lock_mutex1.unlock();

		//...some actions..3 //

		dead_lock_mutex2.unlock();

		//...some actions..4 //
	}

	void DeadLockFunc2()
	{
		//...some actions..5 //

		dead_lock_mutex2.lock();

		//...some actions..6 //

		dead_lock_mutex1.lock();

		//...some actions..7 //

		dead_lock_mutex2.unlock();

		//...some actions..8 //
		
		dead_lock_mutex1.unlock();
		
		//...some actions..9 //
	}

	void DeadLockTest()
	{
		std::thread th1(DeadLockFunc1);
		std::thread th2(DeadLockFunc2);
		th1.join();
		th2.join();

	}











}