#pragma once
#include <iostream>
#include <vector>

namespace Polymorphism_2
{
	class Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) = 0;
		
		Block* _next_block=nullptr;
		
		[[nodiscard]] int ProcessAndPushResultToNext(int x)
		{
			if (_next_block != nullptr)
			{
				return _next_block->ProcessAndPushResultToNext(Process(x));
			}
			else
			{
				return Process(x);
			}
		}
	};

	class BlockMult2 :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "(" << x << " * 2) -> ";
			return x * 2;
		}
	};

	class BlockAdd1 :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "(" << x << " + 1) -> ";
			return x + 1;
		}
	};

	class BlockNegate :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "Negate (" << x << ") -> ";
			return x * (-1);
		}
	};

	class BlockMult2Add1 :public Block
	{
	public:
		
		BlockMult2 blm2;
		BlockAdd1 bla1;
		
		[[nodiscard]] virtual int Process(int x) override
		{
			return bla1.Process(blm2.Process(x));
		}
	};
	
	//============================================================================
	
	void Test()
	{
		BlockMult2 blm2;
		BlockAdd1 bla1;
		BlockNegate bln;
		BlockMult2Add1 blm2bla1;

		blm2._next_block = &bla1;
		bla1._next_block = &bln;
		bln._next_block = &blm2bla1;
		std::cout << blm2.ProcessAndPushResultToNext(1) <<std::endl;
	}

	void Test777()
	{
		int a;
		//a = rand() % 10;
		//std::cin>>a;
		//switch (a)
		//{
		//case 5: std::cout << "5"; break;
		//case 4: std::cout << "4"; break;
		//case 2: std::cout << "2"; break;
		//case 7: std::cout << "5"; break;
		//case 8: std::cout << "5"; break;
		//}

		//constexpr int c = (7 || 8 || 5);
		//
		//switch (a)
		//{
		//case 7:
		//case 8:
		//
		//case 5: 
		//std::cout << "5";
		//std::cout << "6";
		//break;
		//
		//case 4: 
		//std::cout << "4"; 
		//std::cout << "9"; 
		//break;
		//
		//case 2: 
		//std::cout << "2"; 
		//break;
		//
		//default:
		//	std::cout << "!";
		//break;
		//}

		std::vector<std::string> arr_str = {"sdf", "fsd", "wer", "twer"};
		
		//std::cout << &(*arr_str.end()) << std::endl;;
		std::cout << &arr_str[3] << std::endl;
		//std::cout << (int)*((char*)(void*)0x00000237B2B6D4A8) << std::endl;
		
		//for (std::string elem : arr_str)
		//{
		//
		//}
		//for (auto elem : arr_str)
		//{
		//
		//}
		//for (int i = 0; i < arr_str.size(); ++i)
		//{
		//
		//}
		//for (int i = arr_str.size() - 1; i >= 0; --i)
		//{
		//	std::cout << i << ' ' << arr_str[i] << std::endl;
		//}
		//for (int i = 1; i<=1000 ; i*=2 ) //степени двойки до тех пор пока число меньше 1000
		//{
		//	std::cout << i << std::endl;
		//}
		//for (int i = 1; pow(2,i)<1000; ++i) //степени двойки до тех пор пока число меньше 1000
		//{
		//	std::cout << pow(2, i) << std::endl;
		//}


		/*
		bubble 
		4 1 2 5 4 7 2 1 2 3
		1 4 2 5 4 7 2 1 2 3
		1 2 4 5 4 7 2 1 2 3
		1 2 4 4 5 2 7 1 2 3
		1 2 4 4 5 2 7 1 2 3
		
		merge

		quick
		
		insertion
		selection
		counting


		*/

	}

	int* rrr(int* arr)
	{
		//quick_sort;
		return &arr[6];
	}








































}