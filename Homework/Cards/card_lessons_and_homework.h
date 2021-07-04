#pragma once
#include <iostream>
#include <cassert>
#include "card_functions.h"
#include "game_21.h"
#include "functions.h"

using namespace std;

void Homework6_1()
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
//1. Вывести true если в верхних 10 картах есть туз.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
//2. Взять с верха колоды две карты, вывести большую из них по достоинству.Если карты равны, ничего не выводить.
//Например: 4p  4k - ничего не выводить. 9b 5k - вывести 9 бубей.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
//3. Пользователь вводит козырь.Взять с колоды случайные 2 карты и вывести большую из них с учетом козыря.
//Т.е.козырная карта всегда больше не козырной карты.Если карты равны - ничего не выводить.
//Например, козырь пики : 5p 9k - вывод 5p.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	char trumpChar = 0;
	int trumpNumber = 0; //потом вывести в свою функцию свич и вписать сюда равенство - отсылку на функцию
	int card1 = 0;
	int card2 = 0;
	cout << "Масть козырей (b,p,t,c): ";
	cin >> trumpChar;

	trumpNumber = convert_char_suit_to_int_suit(trumpChar);

	card1 = a[rand() % n]; //вытаскиваем карту 1, которая определена через поиск случайного числа индекса в массиве карт - выдал уход в минус!!!
	card2 = a[rand() % n]; //вытаскиваем карту 2, которая определена через поиск случайного числа индекса в массиве карт

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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
//4. Найти в колоде позицию туза червей. найти индекс туза червей в новой перемешанной колоде.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	int int_index_of_canon_card = 0;

	char dignity = 0;
	//int ConvertedDostoinstvo;

	char suit = 0;
	//int ConvertedMast = 0;

	int canon_card_from_int_dignity_and_int_suit = 0;

	cout << "Достоинство карты, позицию которой необходимо найти: \a"; //википедия - управляющие символы
	cin >> dignity;
	cout << "Масть карты, позицию которой необходимо найти: \a";
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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
//5. Среди верхних 10 карт найти максимальное достоинство. Т.е. например последние 10 карт это
//4p 7k 10b 4k jb jp 5k 2c 7b 8k. Тут максимальное достоинство - валет, вот вальта и вывести.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
//6. Выводить карты с колоды, пока не встретится дама.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

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
			cout << "Нашли! " << "Лежит " << i << "-й по счёту в колоде!" << endl;
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
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
//7. Написать функцию, которая принмает на вход 2 карты, возвращает 1, если они одной масти, иначе 0.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	//print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	int canon_card1 = a[rand() % n];
	int canon_card2 = a[rand() % n];

	cout << compare_2_canon_cards_if_equal_suit(canon_card1, canon_card2) << endl;
}

void Homework6_8()
// Заполнить массив всеми картами. Колода 52 карты. 2 - 10 - числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз.
// Колода всегда лежит рубашкой вверх, самая первая верхняя карта - это нулевой индекс в массиве a ( a[0] )
// массив карт НЕ ПЕРЕПИСЫВАЕТСЯ.
// b = 0 - бубны
// p = 1 - пики
// t = 2 - трефы
// c = 3 - червы
//9. Написать функцию, которая принимает на вход массив из 7 карт. Возвращает 1, если среди карт есть пара, иначе 0.
{
	const int n = 52; //количество карт в колоде без джокеров
	int a[n]; //массив для сгенерированной колоды

	canon_cards_array_generation(a, n);
	canon_cards_mixing(a, n);
	//print_canon_cards_array_and_char_cards_arrayOptional(a, n);

	const int m = 7; // количество карт, которые раздаются игрокам

	int player_cards_count = 0;
	int head_card_index = 0;
	int get_next_card = 0;
	
	int player_cards[n];
	
	for (int i = 0; i < m; i++) // первая раздача карт. раздача первой или первых m карт.
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
   0  - карта принадлежит колоде
   -1 - принадлежит битте
   1  - карта принадлежит игроку 1
   2  - карта принадлежит игроку 2
   ...
   i -  карта принадлежит игроку i
   */


	//2140 - туз бубновый у игрока 2 - подход через добавление в какноничную запись карты - идентификатора состояний. Т.е. 2-14-0 у игрока 2, туз, бубновый

	//const int n = 52; //количество карт в колоде без джокеров
	//int dignity[n];
	//int suit[n];   
	//int state[n] = { 0 }; //присвоить ноль всем элементам в массиве
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