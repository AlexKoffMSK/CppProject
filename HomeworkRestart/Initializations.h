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
		A ex; //����� ���� ������ ex.a � ex.b ����� ������
		ex.a = 1;//����� ���� ������ ex.a=1� ex.b ����� ������
		ex.b = "Example";//����� ���� ������ ex.a=1� ex.b ����� Example
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
		B ex(1,"Example"); //� ���� ������ ex.a = 1, ex.b = Example
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
		C ex(1);// ��� ��� ����������� ��������� �������� ������ ���������� �, �� �������� ����� ������ ����. ����� ���� ������ ex.a = 1, ex.b = ��������� �����
		ex.b = "Example"; //��� ��� ����������� ��������� �������� ������ ���������� �, ������������������� b ������, �� ����� ����-��������� ��� ��������
		
		//C ex1; - �������� �� �����, �.�. �� �������� ���� �����������. � ����� �� ����� ���� - ������� ��������� ���������, ���������� �����������.
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
		D ex(1);// ��� ��� ����������� ��������� �������� ������ ���������� �, �� �������� ����� ������ ����. ����� ���� ������ ex.a = 1, ex.b = ��������� �����
		ex.b = "Example"; //��� ��� ����������� ��������� �������� ������ ���������� �, ������������������� b ������, �� ����� ����-��������� ��� ��������

		D ex1; //��� �������� ������ ��� �� ��������� ������ ���������� ������������ � ��������� ����. ����� ��������� ��� �� ����������
		//ex1.a ex1.b - ��������

		ex1.a = 1;
		ex1.b = "Example";
		//������ ������������� ��������
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
		F ex; //ex.a = 1 - ������ ��� �� ��������� �����, ������ ��� �� ��� ������������� �� ����� �������� ����. ex.b - �����
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
		G ex; //ex.a = 1 - ������ ��� �� ��������� �����, ������ ��� �� ��� ������������� �� ����� �������� ����. ex.b - �����
		ex.b = "Example";
	}

	struct J
	{
		int a=1; //� ��� ������, ��� � ����� ��� ������� ������� �� ������������� - ��� ����� ��������� ����������� �������� 1
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
			: a1(a_, b_) //������ ������ �1 � ������� ������������ � ����� �����������, � ������� �� ������ ��� ��������� �_ � b_
			//��������� : ��������� ���������������� ������� � ������� ������������� �������, ������� �� ��������������
			//� ������ ������ �������������� ������ �1 � � ������� ��� ������������, ������� ��������� int � string
		{
		}

	};

	void f10()
	{
		A2 aaa(1, "Example");
	}




}