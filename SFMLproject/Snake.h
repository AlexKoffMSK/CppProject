#pragma once
#include "SFML/Graphics.hpp"

namespace Snake
{
	class SnakeGame
	{
    private:
        sf::RenderWindow _window;
        std::deque<sf::CircleShape> _snake_parts;
        
        bool IsCirclesIntersect(sf::CircleShape circle1, sf::CircleShape circle2)
        {
            float distance = sqrt(pow(circle1.getPosition().x - circle2.getPosition().x, 2) + pow(circle1.getPosition().y - circle2.getPosition().y, 2));
            return distance < circle1.getRadius() + circle2.getRadius();
        }

	public:
       
        SnakeGame()
            :_window(sf::VideoMode(1600, 800), "Snake game!", sf::Style::Default)
        {
           for (int i = 0; i < 10; ++i)
           {
               _snake_parts.emplace_back(10);
               _snake_parts[i].setPosition((10-i)*(_snake_parts[i].getRadius()*2)*1.2, _window.getSize().y / 2);
           }
        }

		void Run()
		{
            //int mouse_move_counter = 0;

            while (_window.isOpen())
            {
                sf::Event event;
                while (_window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        _window.close();
                    }
                    if (event.type == sf::Event::EventType::MouseMoved)
                    {
                        //mouse_move_counter++;
                        //if ((mouse_move_counter % 50) == 0 )
                        //{
                        //    _snake_parts.pop_back();
                        //    _snake_parts.emplace_front(50);
                        //    _snake_parts.front().setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                        //}
                        float x = event.mouseMove.x - _snake_parts.front().getPosition().x;
                        float y = event.mouseMove.y - _snake_parts.front().getPosition().y;
                        float lenght = sqrt(x * x + y * y);
                        x = x / lenght;
                        y = y / lenght;
                        x *= _snake_parts.front().getRadius() * 2*1.5;
                        y *= _snake_parts.front().getRadius() * 2*1.5;
                        x += _snake_parts.front().getPosition().x;
                        y += _snake_parts.front().getPosition().y;

                        sf::CircleShape new_head(_snake_parts.front().getRadius());
                        new_head.setPosition(x, y);
                        
                        bool is_intersect = false;

                        for (sf::CircleShape ch : _snake_parts)
                        {
                            if (IsCirclesIntersect(new_head, ch))
                            {
                                is_intersect = true;
                                break;
                            }
                        }
                        if (is_intersect == false)
                        {
                            _snake_parts.pop_back();
                            _snake_parts.emplace_front(_snake_parts.front().getRadius());
                            _snake_parts.front().setPosition(sf::Vector2f(x, y));
                        }
                    }
                }
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                _window.clear();
                
                for (int i = 0; i < _snake_parts.size(); ++i)
                {
                    _window.draw(_snake_parts[i]);
                }


                _window.display();
            }
		}
	};

    void SnakeGameRun()
    {
        SnakeGame sg;
        sg.Run();
    }

    void Test222()
    {
        sf::Clock cl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        sf::Time tm = cl.getElapsedTime();
        std::cout << tm.asMicroseconds() << std::endl;

        sf::Keyboard kb;
        
        kb.setVirtualKeyboardVisible(true);
        
        while (true)
        {
        std::cout << kb.isKeyPressed(sf::Keyboard::Key::RShift) << std::endl;
        }
        

    }
}