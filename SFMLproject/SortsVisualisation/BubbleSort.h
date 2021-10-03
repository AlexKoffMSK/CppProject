#pragma once
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{

	std::vector<int> BubbleSort1Iteration(std::vector<int> arr)
	{
		//принимает на вход массив, возвращает. Если левый больше чем правый.
		for (int i = 1; i < arr.size(); i++)
		{
			DrawArray(arr, i - 1, i, sf::Color::Blue, sf::Color::Blue);
			if (arr[i - 1] > arr[i])
			{
				std::swap(arr[i - 1], arr[i]);
				DrawArray(arr, i - 1, i, sf::Color::Green, sf::Color::Red);
			}
		}
		return arr;
	}

	std::vector<int> BubbleSort(std::vector<int> arr)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			arr = BubbleSort1Iteration(arr); //перезаписываем массив полностью на каждой итерации его сортировки
		}
		return arr;
	}











}