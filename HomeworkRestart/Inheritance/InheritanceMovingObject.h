#pragma once
#include <iostream>
#include <cassert>

namespace InheritanceObjectWithAction
{
	class ObjectWithAction
	{
	private:
		int _max_speed;
		int _speed=0;
	
	public:
		ObjectWithAction(int max_speed_)
		{
			_max_speed = max_speed_;
		}

		void SetSpeed(int speed)
		{
			assert(speed <= _max_speed);
			_speed = speed;
		}

		int GetSpeed()
		{
			return _speed;
		}
	};

	int GetTimeOfMove(ObjectWithAction mo, int distance)
	{
		return distance / mo.GetSpeed();
	}

	class Car1
	{
		ObjectWithAction mo;

	};

	class Car : public ObjectWithAction
	{

	};







}