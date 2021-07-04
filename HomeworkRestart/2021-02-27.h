#pragma once
#include <iostream>
#include <vector>

namespace Practice_2021_02_27
{
	class Product
	{
		std::string name;
		int time_from_birth;
		
		//==============конструкторы=========
	public:
		Product(std::string name_)
		{
			name = name_;
			time_from_birth = 0;
		}
		
		//==============методы=========
		std::string get_name()
		{
			return name;
		}
		int get_time_from_birth()
		{
			return time_from_birth;
		}
		void increase_time_from_birth()
		{
			time_from_birth++;
		}

		friend ostream& operator<<(ostream& os, Product p)
		{
			os << p.name << ' ' << p.time_from_birth;
			return os;
		}
	};

	void test_prod()
	{
		Product p1("Prod1");
		Product p2("Prod2");

		std::cout << p1 << endl;
		std::cout << p2 << endl;

		p1.increase_time_from_birth();
		p1.increase_time_from_birth();

		std::cout << p1 << endl;
		std::cout << p2 << endl;
	}

	void test_prod2()
	{
		vector<Product> products;
		for (int i = 0; i < 20; i++)
		{
			//Product p(get_random_english_string(4));
			products.push_back(Product(get_random_english_string(4)));
		}
		print_vector_with_endl(products);
		
		for (int i = 0; i < 30; i++) //рандомному объекту увеличиваем время жизни
		{
			int tmp_rnd = rand() % products.size();
			products[tmp_rnd].increase_time_from_birth();
		}
		print_vector_with_endl(products);
	}

	void test_3()
	{
		int a = 3;
		int b = 4;

		int* p_a = &a;
		int* p_b = &b;

		cout << *p_a << ' ' << p_a << endl;

		if (p_a < p_b)
		{
			cout << 4 << endl;
		}
	}

	void test_4()
	{
		const int n = 10;
		int arr[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 10;
		}

		int* ptr = &arr[0];
		int* ptr_end = &arr[n-1];

		while (ptr <= ptr_end)
		{
			cout << *ptr << ' ';
			ptr++;
		}

		cout << endl;

		ptr = &arr[0];

		while ( (ptr - &arr[0]) < std::size(arr) )
		{
			cout << *ptr << ' ';
			ptr++;
		}


	}

	void test_6()
	{
		char c=99;
		char* p_a = &c;
		
		for (int i = -20; i < 20; i++)
		{
			cout << (int)(*(p_a + i)) << endl;
		}
		
	}

	void test_5()
	{
		int a = 33;
		int b = 44;
		test_6();
		cout << &a << ' ' << &b << endl;
	}

	void test_7()
	{
		int arr[10]; //создали статический массив, размер которого известен на стадии компиляции
		
		int n; 
		cin >> n;
		int* n_arr = new int[n]; 
		//new int[n] - попросить у операционной системы выделить нам число n интов
		//создаст и вернет нам указатель на начало массива, который мы записываем в переменную n_arr, 
		//который сам яавляется указателем на начало массива
		
		delete[] n_arr; //освобождаем, возвращаем системе память, удаляем массив.
	}

	void test_8()
	{
		int* a = new int[1];
		int* b = new int;

		delete[] a;
		delete b;

		Product* prod = new Product ("product1"); 
		//просим у операционной системе динамическую память для одного продукта и храним его в указателе prod

		cout << prod->get_name() << endl;
		cout << (*prod).get_name() << endl;
		cout << *prod << endl;

	}

	struct TestNode
	{
		int a = 0;
		TestNode* p = nullptr;

	};

	void Test9()
	{
		TestNode b;
		b.a = 3;
		b.p = &b;

		TestNode* bb = new TestNode;
		bb->a = 4;
		bb->p = &b;

		vector<TestNode*> c;
		c.push_back(&b);
		
		c.push_back(new TestNode);
		c.back()->a = 5;
		c.back()->p = c[c.size() - 1 - 1];

		c.push_back(new TestNode);
		c.back()->a = 6;
		c.back()->p = c[c.size() - 1 - 1];

		c.push_back(new TestNode);
		c.back()->a = 7;
		c.back()->p = c[c.size() - 1 - 1];

		c.push_back(bb);

		for (TestNode* q : c)
		{
			cout << q->a << ',' << q->p->a << endl;
		}
	}















}