#include <SFML/Graphics.hpp>
#include <iostream>
#include "GeometryFormulas.h"

namespace Physics
{
	const int kWidth = 1024;
	const int kHeight = 768;

	struct Circle
	{
		sf::CircleShape _circle_shape;
		sf::Vector2f _direction_of_move;

		sf::Vector2f CentralPoint()
		{
			return _circle_shape.getPosition();
		}

		sf::Vector2f GetNewPosition()
		{
			return _circle_shape.getPosition() + _direction_of_move;
		}

		sf::CircleShape GetCircleShapeForDraw()
		{
			sf::CircleShape new_circ_shape=_circle_shape;
			
			new_circ_shape.setPosition(_circle_shape.getPosition().x - _circle_shape.getRadius(), kHeight - _circle_shape.getPosition().y - _circle_shape.getRadius());

			return new_circ_shape;
		}

		void MoveByDelta()
		{
			_circle_shape.setPosition(_circle_shape.getPosition() + _direction_of_move);
		}
	};

	bool IsCirclesIntersect(Circle circ1, Circle circ2)
	{
		return GeometryFormulas::DistanceBetweenTwoPoints(circ1.CentralPoint(), circ2.CentralPoint()) < (circ1._circle_shape.getRadius() + circ2._circle_shape.getRadius());
	}









}