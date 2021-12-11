#include <SFML/Graphics.hpp>
#include <iostream>
#include "GeometryFormulas.h"

namespace Physics
{
	const int kWidth = 1024;
	const int kHeight = 768;

	struct Object
	{
		sf::Vector2f _direction_of_move;

		virtual sf::Vector2f CentralPoint() = 0;

		virtual void Draw(sf::RenderWindow& window) = 0;

		virtual void MoveByDelta() = 0;

		virtual void MoveByReversedDelta() = 0;
	};
	
	struct Circle : public Object
	{
		sf::CircleShape _circle_shape;

		sf::Vector2f CentralPoint() override
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

		void MoveByDelta() override
		{
			_circle_shape.setPosition(_circle_shape.getPosition() + _direction_of_move);
		}

		void MoveByReversedDelta() override
		{
			_circle_shape.setPosition(_circle_shape.getPosition() - _direction_of_move);
		}

		void Draw(sf::RenderWindow& window) override
		{
			window.draw(GetCircleShapeForDraw());
		}

		Circle(sf::CircleShape circle_shape_, sf::Vector2f direction_of_move_)
		{
			_circle_shape = circle_shape_;
			_direction_of_move = direction_of_move_;
		}
	};

	struct Wall : public Object
	{
		sf::Vector2f _wall_p1;
		sf::Vector2f _wall_p2;

		sf::Vector2f CentralPoint() override
		{
			return sf::Vector2f((_wall_p1.x + _wall_p2.x)/2, (_wall_p1.y + _wall_p2.y) / 2);
		}

		void Draw(sf::RenderWindow& window) override
		{
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position.x = _wall_p1.x;
			line[0].position.y = kHeight - _wall_p1.y;

			line[1].position.x = _wall_p2.x;
			line[1].position.y = kHeight - _wall_p2.y;

			window.draw(line);
		}

		void MoveByDelta() override
		{
			_wall_p1 = _wall_p1 + _direction_of_move;
			_wall_p2 = _wall_p2 + _direction_of_move;
			//_wall_p2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(_wall_p1, _wall_p2, -0.01);

		}

		void MoveByReversedDelta() override
		{
			_wall_p1 = _wall_p1 - _direction_of_move;
			_wall_p2 = _wall_p2 - _direction_of_move;
			//_wall_p2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(_wall_p1, _wall_p2, +0.01);

		}

		Wall(sf::Vector2f wall_p1_, sf::Vector2f wall_p2_)
		{
			_wall_p1 = wall_p1_;
			_wall_p2 = wall_p2_;
		}

	};

	bool IsCirclesIntersect(Circle* circ1, Circle* circ2)
	{
		return GeometryFormulas::DistanceBetweenTwoPoints(circ1->CentralPoint(), circ2->CentralPoint()) < (circ1->_circle_shape.getRadius() + circ2->_circle_shape.getRadius());
	}
}