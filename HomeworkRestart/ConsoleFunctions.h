#pragma once
#include <cassert>
#include <vector>
#include "ConsoleHelper.h"

namespace ConsoleFunctions
{

void g0()
{
	Console.Print(10, 5, '*'); //первый аргумент - это отступ слева, второй аргумент - отступ сверху, третий аргумент - что печатать
}

void g1()
{
	for (int i = 0; i < 10; i++)
	{
		Console.Print(i, i, '*');
	}
}

void print_bar(int x, int y, int lenght, char ch, Color c) //принимает на вход две координаты и длину. рисует вертикальную линию, нижняя часть которой является введенной координатой.
{
	//x - отступ слева - left, y - отступ сверху - top
	assert(y >= lenght);
	for (int i = 0; i < lenght; i++)
	{
		Console.Print(x, y-i, ch, c);
	}
}

void print_changed_bar(int x, int y, int lenght_old, int lenght_new, char ch, Color c) //lenght_old bar уже нарисован. Нужно на этом же месте нарисовать lenght_new 
{
	assert(y >= lenght_new);

	if (lenght_new < lenght_old)
	{
		for (int i = 0; i < (lenght_old - lenght_new); i++)
		{
			Console.Print(x, (y - lenght_old + 1) + i, ' ');
		}
	}
	else
	{
		for (int i = 0; i < (lenght_new - lenght_old); i++)
		{
			Console.Print(x, (y - lenght_new + 1) + i, ch, c);
		}
	}
}

void print_arr_histogramm(vector<int> arr, int max_height, char ch) //принимает массив на вход печатает его гистограмму
{
	for (int i = 0; i < arr.size();i++)
	{
		print_bar(10+i, max_height, arr[i], ch, Color::White);
	}
}












}