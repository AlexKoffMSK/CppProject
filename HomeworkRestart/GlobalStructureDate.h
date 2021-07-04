#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;

	//������������:
	Date(int m, int d) 
		//����� ������� �����������, ���� ��������� Date ����� �� ��� � �������� ��������� (Date), � ����� ����������� ���������
		//� �������� ������� ����� ������������� - ������ ���� �� �������������� �����-�� ��������� ���������
	{
		year = 2021;
		month = m;
		day = d;
	}

	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	Date(int d) //������ ����������� - ��������, ��� ���������� ��������� ���������
	{
		year = 2020;
		month = 1;
		day = d;
	}

	Date()
	{
	}

	int date_to_int()
	{
		return year * 10000 + month * 100 + day;
	}

	friend bool operator<(Date x, Date y)
	{
		return x.date_to_int() < y.date_to_int();
	}

	friend bool operator>(Date x, Date y)
	{
		return x.date_to_int() > y.date_to_int();
	}

	friend bool operator==(Date x, Date y)
	{
		return x.date_to_int() == y.date_to_int();
	}

	friend bool operator!=(Date x, Date y)
	{
		return !(x==y);
	}

};

Date get_random_date_of_birth()
{
	Date rnd_date;

	rnd_date.year = rand() % (2021 - 1921 + 1) + (1921);
	rnd_date.month = rand() % 12 + 1;
	rnd_date.day = rand() % 31 + 1;

	return rnd_date;
}

int convert_date_to_int(Date x)
{
	return x.year * 10000 + x.month * 100 + x.day;
	
	//2020-6-5					  = 20200000 + 600 + 5 = 20200605                
	//2020-11-7					  = 20200000 + 1100 + 7 = 20201107    
}

bool is_date_x_is_later_date_y(Date x, Date y)
{
	//double date_x = (x.year + x.month / 100.0 + x.day / 10000.0); //����� �������� .0 ����� ������������� ����� ����� �������
	//cout << fixed << setprecision(18) << date_x << endl;
	//double date_y = (y.year + y.month / 100.0 + y.day / 10000.0);
	//cout << fixed << setprecision(18) << date_y << endl;

	return convert_date_to_int(x) > convert_date_to_int(y);
}

//��� ������� ������ cout �������� ������� ���� Date
//ostream& operator<<(ostream& os, ...) - ���������������� ������������
//Date d - ��� ���, ������� ����� ����������, d - ��� ���
//54 ������ - ��� ��������������� ����� ����, ��� ������ cout ������������ ��� os
//return os - ���������������� ������������, ������� ������ ���� ����
ostream& operator<<(ostream& os, Date d)
{
	os << d.year << '-' << setfill('0') << setw(2) << d.month << '-' << setw(2) << setfill('0') << d.day;
	return os;
}

void print_date(Date x)
{
	//cout << x.year << '-' << setfill('0') << setw(2) << x.month << '-' << setw(2) << setfill('0') << x.day << endl;
	cout << x << endl;
}

/*
���� < ���� = bool
���� > ���� = bool
���� = ���� 
���� != ����

*/