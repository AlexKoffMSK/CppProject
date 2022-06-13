#include <iostream>
#include <stack>

namespace STLStack
{
	void push()
	{
		std::stack<int> st;
		st.push(5);
		assert(st.size() == 1);
	}

	struct Test
	{
		int _x;
		int _y;
		Test(int x_, int y_)
		{
			_x = x_;
			_y = y_;
		}
	};

	void emplace()
	{
		std::stack<Test> st;
		st.push(Test{ 6,7 });
		st.emplace(6, 7);
		assert(st.size() == 2);
	}

	void top()
	{
		std::stack<int> st;
		st.push(3);
		st.push(4);
		st.push(5);

		assert(st.top() == 5);
	}

	void pop()
	{
		std::stack<int> st;
		st.push(3);
		st.push(4);
		st.push(5);

		st.pop();
		assert(st.top() == 4);

		st.pop();
		assert(st.top() == 3);

		st.pop();
		assert(st.size() == 0);
		assert(st.empty() == true);
	}

	void Test1()
	{
		//std::string str = "((()())((()())))";
		//std::string str = "(()))((())";
		std::string str = "()((()))";
		
		//!(a && b) = !a || !b
		//!(a || b) = !a && !b
		 
		//if 1 - (, lst - )
		//( first == '(' && last == ')' )
		//!(first == '(' && last == ')' )     =     first != '(' || last != ')'   ;
		//()
		//((
		//))
		//)(

		//str <- (

		if (str.front() != '(' || str.back() != ')')
		{
			std::cout << "No" << std::endl;
			return;
		}

		int balance=0;

		for (auto ch : str)
		{
			if (ch == '(')
			{
				balance++;
			}
			else
			{
				balance--;
			}
			//if (balance > 0) //количество открывающихся больше чем закрывающихся - терпимо пока не дошли до конца строки
			//{
			//	continue;
			//}
			if (balance < 0) //количество закрывающихся больше чем открывающихся - все плохо, выходим
			{
				std::cout << "No" << std::endl;
				return;
			}
		}
		if (balance == 0)
		{
			std::cout << "Ok" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}

	struct NumberOrOperator
	{
		int _number=0;
		char _operator='\0';
	};

	void Test2()
	{
		std::stack<NumberOrOperator> st;
		
		//std::string str = "(5+3)*6";
		//std::string str = "5+3*2";
		std::string str = "5*3+2";
		//5+3*2
		int d1=0;
		char o1='\0';
		
		for (auto ch : str)
		{
			if (ch >= '0' && ch <= '9')
			{
				st.push(NumberOrOperator{ ch - '0','\0' });
			}
			if (ch == '+')
			{
				st.push(NumberOrOperator{0,'+'});
			}
			if (ch == '*')
			{
				st.push(NumberOrOperator{ 0,'*' });
			}
		}
		//std::cout << d1 << std::endl;
		
		int addent = 0;
		
		while (st.size()>1) 
		{
			int x = st.top()._number;
			st.pop();

			char o = st.top()._operator;
			st.pop();
			
			int y = st.top()._number;
			st.pop();
			
			int number_to_push = 0;
			if (o == '+')
			{
				if (st.top()._operator == '*')
				{
					addent = 2;
				}
				else
				{
					number_to_push = x + y;
				}
			}
			if (o == '*')
			{
				number_to_push = x * y;
			}
			st.push(NumberOrOperator{ number_to_push,'\0'});
		}
		std::cout << st.top()._number << std::endl;
	}


	bool IsBinaryOperator(char ch)
	{
		return (ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '^' || ch == '%');
	}

	double DoBinaryOperation(char op, double x, double y)
	{
		switch (op)
		{
		case '+': {return (x + y); break; }
		case '-': {return (x - y); break; }
		case '*': {return (x * y); break; }
		case '/': {return (x / y); break; }
		case '^': {return (pow(x, y)); break; }
		case '%': {return ((int)x%(int)y); break; }
		default: {throw ("Unsupported operation"); break; }
		}
	}

	int GetBinaryOperationPriority(char ch)
	{
		switch (ch)
		{
		case '+': {return 10; }
		case '-': {return 10; }
		case '*': {return 20; }
		case '/': {return 20; }
		case '%': {return 20; }
		case '^': {return 30; }
		case '(': {return 0; }
		default: {throw ("Unsupported operation"); break; }
		}
	}


	bool IsUnaryOperation(char ch)
	{
		return ch == '#' || ch == 's'; //s - принят как sin
	}

	double DoUnaryPrefixOperation(char op, double x)
	{
		switch (op)
		{
		case 's': { return std::sin(x); break; }
		case '#': { return -x; break; }
		default: { throw "Unsupported operation"; }
		}
	}


	bool IsDigit(char ch)
	{
		return (ch >= '0' && ch <= '9');
	}

	int ConvertCharDigitToInt(char ch)
	{
		return ch - '0';
	}

	char ConvertPrefixOperationToCustomSymbol(char ch)
	{
		switch (ch)
		{
		case '-': {return '#'; break; }
		}
	}

	bool IsCustomPrefixSymbol(char ch)
	{
		return ch == '#';
	}

	
	double ComputeExpression(std::string inverse_polska_str)
	{
		//532*+ = 11
		//st 532
		//*+ = 11
		//2*3 = 6
		//56
		//56 
		//11
		//считываем очередной символ из строки. Если символ - число, то пушим в стек.
		//Если операция - достаем из стека два элемента, производим операцию, кладем результат в стек
		//как только закончим считывать все символы - в стеке будет лежать результат.

		std::stack<double> st;

		for (auto ch : inverse_polska_str)
		{
			if (IsDigit(ch))
			{
				st.push(ConvertCharDigitToInt(ch));
			}
			if (IsBinaryOperator(ch))
			{
				double y = st.top();
				st.pop();
				double x = st.top();
				st.pop();
				st.push(DoBinaryOperation(ch, x, y));
			}
			if (IsUnaryOperation(ch))
			{
				double x = st.top();
				st.pop();
				st.push(DoUnaryPrefixOperation(ch, x));
			}
		}
		return st.top();
	}

	std::string ConvertInfixNotationToInvertedPolskaNotation(std::string str)
	{
		std::stack<char> st;
		std::string result_str;
		
		char prev_ch = '\0';
		
		for (auto ch : str)
		{
			if (ch == '(')
			{
				st.push(ch);
			}
			else if (IsDigit(ch))
			{
				result_str.push_back(ch);
			}
			else if (ch == ')')
			{
				while (st.top() != '(')
				{
					result_str.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			else if (ch == '-' && !IsDigit(prev_ch))
			{
				st.push(ConvertPrefixOperationToCustomSymbol(ch)); //# условный заменитель минуса, чтобы, когда буду доставать из стека решетку - заменить его унарным минусом
			}
			else if (IsBinaryOperator(ch))
			{
				while (!st.empty())
				{
					if (IsCustomPrefixSymbol(st.top()))
					{
						result_str.push_back(st.top());
						st.pop();
					}
					else if (GetBinaryOperationPriority(st.top()) >= GetBinaryOperationPriority(ch)) 
					{
						result_str.push_back(st.top());
						st.pop();
					}
					else
					{
						break;
					}
				}
				st.push(ch);
			}
			else if (IsUnaryOperation(ch))
			{
				st.push(ch);
			}
			else
			{
				throw "Unsupported symbol";
			}
			prev_ch = ch;
		}
		while (!st.empty())
		{
			result_str.push_back(st.top());
			st.pop();
		}
		return result_str;
	}

	/*
	Пока есть ещё символы для чтения:
		1. Читаем очередной символ.
		2. Если символ является числом, добавляем его к выходной строке 
		//или постфиксной функцией (например, ! — факториал), добавляем его к выходной строке.
		3. Если символ является префиксной функцией //(например, sin — синус)//, помещаем его в стек.
		4. Если символ является открывающей скобкой, помещаем его в стек.
		5. Если символ является закрывающей скобкой:
			До тех пор, пока верхним элементом стека не станет открывающая скобка, выталкиваем элементы из стека в выходную строку. 
			При этом открывающая скобка удаляется из стека, но в выходную строку не добавляется. 
			//Если стек закончился раньше, чем мы встретили открывающую скобку, 
			//это означает, что в выражении либо неверно поставлен разделитель, либо не согласованы скобки.
		//6. Если существуют разные виды скобок, появление непарной скобки также свидетельствует об ошибке. Если какие-то скобки одновременно являются функциями 
		//   (например, [x] — целая часть), добавляем к выходной строке символ этой функции.
		7. Если символ является бинарной операцией о1, тогда:
			1) пока на вершине стека: 
				- префиксная функция…
				… ИЛИ операция приоритетнее или такого же уровня приоритета как o1
				… ИЛИ операция на вершине стека левоассоциативная с приоритетом как у o1
				… выталкиваем верхний элемент стека в выходную строку;
			2) помещаем операцию o1 в стек.
		
	Когда входная строка закончилась, выталкиваем все символы из стека в выходную строку. В стеке должны были остаться только символы операций; 
	если это не так, значит в выражении не согласованы скобки.

		5+3*2
		res = 32*5+
		result = 532*+
		stack = +*
		//-5+3
		st +
		res 5-3+
		// s = / +
		// 16 / 24
		//s1 = 24

		3 4 2 * 1 5 − 2 ^ / +
		3 0.5 +
		3 + 4 * 2 / (1 - 5)^2 = 3.5


		*/

	void TestComputeExpression()
	{
		//assert(ComputeExpression("5") == 5);
		//assert(ComputeExpression("53+") == 8);
		//assert(ComputeExpression("53*") == 15);
		//assert(ComputeExpression("53+2+") == 10);
		//assert(ComputeExpression("53*2*") == 30);
		//assert(ComputeExpression("53*2+") == 17);
		//assert(ComputeExpression("53+2*") == 16);
		//assert(ComputeExpression("53+2*1+") == 17);

		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5+3")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5*3")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5+3*2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5*3+2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5+3+2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5*3*2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("(5+3)")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("(5+3)*2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("(5+(3*2))")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("(5*(3+2))")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5+(8/(6-2)+7*1)*2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("(8/(6-2)+7*1)")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("8/2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("8^2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("2^2^2^2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("9%2")) <<std::endl;
		//std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("9%2+6%4")) <<std::endl;
		std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("5+-3")) <<std::endl;
		std::cout << ComputeExpression(ConvertInfixNotationToInvertedPolskaNotation("s(5)")) <<std::endl;
	}

	//std::string str = "5*3+2+3";

	void TestAll()
	{
		//push();
		//emplace();
		//top();
		//pop();
		//Test1();
		//Test2();
		TestComputeExpression();
	}

	/*
	push
	emplace
	top
	pop
	*/

	//532*+ = 11
	//st 532
	//*+ = 11
	//2*3 = 6
	//56
	//56 
	//11
	//считываем очередной символ из строки. Если символ - число, то пушим в стек.
	//Если операция - достаем из стека два элемента, производим операцию, кладем результат в стек
	//как только закончим считывать все символы - в стеке будет лежать результат.

}