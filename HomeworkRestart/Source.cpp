//Hello Unicode World ☺. 
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include "DataStructures/Queue.h"
#include "Sequences.h"
#include "Functions.h"
#include "ConsoleFunctions.h"
#include "Sorts.h"
#include "Pointers.h"
#include "DynamicMemory.h"
#include "Recusrion.h"
#include "Structures.h"
#include "Classes/Fraction.h"
#include "GlobalStructuresCarUtils.h"
#include "Geometry.h"
#include "Classes/ButtonStruct.h"
#include "Initializations.h"
#include "CorpPosition.h"
#include "Operators.h"
#include "ServiceClasess.h"
#include "Classes/CustomString.h"
#include "Classes/VectorWithinEvens.h"
#include "MapStdExamples.h"
#include "SetStdExamples.h"
#include "WorkWithTextFiles.h"
#include "WorkWithBinaryFiles.h"
#include "2021-02-27.h"
#include "List.h"
#include "List1.h"
#include "DataStructures/ForwardList.h"
#include "DataStructures/List.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/BinarySearchTree.h"
#include "DataStructures/BinarySearchTreeMap.h"
#include "DataStructures/Graph.h"
#include "Json/JsonTests.h"
#include "GameMatrix/GameMatrix.h"
#include "Hash/SHA256.h"
#include "SHA256 from GitHub/SHA256-GitHub.h"
#include "ParallelThreads/ParallelThreads.h"
#include "ParallelThreads/RingBuffer.h"
#include "ParallelThreads/RingBufferTest.h"
#include "Inheritance/InheritanceBasic.h"
#include "Inheritance/InheritanceSquareAndRectangle.h"
#include "EnumExamples.h"
#include "Hash/HashTableVector.h"
#include "Polymorphism/PolymorphismBasic.h"
#include "Polymorphism/DynamicCast.h"
#include "PointersAndReferences.h"
#include "ChronoTime.h"
#include "Polymorphism/SimplePatternStrategy.h"
#include <sys/types.h>
#include <winsock.h>
#include "Network/Test.h"
#include "Iterators.h"
#include "Templates.h"
#include "Hash/HashTableOpenAddress.h"
#include "VariadicTemplates.h"
#include "MoveSemantics/LvalueRvalue.h"
//#include "MoveSemantics/MoveSemanticsClass.h"
//#include "SmartPointers/UniquePtr.h"
#include "SmartPointers/SharedPtr.h"
#include "MoveSemantics/PerfectForwarding.h"


using namespace std;

#pragma region

void f0()
{
	int n = 0;
	cin >> n;
	cout << n * 2 << endl;

}

void f1()
{
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	if (a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void f2()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
	{
		if (a > c)
		{
			cout << a << endl; //выполняется условие, что a>b и a>=c
		}
		else
		{
			cout << c << endl; //выполняется условие, что a>b и c>=a
		}
	}
	else //выполняется условие, что b>=a
	{
		if (b > c)
		{
			cout << b << endl; //выполняется условие, что a>b и a>=c
		}
		else
		{
			cout << c << endl; //выполняется условие, что a>b и c>=a
		}
	}
}

void f3()
{
	int a, b, c;
	cin >> a >> b >> c;

	bool d = (a > b);
	bool e = (b > c);
	bool f = (c > a);
	bool g = (c > b);

	if (d == true && e == true)
	{
		cout << a << endl; //выполняется условие, что a>b и b>c
	}
	else // a<=b || b<=c.   !(d && e) = !d || !e
	if (f == true && g == true)
	{
		// (!d || !e) && (f && g)
		cout << c << endl; // выполняется условие, что c>a и c>b
	}
	else //отрицание 67 строки - a>=c || b>=c. !(f && g) = !f || !g
	{
		// Имеем эти факты, когда пришли сюда: (!d || !e) && (!f || !g)

		// Все возможные варианты расположения или
		// (!d || !e) && (!f || !g) =
		// ((!f || !g) && !f) || ((!f || !g) && !g) = 
		// (!f && !f || !g && !f) || (!f && !g || !g && !g) = 
		// (!f || !g && !f) || (!f && !g || !g) =
		// !f || !g = 
		// (c <= a) || (c <= b) - из этого следует, что c - не самый большой, а значит - самый большой либо а, либо b

		if (d == true)
		{ // a>b && ((c <= a) || (c <= b))
			cout << a << endl;
		}
		else
		{
			cout << b << endl;
		}

		//(a<=b || b<=c) && (a>=c || b>=c)
		
		//(a<=b && b<=c) && (a>=c || b>=c)
		
		//(a<=b) && (a>=c || b>=c)
		//(a<=b) && (a>=c)
		//(a<=b) && (b>=c)

		//(b<=c) && (a>=c || b>=c)
		//(b<=c) && (a>=c)
		//(b<=c) && (b>=c)
		
		//(a<=b || b<=c) && (a>=c && b>=c)

		//(a<=b || b<=c) && (a>=c)
		//(a<=b) && (a>=c)
		//(b<=c) && (a>=c)
		
		//(a<=b || b<=c) && (b>=c)
		//(a<=b) && (b>=c)
		//(b<=c) && (b>=c)

	}

	//bool q;
	//bool w;
	//bool e;
	//
	//if (q)
	//{
	//	// q
	//}
	//else 
	//{
	//	// !q
	//	if (e)
	//	{
	//		// e && !q
	//	}
	//	else
	//	{
	//		// !e && !q
	//		if (w)
	//		{
	//			// w && !e && !q
	//		}
	//		else
	//		{
	//			//!w && !e && !q
	//		}
	//	}
	//}
}

void f4()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b && a > c)
	{
		cout << a << endl;
	}
	else //a<=b || a<=c - подтерждает что а не самое большое и может быть меньше и b, и c
	{
		if (b > c)
		{
			cout << b << endl;
		}
		else // b <= c
		{
			cout << c << endl;
		}
	}

}

void f5()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b)
	{
		if (a > c)
		{
			cout << a << endl;
		}
		else
		{ 
			//a<b && a<=c
			if (b > c)
			{
				cout << c << endl;
			}
			else
			{
				//a<b && a<=c && c>=b
				cout << b << endl;
			}
		}
	}
	else
	{
		//a>=b
		if (a < c)
		{
			cout << a << endl;
		}
		else
		{
			//a>=b c<=a, а - самое большое
			if (c > b)
			{
				cout << c << endl;
			}
			else
			{
				cout << b << endl;
			}
		}
	}

}

//void f6()
//{
//	int a, b, c;
//	int max_a_b = 0;
//	int max_b_c = 0;
//	cin >> a >> b >> c;
//
//	max_a_b = a;
//	max_b_c = b;
//
//	if (b>a)
//	{
//		max_a_b = b;
//	}
//	if (c>b)
//	{
//		max_b_c = c;
//	}
//
//	if (max_a_b > max_b_c)
//	{
//		// a > b => c b a
//		// b > b => 0
//		// a > c => b c a
//		// b > c => 0
//
//		// c b a, _ max_b_c a
//		// b c a, _ max_b_c a
//		cout << max_b_c << endl;
//	}
//	else
//	{
//		// max_a_b <= max_b_c
//		
//		// (a > b) a <= b (b > c)     => 0
//		// (b > a) b <= b (b > c)     => a c b => a c       b
//		//								 c a b =>  c a       b
//		// (a > b) a <= c (b < c)	  => b a c => _ max_a_b c 
//		// (b > a) b <= c (b < c)	  => a b c => _ max_a_b c 
//	}
//}

void f7()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// a < b,  c < d
	// [a,b] [c,d]
	// Вывести их пересечение

	int max_left_ac = a;
	if (c > a)
	{
		max_left_ac = c;
	}
	
	int min_right_bd = b;
	if (d < b)
	{
		min_right_bd = d;
	}

	if (max_left_ac < min_right_bd)
	{
		cout << max_left_ac << ' ' << min_right_bd << endl;
	}
	else
	{
		cout << "No intersection" << endl;
	}
}

void f8()
{
	//даны три числа, вывести их в порядке возрастания. все числа разные.
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a < b)
	{
		if (b < c)
		{
			cout << a << ' ' << b << ' ' << ' ' << c << endl;
		}
		else
		{
			//b>a, b>c
			if (c > a)
			{
				cout << a << ' ' << c << ' ' << ' ' << b << endl;
			}
			else
			{
				cout << c << ' ' << a << ' ' << ' ' << b << endl;
			}
		}
	}
	else
	{
		//a>b
		if (a < c)
		{
			//a>b, c>a
			cout << b << ' ' << a << ' ' << ' ' << c << endl;
		}
		else
		{
			//a>b, a>c
			if (b > c)
			{
				//a>b, a>c, b>c
				cout << c << ' ' << b << ' ' << ' ' << a << endl;
			}
			else
			{
				//a>b, a>c, c>b
				cout << b << ' ' << c << ' ' << ' ' << a << endl;
			}
		}
	}
}

void f9()
{
	//пузырьковая сортировка
	//4 2 1
	//a b c
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b)
	{
		swap(a, b); //swap меняет значения в переменных
		//2 4 1
		//a b c
	}
	if (b > c)
	{
		swap(b, c);
		//2 1 4
		//a b c
	}
	if (a > b)
	{
		swap(a, b);
		//1 2 4
		//a b c
	}
	cout << a << ' ' << b << ' ' << c << endl;
}

void f10() //считалка четных, нечетных чисел и нулей
{
	int const n = 10;
	int arr[n] = {};
	int even_counter = 0;
	int odd_counter = 0;
	int zero_counter = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0 && arr[i] !=0)
		{
			cout << arr[i] << " - Нечетное" << endl;
			odd_counter++;
		}
		if (arr[i] % 2 == 0 && arr[i] != 0)
		{
			cout << arr[i] << " - Четное" << endl;
			even_counter++;
		}
		if (arr[i] == 0)
		{
			cout << arr[i] << " - Ноль" << endl;
			zero_counter++;
		}
	}
	cout << "Количество нечетных чисел: " << odd_counter << endl;
	cout << "Количество четных чисел: " << even_counter << endl;
	cout << "Количество нулей: " << zero_counter << endl;
}

void f11() //шифр Цезаря
{
	int offset = 2; //сдвиг по алфавиту
	
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //создал массив букв
	cout << "enter 1 word only: ";
	string user_input; //создал строку для ввода пользователем слова
	cin >> user_input; //заполнение строки
	//int word_lenght = size(user_input); //user_input.size()
	int const word_lenght_limit = 140; //создал константу для предельной длины пользовательского слова для размера массива ниже
	char users_word_arr[word_lenght_limit] = {0}; //создал пустой массив букв чтобы через него разделить введенное слово на символы
	
	//vector<char> temp_vector; //создан пустой вектор, у вектора тоже есть size

	for (int i = 0; i < user_input.size(); i++) //запускаю цикл, чтобы заполнить массив "пользовательского слова" из строки ввода
	{
		users_word_arr[i] = user_input[i];
		//temp_vector.push_back(user_input[i]); //по одному элементу добавляется в конец вектора, увеличивая его размер.
	}
	
	//string temp_string = user_input; так как стринг это тоже массив (вектор чаров), к нему можно обращаться по адресу

	int current_user_string_position = 0; //создан счетчик для перевода указателя на букву в слове в массиве
	
	for (int j = 0; j < user_input.size(); j++)
	{
		for (int i = 0; i < (sizeof(alphabet)); i++) //* user_input.size() 
		{
			if (current_user_string_position < user_input.size() && alphabet[i] == users_word_arr[current_user_string_position])
			{
				users_word_arr[current_user_string_position] = alphabet[(i + offset) % sizeof(alphabet)];
				cout << users_word_arr[current_user_string_position];
				current_user_string_position++;
			}
		}
	}
} //не работает в минусовый оффсет

void f12()
{
	char a = 'z';
	char b = 4;
	char c = a - 2;
	cout << a+0 << ' ' << int(a) << ' ' << char(a - 2) << ' ' << c << endl;
	cout << int('a') << ' ' << int('b') << ' ' << int('c') << endl;
	cout << int('z' - 'a' + 1) << endl;
	//input char - print its ASCII code
	cin >> a;
	cout << int(a) << endl;
	//вывести какая это буква по алфавиту - её номер
	cout << int(a - 'a') << endl;
}

void f13()
{
	int offset = 2;
	string user_input;
	cin >> user_input;
	
	for (int i = 0; i < user_input.size(); i++)
	{
		cout << user_input[i] << ' ' << int(user_input[i]) << ' ' << user_input[i]+offset << ' ' << char(user_input[i] + offset) << ' ';
		cout << char(((user_input[i] + offset) - 'a') % ('z'-'a'+ 1) +'a')<< endl;
	}
}

void f14()
{
	//человек вводит три числа, которые - год, месяц, день в числовом формате
	//во всех месяцах 31 день, включая февраль, 12 месяцев. вывести вчерашний день - год, месяц, день
	int y, m, d;
	cin >> y >> m >> d;
	//2020-10-5
	if (d != 1)
	{
		cout << y << ' ' << m << ' ' << d - 1 << endl;
	}
	else
	{
		// d==1
		if (m != 1)
		{
			cout << y << ' ' << m - 1 << ' ' << d << endl;
		}
		else
		{
			//m==1, d==1
			cout << y - 1 << ' ' << m << ' ' << d << endl;
		}
	}
}

void f15()
{
//вводит три числа a b c. ax^2 + bx + c = 0. Вывести значения x, искать дискриминант. b^2 - 4ac
	int a, b, c;
	cin >> a >> b >> c;
	
	int d=b*b-4*a*c;

	if (d == 0)
	{
		cout << -b / 2 * a << endl;
	}
	else if (d > 0)
	{
		cout << (-b + sqrt(d)) / 2 * a << endl;
		cout << (-b - sqrt(d)) / 2 * a << endl;
	}
}

void f16()
{
	//три числа, вывести true если какое-то из этих чисел является произведением двух других, false - если не является
	int a, b, c;
	cin >> a >> b >> c;
	if (a * b == c || b * c == a || a * c == b)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

void f17()
{
	//вывести весь алфавит
	for (int i = 0; i <= 255; i++)
	{
		cout << i << ' ' << char(i) << endl;
	}
}

void f18()
{
	//вводит символ, букву, английскую. сказать = это большая или маленькая.
	//вывести тру если введенная буква маленькая
	//если буква маленькая - вывести small, большая - large, иное - undefined
	char a;
	cin >> a;

	cout << int(a) << endl;

	if (int(a) >= int('a') && int(a) <= int('z'))
	{
		cout << "Small";
	}
	else if (int(a) >= int('A') && int(a) <= int('Z'))
	{
		cout << "Large";
	}
	else
	{
		cout << "Undefined";
	}
}

void f19()
{
	//вводит строку при этом все символы маленькие, вывести на экран всё то же но большие.
	string user_input;
	cin >> user_input;

	//for (int i = 0; i <= user_input.size(); i++) //бегаем по индексам строки
	//{
	//	//cout << user_input[i] << endl;
	//}
	for (char c : user_input) //бегаем по самим символам в строке
	{
		//cout << c << endl; //c - это уже символ
		int offset_in_alphabet = (c - 'a');
		cout << char('A' + offset_in_alphabet);
	}
}

void f20()
{
	//человек вводит две строки, вывести на экран тру если они одинаковые
	string a,b;
	cin >> a >> b;

	bool is_equal = true;

	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
			{
				is_equal = false;
			}
		}
	}
	else
	{
		is_equal = false;
	}
	cout << is_equal << endl;
}

void f21()
{
	//человек вводит две строку и символ, вывести на экран тру если в строке есть символ
	string a;
	char b;
	cin >> a;
	cin >> b;

	bool is_char_in_string = false;

	for (char c : a)
	{
		if (c == b)
		{
			is_char_in_string == true;
		}
	}
	cout << is_char_in_string;
}

void f22()
{
	//человек вводит две строки и число. вывести тру если в старт.поз первой строки начинается символ второй строки
	// abcde cd 2 - true
	// abcde cd 3 - false
	// abcde de 3 - true
	// abcde de 2 - false
	// abcde cdo 2 - false

	string a, b;
	cin >> a >> b;

	int start_pos;
	cin >> start_pos;

	cout << is_second_string_in_first (a,b, start_pos) << endl;
}

void f23()
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

	string a, b;
	//cin >> a >> b;
	//cout << is_second_substring_of_first(a, b) << endl;

	std::cout << is_second_substring_of_first("Hello", "ello") << std::endl;
	std::cout << is_second_substring_of_first("Hello", "elo") << std::endl;
	std::cout << is_second_substring_of_first("Hello", "olleH") << std::endl;
	std::cout << is_second_substring_of_first("Hello", "H") << std::endl;
	std::cout << is_second_substring_of_first("Hello", "k") << std::endl;
	std::cout << is_second_substring_of_first("Hello", "lol") << std::endl;

}

void f24()
{
	int num;
	cin >> num;
	cout << sqr(num) << endl;
	cout << sqr(3) << endl;
	cout << sqr(sqr(num)) << endl;
}

void f25()
{
	string str;
	cin >> str;

	char a;
	cin >> a;

	cout << count_char_in_string(str, a) << endl;
}

void f26()
{
	print_without_spaces("Hello world!");
	print_without_spaces("Hello world world!");
	print_without_spaces(" Hello world world!");
	print_without_spaces("Hello   world world! ");
}

void f27()
{
	//создать вектор, заполненный рандомными числами. количество чисел - ввод от человека
	int a=30;
	
	vector<int> dyn_arr; //создали пустой вектор, у него есть функция size и она 0 пока что
	
	for (int i = 0; i < a; i++)
	{
		dyn_arr.push_back(rand() % 20 + 1);
	}

	//print_vector(dyn_arr);
	//cout << find_first_index_of_elem(dyn_arr,5) << endl;
	//cout << find_first_index_of_elem(dyn_arr,7) << endl;
	//cout << find_first_index_of_elem(dyn_arr,2) << endl;
	//cout << find_first_index_of_elem(dyn_arr,4) << endl;
	//cout << summ_elem_in_vector(dyn_arr) << endl;
	//cout << "Max elem" << max_elem_of_vector(dyn_arr) << endl;
	//print_reverse_vector_ignore_even(dyn_arr);
	//print_vector(get_without_0(dyn_arr));
	//print_vector(get_with_min_max_at_start_end(dyn_arr));
	//print_vector(bubble_sort(dyn_arr));
	//bubble_sort(dyn_arr);
	//selection_sort(dyn_arr);
	//counting_sort(dyn_arr);
	//online_sort(dyn_arr);
	//ConsoleFunctions::print_arr_histogramm(dyn_arr);
	//find_elem_in_sorted_array_binary(bubble_sort(dyn_arr), 3);
	cout << find_index_of_elem_in_sorted_array_binary(bubble_sort(dyn_arr), 3) << endl;
}

void f28()
{
	int raw_arr[10] = { 0 };
	for (int i = 0; i < size(raw_arr) - 1; i++)
	{
		raw_arr[i] = rand() % 20 + 1;
		cout << raw_arr[i] << ' ';
	}
		cout << endl;
	
	cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[0], &raw_arr[size(raw_arr) / 2]) << endl;
	
	cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[size(raw_arr) / 2], &raw_arr[size(raw_arr) -1]) << endl;
	
	cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[0], &raw_arr[size(raw_arr) -1]) << endl;
	
	cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[3], &raw_arr[4]) << endl;
}

void f29()
{
	int raw_arr[20] = { 0 };
	for (int i = 0; i < size(raw_arr); i++)
	{
		raw_arr[i] = rand() % 10 + 1;
		cout << raw_arr[i] << ' ';
	}
	cout << endl;

	//cout << *Recursion::find_max_in_segment_of_array_binary(&raw_arr[0], &raw_arr[size(raw_arr) - 1]) << endl;
	//cout << Recursion::binary_find_first_pointer_to_elem_in_sorted_segment(&raw_arr[0], &raw_arr[size(raw_arr)-1],16) - &raw_arr[0]<< endl;
	//cout << Recursion::binary_find_first_pointer_to_elem_in_sorted_segment(&raw_arr[0], &raw_arr[size(raw_arr)-1],16) << endl;
}

void f30()
{
	vector<int> sorted_arr0 = bubble_sort(get_random_vector_max_range_size(20, 10));
	
	vector<int> sorted_arr1 = bubble_sort(get_random_vector_max_range_size(20, 6));
	
	print_vector(sorted_arr0);
	
	print_vector(sorted_arr1);
	
	print_vector(merge_two_sorted_vectors(sorted_arr0, sorted_arr1));
}

void f31()
{
	//vector<int> arr0 = get_random_vector_max_range_size(3, 10);
	//vector<int> arr1 = get_random_vector_max_range_size(3, 10);
	//vector<int> arr0 = { 1,2};
	//vector<int> arr1 = { 3 };
	//print_vector(arr0);
	//print_vector(arr1);
	
	//cout << is_array0_equal_array1_recursion(&arr0[0], &arr0[arr0.size()-1], &arr1[0], &arr1[arr1.size() - 1]);
	
	//print_vector(get_fibbonacci_arr(10));
	//print_vector(get_fibonacci_arr_recursion(30));

	//cout << Structures::is_date_x_is_later_date_y(Structures::Date{2020, 5, 3}, Structures::Date{2020, 5, 3}) << endl;

	//print_season_of_date(Structures::Date{ 2020, 1, 3 });
	
	//cout << temp_yesterday(Structures::Date{ 2021, 12, 5 }).year << endl;
	//cout << temp_yesterday(Structures::Date{ 2021, 12, 5 }).month << endl;
	//cout << temp_yesterday(Structures::Date{ 2021, 12, 5 }).day << endl;

	//Structures::arr_of_random_people(5);

}

void f32()
{
	Fractions::Fraction fr1(1, 5);
	Fractions::Fraction fr2(1);
	Fractions::Fraction fr3;
	Fractions::Fraction fr4(rand()%20+1,rand()%10+1);
	cout << fr1 << endl;
	cout << fr2 << endl;
	cout << fr3 << endl;
	cout << fr4 << endl;

	fr1.print_fr();
	fr2.print_fr();
	fr3.print_fr();
	fr4.print_fr();

	//if (fr4.num / fr4.den > 2)
	//{
	//	cout << true << endl;
	//}
	
	if (fr4.is_greater(2))
	{
		cout << true << endl;
	}
}

void f33()
{
	//создать каршоп накидать рандомных машин с рандомными ценами
	
	CarShop shop;
	
	for (int i = 0; i < 10; i++)
	{
		CarWithPrice car_with_price;
		car_with_price.car = Car(i, get_random_number_from_range(10, 20), "white", get_random_number_from_range(1, 5));
		car_with_price.price = get_random_number_from_range(1, 10);
		shop.cars_for_sale.push_back(car_with_price);
	}
	cout << shop << endl;

}

void f34()
{
	//------------Первый вариант - создать прямоугольник вне цикла
	Geometry::Rectangle r1;
	vector<Geometry::Rectangle> rectangles_vector;
	for (int i=0; i < 10; i++)
	{
		r1.height = rand() % 3 + 1;
		r1.width = rand() % 3 + 1;
		rectangles_vector.push_back(r1);
		cout << r1 << endl; //вывести на экран все прямоугольники
	}

	/*
	//------------Второй вариант - создать прямоугольник внутри цикла
	vector<Geometry::Rectangle> rectangles_vector;
	for (int i = 0; i < 10; i++)
	{
		Geometry::Rectangle r1(rand() % 3 + 1, rand() % 3 + 1);
		rectangles_vector.push_back(r1);
		cout << r1 << endl;
	}
	
	//------------Третий вариант - не создавать прямоугольник вообще
	vector<Geometry::Rectangle> rectangles_vector;
	for (int i = 0; i < 10; i++)
	{
		rectangles_vector.push_back(Geometry::Rectangle(rand() % 3 + 1, rand() % 3 + 1));
		cout << rectangles_vector[i] << endl;
	}
	*/

	cout << " --- " << endl;

	for (Geometry::Rectangle r : rectangles_vector) //вывести на экран все прямоугольники
	{
		cout << r << endl;
	}

	cout << " --- " << endl;

	for (Geometry::Rectangle r : rectangles_vector) //вывести на экран все прямоугольники если они квадраты
	{
		if (r.is_rectangle_square())
		{
			cout << r << endl;
		}
	}

	cout << " --- " << endl;

	for (Geometry::Rectangle r : rectangles_vector) //вывести на экран все прямоугольники с площадью больше 4
	{
		if (r.area_of_rectangle() > 4)
		{
			cout << r << endl;
		}
	}

	cout << " --- " << endl;

	int summ_of_per = 0;
	for (Geometry::Rectangle r : rectangles_vector) //посчитать сумму периметров всех прямоугольников
	{
		summ_of_per += r.perimeter_of_rectangle();
	}
	cout << summ_of_per << endl;
}

void f35()
{
	Fractions::Fraction fr1(3, 5);
	//fr1.num = 9;

	//fr1.set_8_to_num();
	//cout << fr1.num << endl;

	//cout << fr1.num << endl;
	Fractions::Fraction fr2(3);
	Fractions::Fraction fr3;
	cout << fr1 << endl;
	cout << fr2 << endl;
	cout << fr3 << endl;
}

void f36()
{
	for (int i = 0; i < 20; i++)
	{
		int a = rand() % 100;
		if (a < 30)
		{
			cout << "Hello" << endl;
		}
		else
		{
			cout << "Bye" << endl;
		}
	}
}

void f37()
{
	//StandNoCircs stand;
	//StandLocked stand;
	//StandAutoClose stand;
	StandNoMore2 stand;

	for (int i = 0; i < 20; i++)
	{
		int rand_value = rand() % 101;
		int curr_box = rand() % 3 + 1;

		if (rand_value <= 60)
		{
			cout << "Box open: " << curr_box << endl;
			stand.open_box(curr_box);
		}
		else
		{
			cout << "Box close: " << curr_box << endl;
			stand.close_box(curr_box);
		}
		
		cout << stand << endl;
	}
}

void f38()
{
	Bottle bott(10, 1);
	cout << bott << endl;

	bott.fill(5);
	cout << bott << endl;
	
	bott.fill(10);
	cout << bott << endl;

	bott.extract(3);
	cout << bott << endl;

	bott.extract(5);
	cout << bott << endl;

	bott.extract(5);
	cout << bott << endl;
}

void f39()
{
	Date d1{ 2020, 12, 15 };
	Date d2{ 2020, 11, 5 };

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}

void f40()
{
	Fractions::Fraction fr1 (2,3);
	Fractions::Fraction fr2 (5,6);

	cout << (fr1 + fr2) << endl;
	cout << (fr1 - fr2) << endl;
	cout << (fr1 * fr2) << endl;
	cout << (fr1 / fr2) << endl;
	cout << (fr1 < fr2) << endl;
	cout << (fr1 > fr2) << endl;
	cout << (fr1 == fr2) << endl;
	cout << (fr1 != fr2) << endl;
}

void f41()
{
	int arr[] = { 1,4,8,6,2,6,3,3,5,8,3,5,6 };
	quick_sort_raw_pointers(&arr[0], &arr[size(arr) - 1]);
	for (int a : arr)
	{
		cout << a << ' ';
	}
}

#pragma endregion

int main(int argc, char* argv[]) 
//первый аргумент - это то, сколько аргументов в функцию мы передали argc - arguments count
//второй аргумент - это массив указателей на строки, указатель на массив строк
{
	//Console.SetConsolePositionAndSize(10, 10, 900, 1400);

	srand(time(0));

	//std::cout << "Count of arguments: " << argc << std::endl;
	//
	//std::cout << "Arguments:" << std::endl;
	//
	//for (int i = 0; i < argc; ++i)
	//{
	//	std::cout << argv[i] << std::endl;
	//}
	//
	//if (std::string(argv[1]) == "0")
	//{
	//	std::cout << "Hello" << std::endl;
	//}
	//else
	//{
	//	std::cout << "World" << std::endl;
	//}
	//
	//return 0;
	
	//ServiceClasess::servf1(get_random_vector_max_range_size(10,10), get_random_vector_max_range_size(10, 10));
	//ServiceClasess::test_set_performance(30000, 100000, 1000000);
	//ServiceClasess::test_smart_set_performance(30000, 100000, 1000000);

	//f41();
	//compare_two_equal_lenght_strings_1();

	//DataStructures::QueueTesting4();
	//Sequences::PrintMostFrequent();
	//MapStdExamples::CountOfWords();
	//Set::Example1();
	//WorkWithTextFiles::TestPrintVectorFromFile();
	//WorkWithBinaryFiles::ExampleWrite2();
	//WorkWithBinaryFiles::ExampleRead1();
	//WorkWithBinaryFiles::TestSaveVectorToBinaryFile();

	//Practice_2021_02_27::test_8();
	//ContainerList::FindMiddle();
	//ContainerList1::Test5();
	//WorkWithTextFiles::ReadMapFromTextFile();

	//DataStructures::BinarySearchTreeMapTest();
	//DataStructures::BinarySearchTreeTest();
	//Practice_2021_02_27::Test9();
	//DataStructures::Test();
	
	//JsonTests::Test2();
	//Hash::Test();
	//ParallelThreads::Test3();
	//ParallelThreads::Test4();
	//ParallelThreads::Test5(2);
	//ParallelThreads::Test5(3);
	//ParallelThreads::Test5(4);
	//ParallelThreads::Test5(5);
	//ParallelThreads::Test7();

	//RingBufferTest::Test1_RingBufferContainer();
	//RingBufferTest::Test_Queue();

	//Inheritance::Test();
	//InheritanceRectAndSquare::Test();

	//HashTable::Test2();

	//Structures::Test678(); 

	//std::cout << SHA256FromGitHub("Andrey") << std::endl;

	//Polymorphism::Test1();

	//PointersAndReferences::Test5();

	//Polymorphism::Test3();

	//ChronoTime::Test2();
	// 
	//SimplePatternStrategy::Test1();
	
	//GameMatrix::Test();

	//проверка для сетевой функции клиент-сервер
	//if (std::string(argv[1]) == "0")
	//{
	//	Network::TestServerClass();
	//}
	//else
	//{
	//	Network::TestClientClass();
	//}
	////////////////////////////////////////////

	//HashTable::Test4OA();
	

	//Iterators::Test1();
	//Templates::Test3();
	//Templates::Test7();

	//Polymorphism::Test777();
	
	//VariadicTemplate::Test1();

	//MoveSemantics::Test3();
	//std::cout << "================" << std::endl;
	//MoveSemantics::Test4();
	//std::cout << "================" << std::endl;
	//MoveSemantics::Test5();

	//MoveSemantics::Test100();

	//PerfectForwarding::Test2();
	SmartPointers::TestSharedPointer();


	std::cout << "Process is over!" << std::endl;
	getchar(); //ожидание ввода с клавиатуры
}


/*Путь к успеху!
+ Массивы, переменные, условия, циклы
+ Сортировки - остался q_sort - на потом
+ Работа с указателями и памятью
+ Работа с динамической паматью
+ Рекурсии
+ Структуры (классы):
+ конструкторы 
+ методы
+ уровни доступа
+ операторы (кастомные операторы внутри класса)
(1-3 - инкапсуляция)
+- работа с CommonLanguageInterface, .net
+- работа с текстовыми файлами
+- работа с бинарными файлами
+- списки: односвязный, двухсвязный
Написать свои контейнеры:
+- очередь через массив
+ список
+ бинарное дерево
+ бинарное дерево поиска (ассоциативный массив), 
/////
+- граф
+- Наследование,полиморфизм
+ хэш-таблица Сделан метод цепочек. 
- Работа с сетью:
	- сделать игру (проект А)- на сервере игровое поле, игрок управляется из клиента
	- чат
	- биржа
+ хэш-таблица метод открытой адресации.
- вектор
- стринга
- стек, очередь через список
- написать MachineLearning
- красно-черное дерево и много других клевых структур!!
+- Многопоточность, параллельные вычисления
+- шаблоны

+- переменное число параметров в функции (реализуется через шаблон)
	
+ абстрактный класс - Класс, у которого есть чистая функция (=0), называется абстрактным
+ интерфейс - иногда это просто абстрактный класс или класс, у которого все функции чистые

++ rvalue lvalue
++ move-семантика
++ умные указатели
++ идеальная передача

- таблица виртуальных методов и функций
- виртуальный деструктор
- виртуальный конструктор
- виртуальное наследование

- как умножить разделить на два битовыми операциями - маска?

- mutable mutex симафор

Важное про структурирование данных:
Если неважна отсортированность: 
- если элементов много, то используем хэш-таблицу (std::unordered_map, std:: unordered_set)
- если элементов мало, то отсортированный массив
- если элементов мало, дисперсия малая, известна нижняя граница, то использовать массив, где ключом является нижний элемент - маска
Если важна отсортированность элементов, то:
- если элементов много - то дерево (std::map, std::set),
- если мало - отсортированный массив.
Если нужна отсортированность - мапа, если не нужна - хэш-таблица, а если элементов мало - массив.
*/

//https://github.com/AlexKoffMSK/CppProject.git
//git@github.com:AlexKoffMSK/CppProject.git

//ReSharper C++