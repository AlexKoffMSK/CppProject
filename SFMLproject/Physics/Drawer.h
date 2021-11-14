#include <SFML/Graphics.hpp>
#include <iostream>
#include "PhysicsOfObjects.h"

namespace Physics
{
    const double kPi = acos(-1);
    const int kCountOfCircles = 100;

    sf::Vector2f PolarToDecart(int radious, double angle_fi)
    {
        float x = radious * cos(angle_fi);
        float y = radious * sin(angle_fi);
        return sf::Vector2f(x, y);
    }
    
    void Drawer()
	{
        std::srand(time(0));
        sf::RenderWindow window(sf::VideoMode(1024, 768), __FUNCTION__, sf::Style::Default);
        //создается объект класса - окно, которое умеет рендериться. Рендеринга здесь не происходит. Рендеринг происходит на .display

        PhysicsOfObjects physics_of_objects;

        for (int i = 0; i < kCountOfCircles; ++i)
        {
            double fi = (double(rand())/RAND_MAX)*(2*kPi);
            int radious = rand() % 50 + 10;
            physics_of_objects.AddCircle(sf::Vector2f(rand() % (window.getSize().x-radious*2) + radious, rand() % (window.getSize().y - radious*2) + radious), radious, PolarToDecart(1, fi));
            //physics_of_objects.AddCircle(sf::Vector2f(rand() % (window.getSize().x-radious), rand() % (window.getSize().y - radious)), radious, PolarToDecart(0, fi));
        }

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                //else if (event.type == sf::Event::MouseMoved)
                //{
                //    physics_of_objects.SetCirclePosition(0, sf::Vector2f( event.mouseMove.x, kHeight-event.mouseMove.y ));
                //}
            }
            
            physics_of_objects.Action();

            window.clear();
            
            for (int i = 0; i < physics_of_objects.GetCirclesCount(); ++i)
            {
                window.draw(physics_of_objects.GetCircleShapeForDraw(i));
            }

            //sf::VertexArray lines(sf::LinesStrip, 2);
            //lines[0].position.x = 10;
            //lines[0].position.y = 10;
            //lines[1].position.x = 600;
            //lines[1].position.y = 600;
            //window.draw(lines);

            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
	}
}