#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <queue>
#include "SortsVisualisation/SortsVisualisztion.h"
#include "SortsVisualisation/BubbleSort.h"
#include "SortsVisualisation/SelectionSort.h"
#include "SortsVisualisation/CountingSort.h"
#include "SortsVisualisation/OnlineSort.h"
#include "SortsVisualisation/QuickSort.h"
//#include "Snake.h"
#include "SortsVisualisation/MergeSort.h"
#include "LinearRegression/LinearRegressionTestInPlot.h"
#include "LinearRegression/TestPrice.h"
#include "Physics/Drawer.h"

void MakeVecForSorts()
{
	std::vector<int> vec;
	
	for (int i = 0; i < 400; ++i)
	{
		//vec.push_back(i);
		vec.push_back(std::rand()%10+2);
	}

	std::random_shuffle(vec.begin(), vec.end());

	//SortsVisualisation::BubbleSort(vec);
	//SortsVisualisation::SelectionSort(vec);
	//SortsVisualisation::CountingSort(vec);
	//SortsVisualisation::OnlineSortFunc(vec);
	//Snake::SnakeGameRun();
	//Snake::Test222();
	//SortsVisualisation::QuickSort(vec);
	//SortsVisualisation::MergeSort(vec);
	

	getchar();
}

int main()
{
	//MakeVecForSorts();
	//LinRegPlot::TestLinReg();
	//LinRegPlot::TestPrice();
	//srand(time(0));
	Physics::Drawer();
}