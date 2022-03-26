#pragma once
#include <iostream>

using namespace std;


namespace Operators
{

struct Point2D
{
	int x; //ширина
	int y; //высота

	//----------конструкторы----------
	Point2D(int x_, int y_)
	{
		x = x_;
		y = y_;
	}
	//----------метод----------
	Point2D addition(Point2D p)
	{
		Point2D result_point(0, 0);
		result_point.x = x + p.x;
		result_point.y = y + p.y;

		return result_point;
	}

	friend Point2D operator+(Point2D p1, Point2D p2)
	{
		Point2D result_point(0, 0);
		result_point.x = p1.x + p2.x;
		result_point.y = p1.y + p2.y;
		return result_point;
	}

	friend Point2D operator-(Point2D p1, Point2D p2)
	{
		Point2D result_point(0, 0);
		result_point.x = p1.x - p2.x;
		result_point.y = p1.y - p2.y;
		return result_point;
	}

	friend int operator*(Point2D p1, Point2D p2)
	{
		return p1.x * p2.x + p1.y * p2.y;
	}

	friend int operator*(Point2D p1, int a)
	{
		return p1.x * a + p1.y * a;
	}

	friend int operator*(int a, Point2D p1)
	{
		return p1 * a;
	}

	friend ostream& operator<<(ostream& os, Point2D p)
	{
		os << p.x << ',' << p.y;
		return os;
	}
};

Point2D addition(Point2D p1, Point2D p2)
{
	Point2D result_point(0,0);
	result_point.x = p1.x + p2.x;
	result_point.y = p1.y + p2.y;

	return result_point;
}

void ff1()
{
	Point2D p1(10,20);
	Point2D p2(15,4);
	Point2D p3 = addition(p1, p2);
	Point2D p4 = p1.addition(p2);
	Point2D p5 = p2.addition(p1);
	Point2D p6 = p1 + p2;
	Point2D p7 = operator+(p1,p2); //запись аналогичная 85 строке

	cout << p1 + p2 << endl;
	cout << p1 - p2 << endl;
	cout << p1 * p2 << endl;
	cout << p1 * 10 << endl;
	cout << 10 * p1 << endl;
	cout << operator*(10,p1) << endl; //запись аналогичная 85 строке
}

/*
в математике определено 
point+point = point
point-point - point
point * point (скалярное произведение = p1.x * p2.x + p1.y*p2.y) = int
деления нет
point * int = point
*/

class A
{
private:
	int x;
	friend void Summ(A a, A b);
public:

};

void Summ(A a, A b)
{
	std::cout << a.x << std::endl;
}









}