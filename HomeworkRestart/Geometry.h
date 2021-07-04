#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Geometry
{
	/*
	1. Написать структуру - прямоугольник.
	Поля:
	*. Длина width. (инт) (в метрах)
	*. Высота height. (инт) (в метрах)
	
	Конструкторы:
	*. Без аргументов, пусть создастся прямоугольник со сторонами 10 на 20.
	*. С одним аргументом s. Создается прямоугольник со сторонами s на s.
	*. С двумя параметрами.
	
	Методы:
	*. Возвращает true, если прямоугольник является квадратом.
	*. Возвращает площадь прямоугольника.
	*. Возвращает периметр прямоугольника.
	
	Также научить cout выводить прямоугольник.
	
	Потестить:
	1.1. Создать вектор прямоугольников с рандомными сторонами в диапазоне [1,3]:[1,3].
	1.2. Вывести на экран все прямоугольники.
	1.3. Вывести только квадраты.
	1.4. Вывести только те прямоугольники, площадь которых больше 4.
	1.5. Посчитать сумму периметров всех прямоугольников.
	*/

	struct Rectangle
	{
		int width; //ширина
		int height; //высота

		//----------конструкторы----------
		Rectangle()
		{
			width = 10;
			height = 20;
		}
		Rectangle(int s)
		{
			width = s;
			height = s;
		}
		Rectangle(int width_, int height_)
		{
			width = width_;
			height = height_;
		}
	
		//------------методы--------------
		bool is_rectangle_square()
		{
			return width == height;
		}
		int area_of_rectangle()
		{
			return width * height;
		}
		int perimeter_of_rectangle()
		{
			return 2 * (width + height);
		}
		//делает из прямоугольника квадрат, выбирая меньшую из сторон
		void rect_to_square()
		{
			if (width < height)
			{
				height = width;
			}
			else
			{
				width = height;
			}
		}
	};

	ostream& operator<<(ostream& os, Rectangle r)
	{
		os << "Height: " <<r.height << ", " << "Width: " << r.width;
		return os;
	}





















}