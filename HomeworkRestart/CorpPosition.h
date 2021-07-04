#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "GlobalStructureDate.h"

using namespace std;

class Position
{
	string position="";
	int rank=0;

public:
	Position(string position_, int rank_)
	{
		position = position_;
		rank = rank_;
	}
	Position()
	{
	}
	string get_position()
	{
		return position;
	}
	int get_rank()
	{
		return rank;
	}
	int get_highest_of_2_ranks(int rank1, int rank2)
	{
		if (rank1 > rank2)
		{
			return rank1;
		}
		else
		{
			return rank2;
		}
	}
	friend ostream& operator<<(ostream& os, Position p)
	{
		os << "Position: " <<p.position << " | " << "Rank: " << p.rank;
		return os;
	}
};

class Employee
{
	string name = "";
	Date date_of_birth;
	Position position;
	int wage;
	int hours_worked=0;
	int hours_worked_after_wage_increase = 0;

public:
	Employee(string name_, Date date_of_birth_, Position position_, int wage_)
	{
		assert(wage_ > 0);
		name = name_;
		date_of_birth = date_of_birth_;
		position = position_;
		wage = wage_;
		//hours_worked �� ��������� � �� ����������������, �.�. ��� ����� ���������� �������� � 0 ����� �������������� �������
	}

	void add_work_hours(int add_hours_worked)
	{
		hours_worked += add_hours_worked;
		hours_worked_after_wage_increase += add_hours_worked;

		if (hours_worked_after_wage_increase > 1000)
		{
			wage *= 1.3;
			hours_worked_after_wage_increase -= 1000;
		}
		
		//todo - ������� ���� ���������� ��������
		/*
		1. �������� ��������� ���-�� �����, �.�. �����, ������� ��������� ���-�� �����, � ����������� �� ��� �������� ���-�� ������������� ����� ����������.
		������ 1000 �������������� �����  ����������, ��� �� ������ �� 30%.
		*/
	}
	
	void set_new_position(Position new_position)
	{
		position = new_position;
	}

	int get_hours_worked_of_emp()
	{
		return hours_worked;
	}

	string get_name_of_emp()
	{
		return name;
	}

	int get_wage_of_emp()
	{
		return wage;
	}

	bool is_emp2_greater_cur_emp(Employee emp2)
	{
		return hours_worked < emp2.hours_worked;
	}

	friend ostream& operator<<(ostream& os, Employee e)
	{
		os << "Employee's name: " <<e.name << " | " << "Date of birth: " <<e.date_of_birth << " | "  <<e.position << " | " << "Wage: " << e.wage << " | " << "Hours worked: " <<e.hours_worked;
		return os;
	}
};

class Department
{
	string dep_name;
	vector<Employee> employees;
	
public:
	
	Department(string dep_name_)
	{
		dep_name = dep_name_;
	}

	int get_amount_of_emps()
	{
		return employees.size();
	}

	string get_dep_name()
	{
		return dep_name;
	}

	int hours_worked_of_dep()
	{
		int summ_of_hours_worked = 0;
		for (Employee curr_emp : employees)
		{
			summ_of_hours_worked += curr_emp.get_hours_worked_of_emp();
		}
		return summ_of_hours_worked;
	}
	
	void hire_one_employee(Employee emp)
	{
		employees.push_back(emp);
	}

	void fire_employee_with_index_num(int num)
	{
		employees.erase(employees.begin() + num);
	}

	bool is_dep2_hours_greater_cur_dep(Department dep2)
	{
		return dep2.hours_worked_of_dep() > hours_worked_of_dep();
	}
	
	friend ostream& operator<<(ostream& os, Department dep)
	{
		os << "Department name: " <<dep.dep_name << endl;
		for (Employee curr_emp : dep.employees)
		{
			os << curr_emp << endl;
		}
		return os;
	}

	string most_experienced_emp()
	{
		int maximum_hours_worked = 0;
		string name_of_emp_with_max_h;

		for (Employee curr_emp : employees)
		{
			if (curr_emp.get_hours_worked_of_emp() >= maximum_hours_worked)
			{
				maximum_hours_worked = curr_emp.get_hours_worked_of_emp();
				name_of_emp_with_max_h = curr_emp.get_name_of_emp();
			}
		}
		return name_of_emp_with_max_h;
	}

	int greatest_wage()
	{
		int cur_max_wage = 0;
		for (Employee curr_emp : employees)
		{
			if (curr_emp.get_wage_of_emp() >= cur_max_wage)
			{
				cur_max_wage = curr_emp.get_wage_of_emp();
			}
		}
		return cur_max_wage;
	}

	int index_of_emp_with_lowest_wage()
	{
		//int cur_min_wage = employees[0].get_wage_of_emp();
		int index_of_emp_with_min_wage = 0;
		for (int i=1; i< employees.size(); i++)
		{
			if (employees[i].get_wage_of_emp() < employees[index_of_emp_with_min_wage].get_wage_of_emp())
			{
				//cur_min_wage = employees[i].get_wage_of_emp();
				index_of_emp_with_min_wage = i;
			}
		}
		return index_of_emp_with_min_wage;
	}

	void fire_emp_with_lowest_wage()
	{
		fire_employee_with_index_num(index_of_emp_with_lowest_wage());
	}

	void work_random_hours_from_t1_t2(int t1, int t2)
	{
		for (Employee& curr_emp : employees) //���������� ���������� ������� � ���, ��� �� �������� �� � ������ �������, � � ����� �������� � �������
		{
			curr_emp.add_work_hours(get_random_number_from_range(t1, t2));
		}
		
		//for (Employee curr_emp : employees)
		//{
		//	curr_emp.add_work_hours(get_random_number_from_range(t1, t2));
		//}
		//
		//for (int i = 0; i < employees.size(); i++)
		//{
		//	Employee curr_emp = employees[i];
		//	curr_emp.add_work_hours(get_random_number_from_range(t1, t2));
		//}
		//
		//
		//for (int i = 0; i < employees.size(); i++)
		//{
		//	employees[i].add_work_hours(get_random_number_from_range(t1, t2));
		//}
	}
};

Department make_rand_dep(string dep_name_, int start_emp_count_)
{
	Department dep(dep_name_);

	for (int i = 0; i < start_emp_count_; i++)
	{
		//Position rand_pos(get_random_english_string(3), get_random_number_from_range(0,10)); - �� �����, �.�. �� ���� ������� � ������ � ����������� ����������
		//Employee emp(get_random_english_string(4), get_random_date_of_birth(), Position (get_random_english_string(3), get_random_number_from_range(0, 10)), get_random_number_from_range(10, 100)); - ����������
		dep.hire_one_employee(Employee(get_random_english_string(4), get_random_date_of_birth(), Position(get_random_english_string(3), get_random_number_from_range(0, 10)), get_random_number_from_range(10, 100)));
	}
	return dep;
}

void corpf1()
{
	/*
	1. ������� 1 �����. �������� ���� 5 ����������� �� ���������� �������, ������ ��������, �� � �����������.
	������� ��� �� �����. ����� � ����� 10 ��� �������� ������ �� 100 ����� �� 300. ����� ������ ������ ���������� ����� �� �����.
	*/
	
	Department dep=make_rand_dep("Dudes", 5);
	cout << dep << endl;

	for (int i = 0; i < 10; i++)
	{
		dep.work_random_hours_from_t1_t2(100, 300);
		cout << dep;
		cout << dep.most_experienced_emp() << endl;
		cout << endl;
	}
}

void corpf2()
{
	/*
	2. ������� 1 �����. �������� ���� 5 ����������� �� ���������� �������, ������ ��������, �� � �����������.
	� ����� 30 ���:
	� 20% ������������: �������� ������ ���������� - 0-20
	� 10% ������������: ������� ���������� ���������� - 20-30
	� 10% ������������: ������� ���������� � ����� ��������� ��. 30-40
	� 60% ������������: �������� �� 100 ����� �� 300. 40-100
	����� ������� ������, �������� ����� �� �����.
	*/

	Department dep = make_rand_dep("Dudes", 5);
	cout << dep << endl;

	for (int i = 0; i < 30; i++)
	{
		int rand_decision = rand() % 100;
		if (rand_decision >= 0 && rand_decision < 20)
		{
			cout << rand_decision << endl;
			dep.hire_one_employee(Employee(get_random_english_string(4), get_random_date_of_birth(), Position(get_random_english_string(3), get_random_number_from_range(0, 10)), get_random_number_from_range(10, 100)));
			cout << dep << endl;
		
		}
		else if (rand_decision >= 20 && rand_decision < 30)
		{
			cout << rand_decision << endl;
			dep.fire_employee_with_index_num(rand() % dep.get_amount_of_emps());
			cout << dep << endl;
		}
		else if (rand_decision >= 30 && rand_decision < 40)
		{
			cout << rand_decision << endl;
			dep.fire_emp_with_lowest_wage();
			cout << dep << endl;
		}
		else if (rand_decision >= 40 && rand_decision < 100)
		{
			cout << rand_decision << endl;
			dep.work_random_hours_from_t1_t2(100, 300);
			cout << dep << endl;
		}
	}

}

void corpf3()
{
	Department dep = make_rand_dep("Dudes", 5);
	cout << dep << endl;

	for (int i = 0; i < 10; i++)
	{
		dep.hire_one_employee(Employee(get_random_english_string(4), get_random_date_of_birth(), Position(get_random_english_string(3), get_random_number_from_range(0, 10)), get_random_number_from_range(10, 100)));
		cout << dep;
		cout << dep.greatest_wage() << endl;

	}
}

void corpf4()
{
	Department dep0 = make_rand_dep("Folks", 10);
	Department dep1 = make_rand_dep("Comrades", 10);

	for (int i = 0; i < 20; i++)
	{
		dep0.work_random_hours_from_t1_t2(100, 300);
		cout << dep0 << endl;
		dep1.work_random_hours_from_t1_t2(100, 300);
		cout << dep1 << endl;

		if (dep0.hours_worked_of_dep() > dep1.hours_worked_of_dep())
		{
			cout << dep0.get_dep_name();
		}
		else
		{
			cout << dep1.get_dep_name();
		}
	}
}

void corpf5()
{
	Department dep0 = make_rand_dep("Folks", 10);
	Department dep1 = make_rand_dep("Comrades", 10);

	for (int i = 0; i < 20; i++)
	{
		dep0.work_random_hours_from_t1_t2(100, 300);
		cout << dep0 << endl;
		dep1.work_random_hours_from_t1_t2(100, 300);
		cout << dep1 << endl;

		if (dep0.greatest_wage() > dep1.greatest_wage())
		{
			cout << dep0.get_dep_name();
		}
		else
		{
			cout << dep1.get_dep_name();
		}
	}
}

void corpf6()
{
	Employee emp1(get_random_english_string(4), get_random_date_of_birth(), Position("A", 0), 100);
	emp1.add_work_hours(300);// �������� ���������� 300 �����
	cout << emp1.get_wage_of_emp() << endl;
	emp1.add_work_hours(200); // �������� ���������� 500 �����
	cout << emp1.get_wage_of_emp() << endl;
	emp1.add_work_hours(700); // // �������� ���������� 1200 �����. �� �����������
	cout << emp1.get_wage_of_emp() << endl;
	emp1.add_work_hours(600); // �������� ���������� 1800 �����
	cout << emp1.get_wage_of_emp() << endl;
	emp1.add_work_hours(1200); // �������� ���������� 3000 �����. �� ����������� 2 ����
	cout << emp1.get_wage_of_emp() << endl;
}

/*
1. ������� ����� "���������" (� ������ ����������������).
��������:
���������� ��������.
������� ��������. (�.�. ��������� � ������� 5 ��������� ����� ����������, ��� ��������� � ������� 3).

��� �� ����� ������ �����:
��� ������������ ��������� ������ �� �������� � �������� (�.�. �������� ����).

��� ����� ������ �����:
1.1. �������� �������� � �������� (2 �������).
1.2. ���������� ���������, ��������� ��������� ���� ������, ���� ���� �� ��������.
1.3. ���������� � cout.

2. ������� ����� "���������" (Employee). ��� ��������:
���, ���� ��������, ���������, �������� (�� ��������� �� �������), ���-�� ������������� �����.

��� �� ����� ������ �����:
������ ��� ����������, ������ ���� ��������, ������ �������� (�� ����� �������� ������ �� ���-�� ������������� �����).

��� ����� ������ �����:
1. �������� ��������� ���-�� �����, �.�. �����, ������� ��������� ���-�� �����, � ����������� �� ��� �������� ���-�� ������������� ����� ����������.
������ 1000 �������������� �����  ����������, ��� �� ������ �� 30%.

2. �������� ���������.

3. ���������� �� �����.

4. ���������� �����������. ��������� ��������� ������, ���� � ���� ������ ���-�� ������������� ����� ������� ����������.

3. ������� ����� "�����". �� ���� �������:
3.1. �� ����������� (������ (������)).
3.2. �� ������ ���������� (����������), ��� ��������� ����������� ������ ���� {"Manager", 10}.
3.3. �� ����������� ��������.

��� ����� ������ �����:
3.1. �������� ������ ����������.
3.2. ������� i-��� � ������� ����������� ����������. ��� ��������� ����� �������� ������ ����� {"Fired",0}.
3.3. ���������� ������. ����� ��������� ������, ���� ��� ��������� ���-�� ������������� ����� ���� ����������� � ���������� > ������������ ���������� � ������� ������.
3.4. ���������� ����� (�.�. ��������, ���������� � �����������).
3.5. ������� ��� ����������, ������� ���������� ������ ���� (���� ����� ���������, ������� �����).
3.6. ������� ����� ������� �� �� ���� �����������.
3.7. ������� ���������� � ����� ��������� ��.
3.8. ��������. ��� �����, ������� ��������� �� ���� 2 ����� t1,t2 (��� t1,t2) � ��� ���������� �������� �������� ����� �� ��������� [t1,t2], � ���������.
*/

