#pragma once
#include <iostream>
#include <ctime>

namespace Binance
{
	// [
	// 		[
	// 			1499040000000,      // Open time
	// 			"0.01634790",       // Open
	// 			"0.80000000",       // High
	// 			"0.01575800",       // Low
	// 			"0.01577100",       // Close
	// 			"148976.11427815",  // Volume
	// 			1499644799999,      // Close time
	// 			"2434.19055334",    // Quote asset volume
	// 			308,                // Number of trades
	// 			"1756.87402397",    // Taker buy base asset volume
	// 			"28.46694368",      // Taker buy quote asset volume
	// 			"17928899.62484339" // Ignore.
	// 		],
	// 		[
	//		...
	//		],...
	// ]

	//{
	//	"mins": 5,
	//	"price" : "9.35751834"
	//}


	void Test()
	{
		//std::system("dir");
		//std::system("c:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\BinanceDataAPI\\curl-7.80.0-win64-mingw\\bin\\curl.exe \"https://api.binance.com/api/v3/klines?interval=1m&symbol=BTCUSDT\" > klines.json");
		//std::system("c:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\BinanceDataAPI\\curl-7.80.0-win64-mingw\\bin\\curl.exe \"https://api.binance.com/api/v3/avgPrice?symbol=BTCUSDT\" > avgPrice.json");

		while (true)
		{
			std::system("c:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\BinanceDataAPI\\curl-7.80.0-win64-mingw\\bin\\curl.exe \"https://api.binance.com/api/v3/avgPrice?symbol=BTCUSDT\"");
			std::system("c:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\BinanceDataAPI\\curl-7.80.0-win64-mingw\\bin\\curl.exe \"https://api.binance.com/api/v3/avgPrice?symbol=SOLUSDT\"");
			std::cout << std::endl;
			//std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
		
		//json11::Json klines_json = json11::ReadJsonFromFile("klines.json");
		//
		////std::cout << klines_json.array_items().size() << std::endl;
		//
		//for (json11::Json bar : klines_json.array_items())
		//{
		//	//std::cout << bar.array_items()[2].number_value() << std::endl;
		//	//std::cout << bar.array_items()[5].number_value() << std::endl;
		//}
		//
		//json11::Json avg_price_json = json11::ReadJsonFromFile("avgPrice.json");
		//for (auto [key, value] : avg_price_json.object_items())
		//{
		//	std::cout << key << ' ' << value.number_value() << std::endl;
		//}
		//
		//std::cout << avg_price_json["price"].number_value() << std::endl;
	}

	











}