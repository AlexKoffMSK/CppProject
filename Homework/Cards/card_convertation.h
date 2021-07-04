#pragma once
#include <cassert>
#include <iostream>
#include "card_arrays.h"


using namespace std;


int convert_char_dignity_to_int_dignity(char char_dignity)
// ������� ������������ ���������������� ���� ����������� � ���������/�������� �������� - � ��������
{
	char upper_char_dignity = toupper(char_dignity); //������ ����� ������� ��������� ��� ���������� � ���������

	for (int i = 0; i < size(dignities); i++) //����� �� ������� ����������
	{
		if (upper_char_dignity == dignities[i]) //���� ������� ��������� ���������� ����� ����-�� �� �������
		{
			return i + 2; // ���������� ������ ��������� ���� ��������� ���������� + 2
		}
	}
	assert(false);

	//switch (char_dignity)
	//{
	//case 'A': return 14; break;
	//case 'a': return 14; break;
	//case 'K': return 13; break;
	//case 'k': return 13; break;
	//case 'Q': return 12; break;
	//case 'q': return 12; break;
	//case 'J': return 11; break;
	//case 'j': return 11; break;
	//case 'Z': return 10; break; //� ��� ��� ������� ����� ��������? 
	//case 'z': return 10; break;
	//case '9': return 9; break;
	//case '8': return 8; break;
	//case '7': return 7; break;
	//case '6': return 6; break;
	//case '5': return 5; break;
	//case '4': return 4; break;
	//case '3': return 3; break;
	//case '2': return 2; break;
	//}
}

int convert_char_suit_to_int_suit(char char_suit)
// ������� ������������ ���������������� ���� ����������� � ���������/�������� �������� - � ��������
{
	// ���� ����� � ������� suits ��������� ������ suit � ������� ��� ������ � �������
	// � ���� �� �����, ������� assert(false)

	// { 'b', 'p', 't', 'c' }

	for (int i = 0; i < size(suits); i++) //size(suits) - ���������� ������ ������� suits
	{
		if (char_suit == suits[i])
		{
			return i;
		}
	}
	assert(false);

	//assert(suit == 'b' || suit == 'p' || suit == 't' || suit == 'c'); //������ �� ���-�� ������� �� ������� ���������, � �������������� � ������ ����� �� ������� masti[]? ������� ��������� � ����� ������ ������, ���������� - � ���, ����...? �� ��� ����� �������� - ��� � ��� ���� ������?
	//
	//switch (suit)
	//{
	//case 'b': return 0; break;
	//case 'p': return 1; break;
	//case 't': return 2; break;
	//case 'c': return 3; break;
	//}

}

int convert_int_dignity_and_int_suit_to_canon_card(int int_dignity, int int_suit)
//����� ����� ���� �� ������� � ������� � ����, �.�. � ������ ������� ��������� � ����������� ��� ������ ������� � ����� ������ ��.
//������ ���� ���������� ���� ������������ � ����������� ����������! ������ ���������� �������� ������ ���� ��������� ������ ���������� � � �������! 
{
	return int_dignity * 10 + int_suit;
}

int convert_char_dignity_and_char_suit_to_canon_card(char char_dignity, char char_suit)
{
	//return ConvertCharDostoinstvoToNumber(dostoinstvo) * 10 + ConvertCharOfMastiToNumber(mast);
	//return ConvertToNumberFromIntDostoinstvoAndIntMast(ConvertCharDostoinstvoToNumber(dostoinstvo), ConvertCharOfMastiToNumber(mast));
	//������ ������� ������ ���� �� ������, �� ������� ������ ��� ��������� � �������� ������������

	int int_dignity = convert_char_dignity_to_int_dignity(char_dignity);
	int int_suit = convert_char_suit_to_int_suit(char_suit);

	return convert_int_dignity_and_int_suit_to_canon_card(int_dignity, int_suit);
}

char convert_int_dignity_to_char_dignity(int int_dignity)
{
	// [2,14] - 

	return dignities[int_dignity - 2];

	//switch (int_dignity)
	//{
	//case 14: return 'A'; break;
	//case 13: return 'K'; break;
	//case 12: return 'Q'; break;
	//case 11: return 'J'; break;
	//case 10: return 'Z'; break; //� ��� ��� ������� ����� ��������? 
	//case 9: return '9'; break;
	//case 8: return '8'; break;
	//case 7: return '7'; break;
	//case 6: return '6'; break;
	//case 5: return '5'; break;
	//case 4: return '4'; break;
	//case 3: return '3'; break;
	//case 2: return '2'; break;
	//}
}

char convert_int_suit_to_char_suit(int int_suit)
{
	//assert(int_suit >= 0 && int_suit <= 3);
	//return suits[int_suit];

	//switch (int_suit)
	//{
	//case 0: return 'b'; break;
	//case 1: return 'p'; break;
	//case 2: return 't'; break;
	//case 3: return 'c'; break;
	//}
	if (int_suit >= 0 && int_suit <= 3)
	{
		return suits[int_suit];
	}
	else
	{
		assert(false);
	}
}