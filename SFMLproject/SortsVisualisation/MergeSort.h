#pragma once
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{
	void MergeTwoSortedVectors(std::vector<int>& arr, int v0_left_i, int v0_right_i, int v1_left_i, int v1_right_i)
	{
		std::vector<int> new_arr;

		int i0 = v0_left_i;
		int i1 = v1_left_i;

		while (i0 <= v0_right_i || i1 <= v1_right_i)
		{
			if (i0 > v0_right_i)
			{
				new_arr.push_back(arr[i1]);
				DrawArray(arr, i1, -1, sf::Color::Blue, sf::Color::Black);
				i1++;
			}
			else
			{
				if (i1 > v1_right_i)
				{
					new_arr.push_back(arr[i0]);
					DrawArray(arr, i0, -1, sf::Color::Blue, sf::Color::Black);

					i0++;
				}
				else
				{
					if (arr[i0] <= arr[i1])
					{
						new_arr.push_back(arr[i0]);
						DrawArray(arr, i0, -1, sf::Color::Blue, sf::Color::Black);
						i0++;
					}
					else
					{
						new_arr.push_back(arr[i1]);
						DrawArray(arr, i1, -1, sf::Color::Blue, sf::Color::Black);
						i1++;
					}
				}
			}
		}
		
		for (int i = 0; i < new_arr.size(); ++i)
		{
			arr[v0_left_i + i] = new_arr[i];
			DrawArray(arr, v0_left_i + i, -1, sf::Color::Green, sf::Color::Black);
		}
	}

	void MergeSort(std::vector<int>& arr, int v_left_i, int v_right_i)
	{
		//сортировка слиянием несортированного массива
		//разделить неотсортированный массив на половинки
		//отсортировать половинки
		//слить половинки
		//(n/2)^2 + (n/2)^2 - количество операций сортировки половинок 

		if (v_left_i >= v_right_i)
		{
			return;
		}

		int size_sub_arr = v_right_i - v_left_i;

		MergeSort(arr, v_left_i, (v_left_i+size_sub_arr/2));
		MergeSort(arr, (v_left_i + size_sub_arr / 2) + 1, v_right_i);

		MergeTwoSortedVectors(arr, v_left_i, (v_left_i + size_sub_arr / 2), (v_left_i + size_sub_arr / 2) + 1, v_right_i);

		//n/2 + n/2 - количество операций сортировки половинок

		//n*nlog
	}

	void MergeSort(std::vector<int>& vec)
	{
		MergeSort(vec, 0, vec.size() - 1);
	}














}