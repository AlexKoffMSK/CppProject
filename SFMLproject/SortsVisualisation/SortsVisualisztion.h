#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

namespace SortsVisualisation
{
	void DrawArray(sf::RenderWindow& window, const std::vector<int>& vec, int index1_vec_to_color, int index2_vec_to_color, sf::Color color1, sf::Color color2)
	{
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

	void DrawArray(const std::vector<int>& vec, int index1_vec_to_color, int index2_vec_to_color, sf::Color color1, sf::Color color2)
	{
		static sf::RenderWindow window(sf::VideoMode(800, 600), "Function works!", sf::Style::Default);
		window.setPosition(sf::Vector2i(0, 0));
		DrawArray(window, vec, index1_vec_to_color, index2_vec_to_color, color1, color2);
	}
}