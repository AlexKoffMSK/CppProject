#pragma once
#include <iostream>
using namespace std;


//int - это тип, который говорит о том, что интовый объект - это коробка, в которой хранится целое число
//type_card - это тип, который говорит о том, что объект типа type_card - это коробка, в которой хранится ещё две интовые коробки с именами dignity и suit
struct type_Card //объявляем новый тип данных, собственный.
{
	int _dignity;
	int _suit;
	//переменные внутри структуры назваются поля - поэтому меняем тип наименования для отличия. 
	//Подчеркивание - это условное обозначение что переменная является полем
};


//сгенерировать n-случайных карт, причем карты могут повторяться. 
//храним не так как раньше в одном числе, а теперь двумя разными переменными - две интовые переменные

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
		//в первую очередь cards - это массив, а его элемент это объект - карта, которая хранит в себе два инта. Обращение через точку и имя.
		//генерируем случайное число и записываем его в поле, названное достоинством i-й карты массива карт
		//точка "." это способ обратится к полю структуры
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
		// это способ пробежаться по элементам контейнера (любые сущности хранящие любые элементы любым способом)
		// в случае, когда контейнер является массивом, такая запись является аналогом строк:
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



//написать функцию, которая принимает на вход карту, возвращает тру если карта имеет достоинство валет, дама, король и является черной (трефы,пики)
bool card_is_high_black(int dignity, int suit)
{
	return (dignity > 10 && dignity < 14 && suit > 0 && suit < 3); //вернёт тру или фолз
}


//написать функцию, которая принимает на вход карту, возвращает тру если карта имеет достоинство валет, дама, король и является черной (трефы,пики)
bool card_is_high_black_with_struct(type_Card card)
{
	return (card._dignity > 10 && card._dignity < 14 && card_is_black(card)); //вернёт тру или фолз
}


bool operator==(type_Card cardX, type_Card cardY) 
//создаём пользовательскую функцию, которая будет вызываться когда мы проверяем карта1 == карта2
//функция operator может быть использована только операторов +,-,==-сравнение, <, >, =-присваивание,*,/ и так далее...
//научили сравнивать две карты через создание пользовательской функции сравнения двух карт
{
	return (cardX._dignity == cardY._dignity && cardX._suit == cardY._suit);
}


struct type_poker_player_cards
// пример создания вложенных структур
{
	type_Card _card1; //создали поле, использующее структуру, включующую в себя два значения - достоинство и масть
	type_Card _card2;
	char _playerID; //создали чаровское поле, обозначающее ID игрока
};


//функция для проверки работы структур
void test_struc_func()
{
	int a = 4;
	type_Card cardX={ 10,0 }; //Card1 - объект структуры, инициализируемые значения идут по порядку их объявления, т.е. 10 попадает в поле _dignity , а 0 - в поле _suit

	a = 5;
	cardX._suit=2; //через точку обращаемся к полям внутри структуры

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
	if (cardX == cardY) //знак == когда мы сравниваем две карты - это вызов пользовательской функции сравнения двух карт
	{
		cout << 5 << endl;
	}
	if (operator==(cardX, cardY))
	//более классическое выражение записи использования функции
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


struct type_Rectangle //но не в смысле прямоугольник, а просто - четырёхугольник
{
	type_Point _a;
	type_Point _b;
	type_Point _c;
	type_Point _d;
};

struct type_Rectangle_by_array
{
	type_Point _a[4];
	/* аналог объявления массива записью
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
	static const int n = 10; //когда объявляем константу внутри структуры надо добавить вначале ключевое слово static
	type_Triangle _triangles_1[n];
	type_Triangle _triangles_2[n];
	type_Circle _circles[n];
	type_Rectangle _rectangles[n];
};

void test_shapes()
{
	type_shapes a;
	//третьему треугольнику во втором массиве в точке b установить координаты x=10;y=20;
	a._triangles_2[3]._b._x = 10;
	a._triangles_2[3]._b._y = 20;
	a._triangles_2[3]._b = { 10,20 }; //или такая запись строк выше

	//высести радиус максимального круга
	int maximum_radius = 0;
	for (type_Circle cur_circle : a._circles)
	{
		if (cur_circle._radius > maximum_radius)
		{
			maximum_radius = cur_circle._radius;
		}
	}
	
	//альтернатива в классическом виде
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