#pragma once
#include <cassert>
#include <vector>
#include "ConsoleHelper.h"

namespace ConsoleFunctions
{

void g0()
{
	Console.Print(10, 5, '*'); //������ �������� - ��� ������ �����, ������ �������� - ������ ������, ������ �������� - ��� ��������
}

void g1()
{
	for (int i = 0; i < 10; i++)
	{
		Console.Print(i, i, '*');
	}
}

void print_bar(int x, int y, int lenght, char ch, Color c) //��������� �� ���� ��� ���������� � �����. ������ ������������ �����, ������ ����� ������� �������� ��������� �����������.
{
	//x - ������ ����� - left, y - ������ ������ - top
	assert(y >= lenght);
	for (int i = 0; i < lenght; i++)
	{
		Console.Print(x, y-i, ch, c);
	}
}

void print_changed_bar(int x, int y, int lenght_old, int lenght_new, char ch, Color c) //lenght_old bar ��� ���������. ����� �� ���� �� ����� ���������� lenght_new 
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

void print_arr_histogramm(vector<int> arr, int max_height, char ch) //��������� ������ �� ���� �������� ��� �����������
{
	for (int i = 0; i < arr.size();i++)
	{
		print_bar(10+i, max_height, arr[i], ch, Color::White);
	}
}












}