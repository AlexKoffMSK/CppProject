//Hello Unicode World ☺. 
#pragma once
#include <iostream>

namespace GameMatrix
{
	static const char kWallSymbol = '#';
	static const char kRandomMovingEnemySymbol = '%';
	static const char kPlayerSymbol = '@';
	static const char kEmptySymbol = ' ';
	static const char kTrapSymbol = '&';
	static const char kTeleportOneWayInSymbol = 'T';
	static const char kTeleportOneWayOutSymbol = 't';

	struct Point
	{
		int _x = 0; //движение по увеличению от 0 вправо
		int _y = 0; //движение по увеличению от 0 вниз

		friend Point operator+(Point p1, Point p2)
		{
			Point result_point{ 0, 0 };
			result_point._x = p1._x + p2._x;
			result_point._y = p1._y + p2._y;
			return result_point;
		}

		friend bool operator!=(Point p1, Point p2)
		{
			if (p1._x != p2._x || p1._y != p2._y)
			{
				return true;
			}
			return false;
		}

		friend std::ostream& operator<<(std::ostream& os, Point p)
		{
			os << '[' << p._x << ',' << p._y << ']';
			return os;
		}

		friend bool operator<(Point p1, Point p2)
		{
			if (p1._x < p2._x)
			{
				return true;
			}
			else if (p1._x > p2._x)
			{
				return false;
			}
			else if (p1._y < p2._y)
			{
				return true;
			}
			else if (p1._y > p2._y)
			{
				return false;
			}
			return false;
		}
	};

	Point kDeltas[4] = { {0,1}, {0,-1}, {1,0},{-1,0} }; //kDeltas - так гугл обозначает константы, в данном примере - обозначение соседей точки
	
	void Print(Point p, char ch, Color color=Color::White)
	{
		Console.Print(p._y, p._x, ch, color);
		Console.SetPosition(140, 140); //прячем курсор, установка позиции для курсора
	}
	 
	int _field_objects_count = 0;

	class FieldObject
	{
	protected:
		Point _position;
		char _symbol;
		Color _color;
		unsigned int _uniq_id;
	public:
		
		FieldObject()
		{
			_uniq_id = _field_objects_count++;
		}

		FieldObject(Point p_, char symbol_, Color color_)
		{
			_position = p_;
			_symbol = symbol_;
			_color = color_;
			_uniq_id = _field_objects_count++;
		}

		void SetPosition(Point new_position) { _position = new_position; }

		Point Position() { return _position; }
		int UniqId() { return _uniq_id; }
		char Symbol() { return _symbol; }
		
		virtual void Draw()
		{ 
			Print(_position, _symbol, _color); 
		}
		virtual ~FieldObject() = default;
	};

	struct TeleportOneWay : public FieldObject
	{
		Point _position_after_teleport;

		TeleportOneWay()
			: FieldObject()
		{

		}
		
		TeleportOneWay(Point p_, char symbol_, Color color_, Point position_after_teleport_)
			: FieldObject (p_, symbol_, color_)
		{
			_position_after_teleport = position_after_teleport_;
		}
	};

	class ObjectWithAction : public FieldObject
	{
	private:
		int _ticks_before_action=1; //частота принятия решения
		int _current_ticks=0;
	public:
		ObjectWithAction(Point p_, char symbol_, Color color_, int ticks_before_action_)
			:FieldObject(p_, symbol_, color_)
		{
			assert(ticks_before_action_ > 0);
			_ticks_before_action = ticks_before_action_;
		}

		bool IncrementTickAndReturnIsActionShouldBe()
		{
			_current_ticks++;
			if (_current_ticks >= _ticks_before_action)
			{
				_current_ticks = 0;
				return true;
			}
			return false;
		}

		void SetTicksBeforeAction(int ticks_before_action) { _ticks_before_action = ticks_before_action; }

		int TicksBeforeAction() { return _ticks_before_action; }
	};

	class BoolWithCounter
	{
	private:

		int _count_to_disable;

	public:
		BoolWithCounter()
		{
			_count_to_disable = 0;
		}
		
		BoolWithCounter(int count_to_disable_)
		{
			_count_to_disable = count_to_disable_;
		}

		bool IsEnable()
		{
			return (_count_to_disable > 0);
		}
		
		void DecreaseCounter()
		{
			if (_count_to_disable > 0)
			{
				_count_to_disable--;
			}
		}

		void SetCountToDisable(int count_to_count_to_disable)
		{
			_count_to_disable = count_to_count_to_disable;
		}

	};

	//class ObjectWithInvulnerability
	//{
	//private:
	//	BoolWithCounter _counter_of_invulnerability;
	//
	//public:
	//	
	//	void InvulStart()
	//	{
	//		_counter_of_invulnerability.SetCountToDisable(1000);
	//	}
	//
	//	void InvulUpdate()
	//	{
	//		_counter_of_invulnerability.DecreaseCounter();
	//	}
	//
	//	bool IsInvulEnabled()
	//	{
	//		return _counter_of_invulnerability.IsEnable();
	//	}
	//
	//};

	class ObjectWithInvulnerability
	{
	private:
		std::chrono::nanoseconds _end_invul_time{0};
	public:

		void InvulStart()
		{
			auto start_invul_time = chrono::high_resolution_clock::now().time_since_epoch();
			_end_invul_time = start_invul_time + chrono::seconds(5);
		}

		void InvulUpdate()
		{

		}

		bool IsInvulEnabled()
		{
			return std::chrono::high_resolution_clock::now().time_since_epoch() < _end_invul_time;
		}

	};

	class Player : public FieldObject, public ObjectWithInvulnerability
	{
	private:
		Point _position_delta{ 0,0 };

	public:
		
		void SetPositionDelta(Point new_position_delta)
		{
			_position_delta = new_position_delta;
		}

		Point GetNewPosition()
		{
			return _position + _position_delta;
		}

		Player()
			:FieldObject(Point{ 0,0 }, kPlayerSymbol, Color::Green)
		{
		}

		void Draw()
		{
			if (IsInvulEnabled())
			{
				Print(_position, kPlayerSymbol, Color::Orange);
			}
			else
			{
				FieldObject::Draw();
			}
		}
	};

	struct ShootingObject //ненаследуемый объект
	{

	};

	struct ObjectWithHealth //ненаследуемый объект
	{
		unsigned int _health;
	};

	struct RandomMovingEnemy : public ObjectWithAction//, public ObjectWithHealth
	{
		RandomMovingEnemy(Point p_, char symbol_, Color color_, int ticks_before_action_)
			:ObjectWithAction(p_, symbol_, color_, ticks_before_action_)
		{

		}
	};

	struct Trap : public ObjectWithAction
	{
		Trap(Point p_, int ticks_before_action_)
			:ObjectWithAction(p_, kTrapSymbol, Color::Grey, ticks_before_action_)
		{

		}

		void IncrementTickAndChangeVisible()
		{
			if (IncrementTickAndReturnIsActionShouldBe())
			{
				if (_symbol == kTrapSymbol)
				{
					_symbol = ' ';
				}
				else
				{
					_symbol = kTrapSymbol;
				}
				Draw();
			}
		}
	};


















}