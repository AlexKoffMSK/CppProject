#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include "SortsVisualisation/SortsVisualisztion.h"
#include "SortsVisualisation/BubbleSort.h"
#include "SortsVisualisation/SelectionSort.h"
#include "SortsVisualisation/CountingSort.h"

void Test()
{
	std::vector<int> vec;
	
	for (int i = 0; i < 120; ++i)
	{
		//vec.push_back(i);
		vec.push_back(std::rand()%500);
	}

	std::random_shuffle(vec.begin(), vec.end());

	//SortsVisualisation::BubbleSort(vec);
	//SortsVisualisation::SelectionSort(vec);
	SortsVisualisation::CountingSort(vec);

	getchar();
}

int main()
{
    Test();
}