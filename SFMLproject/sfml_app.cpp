#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include "SortsVisualisation/SortsVisualisztion.h"
#include "SortsVisualisation/BubbleSort.h"
#include "SortsVisualisation/SelectionSort.h"

void Test()
{
	std::vector<int> vec;
	
	for (int i = 0; i < 32; ++i)
	{
		vec.push_back(i);
	}

	std::random_shuffle(vec.begin(), vec.end());

	//SortsVisualisation::BubbleSort(vec);
	SortsVisualisation::SelectionSort(vec);

	getchar();
}

int main()
{
    Test();
}