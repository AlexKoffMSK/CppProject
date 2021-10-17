/*#include <SFML/Graphics.hpp>

#include <deque>

static const int kR = 20;

inline float Norm(sf::Vector2f v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

inline sf::Vector2f GetPointBetween(sf::Vector2f a, sf::Vector2f b, float distance_to_a)
{
	auto tmp_p = b - a;
	const auto norm = Norm(tmp_p);

	tmp_p.x /= norm;
	tmp_p.y /= norm;

	tmp_p.x *= distance_to_a;
	tmp_p.y *= distance_to_a;

	tmp_p += a;
	
	return tmp_p;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
	window.setPosition(sf::Vector2i(10,10));
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::deque<sf::CircleShape> snake;
	for (int i = 0; i < 20; i++)
	{
		snake.emplace_back(kR);
		snake.back().setPosition(i*50, 40);
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
			else if (event.type == sf::Event::MouseMoved)
			{
				snake.front().setPosition(event.mouseMove.x, event.mouseMove.y);

				for (int i = 1; i < snake.size(); i++)
				{
					snake[i].setPosition(GetPointBetween(snake[i-1].getPosition(), snake[i].getPosition(), kR*3));
				}
			}
		}

		window.clear();

		for (int i = 0; i < snake.size(); i++)
		{
			window.draw(snake[i]);

			if (i > 0)
			{
				sf::VertexArray lines(sf::LinesStrip, 2);
				lines[0].position.x = snake[i].getPosition().x + kR;
				lines[0].position.y = snake[i].getPosition().y + kR;
				lines[1].position.x = snake[i - 1].getPosition().x + kR;
				lines[1].position.y = snake[i - 1].getPosition().y + kR;

				window.draw(lines);
			}
		}


		window.display();
	}

	return 0;
}
*/

/*
#include <SFML/Graphics.hpp>
#include <chrono>
#include <deque>


static const float kR = 20;
static const float kSpineDist = 60; // Расстояние между элементами, к которому будет стремиться змейка
static const float kSpineRecoverySpeed = 0.002; // С какой скорость змейка будет приходить к ровному состоянию
static const float kStartElemsCount = 10;

inline float Norm(sf::Vector2f v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

inline float Distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

inline sf::Vector2f GetPointBetween(sf::Vector2f a, sf::Vector2f b, float distance_to_a)
{
	auto tmp_p = b - a;
	const auto norm = Norm(tmp_p);

	tmp_p.x /= norm;
	tmp_p.y /= norm;

	tmp_p.x *= distance_to_a;
	tmp_p.y *= distance_to_a;

	tmp_p += a;

	return tmp_p;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
	window.setPosition(sf::Vector2i(10, 10));
	window.setMouseCursorVisible(false);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::deque<sf::CircleShape> snake;
	
	std::vector<sf::Vector2f> lag_positions;
	
	for (int i = 0; i < kStartElemsCount; i++)
	{
		snake.emplace_back(kR);
		snake.back().setPosition(i * 80, 40);
		lag_positions.push_back(snake.back().getPosition());
	}

	std::chrono::nanoseconds time_to_update_head_pos = std::chrono::system_clock::now().time_since_epoch() + std::chrono::seconds(1);

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
				snake.front().setPosition(event.mouseMove.x-kR, event.mouseMove.y-kR);
			}
		}

		if (std::chrono::system_clock::now().time_since_epoch() > time_to_update_head_pos)
		{
			time_to_update_head_pos = std::chrono::system_clock::now().time_since_epoch() + std::chrono::microseconds(100);
			
			for (int i = 0; i < snake.size(); i++)
			{
				lag_positions[i] = snake[i].getPosition();
			}
		}

		for (int i = 1; i < snake.size(); i++)
		{
			const auto dist = Distance(snake[i].getPosition(), lag_positions[i-1]);
			snake[i].setPosition(GetPointBetween(lag_positions[i - 1], snake[i].getPosition(), dist - (dist - kSpineDist) * kSpineRecoverySpeed));
		}

		window.clear();

		for (int i = 0; i < snake.size(); i++)
		{
			window.draw(snake[i]);

			if (i > 0)
			{
				sf::VertexArray lines(sf::LinesStrip, 2);
				lines[0].position.x = snake[i].getPosition().x + kR;
				lines[0].position.y = snake[i].getPosition().y + kR;
				lines[1].position.x = snake[i - 1].getPosition().x + kR;
				lines[1].position.y = snake[i - 1].getPosition().y + kR;

				window.draw(lines);
			}
		}

		window.display();
	}

	return 0;
}
*/