#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

namespace SortsVisualisation
{
	void DrawArray(sf::RenderWindow& window, const std::vector<int>& vec, int index1_vec_to_color, int index2_vec_to_color, sf::Color color1, sf::Color color2)
	{
		bool is_mouse_pressed = false;

		sf::Event event;
		while (window.pollEvent(event) || is_mouse_pressed)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				is_mouse_pressed = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				is_mouse_pressed = false;
			}
		}

		window.clear();

		if (vec.size() == 0)
		{
			return;
		}
		int column_width = window.getSize().x / vec.size(); //ширина бара
		int max_elem = *std::max_element(vec.begin(), vec.end());
		int draw_area_height = window.getSize().y;

		int cur_x = 0;
		for (int i=0; i<vec.size(); ++i)
		{
			int column_height = ((double)vec[i] / max_elem) * draw_area_height;
			sf::RectangleShape rect(sf::Vector2f(column_width, column_height));
			rect.setPosition(cur_x, window.getSize().y - column_height);
			
			if (i == index1_vec_to_color)
			{
				rect.setFillColor(color1);
			}
			if (i == index2_vec_to_color)
			{
				rect.setFillColor(color2);
			}

			cur_x += column_width;
			window.draw(rect);
		}

		window.display();

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		//_getch();
		//std::cout << '1' << std::endl;
	}

	void WindowThread(sf::RenderWindow& window)
	{
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
		}
	}

	void DrawArray(const std::vector<int>& vec, int index1_vec_to_color, int index2_vec_to_color, sf::Color color1, sf::Color color2)
	{
		static sf::RenderWindow window(sf::VideoMode(800, 600), "Function works!", sf::Style::Default);

		/*static std::thread window_thread(WindowThread, std::ref(window));

		static bool is_need_call_detach = true;

		if (is_need_call_detach)
		{
			window_thread.detach();
			is_need_call_detach = false;
		}
		*/

		window.setPosition(sf::Vector2i(0, 0));

		DrawArray(window, vec, index1_vec_to_color, index2_vec_to_color, color1, color2);
	}
}