#pragma once
#include <iostream>

using namespace std;

/*
1. Создать структуру кнопка.
У кнопкки есть 4 состояния:
1. Она выключена.
2. Она горит синим.
3. Она горит красным.
4. Она горит зеленым.

У нее есть действие - "нажать".
Если мы нажали на нее и она была выключена, то она загорится синим.
Если мы нажали на нее и она горела красным, то она с вероятностью `a` загорится зеленым,  иначе выключится.
Если мы нажали на нее и она горела синим, то она загорится зеленым.
Если мы нажали на нее и она горела зеленым, то она загорится красным.
Также у кнопки есть параметр - максимальное число нажатий, как только мы нажали такое количество раз, она выключается и больше ни на что не реагирует.

выкл -> синий -> зеленый -> красный -> Р(А)зеленый + Р(1-А)выкл

Пока так:
Тесты с этой кнопкой:
1. Создать кнопку, у которой максимальное кол-во нажатий 10 и случайный шанс `a`.
Нажать на нее 15 раз и после каждого нажатия выводить на экран ее цвет.

2. Создать 2 кнопки с рандомными параметрами макс нажатий и одинаковыми `a`.
Нажимать их поочереди, выводить каждый раз цвет обоих на экран.
Как только одна из них выключится - закончить.
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
	//0 - выкл; 1 - синий; 2 - зеленый; 3 - красный; 4 - выключено по причине переполнения
	int state=0;
	int count_of_press = 0;
	int press_limit;
	int a_prob_red_green_or_red_off; //вероятность перейти в зеленый

public:
	//конструкторы
	Button(int press_limit_, int a_prob_red_green_or_red_off_)
	{
		press_limit = press_limit_;
		a_prob_red_green_or_red_off = a_prob_red_green_or_red_off_;
	}
	
	//метод
	void print_curr_state() //синий, зеленый, красный, выкл
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