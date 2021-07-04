#pragma once
#include <iostream>
#include <cassert>
#include "canon_card_decomposition.h"
#include "card_convertation.h"

using namespace std;

/*
	1. �������� ������� �����������
	2. ������� �������� PrintCardNameInterpretedFromNumber
	3. ������� �������� Compare2CardsByDignity
	4. ������� �������� Compare2CardsBySuitsAndDignitiesWithTrump
	5. ����������� dignity � int_dignity (suit)
	6. ������������� ������������� �������� ������� from, to, � �.�.
	7. ��������� ������ ����������� ���������� ������� �����������
*/

/*
�� ������ ������, ���������� ��������, ������� � ��� ����:
1. (canon_card)				���������� ������ �����. ��� ��������� �����, �������� 121. 
2. (int_dignity,int_suit)	������� ������ �����. ��� 2 �������� �����, �������� 12 1. 
3. (char_dignity,char_suit)	��������� ������ �����. ��� 2 ��������� ����������. Q p  
4. int_dignity				�����������. (��������� �� ���������� �������, ��� �����������, ��� ���). ��� ������� ����������, ����������� �������� [2,14]
5. char_dignity				��������� �����������. ��� ��������� ����������, ����������� {'2','3','4',...,'Z','J','Q','K','A'}
6. int_suit					�����. (�� �������� � ������������, ��� ���). ��� ������� ����������, ����������� [0,3]
7. char_suit				��������� �����. ��������� ����������, ����������� {'b','p','t','c'}*/

/* Convertation:
������� ������������ ��� ���������������:��� - �� ���, ������� TO
������� ������������ ��� ������������:���-�� - �� ����-��, ������� FROM
	3  -> 1	  * convert_char_dignity_and_char_suit_to_canon_card(char char_dignity, char char_suit)
	2  -> 1	  * convert_int_dignity_and_int_suit_to_canon_card(int int_dignity, int int_suit)
	1  -> 4   * get_int_dignity_from_canon_card(int canon_card)
	1  -> 5   * get_char_dignity_from_canon_card(int canon_card)
	1  -> 6   * get_int_suit_from_canon_card(int canon_card)
	1  -> 7	  * get_char_suit_from_canon_card(int canon_card)
	4  -> 5	  * convert_int_dignity_to_char_dignity(int int_dignity)
	5  -> 4	  * convert_char_dignity_to_int_dignity(char char_dignity)
	6  -> 7	  * convert_int_suit_to_char_suit(int int_suit)
	7  -> 6   * convert_char_suit_to_int_suit(char char_suit)
*/



void canon_cards_array_generation(int* canon_cards, int n)
// ������� ��������� ������ ���� � ��������� ��� ������� �� �����������
{
	const int dmin = 2; //����������� ����������� - ����������� ����� � ������ ������
	const int dmax = dmin + size(dignities) - 1; //������������ ����������� - ��� ����, � 2 �� 10 ��� �������� �����, 11 - �����, 12 - ����, 13 - ������, 14 - ���
	int k = 0; //������ ������� � ��� ���������� ��� �������
	
	// 2 3 4 5 6  7 8 9 10 11  12 13 14 15
	// 0 1 2 3
	// 56 �������� ��� ������� ������� 52, �� 4 ����� �� �������
	for (int i = dmin; i <= dmax; i++) //���� ��� ���������� ������� - ������� ����, � ����� - ����������
	{
		for (int j = 0; j < size(suits); j++) //���� ��� ���������� ������� ���� � ������������ ������������� - �������
		{
			canon_cards[k] = convert_int_dignity_and_int_suit_to_canon_card(i, j); //���������� ������� ����� �������� ���������� � ������
			k++; //������� � ��������� ����� ���� �������� � ���������� ������� �������
		}
	}
}

void canon_cards_mixing(int* canon_cards, int n)
// ������� ������������ ������ �� ����
{
	int peremesh = 10000; //���������� ��� ������������� ������ (10000 * 52)
	int PervayaKartaDlyaPeremesh = 0; //������ �����-�� ����� � ������ ��� ������ ��������� � ������ ������
	int VtorayaKartaDlyaPeremesh = 0; //������ �����-�� ������ ����� ��� ������ ��������� � ������-���������� ������
	int ObmennayaPeremennaya = 0;//��������� ���������� ��� ������ �������� ����

	for (int i = 0; i <= peremesh; i++)//���� ��� ���������� ������� - ������ ����
	{
		PervayaKartaDlyaPeremesh = rand() % n; //���� ������ ������ �����-�� ��������� ����� 
		VtorayaKartaDlyaPeremesh = rand() % n; //���� ������ ������ �����-�� ������ �����
		ObmennayaPeremennaya = canon_cards[PervayaKartaDlyaPeremesh];//����������� ��������� ���������� �������� �� �������-������, ��������������� �������, ������������ ��������
		canon_cards[PervayaKartaDlyaPeremesh] = canon_cards[VtorayaKartaDlyaPeremesh];//����������� �������� ������ ��������� ����� � �������-������ - �������� ������ ��������-��������� �����
		canon_cards[VtorayaKartaDlyaPeremesh] = ObmennayaPeremennaya;//����������� �������� ������ ��������-����������� ����� - �������� �� ��������� ����������, ���� �� �������� �������� ������ ����� �� ������
	}
}



void print_char_card_from_canon_card(int canon_card)
// ������� ��������� �� ���� 1 ����� � �������� � � ������������������ ����
{
	// cout << f_1_5(card) << ' ' << f_1_7(card); //����� ���� ��� ������ ��� ������� �����������, ����� ���������� ��� ������� ����� ������������� ������� �����������

	assert(get_int_suit_from_canon_card(canon_card) >= 0 && get_int_suit_from_canon_card(canon_card) <= 3); //�������, ��� ��������� ����� ���������� card ����� ���������� � ������� ��������� �� 0 �� 3 ������������, ����� �������� ������ � ������������ ���������� ���������
	
	//char dignities[] = { '2', '3', '4' ,'5','6','7','8','9','Z','J','Q','K','A' };
	////������ ������ ��������-���������� [0,12] - ��� ������ �� ����� ����������� �������� ����, ��� ����! 
	////��� ��� ���������� ������� char, ������� ��������� ������ ����� ��������, ���������� ��� ����������� 10 ��������� ����������!

	/*const char* dostoinstva[] = { "2", "3", "4" ,"5","6","7","8","9","10","J","Q","K","A"};
	��� ������� ������������� ������� char ��� ������ (string, �� line), �.�. ��� �� ��� ����� ������ ��������� � ������ ��� ��� �������*/
	  
	//setw(2) -�������, ��� ��� ��������� ����� ���� �������� 2 ������ � ���������. 
	if (get_int_dignity_from_canon_card(canon_card) == 10) //����������� ���������� ��� ������ ����������� ����� 10, �.�. char ��������� ������ ����� ��������
	{
		cout << setw(2) << 10 ; //������� char-������ ������� �� ����� (��� ������� ��� ����� ���� �������� 10)
	}
	else
	{
		cout << setw(2) << get_char_dignity_from_canon_card(canon_card); //������� char-������ ������� �� ����� (��� ������� ��� �� �������� 10), ��� ����:
	//����� 2 ��������� ��� ����, ����� �� �������� �� ������� ���������� �������. ��� ����, �������� ��� ���:
	//���� [a[i] / 10 ��� ������� ����� 2, �� ���� �� �������� -2 �� ��������� �� ������� ������� (3 ������) �������, �.�. 4
	//� ���� ����� ��� - 14 - �� ������ �� ������� ���������� �������.
	}

	//(cond) ? (act1) : (act2)

	//cout << ((get_int_dignity_from_canon_card(canon_card) == 10) ? 10 : get_char_dignity_from_canon_card(canon_card)); //��������� � cout ���� ��������� ��������!
	cout << get_char_suit_from_canon_card(canon_card);

}

void print_canon_cards_array_and_char_cards_arrayOptional(int* canon_cards, int n)
// ������� ��������� �� ���� ������ ���� � �������� ��� � �������������������� ����
{
	for (int i = 0; i < n; i++)
	{
		cout << canon_cards[i] << " - ";
		print_char_card_from_canon_card(canon_cards[i]);
		cout << endl;
	}
}



int compare_2_canon_cards_by_dignity(int canon_card1, int canon_card2)
// ������� ��������� �� ���� 2 ����� � ����������:
// -1, ���� ������ ����� ������ ������
//  0, ���� ��� �����
//  1, ���� ������ ����� ������ ������
// ������������� �����, ���� ������ ����� ������ ������ - ��� ��� ���������
//  0, ���� ��� ����� - ��� ��� ���������
// ������������� �����, ���� ������ ����� ������ ������ - ��� ��� ���������
{
	if (get_int_dignity_from_canon_card(canon_card1) > get_int_dignity_from_canon_card(canon_card2))
	{
		return 1;
	}
	else if (get_int_dignity_from_canon_card(canon_card1) < get_int_dignity_from_canon_card(canon_card2))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int compare_2_canon_cards_if_equal_suit(int canon_card1, int canon_card2)
{
	if (get_int_suit_from_canon_card(canon_card1) == get_int_suit_from_canon_card(canon_card2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int compare_2_canon_cards_by_int_suits_to_int_trump_and_int_dignities_if_suits_are_int_trumps(int canon_card1, int canon_card2, int int_trump)
// ������� ��������� �� ���� 2 �����, ������ � ����������:
// -1, ���� ������ ����� ������ ������
// 0, ���� ��� �����
// 1, ���� ������ ����� ������ ������
{
	if (get_int_suit_from_canon_card(canon_card1) == int_trump && get_int_suit_from_canon_card(canon_card2) != int_trump)
	{
		return 1;
	}
	else if (get_int_suit_from_canon_card(canon_card1) != int_trump && get_int_suit_from_canon_card(canon_card2) == int_trump)
	{
		return -1;
	}
	else // ���� ��� ����� ������, ���� ����� �� ��� �� ������
	{
		return compare_2_canon_cards_by_dignity(canon_card1, canon_card2); //���������� ��� ������� ���������, ������� ��������� ����� ���������� �������
	}
}



int looking_for_pair_in_group_of_canon_cards(int* player_cards, int player_cards_count)
{
	for (int i = 0; i < player_cards_count; i++)
	{
		for (int j = i + 1; j < player_cards_count; j++)
		{
			if (player_cards[j] == player_cards[i])
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}