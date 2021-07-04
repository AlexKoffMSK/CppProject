#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Engine
{
	int volume;
	char type; //d - diesel, g - gasoline;
	int cylinders;
	int fuel_consumption;//������ �������, ���������� � ������ �� 100 ��
};

struct Body
{
	int type; //1,2,3 - ������������, ������������ � ������������
	string str_color;
};

struct Car
{
	Engine engine;
	Body body;
	string privod;
	int number;
	int curr_fuel_volume;
	int mileage;

	
	//--------------�����������------------
	// �������� ������������ ������� � ������ ��������������
	// good practice - ����� ����� ���������� � ������� �������������

	Car(int number_, int start_fuel_volume_, string color_, int car_fuel_consumption_)
	{
		engine.cylinders = 4;
		engine.type = 'g';
		engine.volume = 10;
		engine.fuel_consumption = car_fuel_consumption_;

		body.type = 2;
		body.str_color = color_;

		number = number_;
		
		curr_fuel_volume = start_fuel_volume_;
		
		mileage = 0;
	}
	
	//Car() = default;
	Car() //������ default
	{
	}
};

struct CarWithPrice
{
	Car car;
	int price;
};

struct CarShop
{
	vector<CarWithPrice> cars_for_sale;
	int total_sold;
	int total_revenue;
};

struct ChainOfCarShops
{
	vector<CarShop> car_shops;
};

void f(ChainOfCarShops chain)
{
	//� 3-�� ��������, � 5� ������ ������� ��� ���������
	cout << chain.car_shops[3].cars_for_sale[5].car.engine.type << endl;
	cout << chain.car_shops[3].cars_for_sale[5].car.body.type << endl;
}

ostream& operator<<(ostream& os, Car c)
{
	os << c.number << ',' << c.body.str_color << ',' << c.curr_fuel_volume << ',' << c.engine.fuel_consumption << ',' << c.mileage;
	return os;
	//����� �������������� �� ������������ ����������� ������ ����� ������/���������
}

ostream& operator<<(ostream& os, CarWithPrice cp)
{
	os << cp.car << ": " << cp.price;
	return os;
	//����� �������������� �� ������������ ����������� ������ ����� ������/���������
}

ostream& operator<<(ostream& os, CarShop cs)
{
	for (CarWithPrice cars_in_shop : cs.cars_for_sale)
	{
		os << cars_in_shop << endl;
	}
	return os;
}