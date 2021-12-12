#pragma once
#include <iostream>

namespace PerfectForwarding
{
	void F1(const std::vector<int>& vec)
	{
		std::cout << "F1 lvalue" << std::endl;
	}
	
	void F1(std::vector<int>&& vec) //rvalue, так как два амперсанда стоят справа от конкретного типа
	{
		std::cout << "F1 rvalue" << std::endl;
	}
	
	template <typename T>
	void F(T&& t) //универсальная ссылка (может быть как rvalue, так и lvalue, в зависимости от того как вызываем), так как два амперсанда стоят справа от шаблона!!!
	{
		//std::cout << "F " << typeid(t).name() << std::endl;
		F1(std::forward<T>(t)); //std::forward<T>(t) превратится в std::move(t), если t - имеет тип rvalue-ссылки. Превращается в t, если t имеет тип lvalue-ссылки
	}

	//void Test1()
	//{
	//	F(1);
	//	F(1.3);
	//	F(1.7f);
	//	F('D');
	//	F(true);
	//	F("Hello");
	//}

	void Test2()
	{
		std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
		F(vec);
		F(std::move(vec));
		F(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		vec.emplace_back(4);
	}


























}