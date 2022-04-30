#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

namespace StlVector
{
	void push_back()
	{
		std::vector<int> vec;
		vec.push_back(5);
		std::cout << vec[0] << std::endl;

		vec.push_back(3);
		std::cout << vec[0] << ' ' << vec[1] << std::endl;
		assert(vec[0] == 5);
		assert(vec[1] == 3);

		vec.push_back(6);
		assert(vec[0] == 5);
		assert(vec[1] == 3);
		assert(vec[2] == 6);

		assert(vec.front() == 5);
		assert(vec.back() == 6);
	}

	void front_back()
	{
		std::vector<int> vec = { 5,2,3,1,9 };

		assert(vec.front() == 5);
		vec.front() = 10;
		assert(vec.front() == 10);

		assert(vec.back() == 9);
		vec.back() = 18;
		assert(vec.back() == 18);
	}

	void VectorOfStrings()
	{
		std::vector<std::string> vec;
		vec.push_back("asd");
		vec.push_back("sda");
		vec.push_back("das");

		assert(vec.front() == "asd");
		assert(vec[1] == "sda");
		assert(vec.back() == "das");

		vec.back()[1] = '!';

		std::string str = "ddd";
		str[0] = 'f';

		std::string& str1 = vec.back();
		str1[2] = '?';
		
		assert(vec.back() == "d!?");
		5; //��� ��� int. ���� �������� auto a = 5, �� a ����� ����� ��� int
		5u;//unsigned int
		5l;//long
		5.; //double
		5.f;//float
		'5';//char
		"abs";//const char* - ������, ��������, ������� ������ ��������
		"abs"s;//string
	}

	void IterateOfAllElementsForAutoLoop()
	{
		std::vector<int> vec = { 5,3,7,3,4,7,3 };

		int i = 0;
		for (int a : vec)
		{
			assert(vec[i] == a);
			std::cout << a << std::endl;
			i++;
		}

		for (int& a : vec)
		{
			a++;
		}

		std::vector<int> vector_for_test = { 6,4,8,4,5,8,4 };

		for (int j =0; j<vec.size(); j++)
		{
			assert(vec[j] == vector_for_test[j]);
		}

	}

	//clear
	//emplace_back
	//pop_back
	//resize
	//reserve (*)
	//capacity (*)
	//������������ ����� ���������
	//insert & emplace
	//erase
	
	void clear()
	{
		std::vector<int> vec = { 5,3,7,3,4,7,3 };
		assert(vec.size() == 7);
		assert(!vec.empty());
		vec.clear();
		assert(vec.size() == 0);
		assert(vec.empty());
	}

	struct TestStruct
	{
		int _a;
		double _b;
		float f;

		TestStruct(int x_, double y_)
		{
			_a = x_;
			_b = y_;
		}
	};

	void emplace_back()
	{
		std::vector<TestStruct> vec;

		TestStruct ts(4, 6.8);
		vec.push_back(ts);

		vec.push_back(TestStruct{ 7,9.2 });// �������� ������ ��������� ��������� ���������� ������������� ����� ������� ������ ��� �������, ��� ���� ������� � ���������� �� ������� ������������
		vec.push_back(TestStruct( 7,9.2 ));// ������� ������ ������ �� �� ����� �� ������ ��� ������� ������� ������������

		vec.emplace_back(ts);
		vec.emplace_back(5, 8.2); //�� ����� �������� ���� ��� ������������
		vec.emplace_back(TestStruct{ 3,1.29 }); //����� �������� ���� ��� ������������
		vec.emplace_back(TestStruct( 2,44.2)); //������� ������ ����� ����������, �.�. ��������� ������� ������������
	}

	void pop_back()
	{
		std::vector<int> vec = { 4,5,6 };
		assert(vec.size() == 3);
		assert(vec.back() == 6);
		
		vec.pop_back();
		assert(vec.size() == 2);
		assert(vec.back() == 5);
		
		vec.pop_back();
		assert(vec.size() == 1);
		assert(vec.back() == 4);
		
		vec.pop_back();
		assert(vec.empty());

		//vec.pop_back();
	}

	void resize()
	{
		std::vector<int> vec;
		assert(vec.size() == 0);

		vec.resize(10);
		assert(vec.size() == 10);
		for (int a : vec)
		{
			assert(a == 0);
			//std::cout << a << std::endl;
		}

		vec.clear();

		vec.resize(20, 5);
		for (int a : vec)
		{
			assert(a == 5);
			//std::cout << a << std::endl;
		}

		assert(vec.size() == 20);

		vec.resize(10); //�������� ��������� 10 ���������
		assert(vec.size() == 10);

		vec.resize(20);
		assert(vec.size() == 20);

		for (int i = 0; i < 10; ++i)
		{
			assert(vec[i] == 5);
			assert(vec[i+10] == 0);
		}

		vec.resize(30, 7);
		for (int i = 0; i < 10; ++i)
		{
			assert(vec[i] == 5);
			assert(vec[i + 10] == 0);
			assert(vec[i + 20] == 7);
		}
	}

	void IteratorsIterate()
	{
		std::vector<int> vec = { 5,7,5,3,7,4,3 };

		//for (           int i =0;  i < vec.size(); ++i)
		int i = 0;
		for (auto it = vec.begin(); it != vec.end(); ++it) //vec.end() - ��� ��������, ������� �� ������� �� �� ���� ������� ����������
		{
			assert(*it == vec[i]);
			std::cout << *it << std::endl;
			i++;
		}
		i--;
		for (auto reverse_it = vec.rbegin(); reverse_it != vec.rend(); ++reverse_it)
		{
			assert(*reverse_it == vec[i]);
			std::cout << *reverse_it << std::endl;
			i--;
		}
	}

	void IteratorsExample1()
	{
		std::vector<int> vec = { 5,7,89,3,4,5};
		std::vector<int>::iterator it = vec.begin(); //begin() ���������� ��������! � end() ����.
		assert(*it == 5);

		it++;
		assert(*it == 7);

		it--;
		assert(*it == 5);

		it+=3;
		assert(*it == 3);

		it++;
		assert(*it == 4);

		it++;
		assert(*it == 5);

		it++;
		assert(it == vec.end());
	}

	void IteratorsExample2()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		std::vector<int>::iterator it = vec.begin(); //begin() ���������� ��������! � end() ����.

		assert(*(it + 2) == 89);
		assert(it == vec.begin());
		
		it += 4;

		assert(*(it - 1) == 3);

		it = vec.begin();
		assert(it[0] == 5);
		assert(it[1] == 7);
		assert(it[2] == 89); //������ ������� ������ assert(*(it + 2) == 89) - ���������� �� 2 �� ������� ������� ��������� � ������������
		
		it = vec.begin();
		it++;
		assert(it[0] == 7);
		assert(it[1] == 89);
		//������� ����� it[1] � vec[1] � ���, ��� vec[1] ������� �� 1 ������� �������, � it[1] ������� �� ��������� ������� �� �������� �������� ���������
		
		assert(vec.begin()[1] == 7);
	}

	void insert()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		std::vector<int>::iterator it = vec.begin(); //begin() ���������� ��������! � end() ����.

		assert(vec[3] == 3);
		vec.insert(it + 3, 8); //insert ��������� �������� �� ������� ����������, ����� ������� ���������� �������� ��� ���� �������
		assert(vec[3] == 8);
		assert(vec[4] == 3);

		vec = { 5,7,89,3,4,5 };
		vec.insert(vec.begin() + 3, 8);
	}

	void emplace()
	{
		std::vector<TestStruct> vec;
		vec.emplace_back(4, 5); //���������� insert ��������� ����� ��������� ������ �������
		vec.emplace_back(5, 5);
		vec.emplace_back(6, 5);
		vec.emplace(vec.begin() + 1, 7, 5);
		assert(vec[1]._a == 7 && vec[1]._b == 5);
	}

	void erase()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		assert(vec[2] == 89);
		vec.erase(vec.begin() + 2); //������� ������� �� �������, ��������� ��������� �� ��� �������, ������� ���� �������
		assert(vec[2] == 3);
		assert(vec.size() == 5);

		vec = { 5,7,89,3,4,5 };
		vec.erase(vec.begin() + 1, vec.begin() + vec.size() - 1);
		assert(vec.size() == 2 && vec[0] == 5 && vec[1] == 5);
	}

	void assign()
	{
		std::vector<int> vec;
		vec.assign(10, 5);
		for (int c : vec)
		{
			assert(c == 5);
		}
		assert(vec.size() == 10);

		//vec.resize(2,7) �������� ������ ������� �� 2, 7 �� ����� ���������, �.�. 7 ���� �� ������ ��� ����� ���������, �.�. ���� �� vec.resize(12,7)

		vec.assign(2, 7); // �������� ������ ������� �� 2 � ������ ��� �������� ����� ���������� 7
		for (auto c : vec)
		{
			assert(c == 7);
		}
		assert(vec.size() == 2);
		
		//vec.resize(5, 3); //7 7 3 3 3
		vec.assign(5, 3); //3 3 3 3 3
		for (auto c : vec)
		{
			assert(c == 3);
		}
		assert(vec.size() == 5);
	}

	void at()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		//vec[10] = 8;
		vec.at(2) = 8; //����������� �� �������� �������. ������� � vec[x] � ���, ��� � ������ ������ �� ������� �������, �� ��� at ����� �������� ����������, � ����� [] ����� UB ��� segfault ���� �������
	}
	
	void back_front()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		vec.back() = 8; //back ���������� ��������� ������� � �������. ���� ������ ������ � �������� back - ����� UB
		std::cout << vec.front() << std::endl; //front ���������� ������ ������� � �������

		std::vector<std::string> vecstr = { "Hello", "World" };
		vecstr.front()[4] = '!';
		vecstr.back()[4] = '?';
		assert(vecstr[0][4] == '!');
		assert(vecstr[0] == "Hell!");
		assert(vecstr[1][4] == '?');
		assert(vecstr[1] == "Worl?");
	}

	void TestGetters()
	{
		std::vector<std::string> vecstr = { "Hello", "World" };
		vecstr[0][4] = '!';
		vecstr.at(0).at(4) = '!';
		vecstr[0].at(4) = '!';
		vecstr.at(0)[4] = '!';

		vecstr.front()[4] = '!';
		(*(vecstr.begin()))[4] = '!';
		vecstr.begin()[0][4] = '!';
	}

	void swap()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		std::vector<int> vec1 = { 87,4,6,3,6,3,7,8,6,5,3,3 };
		vec.swap(vec1); //���� ������ ������� ��� �������, ���������� ������ ��������� �� ������� ����� �����
	}

	void STD_sort()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		std::sort(vec.begin(), vec.end()); //quickSort ����� �������
		std::vector<int> sorted_vec = {3,4,5,5,7,89 };
		for (int i=0; i < vec.size(); ++i)
		{
			assert(vec[i] == sorted_vec[i]);
		}
	}

	void STD_sort1()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		std::sort(vec.begin()+1, vec.begin()+vec.size()-1); //quickSort ��������� ������ �������
		std::vector<int> sorted_vec = { 5,3,4,7,89,5 };
		for (int i = 0; i < vec.size(); ++i)
		{
			assert(vec[i] == sorted_vec[i]);
		}
	}

	void STD_find()
	{
		std::vector<int> vec = { 5,7,89,3,4,5 };
		auto it = std::find(vec.begin(), vec.end(), 89); //���������� �������� �� ��������� ������� � �� end ���� ������� �� ������
		assert(*it == 89);
		it = std::find(vec.begin(), vec.end(), 10); //���������� �������� �� ��������� ������� � �� end ���� ������� �� ������
		assert(it == vec.end());
		it = std::find(vec.begin(), vec.end(), 5); //���������� �������� �� ��������� ������� � �� end ���� ������� �� ������
		assert(it == vec.begin());
	}

	//��� ������ �����, ����� � ��� ������ 4 � ������ 9 � ���������� ����� �������, � ������������� � ������� ���, ��� ����� ���� ������� �� �����
	void Test1()
	{
		std::vector<int> vec = { 5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };
		auto it_f = std::find(vec.begin(), vec.end(), 4);
		auto it_l = std::find(it_f, vec.end(), 9);
		std::sort(it_f, (it_l == vec.end()) ? it_l : it_l+1);
		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	//��� ������ �����, ����� � ��� ������ 4 � ������ 9 � ���������� ����� �������, � ������������� � ������� ���, ��� ����� ���� �������� �� �����
	void Test2()
	{
		std::vector<int> vec = { 5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };
		auto it_f = std::find(vec.begin(), vec.end(), 4);
		auto it_l = std::find(it_f, vec.end(), 9);
		
		std::sort(it_f+1, it_l);
		
		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	//��� ������ �����, ������� �� ���� ������ 4
	void Test3()
	{
		std::vector<int> vec = { 5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };

		auto it = std::find(vec.begin(), vec.end(), 4);
		vec.erase(it);
		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	//��� ������ �����, ������� �� ���� ��� 4
	void Test4()
	{
		std::vector<int> vec = { 4,5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };

		//for (auto it = vec.begin(); it != vec.end(); ++it)
		while(true)
		{
			auto it1 = std::find(vec.begin(), vec.end(), 4);
			
			if (it1 == vec.end())
			{
				break;
			}
			vec.erase(it1);
			//Invalidates iterators and references at or after the point of the erase, including the end() iterator.
			for (auto c : vec)
			{
				std::cout << c << ' ';
			}
			std::cout << std::endl;
		}
	}

	void STD_partition()
	{
		std::vector<int> vec = { 4,5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };
		std::partition(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; }); 
		//���������� �������� ����� �������, ��� ������� ���� �� ��������, ������� ������������� �������. 
		//��� ����, ������� �������������� ��������� ����� ���������� �� ���������
		//���������� �������� �� ������ ������ ����
		
		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	void STD_stable_partition()
	{
		std::vector<int> vec = { 4,5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };
		std::stable_partition(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; });
		//�� ��, ��� � partition, �� ������� �������������� ��������� ����������� �� ��������� � ���������

		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	void Test5()
	{
		std::vector<int> vec = {4,5,7,89,999,4,5,6,3,8,7,145,5,3,4,4,9,1,99,44,342,9,33,11 };
		auto it1 = std::stable_partition(vec.begin(), vec.end(), [](int x) {return x != 4; });
		vec.erase(it1, vec.end()); //end ��� ��� ������ ������� �� ���������� � ��������� ��������
		for (auto c : vec)
		{
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	void STD_accumulate()
	{
		std::vector<int> vec = { 1,2,3,4,5 };
		std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
	}

	void Test6()
	{
		std::vector<int> vec = {1,2,3,4,5};
		auto it = vec.end();
		int a = 0;
		it--;
		//std::cout << *it << std::endl;

		for (auto it = vec.begin(); it!=vec.end()-1; it++)
		{
			std::cout << *it << std::endl;
		}

		std::set<int> st = { 1,2,3,4,5 };
		
		auto r_it = st.rbegin();
		r_it++;
		
		for (auto it = st.begin(); it != r_it.base(); it++)
		{
			std::cout << *it << std::endl;
		}
	}

	void CheckAll()
	{
		push_back();
		front_back();
		VectorOfStrings();
		IterateOfAllElementsForAutoLoop();
		emplace_back();
		pop_back();
		resize();
		IteratorsIterate();
		IteratorsExample1();
		insert();
		emplace();
		erase();
		assign();
		at();
		back_front();
		TestGetters();
		swap();
		STD_sort();
		STD_sort1();
		STD_find();
		Test1();
		Test2();
		Test3();
		Test4();
		STD_partition();
		STD_stable_partition();
		Test5();
	}

}