#pragma once
#include <iostream>

namespace PropertiesByBitOperations
{
	struct ObjectProperties
	{
		bool _is_big = false;
		bool _is_red = false;
		bool _is_fast = false;
		bool _is_heavy = false;
		int _id = 0;

		void SetVal(bool is_big, bool is_red, bool is_fast, bool is_heavy)
		{
			_is_big = is_big;
			_is_red = is_red;
			_is_fast = is_fast;
			_is_heavy = is_heavy;
		}
	};

	void Test1()
	{
		ObjectProperties op1;
		op1._is_fast = true;
		op1._is_heavy = true;


	}

	void Test2(ObjectProperties op)
	{
		if (op._is_big && op._is_fast)
		{
			std::cout << "Is big & Is fast" << std::endl;
		}
		else if (op._is_red && !op._is_heavy)
		{
			std::cout << "Is red & Is NOT heavy" << std::endl;

		}
	}

	void Test3(ObjectProperties op, ObjectProperties op1)
	{
		if ((op._is_big == op1._is_big) && (op._is_fast == op1._is_fast) && (op._is_heavy == op1._is_heavy) && (op._is_red == op1._is_red))
		{
			std::cout << "H" << std::endl;
		}
		else
		{
			std::cout << "W" << std::endl;
		}
	}

	void Test4(ObjectProperties op)
	{
		if ((op._is_big) && (op._is_fast) && (op._is_heavy) && (op._is_red))
		{
			std::cout << "H" << std::endl;
		}
		else
		{
			std::cout << "W" << std::endl;
		}
	}

	void Test5()
	{
		ObjectProperties op;
		op.SetVal(true, false, false, true);


	}

	//const char kBig = 1; // (1<<0)
	//const char kRed = 2; // (1<<1)
	//const char kFast = 4; // (1<<2)
	//const char kHeavy = 8; // (1<<3)

	//можно удалять ведущие нули
	//const char kBig =        0b1; // (1<<0)
	//const char kRed =       0b10; // (1<<1)
	//const char kFast =     0b100; // (1<<2)
	//const char kHeavy =   0b1000; // (1<<3)

	const uint8_t kBig =	0b00000001; // (1<<0)
	const uint8_t kRed =	0b00000010; // (1<<1)
	const uint8_t kFast =	0b00000100; // (1<<2)
	const uint8_t kHeavy =	0b00001000; // (1<<3)
	const uint8_t kAll = (kHeavy << 1) - 1; //должен быть всегда относительно последнего флага. Сдвигаем на единицу, потом вычитаем единицу, после чего - в правой части = все единицы.


	struct ObjectPropertiesByBits
	{
		uint8_t _properties = 0;

	};

	void Test1()
	{
		ObjectPropertiesByBits op1;
		op1._properties |= kFast; //поднять флаг kFast в свойствах
		op1._properties |= kHeavy;
		op1._properties &= ~kRed; //опустили флаг kRed в свойствах
	}

	void Test2(ObjectPropertiesByBits op)
	{
		//if ((op._properties & kRed) != 0)
		if (op._properties & kRed) //если флаг kRed поднят
		{

		}
		//else if (((op._properties & kBig) !=0) && ((op._properties & kFast)!=0))
		else if ((op._properties & kBig) && (op._properties & kFast))
		{

		}
		//else if ((op._properties & kRed) && ((op._properties & kHeavy) == 0)
		else if ((op._properties & kRed) && !(op._properties & kHeavy))
		{

		}
	}

	void Test3(ObjectPropertiesByBits op, ObjectPropertiesByBits op1)
	{
		if (op._properties == op1._properties)
		{
		}
		else
		{
		}
	}

	void Test4(ObjectPropertiesByBits op)
	{
		if (op._properties == 0)
		{
		}
		else if (op._properties == kAll)
		{
		}
	}

	void Test5(ObjectPropertiesByBits op)
	{
		op._properties |= (kBig | kFast); // |= поднимает единицы, которые указаны справа в переменной, которая указана слева, не трогая остальные биты
		op._properties = (kBig | kFast); //   = перетирает всё и делает так, что в _properties становится значение только kBig | kFast (0000 0101). Это аналог a=13 
	}
}