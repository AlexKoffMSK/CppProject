#pragma once
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{
	class OnlineSort
	{
	private:
		sf::RenderWindow _window;
		
		int FindPlaceToInsertElemInSortedArray(const std::vector<int>& sorted_arr, int elem)
		{
			for (int i = 0; i < sorted_arr.size(); i++)
			{
				DrawArray(_window, sorted_arr, i, -1, sf::Color::Blue, sf::Color::Black);
				if (sorted_arr[i] >= elem)
				{
					return i; // возвращает позицию для вставки элемента в новом сортируемом массиве
					break; //после первого совпадения выходим из условия
				}
			}
			return sorted_arr.size(); // возвращает позицию для вставки элемента в новом сортируемом массиве
		}

		void InsertElemToArray(std::vector<int>& arr, int place_to_insert, int elem)
		{
			//1 3 5 7 9
			//place_to_insert = 2;
			//elem = 4
			//1 3 4 5 7 9

			DrawArray(_window, arr, -1, -1, sf::Color::Black, sf::Color::Black);
			arr.push_back(1); //1 3 5 7 9 1
			DrawArray(_window, arr, arr.size()-1, -1, sf::Color::Magenta, sf::Color::Black);

			for (int i=arr.size()-1; i>place_to_insert; --i)
			{
				arr[i] = arr[i - 1];
				DrawArray(_window, arr, i-1, i, sf::Color::Blue, sf::Color::Green);
			} //1 3 5 5 7 9

			arr[place_to_insert] = elem;

			DrawArray(_window, arr, place_to_insert, -1, sf::Color::Green, sf::Color::Black);
		}

		int BinarySearchPositionInArr(std::vector<int>& arr, int index_start, int index_finish, int elem)
		{
			
			if (index_start > index_finish)
			{
				return index_start;
			}

			int index_middle = (index_start + index_finish) / 2;

			DrawArray(_window, arr, index_middle, -1, sf::Color::Blue, sf::Color::Black);
			
			if (arr[index_middle] > elem)
			{
				BinarySearchPositionInArr(arr, index_start, index_middle-1, elem);
			}
			else if (arr[index_middle] < elem)
			{
				BinarySearchPositionInArr(arr, index_middle+1, index_finish, elem);
			}
			else
			{
				return index_middle;
			}
		}

	public:
		OnlineSort()
			:_window(sf::VideoMode(800, 600), "Sorted array!", sf::Style::Default)
		{
			_window.setPosition(sf::Vector2i(800,0));
		}

		std::vector<int> RunSort(std::vector<int> arr) // сортирует неотсортированный массив налету
		{
			std::vector<int> sorted_arr;

			for (int i=0; i<arr.size(); i++)
			{
				DrawArray(arr, i, -1, sf::Color::Blue, sf::Color::Black);
				
				//int pos_to_insert = FindPlaceToInsertElemInSortedArray(sorted_arr, arr[i]); //получаем в созданную переменную позицию для вставки элемента в массив
				
				int pos_to_insert = BinarySearchPositionInArr(sorted_arr, 0, sorted_arr.size()-1, arr[i]); //получаем в созданную переменную позицию для вставки элемента в массив

				InsertElemToArray(sorted_arr, pos_to_insert, arr[i]);
				//sorted_arr.insert(sorted_arr.begin() + pos_to_insert, a);
			}
			return sorted_arr;
		}
	};

	void OnlineSortFunc(std::vector<int> arr)
	{
		OnlineSort os;
		os.RunSort(arr);
	}
}