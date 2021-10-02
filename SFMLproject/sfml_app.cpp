#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <queue>


sf::Vector2f Convert_2i_to_2f(sf::Vector2i v2i)
{
    return sf::Vector2f(v2i.x, v2i.y);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default);
    //sf::CircleShape shape(100.f);
    //shape.setPosition(sf::Vector2f(100.f, 200.f));
    //shape.setFillColor(sf::Color::Green);
    
    std::deque<sf::CircleShape> circles;
    
    for (int i = 0; i < 100; ++i)
    {
        circles.emplace_back(50);
        circles.back().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
        circles.back().setPosition(i*40, 300);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::MouseMoved)
            {
                sf::CircleShape temp = circles.front();
                circles.pop_front();
                circles.push_back(temp);
                circles.back().setPosition(event.mouseMove.x, event.mouseMove.y);
            }
        }
        
        //shape.setPosition(Convert_2i_to_2f(sf::Mouse::getPosition(window)));
        
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));

        window.clear();

        for (sf::CircleShape circle : circles)
        {
            //circle.setPosition(sf::Vector2f(rand() % 1024, rand() % 768));
            window.draw(circle);
        }

        //window.draw(shape);

        window.display();
    }
    return 0;
}