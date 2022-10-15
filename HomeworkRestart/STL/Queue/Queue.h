#pragma once
#include <iostream>
#include <queue>

namespace STLQueue
{
	class MyClass
	{
	public:
		int _x = 0;
		char _ch = 0;
	
		MyClass(int x, char ch) : 
			_x(x),
			_ch(ch)
		{
		}
	};
	
	
	void Run()
	{
		std::queue<MyClass> q;
		q.emplace(1, 'a');
		
		for (int i = 0; i < 5; i++)
		{
			q.emplace(q.back()._x + 1, q.back()._ch + 1);
		}

		for (int i = 0; i < 5; i++)
		{
			q.push(MyClass{ 10,'k' });
			q.push(MyClass{ q.back()._x + 1,q.back()._ch + 1 });
		}

		assert(q.front()._x == 1 && q.front()._ch == 'a');
		q.pop();
		assert(q.front()._x == 2 && q.front()._ch == 'b');
		q.pop();
		assert(q.front()._x == 3 && q.front()._ch == 'c');
		
	}
}

/*
emplace
push
front
back
pop
*/