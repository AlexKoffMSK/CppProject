#pragma once
#include <iostream>
#include <bitset>
#include <cassert>

namespace STLBitSet
{

	void operator_squares()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		for (int i = 0; i < 5; i++)
		{
			std::cout << bs[i] << ' ';
		}

		std::cout << std::endl;

		bs[0] = 1;
		bs[1] = true;

		for (int i = 0; i < 5; i++)
		{
			std::cout << bs[i] << ' ';
		}

	}

	void operator_equal()
	{
		std::bitset<7> bs1{ 0b11100 }; //���������� bitset ���� ������ ������
		std::bitset<7> bs2{ 0b11100 };
		std::bitset<7> bs3{ 0b0011100 };
		std::bitset<7> bs4{ 0b1110 };

		assert(bs1 == bs2);

		assert(bs2 == bs3);

		assert(bs2 != bs4);
	}

	void test() //������ ���������� ������
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		assert(bs.test(3) == 1);
		assert(bs.test(0) == 0);
		assert(bs.test(6) == 0);
	}

	void all_any_none()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs1{ 0b00000 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs2{ 0b11111 }; //���������� bitset ���� ������ ������

		//all ���������� true ���� � ����� ��� �������
		//any ���������� true ���� ���� �� ���� �� ����� ����� �������
		//none ���������� true ���� �� ���� �� ����� �� ����� �������, ��� ����� ����

		assert(!bs.all());
		assert(!bs1.all());
		assert(bs2.all());

		assert(bs.any());
		assert(!bs1.any());
		assert(bs2.any());

		assert(!bs.none());
		assert(bs1.none());
		assert(!bs2.none());
	}

	void count()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		assert(bs.count() == 3); //count ������� ���������� ������
	}

	void size()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		assert(bs.size() == 5);
	}

	void bit_AND()
	{
		std::bitset<5> bs1{ 0b11010 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs2{ 0b01110 }; //���������� bitset ���� ������ ������

		std::bitset<5> bs3{ 0b01010 }; //���������� bitset ���� ������ ������

		assert((bs1 & bs2) == bs3);
	}

	void bit_OR()
	{
		std::bitset<5> bs1{ 0b11010 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs2{ 0b01110 }; //���������� bitset ���� ������ ������

		std::bitset<5> bs3{ 0b11110 }; //���������� bitset ���� ������ ������

		assert((bs1 | bs2) == bs3);
	}

	void bit_XOR()
	{
		std::bitset<5> bs1{ 0b11010 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs2{ 0b01110 }; //���������� bitset ���� ������ ������
		std::bitset<5> bs3{ 0b10100 }; //���������� bitset ���� ������ ������

		assert((bs1 ^ bs2) == bs3);
	}

	void bit_NONE()
	{
		std::bitset<6> bs1{ 0b011010 }; //���������� bitset ���� ������ ������
		std::bitset<6> bs2{ 0b100101 }; //���������� bitset ���� ������ ������

		assert(~bs1 == bs2);
	}

	void bit_all_in_one()
	{
		std::bitset<6> bs1{ 0b11010 }; //���������� bitset ���� ������ ������
		std::bitset<6> bs2{ 0b10101 }; //���������� bitset ���� ������ ������

		bs1 &= bs2;
		assert(bs1 == 0b10000);

		//����� ��� ����������� bs1 
		bs1 |= bs2;
		assert(bs1 == 0b10101);

		//����� ��� ����������� bs1 
		bs1 ^= bs2;
		assert(bs1 == 0b00000);
	}

	void bit_move()
	{
		std::bitset<6> bs1{ 0b011010 }; //���������� bitset ���� ������ ������

		assert(bs1 >> 1 == 0b001101);

		//std::cout << (std::bitset<4> {0b0110} << 1) << std::endl;
		//std::cout << (std::bitset<4> {0b1110} << 1) << std::endl;
		//std::cout << (std::bitset<4> {0b0111} << 1) << std::endl;

		//�������� >> �� ������ bs1, ������� ����� ����������� bs1
		assert(bs1 << 1 == 0b110100); //��� ��� ������ 6, �� �� ����� ���� bs1 = 0b011010, ������� ������� ���� 110100, � �� 0b10100

		bs1 >>= 1;
		assert(bs1 == 0b001101);

		//����� ��� ����������� bs1 
		bs1 <<= 1;
		assert(bs1 == 0b011010);
	}

	std::vector<std::string> vec_str{ "kIsHaveElectricity", "kIsHaveWater", "kIsHaveOil", "kIsHaveGas", "kIsFanWorks" };

	void PrintSystemThatDoesntWork(std::string str, std::bitset<5> systems_state)
	{
		for (int i = 0; i < systems_state.size(); ++i)
		{
			if (systems_state[i] == false) //��� false
			{
				std::cout << str << "	Not " << vec_str[i] << std::endl;
			}
		}
	}

	void f_0()
	{
		const int kIsHaveElectricity = 0;
		const int kIsHaveWater = 1;
		const int kIsHaveOil = 2;
		const int kIsHaveGas = 3;
		const int kIsFanWorks = 4;


		std::bitset<5> systems_state0{ 0b11111 };
		std::bitset<5> systems_state1{ 0b11111 };

		int n = 0;

		//1 ��� ��������
		//2 ���-�� �� ��������
		//3 ������ �� ��������

		while (n < 20)
		{
			std::bitset<5>& systems_state = (rand() % 2 == 0) ? systems_state0 : systems_state1;

			//if (systems_state.all())
			//{
			//	std::cout << "All works" << std::endl;
			//}
			//else if (systems_state.none())
			//{
			//	std::cout << "All doesn't work" << std::endl;
			//}
			//else
			//{
			//	std::cout << "Something doesn't work" << std::endl;
			//
			//  PrintSystemThatDoesntWork(systems_state)
			//}

			std::cout << "0: " << systems_state0 << std::endl;
			std::cout << "1: " << systems_state1 << std::endl;

			PrintSystemThatDoesntWork("", systems_state0 & systems_state1);
			//PrintSystemThatDoesntWork(systems_state0 | systems_state1);

			int rand_system = rand() % systems_state.size();
			int rand_condition = rand() % 2;

			systems_state[rand_system] = rand_condition;

			std::cout << "====================================================================" << std::endl;

			n++;
		}
	}

	void f_1()
	{
		const int kIsHaveElectricity = 0;
		const int kIsHaveWater = 1;
		const int kIsHaveOil = 2;
		const int kIsHaveGas = 3;
		const int kIsFanWorks = 4;


		std::bitset<5> systems_state{ 0b11111 };
		std::bitset<5> not_important_systems{ 0b01010 };

		int n = 0;

		//1 ��� ��������
		//2 ���-�� �� ��������
		//3 ������ �� ��������

		while (n < 20)
		{
			std::cout << systems_state << std::endl;

			PrintSystemThatDoesntWork("", systems_state | not_important_systems);

			int rand_system = rand() % systems_state.size();
			int rand_condition = rand() % 2;

			systems_state[rand_system] = rand_condition;

			std::cout << "====================================================================" << std::endl;

			n++;
		}
	}

	void f()
	{
		const int kIsHaveElectricity = 0;
		const int kIsHaveWater = 1;
		const int kIsHaveOil = 2;
		const int kIsHaveGas = 3;
		const int kIsFanWorks = 4;


		std::bitset<5> systems_state0{ 0b11111 };
		std::bitset<5> systems_state1{ 0b11111 };

		int n = 0;

		//1 ��� ��������
		//2 ���-�� �� ��������
		//3 ������ �� ��������

		while (n < 20)
		{
			std::bitset<5>& systems_state = (rand() % 2 == 0) ? systems_state0 : systems_state1;

			std::cout << "0: " << systems_state0 << std::endl;
			std::cout << "1: " << systems_state1 << std::endl;

			PrintSystemThatDoesntWork("0", systems_state0);
			PrintSystemThatDoesntWork("1", systems_state1 | ~systems_state0);

			//0:  01101
			//~0: 10010
			//1:  01101
			//~1:

			int rand_system = rand() % systems_state.size();
			int rand_condition = rand() % 2;

			systems_state[rand_system] = rand_condition;

			std::cout << "====================================================================" << std::endl;

			n++;
		}
	}

	//������� � ��������� ����!!!
	void postfix_increment()
	{
		int m = 5;

		//����������� ���������
		std::cout << m++ << std::endl; //m = m + 1
		std::cout << m << std::endl;

		//std::cout.operator<<(m++).operator<<(' ').operator<<(m).operator<<(std::endl); //�������������� ������, �� ������-�� char ������� ��� int
		//std::cout.operator<<(m); m=m+1; std::cout.operator<<(' ').operator<<(m).operator<<(std::endl); //�������������� ������, �� ������-�� char ������� ��� int

		std::vector<int> vec{ 5,0,7,8,9,4,5,6,9 };
		std::vector<int>::iterator it = vec.begin();

		//std::cout << *(it++) << std::endl;
		//std::cout << *it << std::endl;

		//std::cout << *(it++) << std::endl;
		//std::cout << *it++ << std::endl;
		//std::cout << (*it)++ << std::endl; //5

		//std::cout << (*it++)++ << std::endl; //6
		//// �������������, ��������� ��������������� ����, ������, ���������� ���������
		//// �������������, ������, ���������� ���������, ��������� ��������������� �� ����� ����
		//std::cout << *it << std::endl; //0
		//assert(it == vec.begin()+1); //
		//assert(vec[0]==6); //

		//std::cout << (*(++it))++ << std::endl; //0
		//// ���������� ���������, �������������, ��������� ��������������� ����, ������ 1
		//// ���������� ���������, �������������,������ 0, ��������� ��������������� ����
		//std::cout << *it << std::endl; //1
		//assert(it == vec.begin() + 1); //
		//assert(vec[0] == 5); //

		//std::cout << ++(*(++it)) << std::endl; //
		//// ���������� ���������, �������������, ��������� ��������������� ����, ������ 1
		//// ���������� ���������, �������������, ��������� ��������������� ����, ������ 1
		//std::cout << *it << std::endl; //1
		//assert(it == vec.begin() + 1); //
		//assert(vec[0] == 5); //

		std::cout << ++(*(it++)) << std::endl; //
		// �������������, ��������� ��������������� ����, ������ 6, ���������� ���������
		// �������������, ��������� ��������������� ����, ������ 6, ���������� ���������
		std::cout << *it << std::endl; //0
		assert(it == vec.begin() + 1); //
		assert(vec[0] == 6); //

		//����������� ��������� ������ 3 ��������, � ���������� - 2
	}

	void prefix_increment()
	{
		int m = 5;

		//���������� ���������
		//std::cout << ++m << std::endl;
		//std::cout << m << std::endl;

		std::cout.operator<<(++m).operator<<(' ').operator<<(m).operator<<(std::endl); //�������������� ������, �� ������-�� char ������� ��� int

		std::vector<int> vec{ 5,6,7,8,9,4,5,6,9 };
		std::vector<int>::iterator it = vec.begin();

		std::cout << *(++it) << std::endl;
		std::cout << *it << std::endl;

		//std::cout << *(it++) << std::endl;
		//std::cout << *it++ << std::endl;
		//std::cout << (*it)++ << std::endl;

		//����������� ��������� ������ 3 ��������, � ���������� - 2
	}

	void PostfixPrefixIncrement()
	{
		int arr[20];
		int n = 4;

		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;

		arr[n++] = n;
		//����������� ������ ������������ �
		//arr[n] = n; //��� ���� � �������� n ����� ������� ������� (�� ����������) �������� n
		//n = n + 1;

		arr[++n] = n;
		//���������� ������ ������������ �
		//n = n + 1; //������� ���������� �����������������, ����� ������������
		//arr[n] = n; //��� ���� � �������� n ����� �������� ������������������ �������� n

		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << ' ';
		}
	}

	void set()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������
		bs.set(0, 1);
		assert(bs[0] == 1);
		bs.set();
		assert(bs.all());
	}

	void reset()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������
		bs.reset();
		assert(bs.none());
	}

	void flip()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������
		bs.flip(); //�����������
		assert(bs == 0b00011);
	}

	void to_string()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		std::cout << bs.to_string() << std::endl;
	}

	void to_ulong()
	{
		std::bitset<5> bs{ 0b11100 }; //���������� bitset ���� ������ ������

		unsigned long a = bs.to_ulong(); //���������� ������� ������ � ����� unsigned long

		std::cout << a << std::endl;
	}

	void Run()
	{
		f();
	}
}