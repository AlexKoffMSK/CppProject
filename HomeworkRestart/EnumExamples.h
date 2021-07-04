#pragma once
#include <iostream>
#include <vector>

namespace EnumExamples
{
	void Test(std::string name, char gender)
	{
		if (gender == 'F')
		{
			std::cout << "Woman:" << name << std::endl;
		}
		else
		{
			std::cout << 4 << std::endl;
		}
	}

	enum class Gender 
	{
		Male, 
		Female
	};

	void Test1(std::string name, Gender gender)
	{
		if (gender == Gender::Female)
		{
			std::cout << "Woman: " << name << std::endl;
		}
		else
		{
			std::cout << 4 << std::endl;
		}
	}

	void Test2()
	{
		Test("Vasya", 'M');
		Test("Sveta", 'F');
		Test1("Vasya", Gender::Male);
		Test1("Sveta", Gender::Female);
	}

	enum class SeasonOfYear : long
	{
		Winter = 0,
		Spring = 1, 
		Summer = 2,
		Autumn = 3, 
	};

	namespace SeasonOfYear1
	{
		const char kWinter = 'w';
		const char kSpring = 's';
		const char kSummer = 's';
		const char kautumn = 'a';
	}

	enum SeasonOfYear2 : long
	{
		qWinter = 0,
		qSpring = 1,
		qSummer = 2,
		qAutumn = 3,
	};

	void Test3(SeasonOfYear season)
	{
		std::cout << (int)season << std::endl;
	}

	void Test4()
	{
		int a = qWinter;
		int b = (int)SeasonOfYear::Summer;
		Test3(SeasonOfYear::Winter);
		Test3(SeasonOfYear::Spring);
		Test3(SeasonOfYear::Summer);
		Test3(SeasonOfYear::Autumn);
	}

	enum Exchange
	{
		Moex,
		Lse
	};

	enum ExchangeSubGroup
	{
		MoexStocks,
		MoexCurrency,
		MoexForts,
		LseCurrency,
		LseStocks
	};

	Exchange GetExchangeByExchangeSubGroup(ExchangeSubGroup subgroup)
	{
		switch (subgroup)
		{
			//case ExchangeSubGroup::MoexCurrency
			case MoexStocks: return Moex;
			case MoexCurrency: return Moex;
			case MoexForts: return Moex;
			case LseCurrency: return Lse;
			case LseStocks: return Lse;
		}
	}

	std::vector<ExchangeSubGroup> GetExchangeSubGroupByExchange(Exchange exchange)
	{
		switch (exchange)
		{
		case Moex: return { MoexStocks,MoexCurrency,MoexForts };
		case Lse: return { LseCurrency,LseStocks };
		}
	}

	void Test5(ExchangeSubGroup subgroup)
	{

	}
	void Test6()
	{
		Test5(MoexStocks);
		//Test5(Moex);
	}

	struct a
	{
		int aa = 0;
		enum class www{a,b,c};
		enum ww1w{d,e,f};
	};


}