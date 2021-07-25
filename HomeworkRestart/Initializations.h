#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace Initializations
{
	struct A
	{
		int a;
		string b;
	};

	void f()
	{
		A ex; //после этой строки ex.a и ex.b равны мусору
		ex.a = 1;//после этой строки ex.a=1б ex.b равен мусору
		ex.b = "Example";//после этой строки ex.a=1б ex.b равен Example
	}

	struct B
	{
		int a;
		string b;

		B(int a_, string b_)
		{
			a = a_;
			b = b_;
		}
	};

	void f1()
	{
		B ex(1,"Example"); //в этой строке ex.a = 1, ex.b = Example
	}

	struct C
	{
		int a;
		string b;

		C(int a_)
		{
			a = a_;
		}
	};

	void f2()
	{
		C ex(1);// так как конструктор допускает создание только переменной а, то аргумент будет только один. После этой строки ex.a = 1, ex.b = дефолтный мусор
		ex.b = "Example"; //так как конструктор допускает создание только переменной а, проинициализировать b нельзя, но можно пере-присвоить ему значение
		
		//C ex1; - работать не будет, т.к. мы написали свой конструктор. А когда мы пишем свой - базовый дефолтный стирается, становится недоступным.
	}

	struct D
	{
		int a;
		string b;

		D(int a_)
		{
			a = a_;
		}
		D()
		{
		}
	};

	void f3()
	{
		D ex(1);// так как конструктор допускает создание только переменной а, то аргумент будет только один. После этой строки ex.a = 1, ex.b = дефолтный мусор
		ex.b = "Example"; //так как конструктор допускает создание только переменной а, проинициализировать b нельзя, но можно пере-присвоить ему значение

		D ex1; //это работает потому что мы прописали помимо кастомного конструктора и дефолтный тоже. иначе дефолтный был бы недоступен
		//ex1.a ex1.b - мусорные

		ex1.a = 1;
		ex1.b = "Example";
		//теперь переприсвоены значения
	}

	struct E
	{
		int a;
		string b;

		E(int a_)
		{
			a = a_;
		}
		E(int a_, string b_)
		{
			a = a_;
			b = b_;
		}
		E()
		{
		}
	};

	void f4()
	{
		E ex;
		ex.a = 1;
		ex.b = "Example";

		E ex1(1, "Example");
		
		E ex2(1);
		ex2.b = "Example";
	}
	
	struct F
	{
		int a = 1;
		string b;
	};

	void f5()
	{
		F ex; //ex.a = 1 - потому что он рождается таким, потому что мы это зафиксировали на урове создания поля. ex.b - мусор
		ex.b = "Example";
	}

	struct G
	{
		int a;
		string b;

		G()
		{
			a = 1;
		}
	};

	void f6()
	{
		G ex; //ex.a = 1 - потому что он рождается таким, потому что мы это зафиксировали на урове создания поля. ex.b - мусор
		ex.b = "Example";
	}

	struct J
	{
		int a=1; //в тех местах, где а явным или неявным образом не переприсвоена - она будет принимать изначальное значение 1
		string b;

		J(string b_)
		{
			b = b_;
		}
	};

	//void f7()
	//{
	//	H ex("Example");
	//	ex.a = 2;
	//	H ex1 = ex;
	//}

	struct H
	{
		int a=1;
		string b="Example";

		H(int a_)
		{
			a = a_;
		}
		H(int a_, string b_)
		{
			a = a_;
			b = b_;
		}
		H()
		{
		}

	};
		
	//void f8()
	//	{
	//		G ex;
	//		ex.a = 2;
	//		ex.b = "EExample";
	//
	//		G ex1(2, "EExample");
	//
	//		G ex2(2);
	//		ex2.b = "EExample";
	//	}

	struct K
	{
	private:
		int a;
		string b;

	public:
		K(int a_)
		{
			a = a_;
		}
		K(int a_, string b_)
		{
			a = a_;
			b = b_;
		}
		K()
		{
		}

	};

	//void f9()
	//{
	//	J ex;
	//	
	//	J ex1(2, "EExample");
	//
	//	J ex2(2);
	//
	//}


	struct A1
	{
	private:
		int a;
		string b;

	public:
		A1 (int a_, string b_)
		{
			a = a_;
			b = b_;
		}
	};

	struct A2
	{
		A1 a1;
		A2 (int a_, string b_)
			: a1(a_, b_) //создай объект а1 с помощью конструктора с двумя параметрами, в который мы отдали два параметра а_ и b_
			//синтаксис : позволяет инициализировать объекты с помощью конструкторов объекта, который мы инициализируем
			//в данном случае инициализируем объект а1 и с помощью его конструктора, который принимает int и string
		{
		}

	};

	void f10()
	{
		A2 aaa(1, "Example");
	}




}