#pragma once
#include <vector>
#include <thread>
#include "ConsoleFunctions.h"

using namespace std;

vector<int> bubble_sort_1_iteration(vector<int> arr)
{
	//принимает на вход массив, возвращает. Если левый больше чем правый.
	int max_elem = max_elem_of_vector(arr);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1] > arr[i])
		{
			//ConsoleFunctions::print_arr_histogramm(arr, ' ');
			//ConsoleFunctions::print_bar(i-1 + 10, max_elem, arr[i-1], ' ', Color::Red);
			//ConsoleFunctions::print_bar(i + 10, max_elem, arr[i], ' ', Color::Red);
			swap(arr[i - 1], arr[i]);
			//ConsoleFunctions::print_changed_bar(i + 10, max_elem, arr[i - 1], arr[i], 219, Color::White);
			//ConsoleFunctions::print_changed_bar(i - 1 + 10, max_elem, arr[i], arr[i - 1], 219, Color::White);
			//до - arr[i-1], теперь - arr[i]
			//ConsoleFunctions::print_arr_histogramm(arr, '*');
			//ConsoleFunctions::print_bar(i-1 + 10, max_elem, arr[i-1],219, Color::White);
			//ConsoleFunctions::print_bar(i + 10, max_elem, arr[i], 219, Color::White);

		}
		//this_thread::sleep_for(chrono::microseconds(10)); //эта строчка заставляет спасть 50 микросекунд
	}
	return arr;
}

vector<int> bubble_sort(vector<int> arr)
{
	int max_elem = max_elem_of_vector(arr);
	//ConsoleFunctions::print_arr_histogramm(arr, max_elem, 219);
	//принимает на вход массив, возвращает отсортированный массив
	for (int i = 1; i < arr.size(); i++)
	{
		arr = bubble_sort_1_iteration(arr); //перезаписываем массив полностью на каждой итерации его сортировки
		//print_vector(arr);
	}
	return arr;
}

vector<int> selection_sort(vector<int> arr) //сортировка выбором
{
	int max_elem = max_elem_of_vector(arr);
	//ConsoleFunctions::print_arr_histogramm(arr, max_elem, 219);
	
	for (int i = 0; i < arr.size(); i++)
	{
		int index_of_min_elem = index_of_min_elem_of_tail_of_vector(arr, i);
		
		//ConsoleFunctions::print_bar(i + 10, max_elem, arr[i], ' ', Color::White);
		//ConsoleFunctions::print_bar(index_of_min_elem + 10, max_elem, arr[index_of_min_elem], ' ', Color::White);
		
		swap(arr[index_of_min_elem], arr[i]);
		
		//ConsoleFunctions::print_bar(i + 10, max_elem, arr[i], 219, Color::Green);
		//ConsoleFunctions::print_bar(index_of_min_elem + 10, max_elem, arr[index_of_min_elem], 219, Color::Red);
		
		//this_thread::sleep_for(chrono::microseconds(10)); //эта строчка заставляет спасть 50 микросекунд

		//ConsoleFunctions::print_bar(i + 10, max_elem, arr[i], 219, Color::White);
		//ConsoleFunctions::print_bar(index_of_min_elem + 10, max_elem, arr[index_of_min_elem], 219, Color::White);
	}
	return arr;
} 

vector<int> counting_sort(vector<int> arr) //сортировка подсчётом
{
	print_vector(arr);
	//это работает для массивов, в которых числа не больше 20
	int bucket_count = max_elem_of_vector(arr)+1;
	vector<int> buckets(bucket_count, 0);
	for (int i = 0; i < arr.size(); i++) //перебираем элементы исходного массива
	{
		buckets[arr[i]] += 1; //arr[i] < bucket_count = max_elem_of_vector(arr)+1
	}
	print_vector(buckets);
	vector<int>  sorted_arr;
	for (int i = 0; i < buckets.size(); i++)
	{
		if (buckets[i] > 0)
		{
			for (int j = 0; j < buckets[i]; j++)
			{
				sorted_arr.push_back(i);
			}
		}
	}
	print_vector(sorted_arr);
	return sorted_arr;
}

vector<int> online_sort(vector<int> arr) // сортирует неотсортированный массив налету
{
	////вставка в массив элемента после четвертого элемента массива
	//
	//sorted_arr.insert(sorted_arr.begin() + 4, 7);
	//print_vector(sorted_arr);
	//return sorted_arr;
	//print_vector(arr);

	vector<int> sorted_arr;

	for (int a : arr)
	{
		int pos_to_insert = find_elem_in_sorted_array(sorted_arr, a);

		ConsoleFunctions::print_arr_histogramm(sorted_arr, 51, ' ');

		sorted_arr.insert(sorted_arr.begin() + pos_to_insert, a);

		//cout << "Position to insert elem = " << pos_to_insert << endl;
		//print_vector(sorted_arr);
		ConsoleFunctions::print_arr_histogramm(sorted_arr, 51, 219);

		this_thread::sleep_for(chrono::microseconds(1000000));
	}
	
	return sorted_arr;
}

vector<int> merge_two_sorted_vectors(vector<int> sorted_arr0, vector<int> sorted_arr1)
{
	//1 4 7 9 первый вектор
	//3 5 второй вектор
	//1 3 4 5 7 9 результат - соединенный массив

	//1 2 3 4 5
	//7 8 9

	//1 3 4 5 6
	//3 4 7 8

	vector<int> new_arr;

	int i0 = 0;
	int i1 = 0;

	//for (int i0 = 0, int i1 = 0; i0 < sorted_arr0.size() || i1 < sorted_arr1.size();)
	while (i0 < sorted_arr0.size() || i1 < sorted_arr1.size())
	{
		if (i0 >= sorted_arr0.size())
		{
			new_arr.push_back(sorted_arr1[i1]);
			i1++;
		}
		else
		{
			//i0 < sorted_arr0.size()

			if (i1 >= sorted_arr1.size())
			{
				new_arr.push_back(sorted_arr0[i0]);
				i0++;
			}
			else
			{
				//i0 < sorted_arr0.size() && i1 < sorted_arr1.size()

				if (sorted_arr0[i0] <= sorted_arr1[i1])
				{
					new_arr.push_back(sorted_arr0[i0]);
					i0++;
				}
				else
				{
					//i0 < sorted_arr0.size() && i1 < sorted_arr1.size() && sorted_arr0[i0] < sorted_arr1[i1]

					new_arr.push_back(sorted_arr1[i1]);
					i1++;
				}
			}
		}
	}
	return new_arr;
}

vector<int> merge_sort_unsorted_arr(vector<int> arr)
{
	//сортировка слиянием несортированного массива
	//разделить неотсортированный массив на половинки
	//отсортировать половинки
	//слить половинки
	//(n/2)^2 + (n/2)^2 - количество операций сортировки половинок 
	//vector<int> sorted_left_half = bubble_sort(get_subvector(arr, 0, arr.size() / 2));
	//vector<int> sorted_right_half = bubble_sort(get_subvector(arr, arr.size() / 2+1, arr.size()-1));

	if (arr.size() <= 1)
	{
		return arr;
	}

	vector<int> sorted_left_half = merge_sort_unsorted_arr(get_subvector(arr, 0, arr.size() / 2));
	vector<int> sorted_right_half = merge_sort_unsorted_arr(get_subvector(arr, arr.size() / 2 + 1, arr.size() - 1));


	return merge_two_sorted_vectors(sorted_left_half, sorted_right_half);
	//n/2 + n/2 - количество операций сортировки половинок

	//n*nlog
}

int* partition(int* left_bound, int* right_bound, int pivot) //pivot - в переводе - опорный элемент
{
	int* p_left = left_bound;
	int* p_right = right_bound;

	//while (p_left < p_right)
	//{
	//	while (p_left < p_right && *p_left <= pivot)
	//	{
	//		p_left++; //передвинет указатель к следующему элементу
	//	}
	//	while (p_left < p_right && *p_right > pivot)
	//	{
	//		p_right--; //передвинет указатель к предыдущему элементу
	//	}
	//	swap(*p_left, *p_right);
	//}

	while (p_left < p_right)
	{
		//for (int* p = left_bound; p <= right_bound; p++)
		//{
		//	cout << *p << ' ';
		//}
		//cout << endl;
		//cout << *p_left << "   " << *p_right << "   Pivot: 5 " << endl;
		
		if (*p_left < pivot)
		{
			p_left++;
		}
		else if (*p_right >= pivot) //*p_left > pivot
		{
			p_right--;
		}
		else //*p_right <= pivot, *p_left > pivot
		{
			swap(*p_left, *p_right);
		}
	}
	return p_left;
}

void quick_sort_raw_pointers (int* left_bound, int* right_bound)
{
	cout << "QSort input array: ";
	
	for (int* p = left_bound; p <= right_bound; p++)
	{
		cout << *p << ' ';
	}
	cout << endl;
	
	if (left_bound >= right_bound)
	{
		cout << endl;
		return;
	}
	int pivot = *left_bound;
	
	cout << "Pivot = " << pivot <<endl;

	cout << "Partition... " << endl;

	int* p_middle = partition(left_bound, right_bound, pivot);

	cout << "Partition end. P_middle = "<<*p_middle << endl;
	cout << "Array after partition: ";

	for (int* p = left_bound; p <= right_bound; p++)
	{
		cout << *p << ' ';
	}
	cout << endl;
	cout << endl;

	if (p_middle == left_bound)
	{
		p_middle++;
	}
	quick_sort_raw_pointers(left_bound, p_middle-1);
	quick_sort_raw_pointers(p_middle, right_bound);
}

vector<int> quick_sort(vector<int> arr)
{
	return {};

}

void flip_str(string str)
{
	string fliped_str;
	for (int i=0; i<str.size(); i++)
	{
		fliped_str.push_back(str[str.size()-1-i]);
	}
	cout << fliped_str << endl;
}

void flip_str_sobes_() //переворот строки
{
	string s = "Something";
	string temp_s = s;

	for (int i = 0; i < s.size(); i++)
	{
		s[i] = temp_s[temp_s.size() - 1 - i];
	}
		cout << s;
}

void flip_str_sobes() //переворот строки
{
	string s = "Something";
	for (int i = 0; i < (s.size() / 2); i++)
	{
		swap(s[i], s[s.size() - 1 - i]);
	}
	cout << s;
}

void compare_two_equal_lenght_strings()
{
	string str0 = "Radden";
	string str1 = "dendaR";

	int arr[256] = {0};
	for (char a : str0)
	{
		arr[a] += 1;
	}
	
	int arr1[256] = { 0 };
	for (char a : str1)
	{
		arr1[a] += 1;
	}

	bool is_eq=true;

	for (int i=0; i<256; i++)
	{
		if (arr[i] != arr1[i])
		{
			is_eq = false;
			break;
		}
	}
	cout << is_eq << endl;
}

void compare_two_equal_lenght_strings_1()
{
	string str0 = "Radwden";
	string str1 = "dedndaR";

	int arr[256] = { 0 };
	
	int uniq_chars_count = 0;

	for (char a : str0)
	{
		arr[a] += 1;
		if (arr[a] == 1)
		{
			uniq_chars_count++;
		}
	}

	for (char a : str1)
	{
		arr[a] -= 1;
		if (arr[a] == 0)
		{
			uniq_chars_count--;
		}
	}

	cout << (uniq_chars_count == 0) << endl;
}