#pragma once
#include "SortsVisualisztion.h"
#include "SmartVector.h"

namespace SortsVisualisation
{
	int Partition(std::vector<int>& vec, int left_bound_index, int right_bound_index, int pivot_index) //pivot - в переводе - опорный элемент
	{
		int p_left_i = left_bound_index;
		int p_right_i = right_bound_index;

		while (p_left_i < p_right_i)
		{
			DrawArray(vec, p_left_i, pivot_index, sf::Color::Blue, sf::Color::Red);
			if (vec[p_left_i] < vec[pivot_index])
			{
				p_left_i++;
			}
			else
			{
				DrawArray(vec, p_right_i, pivot_index, sf::Color::Blue, sf::Color::Red);
				if (vec[p_right_i] >= vec[pivot_index]) //*p_left > pivot
				{
					p_right_i--;
				}
				else //*p_right <= pivot, *p_left > pivot
				{
					DrawArray(vec, p_left_i, p_right_i, sf::Color::Green, sf::Color::Green);
					
					if (pivot_index == p_left_i)
					{
						pivot_index = p_right_i;
					}
					else if (pivot_index == p_right_i)
					{
						pivot_index = p_left_i;
					}
					
					std::swap(vec[p_left_i], vec[p_right_i]);
					DrawArray(vec, p_left_i, p_right_i, sf::Color::Green, sf::Color::Green);
				}
			}
		}
		return p_left_i;
	}
	
	void QuickSort(std::vector<int>& vec, int left_bound_index, int right_bound_index)
	{
		if (left_bound_index >= right_bound_index)
		{
			return;
		}
		int pivot = vec[left_bound_index]; //pivot это опорный элемент
		DrawArray(vec, left_bound_index, -1, sf::Color::Blue, sf::Color::Black);

		int p_middle_index = Partition(vec, left_bound_index, right_bound_index, left_bound_index);

		if (p_middle_index == left_bound_index)
		{
			p_middle_index++;
		}
		QuickSort(vec, left_bound_index, p_middle_index - 1);
		QuickSort(vec, p_middle_index, right_bound_index);
	}

	void QuickSort(std::vector<int>& vec)
	{
		QuickSort(vec, 0, vec.size()-1);
	}
}