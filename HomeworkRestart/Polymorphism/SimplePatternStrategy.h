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
		IInterface* p; //создаем указатель. сейчас он мусорный, не nullptr
		p = new A; //создается объект класса А, его адрес линкуется и записывается в объект (указатель) р


		while (true)
		{
			p->f(); //указатель на интерфейс, под капотом у него сидит объект класса А
			std::this_thread::sleep_for(std::chrono::seconds(1));
			int rnd = rand() % 2;
			if (rnd > 0)
			{
				delete p; //отдаем операционной системе память, которую она нам ранее выделяла
				p = new B; //здесь указатель меняетс на объект класса В
			}
			else
			{
				delete p;
				p = new A;
			}
		}
	}







}