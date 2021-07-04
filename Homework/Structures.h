#pragma once
#include <iostream>
using namespace std;


//int - ��� ���, ������� ������� � ���, ��� ������� ������ - ��� �������, � ������� �������� ����� �����
//type_card - ��� ���, ������� ������� � ���, ��� ������ ���� type_card - ��� �������, � ������� �������� ��� ��� ������� ������� � ������� dignity � suit
struct type_Card //��������� ����� ��� ������, �����������.
{
	int _dignity;
	int _suit;
	//���������� ������ ��������� ��������� ���� - ������� ������ ��� ������������ ��� �������. 
	//������������� - ��� �������� ����������� ��� ���������� �������� �����
};


//������������� n-��������� ����, ������ ����� ����� �����������. 
//������ �� ��� ��� ������ � ����� �����, � ������ ����� ������� ����������� - ��� ������� ����������

void cards_generation_diff()
{
	const int n = 5;
	int dignity[n];
	int suits[n];

	for (int i = 0; i < n; i++)
	{
		dignity[i] = rand() % 13 + 2;
		suits[i] = rand() % 4;
		cout << dignity[i] << " - " << suits[i] << endl;
	}
	
	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		if (suits[i] == 3)
		{
			summ += dignity[i];
		}
	}
	cout << summ << endl;
}


bool card_is_black(type_Card card)
{
	return (card._suit > 0 && card._suit < 3);
}


void cards_generation_diff_with_struct()
{
	const int n = 5;
	type_Card cards[n];

	for (int i = 0; i < n; i++)
	{
		cards[i]._dignity = rand() % 13 + 2; 
		//� ������ ������� cards - ��� ������, � ��� ������� ��� ������ - �����, ������� ������ � ���� ��� ����. ��������� ����� ����� � ���.
		//���������� ��������� ����� � ���������� ��� � ����, ��������� ������������ i-� ����� ������� ����
		//����� "." ��� ������ ��������� � ���� ���������
		cards[i]._suit = rand() % 4;
		cout << cards[i]._dignity << " - " << cards[i]._suit << endl;
	}

	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		if (cards[i]._suit == 3)
		{
			summ += cards[i]._dignity;
		}
	}

	int summ_black = 0;
	int summ_red = 0;

	for (int i = 0; i < n; i++)
	{
		if (card_is_black(cards[i]))
		{
			summ_black += cards[i]._dignity;
		}
		else
		{
			summ_red += cards[i]._dignity;
		}
	}
	cout << summ_black << summ_red << endl;


	/*====*/

	//for (int i = 0; i < n; i++)
	//{
	//	type_Card cur_card = cards[i];
	//
	//	if (card_is_black(cur_card))
	//	{
	//		summ_black += cur_card._dignity;
	//	}
	//	else
	//	{
	//		summ_red += cur_card._dignity;
	//	}
	//}

	for (type_Card cur_card : cards) 
		// ��� ������ ����������� �� ��������� ���������� (����� �������� �������� ����� �������� ����� ��������)
		// � ������, ����� ��������� �������� ��������, ����� ������ �������� �������� �����:
		// for (int i = 0; i < n; i++) 
		// { 
		//  type_Card cur_card = cards[i];
	{
		if (card_is_black(cur_card))
		{
			summ_black += cur_card._dignity;
		}
		else
		{
			summ_red += cur_card._dignity;
		}
	}
	cout << summ_black << summ_red << endl;
}



//�������� �������, ������� ��������� �� ���� �����, ���������� ��� ���� ����� ����� ����������� �����, ����, ������ � �������� ������ (�����,����)
bool card_is_high_black(int dignity, int suit)
{
	return (dignity > 10 && dignity < 14 && suit > 0 && suit < 3); //����� ��� ��� ����
}


//�������� �������, ������� ��������� �� ���� �����, ���������� ��� ���� ����� ����� ����������� �����, ����, ������ � �������� ������ (�����,����)
bool card_is_high_black_with_struct(type_Card card)
{
	return (card._dignity > 10 && card._dignity < 14 && card_is_black(card)); //����� ��� ��� ����
}


bool operator==(type_Card cardX, type_Card cardY) 
//������ ���������������� �������, ������� ����� ���������� ����� �� ��������� �����1 == �����2
//������� operator ����� ���� ������������ ������ ���������� +,-,==-���������, <, >, =-������������,*,/ � ��� �����...
//������� ���������� ��� ����� ����� �������� ���������������� ������� ��������� ���� ����
{
	return (cardX._dignity == cardY._dignity && cardX._suit == cardY._suit);
}


struct type_poker_player_cards
// ������ �������� ��������� ��������
{
	type_Card _card1; //������� ����, ������������ ���������, ���������� � ���� ��� �������� - ����������� � �����
	type_Card _card2;
	char _playerID; //������� ��������� ����, ������������ ID ������
};


//������� ��� �������� ������ ��������
void test_struc_func()
{
	int a = 4;
	type_Card cardX={ 10,0 }; //Card1 - ������ ���������, ���������������� �������� ���� �� ������� �� ����������, �.�. 10 �������� � ���� _dignity , � 0 - � ���� _suit

	a = 5;
	cardX._suit=2; //����� ����� ���������� � ����� ������ ���������

	type_Card cardY;
	cardY._dignity = rand() % 13 + 2;
	cardY._suit = rand() % 4;
	if (cardY._suit == cardX._suit)
	{
		cout << 1 << endl;
	}
	if (cardY._suit < cardX._suit)
	{
		cout << 2 << endl;
	}
	if (cardY._suit == cardX._suit && cardY._dignity == cardX._dignity)
	{
		cout << 3 << endl;
	}
	if (cardX == cardY) //���� == ����� �� ���������� ��� ����� - ��� ����� ���������������� ������� ��������� ���� ����
	{
		cout << 5 << endl;
	}
	if (operator==(cardX, cardY))
	//����� ������������ ��������� ������ ������������� �������
	{
		cout << 5 << endl;
	}
}

struct type_Point
{
	int _x;
	int _y;
};

struct type_Segment
{
	type_Point _a;
	type_Point _b;
};

struct type_Triangle
{
	type_Point _a;
	type_Point _b;
	type_Point _c;
};


struct type_Rectangle //�� �� � ������ �������������, � ������ - ��������������
{
	type_Point _a;
	type_Point _b;
	type_Point _c;
	type_Point _d;
};

struct type_Rectangle_by_array
{
	type_Point _a[4];
	/* ������ ���������� ������� �������
	const int n = 4;
	int arr[n];
	*/
};

struct type_Circle
{
	type_Point _center_point;
	int _radius;
};

struct type_shapes
{
	//int a[10];
	//type_Point _b[10];
	static const int n = 10; //����� ��������� ��������� ������ ��������� ���� �������� ������� �������� ����� static
	type_Triangle _triangles_1[n];
	type_Triangle _triangles_2[n];
	type_Circle _circles[n];
	type_Rectangle _rectangles[n];
};

void test_shapes()
{
	type_shapes a;
	//�������� ������������ �� ������ ������� � ����� b ���������� ���������� x=10;y=20;
	a._triangles_2[3]._b._x = 10;
	a._triangles_2[3]._b._y = 20;
	a._triangles_2[3]._b = { 10,20 }; //��� ����� ������ ����� ����

	//������� ������ ������������� �����
	int maximum_radius = 0;
	for (type_Circle cur_circle : a._circles)
	{
		if (cur_circle._radius > maximum_radius)
		{
			maximum_radius = cur_circle._radius;
		}
	}
	
	//������������ � ������������ ����
	int index_of_max_triangle = -1;
	for (int i = 0; i < a.n; i++)
	{
		if (a._circles[i]._radius > maximum_radius)
		{
			maximum_radius = a._circles[i]._radius;
			index_of_max_triangle = i;
		}
	}
}


void entry_function1(int n)
{

}