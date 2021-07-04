#pragma once
#include <iostream>
#include <cassert>
#include "canon_card_decomposition.h"
#include "card_convertation.h"

using namespace std;

/*
	1. Дописать функции конвертации
	2. Сделать рефактор PrintCardNameInterpretedFromNumber
	3. Сделать рефактор Compare2CardsByDignity
	4. Сделать рефактор Compare2CardsBySuitsAndDignitiesWithTrump
	5. Перекделать dignity в int_dignity (suit)
	6. Унифицировать единообразное название функций from, to, и т.д.
	7. дополнять список конвертаций названиями функций конвертаций
*/

/*
На всякий случай, зафиксирую сущности, которые у нас есть:
1. (canon_card)				Каноничная запись карты. Это интовское число, например 121. 
2. (int_dignity,int_suit)	Интовая запись карты. Это 2 интовких числа, например 12 1. 
3. (char_dignity,char_suit)	Чаровская запись карты. Это 2 чаровских переменных. Q p  
4. int_dignity				Достоинство. (Предлагаю по умолчабнию считать, что достоинство, это инт). Это интовая переменная, принимающая значания [2,14]
5. char_dignity				Чаровское достоинство. Это чаровская переменная, принимающая {'2','3','4',...,'Z','J','Q','K','A'}
6. int_suit					Масть. (По аналогии с достоинством, это инт). Это интовая переменная, принимающая [0,3]
7. char_suit				Чаровская масть. Чаровская переменная, принимающая {'b','p','t','c'}*/

/* Convertation:
принцип наименования для конвертирования:ЧТО - во ЧТО, поэтому TO
принцип наименования для вытаскивания:ЧТО-ТО - из ЧЕГО-ТО, поэтому FROM
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
// Функция принимает массив карт и заполняет его картами по возрастанию
{
	const int dmin = 2; //минимальное достоинство - минимальная карта в колоде двойка
	const int dmax = dmin + size(dignities) - 1; //максимальное достоинство - при этом, с 2 до 10 это числовые карты, 11 - Валет, 12 - Дама, 13 - Король, 14 - Туз
	int k = 0; //индекс массива а для заполнения его картами
	
	// 2 3 4 5 6  7 8 9 10 11  12 13 14 15
	// 0 1 2 3
	// 56 действий при размере массива 52, на 4 вышли за границы
	for (int i = dmin; i <= dmax; i++) //цикл для заполнения массива - колодой карт, в части - достоинств
	{
		for (int j = 0; j < size(suits); j++) //цикл для заполнения массива карт с заполненными достоинствами - мастями
		{
			canon_cards[k] = convert_int_dignity_and_int_suit_to_canon_card(i, j); //присвоение текущей карте значений достоинств и мастей
			k++; //переход к следующей карте путём перехода к следующему индексу массива
		}
	}
}

void canon_cards_mixing(int* canon_cards, int n)
// Функция перемешивает массив из карт
{
	int peremesh = 10000; //количество раз перемешиваний колоды (10000 * 52)
	int PervayaKartaDlyaPeremesh = 0; //индекс какой-то карты в колоде для обмена значением с другой картой
	int VtorayaKartaDlyaPeremesh = 0; //индекс какой-то другой карты для обмена значением с первой-попавшейся картой
	int ObmennayaPeremennaya = 0;//временная переменная для обмена значений карт

	for (int i = 0; i <= peremesh; i++)//цикл для заполнения массива - колоды карт
	{
		PervayaKartaDlyaPeremesh = rand() % n; //берём наугад индекс какой-то рандомной карты 
		VtorayaKartaDlyaPeremesh = rand() % n; //берём наугад индекс какой-то другой карты
		ObmennayaPeremennaya = canon_cards[PervayaKartaDlyaPeremesh];//присваиваем временной переменной значение из массива-колоды, соответствующее индексу, подобранному рандомно
		canon_cards[PervayaKartaDlyaPeremesh] = canon_cards[VtorayaKartaDlyaPeremesh];//присваиваем значению первой рандомной карты в массиве-колоде - значение другой рандомно-выбранной карты
		canon_cards[VtorayaKartaDlyaPeremesh] = ObmennayaPeremennaya;//присваиваем значению второй рандомно-подобранной карты - значение из временной переменной, куда мы положили значение первой карты до обмена
	}
}



void print_char_card_from_canon_card(int canon_card)
// Функция принимает на вход 1 карту и печатает её в интерпретированном виде
{
	// cout << f_1_5(card) << ' ' << f_1_7(card); //после того как сделаю все функции конвертации, можно переделать эту функцию через использование функций конвертации

	assert(get_int_suit_from_canon_card(canon_card) >= 0 && get_int_suit_from_canon_card(canon_card) <= 3); //ожидает, что последняя цифра переменной card будет находиться в жестком диапазоне от 0 до 3 включительно, иначе вызывает ошибку и останаливает выполнение программы
	
	//char dignities[] = { '2', '3', '4' ,'5','6','7','8','9','Z','J','Q','K','A' };
	////создаём массив символов-достоинств [0,12] - для вывода на экран читабельных значений карт, при этом! 
	////Так как используем функцию char, которая оперирует только одним символом, необходимо для достоинства 10 прописать исключение!

	/*const char* dostoinstva[] = { "2", "3", "4" ,"5","6","7","8","9","10","J","Q","K","A"};
	это вариант использования функции char для строки (string, не line), т.е. это не про целую строку отведённую в выводе под эти символы*/
	  
	//setw(2) -говорит, что под следующий вывод надо выделить 2 ячейки в терминале. 
	if (get_int_dignity_from_canon_card(canon_card) == 10) //прописываем исключение для вывода достоинства карты 10, т.к. char оперирует только одним символом
	{
		cout << setw(2) << 10 ; //выводим char-овские массивы на экран (при условии что среди карт попалась 10)
	}
	else
	{
		cout << setw(2) << get_char_dignity_from_canon_card(canon_card); //выводим char-овские массивы на экран (при условии что не попалась 10), при этом:
	//минус 2 добавлено для того, чтобы не выходить за границы чаровского массива. При этом, работает это так:
	//если [a[i] / 10 даёт номинал карты 2, то если не написать -2 он обратится ко второму индексу (3 ячейка) массива, т.е. 4
	//а если будет туз - 14 - он выйдет за границы чаровского массива.
	}

	//(cond) ? (act1) : (act2)

	//cout << ((get_int_dignity_from_canon_card(canon_card) == 10) ? 10 : get_char_dignity_from_canon_card(canon_card)); //тернарник в cout надо обрамлять скобками!
	cout << get_char_suit_from_canon_card(canon_card);

}

void print_canon_cards_array_and_char_cards_arrayOptional(int* canon_cards, int n)
// Функция принимает на вход массив карт и печатает его в неинтерпретированном виде
{
	for (int i = 0; i < n; i++)
	{
		cout << canon_cards[i] << " - ";
		print_char_card_from_canon_card(canon_cards[i]);
		cout << endl;
	}
}



int compare_2_canon_cards_by_dignity(int canon_card1, int canon_card2)
// Функция принимает на вход 2 карты и возвращает:
// -1, если первая карта меньше второй
//  0, если они равны
//  1, если первая карта больше второй
// отрицательное число, если первая карта меньше второй - код под комментом
//  0, если они равны - код под комментом
// положительное число, если первая карта больше второй - код под комментом
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
// Функция принимает на вход 2 карты, козырь и возвращает:
// -1, если первая карта меньше второй
// 0, если они равны
// 1, если первая карта больше второй
{
	if (get_int_suit_from_canon_card(canon_card1) == int_trump && get_int_suit_from_canon_card(canon_card2) != int_trump)
	{
		return 1;
	}
	else if (get_int_suit_from_canon_card(canon_card1) != int_trump && get_int_suit_from_canon_card(canon_card2) == int_trump)
	{
		return -1;
	}
	else // Либо обе карты козыри, либо никто из них не козырь
	{
		return compare_2_canon_cards_by_dignity(canon_card1, canon_card2); //возвращает тот интовый результат, который получится после выполнения функции
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