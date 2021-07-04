#pragma once
#include "card_functions.h"

// Создать колоду, перемешать. Создать 2 массива для карт игроков и раздить им по m карт, зигзагом
//void players_card_generation()
//{
//	const int n = 52; //количество карт в колоде без джокеров
//	int cards[n]; //массив для сгенерированной колоды
//	const int m = 4;
//	canon_cards_array_generation(cards, n);
//	canon_cards_mixing(cards, n);
//	
//	int player1_cards[20];
//	int player2_cards[20];
//
//	for (int i = 0; i < m; i++)
//	{
//		player1_cards[i] = cards[i * 2];
//		player2_cards[i] = cards[i * 2+1];
//	}
//	print_char_card_from_canon_card(cards[m * 2]);
//}

void print_player_cards(int* player_cards, int player_cards_count)
//Функция, которая принимает карты игроков и выводит их на экран
{
	for (int i = 0; i < player_cards_count; i++)
	{
		print_char_card_from_canon_card(player_cards[i]);
		cout << ' ';
	}
}
	
int player_summ_count(int* player_cards, int player_cards_count)
//Функция, которая суммирует текущее значение достоинств карт на руках игрока
{
	int cards_summ = 0;
	int temp = 0;
	
	for (int i = 0; i < player_cards_count; i++)
	{
		switch (get_int_dignity_from_canon_card(player_cards[i]))
		{
		case 14: temp = (i >= 2 && cards_summ + 11 > 21) ? 1 : 11; break;
		case 13: temp = 4; break;
		case 12: temp = 3; break;
		case 11: temp = 2; break;
		case 10: temp = 10; break;
		case 9: temp = 9; break;
		case 8: temp = 8; break;
		case 7: temp = 7; break;
		case 6: temp = 6; break;
		case 5: temp = 5; break;
		case 4: temp = 4; break;
		case 3: temp = 3; break;
		case 2: temp = 2; break;
		}

		cards_summ += temp;
	}
	return cards_summ;
}

void print_next_card(int* cards, int head_card_index)
{
	cout << "Следующая карта в колоде:";
	print_char_card_from_canon_card(cards[head_card_index]);
	cout << endl;
}

void print_player1_cards_and_summ(int* player_cards, int player_cards_count)
{
	cout << "Карты у Player 1: ";
	print_player_cards(player_cards, player_cards_count);
	cout << endl;
	cout << "Сумма карт у Player 1: " << player_summ_count(player_cards, player_cards_count) << endl;
}

void print_player2_cards_and_summ(int* player_cards, int player_cards_count)
{
	cout << "Карты у Player 2: ";
	print_player_cards(player_cards, player_cards_count);
	cout << endl;
	cout << "Сумма карт у Player 2: " << player_summ_count(player_cards, player_cards_count) << endl;
}

void player_check_and_print_if_lose(int* player_cards, int player_cards_count, int player_num)
{
	if (player_summ_count(player_cards, player_cards_count) > 21)
	{
		cout << "Player " << player_num << " проиграл!" << endl;
	}
}

void player1_check_and_print_if_lose(int* player_cards, int player_cards_count)
{
	if (player_summ_count(player_cards, player_cards_count) > 21)
	{														 
		cout << "Player 1 проиграл!" << endl;				 
	}	
}

void player2_check_and_print_if_lose(int* player_cards, int player_cards_count)
{
	if (player_summ_count(player_cards, player_cards_count) > 21)
	{
		cout << "Player 2 проиграл!" << endl;
	}
}


void players_card_generation_with_index()
// Создать колоду, перемешать. Создать 2 массива для карт игроков и раздить им по m карт, зигзагом
{
	const int n = 52; //количество карт в колоде без джокеров
	int cards[n]; //массив, в который будет положена сгенерированная колода
	const int m = 3; // количество карт, которые раздаются игрокам
	
	int player1_cards_count = 0;
	int player2_cards_count = 0;
	int head_card_index = 0;
	int player1_summ = 0;
	int player2_summ = 0;
	int get_next_card = 0;
	int win_points = 21;
	int distance_to_win_points_p1 = 0;
	int distance_to_win_points_p2 = 0;

	canon_cards_array_generation(cards, n);
	canon_cards_mixing(cards, n);

	int player1_cards[12];
	int player2_cards[12];
	
	//const int player_count = 2;
	//const int max_player_card_count = 12;
	//int players_cards[player_count][max_player_card_count];
	//
	//for (int k = 0; k < player_count; k++)
	//{
	//	player_cards[k][player_cards_count[k]] = cards[head_card_index];
	//	head_card_index += 1;
	//	player_cards_count[k] += 1;
	//}

	for (int i = 0; i < m; i++) // первая раздача карт. раздача первой или первых m карт.
	{
		
		player1_cards[player1_cards_count] = cards[head_card_index];
		head_card_index += 1;
		player1_cards_count += 1;
		
		player2_cards[player2_cards_count] = cards[head_card_index];
		head_card_index += 1;
		player2_cards_count += 1;
	
		//player2_cards[i] = cards[head_card_index++];
	}

	print_player1_cards_and_summ(player1_cards, player1_cards_count);
	print_player2_cards_and_summ(player2_cards, player2_cards_count);

	//print_next_card(cards, head_card_index);

	player_check_and_print_if_lose(player1_cards, player1_cards_count, 1);
	player_check_and_print_if_lose(player2_cards, player2_cards_count, 2);
	
	bool is_player_1_ready = false;
	bool is_player_2_ready = false;

	do
	{
		if (is_player_1_ready == false && player_summ_count(player1_cards, player1_cards_count) <= 21)
		{
			std::cout << "Player 1 get next card? (Yes = 1 / No = 0): ";
			std::cin >> get_next_card;


			if (get_next_card == 1)
			{
				player1_cards[player1_cards_count] = cards[head_card_index];
				head_card_index += 1;
				player1_cards_count += 1;

				print_player1_cards_and_summ(player1_cards, player1_cards_count);

				distance_to_win_points_p1 = win_points - player_summ_count(player1_cards, player1_cards_count);
				assert(distance_to_win_points_p1 >= 0);
			}
			else
			{
				is_player_1_ready = true;
				distance_to_win_points_p1 = win_points - player_summ_count(player1_cards, player1_cards_count);
				assert(distance_to_win_points_p1 >= 0);
				cout << "Очков до 21 у Player 1: " << distance_to_win_points_p1 << endl;
			}
		}
		else
		{
			player1_check_and_print_if_lose(player1_cards, player1_cards_count);
		}

		if (is_player_2_ready == false && player_summ_count(player2_cards, player2_cards_count) <= 21)
		{
			std::cout << "Player 2 get next card? (Yes = 1 / No = 0): ";
			std::cin >> get_next_card;

			if (get_next_card == 1)
			{
				player2_cards[player2_cards_count] = cards[head_card_index];
				head_card_index += 1;
				player2_cards_count += 1;

				print_player2_cards_and_summ(player2_cards, player2_cards_count);

				distance_to_win_points_p2 = win_points - player_summ_count(player2_cards, player2_cards_count);
				assert(distance_to_win_points_p2 >= 0);
			}
			else
			{
				is_player_2_ready = true;
				distance_to_win_points_p2 = win_points - player_summ_count(player2_cards, player2_cards_count);
				assert(distance_to_win_points_p2 >= 0);
				cout << "Очков до 21 у Player 2: " << distance_to_win_points_p2 << endl;
			}
		}
		else
		{
			player2_check_and_print_if_lose(player2_cards, player2_cards_count);
		}
	
	} while (is_player_1_ready != true || is_player_2_ready != true);

	//print_next_card(cards, head_card_index);

	player1_check_and_print_if_lose(player1_cards, player1_cards_count);
	player2_check_and_print_if_lose(player2_cards, player2_cards_count);

	if (distance_to_win_points_p1 < distance_to_win_points_p2)
	{
		cout << "Player 1 Win!" << endl;
	}
	else if (distance_to_win_points_p1 > distance_to_win_points_p2)
	{
		cout << "Player 2 Win!" << endl;
	}
	else
	{
		cout << "Nobody Win!" << endl;
	}
}