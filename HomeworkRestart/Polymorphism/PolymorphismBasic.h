#pragma once
#include <iostream>

namespace Polymorphism
{
	class Shape
	{
	private:

	protected:

	public:
		virtual double Area()
		{
			return 0; //реализация по умолчанию. Наследники могут и не переопределять ее реализацию
		}
		virtual ~Shape() = default;
	};

	//Класс, у которого есть чистая функция (=0), называется абстрактным
	class Shape1
	{
	private:

	protected:

	public:
		virtual double Area() = 0; //это называется чистая виртуальная функция - pure virtual function. 
		virtual ~Shape1() = default;
	};


	class Rectangle :public Shape //использует публичное наследование. 
	//Приватные поля базового класса недоступны (всегда).
	//Протектед доступны наследнику, но не торчат наружу. 
	//Паблик доступен наследнику и торчит наружу.
	{
	private:
		int _height = 0;
		int _width = 0;

	protected:

	public:
		
		Rectangle(int height_, int width_)
		{
			_height = height_;
			_width = width_;
		}
		
		double Area()
		{
			return _height * _width;
		}
	};

	class Circle:public Shape //использует публичное наследование. 
	{
	private:
		int _radius = 0;

	protected:

	public:
		Circle(int radius_)
		{
			_radius = radius_;
		}

		double Area()
		{
			return 3.14 * (_radius * _radius);
		}
	};

	class RightTriangle :public Shape
	{
	private:
		int _leg_a = 0;
		int _leg_b = 0;

	protected:

	public:
		RightTriangle(int leg_a_, int leg_b_)
		{
			_leg_a = leg_a_;
			_leg_b = leg_b_;
		}

		double Area()
		{
			return (_leg_a * _leg_b) / 2;
		}
	};

	void A1(Shape& sh) {std::cout << sh.Area() << std::endl;	}
	void A2(Rectangle& rect) {std::cout << rect.Area() << std::endl;	}
	void A3(Circle& circ) {std::cout << circ.Area() << std::endl;	}

	void TestArea(Shape& sh)
	{
		if (sh.Area() > 20)
		{
			std::cout << "Big" << std::endl;
		}
		else
		{
			std::cout << "Small" << std::endl;
		}
	}

	void Test1()
	{
		Shape sh;
		Rectangle rect(10,20);
		Circle circ(1);
		Circle circ1(5);
		RightTriangle rt1(2, 5);

		A1(sh);		   //0
		A1(rect);	   //0
		A1(circ);	   //0
		
		//A2(sh); //не сбилдится
		A2(rect); //сбилдится //200
		//A2(circ); //не сбилдится
		
		//A3(sh); //не сбилдится
		//A3(rect); //не сбилдится
		A3(circ); //сбилдится //3.14

		TestArea(sh);
		TestArea(rect);
		TestArea(circ);

		RightTriangle rt(2, 10);
		A1(rt);
		TestArea(rt);
	}

	void Test2(vector<Shape*> shapes)
	{
		for (Shape* sh : shapes)
		{
			std::cout << sh->Area() << std::endl;
		}
	}

	void Test3()
	{
		Shape sh;
		Rectangle rect1(10, 20);
		Rectangle rect2(20, 20);
		Circle circ1(1);
		Circle circ2(2);
		RightTriangle rt(2, 10);

		vector<Shape*> shapes;
		shapes.push_back(&sh);
		shapes.push_back(&rect1);
		shapes.push_back(&rect2);
		shapes.push_back(&circ1);
		shapes.push_back(&circ2);
		shapes.push_back(&rt);
		
		Test2(shapes);
	}
}