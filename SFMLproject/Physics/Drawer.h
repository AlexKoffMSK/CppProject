#include <SFML/Graphics.hpp>
#include <iostream>
#include "PhysicsOfObjectsPolymorphism.h"

namespace Physics
{
    //столкновение с неполным перекрытием - ломалось, когда они встречались по касательной
    //вернуть через полиморфизм логику столкновения и пересечения
    //

    const int kCountOfCircles = 100;
    const int kCountOfWalls = 0;

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

        //physics_of_objects.AddCircle(sf::Vector2f(100,500),30,sf::Vector2f(1,-1));
        //physics_of_objects.AddCircle(sf::Vector2f(480,200),30,sf::Vector2f(-1,1));

        //physics_of_objects.AddCircle(sf::Vector2f(100, 100), 30, sf::Vector2f(2, 0.01));
        //physics_of_objects.AddCircle(sf::Vector2f(500, 100), 30, sf::Vector2f(-1, 0.01));

        //physics_of_objects.AddCircle(sf::Vector2f(kWidth / 3, kHeight / 2),30,sf::Vector2f(-5,0.01));
        

        physics_of_objects.AddWall(sf::Vector2f{ kWidth / 2, kHeight / 7 }, sf::Vector2f{ kWidth / 2, kHeight / 2 },sf::Vector2f(0,0));

        for (int i = 0; i < kCountOfCircles; ++i)
        {
            double fi = (double(rand()) / RAND_MAX) * (2 * GeometryFormulas::kPi);
            int radious = rand() % 50 + 10;
            physics_of_objects.AddCircle(sf::Vector2f(rand() % (window.getSize().x - radious * 4) + radious*2, rand() % (window.getSize().y - radious * 4) + radious*2), radious, PolarToDecart(5, fi));
            //physics_of_objects.AddCircle(sf::Vector2f(rand() % (window.getSize().x - radious * 2) + radious, rand() % (window.getSize().y - radious * 2) + radious), radious, PolarToDecart(0, -GeometryFormulas::kPi/4));
        }

        for (int i = 0; i < kCountOfWalls; ++i)
        {
            double fi = (double(rand()) / RAND_MAX) * (2 * GeometryFormulas::kPi);
            physics_of_objects.AddWall(sf::Vector2f{ float(rand() % window.getSize().x), float(rand() % window.getSize().y) }, sf::Vector2f{ float(rand() % window.getSize().x), float(rand() % window.getSize().y) }, PolarToDecart(5, fi));
        }
        
        //physics_of_objects.AddWall(sf::Vector2f{ 100, 300 }, sf::Vector2f{ 400, 200 },sf::Vector2f(0,0));

        sf::Vector2f mouse_p;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                else if (event.type == sf::Event::MouseMoved)
                {
                    mouse_p.x = event.mouseMove.x;
                    mouse_p.y = kHeight - event.mouseMove.y;
                    //physics_of_objects.SetCirclePosition(0, sf::Vector2f( event.mouseMove.x, kHeight-event.mouseMove.y ));
                }
            }
            
            physics_of_objects.Action();

            window.clear();
            
            physics_of_objects.DrawAll(window);

            //sf::CircleShape csh = n_circ->_circle_shape;
            //csh.setPosition(sf::Vector2f(csh.getPosition().x, kHeight - csh.getPosition().y));
            //window.draw(csh);
            //
            //sf::CircleShape csh2 = n_circ2->_circle_shape;
            //csh2.setPosition(sf::Vector2f(csh2.getPosition().x, kHeight - csh2.getPosition().y));
            //window.draw(csh2);
            //
            //float t = n_circ->_circle_shape.getRadius() / (n_circ->_circle_shape.getRadius() + n_circ2->_circle_shape.getRadius());
            ////float t = 0.7;
            //float x0 = n_circ->_circle_shape.getPosition().x + t * float(n_circ2->_circle_shape.getPosition().x - n_circ->_circle_shape.getPosition().x);
            //float y0 = n_circ->_circle_shape.getPosition().y + t * float(n_circ2->_circle_shape.getPosition().y - n_circ->_circle_shape.getPosition().y);
            ////physics_of_objects.AddCircle(sf::Vector2f(x0, y0), 10, PolarToDecart(0, 0));
            //float a = n_circ->_circle_shape.getPosition().y - n_circ2->_circle_shape.getPosition().y;
            //float b = n_circ2->_circle_shape.getPosition().x - n_circ->_circle_shape.getPosition().x;
            //
            //sf::VertexArray lines1(sf::LinesStrip, 2);
            //lines1[0].position.x = x0 - 2 * a;
            //lines1[0].position.y = kHeight - (y0 - 2 * b);
            //lines1[1].position.x = x0 + 2 * a;
            //lines1[1].position.y = kHeight - (y0 + 2 * b);
            //window.draw(lines1);

            //sf::CircleShape csh3 = n_circ2->_circle_shape;
            //csh3.setPosition(sf::Vector2f(x0, kHeight - y0));
            //window.draw(csh3);

            //physics_of_objects.AddWall(sf::Vector2f{ x0-2*a, y0-2*b }, sf::Vector2f{ x0 + 2 * a, y0 + 2 * b },sf::Vector2f(0,0));

            /*
            sf::VertexArray lines1(sf::LinesStrip, 2);
            lines1[0].position.x = 100;
            lines1[0].position.y = kHeight - 300;
            lines1[1].position.x = 1000;
            lines1[1].position.y = kHeight - 400;
            window.draw(lines1);
            
            sf::VertexArray lines2(sf::LinesStrip, 2);
            lines2[0].position.x = 400;
            lines2[0].position.y = kHeight - 100;
            lines2[1].position.x = mouse_p.x;
            lines2[1].position.y = kHeight - mouse_p.y;
            window.draw(lines2);
            
            //window.setTitle(std::to_string(GeometryFormulas::RadiansToDegrees(GeometryFormulas::GetAngleBetweenLines(sf::Vector2f(100, 300), sf::Vector2f(1000, 300), sf::Vector2f(500,300), mouse_p))));

            sf::Vector2f pnt=GeometryFormulas::PointOfIntersectofTwoLines(sf::Vector2f(100, 300), sf::Vector2f(1000, 400), sf::Vector2f(400, 100), mouse_p);
            sf::CircleShape circ(10);
            circ.setPosition(pnt.x-20, kHeight-pnt.y - 20);
            //window.draw(circ);

            sf::Vector2f pnt1 = GeometryFormulas::GetPerpendicular(sf::Vector2f(100, 300), sf::Vector2f(1000, 400), sf::Vector2f(400, 100));
            circ.setPosition(pnt1.x - 10, kHeight - pnt1.y - 10);
            window.draw(circ);

            //window.setTitle(std::to_string(GeometryFormulas::GetPointPositionDependsOfLine(sf::Vector2f(100, 300), sf::Vector2f(1000, 400), mouse_p)));

            double angle = GeometryFormulas::GetAngleBetweenLines(sf::Vector2f(100, 300), sf::Vector2f(1000, 400), sf::Vector2f(400, 100), mouse_p);
            double angle_ro_rotate = - 2 * angle;
            //double angle_ro_rotate = GeometryFormulas::kPi/2;
            sf::Vector2f new_pnt1=GeometryFormulas::RotateSecondPointDependsFirstPoint(pnt, mouse_p, angle_ro_rotate);
            sf::Vector2f new_pnt2=GeometryFormulas::RotateSecondPointDependsFirstPoint(pnt, mouse_p, -angle_ro_rotate);

            //std::cout << angle << '|' << GeometryFormulas::GetAngleBetweenLines(sf::Vector2f(100, 300), sf::Vector2f(1000, 400), pnt, new_pnt1) << std::endl;

            double d1 = GeometryFormulas::GetPointPositionDependsOfLine(sf::Vector2f(400, 100), mouse_p, new_pnt1);
            double d2 = GeometryFormulas::GetPointPositionDependsOfLine(sf::Vector2f(400, 100), mouse_p, new_pnt2);
            double d0 = GeometryFormulas::GetPointPositionDependsOfLine(sf::Vector2f(400, 100), mouse_p, pnt1);

            std::cout << d0 << '|' << d1 << '|' << d2 << std::endl;

            if (d0 * d1 < 0)
            {
                sf::VertexArray lines3(sf::LinesStrip, 2);
                lines3[0].position.x = pnt.x;
                lines3[0].position.y = kHeight - pnt.y;
                lines3[1].position.x = new_pnt1.x;
                lines3[1].position.y = kHeight - new_pnt1.y;
                window.draw(lines3);
            }
            else
            {
                sf::VertexArray lines4(sf::LinesStrip, 2);
                lines4[0].position.x = pnt.x;
                lines4[0].position.y = kHeight - pnt.y;
                lines4[1].position.x = new_pnt2.x;
                lines4[1].position.y = kHeight - new_pnt2.y;
                window.draw(lines4);
            }
            */
            window.display();

            std::this_thread::sleep_for(std::chrono::microseconds(10));
        }
	}
}