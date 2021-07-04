#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Fractions
{
	int bcd(int a, int b)
	{
		while (a != 0 && b != 0)
		{
			if (a > b)
			{
				a = a % b;
			}
			else
			{
				b = b % a;
			}
		}
		return (a + b);
	}
	
	struct Fraction
	{
	private:
		int num; //числитель numerator
		int den; //знаменатель denominator
	
		void simplify() //приватные блоки внутри структуры доступны только внутри этой структуры (внутри методов этой структуры, внутри конструкторов)
		{
			int cur_bcd = bcd(abs(num), abs(den));
			num = num / cur_bcd; //упрощение дроби, например из 2/6 делаем 1/3
			den = den / cur_bcd;
			if (den < 0)
			{
				num *= -1;
				den *= -1;
			}
		}

	public:
		//----------конструкторы----------

		Fraction(int num_, int den_)
		{
			assert(den_ != 0);
			num = num_;
			den = den_;
			simplify();
		}

		Fraction(int num_)
		{
			num = num_;
			den = 1;
		}

		Fraction()
		{
			num = 1;
			den = 1;
		}

		//------------методы--------------

		void print_fr() //метод - это функци€ внутри структуры
		{
			cout << num << '/' << den << endl;
		}
		
		bool is_greater(int n) 
			//таким образом, мы сложную логику сравнени€ дроби с числом спр€тали внутрь самой структуры дроби - это т.н. »Ќ јѕ—”Ћя÷»я
			//“олько сама дробь знает -  ј  сравнивать дробь с числом.
		{
			return (num / den) > n;
		}

		void set_num(int num_)
		{
			num = num_;
			simplify();
		}

		void set_den(int den_)
		{
			assert(den_ != 0);
			den = den_;
			simplify();
		}

		void set_num_den(int num_, int den_)
		{
			assert(den_ != 0);
			num = num_;
			den = den_;
			simplify();
		}

		int get_num()
		{
			return num;
		}

		int get_den()
		{
			return den;
		}
		
		//------------операторы---------
		friend Fraction operator+(Fraction x, Fraction y)
		{
			int common_den = x.den * y.den; 
			//у результатирующей дробии в качестве знаменател€ будет этот знаменатель, а в числителе:
			//числитель = числитель первой дроби умножить на знаменатель второй дроби + числиитель второй дроби умножить на знаменатель первой дроби
			int new_num = x.num * y.den + y.num * x.den;

			return Fraction(new_num, common_den);
		}

		friend Fraction operator-(Fraction x, Fraction y)
		{
			int common_den = x.den * y.den;
			int new_num = x.num * y.den - y.num * x.den;

			return Fraction(new_num, common_den);
		}

		friend Fraction operator*(Fraction x, Fraction y)
		{
			return Fraction(x.num * y.num, x.den * y.den);
		}

		friend Fraction operator/(Fraction x, Fraction y)
		{
			assert(y.num != 0);
			return Fraction(x.num * y.den, x.den * y.num);
		}

		friend bool operator<(Fraction x, Fraction y)
		{
			return x.num * y.den < y.num* x.den;
		}

		friend bool operator>(Fraction x, Fraction y)
		{
			return x.num * y.den > y.num* x.den;
		}

		friend bool operator==(Fraction x, Fraction y)
		{
			return (x.num == y.num) && (x.den == y.den);
		}
		
		friend bool operator!=(Fraction x, Fraction y)
		{
			return !(x == y);
		}

		friend ostream& operator<<(ostream& os, Fraction f)
		{
			if (f.den == 1)
			{
				os << f.num;
			}
			else
			{
				os << f.num << '/' << f.den;
			}
			return os;
		}
	};

	bool is_frs_equal(Fraction x, Fraction y)
	{
		return x.get_den() == y.get_den() && x.get_num() == y.get_num();
	}

	void fr_f1()
	{
		Fraction fr1(1, 0);
		fr1.set_den(0);
		cout << fr1 << endl;
	}

	void fr_f2()
	{
		Fraction fr2(1, 3);
		Fraction fr3(2, 6);
		cout << is_frs_equal(fr2, fr2) << endl;
		Fraction fr4(1,6);
		fr4.set_num(3);
		cout << fr4 << endl;
	}

}

/*
дробь + дробь = дробь
дробь - дробь = дробь
дробь * дробь = дробь
дробь / дробь = дробь
все операции сравнени€
дробь + инт = дробь
*/