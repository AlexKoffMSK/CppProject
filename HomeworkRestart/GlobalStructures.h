#pragma once
#include <string>
#include "GlobalStructureDate.h"

using namespace std;

struct Student
{
	int age;
	string name;
	int mark;
};

struct Human
{
	string str_name;
	Date date_of_birth;
	char gender;
	string city_of_living;
};

ostream& operator<<(ostream& os, Human h)
{
	os << h.str_name << '.' << h.date_of_birth << '.' << h.gender << '.' << h.city_of_living;
	return os;
}

struct StandNoCircs
{
private:
	bool is_box_1_open = false;
	bool is_box_2_open = false;
	bool is_box_3_open = false;

public:
	//----------конструкторы----------

	//------------методы--------------
	void open_box(int box_num)//безусловно присваивает ящику состояние - открыт
	{
		if (box_num == 1)
		{
			is_box_1_open = true;
		}
		else if (box_num == 2)
		{
			is_box_2_open = true;
		}
		else if (box_num == 3)
		{
			is_box_3_open = true;
		}
	}
	
	void close_box(int box_num)//безусловно присваивает ящику состояние - открыт
	{
		if (box_num == 1)
		{
			is_box_1_open = false;
		}
		else if (box_num == 2)
		{
			is_box_2_open = false;
		}
		else if (box_num == 3)
		{
			is_box_3_open = false;
		}
	}

	friend ostream& operator<<(ostream& os, StandNoCircs s)
	{
		os << s.is_box_1_open << '.' << s.is_box_2_open << '.' << s.is_box_3_open;
		return os;
	}
};

struct StandLocked //не позволяет открыть ящик если открыт один другой
{
private:
	bool is_box_1_open = false;
	bool is_box_2_open = false;
	bool is_box_3_open = false;

public:
	//----------конструкторы----------

	//------------методы--------------
	void open_box(int box_num)
	{
		if (box_num == 1)
		{
			if (is_box_2_open == false && is_box_3_open == false)
			{
				is_box_1_open = true;
			}
		}
		else if (box_num == 2)
		{
			if (is_box_1_open == false && is_box_3_open == false)
			{
				is_box_2_open = true;
			}
		}
		else if (box_num == 3)
		{
			if (is_box_1_open == false && is_box_2_open == false)
			{
				is_box_3_open = true;
			}
		}
	}

	void close_box(int box_num)
	{
		if (box_num == 1)
		{
			is_box_1_open = false;
		}
		else if (box_num == 2)
		{
			is_box_2_open = false;
		}
		else if (box_num == 3)
		{
			is_box_3_open = false;
		}
	}

	friend ostream& operator<<(ostream& os, StandLocked s)
	{
		os << s.is_box_1_open << '.' << s.is_box_2_open << '.' << s.is_box_3_open;
		return os;
	}
};

struct StandAutoClose //
{
private:
	bool is_box_1_open = false;
	bool is_box_2_open = false;
	bool is_box_3_open = false;

public:
	//----------конструкторы----------

	//------------методы--------------
	void open_box(int box_num)
	{
		if (box_num == 1)
		{
			is_box_1_open = true;
			is_box_2_open = false;
			is_box_3_open = false;
		}
		else if (box_num == 2)
		{
			is_box_1_open = false;
			is_box_2_open = true;
			is_box_3_open = false;
		}
		else if (box_num == 3)
		{
			is_box_1_open = false;
			is_box_2_open = false;
			is_box_3_open = true;
		}
	}

	void close_box(int box_num)
	{
		if (box_num == 1)
		{
			is_box_1_open = false;
		}
		else if (box_num == 2)
		{
			is_box_2_open = false;
		}
		else if (box_num == 3)
		{
			is_box_3_open = false;
		}
	}

	friend ostream& operator<<(ostream& os, StandAutoClose s)
	{
		os << s.is_box_1_open << '.' << s.is_box_2_open << '.' << s.is_box_3_open;
		return os;
	}
};


struct StandNoMore2 //
{
private:
	bool is_box_1_open = false;
	bool is_box_2_open = false;
	bool is_box_3_open = false;

public:
	//----------конструкторы----------

	//------------методы--------------
	void open_box(int box_num)
	{
		if (box_num == 1)
		{
			if (is_box_2_open == false || is_box_3_open == false)
			{
				is_box_1_open = true;
			}
		}
		else if (box_num == 2)
		{
			if (is_box_1_open == false || is_box_3_open == false)
			{
				is_box_2_open = true;
			}
		}
		else if (box_num == 3)
		{
			if (is_box_1_open == false || is_box_2_open == false)
			{
				is_box_3_open = true;
			}
		}
	}

	void close_box(int box_num)
	{
		if (box_num == 1)
		{
			is_box_1_open = false;
		}
		else if (box_num == 2)
		{
			is_box_2_open = false;
		}
		else if (box_num == 3)
		{
			is_box_3_open = false;
		}
	}

	friend ostream& operator<<(ostream& os, StandNoMore2 s)
	{
		os << s.is_box_1_open << '.' << s.is_box_2_open << '.' << s.is_box_3_open;
		return os;
	}
};


/*
сосуд
свойства - текущий и максимальный объем жидкости
объем меряется в литрах, есть свойство - скорость выливания - литр в минуту

делать - налить туда указанный объем жидкости, выливать столько-то минут
*/

class Bottle
{
	unsigned int current_volume = 0;
	unsigned int max_volume;
	unsigned int speed_of_extract;

public:

	Bottle(unsigned int max_volume_, unsigned int speed_of_extract_)
	{
		max_volume = max_volume_;
		speed_of_extract = speed_of_extract_;
	}

	void fill(unsigned int volume)
	{
		if (current_volume + volume <= max_volume)
		{
			current_volume += volume;
		}
		else
		{
			cout << "Overflow: " << (current_volume + volume - max_volume) << endl;
			current_volume = max_volume;
		}
	}

	void extract(unsigned int time_in_min)
	{
		int volume_to_extract = time_in_min * speed_of_extract;

		if (volume_to_extract <= current_volume)
		{
			current_volume -= volume_to_extract;
		}
		else
		{
			current_volume = 0;
		}
	}
	
	friend ostream& operator<<(ostream& os, Bottle b)
	{
		os << b.current_volume << '/' << b.max_volume << '(' << b.speed_of_extract << ')';
		return os;
	}

};