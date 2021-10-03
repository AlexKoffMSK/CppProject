#pragma once
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{
	int IndexOfMinElemOfTailOfVector(const std::vector<int>& arr, int start_pos)
	{
		int index_of_min_elem = start_pos;
		for (int i = start_pos; i < arr.size(); i++)
		{
			DrawArray(arr, i, index_of_min_elem, sf::Color::Yellow, sf::Color::Blue);

			if (arr[i] < arr[index_of_min_elem])
			{
				index_of_min_elem = i;
			}
		}
		return index_of_min_elem;
	}
	
	std::vector<int> SelectionSort(std::vector<int>& arr) //сортировка выбором
	{
		for (int i = 0; i < arr.size(); i++)
		{
			int index_of_min_elem = IndexOfMinElemOfTailOfVector(arr, i);

			DrawArray(arr, index_of_min_elem, i, sf::Color::Green, sf::Color::Red);

			std::swap(arr[index_of_min_elem], arr[i]);
		}
		return arr;
	}
}