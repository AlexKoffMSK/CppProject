#pragma once
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class VectorWithinEvens
{
	vector<int> std_vector;


public:

	friend ostream& operator<<(ostream& os, VectorWithinEvens vector_within_evens)
	{
		for (int a : vector_within_evens.std_vector)
		{
			os << a << ' ';
		}
		return os;
	}

	void PushBack(int a)
	{
		if (a % 2 == 0)
		{
			std_vector.push_back(a);
		}
	}

	int size_of_cust_vec()
	{
		return std_vector.size();
	}

	int get_count_of_num(int num)
	{
		int count = 0;
		for (int a : std_vector)
		{
			if (a == num)
			{
				count++;
			}
		}
		return count;
	}
};

void cust_vec_f1()
{
	VectorWithinEvens vec;
	cout << vec << endl;
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(6);
	vec.PushBack(4);
	cout << vec << endl;
	cout << vec.size_of_cust_vec() << endl;
	cout << vec.get_count_of_num(4) << endl;

}