#pragma once
#include <iostream>
#include "SharedMemory/SharedMemoryClient.h"
#include "SharedMemory/SharedMemoryServer.h"

//��������� ������ ��������� � �� ������

namespace SharedMemory1
{
	enum TriggerForWriteAndRead : char
	{
		AfterRead = '0',
		AfterWrite = '1'
	};
	
	struct Mapping
	{
		TriggerForWriteAndRead _trigger_for_write_and_read;
		char _data;
	};

	void TestServer()
	{
		SharedMemoryServer::SharedMemoryServer sh_ser(sizeof(Mapping));

		Mapping* m = (Mapping*)sh_ser.GetBuf(); //����������� �������� �� ���������� ����� ������, �.�. � ������ 134 ����� (����� �� ���������) �� �� ������ ������� ������ �����, ���� �������� ����� m.

		while (true)
		{
			char ch = _getch();
			m->_data = ch;
			m->_trigger_for_write_and_read = AfterWrite;
			if (ch == 27)
			{
				exit(0);
			}
			std::cout << '[' << ch << ']' << std::endl;
		}
		_getch();
	}

	void TestClient()
	{
		SharedMemoryClient::SharedMemoryClient sh_cli((sizeof(Mapping)));
		
		Mapping* m = (Mapping*)sh_cli.GetBuf();

		while (true) 
		{
			if (m->_trigger_for_write_and_read != AfterWrite)
			{
				continue;
			}
			if (m->_data == 27)
			{
				exit(0);
			}
			std::cout << m->_data;
			m->_trigger_for_write_and_read = AfterRead;
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

//���������� ����� ����
//������ �� ��������� ������ � ��������� �������� � �������� � ����� ������ lock-free �����������
//C:\Users\AlekseyRozhkov\source\repos\CppProject\x64\Debug