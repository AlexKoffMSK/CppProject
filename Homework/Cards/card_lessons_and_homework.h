#pragma once
#include <iostream>
#include <cassert>
#include "card_functions.h"
#include "game_21.h"
#include "functions.h"

using namespace std;

void Homework6_1()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
//1. ������� true ���� � ������� 10 ������ ���� ���.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	int IsAExist = 0;
	
	for (int i = 0; i < 10; i++)
	{
		if (a[i] / 10 == 14)
		{
			IsAExist = 1;
		}
	}
	cout << IsAExist << endl;
}

void Homework6_2()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
//2. ����� � ����� ������ ��� �����, ������� ������� �� ��� �� �����������.���� ����� �����, ������ �� ��������.
//��������: 4p  4k - ������ �� ��������. 9b 5k - ������� 9 �����.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);


	int result = compare_2_canon_cards_by_dignity(a[0], a[1]);
	if (result == 1)
	{
		print_char_card_from_canon_card(a[0]);
	}
	else if (result == -1)
	{
		print_char_card_from_canon_card(a[1]);
	}
	else
	{
		cout << endl;
	}

	switch (result)
	{
	case 1: print_char_card_from_canon_card(a[0]); break;
	case -1: print_char_card_from_canon_card(a[1]); break;
	case 0: cout << endl; break;
	}
}

void Homework6_3()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
//3. ������������ ������ ������.����� � ������ ��������� 2 ����� � ������� ������� �� ��� � ������ ������.
//�.�.�������� ����� ������ ������ �� �������� �����.���� ����� ����� - ������ �� ��������.
//��������, ������ ���� : 5p 9k - ����� 5p.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	char trumpChar = 0;
	int trumpNumber = 0; //����� ������� � ���� ������� ���� � ������� ���� ��������� - ������� �� �������
	int card1 = 0;
	int card2 = 0;
	cout << "����� ������� (b,p,t,c): ";
	cin >> trumpChar;

	trumpNumber = convert_char_suit_to_int_suit(trumpChar);

	card1 = a[rand() % n]; //����������� ����� 1, ������� ���������� ����� ����� ���������� ����� ������� � ������� ���� - ����� ���� � �����!!!
	card2 = a[rand() % n]; //����������� ����� 2, ������� ���������� ����� ����� ���������� ����� ������� � ������� ����

	print_char_card_from_canon_card(card1);
	print_char_card_from_canon_card(card2);

	int result = compare_2_canon_cards_by_int_suits_to_int_trump_and_int_dignities_if_suits_are_int_trumps(card1, card2, trumpNumber);

	switch (result)
	{
	case 1: print_char_card_from_canon_card(card1); break;
	case -1: print_char_card_from_canon_card(card2); break;
	case 0: cout << endl; break;
	}
}

void Homework6_4()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
//4. ����� � ������ ������� ���� ������. ����� ������ ���� ������ � ����� ������������ ������.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	int int_index_of_canon_card = 0;

	char dignity = 0;
	//int ConvertedDostoinstvo;

	char suit = 0;
	//int ConvertedMast = 0;

	int canon_card_from_int_dignity_and_int_suit = 0;

	cout << "����������� �����, ������� ������� ���������� �����: \a"; //��������� - ����������� �������
	cin >> dignity;
	cout << "����� �����, ������� ������� ���������� �����: \a";
	cin >> suit;

	//ConvertedDostoinstvo = ConvertCharDostoinstvoToNumber(dostoinstvo);
	//ConvertedMast = ConvertCharOfMastiToNumber(mast);
	//
	//CardNumberFromDostoinstvoAndMast = ConvertToNumberFromIntDostoinstvoAndIntMast(ConvertedDostoinstvo, ConvertedMast);

	canon_card_from_int_dignity_and_int_suit = convert_char_dignity_and_char_suit_to_canon_card(dignity, suit);

	for (int i = 0; i < n; i++)
	{
		if (a[i] == canon_card_from_int_dignity_and_int_suit)
		{
			int_index_of_canon_card = i;
		}
	}
	cout << int_index_of_canon_card << endl;

	char b = 0;
	b = get_char_dignity_from_canon_card(canon_card_from_int_dignity_and_int_suit);
	cout << b << endl;
	char c = 0;
	c = get_char_suit_from_canon_card(canon_card_from_int_dignity_and_int_suit);
	cout << c << endl;
}

void Homework6_5()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
//5. ����� ������� 10 ���� ����� ������������ �����������. �.�. �������� ��������� 10 ���� ���
//4p 7k 10b 4k jb jp 5k 2c 7b 8k. ��� ������������ ����������� - �����, ��� ������ � �������.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	int search_range = 10;

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, search_range);

	int max_int_dignity = a[0];
	
	for (int i = 1; i < search_range; i++)
	{
		if (a[i] > max_int_dignity)
		{
			max_int_dignity = a[i];
		}
	}
	print_char_card_from_canon_card(max_int_dignity);
}

void Homework6_6()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
//6. �������� ����� � ������, ���� �� ���������� ����.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	//print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	char char_dignity_looking_for = 'Q';

	for (int i = 0; i < n; i++)
	{
		print_char_card_from_canon_card(a[i]);
		cout << endl;
		if (get_int_dignity_from_canon_card(a[i]) == convert_char_dignity_to_int_dignity(char_dignity_looking_for))
		{
			cout << "�����! " << "����� " << i << "-� �� ����� � ������!" << endl;
			break;
		}
	}

	//int i = 0;
	//while (i < n && get_int_dignity_from_canon_card(a[i]) != convert_char_dignity_to_int_dignity(char_dignity_looking_for))
	//{
	//	i++;
	//}
}

void Homework6_7()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
//7. �������� �������, ������� �������� �� ���� 2 �����, ���������� 1, ���� ��� ����� �����, ����� 0.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	//print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	int canon_card1 = a[rand() % n];
	int canon_card2 = a[rand() % n];

	cout << compare_2_canon_cards_if_equal_suit(canon_card1, canon_card2) << endl;
}

void Homework6_8()
// ��������� ������ ����� �������. ������ 52 �����. 2 - 10 - �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���.
// ������ ������ ����� �������� �����, ����� ������ ������� ����� - ��� ������� ������ � ������� a ( a[0] )
// ������ ���� �� ��������������.
// b = 0 - �����
// p = 1 - ����
// t = 2 - �����
// c = 3 - �����
//9. �������� �������, ������� ��������� �� ���� ������ �� 7 ����. ���������� 1, ���� ����� ���� ���� ����, ����� 0.
{
	const int n = 52; //���������� ���� � ������ ��� ��������
	int a[n]; //������ ��� ��������������� ������

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	//print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	const int m = 7; // ���������� ����, ������� ��������� �������

	int player_cards_count = 0;
	int head_card_index = 0;
	int get_next_card = 0;
	
	int player_cards[n];
	
	for (int i = 0; i < m; i++) // ������ ������� ����. ������� ������ ��� ������ m ����.
	{
		player_cards[player_cards_count] = a[head_card_index];
		head_card_index += 1;
		player_cards_count += 1;
	
		//player2_cards[i] = cards[head_card_index++];
	}
	
	print_player_cards(player_cards, player_cards_count);
	cout << endl;
	cout << looking_for_pair_in_group_of_canon_cards(player_cards, player_cards_count) << endl;
}

//int a[52];
//int n = 52;
//
//int Get(int i)
//{
//	if (i >= n || i < 0)
//	{
//		assert(false);
//	}
//
//	return a[i];
//}

//void Classwork7_2()
//{
//	int r  = a[5];
//	int r1 = Get(5);
//
//	int player_cards[7];
//	looking_for_pair_in_group_of_canon_cards()
//
//}


void Classwork7_3()
{
   /*
   0  - ����� ����������� ������
   -1 - ����������� �����
   1  - ����� ����������� ������ 1
   2  - ����� ����������� ������ 2
   ...
   i -  ����� ����������� ������ i
   */


	//2140 - ��� �������� � ������ 2 - ������ ����� ���������� � ����������� ������ ����� - �������������� ���������. �.�. 2-14-0 � ������ 2, ���, ��������

	//const int n = 52; //���������� ���� � ������ ��� ��������
	//int dignity[n];
	//int suit[n];   
	//int state[n] = { 0 }; //��������� ���� ���� ��������� � �������
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	state[i] = 1;
	//}
	//
	//state[i] = 1;
	//
	//int d  = dignity[0];
	//int s  = suit[3];
	//int st = state[3];
	//
	//if (st == -1)
	//{
	//
	//}
}

void Homework6_9()
{
	int a = 0;
	cin >> a;
	//cout << if_number_is_prime(a) << endl;
}


int Square(int a)
{
	return a * a;
}

void Classwork7_1()
{
	int card1 = 132;
	int card2 = 103;
	int card3 = 81;

	print_char_card_from_canon_card(card1);
	print_char_card_from_canon_card(card2);
	print_char_card_from_canon_card(card3);
	print_char_card_from_canon_card(37);


	int y = Square(3);
}