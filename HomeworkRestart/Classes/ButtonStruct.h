#pragma once
#include <iostream>

using namespace std;

/*
1. ������� ��������� ������.
� ������� ���� 4 ���������:
1. ��� ���������.
2. ��� ����� �����.
3. ��� ����� �������.
4. ��� ����� �������.

� ��� ���� �������� - "������".
���� �� ������ �� ��� � ��� ���� ���������, �� ��� ��������� �����.
���� �� ������ �� ��� � ��� ������ �������, �� ��� � ������������ `a` ��������� �������,  ����� ����������.
���� �� ������ �� ��� � ��� ������ �����, �� ��� ��������� �������.
���� �� ������ �� ��� � ��� ������ �������, �� ��� ��������� �������.
����� � ������ ���� �������� - ������������ ����� �������, ��� ������ �� ������ ����� ���������� ���, ��� ����������� � ������ �� �� ��� �� ���������.

���� -> ����� -> ������� -> ������� -> �(�)������� + �(1-�)����

���� ���:
����� � ���� �������:
1. ������� ������, � ������� ������������ ���-�� ������� 10 � ��������� ���� `a`.
������ �� ��� 15 ��� � ����� ������� ������� �������� �� ����� �� ����.

2. ������� 2 ������ � ���������� ����������� ���� ������� � ����������� `a`.
�������� �� ���������, �������� ������ ��� ���� ����� �� �����.
��� ������ ���� �� ��� ���������� - ���������.
*/

//struct A_Prob_of_Green_or_Off
//{
//	int green = rand() % 101;
//	int off = 1 - green;
//};
//
//struct ButtonColorLine
//{
//	int blue = 1;
//	int green = 2;
//	int red = 3;
//	A_Prob_of_Green_or_Off prob_gr_off;
//};
//
//struct Button
//{
//	int on_off = 0;
//	int press_limit = 10;
//	int counts_from_off = 0;
//	ButtonColorLine butt_color_line;
//};
//
//void pressing_butt0()
//{
//	Button butt;
//
//	int press_counts = 15;
//
//	for (int i = 0; i < press_counts; i++)
//	{
//		butt.counts_from_off++;
//		if (butt.counts_from_off <= butt.press_limit)
//		{
//			butt.on_off * 
//		}
//		else
//		{
//			butt.on_off = 0;
//		}
//	}
//
//
//}

class Button
{
private:
	//0 - ����; 1 - �����; 2 - �������; 3 - �������; 4 - ��������� �� ������� ������������
	int state=0;
	int count_of_press = 0;
	int press_limit;
	int a_prob_red_green_or_red_off; //����������� ������� � �������

public:
	//������������
	Button(int press_limit_, int a_prob_red_green_or_red_off_)
	{
		press_limit = press_limit_;
		a_prob_red_green_or_red_off = a_prob_red_green_or_red_off_;
	}
	
	//�����
	void print_curr_state() //�����, �������, �������, ����
	{
		if (state == 0 || state == 4)
		{
			cout << "Off" << endl;
		}
		if (state == 1)
		{
			cout << "Blue" << endl;
		}
		if (state == 2)
		{
			cout << "Green" << endl;
		}
		if (state == 3)
		{
			cout << "Red" << endl;
		}
	}

	void press()
	{
		count_of_press++;
		if (count_of_press > press_limit)
		{
			state = 4;
		}
		else if (state == 0)
		{
			state = 1;
		} 
		else if (state == 1)
		{
			state = 2;
		}
		else if (state == 2)
		{
			state = 3;
		}
		else if (state == 3)
		{
			int random_value = rand() % 100;
			
			if (random_value < a_prob_red_green_or_red_off)
			{
				state = 2;
			}
			else
			{
				state = 0;
			}
		}
	}

	bool is_on()
	{
		if (state == 0 || state == 4)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};

void f_butt_r()
{
	Button butt0(10, 40);
	butt0.print_curr_state();

	Button butt1(5, 20);
	butt1.print_curr_state();

	butt0.press();

	butt0.print_curr_state();
	butt1.print_curr_state();

}

void f_butt_r1()
{
	Button butt0(10, 50);
	butt0.print_curr_state();

	for (int i = 0; i < 20; i++)
	{
		butt0.press();
		butt0.print_curr_state();
	}
}

void f_2butt_1()
{
	Button butt0(10, 90);
	Button butt1(20, 70);
	
	do
	{
	butt0.press();
	cout << "1: ";
	butt0.print_curr_state();
	butt1.press();
	cout << "2: ";
	butt1.print_curr_state();
	} while (butt0.is_on() || butt1.is_on());
}

void f_butt3()
{
	Button f1(10,50);
	f1.press();
	//f1.count_of_press = 100;
	f1.press();
	f1.print_curr_state();
}