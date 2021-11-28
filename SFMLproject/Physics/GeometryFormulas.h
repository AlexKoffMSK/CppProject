#pragma once
#include <SFML/Graphics.hpp>

namespace GeometryFormulas
{
	const double kEps = 0.0000001;
	
	const double kPi = acos(-1);

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
		//double b = p2.x - p1.x;
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

	double GetAngleBetweenLines(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q1, sf::Vector2f q2)
	{
		double ap = p1.y - p2.y;
		double bp = p2.x - p1.x;
		double aq = q1.y - q2.y;
		double bq = q2.x - q1.x;
		
		double num = abs(ap * aq + bp * bq);
		double den = sqrt(ap * ap + bp * bp) * sqrt(aq * aq + bq * bq);

		return acos(num / den);
	}

	double RadiansToDegrees(double radians)
	{
		return radians * 180 / kPi;
	}

	sf::Vector2f Rotate(sf::Vector2f v, double angle)
	{
		return sf::Vector2f(v.x * cos(angle) - v.y * sin(angle), v.y * cos(angle) + v.x * sin(angle));
	}

	sf::Vector2f PointOfIntersectofTwoLines(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q1, sf::Vector2f q2)
	{
		double ap = p1.y - p2.y;
		double bp = p2.x - p1.x;
		double aq = q1.y - q2.y;
		double bq = q2.x - q1.x;
		double cp = p1.x * p2.y - p2.x * p1.y;
		double cq = q1.x * q2.y - q2.x * q1.y;

		double y = ((cq * ap) / aq - cp) / ((-bq * ap) / aq + bp);
		double x = (-cq - bq * y) / aq;

		//x = (bq * cp - bp * cq) / (aq * bp - ap * bq);
		//y = (ap*cq - aq * cp) / (aq * bp - ap * bq);

		return sf::Vector2f(x, y);
	}

	double GetPointPositionDependsOfLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q)
	{
		double a = p1.y - p2.y;
		double b = p2.x - p1.x;
		double c = p1.x * p2.y - p2.x * p1.y;

		double res = a * q.x + b * q.y + c;

		return res;
	}

	sf::Vector2f RotateSecondPointDependsFirstPoint(sf::Vector2f p, sf::Vector2f q, double angle)
	{
		sf::Vector2f trans_q = q-p; //сдвинули р в начало координат
		sf::Vector2f rotated_q = Rotate(trans_q, angle);
		sf::Vector2f result_q = rotated_q + p;
		return result_q;
	}

	sf::Vector2f GetPerpendicular(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q)
	{
		double x1 = p1.x;
		double x2 = p2.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double x3 = q.x;
		double y3 = q.y;
		double k = ((y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1)) / (pow((y2 - y1), 2) + pow((x2 - x1), 2));
		double x4 = x3 - k * (y2 - y1);
		double y4 = y3 + k * (x2 - x1);
		return sf::Vector2f(x4, y4);
	}

	bool IsPointOnSegment(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f q)
	{
		if (p2.x == p1.x)
		{
			double t = (q.y - p1.y) / (p2.y - p1.y);
			return (t >= 0 && t <= 1);
		}
		if (p2.y == p1.y)
		{
			double t = (q.x - p1.x) / (p2.x - p1.x);
			return (t >= 0 && t <= 1);
		}
		
		double t1 = (q.x - p1.x) / (p2.x - p1.x);
		double t2 = (q.y - p1.y) / (p2.y - p1.y);

		//std::cout << t1 << ' ' << t2 << ' ' << q.x << '/' << q.y << std::endl;

		if (abs(t2 - t1) > kEps)
		{
			return false;
		}

		//return (abs(t2 - t1) <= kEps && (t1 >= 0 && t1 <= 1));

		return (t1 >= 0 && t1 <= 1);
	}

	bool IsCircleIntersectSegment(sf::Vector2f centre_of_circle, double radious, sf::Vector2f p1, sf::Vector2f p2)
	{
		p1 = p1 - centre_of_circle;
		p2 = p2 - centre_of_circle;
		double a = p1.y - p2.y;
		double b = p2.x - p1.x;
		double c = p1.x * p2.y - p2.x * p1.y;
		
		double x0 = -a * c / (a * a + b * b); 
		double y0 = -b * c / (a * a + b * b);

		if (c * c > radious * radious * (a * a + b * b) + kEps)
		{
			//std::cout << '1' << std::endl;
			return false;
		}
		else if (abs(c * c - radious * radious * (a * a + b * b)) < kEps) 
		{
			//std::cout << '2' << std::endl;
			return IsPointOnSegment(p1,p2,sf::Vector2f(x0,y0));
		}
		else 
		{
			//std::cout << '3' << std::endl;

			double d = radious * radious - c * c / (a * a + b * b);
			double mult = sqrt(d / (a * a + b * b));
			double ax, ay, bx, by;
			ax = x0 + b * mult;
			bx = x0 - b * mult;
			ay = y0 - a * mult;
			by = y0 + a * mult;
			return IsPointOnSegment(p1,p2,sf::Vector2f(ax,ay)) || IsPointOnSegment(p1,p2,sf::Vector2f(bx,by));
		}
	}
}