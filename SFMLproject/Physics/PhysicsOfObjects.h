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

		std::vector<Wall> _walls;

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
				for (Wall wall : _walls)
				{
					CheckIntersectionAndSetDirection(circ, wall._wall_p1, wall._wall_p2);
				}
				circ.MoveByDelta();
			}
		}

		sf::Vector2f GetReflectionVector(sf::Vector2f q1, sf::Vector2f q2, sf::Vector2f p1, sf::Vector2f p2)
		{
			sf::Vector2f intersection_point = GeometryFormulas::PointOfIntersectofTwoLines(p1, p2, q1, q2);

			sf::Vector2f point_of_perpend = GeometryFormulas::GetPerpendicular(p1,p2, q1);

			double angle = GeometryFormulas::GetAngleBetweenLines(p1, p2, q1, q2);
			double angle_ro_rotate = -2 * angle;

			sf::Vector2f point_after_rotate_1 = GeometryFormulas::RotateSecondPointDependsFirstPoint(intersection_point, intersection_point + q2 - q1, angle_ro_rotate);
			sf::Vector2f point_after_rotate_2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(intersection_point, intersection_point + q2 - q1, -angle_ro_rotate);

			double d0 = GeometryFormulas::GetPointPositionDependsOfLine(q1, q2, point_of_perpend);
			double d1 = GeometryFormulas::GetPointPositionDependsOfLine(q1, q2, point_after_rotate_1);
			double d2 = GeometryFormulas::GetPointPositionDependsOfLine(q1, q2, point_after_rotate_2);

			if (d0 * d1 < 0)
			{
				return point_after_rotate_1 - intersection_point;
			}
			else
			{
				return point_after_rotate_2 - intersection_point;
			}
		}

		void CheckIntersectionAndSetDirection(Circle& circ, sf::Vector2f wall_p1, sf::Vector2f wall_p2)
		{
			sf::Vector2f circ_center_new_pos = circ.GetNewPosition();

			if (GeometryFormulas::IsCircleIntersectLine(circ_center_new_pos, circ._circle_shape.getRadius(), wall_p1, wall_p2))
			{
				circ._direction_of_move = GetReflectionVector(circ._circle_shape.getPosition(), circ_center_new_pos, wall_p1, wall_p2);
			}
		}

	public:

		PhysicsOfObjects()
		{
			AddWall(kLeftUpBound, kRightUpBound);
			AddWall(kRightUpBound, kRightBottomBound);
			AddWall(kRightBottomBound, kLeftBottomBound);
			AddWall(kLeftBottomBound, kLeftUpBound);
		}

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

		void AddWall(sf::Vector2f wall_p1, sf::Vector2f wall_p2)
		{
			_walls.push_back(Wall{ wall_p1, wall_p2 });
		}
		
		//void RemoveCircle()

		sf::CircleShape GetCircleShapeForDraw(int index_of_circle)
		{
			return _circles[index_of_circle].GetCircleShapeForDraw();
		}

		sf::VertexArray GetWallShapeForDraw(int index_of_wall)
		{
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position.x = _walls[index_of_wall]._wall_p1.x;
			line[0].position.y = kHeight - _walls[index_of_wall]._wall_p1.y;

			line[1].position.x = _walls[index_of_wall]._wall_p2.x;
			line[1].position.y = kHeight - _walls[index_of_wall]._wall_p2.y;

			return line;
		}

		int GetCirclesCount()
		{
			return _circles.size();
		}

		int GetWallCount()
		{
			return _walls.size();
		}

		void Action()
		{
			MoveCircles();
			_walls[4]._wall_p2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(_walls[4]._wall_p1, _walls[4]._wall_p2, 0.01);
		}

		void SetCirclePosition(int index_of_circle, sf::Vector2f new_position)
		{
			_circles[index_of_circle]._circle_shape.setPosition(new_position);
		}
	};




















}