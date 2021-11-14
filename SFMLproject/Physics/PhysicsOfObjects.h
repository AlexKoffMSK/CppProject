#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objects.h"

namespace Physics
{
	const sf::Vector2f kLeftUpBound(0, kHeight);
	const sf::Vector2f kRightUpBound(kWidth, kHeight);
	const sf::Vector2f kLeftBottomBound(0, 0);
	const sf::Vector2f kRightBottomBound(kWidth, 0);
	
	class PhysicsOfObjects
	{
	private:
		std::vector<Circle> _circles;

		int IndexOfIntersectableCircle(Circle circ)
		{
			for (int i = 0; i < _circles.size(); ++i)
			{
				if (IsCirclesIntersect(circ, _circles[i]))
				{
					return i;
				}
			}
			return -1;
		}

		void MoveCircles()
		{
			for (Circle& circ : _circles)
			{
				//получаем новую позицию нашего круга
				sf::Vector2f circ_center_new_pos = circ.GetNewPosition();
				//проверяем не пересекает ли она все четыре стены. 
				if (GeometryFormulas::IsCircleIntersectLine(circ_center_new_pos,circ._circle_shape.getRadius(),kLeftUpBound,kRightUpBound) ||
				    GeometryFormulas::IsCircleIntersectLine(circ_center_new_pos,circ._circle_shape.getRadius(),kLeftUpBound,kLeftBottomBound) ||
				    GeometryFormulas::IsCircleIntersectLine(circ_center_new_pos, circ._circle_shape.getRadius(), kRightUpBound, kRightBottomBound) ||
				    GeometryFormulas::IsCircleIntersectLine(circ_center_new_pos, circ._circle_shape.getRadius(), kLeftBottomBound, kRightBottomBound))
				{
					//Если пересекает - останавливаем круг, 
					circ._direction_of_move.x = 0;
					circ._direction_of_move.y = 0;
				}
				else
				{
				//если нет - двигаем круг
					circ.MoveByDelta();
				}
			}
		}

	public:
		void AddCircle(sf::Vector2f position, double radious, sf::Vector2f direction_of_move)
		{
			Circle circle{ sf::CircleShape(radious),direction_of_move };
			circle._circle_shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 100+155));
			circle._circle_shape.setPosition(position);
			if (IndexOfIntersectableCircle(circle) == -1)
			{
				_circles.push_back(circle);
			}
		}
		
		//void RemoveCircle()

		sf::CircleShape GetCircleShapeForDraw(int index_of_circle)
		{
			return _circles[index_of_circle].GetCircleShapeForDraw();
		}

		int GetCirclesCount()
		{
			return _circles.size();
		}

		void Action()
		{
			MoveCircles();
		}

		void SetCirclePosition(int index_of_circle, sf::Vector2f new_position)
		{
			_circles[index_of_circle]._circle_shape.setPosition(new_position);
		}
	};




















}