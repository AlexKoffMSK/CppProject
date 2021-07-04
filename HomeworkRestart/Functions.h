#pragma once
#include <string>
#include <thread>
#include <iomanip>
#include <map>
#include "MaxMinSearchFunctions.h"
#include "GlobalStructures.h"


using namespace std;

int sqr(int a)
{
	return a * a;
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int max_of_3(int a, int b, int c)
{
	return max(max(a, b), c); //сравниваем 'c' с наибольшим из a,b
}

//int count_char_in_string(string str, char ch)
//{
//	int count = 0;
//	for (int i=0; i < str.size(); i++)
//	{
//		if (str[i] == ch)
//		{
//			count++;
//		}
//	 }
//	return count;
//}

int count_char_in_string(string str, char ch)
{
	int count = 0;
	for (char a:str)
	{
		if (a == ch)
		{
			count++;
		}
	}
	return count;
}

/*for (char a : str)
{
	if (a == ch)
	{
		count++;
	}
}

for (int i=0; i < str.size(); i++)
{
	char a = str[i];
}
*/

bool is_second_string_in_first(string first_str, string second_str, int start_pos)
{
	//человек вводит две строки и число. вывести тру если в старт.поз первой строки начинается символ второй строки
	// abcde cd 2 - true
	// abcde cd 3 - false
	// abcde de 3 - true
	// abcde de 2 - false
	// abcde cdo 2 - false

	//if (a[start_pos] == b[0] && a[start_pos+1] == b[1])
	//{
	//	cout << "True";
	//}

	for (int i = 0; i < second_str.size(); i++)
	{
		if ((start_pos + i) >= first_str.size() || first_str[start_pos + i] != second_str[i])
		{
			return false;
		}
	}
	return true;

}

bool is_second_substring_of_first(string first_str, string second_str)
{
	//человек вводит две строки, вторая строка короче первой. вывести тру если вторая строка содержится в первой
	// hello - hell = 1
	// hello - ello = 1
	// hello - lo = 1
	// hello - e = 1
	// hello - rello = 0;
	// hello - le = 0;
	// hello - k = 0;
	// hello - olleh = 0;

	for (int i = 0; i < first_str.size(); i++)
	{
		if (is_second_string_in_first(first_str, second_str, i) == true)
		{
			return true;
		}
	}
	return false;
}

string get_without_spaces(string str)
{
	string result_str;
	for (char a : str)
	{
		if (a != ' ')
		{
			result_str.push_back(a);
			//result_arr.push_back(arr1[i]);
		}
	}
	return result_str;
}

void print_without_spaces(string str)
{
	cout << get_without_spaces(str) << endl;
}

template <class T> void print_vector(vector<T> arr)
{
	for (T elem : arr)
	{
		cout << setw(2) << elem << ' ';
	}
	cout << endl;
}

template <class T> void print_vector_with_endl (vector<T> arr)
{
	for (T elem : arr)
	{
		cout << setw(2) << elem << endl;
	}
	cout << endl;
}

int summ_elem_in_vector(vector<int> arr) 
{
	int summ = 0;
	for (int elem : arr)
	{
		summ += elem;
	}
	return summ;
}

void print_reverse_vector_ignore_even(vector<int> arr)
{
	for (int i = arr.size()-1; i >= 0; i--)
	{
		if (arr[i] % 2 != 0)
		{
			cout << arr[i] << endl;
		}
	}
}

vector<int> get_without_0(vector<int> arr)
{
	//принимает на вход массив, возвращает массив без нулей
	vector<int> result_arr;
	for (int c : arr)
	{
		if (c != 0)
		{
			result_arr.push_back(c);
		}
	}
	return result_arr;
}

vector<int> get_with_min_max_at_start_end(vector<int> arr)
{
	//принимает на вход массив, возвращает массив в котором первым элементом стоит минимальный, последний - максимальный
	//меняем через swap

	int index_of_min = index_of_min_elem_of_vector(arr);
	int index_of_max = index_of_max_elem_of_vector(arr);
	
	swap(arr[0], arr[index_of_min]);
	
	swap(arr[arr.size()-1], arr[index_of_max]);
	
	return arr;
}

int find_first_index_of_elem(vector<int> arr, int a)
{
	//человек вводит число, вывести на экран позицию этого числа в массиве и -1 если этого числа в массиве нет

	int pos_of_a = -1;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == a)
		{
			pos_of_a = i;
			break;
		}
	}
	return pos_of_a;
}

int find_first_index_of_elem_using_std(vector<int> arr, int a)
{
	auto iterator = find(arr.begin(), arr.end(), a); 
	
	// аналогичная запись for (auto iterator = arr.begin(); iterator != arr.end(); iterator++)

	//создали переменную iterator с типом auto (тип будет определен в зависимости от правой части), 
	//например auto a = 3, а - будет int, если auto a='c', то a - будет char
	//find ищет в диапазоне, ограниченном началом и концом массива arr элемент a и возвращает итератор найденного элемента. 
	//в случае вектора - вернет итератор, но под итератором в векторе можно понимать индекс 

	if (iterator == arr.end())
	{
		return -1;
	}
	return iterator - arr.begin();
}

bool find_elem_in_sorted_array_binary(vector<int> sorted_arr, int elem)
{
	//бинарный поиск. работает только с отсортированным массивом!
	//возвращает позицию elem в отсортированном массиве. возвращает -1 если такой элемент не найден.
	//sorted_arr.erase(sorted_arr.begin(), sorted_arr.begin() + 5); //удаляем первые 5 элементов из массива index [0,1,2,3,4]
	//sorted_arr.erase(sorted_arr.begin()+7, sorted_arr.end()); //удаляем все элементы, начиная с 7-го
	//sorted_arr.erase(sorted_arr.begin()+3, sorted_arr.begin()+7); //удаляем элементы [3, 6] по шестой, т.е. 3,4,5,6
	//sorted_arr.erase(sorted_arr.begin()+sorted_arr.size()-3 , sorted_arr.end()); //удаляем последние три элемента, к .end нельзя добавлять или вычитать

	print_vector(sorted_arr);

	cout << "Looking for elem: " << elem << endl;

	while (sorted_arr.size() > 1)
	{
		int middle_of_arr = (sorted_arr.size() / 2);
		
		cout << "Index of middle of array: " << middle_of_arr << endl;
		
		if (elem > sorted_arr[middle_of_arr])
		{
			sorted_arr.erase(sorted_arr.begin(), sorted_arr.begin() + middle_of_arr + 1);
		}
		else if (elem < sorted_arr[middle_of_arr])
		{
			sorted_arr.erase(sorted_arr.begin() + middle_of_arr, sorted_arr.end());
		}
		else
		{
			return true;
		}
		print_vector(sorted_arr);
	}

	//while (<условие>)
	//если условие истинно, заходим в фигурные скобки
	//{
	// <действие>
	//}
	//пока выполнено <условие> - выполнять <действие>

	return false;
}

int find_elem_in_sorted_array(vector<int> sorted_arr, int elem)
{
	//вернуть позицию первого встреченного элемента в массиве, который больше или равен elem, 
	//если elem больше всех элементов в массиве - вернуть размер массива
	//1 2 3 3 3 5 9
	//elem = 3  => index=2
	//elem = 4  => index=5
	//elem = 5  => index=5
	//elem = 0  => index=0
	//elem = 10  => index=7, хоть это и не индекс

	for (int i = 0; i < sorted_arr.size(); i++)
	{
		if (sorted_arr[i] >= elem)
		{
			return i;
			break; //после первого совпадения выходим из условия
		}
	}
	return sorted_arr.size();
}

int find_index_of_elem_in_sorted_array_binary(vector<int> sorted_arr, int elem)
{
	int index_of_cur_left_board_of_array = 0;
	int index_of_cur_right_board_of_array = sorted_arr.size()-1;
	//0 1 2 3 4 5 6 7 8 9
	//0-9
	//5-9
	//5-6
	//6-6

	print_vector(sorted_arr);

	while (index_of_cur_left_board_of_array < index_of_cur_right_board_of_array)
	{
		int middle_of_arr = (index_of_cur_left_board_of_array + index_of_cur_right_board_of_array) / 2;

		cout << index_of_cur_left_board_of_array << ' ' << middle_of_arr << ' ' << index_of_cur_right_board_of_array << endl;

		if (elem > sorted_arr[middle_of_arr])
		{
			index_of_cur_left_board_of_array = middle_of_arr + 1;
		}
		else if (elem < sorted_arr[middle_of_arr])
		{
			index_of_cur_right_board_of_array = middle_of_arr - 1;
		}
		else
		{
			return middle_of_arr;
		}
	}
	return -1;
}

vector<int> get_left_part_of_vector(vector<int> arr, int last_index_of_new_vector)
{
	//0 1 2 3 4 5, 3
	//0 1 2 3, можно через erase (операция void-овская, ничего не возвращает), можно через resize (убирает именно с конца!, операция void-овская, ничего не возвращает), можно через push_back в for-е
	//resize - устанавливает массиву размер, указанный как аргумент функции

	vector<int> new_arr = arr; //создан новый вектор, полностью скопировавший исходный вектор
	new_arr.resize(last_index_of_new_vector+1);
	return new_arr;
}

vector<int> get_subvector(vector<int> arr, int first_index_of_new_vector, int last_index_of_new_vector)
{
	//0 1 2 3 4 5,    2,4
	//2 3 4 -  можно через erase (операция void-овская, ничего не возвращает), 
	//можно через resize (убирает именно с конца!, операция void-овская, ничего не возвращает), 
	//можно через push_back в for-е
	//resize - устанавливает массиву размер, указанный как аргумент функции

	//arr.erase(arr.begin()+3,arr.begin()+7) - удаляет элементы ы с 3-го по 6-й, не включая 7-й, т.е. правая граница НЕВКЛЮЧИТЕЛЬНО!!!

	vector<int> new_arr = arr; //создан новый вектор, полностью скопировавший исходный вектор
	
	new_arr.erase(new_arr.begin(), new_arr.begin() + first_index_of_new_vector);
	
	//new_arr.erase(new_arr.begin()+ last_index_of_new_vector, new_arr.end()); 
	
	//0 1 2 3 4 5 6 7    3,6
	//3 4 5 6 7    

	new_arr.erase(new_arr.begin() + (last_index_of_new_vector - first_index_of_new_vector +1), new_arr.begin()+size(new_arr)); //new_arr.end() РАВНО new_arr.begin()+size(new_arr)
	
	return new_arr;
}

vector<int> get_random_vector_max_range_size(int range, int size)
{
	vector<int> dyn_arr;
	
	for (int i = 0; i < size; i++)
	{
		dyn_arr.push_back(rand() % range);
	}
	return dyn_arr;
}

int count_elem_in_arr(vector<int> arr, int a)
{
	//1. Функция принимает на вход вектор и число a. Функция возвращает - сколько раз число а встречалась в векторе.
	//1.1. Без рекурсии.
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == a)
		{
			counter++;
		}
	}
	return counter;
}

bool is_summ_arr0_bigger_arr1(vector<int> arr0, vector<int> arr1)
{
	//2. Функция принимает на вход 2 вектора. 
	//Вернуть true, если сумма элементов в первом веторе больше чем во втором. Иначе false;
	int summ_of_elem_arr0 = 0;

	for (int i = 0; i < arr0.size();i++)
	{
		summ_of_elem_arr0 += arr0[i];
		cout << "summ_of_elem_arr0" << ' ' << summ_of_elem_arr0 << endl;
	}

	int summ_of_elem_arr1 = 0;
	for (int i = 0; i < arr1.size();i++)
	{
		summ_of_elem_arr1 += arr1[i];
		cout << "summ_of_elem_arr1" << ' ' << summ_of_elem_arr1 << endl;
	}
	return summ_of_elem_arr0 > summ_of_elem_arr1;
}

bool is_array0_equal_array1(vector<int> arr0, vector<int> arr1)
{
	//3. Функция принимает на вход 2 вектора. Вернуть true, если векторы равны (у них одинаковый размер и содержимое, учитывая порядок).

	if (arr0.size() != arr1.size())
	{
		return false;
	}

	for (int i = 0; i < arr0.size(); i++)
	{
		if (arr0[i] != arr1[i])
		{
			return false;
			break;
		}
	}
	return true;
}

vector<int> get_fibonacci_arr(int n)
{
	//возвращает массив, заполненный первыми n-числами Фибоначчи
	//размер возвращаемого массива будет n
	//F0=0, F1=1, Fn = Fn-1 + Fn-2

	//arr[0] = 0, arr[1] = 1, arr[n] = arr[n-1] + arr[n-2]

	vector<int> fib_arr;
	fib_arr.push_back(0);
	fib_arr.push_back(1);

	for (int i = 2; i < n + 2; i++)
	{
		fib_arr.push_back(fib_arr[i - 1] + fib_arr[i - 2]);
		print_vector(fib_arr);
	}
	return fib_arr;
}

int get_random_number_from_range(int min, int max)
{
	int a = rand()% (max-min+1) + (min);
	return a;
}

string get_random_english_string(int lenght)
{
	string random_str;
	for (int i = 0; i < lenght; i++)
	{
		random_str.push_back(get_random_number_from_range('a', 'z'));
	}
	return random_str;
}

char random_gender()
{
	int rnd_gender = rand() % 2;
	if (rnd_gender == 0)
	{
		return 'M';
	}
	else
		return 'F';
}

template<class MapKey,class MapValue> void PrintMap(std::map<MapKey, MapValue> m)
{
	for (auto [key, value] : m)
	{
		cout << "Map.Key: " << key << " - " << "Map.Value: " << value << endl;
	}
	cout << endl;
}