#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include "LinearRegression.h"

namespace LinRegPlot
{
    const int scale_x = 10;
    const int scale_y = 20;
    const int dispersion_y = 5;
    const int last_bars_count_for_regression = 20;
    
    
    void TestPrice()
    {
        std::vector<double> points_x_time;
        std::vector<double> points_y_price;

        sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default);

        const int h = window.getSize().y;

        points_x_time.push_back(0);
        points_y_price.push_back(h/2);

        for (int i = 1; i < window.getSize().x/16; ++i)
        {
            points_x_time.push_back(i* scale_x);
            points_y_price.push_back(points_y_price[i-1] + (rand()% dispersion_y - dispersion_y/2)* scale_y);
        }

        int counter_for_adding_price = 0;

        std::vector<sf::Vector2f> predictions;

        LinReg::LinearRegressionCoeffs lrc = LinReg::LinearRegression(points_x_time, points_y_price, (points_x_time.size() - last_bars_count_for_regression), points_x_time.size());
        predictions.push_back(sf::Vector2f(points_x_time.back() + scale_x, lrc._a * (points_x_time.back() + scale_x) + lrc._b));

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            counter_for_adding_price++;
            if (counter_for_adding_price % 1000 == 0)
            {
                points_x_time.push_back(points_x_time.back() + 1* scale_x);
                points_y_price.push_back(points_y_price.back() + (rand() % dispersion_y - dispersion_y/2)* scale_y);
                
                lrc = LinReg::LinearRegression(points_x_time, points_y_price, (points_x_time.size() - last_bars_count_for_regression), points_x_time.size());
                predictions.push_back(sf::Vector2f(points_x_time.back() + scale_x, lrc._a * (points_x_time.back() + scale_x) + lrc._b));
            }
            
            window.clear();

            sf::VertexArray lines(sf::LinesStrip, points_x_time.size());
            for (int i = 0; i < points_x_time.size(); ++i)
            {
                lines[i].position.x = points_x_time[i];
                lines[i].position.y = h - points_y_price[i];
            }

            window.draw(lines);

            sf::CircleShape circ(3.f);
            
            for (int i = 0; i < predictions.size(); ++i)
            {
                circ.setPosition(predictions[i].x - circ.getRadius(), h - (predictions[i].y + circ.getRadius()));
                circ.setFillColor(sf::Color::Green);
                window.draw(circ);
            }
            

            //PrintLinearFunction(window, lrc._a, lrc._b);

            window.display();
        }
    }


}