#pragma once
#include <SFML/Graphics.hpp>

namespace GeometryFormulas
{
	double DistanceBetweenTwoPoints(sf::Vector2f point_1, sf::Vector2f point_2)
	{
		return sqrt(pow(point_1.x - point_2.x, 2) + pow(point_1.y - point_2.y, 2));
	}

	double DistanceBetweenPointAndLine(sf::Vector2f p, sf::Vector2f p1, sf::Vector2f p2)
	{
		double num = abs((p2.y - p1.y) * p.x - (p2.x - p1.x) * p.y + p2.x * p1.y - p2.y * p1.x);
		double den = sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
		return num / den;
	}

	bool IsCircleIntersectLine(sf::Vector2f centre_of_circle, double radious, sf::Vector2f p1, sf::Vector2f p2)
	{
		return DistanceBetweenPointAndLine(centre_of_circle, p1, p2) <= radious;

		//const double EPS = 0.0000001;
		//p1 = p1 - centre_of_circle;
		//p2 = p2 - centre_of_circle;
		//double a = p1.y - p2.y;
		//double b = p2.x - p1.y;
		//double c = p1.x * p2.y - p2.x * p1.y;
		//
		//double x0 = -a * c / (a * a + b * b); 
		//double y0 = -b * c / (a * a + b * b);
		//if (c * c > radious * radious * (a * a + b * b) + EPS)
		//{
		//	return false;
		//}
		//else if (abs(c * c - radious * radious * (a * a + b * b)) < EPS) 
		//{
		//	return true;
		//}
		//else 
		//{
		//	double d = radious * radious - c * c / (a * a + b * b);
		//	double mult = sqrt(d / (a * a + b * b));
		//	double ax, ay, bx, by;
		//	ax = x0 + b * mult;
		//	bx = x0 - b * mult;
		//	ay = y0 - a * mult;
		//	by = y0 + a * mult;
		//	return true;
		//}
	}


}