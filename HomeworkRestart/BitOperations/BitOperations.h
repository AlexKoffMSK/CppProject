#pragma once
#include <iostream>

namespace BitOperations
{
	int RotateRight(int a, int shift_bits_count)
	{
		//например a=19,  shift_bits_count=2
		//его битовое представление 0000 0000  0000 0000  0000 0000  0001 0011
		//хотим получить            1100 0000  0000 0000  0000 0000  0000 0100
		
		//хотим запомнить последние два бита исходного числа
		//берем для этого логическое И с маской 0000 0000  0000 0000  0000 0000  0000 0011
		//0000 0000  0000 0000  0000 0000  0001 0011
		//and
		//0000 0000  0000 0000  0000 0000  0000 0011
		//=
		//0000 0000  0000 0000  0000 0000  0000 0011
		int saved_bits = a & ((int)std::pow(2, shift_bits_count) - 1);

		a = a >> shift_bits_count;

		//saved_bits =			0000 0000  0000 0000  0000 0000  0000 0011;
		//хотим сделать преобразование
		//shifted_saved_bits =	1100 0000  0000 0000  0000 0000  0000 0000
		int shifted_saved_bits = saved_bits << (32 - shift_bits_count);

		//a=19>>2 =					0000 0000  0000 0000  0000 0000  0000 0100
		//shifted_saved_bits =		1100 0000  0000 0000  0000 0000  0000 0000
		//a | shifted_saved_bits =  1100 0000  0000 0000  0000 0000  0000 0100
		a = a | shifted_saved_bits;

		return a;
	}
}