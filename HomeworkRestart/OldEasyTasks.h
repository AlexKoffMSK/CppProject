#pragma once
#include <iostream>

namespace OldEasyTasks
{
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
				cout << a << endl; //����������� �������, ��� a>b � a>=c
			}
			else
			{
				cout << c << endl; //����������� �������, ��� a>b � c>=a
			}
		}
		else //����������� �������, ��� b>=a
		{
			if (b > c)
			{
				cout << b << endl; //����������� �������, ��� a>b � a>=c
			}
			else
			{
				cout << c << endl; //����������� �������, ��� a>b � c>=a
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
			cout << a << endl; //����������� �������, ��� a>b � b>c
		}
		else // a<=b || b<=c.   !(d && e) = !d || !e
			if (f == true && g == true)
			{
				// (!d || !e) && (f && g)
				cout << c << endl; // ����������� �������, ��� c>a � c>b
			}
			else //��������� 67 ������ - a>=c || b>=c. !(f && g) = !f || !g
			{
				// ����� ��� �����, ����� ������ ����: (!d || !e) && (!f || !g)

				// ��� ��������� �������� ������������ ���
				// (!d || !e) && (!f || !g) =
				// ((!f || !g) && !f) || ((!f || !g) && !g) = 
				// (!f && !f || !g && !f) || (!f && !g || !g && !g) = 
				// (!f || !g && !f) || (!f && !g || !g) =
				// !f || !g = 
				// (c <= a) || (c <= b) - �� ����� �������, ��� c - �� ����� �������, � ������ - ����� ������� ���� �, ���� b

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
		else //a<=b || a<=c - ����������� ��� � �� ����� ������� � ����� ���� ������ � b, � c
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
				//a>=b c<=a, � - ����� �������
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
		// ������� �� �����������

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
		//���� ��� �����, ������� �� � ������� �����������. ��� ����� ������.
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
		//����������� ����������
		//4 2 1
		//a b c
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b)
		{
			swap(a, b); //swap ������ �������� � ����������
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

	void f10() //�������� ������, �������� ����� � �����
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
			if (arr[i] % 2 != 0 && arr[i] != 0)
			{
				cout << arr[i] << " - ��������" << endl;
				odd_counter++;
			}
			if (arr[i] % 2 == 0 && arr[i] != 0)
			{
				cout << arr[i] << " - ������" << endl;
				even_counter++;
			}
			if (arr[i] == 0)
			{
				cout << arr[i] << " - ����" << endl;
				zero_counter++;
			}
		}
		cout << "���������� �������� �����: " << odd_counter << endl;
		cout << "���������� ������ �����: " << even_counter << endl;
		cout << "���������� �����: " << zero_counter << endl;
	}

	void f11() //���� ������
	{
		int offset = 2; //����� �� ��������

		char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; //������ ������ ����
		cout << "enter 1 word only: ";
		string user_input; //������ ������ ��� ����� ������������� �����
		cin >> user_input; //���������� ������
		//int word_lenght = size(user_input); //user_input.size()
		int const word_lenght_limit = 140; //������ ��������� ��� ���������� ����� ����������������� ����� ��� ������� ������� ����
		char users_word_arr[word_lenght_limit] = { 0 }; //������ ������ ������ ���� ����� ����� ���� ��������� ��������� ����� �� �������

		//vector<char> temp_vector; //������ ������ ������, � ������� ���� ���� size

		for (int i = 0; i < user_input.size(); i++) //�������� ����, ����� ��������� ������ "����������������� �����" �� ������ �����
		{
			users_word_arr[i] = user_input[i];
			//temp_vector.push_back(user_input[i]); //�� ������ �������� ����������� � ����� �������, ���������� ��� ������.
		}

		//string temp_string = user_input; ��� ��� ������ ��� ���� ������ (������ �����), � ���� ����� ���������� �� ������

		int current_user_string_position = 0; //������ ������� ��� �������� ��������� �� ����� � ����� � �������

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
	} //�� �������� � ��������� ������

	void f12()
	{
		char a = 'z';
		char b = 4;
		char c = a - 2;
		cout << a + 0 << ' ' << int(a) << ' ' << char(a - 2) << ' ' << c << endl;
		cout << int('a') << ' ' << int('b') << ' ' << int('c') << endl;
		cout << int('z' - 'a' + 1) << endl;
		//input char - print its ASCII code
		cin >> a;
		cout << int(a) << endl;
		//������� ����� ��� ����� �� �������� - � �����
		cout << int(a - 'a') << endl;
	}

	void f13()
	{
		int offset = 2;
		string user_input;
		cin >> user_input;

		for (int i = 0; i < user_input.size(); i++)
		{
			cout << user_input[i] << ' ' << int(user_input[i]) << ' ' << user_input[i] + offset << ' ' << char(user_input[i] + offset) << ' ';
			cout << char(((user_input[i] + offset) - 'a') % ('z' - 'a' + 1) + 'a') << endl;
		}
	}

	void f14()
	{
		//������� ������ ��� �����, ������� - ���, �����, ���� � �������� �������
		//�� ���� ������� 31 ����, ������� �������, 12 �������. ������� ��������� ���� - ���, �����, ����
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
		//������ ��� ����� a b c. ax^2 + bx + c = 0. ������� �������� x, ������ ������������. b^2 - 4ac
		int a, b, c;
		cin >> a >> b >> c;

		int d = b * b - 4 * a * c;

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
		//��� �����, ������� true ���� �����-�� �� ���� ����� �������� ������������� ���� ������, false - ���� �� ��������
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
		//������� ���� �������
		for (int i = 0; i <= 255; i++)
		{
			cout << i << ' ' << char(i) << endl;
		}
	}

	void f18()
	{
		//������ ������, �����, ����������. ������� = ��� ������� ��� ���������.
		//������� ��� ���� ��������� ����� ���������
		//���� ����� ��������� - ������� small, ������� - large, ���� - undefined
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
		//������ ������ ��� ���� ��� ������� ���������, ������� �� ����� �� �� �� �� �������.
		string user_input;
		cin >> user_input;

		//for (int i = 0; i <= user_input.size(); i++) //������ �� �������� ������
		//{
		//	//cout << user_input[i] << endl;
		//}
		for (char c : user_input) //������ �� ����� �������� � ������
		{
			//cout << c << endl; //c - ��� ��� ������
			int offset_in_alphabet = (c - 'a');
			cout << char('A' + offset_in_alphabet);
		}
	}

	void f20()
	{
		//������� ������ ��� ������, ������� �� ����� ��� ���� ��� ����������
		string a, b;
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
		//������� ������ ��� ������ � ������, ������� �� ����� ��� ���� � ������ ���� ������
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
		//������� ������ ��� ������ � �����. ������� ��� ���� � �����.��� ������ ������ ���������� ������ ������ ������
		// abcde cd 2 - true
		// abcde cd 3 - false
		// abcde de 3 - true
		// abcde de 2 - false
		// abcde cdo 2 - false

		string a, b;
		cin >> a >> b;

		int start_pos;
		cin >> start_pos;

		cout << is_second_string_in_first(a, b, start_pos) << endl;
	}

	void f23()
	{
		//������� ������ ��� ������, ������ ������ ������ ������. ������� ��� ���� ������ ������ ���������� � ������
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
		//������� ������, ����������� ���������� �������. ���������� ����� - ���� �� ��������
		int a = 30;

		vector<int> dyn_arr; //������� ������ ������, � ���� ���� ������� size � ��� 0 ���� ���

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

		cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[size(raw_arr) / 2], &raw_arr[size(raw_arr) - 1]) << endl;

		cout << *Pointers::find_max_elem_in_segment_and_return_pointer(&raw_arr[0], &raw_arr[size(raw_arr) - 1]) << endl;

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
		Fractions::Fraction fr4(rand() % 20 + 1, rand() % 10 + 1);
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
		//������� ������ �������� ��������� ����� � ���������� ������

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
		//------------������ ������� - ������� ������������� ��� �����
		Geometry::Rectangle r1;
		vector<Geometry::Rectangle> rectangles_vector;
		for (int i = 0; i < 10; i++)
		{
			r1.height = rand() % 3 + 1;
			r1.width = rand() % 3 + 1;
			rectangles_vector.push_back(r1);
			cout << r1 << endl; //������� �� ����� ��� ��������������
		}

		/*
		//------------������ ������� - ������� ������������� ������ �����
		vector<Geometry::Rectangle> rectangles_vector;
		for (int i = 0; i < 10; i++)
		{
			Geometry::Rectangle r1(rand() % 3 + 1, rand() % 3 + 1);
			rectangles_vector.push_back(r1);
			cout << r1 << endl;
		}

		//------------������ ������� - �� ��������� ������������� ������
		vector<Geometry::Rectangle> rectangles_vector;
		for (int i = 0; i < 10; i++)
		{
			rectangles_vector.push_back(Geometry::Rectangle(rand() % 3 + 1, rand() % 3 + 1));
			cout << rectangles_vector[i] << endl;
		}
		*/

		cout << " --- " << endl;

		for (Geometry::Rectangle r : rectangles_vector) //������� �� ����� ��� ��������������
		{
			cout << r << endl;
		}

		cout << " --- " << endl;

		for (Geometry::Rectangle r : rectangles_vector) //������� �� ����� ��� �������������� ���� ��� ��������
		{
			if (r.is_rectangle_square())
			{
				cout << r << endl;
			}
		}

		cout << " --- " << endl;

		for (Geometry::Rectangle r : rectangles_vector) //������� �� ����� ��� �������������� � �������� ������ 4
		{
			if (r.area_of_rectangle() > 4)
			{
				cout << r << endl;
			}
		}

		cout << " --- " << endl;

		int summ_of_per = 0;
		for (Geometry::Rectangle r : rectangles_vector) //��������� ����� ���������� ���� ���������������
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
		Fractions::Fraction fr1(2, 3);
		Fractions::Fraction fr2(5, 6);

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

}
#pragma endregion