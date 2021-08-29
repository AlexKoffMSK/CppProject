#pragma once
#include <iostream>
#include <chrono>
#include <thread>


namespace SimplePatternStrategy
{
	class IInterface
	{
	public:
		virtual void f() = 0; //чистая функция - виртуальный метод, у которого нет никакой реализации
		virtual ~IInterface() = default;
	};

	class A :public IInterface
	{
	public:
		void f()
		{
			std::cout << "Hello" << std::endl;
		}
	};

	class B :public IInterface
	{
	public:
		void f()
		{
			std::cout << "World" << std::endl;
		}
	};
	
	void Test1()
	{
		//A a;
		//B b;
		IInterface* p = new A;


		while (true)
		{
			p->f();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			int rnd = rand() % 2;
			if (rnd > 0)
			{
				delete p;
				p = new B;
			}
			else
			{
				delete p;
				p = new A;
			}
		}
	}







}