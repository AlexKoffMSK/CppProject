#pragma once
#include <iostream>
#include "SortsVisualisztion.h"

namespace SortsVisualisation
{
	class SmartVector
	{
	private:
		std::vector<int> _vec;

	public:
		int size()
		{
			std::cout << "Return size of array: " << _vec.size() << std::endl;
			return _vec.size();
		}

		int operator[](int index) const
		{
			std::cout << "Get index  to read: " << index << std::endl;
			DrawArray(_vec, index, -1, sf::Color::Blue, sf::Color::Black);
			return _vec[index];
		}

		int& operator[](int index)
		{
			std::cout << "Get index to write: " << index << std::endl;
			DrawArray(_vec, index, -1, sf::Color::Green, sf::Color::Black);
			return _vec[index];
		}
	};



	
















}