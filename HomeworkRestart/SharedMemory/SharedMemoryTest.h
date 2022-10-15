#pragma once
#include <iostream>
#include "SharedMemory/SharedMemoryClient.h"
#include "SharedMemory/SharedMemoryServer.h"

//пересылка данных после нажатия Ввод

namespace SharedMemory
{
	const char kTriggerAfterWrite = '1';
	const char kTriggerAfterRead = '0';
	const int kOffsetForStartToReadAndWrite = 1;
	const int kAdditionalSizeForTerminalZero = 1;
	
	struct Mapping
	{
		char _trigger_for_write_and_read; //1 - в 0 байте будет один чар
		char _data[50]; //50 - начиная с 1 по 50 байт включительно память воспринимется как 1 байт под чар
		int _data_int = 1; //4 - начиная с 51 по 54 включительно - как инт, т.е. 1 значение инта
		double _data_double[10];//80 - начиная с 55 по 134 - под даблы
	};

	void TestServer()
	{
		SharedMemoryServer::SharedMemoryServer sh_ser((sizeof(Mapping)));

		//*sh_ser.GetBuf() = kTriggerAfterWrite;

		Mapping* m = (Mapping*)sh_ser.GetBuf(); //накладываем трафарет на выделенный объем памяти, т.е. в первые 134 байта (сумма по структуре) мы не сможем вписать ничего иного, если работать через m.
		//m->_data_int = 4;

		while (true)
		{
			std::string str;
			std::cout << "Enter data: ";
			std::cin >> str;

			CopyMemory((PVOID)(&(m->_data[0])), str.c_str(), (str.size() + kAdditionalSizeForTerminalZero));
			
			m->_trigger_for_write_and_read = kTriggerAfterWrite;

			if (str == "0")
			{
				return;
			}

			//*(int*)(sh_ser.GetBuf() + 50) = 4; //начиная с 50 байта по 54 байт память объединена в 4 байта под интовую переменную

		}
		_getch();
	}

	void TestClient()
	{
		SharedMemoryClient::SharedMemoryClient sh_cli((sizeof(Mapping)));
		
		Mapping* m = (Mapping*)sh_cli.GetBuf();

		std::string str1;

		while (true) 
		{
			if (m->_trigger_for_write_and_read != kTriggerAfterWrite)
			{
				continue;
			}
			
			std::string str(&(m->_data[0]));
			
			if (str == "0")
			{
				//return;
				exit(0);
			}

			std::cout << str << std::endl;
			
			m->_trigger_for_write_and_read = kTriggerAfterRead;

			//std::cout << (char*)sh_cli.GetBuf() << std::endl;

			//MessageBox(NULL, (LPCWSTR)sh_cli.GetBuf(), TEXT("Process2"), MB_OK);
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