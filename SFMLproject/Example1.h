#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>

sf::Vector2f Convert_2i_to_2f(sf::Vector2i v2i)
{
    return sf::Vector2f(v2i.x, v2i.y);
}

int Example2()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default);
    //sf::CircleShape shape(100.f);
    //shape.setPosition(sf::Vector2f(100.f, 200.f));
    //shape.setFillColor(sf::Color::Green);

    std::vector<sf::CircleShape> circles;

    for (int i = 0; i < 100; ++i)
    {
        circles.emplace_back(rand() % 100);
        circles.back().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
        circles.back().setPosition(sf::Vector2f(rand() % 1024, rand() % 768));
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //if (event.type == sf::Event::EventType::MouseButtonPressed)
            //{
            //    if (event.mouseButton.button == sf::Mouse::Button::Left)
            //    {
            //        sf::Mouse::setPosition(sf::Vector2i(rand() % 1024, rand() % 768));
            //    }
            //    if (event.mouseButton.button == sf::Mouse::Button::Right)
            //    {
            //        sf::Vector2i cur_pos = sf::Mouse::getPosition();
            //        cur_pos.y+= 10;
            //        sf::Mouse::setPosition(cur_pos);
            //    }
            //}
        }

        //shape.setPosition(Convert_2i_to_2f(sf::Mouse::getPosition(window)));

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        window.clear();

        for (sf::CircleShape circle : circles)
        {
            circle.setPosition(sf::Vector2f(rand() % 1024, rand() % 768));
            window.draw(circle);
        }

        //window.draw(shape);

        window.display();
    }
    return 0;
}


int Example1()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //std::cout << event.type << ' ' << event.text.unicode << std::endl;

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            else if (event.type == sf::Event::LostFocus)
            {
                std::cout << "LostFocus" << std::endl;
            }
            else if (event.type == sf::Event::GainedFocus)
            {
                std::cout << "GainedFocus" << std::endl;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                //if (event.text.unicode < 128)
                {
                    std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
            }
            else if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                    std::cout << "wheel type: vertical" << std::endl;
                else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                    std::cout << "wheel type: horizontal" << std::endl;
                else
                    std::cout << "wheel type: unknown" << std::endl;
                std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                else if (event.mouseButton.button == sf::Mouse::Middle)
                {
                    std::cout << "the middle button was pressed" << std::endl;
                }

                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
            }
            else if (event.type == sf::Event::MouseEntered)
            {
                std::cout << "the mouse cursor has entered the window" << std::endl;
            }

            else if (event.type == sf::Event::MouseLeft)
            {
                std::cout << "the mouse cursor has left the window" << std::endl;
            }
        }

        window.clear();
        //window.draw(shape);
        window.display();
    }
    return 0;
}