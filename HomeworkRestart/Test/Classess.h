#pragma once
#include <iostream>
#include <random>

namespace TestInheritance
{
	class TheRoot
	{
	private:
		int _x;
		int _y;
		std::string str = "TheRoot";
	public:
		TheRoot()
		{
			_x = 1;
			_y = 1;
		}
		int Get_x()
		{
			return _x;
		}

		int Get_y()
		{
			return _y;
		}

		virtual void WhoAmI()
		{
			std::cout << str << std::endl;
		}
	};

	class FirstFromRoot : public TheRoot
	{
	private:
		int _xx;
		int _yy;
		std::string str = "TheFirstFromRoot";
	public:
		FirstFromRoot()
		{
			_xx = 2;
			_yy = 2;
		}

		int Get_x()
		{
			return _xx;
		}
		int Get_y()
		{
			return _yy;
		}

		virtual void WhoAmI()
		{
			std::cout << str << std::endl;
		}
	};

	void Test()
	{
		TheRoot rt;
		FirstFromRoot frt;

		rt.WhoAmI();
		frt.WhoAmI();
	}






}