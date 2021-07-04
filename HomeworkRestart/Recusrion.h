#pragma once
#include <iostream>

namespace Recursion
{
	int factorial(int a)
	{
		//функция поиска фаториала числа а
		//5! = 1*2*3*4*5
	
		int factorial = 1; //так как мультиплицируются результаты, 0 нельзя использовать в качестве инициализации переменной
	
		for (int i = 1; i <= a; i++)
		{
			factorial *= i;
		}
		return factorial;
	}

	//рекурсия - это когда функция вызывает саму же себя

	void f0(int a)
	{
		std::cout << a << std::endl;
		if (a < 10) //условие выхода из рекурсии
		{
			f0(a+1);
		}
		std::cout << 4;
	}

	void f1(int a)
	{
		//принимает число, например 120, принтует 120,60,30,15,7,3,1
		if (a != 0)
		{
			std::cout << a << std::endl;
			f1(a / 2);
		}
	}

	int factorial_recursion(int n)
	{
		//функция поиска фаториала числа а
		//5! = 1*2*3*4*5
		//4! = 1*2*3*4
		//5! = 5 * 4!
		
		//n! = n * (n-1)!

		if (n == 1)
		{
			return 1;
		}
		return n * factorial_recursion(n - 1);
	}

	int* max_of_values_between_two_pointers(int* pointer_1, int* pointer_2)
	{
		std::cout << "max_of_values_between_two_pointers: " << *pointer_1 << ' ' << *pointer_2 << std::endl;
		if (*pointer_2 > * pointer_1)
		{
			return pointer_2;
		}
		else
		{
			return pointer_1;
		}
	}

	int* find_max_in_segment_of_array(int* pointer_left_bound, int* pointer_right_bound)
	{
		//max{ ind0 : ind6 } = максимум {ind0 , max { ind1 : ind6 } }
		
		std::cout << "find_max_in_segment_of_array: " << *pointer_left_bound << ' ' << *pointer_right_bound << std::endl;

		if (pointer_left_bound == pointer_right_bound)
		{
			return pointer_left_bound;
		}
		return max_of_values_between_two_pointers(pointer_left_bound,find_max_in_segment_of_array(pointer_left_bound+1, pointer_right_bound));
	}

	int* find_max_in_segment_of_array_binary(int* pointer_left_bound, int* pointer_right_bound)
	{
		//max{ ind0 : ind6 } = максимум {max {ind0 : ind3} , max { ind4 : ind6 } }

		assert(pointer_left_bound <= pointer_right_bound);

		std::cout << "find_max_in_segment_of_array: " << *pointer_left_bound << ' ' << *pointer_right_bound << std::endl;

		if (pointer_left_bound == pointer_right_bound)
		{
			return pointer_left_bound;
		}
		int elements_count = pointer_right_bound - pointer_left_bound + 1;
		cout << elements_count << endl;
		int* pointer_to_middle_element = pointer_left_bound + elements_count / 2 - 1;
		int* max_of_left_half = find_max_in_segment_of_array_binary(pointer_left_bound, pointer_to_middle_element);
		int* max_of_right_half = find_max_in_segment_of_array_binary(pointer_to_middle_element+1, pointer_right_bound);

		return max_of_values_between_two_pointers(max_of_left_half, max_of_right_half);
	}

	int power_x_y(int x, int y)
	{
		//x - число
		//у - степень
		//x * x^(y-1)

		int result = 0;
		if (y == 0)
		{
			return 1;
		}
		result = x * power_x_y(x, y - 1);
		cout << result << endl;
		return result;
	}

	int summ_of_elements_in_segment(int* pointer_left, int* pointer_right)
	{
		//сумма {ind0 : ind_n} = arr[ind0] + сумма {arr[ind1] : arr[ind_n]}
		
		if (pointer_left == pointer_right)
		{
			return *pointer_left;
		}

		int summ_of_elements = 0;
		cout << "pointer_left: " << *pointer_left << ' ' << "pointer_right: " << *pointer_right << endl;
		summ_of_elements = *pointer_left + summ_of_elements_in_segment(pointer_left+1, pointer_right);
		cout << summ_of_elements << endl; 
		return summ_of_elements;
	}

	int number_of_elements_in_segment(int* pointer_left, int* pointer_right)
	{
		//num {ind0 : ind_n} =  num {ind0:ind0} + num {ind1 : ind_n} = 1 + num {ind1 : ind_n}
		
		assert(pointer_left <= pointer_right);
		if (pointer_left == (pointer_right-1) || pointer_left == pointer_right)
		{
			return 1;
		}

		int number_of_elements = 0;
		cout << "pointer_left: " << pointer_left << ' ' << "pointer_right: " << pointer_right << endl;
		//number_of_elements = 1 + number_of_elements_in_segment(pointer_left + 1, pointer_right);
		number_of_elements = number_of_elements_in_segment(pointer_left, pointer_left) + number_of_elements_in_segment(pointer_left + 1, pointer_right);
		return number_of_elements;
	}

	int* find_first_pointer_to_elem_in_segment(int* pointer_left, int* pointer_right, int a)
	{
		//find (ind0 : ind_n, a) = 

		if (pointer_left == pointer_right && *pointer_left != a)
		{
			return nullptr; //ptr - это сокращение от pointer, которое создатели языка выбрали для сокращения
		}

		if (*pointer_left == a)
		{
			return pointer_left;
		}

		return find_first_pointer_to_elem_in_segment(pointer_left + 1, pointer_right, a);
	}

	int* find_last_pointer_to_elem_in_segment(int* pointer_left, int* pointer_right, int a)
	{
		//find (ind0 : ind_n, a) = 

		if (pointer_left == pointer_right && *pointer_right != a)
		{
			return nullptr; //ptr - это сокращение от pointer, которое создатели языка выбрали для сокращения
		}

		if (*pointer_right == a)
		{
			return pointer_right;
		}

		return find_last_pointer_to_elem_in_segment(pointer_left, pointer_right-1, a);
	}

	int* binary_find_first_pointer_to_elem_in_sorted_segment(int* pointer_left, int* pointer_right, int a)
	{
		if (pointer_left > pointer_right)
		{
			return nullptr;
		}
		
		if (pointer_left == pointer_right && *pointer_left != a)
		{
			return nullptr;
		}

		int* ptr_to_middle_of_segment = pointer_left + ((pointer_right - pointer_left) / 2);
		
		if (*ptr_to_middle_of_segment == a)
		{
			return ptr_to_middle_of_segment;
		}
		else if (a < *ptr_to_middle_of_segment)
		{
			return binary_find_first_pointer_to_elem_in_sorted_segment(pointer_left, ptr_to_middle_of_segment-1, a);
		}
		else
		{
			return binary_find_first_pointer_to_elem_in_sorted_segment(ptr_to_middle_of_segment+1, pointer_right, a);
		}
	}

}

/*
1. Написать функцию, которая которая принимает число и степень. 
Возвращает это число возведенное в эту степень.
Не использовать for и pow.

2. Написать функцию, которая принимает указатель на левый и правый границы сегмента:
Возвращает сумму элементов в этом сегменте. Нельзя использовать фор (делать через рекурсию).

3. Написать функцию, которая принимает указатель на левый и правый границы сегмента:
Возвращает количество элементов в этом сегменте. Нельзя вычитать один адрес из другого (т.е. использовать p1 - p2).

4. Написать функцию, которая принимает указатель на левый и правый границы сегмента и число:
Вернуть указатель на элемент в массиве, который равен этому числу. 
Если числа в массиве нет, вернуть нулевой указатель (return nullptr; или return 0);
*/

int count_elem_in_arr_recursion(int* ptr_l, int* ptr_r, int a)
{
	//1. Функция принимает на вход вектор и число a. Функция возвращает - сколько раз число а встречалась в векторе.
	//1.2. С рекурсией.
	
	if (ptr_l == ptr_r)
	{
		if (*ptr_l == a)
		{
			return 1;
		}
		return 0;
	}
	
	int counter = 0;
	
	//count {ind0:indn , a} = count {ind0:ind0, a} + count { ind1:indn, a}

	if (*ptr_l == a)
	{
		counter++;
	}

	counter += count_elem_in_arr_recursion(ptr_l+1, ptr_r, a);
	
	cout << counter << ' ' << *ptr_l << ' ' << *ptr_r << endl;
	
	return counter;
}

bool is_array0_equal_array1_recursion(int* ptr_l0, int* ptr_r0, int* ptr_l1, int* ptr_r1)
{
	//3. Функция принимает на вход 2 вектора. Вернуть true, если векторы равны (у них одинаковый размер и содержимое, учитывая порядок).
	//С рекурсией

	// is_equal = {ind0:indn, ind0:indn} = is_equal {ind0:ind0, ind0:ind0} && is_equal{ind1:indn, ind1:indn}

	if ((ptr_r0 - ptr_l0) != (ptr_r1 - ptr_l1))
	{
		return false;
	}
	
	if (ptr_l0 == ptr_r0 && ptr_l1 == ptr_r1)
	{
		if (*ptr_l0 == *ptr_l1)
		{
			return true;
		}
	}
	
	if (*ptr_l0 != *ptr_l1)
	{
		return false;
	}

	return is_array0_equal_array1_recursion(ptr_l0 + 1, ptr_r0, ptr_l1 + 1, ptr_r1);
}

int get_n_num_fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int n_num_fibonacc = get_n_num_fibonacci(n - 1) + get_n_num_fibonacci(n - 2);
	return n_num_fibonacc;
}

vector<int> get_fibonacci_arr_recursion(int n)
{
	//возвращает массив, заполненный первыми n-числами Фибоначчи
	//размер возвращаемого массива будет n
	//F0=0, F1=1, Fn = Fn-1 + Fn-2

	//arr[0] = 0, arr[1] = 1, arr[n] = arr[n-1] + arr[n-2]

	if (n == 0)
	{
		std::vector<int> result;
		return result;
	}

	if (n == 1)
	{
		std::vector<int> result = {0};
		return result;
	}

	if (n == 2)
	{
		std::vector<int> result = { 0,1 };
		return result;
	}

	vector<int> fib_arr = get_fibonacci_arr_recursion(n - 1);
	fib_arr.push_back(fib_arr[fib_arr.size() - 1] + fib_arr[fib_arr.size() - 2]);
	return fib_arr;
}
