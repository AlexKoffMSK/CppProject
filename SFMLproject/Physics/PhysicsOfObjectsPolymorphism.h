#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
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
		//std::vector<std::unique_ptr<Object>> _objects;
		std::vector<Object*> _objects;

		void MoveObjects()
		{
			for (Object* object : _objects)
			{
				object->MoveByDelta();

				Object* intersectable_object = AreObjectsIntersectsObjects(object);

				if (intersectable_object == nullptr)
				{
					continue;
				}

				object->MoveByReversedDelta();

				if (dynamic_cast<Circle*>(object))
				{
					if (dynamic_cast<Circle*>(intersectable_object))
					{
						//круг наткнулся на круг
						CheckCircleIntersectsCircleAndSetDirection(dynamic_cast<Circle*>(object), dynamic_cast<Circle*>(intersectable_object));
					}
					else if (dynamic_cast<Wall*>(intersectable_object))
					{
						//круг наткнулся на стену
						CheckIntersectionWithWallAndSetDirection(dynamic_cast<Circle*>(object), dynamic_cast<Wall*>(intersectable_object)->_wall_p1, dynamic_cast<Wall*>(intersectable_object)->_wall_p2);
					}
				}
				else if (dynamic_cast<Wall*>(object))
				{
					if (dynamic_cast<Circle*>(intersectable_object))
					{
						//если стена наткнулась на круг
						intersectable_object->_direction_of_move.x = object->_direction_of_move.x*1.5;
						intersectable_object->_direction_of_move.y = object->_direction_of_move.y*1.5;
					}
					else if (dynamic_cast<Wall*>(intersectable_object))
					{
					}
				}

				//object->MoveByDelta();
				//
				//Object* intersectable_object = AreObjectsIntersectsObjects(object);
				//
				//if (intersectable_object == nullptr)
				//{
				//	continue;
				//}

				//CheckIntersectionWithCirclesAndSetDirection(circ);
				
				//for (Wall wall : _walls)
				//{
				//	CheckIntersectionWithWallAndSetDirection(circ, wall._wall_p1, wall._wall_p2);
				//}
				//
				//circ.MoveByDelta();
				//
				//if (IsCircleIntersectAnything(circ))
				//{
				//	circ.MoveByReverseDelta();
				//}
			}
		}

		bool AreObjectsIntersects(Object* object1, Object* object2)
		{
			if (object1 == object2)
			{
				return false;
			}
			if (dynamic_cast<Circle*>(object1))
			{
				if (dynamic_cast<Circle*>(object2))
				{
					return IsCirclesIntersect(dynamic_cast<Circle*>(object1), dynamic_cast<Circle*>(object2));
				}
				else if (dynamic_cast<Wall*>(object2))
				{
					return GeometryFormulas::IsCircleIntersectSegment(object1->CentralPoint(), dynamic_cast<Circle*>(object1)->_circle_shape.getRadius(), dynamic_cast<Wall*>(object2)->_wall_p1, dynamic_cast<Wall*>(object2)->_wall_p2);
				}
			}
			else if (dynamic_cast<Wall*>(object1))
			{
				if (dynamic_cast<Circle*>(object2))
				{
					return GeometryFormulas::IsCircleIntersectSegment(object2->CentralPoint(), dynamic_cast<Circle*>(object2)->_circle_shape.getRadius(), dynamic_cast<Wall*>(object1)->_wall_p1, dynamic_cast<Wall*>(object1)->_wall_p2);
				}
				else if (dynamic_cast<Wall*>(object2))
				{
					return false;
				}
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

		void CheckIntersectionWithWallAndSetDirection(Circle* circ, sf::Vector2f wall_p1, sf::Vector2f wall_p2)
		{
			sf::Vector2f new_position = circ->CentralPoint() + circ->_direction_of_move;

			if (GeometryFormulas::IsCircleIntersectSegment(new_position, circ->_circle_shape.getRadius(), wall_p1, wall_p2))
			{
				circ->_direction_of_move = GetReflectionVector(circ->_circle_shape.getPosition(), new_position, wall_p1, wall_p2);
				//circ->_circle_shape.setFillColor(sf::Color::Green);
			}
			//else
			//{
			//	circ->_circle_shape.setFillColor(sf::Color::Red);
			//}
		}

		void CheckCircleIntersectsCircleAndSetDirection(Circle* circ1, Circle* circ2)
		{
			float t = circ1->_circle_shape.getRadius() / (circ1->_circle_shape.getRadius() + circ2->_circle_shape.getRadius());
			float x0 = circ1->_circle_shape.getPosition().x + t * float(circ2->_circle_shape.getPosition().x - circ1->_circle_shape.getPosition().x);
			float y0 = circ1->_circle_shape.getPosition().y + t * float(circ2->_circle_shape.getPosition().y - circ1->_circle_shape.getPosition().y);
			float a = circ1->_circle_shape.getPosition().y - circ2->_circle_shape.getPosition().y;
			float b = circ2->_circle_shape.getPosition().x - circ1->_circle_shape.getPosition().x;
			
			sf::Vector2f wall_p1(x0 - 2 * a, (y0 - 2 * b));
			sf::Vector2f wall_p2(x0 + 2 * a, (y0 + 2 * b));

			CheckIntersectionWithWallAndSetDirection(circ1, wall_p1, wall_p2);
			CheckIntersectionWithWallAndSetDirection(circ2, wall_p1, wall_p2);

		}

		Object* AreObjectsIntersectsObjects(Object* object)
		{
			
			for (Object* object_inters : _objects)
			{
				if (AreObjectsIntersects(object, object_inters))
				{
					return object_inters;
				}
			}
			return nullptr;
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
			Circle* circle = new Circle( sf::CircleShape(radious),direction_of_move );
			circle->_circle_shape.setPosition(position);

			if (AreObjectsIntersectsObjects(circle) == nullptr)
			{
				circle->_circle_shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 100 + 155));
				_objects.push_back(circle);
			}
		}

		void AddWall(sf::Vector2f wall_p1, sf::Vector2f wall_p2, sf::Vector2f direction_of_move = sf::Vector2f(0,0))
		{
			Wall* new_wall = new Wall(wall_p1, wall_p2);

			if (AreObjectsIntersectsObjects(new_wall) == nullptr)
			{
				new_wall->_direction_of_move = direction_of_move;
				_objects.push_back(new_wall);
			}
		}
		
		void Action()
		{
			MoveObjects();
			//dynamic_cast<Wall*>(_objects[4])->_wall_p2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(dynamic_cast<Wall*>(_objects[4])->_wall_p1, dynamic_cast<Wall*>(_objects[4])->_wall_p2, -0.01);
			//_walls[5]._wall_p2 = GeometryFormulas::RotateSecondPointDependsFirstPoint(_walls[5]._wall_p1, _walls[5]._wall_p2, -0.010);
		}

		void DrawAll(sf::RenderWindow& window)
		{
			for (Object* object : _objects)
			{
				object->Draw(window);
			}
		}
	};




















}