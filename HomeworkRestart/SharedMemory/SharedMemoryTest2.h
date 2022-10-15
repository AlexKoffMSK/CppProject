#pragma once
#include <iostream>
#include <thread>
#include <queue>
#include "SharedMemory/SharedMemoryClient.h"
#include "SharedMemory/SharedMemoryServer.h"


namespace SharedMemory2
{
	struct Mapping
	{
		uint32_t _server_last_write_index;
		int _x[128];
	};

	void TestServer()
	{
		SharedMemoryServer::SharedMemoryServer sh_ser(sizeof(Mapping));

		Mapping* m = (Mapping*)sh_ser.GetBuf(); //накладываем трафарет на выделенный объем памяти, т.е. в первые 134 байта (сумма по структуре) мы не сможем вписать ничего иного, если работать через m.

		uint32_t index_x = 0;
		int x = 0;
		m->_server_last_write_index = 0;

		while (true)
		{
			index_x++;
			m->_x[index_x%std::size(m->_x)] = x++; //взятие остатка от 128 обеспечивает невыход за границы массива, а кольцевое хождение по нему
			m->_server_last_write_index = index_x;
			
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			if (rand() % 10 == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
		_getch();
	}

	void TestClient()
	{
		SharedMemoryClient::SharedMemoryClient sh_cli((sizeof(Mapping)));
		
		Mapping* m = (Mapping*)sh_cli.GetBuf();

		uint32_t index_of_last_read = m->_server_last_write_index;

		int prev_x = 0;

		while (true) 
		{
			if (index_of_last_read == m->_server_last_write_index)
			{
				continue;
			}
			
			if (index_of_last_read > m->_server_last_write_index)
			{
				std::cout << "Client overrun server";
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				continue;
			}

			std::cout << index_of_last_read << ' ' << m->_server_last_write_index << ' ' << m->_server_last_write_index - index_of_last_read << std::endl;
			
			index_of_last_read++;

			int x = m->_x[index_of_last_read % std::size(m->_x)];

			if (prev_x != 0 && x != (prev_x + 1)) 
			{
				std::cout << " Error ";
			}
			prev_x = x;

			//std::cout << x << ' ';

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			
			//if (rand() % 10 == 0) 
			//{
			//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			//}
		}
	}

	void Test(int argc, char* argv[])
	{
		if (argc == 1)
		{
			return;
		}

		if (std::string(argv[1]) == "0")
		{
			TestServer();
		}
		else if (std::string(argv[1]) == "1")
		{
			TestClient();
		}
		else
		{
			return;
		}
	}
}

//продолжить через файл
//логгер на отдельном потоке и отдельной функцией с доступом к общей памяти lock-free архитектура
//C:\Users\AlekseyRozhkov\source\repos\CppProject\x64\Debug