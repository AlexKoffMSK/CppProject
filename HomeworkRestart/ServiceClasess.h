#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace ServiceClasess
{
	class EvenOddZeroCounter
	{
		int counter_of_evens = 0;
		int counter_of_odds = 0;
		int counter_of_zeros = 0;
	
	public:

		void add_num(int num)
		{
			if (num % 2 == 0 && num != 0)
			{
				counter_of_evens++;
			}
			else if (num % 2 != 0 && num != 0)
			{
				counter_of_odds++;
			}
			else
			{
				counter_of_zeros++;
			}
		}

		void add_arr(vector<int> arr)
		{
			for (int curr : arr)
			{
				add_num(curr);
			}
		}

		int get_even_counter()
		{
			return counter_of_evens;
		}

		int get_odd_counter()
		{
			return counter_of_odds;
		}

		int get_zero_counter()
		{
			return counter_of_zeros;
		}

	};

	void servf1(vector<int> a, vector<int> b)
	{
		print_vector(a);
		print_vector(b);
		
		EvenOddZeroCounter counter_for_a;
		EvenOddZeroCounter counter_for_b;
		counter_for_a.add_arr(a);
		counter_for_b.add_arr(b);
		
		//(условие) ? (если да) : (если нет)
		//(counter_for_a.get_even_counter() > counter_for_b.get_even_counter()) ? (cout << "a" << endl) : (cout << "b" << endl);

		cout << ((counter_for_a.get_even_counter() > counter_for_b.get_even_counter()) ? "a" : "b") << endl;
		cout << ((counter_for_a.get_odd_counter() > counter_for_b.get_odd_counter()) ? "a" : "b") << endl;
		cout << ((counter_for_a.get_zero_counter() > counter_for_b.get_zero_counter()) ? "a" : "b") << endl;
		
	}

	class SortedArray
	{
		vector<int> arr;

		int find_pos_to_insert_elem_in_sorted_array(int elem)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i] >= elem)
				{
					return i;
					break; //после первого совпадения выходим из условия
				}
			}
			return arr.size();
		}

	public:
		
		int get_size_arr()
		{
			return arr.size();
		}
		
		bool binary_search_elem_in_sorted_array(int elem)
		{
			int ind_of_left_bound = 0;
			int ind_of_right_bound = arr.size() - 1;

			while (ind_of_left_bound < ind_of_right_bound)
			{
				int ind_mid = (ind_of_left_bound + ind_of_right_bound) / 2;
				if (elem == arr[ind_mid])
				{
					return true;
				}
				else if (elem > arr[ind_mid])
				{
					ind_of_left_bound = ind_mid+1;
				}
				else
				{
					ind_of_right_bound = ind_mid-1;
				}
			}
			return false;
		}
		
		void add_num(int num)
		{
			int pos_to_insert = find_pos_to_insert_elem_in_sorted_array(num);
			arr.insert(arr.begin() + pos_to_insert, num);
		}

		vector<int> get_sorted_arr()
		{
			return arr;
		}

	};
	
	void servf2()
	{
		//10 раз генерит рандомное число и записывает в отсортированный массив и принтует каждый раз
		
		SortedArray arr;
		
		for (int i = 0; i < 10;i++)
		{
			int rnd_x = rand() % 100;
			arr.add_num(rnd_x);
			print_vector(arr.get_sorted_arr());

		}
	}

	class Set
	{
		vector<int> arr;

	public:
		
		void add_num(int num)
		{
			arr.push_back(num);
		}

		bool is_num_in_set(int num)
		{
			for (int b : arr)
			{
				if (num == b)
				{
					return true;
				}
			}
			return false;
		}
	};

	void servf3()
	{
	// генерируем 10 числе, дальше вводим число с клавиатуры и выводим это число если оно генерировалось до этого
		Set set_x;

		for (int i = 0; i < 10; i++)
		{
			int rnd_x = rand() % 100;
			set_x.add_num(rnd_x);
			cout << rnd_x << ' ';
		}
		cout << endl;

		int a;
		cin >> a;
		cout << boolalpha << set_x.is_num_in_set(a) << endl;
	}

	void test_set_performance(int count_of_elements_in_set, int count_of_elements_for_test, int max_elem)
	{
		cout << "Start fill Set for test" << endl;
		Set set_x;

		auto start = std::chrono::system_clock::now(); // This and "end"'s type is std::chrono::time_point
		
		for (int i = 0; i < count_of_elements_in_set; i++)
		{
			//set_x.add_num(rand()% max_elem);
			set_x.add_num(3);
		}

		auto end_fill = std::chrono::system_clock::now(); // This and "end"'s type is std::chrono::time_point


		for (int i = 0; i < count_of_elements_for_test; i++)
		{
			int rnd_x = rand() % max_elem;
			set_x.is_num_in_set(rnd_x);
		}

		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_fill = end_fill - start;
		std::chrono::duration<double> elapsed_search = end - end_fill;
		std::cout << "Elapsed time (Set): " << elapsed_fill.count() << "s " << elapsed_search.count() << "s" << endl;
	}

	class SmartSet
	{
		SortedArray arr;

	public:

		void add_num(int num)
		{
			arr.add_num(num);
		}

		bool is_num_in_set(int num)
		{
			return arr.binary_search_elem_in_sorted_array(num);
		}
	};

	void test_smart_set_performance(int count_of_elements_in_set, int count_of_elements_for_test, int max_elem)
	{
		cout << "Start fill SmartSet for test" << endl;
		SmartSet set_x;
		
		auto start = std::chrono::system_clock::now(); // This and "end"'s type is std::chrono::time_point

		for (int i = 0; i < count_of_elements_in_set; i++)
		{
			//set_x.add_num(rand() % max_elem);
			set_x.add_num(3);
		}

		auto end_fill = std::chrono::system_clock::now(); // This and "end"'s type is std::chrono::time_point

		for (int i = 0; i < count_of_elements_for_test; i++)
		{
			int rnd_x = rand() % max_elem;
			set_x.is_num_in_set(rnd_x);
		}

		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_fill = end_fill - start;
		std::chrono::duration<double> elapsed_search = end - end_fill;
		std::cout << "Elapsed time (Set): " << elapsed_fill.count() << "s " << elapsed_search.count() << "s" << endl;
	}







































}