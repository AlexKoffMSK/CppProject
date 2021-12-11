#pragma once
#include <iostream>

namespace Polymorphism
{
	class Object
	{
	public:
		virtual void Print()
		{
			std::cout << "Object" << std::endl;
		}
	};

	class Chair : public Object
	{
	public:
		void Print() override
		{
			std::cout << "Chair" << std::endl;
		}
	};

	class Table : public Object
	{
	public:
		void Print() override
		{
			std::cout << "Table" << std::endl;
		}
	};

	void PrintObject0(Object& obj)
	{
		obj.Print();
	}

	void PrintObject(Object& obj0)
	{
		if (dynamic_cast<Chair*>(&obj0))
		{
			std::cout << "Is chair" << std::endl;
		}
		else
		{
			std::cout << "Is not chair" << std::endl;
		}
	}

	void CheckObjects(Object& obj0, Object& obj1)
	{
		if (dynamic_cast<Chair*>(&obj0) && dynamic_cast<Chair*>(&obj1))
		{
			std::cout << "Is chairs" << std::endl;
		}
		if (dynamic_cast<Chair*>(&obj0) && dynamic_cast<Table*>(&obj1) || dynamic_cast<Table*>(&obj0) && dynamic_cast<Chair*>(&obj1))
		{
			std::cout << "Is chair and table" << std::endl;
		}
		if (dynamic_cast<Table*>(&obj0) && dynamic_cast<Table*>(&obj1))
		{
			std::cout << "Is tables" << std::endl;
		}

	}

	void Test777()
	{
		Object object;
		Chair chair;
		Table table;

		CheckObjects(object, chair);
		CheckObjects(chair, table);
		CheckObjects(chair, chair);
		CheckObjects(table, table);

	}





}