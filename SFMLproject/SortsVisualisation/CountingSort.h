#pragma once
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{
	std::vector<int> CountingSort(std::vector<int> arr) //сортировка подсчётом
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Buckets", sf::Style::Default);
		window.setPosition(sf::Vector2i(800, 0));
		
		int bucket_count = arr.front();

		for (int elem : arr)
		{
			if (elem > bucket_count)
			{
				bucket_count = elem;
			}
		}

		std::vector<int> buckets(bucket_count+1,0);

		for (int i = 0; i < arr.size(); i++) //перебираем элементы исходного массива
		{
			buckets[arr[i]] += 1;
			DrawArray(arr, i, -1, sf::Color::Blue, sf::Color::Black);
			DrawArray(window, buckets, arr[i], -1, sf::Color::Green, sf::Color::Blue);
		}

		int k = 0;
		
		for (int i = 0; i < buckets.size(); i++)
		{
			if (buckets[i] > 0)
			{
				for (int j = 0; j < buckets[i]; j++)
				{
					arr[k]=i;
					k++;
				}
				DrawArray(arr, k, -1, sf::Color::Green, sf::Color::Red);
				DrawArray(window, buckets, i, -1, sf::Color::Blue, sf::Color::Black);
			}
		}

		return arr;
	}
}