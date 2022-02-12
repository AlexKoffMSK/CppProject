#pragma once
#include <iostream>
#include <memory>

namespace PolymorphismVirtual
{
//виртуальный деструктор//
	class Base
	{
	public:
		int c = 0;
		virtual void foo()
		{
			std::cout << "Base" << std::endl;
		}

		virtual ~Base()
		{
			std::cout << "Destructor Base: C: " << c << std::endl;
		}

	};

	class A : public Base
	{
	public:
		void foo() override
		{
			std::cout << "A" << std::endl;
		}
		~A()
		{
			std::cout << "Destructor A" << std::endl;
		}
	};

	class B : public Base
	{
	public:
		void foo() override
		{
			std::cout << "B" << std::endl;
		}
		~B()
		{
			std::cout << "Destructor B" << std::endl;
		}
	};

	void Bar(Base& b)
	{
		b.foo();
	}

	void Test()
	{
		A a;
		B b;
		a.c = 3;
		b.c = 4;
		Bar(a);
		Bar(b);
	}

	void Test1()
	{
		A* a = new A;

		a->foo();

		delete a;
		std::cout << "!" << std::endl;
	}

	void Test2()
	{
		Base* base = new A;

		base->foo();

		delete base;
		std::cout << "!" << std::endl;
	}

	class IReceiver
	{
	public:
		virtual void Receive(int x) = 0;
		virtual ~IReceiver() = default;
	};

	class Reader
	{
	public:
		std::vector<std::unique_ptr<IReceiver>> _receivers;

		void ReadFromKeyboardAndPushToReceivers()
		{
			while (true)
			{
				int k;
				std::cin >> k;
				std::cout << "Read from keyboard: " << k << std::endl;
				for (auto& receiver : _receivers)
				{
					receiver->Receive(k);
				}
			}
		}
	};

	class SummOfReceivedData : public IReceiver
	{
		int _summ = 0;

	public:
		void Receive(int x)
		{
			_summ += x;
			std::cout << "SummOfReceivedData: + x " << x << ", Summ: " << _summ << std::endl;
		}
	};

	class PrintReceivedXAndMultipleTwice : public IReceiver
	{
	public:
		void Receive(int x)
		{
			std::cout << "MultipleTwice X: " << x * 2 << std::endl;
		}
	};

	void Test3()
	{
		std::unique_ptr<Reader> reader(new Reader);
		
		//SummOfReceivedData* summ_of_received_data = new SummOfReceivedData;
		//PrintReceivedXAndMultipleTwice* print_received_x_and_mult_twice = new PrintReceivedXAndMultipleTwice;
		
		reader->_receivers.push_back(std::unique_ptr<IReceiver>(new SummOfReceivedData));
		reader->_receivers.push_back(std::unique_ptr<IReceiver>(new PrintReceivedXAndMultipleTwice));
		reader->ReadFromKeyboardAndPushToReceivers();
	}
}