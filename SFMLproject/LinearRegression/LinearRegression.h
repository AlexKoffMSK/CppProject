#pragma once
#include <iostream>
#include <vector>
#include <cassert>

namespace LinReg
{
	struct LinearRegressionCoeffs
	{
		//Параметры модели: f(x) = ax+b; a - коэффициент умножения, мультипликатор, b - сдвиг
		double _a=0;
		double _b=0;
	};
	
	LinearRegressionCoeffs LinearRegression(std::vector<double> vec_x, std::vector<double> vec_y, int index_left_bound, int index_right_bound)
	{
		assert(vec_x.size() == vec_y.size());
		
		//Средние значения: MeanValues += (value - MeanValues) / CountValues

		double Avg_x = 0, Avg_y = 0, Avg_xy = 0, Avg_xx = 0;
		
		//Вычисление параметров модели:
		for (int i = index_left_bound; i < index_right_bound; i++)
		{
			Avg_x += (vec_x[i] - Avg_x) / (i - index_left_bound + 1);
			Avg_y += (vec_y[i] - Avg_y) / (i - index_left_bound + 1);
			Avg_xx += (vec_x[i] * vec_x[i] - Avg_xx) / (i - index_left_bound + 1);
			Avg_xy += (vec_x[i] * vec_y[i] - Avg_xy) / (i - index_left_bound + 1);
		}

		//for (int i = 0; i < vec_x.size(); i++) 
		//{
		//	Avg_x += (vec_x[i]);
		//	Avg_y += (vec_y[i]);
		//	Avg_xx += (vec_x[i] * vec_x[i]);
		//	Avg_xy += (vec_x[i] * vec_y[i]);
		//}
		//
		//Avg_x /= vec_x.size();
		//Avg_y /= vec_y.size();
		//Avg_xx /= vec_x.size();
		//Avg_xy /= vec_y.size();

		LinearRegressionCoeffs lrc;
		lrc._a = (Avg_x * Avg_y - Avg_xy) / (Avg_x * Avg_x - Avg_xx);
		lrc._b = (Avg_xy - lrc._a * Avg_xx) / Avg_x;

		//Результат:
		return lrc;
	}
}

/*
Принимаем на вход:
- два потока однороднных данных
*/