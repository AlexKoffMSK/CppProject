#pragma once
#include <iostream>
#include <variant>
#include <any>

namespace Union
{
	struct Color
	{
		uint8_t _red = 0;
		uint8_t _green = 0;
		uint8_t _blue = 0;
		uint8_t _alpha = 0;
	};

	union ColorUnion
	{
		uint32_t _color_packed;
		Color _color_struct;
	};

	void Test0()
	{
		ColorUnion cu{};
		cu._color_struct._red = 200;
		cu._color_struct._green = 150;
		cu._color_struct._blue = 30;
		std::cout << std::hex << cu._color_packed << std::endl;

		cu._color_packed = 0x23AA613B;
		
		std::cout << std::hex << (int)cu._color_struct._blue << std::endl;
		std::cout << std::hex << (int)cu._color_struct._green << std::endl;
		std::cout << std::hex << (int)cu._color_struct._red << std::endl;
	}
	
	void Test()
	{
		Color col;
		col._red = 200;
		col._green = 150;
		col._blue = 30;

		uint32_t color = 0x23AA613B; //запись шеснадцатиричного числа - 2 символа = 1 байт
		//uint32_t color_1 = color << 24; 0x3B000000
		//uint8_t alpha = (color << 24) >> 24;
		//uint8_t alpha = color & 0b11111111;
		uint8_t alpha = (color & 0x000000FF);		// 0x0000003B
		uint8_t blue =  (color & 0x0000FF00) >> 8;  // 0x00006100, >> 8=0x00000061
		uint8_t green = (color & 0x00FF0000) >> 16; // 0x00AA0000, >>16=0x000000AA
		uint8_t red =   (color & 0xFF000000) >> 24; // 0x23000000, >>24=0x00000023

		std::cout << std::hex << (int)alpha << std::endl;
		std::cout << std::hex << (int)blue << std::endl;
		std::cout << std::hex << (int)green << std::endl;
		std::cout << std::hex << (int)red << std::endl;

		//0010 0101
		//0000 0111
		//&
		//0000 0101
		//0010 0101 0010 0101 0010 0101 0010 0101
		//& 0xFF 						
		//0000 0000 0000 0000 0000 0000	1111 1111
		//
		//			0010 0101
		//1111 1111 0000 1011
	}

	union LongAndDouble
	{
		long _long;
		double _double;
	};

	struct LongAndDoubleStructure
	{
		long _long;
		double _double;
	};


	void Test2()
	{
		LongAndDoubleStructure lads;
		lads._long = 3;
		lads._double = 2.5;

		LongAndDouble lad;
		lad._long = 3;
		lad._double = 2.5;

		std::cout << lads._long << ' ' << lads._double << std::endl; //3, 2.5
		std::cout << lad._long << ' ' << lad._double << std::endl; // 2, 2.5
	}

	union IntAndDoubleandChar
	{
		int _int;
		double _double;
		char _char;
	};

	void Test3()
	{
		IntAndDoubleandChar iadc;
		iadc._int = 3;
		iadc._double = 2.5;
		iadc._char = 90;

		std::cout << sizeof(iadc) << std::endl;
		std::cout << iadc._int << ' ' << iadc._double << ' ' << iadc._char << std::endl;

	}

	union U1
	{
		char _arr[4];
		unsigned int _int;
	};



	void Test4()
	{
		U1 u1;
		u1._int = 0x79;

		for (int i = 0; i < std::size(u1._arr); ++i)
		{
			std::cout << std::hex <<(unsigned int) u1._arr[i] << ' ';
		}
		std::cout << endl;
	}

	struct OrderIdAndAccount
	{
		uint16_t _order_id;
		uint16_t _account_id;
	};

	union OrderIdAndAccountUnion
	{
		uint32_t _orderid_and_account_packed;
		OrderIdAndAccount _oia;
	};

	void Test5()
	{
		OrderIdAndAccountUnion oiau;
		oiau._oia._account_id = 5;
		oiau._oia._order_id = 300;

		//SendTExchange(oiau._orderid_and_account_packed)
		uint32_t exchange_response = 0x0005012C;
		oiau._orderid_and_account_packed = exchange_response;

		std::cout << (int)oiau._oia._account_id << ' ' << (int)oiau._oia._order_id << std::endl;
	}


	union IntDoubleString
	{
		int _int;
		double _double;
		std::string _str{};

		IntDoubleString() = default;
	};

	void Test6()
	{
		int arr[10];
		double arr1[10];
		std::string arrs[10];

		arr[0] = 3;
		arrs[1] = "Hello";
		arr1[2] = 2.5;

		std::variant<int, double, std::string> arrvar[10];
		arrvar[0] = 3;
		arrvar[1] = "Hello";
		arrvar[2] = 2.5;

		std::cout << std::get<int>(arrvar[0]) << std::endl;
		std::cout << std::get<std::string>(arrvar[1]) << std::endl;
		std::cout << std::get<double>(arrvar[2]) << std::endl;

		auto Print = [](auto&& arg)
		{
			std::cout << arg << ' ';
		};
		
		for (std::variant<int, double, std::string>& elem : arrvar)
		{
			std::visit(Print, elem);
		}

		std::cout << std::endl;

		std::any any1[10];
		any1[0] = 3;
		any1[1] = "Hello";
		any1[2] = 2.5;

		for (std::any& elem : any1)
		{
			std::cout << elem.type().name() << '|';
		}
	}
}