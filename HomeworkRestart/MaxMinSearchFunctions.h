#pragma once
#include <vector>

using namespace std;

//---------------------------------------------------max----------------------------------------------------------------

int index_of_max_elem_of_tail_of_vector(vector<int> arr, int start_pos)
{
	int index_of_max_elem = 0;
	for (unsigned int i = start_pos; i < arr.size(); i++)
	{
		if (arr[i] > arr[index_of_max_elem])
		{
			index_of_max_elem = i;
		}
	}
	return index_of_max_elem;
}

int index_of_max_elem_of_vector(vector<int> arr)
{
	return index_of_max_elem_of_tail_of_vector(arr, 0);
}

int max_elem_of_vector(vector<int> arr) //называется адаптер,она ничего не делает, но с по-другому вызывает другую функцию.
{
	return arr[index_of_max_elem_of_vector(arr)];

	//int max_elem = 0;
	//for (int elem : arr)
	//{
	//	if (elem > max_elem)
	//	{
	//		max_elem = elem;
	//	}
	//}
	//return max_elem;
}

//---------------------------------------------------min----------------------------------------------------------------

int index_of_min_elem_of_tail_of_vector(vector<int> arr, int start_pos)
{
	int index_of_min_elem = start_pos;
	for (int i = start_pos; i < arr.size(); i++)
	{
		if (arr[i] < arr[index_of_min_elem])
		{
			index_of_min_elem = i;
		}
	}
	return index_of_min_elem;
}

int index_of_min_elem_of_vector(vector<int> arr)
{
	return index_of_min_elem_of_tail_of_vector(arr, 0);
}

int min_elem_of_vector(vector<int> arr) //называется адаптер,она ничего не делает, но с по-другому вызывает другую функцию.
{
	return arr[index_of_min_elem_of_vector(arr)];
}