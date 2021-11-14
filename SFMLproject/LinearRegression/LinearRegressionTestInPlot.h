#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include "LinearRegression.h"

namespace LinRegPlot
{
    void PrintLinearFunction(sf::RenderWindow& window, double a, double b)
    {
        int x = 0;
        double y = a * x + b;
        int x1 = window.getSize().x;
        double y1 = a * x1 + b;

        sf::VertexArray lines(sf::LinesStrip, 2);
        lines[0].position.x = x;
        lines[0].position.y = window.getSize().y - y;
        lines[1].position.x = x1;
        lines[1].position.y = window.getSize().y - y1;

        window.draw(lines);
    }

	void TestLinReg()
	{
		//std::vector<double> vec_x;
		//std::vector<double> vec_y;
		//
		//for (int i = 0; i < 10; ++i)
		//{
		//	vec_x.push_back(i);
		//	vec_y.push_back(3*i + 5);
		//}
		//
		//LinReg::LinearRegressionCoeffs lrc = LinReg::LinearRegression(vec_x, vec_y);
		//std::cout << lrc._a << " / " << lrc._b << std::endl;

        std::vector<double> points_x;
        std::vector<double> points_y;

        sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default);

        const int h = window.getSize().y;

        while (window.isOpen())
        {
            
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    points_x.push_back(event.mouseButton.x);
                    points_y.push_back(h - event.mouseButton.y);
                }
            }

            window.clear();

            sf::CircleShape circ(10.f);
            for (int i = 0; i < points_x.size(); ++i)
            {
                circ.setPosition(sf::Vector2f(points_x[i] - circ.getRadius(), h - (points_y[i] + circ.getRadius())));
                circ.setFillColor(sf::Color::Green);
                window.draw(circ);
            }
            
            LinReg::LinearRegressionCoeffs lrc = LinReg::LinearRegression(points_x, points_y, 0, points_x.size());
            
            PrintLinearFunction(window, lrc._a, lrc._b);
            
            window.display();
        }
	}


}