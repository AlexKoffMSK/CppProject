#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <climits>
#include <queue>
#include <conio.h>
#include "GameMatrix/GameStructures.h"

//#define __matrix(point) _matrix[p._x][p._y] //макрос по замене имени, по которому обращаться к матрице
//#define ENDL std::endl;
//#define COUT_ENDL std::cout << std::endl;

namespace GameMatrix
{
	class Game
	{
	private:
		std::vector<std::string> _matrix;

		std::map<int, RandomMovingEnemy> _random_moving_enemies;
		
		//int objects_count = 0;

		Player _player;

		bool IsPointInMatrix(Point p)
		{
			return !(p._x < 0 || p._y < 0 || p._x >= _matrix.size() || p._y >= _matrix[0].size());
		}

		bool IsWall(Point p)
		{
			return (_matrix[p._x][p._y] == kWallSymbol);
		}
		
		void MoveEnemies()
		{
			MoveRandomMovingEnemies();
		}

		void MoveRandomMovingEnemies()
		{
			for (auto& [id, enemy] : _random_moving_enemies)
			{
				if (enemy.IncrementTickAndReturnIsActionShouldBe())
				{
					Move(enemy);
				}
			}
		}

		void SetFieldObjectToMatrixAndPrint(FieldObject field_object)
		{
			_matrix[field_object.Position()._x][field_object.Position()._y] = field_object.Symbol();
			field_object.Draw();
		}

		void RemoveFieldObjectFromMatrixAndPrint(FieldObject field_object)
		{
			_matrix[field_object.Position()._x][field_object.Position()._y] = kEmptySymbol;
			Print(field_object.Position(), kEmptySymbol);
		}

		void Move(RandomMovingEnemy& enemy)
		{
			Point new_position = enemy.Position() + kDeltas[rand() % std::size(kDeltas)];
			
			char new_position_symbol = _matrix[new_position._x][new_position._y];

			if (new_position_symbol == kWallSymbol || new_position_symbol == kRandomMovingEnemySymbol)
			{
				return;
			}
			else if (new_position_symbol == kPlayerSymbol)
			{
				exit(0);
			}
			else
			{
				if (new_position_symbol != kEmptySymbol)
				{
					std::cout << "Unrecognised symbol: " << (int) new_position_symbol << std::endl;
					assert(false); //падаем таким образом
				}
			}
			
			RemoveFieldObjectFromMatrixAndPrint(enemy);
			enemy.SetPosition(new_position);
			SetFieldObjectToMatrixAndPrint(enemy);
		}

		void InputFromKeyboard()
		{
			while (true)
			{
				char ch = _getch();

				switch (ch)
				{
				case 'w': _player.SetPositionDelta(kDeltas[3]); break;
				case 'a': _player.SetPositionDelta(kDeltas[1]); break;
				case 'd': _player.SetPositionDelta(kDeltas[0]); break;
				case 's': _player.SetPositionDelta(kDeltas[2]); break;
				}
			}
		}

	public:

		Game(string level_file_name)
		{
			std::ifstream ifs(level_file_name);
			if (!ifs.is_open())
			{
				std::cout << "Fail" << std::endl;
				return;
			}
			
			std::string line;

			int i = 0;

			while (std::getline(ifs, line))
			{
				_matrix.push_back(line);

				for (int j = 0; j < line.size(); j++)
				{

					char ch = _matrix[i][j];
	
					if (ch == kPlayerSymbol)
					{
						_player.SetPosition(Point{ i, j });
					}
					else if (ch == kRandomMovingEnemySymbol)
					{
						Point p{ i,j };
						RandomMovingEnemy enemy(p, kRandomMovingEnemySymbol,Color::Red, rand()%10+5);
						_random_moving_enemies.emplace(enemy.UniqId(), enemy);

						//_random_moving_enemies.emplace(objects_count++, RandomMovingEnemy { Point { i,j } });
					}

					std::cout << _matrix[i][j];
				}
				i++;
				std::cout << std::endl;
			}
		}

		void Run()
		{
			std::thread input_keyboard_thread(&Game::InputFromKeyboard, this);

			while (true)
			{
				MoveEnemies();
				
				Point player_new_position = _player.GetNewPosition();

				if (IsPointInMatrix(player_new_position) && !IsWall(player_new_position))
				{
					if (_matrix[player_new_position._x][player_new_position._y] == kRandomMovingEnemySymbol)
					{
						exit(0);
					}
					
					RemoveFieldObjectFromMatrixAndPrint(_player);
					_player.SetPosition(player_new_position);
					SetFieldObjectToMatrixAndPrint(_player);
				}

				_player.SetPositionDelta(Point{ 0, 0 });

				Console.SetPosition(140, 140);
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}

		void PrintShortPath(Point beg_p, Point end_p)
		{
			_matrix[end_p._x][end_p._y] = kEmptySymbol;
			
			std::system("CLS");

			for (int i = 0; i < _matrix[0].size(); i++)
			{
				for (int j = 0; j < _matrix.size(); j++)
				{
					if (IsWall(Point{ j,i }))
					{
						std::cout << kWallSymbol;
					}
					else
					{
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
			Console.Print(beg_p._x, beg_p._y, kPlayerSymbol, Color::Cyan);

			Console.Print(end_p._x, end_p._y, '&', Color::Green);

			//int weight_matrix[n][n]; поправить потом на новый тип матрицы
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		weight_matrix[i][j] = -1;
			//	}
			//}
			//weight_matrix[beg_p._x][beg_p._y] = 0;

			std::queue<Point> not_visited_points;
			not_visited_points.push(beg_p);
			//[x5][y7]

			//[x5][y6]
			//[x6][y7]
			//[x5][y8]
			//[x4][y7]

			//while (!not_visited_points.empty())
			//{
			//	Point cur_point = not_visited_points.front(); //берем первую точку на очереди для удобства
			//
			//	for (Point delta : kDeltas)
			//	{
			//		Point neighbour_p = cur_point + delta; //координата соседа
			//		if (!IsPointInMatrix(neighbour_p))
			//		{
			//			continue;
			//		}
			//		if (IsWall(neighbour_p))
			//		{
			//			continue;
			//		}
			//		if (weight_matrix[neighbour_p._x][neighbour_p._y] == -1)
			//		{
			//			weight_matrix[neighbour_p._x][neighbour_p._y] = weight_matrix[cur_point._x][cur_point._y] + 1;
			//		}
			//		else
			//		{
			//			continue;
			//		}
			//		not_visited_points.push(neighbour_p);
			//	}
			//	not_visited_points.pop();
			//}

			//std::system("CLS");

			Console.SetPosition(0, 21);

			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		if (IsWall(Point{ j,i }))
			//		{
			//			std::cout << kWallSymbol << kWallSymbol << ' ';
			//		}
			//		else
			//		{
			//			std::cout <<std::setw(2) << weight_matrix[j][i] << ' ';
			//		}
			//	}
			//	std::cout << std::endl;
			//}

			vector<Point> points_of_shortest_path;
			Point cur_pt = end_p;
			
			//while (cur_pt != beg_p)
			//{
			//	points_of_shortest_path.push_back(cur_pt);
			//
			//	bool is_way_found = false;
			//
			//	for (Point delta : kDeltas)
			//	{
			//		Point neighbour_p = cur_pt + delta;
			//		
			//		if (!IsPointInMatrix(neighbour_p))
			//		{
			//			continue;
			//		}
			//
			//		if (weight_matrix[neighbour_p._x][neighbour_p._y] == -1)
			//		{
			//			continue;
			//		}
			//		
			//		if (weight_matrix[neighbour_p._x][neighbour_p._y] < weight_matrix[cur_pt._x][cur_pt._y])
			//		{
			//			cur_pt = neighbour_p;
			//			is_way_found = true;
			//			break;
			//		}
			//	}
			//	if (is_way_found == false)
			//	{
			//		break;
			//	}
			//}

			for (Point a : points_of_shortest_path)
			{
				Console.Print(a._x, a._y, '*', Color::Red);
			}
			Console.Print(end_p._x, end_p._y, '&', Color::Green);
		}

	};

	void Test()
	{
		Game m{ "GameMatrix/Levels/Level1.txt" };
		m.Run();
	}

		//добавить врагов, которые будут сами по себе двигаться
		//добавить телепоры
		//добавить счетчик жизней
		//предметы:
		//	1. Увеличивает счетчик жизней 
		//	2. Останавливает врагов 
		//	3. Убивает случайного врага 
		//добавить врагам скорость
		//добавить врагам логику поиска кратчайшего пути к нам





















}