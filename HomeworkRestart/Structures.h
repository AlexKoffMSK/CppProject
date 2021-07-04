#pragma once
#include <iostream>
#include <iomanip>
#include "Functions.h"
#include "GlobalStructures.h"
#include "GlobalStructureDate.h"

using namespace std;

namespace Structures
{
	//���������� ���������� ���. � ������ ���� - �, B. ������ ��������� �������� ���� - ��� � ����������. � ������ ���� - c,d.
	//������ - ��� ��

	struct A
	{
		int c;
		int d;
	};

	struct B
	{
		int c;
		int d;
	};

	void f0()
	{
		int b;
		b = 3;
		cout << b << endl;

		A a;
		a.c = 5;
		a.d = 6;

		B y;
		y.c = 7;
		y.d = 8;

		cout << a.c << ' ' << a.d << endl;
		cout << y.c << ' ' << y.d << endl;

	}

	void f1()
	{
		struct IntAndTwoChars //IntAndTwoChars ���������
		{
			int a;  // a - ��� ���� (������� ����������, ������� �������� ������ ���������)
			char b; // b - ��� ���� (��������� ����������, ������� �������� ������ ���������)
			char c; // c - ��� ���� (��������� ����������, ������� �������� ������ ���������)
		};

		IntAndTwoChars a; //a - ��� ������, ��������� �� ��� (� ������ �������) �����
		a.a = 5; //������� � � ���� a ����������/����������� �������� 5
		a.b = 'b'; //������� � � ���� b ����������/����������� ������ 'b'
		a.c = rand() % 255 + 1;

		IntAndTwoChars b;
		b.a = rand() % 10;
		b.b = 'y';
		b.c = 'z';

		//���� ���� � ������� � ����� ���� b ������� b, �� ������� 3, ����� - 5

		if (a.c == b.b)
		{
			cout << 3 << endl;
		}
		else
		{
			cout << 5 << endl;
		}

		//���� ���� a ������� b ������ ���� a ������� a, ������� ���� b ������� a, ����� - ������� ���� � ������� b
		if (b.a > a.a)
		{
			cout << a.b << endl;
		}
		else
		{
			cout << b.a << endl;
		}
	}

	void f2()
	{
		struct IntAndChar
		{
			int a;
			char b;
		};

		struct IntAndCharAndInt
		{
			IntAndChar c;
			int d;
		};

		IntAndCharAndInt e;
		e.d = 5;
		e.c.a = 1;
		e.c.b = 'z';

		IntAndChar f;
		f.a = 9;
		f.b = 'x';
	}

	void f3()
	{

		Student petrov;
		Student sidorov;

		petrov.age = get_random_number_from_range(17, 23);
		petrov.name = "Petr";
		petrov.mark = get_random_number_from_range(0, 5);

		sidorov.age = get_random_number_from_range(17, 23);
		sidorov.name = "Sidor";
		sidorov.mark = get_random_number_from_range(0, 5);

		cout << petrov.name << ' ' << petrov.age << ' ' << petrov.mark << endl;
		cout << sidorov.name << ' ' << sidorov.age << ' ' << sidorov.mark << endl;


		if (petrov.mark > sidorov.mark)
		{
			cout << petrov.name << ' ' << petrov.age << endl;
		}
		else
		{
			cout << sidorov.name << ' ' << sidorov.age << endl;
		}

	}

	void f4()
	{
		//����������� ������ ��������� ������� 10, �������� �������� ���� ������ �������� � ���������. � ���� ��� - Petr
		int arr[10]; //��� ������ �������� �����
		Student students[10]; //��� ������ �������� ��������� Student
		for (int i = 0; i < size(students); i++)
		{
			students[i].age = get_random_number_from_range(17, 23);
			students[i].mark = get_random_number_from_range(0, 5);
			students[i].name = get_random_english_string(5);
		}

		int summ_mark = 0;

		for (Student curr_student_from_array : students)
		{
			cout << curr_student_from_array.age << '-' << curr_student_from_array.mark << '-' << curr_student_from_array.name << endl;
			summ_mark += curr_student_from_array.mark;
		}
		cout << summ_mark << endl;

		//���� ������������ �������� ����� ���������
		int max_age = students[0].age;
		for (Student curr_student_from_array : students)
		{
			if (curr_student_from_array.age > max_age)
			{
				max_age = curr_student_from_array.age;
			}
		}
		cout << max_age << endl;

		//������� ����� ���� ���������, ��������������� ������������� ��������
		for (Student curr_student_from_array : students)
		{
			if (curr_student_from_array.age == max_age)
			{
				cout << curr_student_from_array.name << endl;
			}
		}
	}

	void f5()
	{
		int a = 3;
		Student s{ 20,"Petr",5 };
	}

	void f6()
	{
		//������� ������ ���������

		vector<Student> students_in_vector;
		Student s{ 20, "Petr", 5 };
		//students_in_vector.push_back(s);

		//students_in_vector.push_back(Student{ 25,"Sidor",3 });

		//������� ��������� ���������� ��������� ���������
		students_in_vector.push_back(Student{ get_random_number_from_range(17, 23), get_random_english_string(5), get_random_number_from_range(0, 5) });
		//age mane mark

		for (int i = 0, rand_number = rand() % 30 + 1; i < rand_number; i++)
		{
			students_in_vector.push_back(Student{ get_random_number_from_range(17, 23), get_random_english_string(5), get_random_number_from_range(0, 5) });
		}
		for (Student curr_student_from_array : students_in_vector)
		{
			cout << curr_student_from_array.age << ' ' << curr_student_from_array.mark << ' ' << curr_student_from_array.name << endl;
		}
	}

	void f7()
	{
		//������� ������ ����
		//Date d{ 2021, 1, 10 }; ����� �������� ���������� ������������ - ����������� �� ������� (�� ���������, ��� ������������� ��� ����) ��������� ��������
		Date d1(6, 15);
		cout << d1 << endl;

		cout << Date() << endl;
		cout << Date(2017, 4, 2) << endl;
	}

	/*
	1. ������� ��������� Date. ��� ������ 3 ������� �����. ���, �����, ����.
	2. �������� �������, ������� ��������� 2 ���� � ���������� true, ���� ������ ���� ������ ������, ����� false;
	3. �������� �������, ������� ��������� ���� � �������� �� ����� ����� ���� ���� ����.
	4. �������� �������, ������� ��������� ���� � ���������� ����, ������������ ��������� ���� (������ ���������, ��� �� ���� ������� 31 ����).

	5. ������� ��������� Human, ������� �������� � ���� - ��� ��������, ���� ��� ��������, ���, � ����� ����������.
	6. �������� �������, ������� ��������� �� ���� ����� n � ���������� ������� ��������� ����� ������� n.
	7. �������� �������, ������� ��������� ������ ����� � �����. �������� �� ����� ���� ����� � ����� ������.
	8. �������� ������, ������� ��������� ������ ����� � �������� �� ����� ����� ������� �����.
	*/

	void print_season_of_date(Date x)
	{
		if (x.month == 12 || x.month >= 1 && x.month <= 2)
		{
			cout << "It's winter!" << endl;
		}
		else if (x.month >= 3 && x.month <= 5)
		{
			cout << "It's spring!" << endl;
		}
		else if (x.month >= 6 && x.month <= 8)
		{
			cout << "It's summer!" << endl;
		}
		else if (x.month >= 9 && x.month <= 11)
		{
			cout << "It's autumn!" << endl;
		}
	}

	Date temp_yesterday(Date x)
	{
		Date new_date;
		
		if (x.day != 1)
		{
			new_date = Date{ x.year, x.month, x.day - 1 };
		}
		else
		{
			if (x.month != 1)
			{
				new_date = Date{ x.year, x.month - 1, 31 };
			}
			else
			{
				new_date = Date{ x.year - 1, 12, 31 };
			}
		}
		return new_date;
	}

	Date temp_yesterday_2(Date x)
	{
		if (x.day != 1)
		{
			return Date{ x.year, x.month, x.day - 1 };
		}
		if (x.month != 1)
		{
			return Date{ x.year, x.month - 1, 31 };
		}
		return Date{ x.year - 1, 12, 31 };
	}

	vector<Human> arr_of_random_people(int n)
	{
		vector<Human> people_in_vector;

		for (int i = 0; i<n; i++)
		{
			people_in_vector.push_back(Human{ get_random_english_string(4), get_random_date_of_birth(), random_gender(), get_random_english_string(2) });
		}
		for (Human curr_human_in_arr : people_in_vector)
		{
			//cout << "Name: " << curr_human_in_arr.str_name << " Gender: " <<curr_human_in_arr.gender << " City: " << curr_human_in_arr.city_of_living << ' ';
			//print_date(curr_human_in_arr.date_of_birth);
		
			cout << curr_human_in_arr << endl;
		}
		
		return people_in_vector;
	}

	void print_human_and_city(vector<Human> arr_of_people, string city)
	{
		for (Human curr_human_in_arr : arr_of_people)
		{
			cout << curr_human_in_arr << endl;
		}
		
		cout << "-----" << endl;
		
		for (Human curr_human_in_arr : arr_of_people)
		{
			if (curr_human_in_arr.city_of_living == city)
			{
				cout << curr_human_in_arr << endl;
			}
		}
	}

	void print_oldest_human(vector<Human> arr_of_people)
	{
		cout << "-------" << endl;

		Date oldest_birthday;

		oldest_birthday = arr_of_people[0].date_of_birth; // 0 0 0 ��� ��������� ���� - ����� ������������ ��������! ��������� - ������ ������������� � [0]

		for (Human cur_human_in_array : arr_of_people)
		{
			if (is_date_x_is_later_date_y(Date (oldest_birthday), Date(cur_human_in_array.date_of_birth)) == true)
			{
				oldest_birthday = cur_human_in_array.date_of_birth;
			}
		}

		for (Human cur_human_in_array : arr_of_people)
		{
			if (cur_human_in_array.date_of_birth.year == oldest_birthday.year && cur_human_in_array.date_of_birth.month == oldest_birthday.month && cur_human_in_array.date_of_birth.day == oldest_birthday.day)
			{
				cout << cur_human_in_array << endl;
			}
		}
	}

	struct Human1
	{
		std::string _name;
		int _age;

		~Human1()
		{
			std::cout << "Destructor: " << _name << ' ' << _age << std::endl;
		}
	};

	void Test678()
	{
		Human1 h1{ "Vasya",35 };
		std::cout << "H1: " << h1._name << " H1.AGE: " << h1._age << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			Human1 h2{ "Petya", i };
			std::cout << "H2: " << h2._name << " H2.AGE: " << h2._age << std::endl;
		}
		std::cout << "H1: " << h1._name << " H1.AGE: " << h1._age << std::endl;

		// int a = 4;
		// int b = 4;
		// int c = a++;
		// // c = a;
		// // a += 1;
		// int d = ++b;
		// a++; //a+=1 ����� ����������� ������������� 
		// ++b; //b+=1 ����� ����������� �������������
		// //a = 5  a+=1 a=a+1
		// //b = 5  _+=1 _=b+1
		// //c = 4
		// //d = 5
		// 
		// std::vector<int> vec{ 1,2,3 };
		// for (auto iter = vec.begin(); iter != vec.end(); iter++)
		// {
		// 
		// }
	
	}





}