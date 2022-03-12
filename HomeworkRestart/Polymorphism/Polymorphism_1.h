#pragma once
#include <iostream>
#include <vector>

namespace Polymorphism_1
{
	class Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) = 0;
	};

	class BlockMult2 :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "(" << x << " * 2) = ";
			return x * 2;
		}
	};

	class BlockAdd1 :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "(" << x << " + 1) = ";
			return x + 1;
		}
	};

	class BlockNegate :public Block
	{
	public:
		[[nodiscard]] virtual int Process(int x) override
		{
			std::cout << "Negate (" << x << ") = ";
			return x * (-1);
		}
	};

	void Test()
	{
		std::vector<Block*> bl;
		//добавить в bl блоков
		BlockMult2 blm2;
		BlockAdd1 bla1;
		BlockNegate bln;
		bl.push_back(&blm2);
		bl.push_back(&bla1);
		bl.push_back(&blm2);
		bl.push_back(&bln);
		bl.push_back(&bla1);
		bl.push_back(&bla1);
		bl.push_back(&bln);

		int current_value=1;
		
		for (Block* b : bl)
		{
			current_value = b->Process(current_value);
			std::cout << current_value << std::endl;
		}
	}

	void Test1()
	{
		BlockMult2 blm2;
		std::cout << blm2.Process(4) << std::endl;

		BlockMult2 blm21;
		std::cout << blm21.Process(blm2.Process(4)) << std::endl;
		
		Block* bl = &blm2;//в будущем присвоим сюда какой-то объект
		std::cout << bl->Process(4) << std::endl;
		
		Block* bl2 = &blm21;
		std::cout << bl2->Process(bl->Process(5)) << std::endl;
		
		int x = bl->Process(5);
		std::cout << bl2->Process(x) << std::endl;
	}















}