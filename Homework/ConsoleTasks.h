#pragma once
//#include <thread>

#include "ConsoleHelper.h"
#include <conio.h>

using namespace std;

void Sleep(int a)
{
	int sum = 0;
	for (int i = 0; i < a * 1000000; i++)
	{
		sum += i;
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void ConsoleTask00()
{
	for (int i = 3; i < 10; i++)
	{
		for (int j = 3; j < 10; j++)
		{
			if (i < j)
			{
			Console.Print(i, j, '*', Color::Red);
			}
		}
	}
}

void ConsoleTask546(int left, int top, int width, int height) //задаю по порядку объявления: ширина, высота, отступ слева, отступ сверху
{
	//for (int offset = 0; offset < width; offset++)
	//{
	//	Console.Print(left + offset, j, '*', Color::Red);
	//}


	
	for (int x = left; x <= (left + width); x++)
	{
		Console.Print(x, top, '*', Color::Red);
		Console.Print(x, top+height, '*', Color::Green);
	}
	for (int y = top; y <= (top + height); y++)
	{
		Console.Print(left, y, '*', Color::Orange);
		Console.Print(left+width, y, '*', Color::Yellow);
	}
}

void ConsoleTask876()
{
	int x = 10;
	int y = 10;
	int new_x = 0;
	int new_y = 0;

	for (int i = 0; i < 1000; i++)
	{
		Sleep(20);

		new_x = x + rand() % 3-1;
		new_y = y + rand() % 3-1;

		Console.PrintInt(100, 50,i);

		if (new_x >= 0 && new_x <= 20 && new_y >= 0 && new_y <= 20)
		{
			Console.Print(x, y, ' ', Color::Cyan);
			x = new_x;
			y = new_y;
			Console.Print(x, y, '*', Color::Cyan);
		}
	}
}

void ConsoleTask432()
{
	//char ch = _getch();

	int x = 10;
	int y = 10;
	int new_x = 0;
	int new_y = 0;

	Console.Print(x, y, '*', Color::Cyan);

	for (int i = 0; i < 1000; i++)
	{
		//Sleep(20);

		char ch = _getch();
	
		switch (ch)
		{
		case 'w': new_x = x + 0; new_y = y - 1; break;
		case 's': new_x = x + 0; new_y = y + 1; break;
		case 'a': new_x = x - 1; new_y = y + 0; break;
		case 'd': new_x = x + 1; new_y = y + 0; break;
		case 27: exit(1);
		}
		//Console.PrintInt(100, 50, i);
		if (new_x >= 0 && new_x <= 20 && new_y >= 0 && new_y <= 20)
		{
			Console.Print(x, y, ' ', Color::Cyan);
			x = new_x;
			y = new_y;
			Console.Print(x, y, '*', Color::Cyan);
		}
	}
}

void ConsoleTask123()
{
	const int n = 80;
	const int m = 20;
	int a[n][m];

	for (int k = 0; k < 100; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = (rand() % 100 <= 10);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//(a[i][j] == 1) ? Console.Print(i, j, '*', Color::Red): Console.Print(i, j, ' ', Color::Red);
				Console.Print(i, j, (a[i][j] == 1) ? '*' : ' ', Color::Red);
			}
		}
	}
}

void ConsoleTask456()
{
	const int n = 80;
	const int m = 20;
	int a[n][m];
	//70% вер ген 0, иначе с 50% 1 или 2
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (rand() % 100 <= 50)
			{
				a[i][j] = 0;
			}
			else if (rand() % 100 <= 50)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 2;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			switch (a[i][j])
			{
			case 0: Console.Print(i, j, ' ', Color::White); break;
			case 1: Console.Print(i, j, '#', Color::Red); break;
			case 2: Console.Print(i, j, '@', Color::Green); break;
			}
		}
	}

	// ============== //
	
	int x = 10;
	int y = 10;
	int new_x = 0;
	int new_y = 0;
	int points_counter = 0;
	
	//a[x][y] = 1;
	a[x][y] = 0;

	Console.Print(x, y, '*', Color::LightCyan);

	for (int i = 0; i < 10000; i++)
	{
		//Sleep(20);

		//Console.PrintInt(81, 0, i);

		char ch = _getch();
		
		switch (ch)
		{
		case 'w': new_x = x + 0; new_y = y - 1; break; //вверх
		case 's': new_x = x + 0; new_y = y + 1; break; //вниз
		case 'a': new_x = x - 1; new_y = y + 0; break; //влево
		case 'd': new_x = x + 1; new_y = y + 0; break; //вправо
		case 27: exit(1);
		}
		
		//new_x = std::rand() % 3 - 1 + x;
		//new_y = std::rand() % 3 - 1 + y;

		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] != 1)
		{
			Console.Print(x, y, ' ', Color::LightCyan);
			x = new_x;
			y = new_y;
			Console.Print(x, y, '*', Color::LightCyan);
			if (a[new_x][new_y] == 2)
			{
				points_counter++;
				a[new_x][new_y] = 0;
			}
			Console.PrintInt(80, 0, points_counter);
		}
	}
}

void ConsoleTask567()
{
	const int n = 80;
	const int m = 20;
	int a[n][m];

	//70% вер ген 0, иначе с 50% 1 или 2
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (rand() % 100 <= 80)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			switch (a[i][j])
			{
			case 0: Console.Print(i, j, ' ', Color::White); break;
			case 1: Console.Print(i, j, '#', Color::Red); break;
			}
		}
	}

	// ============== //

	int x = n/3.;
	int y = m/2.;
	int new_x = 0;
	int new_y = 0;
	a[x][y] = 0;
	
	Console.Print(x, y, '*', Color::LightCyan);

	int pos_enemy_x = n*2./3.;
	int pos_enemy_y = m/2.;
	int new_pos_enemy_x = 0;
	int new_pos_enemy_y = 0;
	a[pos_enemy_x][pos_enemy_y] = 0;
	Console.Print(pos_enemy_x, pos_enemy_y, '@', Color::Orange);

	for (;;) //бесконечный цикл
	{
		//Sleep(20);

		//Console.PrintInt(81, 0, i);

		char ch = _getch();

		switch (ch)
		{
		case 'w': new_x = x + 0; new_y = y - 1; break; //вверх
		case 's': new_x = x + 0; new_y = y + 1; break; //вниз
		case 'a': new_x = x - 1; new_y = y + 0; break; //влево
		case 'd': new_x = x + 1; new_y = y + 0; break; //вправо
		case 27: exit(1);
		}

		//new_x = std::rand() % 3 - 1 + x;
		//new_y = std::rand() % 3 - 1 + y;

		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] != 1)
		{
			Console.Print(x, y, ' ', Color::LightCyan);
			x = new_x;
			y = new_y;
			Console.Print(x, y, '*', Color::LightCyan);
		}

		//new_pos_enemy_x = pos_enemy_x + (rand() % 3 - 1);
		//new_pos_enemy_y = pos_enemy_y + (rand() % 3 - 1);

		if (new_x < pos_enemy_x)
		{
			new_pos_enemy_x = pos_enemy_x - 1;
		}
		else if (new_x > pos_enemy_x)
		{
			new_pos_enemy_x = pos_enemy_x + 1;
		}
		else
		{
			new_pos_enemy_x = pos_enemy_x;
		}
		if (new_y < pos_enemy_y)
		{
			new_pos_enemy_y = pos_enemy_y - 1;
		}
		else if (new_y > pos_enemy_y)
		{
			new_pos_enemy_y = pos_enemy_y + 1;
		}
		else
		{
			new_pos_enemy_y = pos_enemy_y;
		}


		if (new_pos_enemy_x >= 0 && new_pos_enemy_x < n && new_pos_enemy_y >= 0 && new_pos_enemy_y < m && a[new_pos_enemy_x][new_pos_enemy_y] != 1)
		{
			Console.Print(pos_enemy_x, pos_enemy_y, ' ', Color::Orange);
			pos_enemy_x = new_pos_enemy_x;
			pos_enemy_y = new_pos_enemy_y;
			Console.Print(new_pos_enemy_x, new_pos_enemy_y, '@', Color::Orange);
		}
		
		
		if (x == pos_enemy_x && y == pos_enemy_y)
		{
			break;
		}
	}
	cout << "You lose!" << endl;
	_getch();
}

void ConsoleTask343() //dogs are hunting
{
	const int n = 80;
	const int m = 20;
	int a[n][m];
	int eaten_food_count = 0;
	const int eaten_food_count_win = 10;

	//70% вер ген 0, иначе с 50% 1 или 2
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (rand() % 100 <= 90)
			{
				a[i][j] = 0;
			}
			else if (rand() % 100 <= 70)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			switch (a[i][j])
			{
			case 0: Console.Print(i, j, ' ', Color::White); break;
			case 1: Console.Print(i, j, '#', Color::Red); break;
			case 3: Console.Print(i, j, '&', Color::Green); break;
			}
		}
	}

	// ============== //

	const int enemies_count = 4;

	int x = n / 3.;
	int y = m / 2.;
	int new_x = 0;
	int new_y = 0;
	a[x][y] = 0;

	Console.Print(x, y, '*', Color::LightCyan);

	int pos_enemy_x[enemies_count];// = n * 2. / 3.;
	int pos_enemy_y[enemies_count];// = m / 2.;

	for (int i = 0; i < enemies_count; i++)
	{
		pos_enemy_x[i] = n * 2. / 3.;
		pos_enemy_y[i] = m/enemies_count*i;
		a[pos_enemy_x[i]][pos_enemy_y[i]] = 2;
		Console.Print(pos_enemy_x[i], pos_enemy_y[i], '@', Color::Orange);
	}

	int new_pos_enemy_x = 0;
	int new_pos_enemy_y = 0;
	
	for (;;) //бесконечный цикл
	{
		//Sleep(20);

		//Console.PrintInt(81, 0, i);

		char ch = _getch();

		switch (ch)
		{
		case 'w': new_x = x + 0; new_y = y - 1; break; //вверх
		case 's': new_x = x + 0; new_y = y + 1; break; //вниз
		case 'a': new_x = x - 1; new_y = y + 0; break; //влево
		case 'd': new_x = x + 1; new_y = y + 0; break; //вправо
		case 27: exit(1);
		}

		//new_x = std::rand() % 3 - 1 + x;
		//new_y = std::rand() % 3 - 1 + y;

		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] != 1)
		{
			Console.Print(x, y, ' ', Color::LightCyan);
			x = new_x;
			y = new_y;
			Console.Print(x, y, '*', Color::LightCyan);
		}
		
		if (a[x][y] == 3)
		{
			eaten_food_count++;
			Console.PrintInt(n + 1, 0, eaten_food_count);
			if (eaten_food_count == eaten_food_count_win)
			{
				cout << "You win!" << endl;
				_getch();
				exit(1);
			}
		}
		
		//else
		//{
		//	continue;
		//}

		//new_pos_enemy_x = pos_enemy_x + (rand() % 3 - 1);
		//new_pos_enemy_y = pos_enemy_y + (rand() % 3 - 1);

		for (int i =0; i<enemies_count; i++)
		{
			if (new_x < pos_enemy_x[i])
			{
				new_pos_enemy_x = pos_enemy_x[i] - 1;
			}
			else if (new_x > pos_enemy_x[i])
			{
				new_pos_enemy_x = pos_enemy_x[i] + 1;
			}
			else
			{
				new_pos_enemy_x = pos_enemy_x[i];
			}
			if (new_y < pos_enemy_y[i])
			{
				new_pos_enemy_y = pos_enemy_y[i] - 1;
			}
			else if (new_y > pos_enemy_y[i])
			{
				new_pos_enemy_y = pos_enemy_y[i] + 1;
			}
			else
			{
				new_pos_enemy_y = pos_enemy_y[i];
			}

			if (new_pos_enemy_x >= 0 && new_pos_enemy_x < n && new_pos_enemy_y >= 0 && new_pos_enemy_y < m && a[new_pos_enemy_x][new_pos_enemy_y] == 0)
			{
				Console.Print(pos_enemy_x[i], pos_enemy_y[i], ' ', Color::Orange);
				a[pos_enemy_x[i]][pos_enemy_y[i]] = 0;
				pos_enemy_x[i] = new_pos_enemy_x;
				pos_enemy_y[i] = new_pos_enemy_y;
				a[pos_enemy_x[i]][pos_enemy_y[i]] = 2;
				Console.Print(new_pos_enemy_x, new_pos_enemy_y, '@', Color::Orange);
			}

			if (x == pos_enemy_x[i] && y == pos_enemy_y[i])
			{
				cout << "You lose!" << endl;
				_getch();
				exit(1);
			}
		}
	}
	
}

void TestCharMatrix()
{
	const int n = 3;
	const int m = 3;
	
	char a[n][m];

	char int_to_char[] = { '_', 'X', '0' };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = int_to_char[0];
			//a[i][j] = int_to_char[rand() % 3];

			Console.Print(i, j, a[i][j], Color::Green);
		}
	}

	int x;
	int y;

	cin >> x >> y; // Человек указывает координаты куда поставить крестик

	/*
	1. Сгенерировалои поле из пробелов
	2. Спросили у человека куда поставить крестик
	3. По этим координатам(x,y, которые ввел человек до этого) в массив записать Х
	4. Сгенерировать рандомно координаты куда комп поставит 0.
	5. Проверить что по этиой координате в массиве стоит пробел
	6. Если в этой ячейке не пробел, то идем к пунку 4. (Генерируем до тех пор, пока не сгенерируем коодинату в которй стоит пробел)
	7. (Если в этой ячейке пробел) заполняем матрицу по сгенерированной координате '0'
	8. Проверим что кто-то выиграл (анписать функцию, которая принимает матрицу 3х3 и возвращает 0, если никто не выиграл, 1 если Х выиграл, -1 если 0)
	8. Если никто не выиграл то. вернуться к пунку 2. 
	9. Печатаем результат


	*/

	_getch();
}

void ConsoleTask876(int left, int top, int size) //задаю по порядку объявления: отступ слева, отступ сверху, ширина, высота
//Например: (3,3, 7, 7). (3,3) - координаты левой верхней звездочки
{
	int temp_top_x = top;
	int temp_top_y = top;

	//
	//for (int x = left; x <= (left + width); x++)
	//{
	//	Console.Print(x, temp_top_x++, '*', Color::Red);
	//}
	//for (int z = left; z <= (left + width); z++)
	//{
	//	Console.Print(z, (temp_top_y+height), '*', Color::Green);
	//	height--;
	//}

	//for (int offset = 0; offset < size; offset++)
	//{
	//	Console.Print(left+offset, top + offset, '*',Color::Red);
	//}
	//
	//for (int offset = 0; offset < size; offset++)
	//{
	//	Console.Print(left + offset, (top + size - 1) - offset, '*', Color::Red); //складывать координаты и длину с учётом того, что длина в целых числах от 1, а координаты от нуля как массив
	//}


	for (int offset = 0; offset < size; offset++)
	{
		Console.Print(left + offset, top + offset, '*', Color::Red);
		
		Console.Print(left + offset, (top + size - 1) - offset, '*', Color::Red);
		
		Console.Print(left + offset, top+size/2, '*', Color::Red);
		
		Console.Print(left + size / 2, top+ offset, '*', Color::Red); 
		
		Console.Print(left + offset, top, '*', Color::Red);
		
		Console.Print(left + offset, top+size-1, '*', Color::Red);
		
		Console.Print(left, top+offset, '*', Color::Red);
		
		Console.Print(left+size-1, top+offset, '*', Color::Red);
	}

	_getch();
}

void ConsoleTask987(int left, int top, int width, int height)
/*
2. Написать функцию, которая принимает(left, top, width, heigth) и рисует букву Б.
Например: (5,6,17,9).
*******
*
*
*
*
*******
*     *
*     *
*     *
*******
А - X:left,			Y:top
B - X:left+width,	Y:top
C - X:left			Y:top+height/2
D - X:left+width	Y:top+height/2
E - X:left			Y:top+height
F - X:left+width	Y:top+height
*/
{
	for (int y = top; y < (top+height); y++) //отрисовка вертикальных линий
	{
		Console.Print(left, y, '*', Color::Green);
	}

	for (int y = (top + height / 2 /*+ height % 2*/); y < (top+height); y++) //отрисовка вертикальных линий
	{
		Console.Print(left + width - 1, y, '*', Color::LightBlue);
	}

	for (int x = left; x < (left + width); x++) 
	{
		Console.Print(x, top, '*', Color::Red);
		Console.Print(x, top+height/2, '*', Color::Red);
		Console.Print(x, top+height, '*', Color::Red);
	}
	_getch();
}

void ConsoleTask(int left, int top, int a)
//3. Написать функцию, которая принимает(x, y, a) и рисует линию длины а, верхняя координата которой(x, y).
//Например: (10, 9, 4).
//* < -(координата этой точки 10, 9)
//	*
//	*
//	*
{
	for (int z = 0; z < a; z++)
	{
		Console.Print(left, top + z, '*', Color::Red);
	}
}

/*

4. Написать функцию, которая принимает массив и его размер рисует его по типу гистограммы
Например : {1, 4, 3, 5, 6, 2}
******
 *****
 ****
 * **
   **
	*


5. Всунуть печать такого массива в итерацию пузырьковой сортировки, с задержкой.

*/